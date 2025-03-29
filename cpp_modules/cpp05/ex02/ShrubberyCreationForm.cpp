#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
}
ShrubberyCreationForm::~ShrubberyCreationForm(){}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy) :  AForm::AForm("shrubbery creation", 145, 137) {
    *this = copy;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm& copy) {
    if (this != &copy)
        _target = copy._target;
    return *this; 
}


void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    if (!isSigned())
        throw AForm::FormNotSignedException();

    if (executor.getGrade() > getGradeToExecute())
        throw AForm::GradeTooLowException();

    std::ofstream ofs((_target + "_shrubbery").c_str());
    if (!ofs)
    {
        std::cerr << "Error: Could not open file for writing" << std::endl;
        return;
    }
    ofs << "        &&& &&  & &&" << std::endl;
    ofs << "    && &\\/&\\|& ()|/ @, &&" << std::endl;
    ofs << "    &\\/(/&/&||/& /_/)_&/_&" << std::endl;
    ofs << " &() &\\/&|()|/&\\/ '%\" & ()" << std::endl;
    ofs << " &_\\_&&_\\ |& |&&/&__%_/_& &&" << std::endl;
    ofs << "&&   && & &| &| /& & % ()& /&&" << std::endl;
    ofs << "    ()&_---()&\\&\\|&&-&&--%---()~" << std::endl;
    ofs << "        &&     \\|||" << std::endl;
    ofs << "                |||" << std::endl;
    ofs << "                |||" << std::endl;
    ofs << "                |||" << std::endl;
    ofs << "          , -=-~  .-^- _" << std::endl;


    ofs.close();
}