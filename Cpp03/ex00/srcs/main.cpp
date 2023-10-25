/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 08:57:37 by lboulatr          #+#    #+#             */
/*   Updated: 2023/08/24 07:32:59 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
    ClapTrap Billy("Billy");

    Billy.attack("Alfred");
    Billy.takeDamage(5);
    Billy.beRepaired(25);

    for(int i = 0; i < 8; i++)
        Billy.beRepaired(1);

    Billy.takeDamage(5);
    Billy.takeDamage(50);
    Billy.takeDamage(5);
    Billy.attack("Alfred");

    return (0);
}