/*
    Name: Justin Fifarek
    Project: Appointment management app
    Module: main file
*/

#include <iostream>
#include <limits>
#include <string>

#include "../includes/main.h"

void displayMenu(std::string menu = "main") {
    if (menu == "main") {
        std::cout << "Main menu: " << std::endl;
        std::cout << "  1. Contacts" << std::endl;
        std::cout << "  2. Tasks" << std::endl;
        std::cout << "  3. Appointments" << std::endl;
        std::cout << "  9. Exit program" << std::endl;
    }
    else if (menu == "contacts") {
        std::cout << "Contacts menu: " << std::endl;
        std::cout << "  1. Display list of contacts" << std::endl;
        std::cout << "  2. Find contact by ID" << std::endl;
        std::cout << "  3. Add a contact" << std::endl;
        std::cout << "  4. Edit a contact" << std::endl;
        std::cout << "  5. Delete a contact" << std::endl;
        std::cout << "  9. Back to main menu" << std::endl;
    }
    else if (menu == "tasks") {
        std::cout << "Tasks menu: " << std::endl;
        std::cout << "  1. Display list of tasks" << std::endl;
        std::cout << "  2. Find task by ID" << std::endl;
        std::cout << "  3. Add a task" << std::endl;
        std::cout << "  4. Edit a task" << std::endl;
        std::cout << "  5. Delete a task" << std::endl;
        std::cout << "  9. Back to main menu" << std::endl;
    }
    else if (menu == "appointments") {
        std::cout << "Appointments menu: " << std::endl;
        std::cout << "  1. Display list of appointment" << std::endl;
        std::cout << "  2. Find appointment by ID" << std::endl;
        std::cout << "  3. Add a appointment" << std::endl;
        std::cout << "  4. Edit a appointment" << std::endl;
        std::cout << "  5. Delete a appointment" << std::endl;
        std::cout << "  9. Back to main menu" << std::endl;
    }
    else {
        std::cout << "Incorrect menu option called in function variable" << std::endl;
    }
    return;
}

void processMenu(unsigned int processMenuOption) {
    if (processMenuOption == 1) {
        contactsMenu();
    }
    else if (processMenuOption == 2) {
        tasksMenu();
    }
    else if (processMenuOption == 3) {
        appointmentsMenu();
    }
    else if (processMenuOption == 9) {
        std::cout << "Option 9 selected, exiting program..." << std::endl;
        exit(0);
    }
    else {
        std::cout << "Invalid option, please try again." << std::endl;
    }
    return;
}

