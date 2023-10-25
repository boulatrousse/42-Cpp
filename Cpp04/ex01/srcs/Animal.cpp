/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 14:49:29 by lboulatr          #+#    #+#             */
/*   Updated: 2023/08/31 10:01:41 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void)
{
    std::cout << "Default Animal constructor called." << std::endl;
    this->type = "Animal";

    return ;
}

Animal::Animal(std::string type)
{
    std::cout << "Default Animal ";
    std::cout << type << " constructor with type called." << std::endl;
    this->type = type;
    
    return ;
}

Animal::Animal(const Animal &src)
{
    std::cout << "Copy Animal constructor called." << std::endl;
    *this = src;

    return ;
}

Animal::~Animal(void)
{
    std::cout << "Destructor Animal called." << std::endl;

    return ;
}

Animal &Animal::operator=(Animal const &src)
{
    std::cout << "Copy assignment operator called." << std::endl;
    this->type = src.type;
    
    return (*this);
}

void Animal::makeSound() const
{
    std::cout << "Generic sound" << std::endl;
}

std::string Animal::getType() const
{
    return (this->type);
}

Brain *Animal::getBrain() const
{
    return (NULL);
}