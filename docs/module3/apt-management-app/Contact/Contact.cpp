/*
    Name: Justin Fifarek
    Project: Contact class
*/
#include <iostream>
#include <string>
#include <atomic>

class Contact {
private:
    std::string contactID;
    std::string firstName;
    std::string lastName;
    std::string phone;
    std::string address;
    static std::atomic<long> idGenerator;

public:
    Contact(std::string firstName, std::string lastName, std::string phone, std::string address) {
        this->contactID = std::to_string(idGenerator++);

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
        if (phone.empty()) {
            this->phone = "1234567890";
        }
        else if (phone.length() > 10) {
            this->phone = phone.substr(0, 10);
        }
        else {
            this->phone = phone;
        }

        if (address.empty()) {
            this->address = "NULL";
        }
        else if (address.length() > 10) {
            this->address = address.substr(0, 10);
        }
        else {
            this->address = address;
        }
    }

    // Getters
    std::string getContactID() {
        return this->contactID;
    }
    std::string getFirstName() {
        return this->firstName;
    }
    std::string getLastName() {
        return this->lastName;
    }
    std::string getPhone() {
        return this->phone;
    }
    std::string getAddress() {
        return this->address;
    }

    // Setters (uses the same criteria as constructor)
    void setFirstName(std::string firstName) {
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
    void setLastName(std::string lastName) {
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
    void setPhone(std::string phone) {
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
    void setAddress(std::string address) {
        if (address.empty()) {
            this->address = "NULL";
        }
        else if (address.length() > 10) {
            this->address = address.substr(0, 10);
        }
        else {
            this->address = address;
        }
    }
};