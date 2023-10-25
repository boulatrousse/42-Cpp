/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 11:20:57 by lboulatr          #+#    #+#             */
/*   Updated: 2023/08/03 08:05:51 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>
# include <cmath>

class Fixed
{
    public:

        Fixed(void);
        Fixed(const Fixed &src);
        Fixed(const int value);
        Fixed(const float value);
        ~Fixed(void);
        
        bool                    operator<(const Fixed &src) const;
        bool                    operator<=(const Fixed &src) const;
        bool                    operator>(const Fixed &src) const;
        bool                    operator>=(const Fixed &src) const;
        bool                    operator==(const Fixed &src) const;
        bool                    operator!=(const Fixed &src) const;

        Fixed&                  operator=(const Fixed &src);
        Fixed                   operator+(const Fixed &src) const;
        Fixed                   operator-(const Fixed &src) const;
        Fixed                   operator*(const Fixed &src) const;
        Fixed                   operator/(const Fixed &src) const;

        Fixed&                  operator++();
        Fixed&                  operator--();
        Fixed                   operator++(int);
        Fixed                   operator--(int);

        int                     getRawBits(void) const;
        void                    setRawBits(int const raw);
        float                   toFloat(void) const;
        int                     toInt(void) const;
        static Fixed&           min(Fixed &a, Fixed &b);
        static const Fixed&     min(const Fixed &a, const Fixed &b);
        static Fixed&           max(Fixed &a, Fixed &b);
        static const Fixed&     max(const Fixed &a, const Fixed &b);

    private:

        int                 _value;
        const static int    _bit = 8;
        
};

std::ostream &operator<<(std::ostream &out, const Fixed &src);

#endif