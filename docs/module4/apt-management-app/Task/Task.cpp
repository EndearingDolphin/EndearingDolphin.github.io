/*
    Name: Justin Fifarek
    Project: Appointment management app
    Module: Task class file
*/
#include <iostream>
#include <string>
#include <atomic>
#include "Task.h"

// Constructor
Task::Task(std::string taskName, std::string taskDesc) {
    // TaskID is generated when constructor is called
    this->taskID = std::to_string(idGenerator++);

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
std::string Task::getTaskID() {
    return taskID;
}

std::string Task::getTaskName() {
    return taskName;
}

std::string Task::getTaskDesc() {
    return taskDesc;
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