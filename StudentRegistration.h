#ifndef STUDENT_REGISTRATION_H
#define STUDENT_REGISTRATION_H
#pragma once
#include<tuple>
#include<vector>
#include<stdexcept>
class StudentRegistrationSystem {
    public:
    using DataVerification = std::tuple<int, std::string, std::string>;
    protected:
    DataVerification data;
    std::vector<DataVerification> StudentsData;
    public:
    StudentRegisterationSystem() = default;
    StudentRegisterationSystem(int ID,const std::string& Name, const std::string& Course) : data{ID, Name, Course}{
        StudentsData.emplace_back(data);
    }
    void addStudent(int ID, const std::string& Name, const std::string& Course) {
        StudentsData.emplace_back(std::make_tuple(ID, Name, Course));
    }
    template <typename... Args>
    void PrintAllElements(const std::tuple<Args...>& t) {
        std::apply([](const auto&... elements) { (std::cout << elements << " "), ...}; t);
    }
    virtual void Display();
    virtual ~StudentRegisterationSystem() = default;
};
class DisplayData : public StudentRegistrationSystem() {
    public:
    DisplayData(int ID, const std::string& Name, const std::string& Course);
    void Display() override;
    ~DisplayData() = default;
};
#endif