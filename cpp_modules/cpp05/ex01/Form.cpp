#include "Form.hpp"

Form::Form(const std::string name, int gradeToSign, int gradeToExecute)
    : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}
Form::~Form() {}

//Getter
void Form::setIsSigned(bool value){_isSigned = value;}

//Setter
std::string Form::getName() const {return _name;}
bool Form::isSigned() const {return _isSigned;}
int Form::getGradeToSign() const {return _gradeToSign;}
int Form::getGradeToExecute() const {return _gradeToExecute;}
std::string Form::isSignedStatus() const {return isSigned() ? "yes" : "No";}

Form::Form(const Form& copy) : _name(copy.getName()),
                               _gradeToSign(getGradeToSign()),
                               _gradeToExecute(getGradeToExecute()) {
    *this = copy;
}

Form &Form::operator=(const Form& copy) {
    if (this == &copy)
        return *this;
    _isSigned = copy._isSigned;
    return *this;
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > getGradeToSign())
        throw GradeTooLowException();
    setIsSigned(true);
}

std::ostream& operator<<(std::ostream& str, const Form& form)
{
    str << BLUE << "Form name: " << GREEN << form.getName() << std::endl << RESET;
    str << BLUE <<"Form sign grade: " << GREEN <<form.getGradeToSign() << std::endl << RESET;
    str << BLUE << "Form execute grade: " << GREEN << form.getGradeToExecute() << std::endl << RESET;
    str << BLUE << "Form signed: " << GREEN << form.isSignedStatus() << std::endl << RESET;
    return str;
}