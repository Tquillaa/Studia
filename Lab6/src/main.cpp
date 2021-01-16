#include <iostream>
#include <stdlib.h>
#include <time.h>

#include <Lab6/employee.hpp>
#include <Lab6/hrms.hpp>

using namespace std;

int main() {
    Employee em1,em2,em3,em4,em5,em6,em7,em8,em9,em10;
    HRMS hr;

    srand(time(NULL));

    //stworzenie 10 pracownikow
    em1.createEmployee("JRF","James","Rollins","FrontEndProgrammer");
    em2.createEmployee("RCF","Rebecca", "Cantrell","FrontEndProgrammer");
    em3.createEmployee("NKF","Nicole","Kidman","FrontEndProgrammer");
    em4.createEmployee("VDF","Vin","Diesel","FrontEndProgrammer");
    em5.createEmployee("DPT","Danielle","Panabaker","TeamLeader");
    em6.createEmployee("GGT","Grant","Gustin","TeamLeader");
    em7.createEmployee("EBT","Emily","Browning","TeamLeader");
    em8.createEmployee("PSB","Peter","Stormare","BackEndProgrammer");
    em9.createEmployee("JMB","James","McAvoy","BackEndProgrammer");
    em10.createEmployee("RMB","Rachel","McAdams","BackEndProgrammer");

    //zatrudnienie pracownikow w edpartamentach
    hr.add(em1, "CDPR", (rand()%50)*100+1000);
    hr.add(em2, "CDPR", (rand()%50)*100+1000);
    hr.add(em3, "Wargaming", (rand()%50)*100+1000);
    hr.add(em4, "Steam", (rand()%50)*100+1000);
    hr.add(em5, "CDPR", (rand()%50)*100+1000);
    hr.add(em6, "Wargaming", (rand()%50)*100+1000);
    hr.add(em7, "Steam", (rand()%50)*100+1000);
    hr.add(em8, "Wargaming", (rand()%50)*100+1000);
    hr.add(em9, "CDPR", (rand()%50)*100+1000);
    hr.add(em10, "Steam", (rand()%50)*100+1000);
    
    //wypisanie z CDPR
    std::cout<<std::endl<<"Pracownicy pracujacy w departamencie CDPR:";
    hr.printDepartment("CDPR");
    std::cout<<std::endl;

    //wypisanie z Wargaming
    std::cout<<"Pracownicy pracujacy w departamencie Wargaming:";
    hr.printDepartment("Wargaming");
    std::cout<<std::endl;

    //wypisanie z Steam
    std::cout<<"Pracownicy pracujacy w departamencie Steam:";
    hr.printDepartment("Steam");
    std::cout<<std::endl;

    //wypisanie salaries
    std::cout<<"Zarobki pracownikow:";
    hr.printSalaries();
    std::cout<<std::endl;

    //zmiana salary dla Jamesa Rollinsa
    hr.changeSalary("JRF",7800);
    
    //wypisanie salaries po zmianie i posortowane
    std::cout<<"Posortowane zarobki pracownikow:";
    hr.printSalariesSorted();
    std::cout<<std::endl;

    return 0;
}
