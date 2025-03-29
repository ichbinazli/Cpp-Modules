#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main() {
    try {
        Bureaucrat max(PURPLE "Max" RESET, 50);
        
        RobotomyRequestForm robotomyForm(GREEN "Target" RESET);
        ShrubberyCreationForm shrubberyForm(GREEN "Garden" RESET);
        PresidentialPardonForm pardonForm(GREEN "Victim" RESET);

        max.signForm(robotomyForm);
        max.executeForm(robotomyForm);
        
        max.signForm(shrubberyForm);
        max.executeForm(shrubberyForm);

        max.signForm(pardonForm);
        max.executeForm(pardonForm);
        
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
