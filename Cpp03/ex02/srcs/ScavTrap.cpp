/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 10:29:10 by lboulatr          #+#    #+#             */
/*   Updated: 2023/08/24 08:59:02 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap()
{
    std::cout << "Default constructor for ScavTrap called." << std::endl;

    this->_hp = 100;
    this->_energyPoints = 50;
    this->_damage = 20;
    
    return ;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    std::cout << "Constructor for ScavTrap ";
    std::cout << name << " called." << std::endl;
    
    this->_name = name;
    this->_hp = 100;
    this->_energyPoints = 50;
    this->_damage = 20;
    
    return ;
}

ScavTrap::ScavTrap(const ScavTrap &src)
{
    std::cout << "Copy constructor called." << std::endl;
    *this = src;

    return ;
}

ScavTrap::~ScavTrap(void)
{
    std::cout << "Destructor for ScavTrap ";
    std::cout << this->_name << " called." << std::endl;

    return ;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &src)
{
    std::cout << "Copy assignment operator called." << std::endl;
    
    this->_name = src._name;   
    this->_hp = src._hp;
    this->_energyPoints = src._energyPoints;    
    this->_damage = src._damage;
    
    return (*this);
}


void ScavTrap::attack(const std::string &target)
{
    
    if (this->_hp <= 0)
        return (printDeath(this));
    if (this->_energyPoints <= 0)
        return (printNoEnergy(this));

    std::cout << "\033[1;36m";
    std::cout << "ScavTrap " << this->_name;
    std::cout << " shoots " << target;
    std::cout << " and does ";
    std::cout << this->_damage << " points of damage ! \033[0m" << std::endl;

    this->_energyPoints--;

    return ;
}

void ScavTrap::guardGate(void)
{
    if (this->_hp <= 0)
        return (printDeath(this));
    
    std::cout << "\033[1;35m";
    std::cout << "[ Be advised, ScavTrap " << this->_name;
    std::cout << " has entered Gate Keeper mode ! ]\033[0m" << std::endl;

    return ;
}

void printDeath(ScavTrap *scav)
{
    std::cout << "\033[1;31m";
    std::cout << "ScavTrap " << scav->getName();
    std::cout << " has sadly passed away..." << std::endl;
    std::cout << "\033[1;0m" << std::endl;
    
    return ;
}

void printNoEnergy(ScavTrap *scav)
{
    std::cout << "\033[1;34m";
    std::cout << "ScavTrap " << scav->getName();
    std::cout << " is too tired..." << std::endl;
    std::cout << "\033[1;0m" << std::endl;
    
    return ;
}