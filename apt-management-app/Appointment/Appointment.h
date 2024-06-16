/*
    Name: Justin Fifarek
    Project: Appointment management app
    Module: Appointment header
*/
#pragma once

#include <iostream>
#include <string>
#include <atomic>
#include <ctime>

class Appointment {
private:
    std::string appointmentID;
    std::time_t appointmentDate;
    std::string appointmentDesc;
    static std::atomic<long> idGenerator;

public:
    Appointment(std::time_t appointmentDate, std::string appointmentDesc) {
        // appointmentID is generated when constructor is called
        this->appointmentID = std::to_string(idGenerator++);

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
    std::string getAppointmentID();
    std::time_t getAppointmentDate();
    std::string getAppointmentDesc();
    void setAppointmentDate(std::time_t appointmentDate);
    void setAppointmentDesc(const std::string& appointmentDesc);
};