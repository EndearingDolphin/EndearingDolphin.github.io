/*
    Name: Justin Fifarek
    Project: Appointment management app
    Module: AppointmentService class file
*/

#include "../includes/AppointmentService.h"

// Display all appointments in the list
void AppointmentService::displayAppointments() {
    for (auto appointment : appointmentList) {
        std::cout << "Appointment ID: " << appointment.getAppointmentID() << std::endl;
        std::cout << " Appointment Date: " << appointment.getAppointmentDate() << std::endl;
        std::cout << " Appointment Description: " << appointment.getAppointmentDesc() << std::endl;
    }
}

// Display given appointmentID from appointmentList
bool AppointmentService::displayOneAppointment(unsigned int appointmentID) {
    for (auto appointment : appointmentList) {
        if (appointment.getAppointmentID() == appointmentID) {
            std::cout << "Appointment ID: " << appointment.getAppointmentID() << std::endl;
            std::cout << " Appointment Date: " << appointment.getAppointmentDate() << std::endl;
            std::cout << " Appointment Description: " << appointment.getAppointmentDesc() << std::endl;
            for (size_t x = 0; x < appointment.getAppointmentDesc().length(); ++x) {
                std::cout << "-";
            }
            std::cout << std::endl;
            return true;
        }
    }
    return false;
}

// Adds new appointment using the appointment constructor
void AppointmentService::addAppointment(std::string appointmentDate, std::string appointmentDesc) {
    // Create the new appointment
    Appointment appointment(appointmentDate, appointmentDesc);
    appointmentList.push_back(appointment);
}

// Returns an appointment given appointmentID, if it exists. 
// Otherwise, returns a default appointment
Appointment AppointmentService::getAppointment(unsigned int appointmentID) {
    for (auto appointment : appointmentList) {
        if (appointment.getAppointmentID() == appointmentID) {
            return appointment;
        }
    }
    return Appointment("", "");
}

// Loops through appointmentList for given appointmentID 
// and deletes it if found.
void AppointmentService::deleteAppointment(unsigned int appointmentID) {
    for (auto it = appointmentList.begin(); it != appointmentList.end(); ++it) {
        if (it->getAppointmentID() == appointmentID) {
            appointmentList.erase(it);
            return;
        }
    }
    std::cout << "Appointment ID: " << appointmentID << " not found." << std::endl;
}

// Updates appointmentDate of appointmentID given a newDate
void AppointmentService::updateAppointmentDate(std::string newDate, unsigned int appointmentID) {
    for (auto appointment : appointmentList) {
        if (appointment.getAppointmentID() == appointmentID) {
            appointment.setAppointmentDate(newDate);
            return;
        }
    }
    std::cout << "Appointment ID: " << appointmentID << " not found." << std::endl;
}

// Updates appointmentDesc of given appointmentID
void AppointmentService::updateAppointmentDesc(std::string newDesc, unsigned int appointmentID) {
    for (auto appointment : appointmentList) {
        if (appointment.getAppointmentID() == appointmentID) {
            appointment.setAppointmentDesc(newDesc);
            return;
        }
    }
    std::cout << "Appointment ID: " << appointmentID << " not found." << std::endl;
};