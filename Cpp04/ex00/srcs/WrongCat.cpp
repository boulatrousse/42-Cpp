/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 15:18:23 by lboulatr          #+#    #+#             */
/*   Updated: 2023/08/27 10:09:06 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
    std::cout << "Default Wrong Cat constructor called." << std::endl;
    this->_type = "Wrong Cat";
    return ;
}

WrongCat::WrongCat(std::string type)
{
    std::cout << "Default Wrong Cat ";
    std::cout << type << " constructor with type called." << std::endl;
    this->_type = type;
    
    return ;
}

WrongCat::WrongCat(const WrongCat &src)
{
    std::cout << "Copy WrongCat constructor called." << std::endl;
    *this = src;

    return ;
}

WrongCat::~WrongCat(void)
{
    std::cout << "Destructor Wrong Cat for ";
    std::cout << this->_type << " called." << std::endl;

    return ;
}

WrongCat &WrongCat::operator=(WrongCat const &src)
{
    std::cout << "Copy assignment operator called." << std::endl;
    this->_type = src._type;
    
    return (*this);
}

void WrongCat::makeSound() const
{
    std::cout << "\033[1;32mMEOW\033[0m" << std::endl;

    return ;
}

std::string WrongCat::getType() const
{
    return (this->_type);
}