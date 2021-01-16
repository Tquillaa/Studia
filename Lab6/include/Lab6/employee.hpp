#ifndef EMPLOYEE_HEADER
#define EMPLOYEE_HEADER

#include <string>

class Employee {
    private:
        std::string id;
        std::string name;
        std::string surname;
        std::string departmentId;
        std::string position;

    public:
        //create
        void createEmployee(std::string id, std::string name, std::string surname, std::string position);

        //getery
        std::string getId();
        std::string getName();
        std::string getSurname();
        std::string getDepartmentId();
        std::string getPosition();

        //setery
        void setId(std::string id);
        void setName(std::string name);
        void setSurname(std::string surname);
        void setDepartmentId(std::string departmentId);
        void setPosition(std::string position);

};

#endif