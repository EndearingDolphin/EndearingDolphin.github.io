/*
    Name: Justin Fifarek
    Project: Appointment management app
    Module: Appointment class file
*/

#include "../includes/Appointment.h"

// Initialize first ID number
unsigned int Appointment::nextID = 0;

// Parse date and time string into a time_point
std::chrono::system_clock::time_point Appointment::parseDateTime(const std::string& dateTimeString) {
    try {
        std::tm tm = {};
        std::istringstream ss(dateTimeString);
        ss >> std::get_time(&tm, "%Y-%m-%d %H:%M:%S");
        if (ss.fail()) {
            throw std::runtime_error("Failed to parse date/time string");
        }
        return std::chrono::system_clock::from_time_t(std::mktime(&tm));
    }
    catch (const std::exception&) {
        std::cout << "Failed to parse date/time string" << std::endl;
        return std::chrono::system_clock::now() + std::chrono::hours(1);
    }
}

bool Appointment::isBeforeNow(const std::string& dateTimeStr) {
    auto inputTime = parseDateTime(dateTimeStr);
    auto now = std::chrono::system_clock::now();
    return inputTime < now;
}

Appointment::Appointment(std::string appointmentDate, std::string appointmentDesc) {
    // appointmentID is generated when constructor is called
    this->appointmentID = ++nextID;

    // appointmentDate cannot be before the current date
    if (isBeforeNow(appointmentDate)) {
        std::cout << "Invalid date. Date cannot be in the past." << std::endl;
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
unsigned int Appointment::getAppointmentID() {
    return this->appointmentID;
}

std::string Appointment::getAppointmentDate() {
    return this->appointmentDate;
}

std::string Appointment::getAppointmentDesc() {
    return this->appointmentDesc;
}

// Setters
// Set up the same as in constructor
bool Appointment::setAppointmentDate(std::string appointmentDate) {
    if (isBeforeNow(appointmentDate)) {
        std::cout << "Invalid date. Date cannot be in the past." << std::endl;
        return false;
    }
    this->appointmentDate = appointmentDate;
    return true;
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
