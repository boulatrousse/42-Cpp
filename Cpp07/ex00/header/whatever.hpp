/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 16:20:05 by lboulatr          #+#    #+#             */
/*   Updated: 2023/10/10 16:27:26 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>

template<typename T>
void    swap(T &a, T &b)
{
    T tmp = a;
    a = b;
    b = tmp;
}

template<typename T>
T min(T &a, T &b)
{
    if (a == b)
        return (b);
    if (a > b)
        return (b);
    else
        return (a);
}

template<typename T>
T max(T &a, T &b)
{
    if (a == b)
        return (b);
    if (a > b)
        return (a);
    else
        return (b);
}

#endif