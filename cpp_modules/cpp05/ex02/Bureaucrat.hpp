#pragma once

#include "AForm.hpp"

# define RED "\x1b[31;01m"
# define RESET "\x1b[0m"
# define GREEN "\x1b[32;01m"

class AForm;


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
        void signForm(AForm& form);
        void executeForm(AForm const & form) const;

        class GradeTooHighException : public std::exception {
            public:
                const char *what() const throw()
                {
                    return "Grade is too high";
                }
        };

        class GradeTooLowException : public std::exception {
            public:
                const char *what() const throw()
                {
                    return "Grade is too low";
                }
        };


};

std::ostream& operator<<(std::ostream& str, const Bureaucrat& bureaucrat);
