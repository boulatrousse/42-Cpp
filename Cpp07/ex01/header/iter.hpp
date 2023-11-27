/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 16:30:41 by lboulatr          #+#    #+#             */
/*   Updated: 2023/11/27 10:43:51 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template<typename T>
void    iter(T *array, int length, void (*fct)(T const &))
{
    for (int i = 0; i < length; i++)
        fct(array[i]);
}

template<typename T>
void    iter(T *array, int length, void (*fct)(T &))
{
    for (int i = 0; i < length; i++)
        fct(array[i]);
}

#endif