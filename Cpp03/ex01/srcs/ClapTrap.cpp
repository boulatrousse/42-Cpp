/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 08:57:40 by lboulatr          #+#    #+#             */
/*   Updated: 2023/08/24 07:56:43 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
{
    std::cout << "Default constructor called." << std::endl;

    this->_hp = 10;
    this->_energyPoints = 10;
    this->_damage = 0;
    
    return ;
}

ClapTrap::ClapTrap(std::string name)
{
    std::cout << "Constructor for ClapTrap ";
    std::cout << name << " called." << std::endl;
    
    this->_name = name;
    this->_hp = 10;
    this->_energyPoints = 10;
    this->_damage = 0;
    
    return ;
}

ClapTrap::ClapTrap(const ClapTrap &src)
{
    std::cout << "Copy constructor called." << std::endl;
    *this = src;

    return ;
}

ClapTrap::~ClapTrap(void)
{
    std::cout << "Destructor for ClapTrap ";
    std::cout << this->_name << " called." << std::endl;

    return ;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &src)
{
    std::cout << "Copy assignment operator called." << std::endl;
    
    this->_name = src._name;   
    this->_hp = src._hp;
    this->_energyPoints = src._energyPoints;    
    this->_damage = src._damage;
    
    return (*this);
}

void ClapTrap::attack(const std::string &target)
{
    
    if (this->_hp <= 0)
        return (printDeath(this));
    if (this->_energyPoints <= 0)
        return (printNoEnergy(this));

    std::cout << "\033[1;36m";
    std::cout << "ClapTrap " << this->_name;
    std::cout << " attacks " << target;
    std::cout << ", causing ";
    std::cout << this->_damage << " points of damage !";
    std::cout << "\033[1;0m" << std::endl;

    this->_energyPoints--;

    return ;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    
    if (this->_hp <= 0)
        return (printDeath(this));
    
    std::cout << "\033[1;34m";
    std::cout << "ClapTrap " << this->_name;
    std::cout << " is taking " << amount << " points of damage !" << std::endl;
    std::cout << "\033[1;0m";
    this->_hp -= amount;
    
    return ;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    
    
    if (this->_hp <= 0)
        return (printDeath(this));
    if (this->_energyPoints <= 0)
        return (printNoEnergy(this));
    
    std::cout << "\033[1;32m";
    std::cout << "ClapTrap " << this->_name;
    std::cout << " is repairing himself and regains ";
    std::cout << amount << " health point(s) !\033[0m" << std::endl;
    this->_hp += amount;
    this->_energyPoints--;
    
    return ;
}

std::string ClapTrap::getName(void)
{
    return (this->_name);
}

void printDeath(ClapTrap *clap)
{
    std::cout << "\033[1;31m";
    std::cout << "ClapTrap " << clap->getName();
    std::cout << " is dead !";
    std::cout << "\033[1;0m" << std::endl;
    
    return ;
}

void printNoEnergy(ClapTrap *clap)
{
    std::cout << "\033[1;34m";
    std::cout << "ClapTrap " << clap->getName();
    std::cout << " doesn't have enough energy !";
    std::cout << "\033[1;0m" << std::endl;
    
    return ;
}

