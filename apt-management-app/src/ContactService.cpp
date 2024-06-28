/*
    Name: Justin Fifarek
    Project: Appointment management app
    Module: ContactService class file
*/
#include <atomic>
#include <vector>

#include "../includes/ContactService.h"

// Display list of stored contacts
void ContactService::displayContacts() {
    for (auto contact : contactList) {
        std::cout << " Contact ID: " << contact.getContactID() << std::endl;
        std::cout << " First Name: " << contact.getFirstName() << std::endl;
        std::cout << " Last Name: " << contact.getLastName() << std::endl;
        std::cout << " Phone Number: " << contact.getPhone() << std::endl;
        std::cout << " Address: " << contact.getAddress() << std::endl;
        for (size_t x = 0; x < contact.getAddress().length() + 10; ++x) {
            std::cout << "-";
        }
        std::cout << std::endl;
    }
}

// Display contact of given contactID
bool ContactService::displayOneContact(unsigned int contactID) {
    for (auto contact : contactList) {
        if (contact.getContactID() == contactID) {
            std::cout << " Contact ID: " << contact.getContactID() << std::endl;
            std::cout << " First Name: " << contact.getFirstName() << std::endl;
            std::cout << " Last Name: " << contact.getLastName() << std::endl;
            std::cout << " Phone Number: " << contact.getPhone() << std::endl;
            std::cout << " Address: " << contact.getAddress() << std::endl;
            for (size_t x = 0; x < contact.getAddress().length() + 10; ++x) {
                std::cout << "-";
            }
            std::cout << std::endl;
            return true;
        }
    }
    std::cout << "Contact ID " << contactID << " not found." << std::endl;
    return false;
}

// Adds new contact using the contact constructor
void ContactService::addContact(std::string firstName, std::string lastName, std::string phone, std::string address) {
    Contact contact(firstName, lastName, phone, address);
    contactList.push_back(contact);
}

// Searches through contactList vector and returns the contact
// of given contactID, if it exists.
Contact ContactService::getContact(unsigned int contactID) {
    for (size_t i = 0; i < contactList.size(); ++i) {
        if (contactList[i].getContactID() == contactID) {
            return contactList[i];
        }
    }
    return Contact("", "", "", "");
}

// Searches through contactList vector and deletes the contact
// of given contactID, if it exists.
void ContactService::deleteContact(unsigned int contactID) {
    for (auto it = contactList.begin(); it != contactList.end(); ++it) {
        if (it->getContactID() == contactID) {
            contactList.erase(it);
            return;
        }
    }
    std::cout << "Contact ID: " << contactID << " not found." << std::endl;
}

// Searches through contactList vector and updates the firstName
// of given contactID, if it exists.
void ContactService::updateFirstName(std::string updatedString, unsigned int contactID) {
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
void ContactService::updateLastName(std::string updatedString, unsigned int contactID) {
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
void ContactService::updatePhone(std::string updatedString, unsigned int contactID) {
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
void ContactService::updateAddress(std::string updatedString, unsigned int contactID) {
    for (size_t i = 0; i < contactList.size(); ++i) {
        if (contactList[i].getContactID() == contactID) {
            contactList[i].setAddress(updatedString);
            return;
        }
    }
    std::cout << "Contact ID: " << contactID << " not found." << std::endl;
};
