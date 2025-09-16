#include "StudentRegistration.h"
#include<iostream>
#include<windows.h>
StudentRegistrationSystem::~StudentRegistrationSystem() {
    std::cerr << "Error Occur/ Please Retry" << std::endl;
}
void DisplayData::Display() {
    std::cout << "Displaying Students' Datas" << std::flush();
    for (auto& student : StudentsData) {
        PrintAllElemetns(student);
        std::cout << " " << std::endl;
    }
}
int main() {
    try {
    StudentRegistrationSystem StudentA(25120327, "Lewis", "Software Engineering & Operating System");
    StudentRegistrationSystem NewStudent();
    while (true) {
        std::cout << "**** Student Registration System ****" << std::flush();
        std::cout << "1. Add Student" << std::endl;
        std::cout << "2. Display Students' Data" << std::endl;
        std::cout << "3. Exit The Program" << std::endl;
        std::cout << "Choose An Option: ";
        int key;
        std::cin >> key;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), std::endl);
        if (key == 1) {
            int ID;
            std::string Name, Course;
            std::cout << "Your ID: ";
            std::cin >> ID;     
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), std::endl);
            std::cout << "Your Name: ";
            std::getline(std::cin, Name);
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), std::endl);
            std::cout << "Your Study: ";
            std::getline(std::cin, Course);
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), std::endl);
            NewStudent.addStudent(ID, Name, Course);
        }
        else if (key == 2) {
            NewStudent.Display();
        }
        else if (key == 3) {
            system("cls");
            break;
        }
        else {
            throw std::invalid_argument("Invalid Option");
            break;
        }
    }
}
        catch (const std::runtime_error& e) {
            std::cout << e.what();
        }
    return 0;
}