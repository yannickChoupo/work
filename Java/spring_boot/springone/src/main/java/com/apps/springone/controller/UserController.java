package com.apps.springone.controller;

import java.util.List;

import com.apps.springone.data.model.user.User;
import com.apps.springone.service.UserService;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import io.swagger.annotations.ApiParam;
import io.swagger.annotations.ApiResponse;
import io.swagger.annotations.ApiResponses;

@RestController
@RequestMapping("/api/user")
@Api(value = "User controller - Schnittstelle zum User")
public class UserController {

    private final UserService userService;

    @Autowired
    public UserController(UserService userService) {
        this.userService = userService;
    }

    @GetMapping(path = "/all", produces = "application/json")
    @ApiOperation(value = "Gives a list of all users in db back", response = User.class)
    @ApiResponses(value = {
            @ApiResponse(code = 200, message = "OK. You're in the right place. Here you go"),
            @ApiResponse(code = 301, message = "MOVED PERMANENTLY. We're reorganized a bit. The resource is now in an other location"),
            @ApiResponse(code = 302, message = "MOVED TEMPORARILY. We move to the saesonel section for summer. You will find the resource you need in the follwing XXX location"),
            @ApiResponse(code = 401, message = "UNAUTHORIED. We keep the resource you need in a locked case. I'm going to have to see your ID."),
            @ApiResponse(code = 403, message = "FORBIDDEN. We're reorganized a bit. The resource is now in an other location"),
            @ApiResponse(code = 404, message = "NOT FOUND. What's that ? can you come back when my supervisor is here"),
            @ApiResponse(code = 410, message = "GONE. I kown the one. A kid lost an eye. so we've pulled it from our shelves permanently. Sorry"),
            @ApiResponse(code = 500, message = "INTERNAL SERVER ERROR. ... generic error message "),
            @ApiResponse(code = 503, message = "SERVICE UNAVAILABLE. I'm sorry sir. We have a problem in the store Nobody is allowed in"),
    })

    public List<User> fetchAllUser() {
        return userService.getAllUsers();
    }

    @GetMapping("/{id}")
    User getUser(
            @ApiParam(value = "Give the id of the user you are looking for.", required = true) @PathVariable String id) {
        return userService.getUserById(id);
    }

    @PostMapping("/add")
    public String addUser(
            @RequestParam(defaultValue = "") String firstName,
            @RequestParam(defaultValue = "") String lastName,
            @RequestParam(defaultValue = "") String email) {
        if (firstName == "" || lastName == "" || email == "") {
            return "an argument is missing";
        } else {
            return "addedUser.getEmail addedUser.getFirtName() +  addedUser.getLastName()";
        }
    }

    @PostMapping(path = "/addjson", consumes = "application/json", produces = "appliction/json")
    public String addUserJson(
            @RequestParam(defaultValue = "") String firstName,
            @RequestParam(defaultValue = "") String lastName,
            @RequestParam(defaultValue = "") String email) {
        if (firstName == "" || lastName == "" || email == "") {
            return "an argument is missing";
        } else {
            return "addedUser.getEmail addedUser.getFirtName() +  addedUser.getLastName()";
        }
    }

}
