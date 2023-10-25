/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 10:14:09 by lboulatr          #+#    #+#             */
/*   Updated: 2023/08/21 15:50:20 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    Zombie z1("billy");
    z1.announce();

    Zombie *z2 = newZombie("alfred");
    z2->announce();

    randomChump("damian");
    
    delete z2;

    return (0);
}