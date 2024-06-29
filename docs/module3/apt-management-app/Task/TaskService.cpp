/*
    Name: Justin Fifarek
    Project: TaskService class
*/
#include <iostream>
#include <vector>
#include "Task.cpp"

class TaskService {
private:
    // Vector to hold tasks
    std::vector<Task> taskList;

public:
    // Display tasks
    void displayTasks() {
        for (size_t i = 0; i < taskList.size(); ++i) {
            std::cout << "Task ID:  " << taskList[i].getTaskID() << std::endl;
            std::cout << "Task Name: " << taskList[i].getTaskName() << std::endl;
            std::cout << "Task Description: " << taskList[i].getTaskDesc() << std::endl;
        }
    }

    // Searches through taskList vector and returns the task
    // of given taskID, if it exists.
    Task getTask(std::string taskID) {
        for (size_t i = 0; i < taskList.size(); ++i) {
            if (taskList[i].getTaskID() == taskID) {
                return taskList[i];
            }
        }
        return Task("", "");
    }

    // Adds new task using the task constructor
    void addTask(std::string taskName, std::string taskDesc) {
        Task task(taskName, taskDesc);
        taskList.push_back(task);
    }

    // Delete task given a taskID
    void deleteTask(const std::string& taskID) {
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
    void updateTaskName(const std::string& newTaskName, const std::string& taskID) {
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
    void updateTaskDesc(const std::string& newTaskDesc, const std::string& taskID) {
        for (auto& task : taskList) {
            if (task.getTaskID() == taskID) {
                task.setTaskDesc(newTaskDesc);
                return;
            }
        }
        std::cout << "Task ID: " << taskID << " not found." << std::endl;
    }
};
