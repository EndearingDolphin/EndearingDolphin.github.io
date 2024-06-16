/*
    Name: Justin Fifarek
    Project: Appointment management app
    Module: AppointmentService class file
*/
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include "AppointmentService.h"

// Display all appointments in the list
void AppointmentService::displayApptList() {
    std::cout << "ApptService display appt list function reached" << std::endl;
    for (size_t i = 0; i < appointmentList.size(); ++i) {
        std::cout << "Appointment ID: " << appointmentList[i].getAppointmentID() << std::endl;
        std::cout << "Appointment Date: " << appointmentList[i].getAppointmentDate() << std::endl;
        std::cout << "Appointment Description: " << appointmentList[i].getAppointmentDesc() << std::endl;
    }
}

// Adds new appointment using the appointment constructor
void AppointmentService::addAppointment(std::time_t appointmentDate, std::string appointmentDesc) {
    // Create the new appointment
    Appointment appointment(appointmentDate, appointmentDesc);
    appointmentList.push_back(appointment);
}

// Returns an appointment given appointmentID, if it exists. 
// Otherwise, returns a default appointment
Appointment AppointmentService::getAppointment(std::string appointmentID) {
    for (size_t i = 0; i < appointmentList.size(); ++i) {
        if (appointmentList[i].getAppointmentID() == appointmentID) {
            return appointmentList[i];
        }
    }
    // FIXME: Fix returning a default/empty appointment object
    //return Appointment();
}

// Loops through appointmentList for given appointmentID 
// and deletes it if found.
void AppointmentService::deleteAppointment(const std::string& appointmentID) {
    for (auto it = appointmentList.begin(); it != appointmentList.end(); ++it) {
        if (it->getAppointmentID() == appointmentID) {
            appointmentList.erase(it);
            return;
        }
    }
    std::cout << "Appointment ID: " << appointmentID << " not found." << std::endl;
}

// Updates appointmentDate of appointmentID given a newDate
void AppointmentService::updateAppointmentDate(std::time_t newDate, std::string appointmentID) {
    for (size_t i = 0; i < appointmentList.size(); ++i) {
        if (appointmentList[i].getAppointmentID() == appointmentID) {
            appointmentList[i].setAppointmentDate(newDate);
            return;
        }
    }
    std::cout << "Appointment ID: " << appointmentID << " not found." << std::endl;
}

// Updates appointmentDesc of given appointmentID
void AppointmentService::updateAppointmentDesc(std::string newDesc, std::string appointmentID) {
    for (size_t i = 0; i < appointmentList.size(); ++i) {
        if (appointmentList[i].getAppointmentID() == appointmentID) {
            appointmentList[i].setAppointmentDesc(newDesc);
            return;
        }
    }
    std::cout << "Appointment ID: " << appointmentID << " not found." << std::endl;
};