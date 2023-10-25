/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 10:44:56 by lboulatr          #+#    #+#             */
/*   Updated: 2023/08/24 15:36:48 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
    int i;

    i = 0;
    if (N <= 0)
    {
        std::cout << "Invalid N." << std::endl;
        return (NULL);
    }
    Zombie* horde = new Zombie[N];

    while (i < N)
    {
        horde[i].setName(name);
        i++;
    }
    
    return (horde);
}