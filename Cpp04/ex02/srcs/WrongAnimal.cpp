/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 14:49:29 by lboulatr          #+#    #+#             */
/*   Updated: 2023/08/04 09:36:18 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)
{
    std::cout << "Default Wrong Animal constructor called." << std::endl;
    this->type = "Wrong Animal";
    
    return ;
}

WrongAnimal::WrongAnimal(std::string type)
{
    std::cout << "Default Wrong Animal ";
    std::cout << type << " constructor with type called." << std::endl;
    this->type = type;
    
    return ;
}

WrongAnimal::WrongAnimal(const WrongAnimal &src)
{
    std::cout << "Copy Wrong Animal constructor called." << std::endl;
    *this = src;

    return ;
}

WrongAnimal::~WrongAnimal(void)
{
    std::cout << "Destructor Wrong Animal called." << std::endl;

    return ;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &src)
{
    std::cout << "Copy assignment operator called." << std::endl;
    this->type = src.type;
    
    return (*this);
}

void WrongAnimal::makeSound() const
{
    std::cout << "Wrong Animal generic sound" << std::endl;
}

std::string WrongAnimal::getType() const
{
    return (this->type);
}