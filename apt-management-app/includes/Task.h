/*
    Name: Justin Fifarek
    Project: Appointment management app
    Module: Task header
*/
#pragma once

#include <iostream>
#include <string>

class Task {
private:
    unsigned int taskID;
    std::string taskName;
    std::string taskDesc;
    static unsigned int nextID;

public:
    Task(std::string taskName, std::string taskDesc);

    // Getters
    unsigned int getTaskID();
    std::string getTaskName();
    std::string getTaskDesc();

    // Setters
    void setTaskName(std::string taskName);
    void setTaskDesc(std::string taskDesc);
};
