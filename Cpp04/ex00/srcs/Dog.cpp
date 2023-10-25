/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 15:21:28 by lboulatr          #+#    #+#             */
/*   Updated: 2023/08/27 10:08:44 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
{
    std::cout << "Default Dog constructor called." << std::endl;
    this->_type = "Dog";
    
    return ;
}

Dog::Dog(std::string type)
{
    std::cout << "Default Dog ";
    std::cout << type << " constructor with type called." << std::endl;
    this->_type = type;
    
    return ;
}


Dog::Dog(const Dog &src)
{
    std::cout << "Copy Dog constructor called." << std::endl;
    *this = src;

    return ;
}

Dog::~Dog(void)
{
    std::cout << "Destructor Dog for ";
    std::cout << this->_type << " called." << std::endl;

    return ;
}

Dog &Dog::operator=(Dog const &src)
{
    std::cout << "Copy assignment operator called." << std::endl;
    this->_type = src._type;
    
    return (*this);
}

void Dog::makeSound() const
{
    std::cout << "\033[1;36mWOOF\033[0m" << std::endl;

    return ;
}

std::string Dog::getType() const
{
    return (this->_type);
}