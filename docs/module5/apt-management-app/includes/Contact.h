/*
    Name: Justin Fifarek
    Project: Appointment management app
    Module: Contact class header
*/
#pragma once

#include <string>

class Contact {
private:
    unsigned int contactID;
    std::string firstName;
    std::string lastName;
    std::string phone;
    std::string address;
    static unsigned int nextID;

public:
    // Constructor
    Contact(std::string firstName, std::string lastName, std::string phone, std::string address);

    // Getters
    unsigned int getContactID();
    std::string getFirstName();
    std::string getLastName();
    std::string getPhone();
    std::string getAddress();

    // Setters
    void setFirstName(std::string firstName);
    void setLastName(std::string lastName);
    void setPhone(std::string phone);
    void setAddress(std::string address);
};
