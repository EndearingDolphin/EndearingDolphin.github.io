/*
    Name: Justin Fifarek
    Project: Appointment management app
    Module: TaskService class file
*/
#include <iostream>
#include <vector>

#include "../includes/TaskService.h"

// Display all tasks within task list
void TaskService::displayTasks() {
    for (auto task : taskList) {
        std::cout << "Task ID: " << task.getTaskID() << std::endl;
        std::cout << " Task Name: " << task.getTaskName() << std::endl;
        std::cout << " Task Description: " << task.getTaskDesc() << std::endl;
        for (size_t x = 0; x < task.getTaskDesc().length(); ++x) {
            std::cout << "-";
        }
        std::cout << std::endl;
    }
}

// Display given taskID from taskList
bool TaskService::displayOneTask(unsigned int taskID) {
    for (auto task : taskList) {
        if (task.getTaskID() == taskID) {
            std::cout << " Task ID: " << task.getTaskID() << std::endl;
            std::cout << " Task Name: " << task.getTaskName() << std::endl;
            std::cout << " Task Description: " << task.getTaskDesc() << std::endl;
            for (size_t x = 0; x < task.getTaskDesc().length(); ++x) {
                std::cout << "-";
            }
            std::cout << std::endl;
            return true;
        }
    }
    std::cout << "Task ID: " << taskID << " not found." << std::endl;
    return false;
}

// Searches through taskList vector and returns the task
// of given taskID, if it exists.
Task TaskService::getTask(unsigned int taskID) {
    for (size_t i = 0; i < taskList.size(); ++i) {
        if (taskList[i].getTaskID() == taskID) {
            return taskList[i];
        }
    }
    return Task("", "");
}

// Adds new task using the task constructor
void TaskService::addTask(std::string taskName, std::string taskDesc) {
    Task task(taskName, taskDesc);
    taskList.push_back(task);
}

// Delete task given a taskID
void TaskService::deleteTask(unsigned int taskID) {
    for (auto it = taskList.begin(); it != taskList.end(); ++it) {
        if (it->getTaskID() == taskID) {
            taskList.erase(it);
            return;
        }
    }
    std::cout << "Task ID " << taskID << " not found." << std::endl;
}

// Searches through taskList vector and updates taskName
// of given taskID, if it exists.
void TaskService::updateTaskName(std::string newTaskName, unsigned int taskID) {
    for (auto& task : taskList) {
        if (task.getTaskID() == taskID) {
            task.setTaskName(newTaskName);
            return;
        }
    }
    std::cout << "Task ID: " << taskID << " not found." << std::endl;
}

// Searches through taskList vector and updates taskDesc
// of given taskID, if it exists.
void TaskService::updateTaskDesc(std::string newTaskDesc, unsigned int taskID) {
    for (auto& task : taskList) {
        if (task.getTaskID() == taskID) {
            task.setTaskDesc(newTaskDesc);
            return;
        }
    }
    std::cout << "Task ID: " << taskID << " not found." << std::endl;
};
