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
    void addContact(std::string firstName, std::string lastName, std::string phone, std::string address);
    Contact getContact(std::string contactID);
    void deleteContact(std::string contactID);
    void updateFirstName(std::string updatedString, std::string contactID);
    void updateLastName(std::string updatedString, std::string contactID);
    void updatePhone(std::string updatedString, std::string contactID);
    void updateAddress(std::string updatedString, std::string contactID);
};
