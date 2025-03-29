#pragma once

#include <iostream>
#include <exception>
#include "Form.hpp"

# define RED "\x1b[31;01m"
# define RESET "\x1b[0m"
# define GREEN "\x1b[32;01m"
# define PURPLE "\x1b[38;2;178;58;238;01m"

class Form;

class Bureaucrat
{
    private:
       std::string _name;
        int _grade;
        void setName(std::string name);
        void setGrade(int grade);
    public:
        Bureaucrat(const std::string name, int grade);
        ~Bureaucrat();
        Bureaucrat(const Bureaucrat& copy);
        Bureaucrat &operator=(const Bureaucrat& copy);

        std::string getName() const;
        int getGrade() const;

        void incrementGrade();
        void decrementGrade();
        void signForm(Form& form);

        class GradeTooHighException : public std::exception {
            public:
                const char *what() const throw()
                {
                    return (RED "Grade is too high" RESET);
                }
        };

        class GradeTooLowException : public std::exception {
            public:
                const char *what() const throw()
                {
                    return (RED "Grade is too low" RESET);
                }
        };


};

std::ostream& operator<<(std::ostream& str, const Bureaucrat& bureaucrat);
