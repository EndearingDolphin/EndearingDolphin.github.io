#pragma once

#include <iostream>
#include <string>
#include <atomic>

class Task {
private:
    std::string taskID;
    std::string taskName;
    std::string taskDesc;
    static std::atomic<long> idGenerator;

public:
    Task(std::string taskName, std::string taskDesc);

    std::string getTaskID();
    std::string getTaskName();
    std::string getTaskDesc();
    void setTaskName(std::string taskName);
    void setTaskDesc(std::string taskDesc);
};