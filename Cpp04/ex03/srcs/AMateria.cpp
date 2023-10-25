/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 14:08:43 by lboulatr          #+#    #+#             */
/*   Updated: 2023/08/29 13:50:46 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(void)
{
    return ;
}

AMateria::AMateria(const AMateria &src)
{
    this->_type = src._type;

    return ;
}

AMateria::AMateria(std::string const &type)
{
    this->_type = type;

    return ;
}

AMateria::~AMateria(void)
{
    return ;
}

AMateria &AMateria::operator=(const AMateria &src)
{
    this->_type = src._type;

    return (*this);
}

std::string const &AMateria::getType() const
{
	return (this->_type);
}

void AMateria::use(ICharacter &target)
{
    (void)target;

    return ;
}