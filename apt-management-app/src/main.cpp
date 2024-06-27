/*
    Name: Justin Fifarek
    Project: Appointment management app
    Module: main file
*/

#include <iostream>
#include <string>

#include "../includes/main.h"

void displayMenu() {
    std::cout << "Main menu: " << std::endl;
    std::cout << "  1. Contacts" << std::endl;
    std::cout << "  2. Tasks" << std::endl;
    std::cout << "  3. Appointments" << std::endl;
    std::cout << "  9. Exit program" << std::endl;
}

void processMenu(int option) {
    switch(option) {
        default:
            std::cout << "Invalid option, please try again." << std::endl;
            break;
        case 1:
            contactsMenu();
            break;
        case 2:
            tasksMenu();
            break;
        case 3:
            appointmentsMenu();
            break;
        case 9:
            std::cout << "Option 9 selected, exiting program..." << std::endl;
            exit(0);
    }
}

void contactsMenu() {
    std::cout << "Contacts menu: " << std::endl;
    std::cout << "  1. Display list of contacts" << std::endl;
    std::cout << "  2. Add a contact" << std::endl;
    std::cout << "  3. Edit a contact" << std::endl;
    std::cout << "  4. Delete a contact" << std::endl;
    std::cout << "  9. Back to main menu" << std::endl;
    int option = 0;
    std::string firstname = "", lastname = "", phone = "", address = "";
    while (option != 9) {
        std::cout << "Enter menu choice (1-4, 9): ";
        std::cin >> option;
        switch(option) {
            case 1:
                std::cout << "Display contact list option" << std::endl;
                contactService.displayContacts();
                break;
            case 2:
                while (true) {
                    std::cout << "Please enter first name (cannot be longer than 10 chars): " << std::endl;
                    std::getline(std::cin, firstname);
                    std::cout << "Please enter last name (cannot be longer than 10 chars): " << std::endl;
                    std::getline(std::cin, lastname);
                    std::cout << "Please enter phone (must be exactly 10 digits): " << std::endl;
                    std::getline(std::cin, phone);
                    std::cout << "Please enter address (cannot be longer than 30 chars): " << std::endl;
                    std::getline(std::cin, address);
                    contactService.addContact(firstname, lastname, phone, address);
                    break;
                }
                break;
            case 3:
                std::cout << "Edit a contact option" << std::endl;
                break;
            case 4:
                std::cout << "Delete a contact option" << std::endl;
                break;
            case 9:
                main();
                break;
            default:
                std::cout << "Invalid option, please try again." << std::endl;
                std::cin.clear();
                std::cin.ignore(1000, '\n');
        }
    }
}

void tasksMenu() {
    std::cout << "Tasks menu: " << std::endl;
    std::cout << "  1. Display list of tasks" << std::endl;
    std::cout << "  2. Add a task" << std::endl;
    std::cout << "  3. Edit a task" << std::endl;
    std::cout << "  4. Delete a task" << std::endl;
    std::cout << "  9. Back to main menu" << std::endl;
    int option = 0;
    while (option != 9) {
        std::cout << "Enter menu choice (1-4, 9): ";
        std::cin >> option;
        switch(option) {
            case 1:
                std::cout << "Display task list option" << std::endl;
                break;
            case 2:
                std::cout << "Add a task option" << std::endl;
                break;
            case 3:
                std::cout << "Edit a task option" << std::endl;
                break;
            case 4:
                std::cout << "Delete a task option" << std::endl;
                break;
            case 9:
                main();
                break;
            default:
                std::cout << "Invalid option, please try again." << std::endl;
                std::cin.clear();
                std::cin.ignore(1000, '\n');
        }
    }
}

void appointmentsMenu() {
    std::cout << "Appointments menu: " << std::endl;
    std::cout << "  1. Display list of appointments" << std::endl;
    std::cout << "  2. Add a appointment" << std::endl;
    std::cout << "  3. Edit a appointment" << std::endl;
    std::cout << "  4. Delete a appointment" << std::endl;
    std::cout << "  9. Back to main menu" << std::endl;
    int option = 0;
    while (option != 9) {
        std::cout << "Enter menu choice (1-4, 9): ";
        std::cin >> option;
        switch(option) {
            case 1:
                std::cout << "Display appointment list option" << std::endl;
                break;
            case 2:
                std::cout << "Add a appointment option" << std::endl;
                break;
            case 3:
                std::cout << "Edit a appointment option" << std::endl;
                break;
            case 4:
                std::cout << "Delete a appointment option" << std::endl;
                break;
            case 9:
                main();
                break;
            default:
                std::cout << "Invalid option, please try again." << std::endl;
                std::cin.clear();
                std::cin.ignore(1000, '\n');
        }
    }
}

int main() {
    // Bob, Ross, 1112223333, Alamosa Lane
    contactService.addContact("Bob", "Ross", "1112223333", "Alamosa Lane");
    contactService.addContact("Jane", "Doe", "5556667777", "Ramona Road");

    int option = 0;
    while (true) {
        displayMenu();
        std::cout << "Enter menu choice (1-3, 9): ";
        std::cin >> option;

        processMenu(option);
        std::cout << std::endl;
    }
    exit(0);
}