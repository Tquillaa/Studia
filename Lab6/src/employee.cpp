#include <iostream>
#include <string>
#include <fstream>
#include <exception>

#include <Lab6/employee.hpp>

//create
void Employee::createEmployee(std::string id, std::string name, std::string surname, std::string position) {
    this->id = id;
    this->name = name;
    this->surname = surname;
    this->position = position;
}

//getery
std::string Employee::getId() {
    return this->id;
}
std::string Employee::getName() {
    return this->name;
}
std::string Employee::getSurname() {
    return this->surname;
}
std::string Employee::getDepartmentId() {
    return this->departmentId;
}
std::string Employee::getPosition() {
    return this->position;
}

//setery
void Employee::setId(std::string id) {
    this->id = id;
}
void Employee::setName(std::string name) {
    this->name = name;
}
void Employee::setSurname(std::string surname) {
    this->surname = surname;
}
void Employee::setDepartmentId(std::string departmentId) {
    this->departmentId = departmentId;
}
void Employee::setPosition(std::string position) {
    this->position = position;
}
