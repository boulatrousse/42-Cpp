/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 11:20:57 by lboulatr          #+#    #+#             */
/*   Updated: 2023/08/01 11:02:32 by lboulatr         ###   ########.fr       */
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
        
        Fixed &operator=(const Fixed &src);

        int     getRawBits(void) const;
        void    setRawBits(int const raw);
        float   toFloat(void) const;
        int     toInt(void) const;

    private:

        int                 _value;
        const static int    _bit = 8;
        
};

std::ostream &operator<<(std::ostream &out, const Fixed &src);

#endif