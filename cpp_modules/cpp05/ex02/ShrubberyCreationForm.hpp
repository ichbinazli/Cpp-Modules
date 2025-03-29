#pragma once

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
    private:
        std::string _target;

    public:
        ShrubberyCreationForm(const std::string target);
        ~ShrubberyCreationForm();

        ShrubberyCreationForm(const ShrubberyCreationForm& copy);
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm& copy);

        virtual void execute(const Bureaucrat& bureaucrat) const;


};
