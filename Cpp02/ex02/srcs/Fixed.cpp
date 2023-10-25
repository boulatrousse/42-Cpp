/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 12:11:59 by lboulatr          #+#    #+#             */
/*   Updated: 2023/08/24 11:04:05 by lboulatr         ###   ########.fr       */
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
    _value = value * ( 1 << _bit);

    return ;
}

Fixed::Fixed(const float value)
{
    _value = roundf(value * ( 1 << _bit));

    return ;
}

Fixed::~Fixed(void)
{
    std::cout << "Destructor called." << std::endl;

    return ;
}

bool Fixed::operator<(const Fixed &src) const
{
    return (this->_value < src._value);
}

bool Fixed::operator<=(const Fixed &src) const
{
    return (this->_value <= src._value);
}

bool Fixed::operator>(const Fixed &src) const
{
    return (this->_value > src._value);
}

bool Fixed::operator>=(const Fixed &src) const
{
    return (this->_value >= src._value);
}

bool Fixed::operator==(const Fixed &src) const
{
    return (this->_value == src._value);
}

bool Fixed::operator!=(const Fixed &src) const
{
    return (this->_value != src._value);
}

Fixed &Fixed::operator=(const Fixed &src)
{
    std::cout << "Copy assignment operator called." << std::endl;
    this->_value = src.getRawBits();
    
    return (*this);
}

Fixed Fixed::operator+(const Fixed &src) const
{
    Fixed tmp;
    tmp.setRawBits(this->_value + src._value);
    
    return (tmp);
}

Fixed Fixed::operator-(const Fixed &src) const
{
    Fixed tmp;
    tmp.setRawBits(this->_value - src._value);
    
    return (tmp);
}

Fixed Fixed::operator*(const Fixed &src) const
{
    Fixed tmp;
    tmp.setRawBits(this->_value * src._value >> _bit);
    
    return (tmp);
}

Fixed Fixed::operator/(const Fixed &src) const
{
    Fixed tmp;
    if (src._value == 0)
    {
        std::cout << "You cannot divide something by 0." << std::endl;
        return (0);        
    }
    tmp.setRawBits((this->_value << _bit) / src._value);
    
    return (tmp);
}

Fixed &Fixed::operator++()
{
    this->_value++;
    
    return (*this);
}

Fixed &Fixed::operator--()
{
    this->_value--;
    
    return (*this);
}

Fixed Fixed::operator++(int)
{
    Fixed tmp = *this;
    this->_value++;
    
    return (tmp);
}

Fixed Fixed::operator--(int)
{
    Fixed tmp = *this;
    this->_value--;
    
    return (tmp);
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

float Fixed::toFloat(void) const
{
    return (float(_value) / (1 << _bit));
}

int Fixed::toInt(void) const
{
    return (int(_value) / (1 << _bit));
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    if (a > b)
        return (b);
    return (a);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    if (a._value > b._value)
        return (b);
    return (a);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    if (a > b)
        return (a);
    return (b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    if (a._value > b._value)
        return (a);
    return (b);
}

std::ostream &operator<<(std::ostream &out, const Fixed &src)
{
    out << src.toFloat();
    return (out);
}