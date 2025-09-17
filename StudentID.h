#ifndef STUDENT_REGISTRATION_H
#define STUDENT_REGISTRATION_H
#pragma once
#include<tuple>
#include<vector>
#include<stdexcept>
#include<iostream>
class StudentRegistrationSystem {
    public:
    using DataVerification = std::tuple<int, std::string, std::string>;
    protected:
    DataVerification data;
    std::vector<DataVerification> StudentsData;
    public:
    StudentRegistrationSystem() = default;
    StudentRegistrationSystem(int ID,const std::string& Name, const std::string& Course) : data{ID, Name, Course}{
        StudentsData.emplace_back(data);
    };
    void addStudent(int ID, const std::string& Name, const std::string& Course);
    template <typename... Args>
    void PrintAllElements(const std::tuple<Args...>& t) {
        std::apply([](const auto&... elements) { ((std::cout << " " << elements << " " << '\n'), ...); }, t);
    }
    virtual void Display(); 
    virtual ~StudentRegistrationSystem();
};
class DisplayData : public StudentRegistrationSystem {
    public:
    DisplayData(int ID, const std::string& Name, const std::string& Course);
    void Display() override;
    ~DisplayData() = default;
};
#endif