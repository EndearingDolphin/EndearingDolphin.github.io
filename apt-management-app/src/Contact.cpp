/*
    Name: Justin Fifarek
    Project: Appointment management app
    Module: Contact class file
*/
#include <iostream>
#include <string>

#include "../includes/Contact.h"

// nextID initialization
unsigned int Contact::nextID = 0;

Contact::Contact(std::string firstName, std::string lastName, std::string phone, std::string address) {
    this->contactID = ++nextID;

    // firstName cannot be more than 10 characters
    // and cannot be null
    if (firstName.empty()) {
        this->firstName = "NULL";
    }
    else if (firstName.length() > 10) {
        this->firstName = firstName.substr(0, 10);
    }
    else {
        this->firstName = firstName;
    }

    // lastName cannot be more than 10 characters
    // and cannot be null
    if (lastName.empty()) {
        this->lastName = "NULL";
    }
    else if (lastName.length() > 10) {
        this->lastName = lastName.substr(0, 10);
    }
    else {
        this->lastName = lastName;
    }

    // phone must be exactly 10 digits
    // and cannot be null
    if (phone.empty() or phone.length() < 10) {
        this->phone = "1234567890";
    }
    else if (phone.length() > 10) {
        this->phone = phone.substr(0, 10);
    }
    else {
        this->phone = phone;
    }
    
    // address cannot be more than 30 characters
    // and cannot be null
    if (address.empty()) {
        this->address = "NULL";
    }
    else if (address.length() > 30) {
        this->address = address.substr(0, 30);
    }
    else {
        this->address = address;
    }
}

// Getters
unsigned int Contact::getContactID() {
    return this->contactID;
}
std::string Contact::getFirstName() {
    return this->firstName;
}
std::string Contact::getLastName() {
    return this->lastName;
}
std::string Contact::getPhone() {
    return this->phone;
}
std::string Contact::getAddress() {
    return this->address;
}

// Setters
void Contact::setFirstName(std::string firstName) {
    if (firstName.empty()) {
        this->firstName = "NULL";
    }
    else if (firstName.length() > 10) {
        this->firstName = firstName.substr(0, 10);
    }
    else {
        this->firstName = firstName;
    }
}
void Contact::setLastName(std::string lastName) {
    if (lastName.empty()) {
        this->lastName = "NULL";
    }
    else if (lastName.length() > 10) {
        this->lastName = lastName.substr(0, 10);
    }
    else {
        this->lastName = lastName;
    }
}
void Contact::setPhone(std::string phone) {
    if (phone.empty()) {
        this->phone = "1234567890";
    }
    else if (phone.length() > 10) {
        this->phone = phone.substr(0, 10);
    }
    else {
        this->phone = phone;
    }
}
void Contact::setAddress(std::string address) {
    if (address.empty()) {
        this->address = "NULL";
    }
    else if (address.length() > 10) {
        this->address = address.substr(0, 10);
    }
    else {
        this->address = address;
    }
};
