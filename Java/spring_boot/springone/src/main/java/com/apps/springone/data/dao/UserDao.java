package com.apps.springone.data.dao;

import java.util.List;

import com.apps.springone.data.model.user.User;
import com.apps.springone.data.repository.UserRepository;

import org.springframework.data.mongodb.core.MongoTemplate;
import org.springframework.stereotype.Service;

@Service
public class UserDao {

    private final UserRepository userRepository;
    private final MongoTemplate mongoTemplate;

    public UserDao(UserRepository userRepository, MongoTemplate mongoTemplate) {
        this.userRepository = userRepository;
        this.mongoTemplate = mongoTemplate;
    }

    public Boolean mongoCollectionExits() {
        return mongoTemplate.collectionExists("User");
    }

    public User saveUserToDB(User newUser) {
        return this.userRepository.insert(newUser);
    }

    public List<User> getAllUsersFromDB() {
        return this.userRepository.findAll();
    }

    public User getUserById(String id) {
        return this.userRepository.findById(id).orElse(null);
    }
}
