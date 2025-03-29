#pragma once

#include "AForm.hpp"

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
                const char *what() const throw()
                {
                    return "Grade is too high";
                }
        };

        class GradeTooLowException : public std::exception {
                const char *what() const throw()
                {
                    return "Grade is too low";
                }
        };


};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat);
