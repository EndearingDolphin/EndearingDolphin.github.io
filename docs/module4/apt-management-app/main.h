/*
    Name: Justin Fifarek
    Project: Appointment management app
    Module: main header
*/

#pragma once

// Includes for each module
#include ".\Contact\Contact.h"
#include ".\Contact\ContactService.h"

#include ".\Task\Task.h"
#include ".\Task\TaskService.h"

#include ".\Appointment\Appointment.h"
#include ".\Appointment\AppointmentService.h"

// Main functions declaration
void displayMenu();
void processMenu(int option);
void contactsMenu();
void tasksMenu();
void appointmentsMenu();
int main();