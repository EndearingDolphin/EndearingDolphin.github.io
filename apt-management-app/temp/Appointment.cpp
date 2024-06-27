/*
    Name: Justin Fifarek
    Project: Appointment management app
    Module: Appointment class file
*/
#include <iostream>
#include <string>
#include <atomic>
#include <ctime>

#include "../includes/Appointment.h"

// Initialize first ID number
unsigned int Appointment::nextID = 0;

Appointment::Appointment(std::time_t appointmentDate, std::string appointmentDesc) {
    // appointmentID is generated when constructor is called
    this->appointmentID = ++nextID;

    // appointmentDate cannot be before the current date
    std::time_t now = std::time(nullptr);
    if (appointmentDate < now) {
        throw std::invalid_argument("Invalid date. Date cannot be in the past.");
    }
    this->appointmentDate = appointmentDate;

    // appointmentDesc cannot be more than 50 characters
    // and cannot be null
    if (appointmentDesc.empty()) {
        this->appointmentDesc = appointmentDesc;
    }
    else if (appointmentDesc.length() > 50) {
        this->appointmentDesc = appointmentDesc.substr(0, 50);
    }
    else {
        this->appointmentDesc = appointmentDesc;
    }
}

// Getters
std::string Appointment::getAppointmentID() {
    return appointmentID;
}

std::time_t Appointment::getAppointmentDate() {
    return appointmentDate;
}

std::string Appointment::getAppointmentDesc() {
    return appointmentDesc;
}

// Setters
// Set up the same as in constructor
void Appointment::setAppointmentDate(std::time_t appointmentDate) {
    std::time_t now = std::time(nullptr);
    if (appointmentDate < now) {
        throw std::invalid_argument("Invalid date. Date cannot be in the past.");
    }
    this->appointmentDate = appointmentDate;
}

void Appointment::setAppointmentDesc(const std::string& appointmentDesc) {
    if (appointmentDesc.empty()) {
        this->appointmentDesc = appointmentDesc;
    }
    else if (appointmentDesc.length() > 50) {
        this->appointmentDesc = appointmentDesc.substr(0, 50);
    }
    else {
        this->appointmentDesc = appointmentDesc;
    }
};
