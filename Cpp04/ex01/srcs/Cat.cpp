/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 15:18:23 by lboulatr          #+#    #+#             */
/*   Updated: 2023/08/31 11:35:14 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void)
{
    std::cout << "Default Cat constructor called." << std::endl;
    this->type = "Cat";
    this->_brain = new Brain();
    
    return ;
}

Cat::Cat(std::string type)
{
    std::cout << "Default Cat ";
    std::cout << type << " constructor with type called." << std::endl;
    this->type = type;
    this->_brain = NULL;
    
    return ;
}

Cat::Cat(const Cat &src)
{
    std::cout << "Copy Cat constructor called." << std::endl;
    *this = src;

    return ;
}

Cat::~Cat(void)
{
    std::cout << "Destructor Cat for ";
    std::cout << this->type << " called." << std::endl;
    delete this->_brain;

    return ;
}

Cat &Cat::operator=(Cat const &src)
{
    std::cout << "Copy assignment operator called." << std::endl;
    this->type = src.type;
    if (this != &src)
    {
        this->type = src.type;
        delete this->_brain;
        this->_brain = new Brain(*src._brain);
    }
    
    return (*this);
}

void Cat::makeSound() const
{
    std::cout << "\033[1;32mMEOW\033[0m" << std::endl;

    return ;
}

std::string Cat::getType() const
{
    return (this->type);
}

Brain *Cat::getBrain() const
{
    return (this->_brain);
}