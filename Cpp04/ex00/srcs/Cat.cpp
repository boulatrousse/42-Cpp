/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 15:18:23 by lboulatr          #+#    #+#             */
/*   Updated: 2023/08/27 10:08:34 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void)
{
    std::cout << "Default Cat constructor called." << std::endl;
    this->_type = "Cat";
    return ;
}

Cat::Cat(std::string type)
{
    std::cout << "Default Cat ";
    std::cout << type << " constructor with type called." << std::endl;
    this->_type = type;
    
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
    std::cout << this->_type << " called." << std::endl;

    return ;
}

Cat &Cat::operator=(Cat const &src)
{
    std::cout << "Copy assignment operator called." << std::endl;
    this->_type = src._type;
    
    return (*this);
}

void Cat::makeSound() const
{
    std::cout << "\033[1;32mMEOW\033[0m" << std::endl;

    return ;
}

std::string Cat::getType() const
{
    return (this->_type);
}