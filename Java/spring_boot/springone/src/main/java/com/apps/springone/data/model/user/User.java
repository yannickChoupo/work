package com.apps.springone.data.model.user;

import org.springframework.data.annotation.Id;
import org.springframework.data.mongodb.core.mapping.Document;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;

@Data
@Document(collection = "User")
@AllArgsConstructor
@ApiModel(description = "Primary user possible of the app")
public class User {

    @ApiModelProperty("The unique Identifier of a user in the db")
    @Id private String id;

    @ApiModelProperty("User firstName")
    private String firtName;

    @ApiModelProperty("User lastName")
    private String lastName;
    
    @ApiModelProperty("User email")
    private String email;

    
    public User(String firtName, String lastName, String email) {
        this.firtName = firtName;
        this.lastName = lastName;
        this.email = email;
    }

    public User() {};


    public String getFirtName() {
        return firtName;
    }


    public void setFirtName(String firtName) {
        this.firtName = firtName;
    }


    public String getLastName() {
        return lastName;
    }


    public void setLastName(String lastName) {
        this.lastName = lastName;
    }


    public String getEmail() {
        return email;
    }


    public void setEmail(String email) {
        this.email = email;
    }


}
