/*
    Name: Justin Fifarek
    Project: Appointment management app
    Module: AppointmentService header
*/
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
    void displayAppointments();
    bool displayOneAppointment(unsigned int appointmentID);
    void addAppointment(std::time_t appointmentDate, std::string appointmentDesc);
    Appointment getAppointment(unsigned int appointmentID);
    void deleteAppointment(unsigned int appointmentID);
    void updateAppointmentDate(std::time_t newDate, unsigned int appointmentID);
    void updateAppointmentDesc(std::string newDesc, unsigned int appointmentID);
};