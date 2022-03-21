package com.apps.springone.data.repository;

import com.apps.springone.data.model.user.User;

import org.springframework.data.mongodb.repository.MongoRepository;

public interface UserRepository extends MongoRepository<User, String> {
    
}
