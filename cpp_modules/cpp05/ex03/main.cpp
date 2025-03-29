#include <iostream>
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <exception>

int main() {
    Intern intern;
    AForm* form;

    try{
        form = intern.makeForm("presidential pardon", "Bender");
        delete form;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    
    return 0;  
}
