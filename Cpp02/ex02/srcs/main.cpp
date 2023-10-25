/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 11:17:43 by lboulatr          #+#    #+#             */
/*   Updated: 2023/08/24 11:03:13 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void )
{
    Fixed a;
    Fixed z(500);
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    Fixed const c(1000);
    Fixed const d(0);
    
    std::cout << a << std::endl;
    
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;    
    std::cout << b << std::endl;
    std::cout << Fixed::max( a, b ) << std::endl;
    std::cout << Fixed::max( c, b) << std::endl;
    std::cout << Fixed::min( c, b) << std::endl;
    Fixed const e = c/d;
    
    return 0;
}