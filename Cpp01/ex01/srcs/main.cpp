/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 10:44:29 by lboulatr          #+#    #+#             */
/*   Updated: 2023/08/24 15:37:16 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    int n_zombies;

    n_zombies = 1;
    Zombie *horde = zombieHorde(n_zombies, "Billy");

    for (int i = 0; i < n_zombies; i++)
        horde[i].announce();
    
    std::cout << std::endl;
    
    delete [] horde;
    
    return (0);
}