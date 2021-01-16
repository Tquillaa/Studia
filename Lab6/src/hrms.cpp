#include <iostream>
#include <string>
#include <fstream>
#include <exception>
#include <vector>
#include <map>
#include <algorithm>

#include <Lab6/employee.hpp>
#include <Lab6/hrms.hpp>
#include <privateException.hpp>

std::vector<Employee> spisPracownikow; //kontener w którym będą przechowywani wszyscy pracownicy
std::map<std::string, std::string> idDepIdEmp; //kontener w którym będzie przechowywane mapowanie pomiędzy identyfikatorami departamentów a identyfikatorami wszystkich pracowników danego departamentu
std::map<std::string, double> employeeSalary; //kontener przechowywujący informacje o zarobkach pracowników

void HRMS::add(Employee employee, std::string departmentId, double salary) {
    employee.setDepartmentId(departmentId);
    spisPracownikow.push_back(employee);
    idDepIdEmp.insert(make_pair(departmentId, employee.getId()));
    employeeSalary.insert(make_pair(employee.getId(),salary));
}

void HRMS::printDepartment(std::string departmentId) {
    noEmployees noEmployees;
    noDepartments noDepartments;
    try {
        if(spisPracownikow.size()==0) throw noEmployees;
        if(idDepIdEmp.size()==0) throw noDepartments;
        std::cout<<std::endl;
        for(int i=0; i<spisPracownikow.size(); i++) {
            if(spisPracownikow[i].getDepartmentId() == departmentId) {
                std::cout<<"ID: ";
                std::cout.width(4);
                std::cout<<std::left<<spisPracownikow[i].getId()<<" Name: ";
                std::cout.width(15);
                std::cout<<spisPracownikow[i].getName()<<" ";
                std::cout.width(15);
                std::cout<<spisPracownikow[i].getSurname()<<" Position: ";
                std::cout.width(25);
                std::cout<<spisPracownikow[i].getPosition()<<std::endl;
            }
        }
    }
    catch(std::exception &e){
        std::cout<<e.what()<<std::endl;
    }
}

void HRMS::changeSalary(std::string employeeId, double salary) {
    noEmployeeId noEmployeeId;
    try {
        if(employeeId.size()==0) throw noEmployeeId;
        employeeSalary[employeeId] = salary;
    }
    catch(std::exception &e){
        std::cout<<e.what()<<std::endl;
    }
}

void HRMS::printSalaries() {
    noEmployees noEmployees;
    try {
        if(spisPracownikow.size()==0) throw noEmployees;
        std::map<std::string, double>::iterator itr; 
        std::cout<<std::endl;
        for(itr = employeeSalary.begin(); itr != employeeSalary.end(); itr++) {
            std::string temp = itr->first;
            Employee tempEmp;

            for(int i=0; i<spisPracownikow.size(); i++)
                if(temp == spisPracownikow[i].getId()) tempEmp = spisPracownikow[i];

            std::cout<<"Salary: ";
            std::cout.width(4);
            std::cout<<itr->second<<" ID: ";
            std::cout.width(4);
            std::cout<<std::left<<temp<<" Name: ";
            std::cout.width(15);
            std::cout<<tempEmp.getName()<<" ";
            std::cout.width(15);
            std::cout<<tempEmp.getSurname()<<" Department ID: ";
            std::cout.width(10);
            std::cout<<tempEmp.getDepartmentId()<<" Position: ";
            std::cout.width(25);
            std::cout<<tempEmp.getPosition()<<std::endl;
        }
    }
    catch(std::exception &e){
        std::cout<<e.what()<<std::endl;
    }
}

void HRMS::printSalariesSorted() {
    noEmployees noEmployees;
    try {
        if(spisPracownikow.size()==0) throw noEmployees;
        std::map<std::string, double>::iterator itr; 
        typedef std::pair<double, std::string> pary;
        std::vector<pary> vec;

        std::cout<<std::endl;

        for(itr = employeeSalary.begin(); itr != employeeSalary.end(); itr++) {
            vec.push_back(make_pair(itr->second, itr->first));
        }

        std::sort(vec.begin(), vec.end());

        for(int i=0; i<vec.size();i++) {
            std::string temp = vec[i].second;
            Employee tempEmp;

            for(int j=0; j<spisPracownikow.size(); j++)
                if(temp == spisPracownikow[j].getId()) tempEmp = spisPracownikow[j];

            std::cout<<"Salary: ";
            std::cout.width(4);
            std::cout<<vec[i].first<<" ID: ";
            std::cout.width(4);
            std::cout<<std::left<<temp<<" Name: ";
            std::cout.width(15);
            std::cout<<tempEmp.getName()<<" ";
            std::cout.width(15);
            std::cout<<tempEmp.getSurname()<<" Department ID: ";
            std::cout.width(10);
            std::cout<<tempEmp.getDepartmentId()<<" Position: ";
            std::cout.width(25);
            std::cout<<tempEmp.getPosition()<<std::endl;
        }
    }
    catch(std::exception &e){
        std::cout<<e.what()<<std::endl;
    }
}
