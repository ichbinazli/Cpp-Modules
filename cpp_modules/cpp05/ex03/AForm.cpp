#include "AForm.hpp"

AForm::AForm(const std::string name, int gradeToSign, int gradeToExecute)
    : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

//Setter
void AForm::setIsSigned(bool value){_isSigned = value;}

//Getter
std::string AForm::getName() const {return _name;}
bool AForm::isSigned() const {return _isSigned;}
int AForm::getGradeToSign() const {return _gradeToSign;}
int AForm::getGradeToExecute() const {return _gradeToExecute;}
std::string AForm::isSignedStatus() const {return isSigned() ? "yes" : "No";}

AForm::~AForm(){}

AForm::AForm(const AForm& copy) : _name(copy.getName()),
                               _gradeToSign(getGradeToSign()),
                               _gradeToExecute(getGradeToExecute()) {
    *this = copy;
}

AForm &AForm::operator=(const AForm& copy) {
    if (this == &copy)
        return *this;
    _isSigned = copy._isSigned;
    return *this;
}

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > getGradeToSign())
        throw GradeTooLowException();
    setIsSigned(true);
}

std::ostream& operator<<(std::ostream& out, const AForm& form)
{
    out << form.getName() << ", form grade to sign " << form.getGradeToSign()
        << ", form grade to execute " << form.getGradeToExecute()
        << ", is signed " << form.isSignedStatus() << std::endl;
    return out;
}