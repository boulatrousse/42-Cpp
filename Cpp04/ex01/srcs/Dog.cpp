/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 15:21:28 by lboulatr          #+#    #+#             */
/*   Updated: 2023/08/31 09:57:07 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
{
    std::cout << "Default Dog constructor called." << std::endl;
    this->type = "Dog";
    this->_brain = new Brain();
    
    return ;
}

Dog::Dog(std::string type)
{
    std::cout << "Default Dog ";
    std::cout << type << " constructor with type called." << std::endl;
    this->type = type;
    this->_brain = NULL;
    
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
    std::cout << this->type << " called." << std::endl;
    delete this->_brain;

    return ;
}

Dog &Dog::operator=(Dog const &src)
{
    std::cout << "Copy assignment operator called." << std::endl;
    if (this != &src)
    {
        this->type = src.type;
        this->_brain = new Brain(*src._brain);
    }

    return (*this);
}

void Dog::makeSound() const
{
    std::cout << "\033[1;36mWOOF\033[0m" << std::endl;

    return ;
}

std::string Dog::getType() const
{
    return (this->type);
}

Brain *Dog::getBrain() const
{
    return (this->_brain);
}

