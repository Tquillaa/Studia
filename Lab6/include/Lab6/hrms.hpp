#ifndef HRMS_HEADER
#define HRMS_HEADER

#include <string>

class HRMS {
    private:

    public:
    void add(Employee employee, std::string departmentId, double salary); //metoda dodająca użytkownika do systemu, do danego departamentu, mającego dane wynagrodzenie
    void printDepartment(std::string departmentId); //metoda wypisująca wszystkich pracowników danego departamentu
    void changeSalary(std::string employeeId, double salary); // metoda zmieniająca wynagrodzenie danego pracownika
    void printSalaries(); //metoda wypisująca wynagrodzenia wszystkich pracowników, wraz z informacjami o tych pracownikach
    void printSalariesSorted(); //metoda wypisująca wynagrodzenia wszystkich pracowników, wraz z informacjami o tych pracownikach, w kolejności malejącego wynagrodzenia (sortowanie ma być wykonana z użyciem std::algorithm)
};

#endif