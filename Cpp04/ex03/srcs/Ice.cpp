/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 14:30:27 by lboulatr          #+#    #+#             */
/*   Updated: 2023/08/29 13:40:11 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "ICharacter.hpp"

Ice::Ice(void)
{
    this->_type = "ice";

    return ;   
}

Ice::Ice(const Ice &src) : AMateria(src)
{
    return ;
}

Ice::~Ice(void)
{
    return ;   
}

Ice &Ice::operator=(const Ice &src)
{
    this->_type = src._type;

    return (*this);
}

AMateria *Ice::clone() const
{
    return (new Ice(*this));
}

void Ice::use(ICharacter &target)
{
    std::cout << "\033[1;36m";
    std::cout << "* shoots an ice bolt at ";
    std::cout << target.getName() << " *" << "\033[0m" << std::endl;

    return ;
}
