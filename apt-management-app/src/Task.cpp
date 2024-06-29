/*
    Name: Justin Fifarek
    Project: Appointment management app
    Module: Task class file
*/
#include <iostream>
#include <string>
#include <atomic>

#include "../includes/Task.h"

// Initialize first ID number
unsigned int Task::nextID = 0;

// Constructor
Task::Task(std::string taskName, std::string taskDesc) {
    // TaskID is generated when constructor is called
    this->taskID = ++nextID;

    // taskName cannot be more than 20 characters
    // and cannot be empty
    if (taskName.empty()) {
        this->taskName = "NULL";
    } else if (taskName.length() > 20) {
        this->taskName = taskName.substr(0, 20);
    } else {
        this->taskName = taskName;
    }
    
    // taskDesc cannot be more than 50 characters
    // and cannot be empty
    if (taskDesc.empty()) {
        this->taskDesc = "NULL";
    } else if (taskDesc.length() > 50) {
        this->taskDesc = taskDesc.substr(0, 50);
    } else {
        this->taskDesc = taskDesc;
    }
}

// Getters
unsigned int Task::getTaskID() {
    return this->taskID;
}

std::string Task::getTaskName() {
    return this->taskName;
}

std::string Task::getTaskDesc() {
    return this->taskDesc;
}

// Setters
// Set up variables with the same
// conditions as the constructor.
void Task::setTaskName(std::string taskName) {
    if (taskName.empty()) {
        this->taskName = "NULL";
    } else if (taskName.length() > 20) {
        this->taskName = taskName.substr(0, 20);
    } else {
        this->taskName = taskName;
    }
}

void Task::setTaskDesc(std::string taskDesc) {
    if (taskDesc.empty()) {
        this->taskDesc = "NULL";
    } else if (taskDesc.length() > 50) {
        this->taskDesc = taskDesc.substr(0, 50);
    } else {
        this->taskDesc = taskDesc;
    }
};