/*
    Name: Justin Fifarek
    Project: Appointment management app
    Module: AppointmentService header
*/
#pragma once

#include <vector>
#include "Appointment.h"

class AppointmentService {
private:
    std::vector<Appointment> appointmentList;

public:
    std::chrono::system_clock::time_point parseDateTime(const std::string& dateTimeString);

    void displayAppointments();
    bool displayOneAppointment(unsigned int appointmentID);
    void addAppointment(std::string appointmentDate, std::string appointmentDesc);
    Appointment getAppointment(unsigned int appointmentID);
    void deleteAppointment(unsigned int appointmentID);
    void updateAppointmentDate(std::string newDate, unsigned int appointmentID);
    void updateAppointmentDesc(std::string newDesc, unsigned int appointmentID);
};