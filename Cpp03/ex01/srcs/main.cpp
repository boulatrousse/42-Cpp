/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 08:57:37 by lboulatr          #+#    #+#             */
/*   Updated: 2023/08/03 12:50:50 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    ClapTrap Billy("Billy");
    ScavTrap John("John");

    for(int i = 0; i < 12; i++)
        Billy.beRepaired(1);
    Billy.attack("Damian");
    
    John.guardGate();
    John.attack("Stockton");
    for(int i = 0; i < 6; i++)
        John.takeDamage(20);
    John.beRepaired(200);
    John.guardGate();
    
    return (0);
}