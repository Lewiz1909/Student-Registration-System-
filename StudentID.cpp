    #include"StudentID.h"
    #include<windows.h>
    #include<limits>
    StudentRegistrationSystem::~StudentRegistrationSystem() {
        std::cerr << "Destructor Runs" << std::endl;
    };
    void StudentRegistrationSystem::addStudent(int ID, const std::string& Name, const std::string& Course) {
        StudentsData.emplace_back(std::make_tuple(ID, Name, Course));
    }
    void StudentRegistrationSystem::Display() {
        std::cout << "Base Display (override in derived class)" << std::endl;
    }

    DisplayData::DisplayData(int id, const std::string& name, const std::string& course) {
    addStudent(id, name, course);
     }   
      void DisplayData::Display() {
        for (auto& student : StudentsData) {
            PrintAllElements(student);
        }
    }
    int main() {
        try {
        DisplayData StudentA(25120327, "Lewis", "Software Engineering & Operating System");
        while (true) {
            Sleep(5000);
            std::cout << "**** Student Registration System ****" << std::endl;
            std::cout << "1. Add Student" << std::endl;
            std::cout << "2. Display Students' Data" << std::endl;
            std::cout << "3. Exit The Program" << std::endl;
            std::cout << "Choose An Option: ";
            int key;
            std::cin >> key;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            if (key == 1) {
                int ID;
                std::string Name, Course;
                std::cout << "Your ID: ";
                std::cin >> ID;     
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Your Name: ";
                std::getline(std::cin, Name);
                std::cout << "Your Study: ";
                std::cin >> Course;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                StudentA.addStudent(ID, Name, Course);
            }
            else if (key == 2) {
                StudentA.Display();
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
            catch (const std::exception& e) {
                std::cout << e.what();
            }
        return 0;
    }