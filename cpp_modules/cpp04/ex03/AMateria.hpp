#ifndef AMATERIA_HPP

# define AMATERIA_HPP

#define PURPLE "\033[38;5;92m"
#define YELLOW "\033[1;33m"
#define BLUE "\x1b[34;01m"

# include <iostream>
# include "ICharacter.hpp"

class AMateria
{
    protected:
        std::string _type;
    public:
        AMateria();
        AMateria(std::string const& type);
        AMateria(const AMateria& other);
        virtual ~AMateria();
        AMateria& operator=(const AMateria& other);

        std::string const& getType() const;
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);
};

#endif