#pragma once

#include "Contact.h"
#include <iostream>
#include <vector>

class ContactService {
private:
    // Vector to hold list of contacts
    std::vector<Contact> contactList;

public:
    // Display list of stored contacts
    void displayContacts();

    // Adds new contact using the contact constructor
    void addContact(std::string firstName, std::string lastName, std::string phone, std::string address);

    // Searches through contactList vector and returns the contact
    // of given contactID, if it exists.
    Contact getContact(std::string contactID);
    
    // Searches through contactList vector and deletes the contact
    // of given contactID, if it exists.
    void deleteContact(std::string contactID);

    // Searches through contactList vector and updates the firstName
    // of given contactID, if it exists.
    void updateFirstName(std::string updatedString, std::string contactID);

    // Searches through contactList vector and updates the lastName
    // of given contactID, if it exists.
    void updateLastName(std::string updatedString, std::string contactID);

    // Searches through contactList vector and updates the phone
    // of given contactID, if it exists.
    void updatePhone(std::string updatedString, std::string contactID);

    // Searches through contactList vector and updates the address
    // of given contactID, if it exists.
    void updateAddress(std::string updatedString, std::string contactID);
};
