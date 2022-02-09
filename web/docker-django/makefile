# create the django project / django-admin startproject mySite
all:
	docker-compose run web django-admin startproject DjangoSite .

runTest:
	python3 manage.py collectstatic
	python3 manage.py test

deplayCheck:
	python3 manage.py check --deploy