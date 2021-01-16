#include <exception>

class noEmployees : public std::exception
{
    virtual const char *what() const throw()
    {
        return "Brak pracownikow";
    }
};

class noEmployeeId : public std::exception
{
    virtual const char *what() const throw()
    {
        return "Brak id pracownika";
    }
};

class noDepartments : public std::exception
{
    virtual const char *what() const throw()
    {
        return "Brak departamentow";
    }
};