package com.apps.springone.controller;

import java.io.IOException;
import java.net.HttpURLConnection;
import java.net.URL;
import java.nio.charset.MalformedInputException;

import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

//MVC-Controller
@RestController
@RequestMapping("/api/urlcheck")
public class UrlCheckController {

    private final String SITE_IS_UP = "Site is up!";
    private final String SITE_IS_DOWN = "Site is down!";
    private final String INCORECT_URL = "Incorect url!";


    @GetMapping("/")
    public String getUrlStatusMessage(@RequestParam String url) {
        String returnMessage = "";
        System.out.println(url);
        try {
            URL urlObj = new URL(url);
            HttpURLConnection connection = (HttpURLConnection) urlObj.openConnection();
            connection.setRequestMethod("GET");
            connection.connect();
            int responseCategorie = connection.getResponseCode() / 100; 
            returnMessage = SITE_IS_DOWN;
            if(responseCategorie == 2|| responseCategorie == 3) {
                returnMessage = SITE_IS_UP;
            }
        } catch (MalformedInputException e) {
            e.printStackTrace();
            returnMessage = INCORECT_URL;
        } catch (IOException e) {
            e.printStackTrace();
            returnMessage = INCORECT_URL;
        }
        return returnMessage;
    }
}
