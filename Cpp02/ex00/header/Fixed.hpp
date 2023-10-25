/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 11:20:57 by lboulatr          #+#    #+#             */
/*   Updated: 2023/08/03 08:52:08 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>

class Fixed
{
    public:

        Fixed(void);
        Fixed(const Fixed &src);
        ~Fixed(void);
        Fixed &operator=(const Fixed &src);

        int     getRawBits(void) const;
        void    setRawBits(int const raw);

    private:

        int                 _value;
        const static int    _bit = 8;
        
};

#endif