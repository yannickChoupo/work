package com.apps.springone.service;

import java.util.List;

import com.apps.springone.data.dao.UserDao;
import com.apps.springone.data.model.user.User;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

@Service
public class UserService {

    private final UserDao userDao;

    @Autowired
    public UserService(UserDao userDao) {
        this.userDao = userDao;
    }


    public List<User> getAllUsers() {
        return userDao.getAllUsersFromDB();
    }

    public Boolean checkDB() {
        return userDao.mongoCollectionExits();
    }

    public User addNewUser(User newUser) {
        return userDao.saveUserToDB(newUser);
    }

    public User getUserById(String id) {
        return userDao.getUserById(id);
    }
}
