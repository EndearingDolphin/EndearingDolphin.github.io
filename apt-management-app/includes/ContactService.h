/*
    Name: Justin Fifarek
    Project: Appointment management app
    Module: ContactService header
*/
#pragma once

#include "Contact.h"
#include <iostream>
#include <vector>

class ContactService {
private:
    std::vector<Contact> contactList;

public:
    void displayContacts();
    bool displayOneContact(unsigned int contactID);
    void addContact(std::string firstName, std::string lastName, std::string phone, std::string address);
    Contact getContact(unsigned int contactID);
    void deleteContact(unsigned int contactID);
    void updateFirstName(std::string updatedString, unsigned int contactID);
    void updateLastName(std::string updatedString, unsigned int contactID);
    void updatePhone(std::string updatedString, unsigned int contactID);
    void updateAddress(std::string updatedString, unsigned int contactID);
};