void contactsMenu() {
    unsigned int option = 0, option2, id = 0;
    std::string firstname = "", lastname = "", phone = "", address = "";
    displayMenu("contacts");
    while (true) {
        std::cout << "Enter menu choice: ";
        std::cin >> option;
        if (option == 1) {
            std::cout << "Display contact list option" << std::endl;
            contactService.displayContacts();
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else if (option == 2) {
            std::cout << "Enter ID to find: " << std::endl;
            std::cin >> id;
            if (!contactService.displayOneContact(id)) {
                break;
            }
        }
        else if (option == 3) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Please enter first name (cannot be more than 10 chars): " << std::endl;
            std::getline(std::cin, firstname);
            std::cout << "Please enter last name (cannot be more than 10 chars): " << std::endl;
            std::getline(std::cin, lastname);
            std::cout << "Please enter phone (must be exactly 10 digits): " << std::endl;
            std::getline(std::cin, phone);
            std::cout << "Please enter address (cannot be more than 30 chars): " << std::endl;
            std::getline(std::cin, address);
            contactService.addContact(firstname, lastname, phone, address);
        }
        else if (option == 4) {
            option2 = 0;
            std::cout << "Enter ID to edit: " << std::endl;
            std::cin >> id;
            while (true) {
                if (!contactService.displayOneContact(id)) {
                    break;
                }
                std::cout << "Please select what you want to edit:" << std::endl;
                std::cout << " 1. First name" << std::endl;
                std::cout << " 2. Last name" << std::endl;
                std::cout << " 3. Phone" << std::endl;
                std::cout << " 4. Address" << std::endl;
                std::cout << " 9. Go back" << std::endl;
                std::cin >> option2;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                if (option2 == 1) {
                    std::cout << "Please enter first name (cannot be more than 10 chars): " << std::endl;
                    std::getline(std::cin, firstname);
                    contactService.updateFirstName(firstname, id);
                }
                else if (option2 == 2) {
                    std::cout << "Please enter last name (cannot be more than 10 chars): " << std::endl;
                    std::getline(std::cin, lastname);
                    contactService.updateLastName(lastname, id);
                }
                else if (option2 == 3) {
                    std::cout << "Please enter phone (must be exactly 10 digits): " << std::endl;
                    std::getline(std::cin, phone);
                    contactService.updatePhone(phone, id);
                }
                else if (option2 == 4) {
                    std::cout << "Please enter address (cannot be more than 30 chars): " << std::endl;
                    std::getline(std::cin, address);
                    contactService.updateAddress(address, id);
                }
                else if (option2 == 9) {
                    contactsMenu();
                }
                else {
                    std::cout << "Invalid option, please try again." << std::endl;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
                continue;
            }
        }
        else if (option == 5) {
            std::cout << "Please enter the contactID to be deleted: " << std::endl;
            std::cin >> id;
            contactService.deleteContact(id);
        }
        else if (option == 9) {
            break;
        }
        else {
            std::cout << "Invalid option, please try again." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        continue;
    }
    return;
}

void tasksMenu() {
    unsigned int option = 0, option2 = 0, id = 0;
    std::string taskname = "", taskdesc = "";
    displayMenu("tasks");
    while (true) {
        option = 0, option2 = 0;
        std::cout << "Enter menu choice: ";
        std::cin >> option;
        if (option == 1) {
            taskService.displayTasks();
        }
        else if (option == 2) {
            std::cout << "Enter ID to find: " << std::endl;
            std::cin >> id;
            taskService.displayOneTask(id);
        }
        else if (option == 3) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Please enter task name (cannot be more than 20 chars): " << std::endl;
            std::getline(std::cin, taskname);
            std::cout << "Please enter task description (cannot be more than 50 chars): " << std::endl;
            std::getline(std::cin, taskdesc);
            taskService.addTask(taskname, taskdesc);
        }
        else if (option == 4) {
            while (true) {
                std::cout << "Enter ID to edit: " << std::endl;
                std::cin >> id;
                if (!taskService.displayOneTask(id)) {
                    continue;
                }
                std::cout << "Please select what you want to edit: " << std::endl;
                std::cout << " 1. Task name" << std::endl;
                std::cout << " 2. Task description" << std::endl;
                std::cout << " 9. Go back" << std::endl;
                std::cin >> option2;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                if (option2 == 1) {
                    std::cout << "Please enter task name (cannot be more than 20 chars): " << std::endl;
                    std::getline(std::cin, taskname);
                    taskService.updateTaskName(taskname, id);
                }
                else if (option2 == 2) {
                    std::cout << "Please enter task description (cannot be more than 50 chars): " << std::endl;
                    std::getline(std::cin, taskdesc);
                    taskService.updateTaskDesc(taskdesc, id);
                }
                else if (option2 == 9) {
                    tasksMenu();
                }
                break;
            }
        }
        else if (option == 5) {
            std::cout << "Please enter the taskID to be deleted: " << std::endl;
            std::cin >> id;
            taskService.deleteTask(id);
        }
        else if (option == 9) {
            break;
        }
        else {
            std::cout << "Invalid option, please try again." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        continue;
    }
    return;
}

void appointmentsMenu() {
    unsigned int option = 0, option2 = 0, id = 0;
    std::string appointmentdate = "", appointmentdesc = "";
    displayMenu("appointments");
    while (true) {
        option = 0;
        std::cout << "Enter menu choice: ";
        std::cin >> option;
        if (option == 1) {
            appointmentService.displayAppointments();
        }
        else if (option == 2) {
            std::cout << "Enter ID to find: " << std::endl;
            std::cin >> id;
            appointmentService.displayOneAppointment(id);
        }
        else if (option == 3) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Please  enter a date in YYYY-MM-DD HH:MM:SS format: " << std::endl;
            std::getline(std::cin, appointmentdate);
            std::cout << "Please enter description (cannot be more than 50 characters)" << std::endl;
            std::getline(std::cin, appointmentdesc);
            appointmentService.addAppointment(appointmentdate, appointmentdesc);

        }
        else if (option == 4) {
            option2 = 0;
            std::cout << "Enter ID to edit: " << std::endl;
            std::cin >> id;
            while (true) {
                if (!appointmentService.displayOneAppointment(id)) {
                    break;
                }
                std::cout << "Please select what you want to edit: " << std::endl;
                std::cout << " 1. Appointment date" << std::endl;
                std::cout << " 2. Appointment description" << std::endl;
                std::cout << " 9. Go back" << std::endl;
                std::cin >> option2;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                if (option2 == 1) {
                    std::cout << "Please enter a new date in YYYY-MM-DD HH:MM:SS format" << std::endl;
                    std::getline(std::cin, appointmentdate);
                    appointmentService.updateAppointmentDate(appointmentdate, id);
                }
                else if (option2 == 2) {
                    std::cout << "Please enter a new description (cannot be more than 50 chars)" << std::endl;
                    std::getline(std::cin, appointmentdesc);
                    appointmentService.updateAppointmentDesc(appointmentdesc, id);
                }
                else if (option2 == 9) {
                    appointmentsMenu();
                }
                else {
                    std::cout << "Invalid option, please try again." << std::endl;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
            }
        }
        else if (option == 5) {
            std::cout << "Please enter the appointmentID to be deleted: " << std::endl;
            std::cin >> id;
            appointmentService.deleteAppointment(id);
        }
        else if (option == 9) {
            break;
        }
        else {
            std::cout << "Invalid option, please try again." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        continue;
    }
    return;
}

int main() {
    // Contacts for testing
    contactService.addContact("AAAA", "A", "1111111111", "Ramona Road");
    contactService.addContact("BBBB", "B", "2222222222", "Ramona Road");
    contactService.addContact("CCCC", "C", "3333333333", "Ramona Road");

    // Tasks for testing
    taskService.addTask("Task name 1", "Task description 1");
    taskService.addTask("Task name 2", "Task description 2");
    taskService.addTask("Task name 3", "Task description 3");

    // Appointments for testing
    appointmentService.addAppointment("2025-01-05 12:09:09", "Appointment desc 1");
    appointmentService.addAppointment("2025-02-10 12:19:19", "Appointment desc 2");
    appointmentService.addAppointment("2025-03-15 12:29:29", "Appointment desc 3");
    

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
