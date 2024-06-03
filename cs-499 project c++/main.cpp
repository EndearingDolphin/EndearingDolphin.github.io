/*
    Name: Justin Fifarek
    Project: main.cpp file
*/
#include ".\Contact\Contact.cpp"
#include ".\Contact\ContactService.cpp"
#include ".\Task\Task.cpp"
#include ".\Task\TaskService.cpp"
#include ".\Appointment\Appointment.cpp"
#include ".\Appointment\AppointmentService.cpp"
#include <iostream>
#include <string>

void displayMenu() {
    std::cout << "Main menu: " << std::endl;
    std::cout << "1. Option 1" << std::endl;
    std::cout << "2. Option 2" << std::endl;
    std::cout << "3. Option 3" << std::endl;
    std::cout << "4. Exit program" << std::endl;
}

void processMenu(int option) {
    switch(option) {
        default:
            std::cout << "Invalid option, please try again." << std::endl;
            break;
        case 1:
            std::cout << "Option 1 selected" << std::endl;
            break;
        case 2:
            std::cout << "Option 2 selected" << std::endl;
            break;
        case 3:
            std::cout << "Option 3 selected" << std::endl;
            break;
        case 4:
            std::cout << "Option 4 selected, exiting program..." << std::endl;
            break;
    }
}

int main() {
    int option = 0;
    while (option != 4) {
        displayMenu();
        std::cout << "Enter menu choice (1-4): ";
        std::cin >> option;

        processMenu(option);
        std::cout << std::endl;
    }
}