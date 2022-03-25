package com.apps.springone.controller;

import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestParam;

import io.swagger.models.Model;

@Controller
public class HomeController {
    
    @GetMapping("/")
    public String greeting(
        @RequestParam(name="name", required=false, defaultValue="World") String name, Model model
    ) {
        return "index";
    }
}
