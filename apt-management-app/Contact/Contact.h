/*
    Name: Justin Fifarek
    Project: Appointment management app
    Module: Contact class header
*/
#pragma once

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
    Contact(std::string firstName, std::string lastName, std::string phone, std::string address);

    // Getters
    std::string getContactID();
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
