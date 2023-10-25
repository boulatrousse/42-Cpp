/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 12:33:44 by lboulatr          #+#    #+#             */
/*   Updated: 2023/08/23 11:14:08 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
    this->_name = name;
    this->_weapon = NULL;
    return ;
}

HumanB::~HumanB(void)
{
    return ;
}

void HumanB::attack(void)
{
	std::cout << this->_name;
    if (this->_weapon == NULL)
        std::cout << " attacks with nothing." << std::endl;
    else
    {
        std::cout << " attacks with his ";
        std::cout << this->_weapon->getType() << std::endl;
    }

    return ;
}

void HumanB::setWeapon(Weapon& weapon)
{
    this->_weapon = &weapon;   
    return ;
}