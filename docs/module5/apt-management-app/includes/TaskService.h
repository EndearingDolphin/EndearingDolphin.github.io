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
    bool displayOneTask(unsigned int taskID);
    Task getTask(unsigned int taskID);
    void addTask(std::string taskName, std::string taskDesc);
    void deleteTask(unsigned int taskID);
    void updateTaskName(std::string newTaskName, unsigned int taskID);
    void updateTaskDesc(std::string newTaskDesc, unsigned int taskID);
};