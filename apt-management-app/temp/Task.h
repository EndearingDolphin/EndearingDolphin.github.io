/*
    Name: Justin Fifarek
    Project: Appointment management app
    Module: Task header
*/
#pragma once

#include <iostream>
#include <string>
#include <atomic>

class Task {
private:
    std::string taskID;
    std::string taskName;
    std::string taskDesc;
    static unsigned int nextID;

public:
    Task(std::string taskName, std::string taskDesc);

    // Getters
    std::string getTaskID();
    std::string getTaskName();
    std::string getTaskDesc();

    // Setters
    void setTaskName(std::string taskName);
    void setTaskDesc(std::string taskDesc);
};

// Initialize first ID number
unsigned int Task::nextID = 0;