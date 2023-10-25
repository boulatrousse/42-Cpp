/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 14:43:20 by lboulatr          #+#    #+#             */
/*   Updated: 2023/08/29 08:49:54 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure(void)
{
    this->_type = "cure";

    return ;   
}

Cure::Cure(const Cure &src) : AMateria(src)
{
    return ;
}

Cure::~Cure(void)
{
    return ;   
}

Cure &Cure::operator=(const Cure &src)
{
    this->_type = src._type;

    return (*this);
}

AMateria *Cure::clone() const
{
    return (new Cure(*this));
}

void Cure::use(ICharacter &target)
{
    std::cout << "\033[1;32m";
    std::cout << "* heals ";
    std::cout << target.getName() << "'s wounds *" << "\033[0m" << std::endl;

    return ;
}