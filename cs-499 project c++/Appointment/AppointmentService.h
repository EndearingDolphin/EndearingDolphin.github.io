#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include "Appointment.h"

class AppointmentService {
private:
    std::vector<Appointment> appointmentList;

public:
    void displayApptList();
    void addAppointment(std::time_t appointmentDate, std::string appointmentDesc);
    Appointment getAppointment(std::string appointmentID);
    void deleteAppointment(const std::string& appointmentID);
    void updateAppointmentDate(std::time_t newDate, std::string appointmentID);
    void updateAppointmentDesc(std::string newDesc, std::string appointmentID);
};