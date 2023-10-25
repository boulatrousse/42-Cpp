/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 12:11:59 by lboulatr          #+#    #+#             */
/*   Updated: 2023/08/22 16:08:56 by lboulatr         ###   ########.fr       */
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

Fixed::Fixed(const int value)
{
    std::cout << "Int constructor called." << std::endl;
    _value = value * ( 1 << _bit);

    return ;
}

Fixed::Fixed(const float value)
{
    std::cout << "Float constructor called." << std::endl;
    _value = roundf(value * ( 1 << _bit));

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
    return (this->_value);
}

void Fixed::setRawBits(int const raw)
{
    this->_value = raw;
    
    return ;
}

float Fixed::toFloat(void) const
{
    return (float(_value) / (1 << _bit));
}

int Fixed::toInt(void) const
{
    return (int(_value) / (1 << _bit));
}

std::ostream &operator<<(std::ostream &out, const Fixed &src)
{
    out << src.toFloat();
    return (out);
}