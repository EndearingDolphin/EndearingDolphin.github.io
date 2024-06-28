/*
    Name: Justin Fifarek
    Project: Appointment management app
    Module: main file
*/

#include <iostream>
#include <limits>
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
    unsigned int option = 0, id = 0;
    std::string firstname = "", lastname = "", phone = "", address = "";
    std::cout << "Contacts menu: " << std::endl;
    std::cout << "  1. Display list of contacts" << std::endl;
    std::cout << "  2. Find contact by ID" << std::endl;
    std::cout << "  3. Add a contact" << std::endl;
    std::cout << "  4. Edit a contact" << std::endl;
    std::cout << "  5. Delete a contact" << std::endl;
    std::cout << "  9. Back to main menu" << std::endl;
    while (option != 9) {
        std::cout << "Enter menu choice (1-5, 9): ";
        std::cin >> option;
        switch(option) {
            case 1:
                std::cout << "Display contact list option" << std::endl;
                contactService.displayContacts();
                break;
            case 2:
                std::cout << "Enter ID to find: " << std::endl;
                std::cin >> id;
                if (!contactService.displayOneContact(id)) {
                    break;
                }
                std::cout << "Enter anything to continue..." << std::endl;
                std::cin >> id;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                contactsMenu();
            case 3:
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Please enter first name (cannot be longer than 10 chars): " << std::endl;
                std::getline(std::cin, firstname);
                std::cout << "Please enter last name (cannot be longer than 10 chars): " << std::endl;
                std::getline(std::cin, lastname);
                std::cout << "Please enter phone (must be exactly 10 digits): " << std::endl;
                std::getline(std::cin, phone);
                std::cout << "Please enter address (cannot be longer than 30 chars): " << std::endl;
                std::getline(std::cin, address);
                contactService.addContact(firstname, lastname, phone, address);
                firstname = "", lastname = "", phone = "", address = "";
                break;
            case 4:
                option = 0;
                std::cout << "Enter ID to edit: " << std::endl;
                std::cin >> id;
                while (option != 9) {
                    if (!contactService.displayOneContact(id)) {
                        break;
                    }
                    std::cout << "Please select what you want to edit:" << std::endl;
                    std::cout << " 1. First name" << std::endl;
                    std::cout << " 2. Last name" << std::endl;
                    std::cout << " 3. Phone" << std::endl;
                    std::cout << " 4. Address" << std::endl;
                    std::cout << " 9. Go back" << std::endl;
                    std::cin >> option;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    switch(option) {
                        case 1:
                            std::cout << "Please enter first name (cannot be longer than 10 chars): " << std::endl;
                            std::getline(std::cin, firstname);
                            contactService.updateFirstName(firstname, id);
                            break;
                        case 2:
                            std::cout << "Please enter last name (cannot be longer than 10 chars): " << std::endl;
                            std::getline(std::cin, lastname);
                            contactService.updateLastName(lastname, id);
                            break;
                        case 3:
                            std::cout << "Please enter phone (must be exactly 10 digits): " << std::endl;
                            std::getline(std::cin, phone);
                            contactService.updatePhone(phone, id);
                            break;
                        case 4:
                            std::cout << "Please enter address (cannot be longer than 30 chars): " << std::endl;
                            std::getline(std::cin, address);
                            contactService.updateAddress(address, id);
                            break;
                        case 9:
                            contactsMenu();
                            break;
                        default:
                            std::cout << "Invalid option, please try again." << std::endl;
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            break;
                    }
                }
                break;
            case 5:
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Please enter the contactID to be deleted: " << std::endl;
                std::cin >> id;
                contactService.deleteContact(id);
                contactsMenu();
            case 9:
                return;
            default:
                std::cout << "Invalid option, please try again." << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break;
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
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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
                return;
            default:
                std::cout << "Invalid option, please try again." << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break;
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
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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
                return;
            default:
                std::cout << "Invalid option, please try again." << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break;
        }
    }
}

int main() {
    // Contacts for testing
    contactService.addContact("AAAA", "A", "1111111111", "Ramona Road");
    contactService.addContact("BBBB", "B", "2222222222", "Ramona Road");
    contactService.addContact("CCCC", "C", "3333333333", "Ramona Road");
    contactService.addContact("DDDD", "D", "4444444444", "Ramona Road");
    contactService.addContact("EEEE", "E", "5555555555", "Ramona Road");
    contactService.addContact("FFFF", "F", "6666666666", "Ramona Road");

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
