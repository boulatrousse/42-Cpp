/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 13:48:35 by lboulatr          #+#    #+#             */
/*   Updated: 2023/08/03 14:04:50 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap()
{
    std::cout << "Default constructor for FragTrap called." << std::endl;

    this->_hp = 100;
    this->_energyPoints = 100;
    this->_damage = 30;
    
    return ;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    std::cout << "Constructor for FragTrap ";
    std::cout << name << " called." << std::endl;
    
    this->_name = name;
    this->_hp = 100;
    this->_energyPoints = 100;
    this->_damage = 30;
    
    return ;
}

FragTrap::FragTrap(const FragTrap &src)
{
    std::cout << "Copy constructor for FragTrap called." << std::endl;
    *this = src;

    return ;
}

FragTrap::~FragTrap(void)
{
    std::cout << "Destructor for FragTrap ";
    std::cout << this->_name << " called." << std::endl;

    return ;
}

FragTrap &FragTrap::operator=(FragTrap const &src)
{
    std::cout << "Copy assignment operator called." << std::endl;
    
    this->_name = src._name;   
    this->_hp = src._hp;
    this->_energyPoints = src._energyPoints;    
    this->_damage = src._damage;
    
    return (*this);
}

void FragTrap::highFiveGuys()
{
    std::cout << "\033[1;35m[ ";
    std::cout << this->_name << " wants to highfive ! ]\033[0m" << std::endl;

    return ;
}