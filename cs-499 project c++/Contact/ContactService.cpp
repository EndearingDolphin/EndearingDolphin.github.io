/*
    Name: Justin Fifarek
    Project: ContactService class
*/
#include <atomic>
#include <vector>
#include "Contact.h"
#include "ContactService.h"

// Display list of stored contacts
void ContactService::displayContacts() {
    for (size_t i = 0; i < contactList.size(); ++i) {
        std::cout << " Contact ID: " << contactList[i].getContactID() << std::endl;
        std::cout << " First Name: " << contactList[i].getFirstName() << std::endl;
        std::cout << " Last Name: " << contactList[i].getLastName() << std::endl;
        std::cout << " Phone Number: " << contactList[i].getPhone() << std::endl;
        std::cout << " Address: " << contactList[i].getAddress() << std::endl;
        for (size_t x = 0; x < contactList[i].getAddress().length() + 9; ++x) {
            std::cout << "-";
        }
        std::cout << std::endl;
    }
}

// Adds new contact using the contact constructor
void ContactService::addContact(std::string firstName, std::string lastName, std::string phone, std::string address) {
    Contact contact(firstName, lastName, phone, address);
    contactList.push_back(contact);
}

// Searches through contactList vector and returns the contact
// of given contactID, if it exists.
Contact ContactService::getContact(std::string contactID) {
    for (size_t i = 0; i < contactList.size(); ++i) {
        if (contactList[i].getContactID() == contactID) {
            return contactList[i];
        }
    }
    return Contact("", "", "", "");
}

// Searches through contactList vector and deletes the contact
// of given contactID, if it exists.
void ContactService::deleteContact(std::string contactID) {
    for (auto it = contactList.begin(); it != contactList.end(); ++it) {
        if (it->getContactID() == contactID) {
            contactList.erase(it);
            return;
        }
    }
}

// Searches through contactList vector and updates the firstName
// of given contactID, if it exists.
void ContactService::updateFirstName(std::string updatedString, std::string contactID) {
    for (size_t i = 0; i < contactList.size(); ++i) {
        if (contactList[i].getContactID() == contactID) {
            contactList[i].setFirstName(updatedString);
            return;
        }
    }
    std::cout << "Contact ID: " << contactID << " not found." << std::endl;
}

// Searches through contactList vector and updates the lastName
// of given contactID, if it exists.
void ContactService::updateLastName(std::string updatedString, std::string contactID) {
    for (size_t i = 0; i < contactList.size(); ++i) {
        if (contactList[i].getContactID() == contactID) {
            contactList[i].setLastName(updatedString);
            return;
        }
    }
    std::cout << "Contact ID: " << contactID << " not found." << std::endl;
}

// Searches through contactList vector and updates the phone
// of given contactID, if it exists.
void ContactService::updatePhone(std::string updatedString, std::string contactID) {
    for (size_t i = 0; i < contactList.size(); ++i) {
        if (contactList[i].getContactID() == contactID) {
            contactList[i].setPhone(updatedString);
            return;
        }
    }
    std::cout << "Contact ID: " << contactID << " not found." << std::endl;
}

// Searches through contactList vector and updates the address
// of given contactID, if it exists.
void ContactService::updateAddress(std::string updatedString, std::string contactID) {
    for (size_t i = 0; i < contactList.size(); ++i) {
        if (contactList[i].getContactID() == contactID) {
            contactList[i].setAddress(updatedString);
            return;
        }
    }
    std::cout << "Contact ID: " << contactID << " not found." << std::endl;
};