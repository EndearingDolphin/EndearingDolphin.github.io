/*
    Name: Justin Fifarek
    Project: AppointmentService class
*/
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include ".\Appointment\Appointment.cpp"

class AppointmentService {
public:
    // Vector to store appointments
    std::vector<Appointment> appointmentList;

    // Display all appointments in the list
    void displayApptList() {
        for (size_t i = 0; i < appointmentList.size(); ++i) {
            std::cout << "Appointment ID: " << appointmentList[i].getAppointmentID() << std::endl;
            std::cout << "Appointment Date: " << appointmentList[i].getAppointmentDate() << std::endl;
            std::cout << "Appointment Description: " << appointmentList[i].getAppointmentDesc() << std::endl;
        }
    }

    // Adds new appointment using the appointment constructor
    void addAppointment(std::time_t appointmentDate, std::string appointmentDesc) {
        // Create the new appointment
        Appointment appointment(appointmentDate, appointmentDesc);
        appointmentList.push_back(appointment);
    }

    // Returns an appointment given appointmentID, if it exists. 
    // Otherwise, returns a default appointment
    Appointment getAppointment(std::string appointmentID) {
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
    void deleteAppointment(const std::string& appointmentID) {
        for (auto it = appointmentList.begin(); it != appointmentList.end(); ++it) {
            if (it->getAppointmentID() == appointmentID) {
                appointmentList.erase(it);
                return;
            }
        }
        std::cout << "Appointment ID: " << appointmentID << " not found." << std::endl;
    }

    // Updates appointmentDate of appointmentID given a newDate
    void updateAppointmentDate(std::time_t newDate, std::string appointmentID) {
        for (size_t i = 0; i < appointmentList.size(); ++i) {
            if (appointmentList[i].getAppointmentID() == appointmentID) {
                appointmentList[i].setAppointmentDate(newDate);
                return;
            }
        }
        std::cout << "Appointment ID: " << appointmentID << " not found." << std::endl;
    }

    // Updates appointmentDesc of given appointmentID
    void updateAppointmentDesc(std::string newDesc, std::string appointmentID) {
        for (size_t i = 0; i < appointmentList.size(); ++i) {
            if (appointmentList[i].getAppointmentID() == appointmentID) {
                appointmentList[i].setAppointmentDesc(newDesc);
                return;
            }
        }
        std::cout << "Appointment ID: " << appointmentID << " not found." << std::endl;
    }
};