/*
    Name: Justin Fifarek
    Project: Appointment management app
    Module: TaskService header
*/
#pragma once

#include <iostream>
#include <vector>
#include "Task.h"

class TaskService {
private:
    std::vector<Task> taskList;

public:
    void displayTasks();
    Task getTask(std::string taskID);
    void addTask(std::string taskName, std::string taskDesc);
    void deleteTask(const std::string& taskID);
    void updateTaskName(const std::string& newTaskName, const std::string& taskID);
    void updateTaskDesc(const std::string& newTaskDesc, const std::string& taskID);
};