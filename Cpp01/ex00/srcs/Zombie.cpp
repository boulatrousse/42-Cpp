/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 10:07:47 by lboulatr          #+#    #+#             */
/*   Updated: 2023/08/20 15:45:12 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
    _name = name;

    return ;
}

Zombie::~Zombie(void)
{
    std::cout << "Destructor: ";
    std::cout << "\033[1;31m";
    std::cout << this->_name;
    std::cout << "\033[0m";
    std::cout << " has been deleted." << std::endl;

    return ;
}

void Zombie::announce(void)
{
    std::cout << this->_name;
    std::cout << ":  BraiiiiiiinnnzzzZ..." << std::endl;

    return ;
}