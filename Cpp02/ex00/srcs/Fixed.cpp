/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 12:11:59 by lboulatr          #+#    #+#             */
/*   Updated: 2023/08/03 08:52:17 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
    std::cout << "Default constructor called." << std::endl;
    this->_value = 0;

    return ;
}

Fixed::Fixed(const Fixed &src)
{
    std::cout << "Copy constructor called." << std::endl;
    *this = src;

    return ;
}

Fixed::~Fixed(void)
{
    std::cout << "Destructor called." << std::endl;

    return ;
}

Fixed &Fixed::operator=(Fixed const &src)
{
    std::cout << "Copy assignment operator called." << std::endl;
    this->_value = src.getRawBits();
    
    return (*this);
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called." << std::endl;
    
    return (this->_value);
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called." << std::endl;
    this->_value = raw;
    
    return ;
}