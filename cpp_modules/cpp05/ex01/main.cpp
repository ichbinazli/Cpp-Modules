#include "Form.hpp"

int main()
{
    try
    {
    Bureaucrat Max(PURPLE "Max" RESET, 50);
    std::cout << Max << std::endl;

    Form Fox(PURPLE "Fox" RESET,66,44);
    Max.signForm(Fox);

    Form Frog(PURPLE "Frog" RESET, 40, 80);
    Max.signForm(Frog);

    std::cout << Fox << std::endl;
    std::cout << Frog << std::endl;

    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}