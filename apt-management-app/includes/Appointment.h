/*
    Name: Justin Fifarek
    Project: Appointment management app
    Module: Appointment header
*/
#pragma once

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <chrono>
#include <ctime>

class Appointment {
private:
    unsigned int appointmentID;
    std::string appointmentDate;
    std::string appointmentDesc;
    static unsigned int nextID;

public:
    std::chrono::system_clock::time_point parseDateTime(const std::string& dateTimeString);

    Appointment(std::string appointmentDate, std::string appointmentDesc);

    bool isBeforeNow(const std::string& dateTimeStr);

    // Getters
    unsigned int getAppointmentID();
    std::string getAppointmentDate();
    std::string getAppointmentDesc();
    
    // Setters
    bool setAppointmentDate(std::string appointmentDate);
    void setAppointmentDesc(const std::string& appointmentDesc);
};
