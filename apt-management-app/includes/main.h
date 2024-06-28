/*
    Name: Justin Fifarek
    Project: Appointment management app
    Module: main header
*/

#pragma once

// Includes for each module
#include "Contact.h"
#include "ContactService.h"

#include "Task.h"
#include "TaskService.h"

#include "Appointment.h"
#include "AppointmentService.h"

// Main functions declaration
void displayMenu();
void processMenu(int option);
void contactsMenu();
void tasksMenu();
void appointmentsMenu();
int main();

// Class initializations
ContactService contactService;
TaskService taskService;
AppointmentService appointmentService;