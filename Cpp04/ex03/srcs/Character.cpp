/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 14:35:33 by osterger          #+#    #+#             */
/*   Updated: 2023/09/06 13:51:14 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(void)
{
    return ;
}

Character::Character(const std::string &name)
{
    this->_name = name;

    for (int i = 0; i < N_MATERIAS; i++)
        this->_inventory[i] = NULL;

    for (int i = 0; i < N_SURROUND; i++)
        this->_surround[i] = NULL;
        
    return ;
}

Character::Character(const Character &src)
{
    this->_name = src._name;

    for (int i = 0; i < N_MATERIAS; i++)
    {
        if (src._inventory[i])
            this->_inventory[i] = src._inventory[i]->clone();
        else
            this->_inventory[i] = NULL;   
    }

    return ;
}

Character::~Character(void)
{
    for (int i = 0; i < N_MATERIAS; i++)
    {
        if (this->_inventory[i] != NULL)
            delete this->_inventory[i];
    }
    for (int i = 0; i < N_SURROUND; i++)
    {
        if (this->_surround[i] != NULL)
            delete this->_surround[i];
    }

    return ;
}

Character &Character::operator=(const Character &src)
{
    if (this != &src)
    {
        this->_name = src._name;
        for (int i = 0; i < N_MATERIAS; i++)
        {
            if (this->_inventory[i])
                delete this->_inventory[i];
            if (src._inventory[i])
                this->_inventory[i] = src._inventory[i]->clone();
            else
                this->_inventory[i] = NULL;
        }
    }

    return (*this);
}

void Character::equip(AMateria *m)
{
    if (!m)
    {
        std::cout << "This materia does not exist !" << std::endl;
        return ;
    }

    for (int i = 0; i < N_MATERIAS; i++)
    {
        if (this->_inventory[i] == m)
        {
            std::cout << "You cannot equip the same materia in 2 differents spots !" << std::endl;
            return ;
        }
        if (this->_inventory[i] == NULL)
        {
            this->_inventory[i] = m;
            break ;   
        }
        if (i == (N_MATERIAS - 1))
        {
            std::cout << i << " Inventory is full." << std::endl;
            //delete m;
            break ;
        }
    }

    return ;
}

void Character::unequip(int idx)
{
    if (idx < 0 || idx > N_MATERIAS)
    {
        std::cout << "Error: wrong index." << std::endl;
        return ;
    }     
    if (this->_inventory[idx] == NULL)
    {
        std::cout << "This slot is already empty !" << std::endl;
        return ;
    }
    
    for (int i = 0; i < N_SURROUND; i++)
    {
        if (!this->_surround[i])
        {
            this->_surround[i] = this->_inventory[idx]->clone();
            delete this->_inventory[idx];
            break ;
        }
        if (i == (N_SURROUND - 1))
        {
            delete this->_surround[0];
            this->_surround[0] = this->_inventory[idx]->clone();
            delete this->_inventory[idx];
            break ;
        }
    }
    this->_inventory[idx] = NULL;
    return ;
}

void Character::use(int idx, ICharacter &target)
{
    if (idx >= 0 && idx <= N_MATERIAS - 1)
    {
        if (this->_inventory[idx])
        {
            this->_inventory[idx]->use(target);
            delete this->_inventory[idx];
            this->_inventory[idx] = NULL;
        }
        else
            std::cout << "No Materia at this index." << std::endl;
    }
    else
        std::cout << "Error: wrong index." << std::endl;

    return ;
}

const std::string &Character::getName() const
{
    return (this->_name);
}
