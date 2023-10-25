/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 08:21:23 by lboulatr          #+#    #+#             */
/*   Updated: 2023/10/25 08:15:54 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
    {
        Weapon club = Weapon("An archaic club");
        HumanA bob("Bob", club);
        bob.attack();
        club.setType("Colt 45");
        bob.attack();
    }
    {
        Weapon club = Weapon("An archaic club");
        HumanB jim("Jim");
        jim.setWeapon(club);
        jim.attack();
        club.setType("Baseball bat");
        jim.attack();
    }
    return 0;
}