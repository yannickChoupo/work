from enum import unique
from tokenize import blank_re
from unittest.util import _MAX_LENGTH
import uuid
from django.db import models
from django.urls import reverse
from django.contrib.auth.models import User
from datetime import date

# Create your models here.


class Genre(models.Model):
    """Model representing a book genre"""
    name = models.CharField(
        max_length=200,
        help_text='Enter a book genre'
    )

    def __str__(self):
        """String for representing the model object."""
        return self.name


class Author(models.Model):
    """Model representing an author."""
    first_name = models.CharField(max_length=100)
    last_name = models.CharField(max_length=100)
    date_of_birth = models.DateField(null=True, blank=True)
    date_of_death = models.DateField('Died', null=True, blank=True)

    class Meta:
        ordering = ['last_name', 'first_name']

    def get_absolute_url(self):
        """Returns the url to access a particular author instance."""
        return reverse('author-detail', args=[str(self.id)])

    def __str__(self):
        """String for representing the Model object."""
        return f'{self.last_name}, {self.first_name}'


class Book(models.Model):
    """Model representing a book(but not a specific copy of a book"""
    title = models.CharField(max_length=200)

    # Foreign key used because book can only  have one author, but authors can have multiple
    # books
    author = models.ForeignKey(
        Author,
        on_delete=models.SET_NULL,
        null=True)

    summary = models.TextField(
        max_length=1000,
        help_text="Enter a brief description of the book"
    )

    isbn = models.CharField(
        'ISBN',
        max_length=13,
        unique=True,
        help_text='13 character <a href="https://www.isbn-international.org/content/what-isbn">ISBN number</a>'
    )

    genre = models.ManyToManyField(
        Genre, help_text='Select a genrer for this book')

    def __str__(self):
        """String for representing the Model object"""
        return self.title

    def get_absolute_url(self):
        """Returns the url to acces a detail record for this book"""
        return reverse('book-detail', args=[str(self.id)])


class BookInstance(models.Model):
    """Model representing a specific copy of a book"""
    id = models.UUIDField(
        primary_key=True,
        default=uuid.uuid4,
        help_text='Unique ID for the particular book accross whole library'
    )

    borrower = models.ForeignKey(
        User,
        on_delete=models.SET_NULL,
        null=True,
        blank=True
    )

    book = models.ForeignKey(
        Book,
        on_delete=models.RESTRICT,
        null=True
    )

    imprint = models.CharField(max_length=200)
    due_back = models.DateField(null=True, blank=True)

    LOAN_STATUS = (
        ('m', 'Maintenance'),
        ('o', 'On loan'),
        ('a', 'Available'),
        ('r', 'Reserved'),
    )

    status = models.CharField(
        max_length=1,
        choices=LOAN_STATUS,
        blank=True,
        default='m',
        help_text='Book availability',
    )

    class Meta:
        ordering = ['due_back']
        permissions = (("can_mark_returned", "Set book as returned"),)

    def __str__(self):
        """String for representing the Model object."""
        return f'{self.id} ({self.book.title})'

    @property
    def is_overdue(self):
        if self.due_back and date.today() > self.due_back:
            return True
        return False


class Language(models.Model):
    name = models.CharField(
        max_length=20,
        help_text='Enter a Language'
    )

    def __str__(self):
        return self.name


def display_genre(self):
    """Create a string for the Genre. This is required to display genre in Admin."""
    return ', '.join(genre.name for genre in self.genre.all()[:3])


display_genre.short_description = 'Genre'
