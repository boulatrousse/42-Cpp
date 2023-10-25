/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 15:46:13 by osterger          #+#    #+#             */
/*   Updated: 2023/08/29 08:27:38 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
    for (int i = 0; i < N_MATERIAS; i++)
        this->_inventory[i] = NULL;

    return ;
}

MateriaSource::MateriaSource(const MateriaSource &src)
{
    for (int i = 0; i < N_MATERIAS; i++)
    {
        if (src._inventory[i])
            this->_inventory[i] = src._inventory[i]->clone();
        else
            this->_inventory[i] = NULL;   
    }

    return ;
}

MateriaSource::~MateriaSource(void)
{
    for (int i = 0; i < N_MATERIAS; i++)
    {
        if (this->_inventory[i] != NULL)
            delete this->_inventory[i];
    }

    return ;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &src)
{
    if (this != &src)
    {
        for (int i = 0; i < N_MATERIAS; i++)
            this->_inventory[i] = src._inventory[i];
    }

    return (*this);
}

void MateriaSource::learnMateria(AMateria *m)
{
    if (!m)
    {
        std::cout << "This materia does not exist !" << std::endl;
        return ;
    }

    for (int i = 0; i < N_MATERIAS; i++)
    {
        if (this->_inventory[i] == NULL)
        {
            this->_inventory[i] = m;
            break ;   
        }
    }

    return ;
}

AMateria *MateriaSource::createMateria(const std::string &type)
{
    for (int i = 0; i < N_MATERIAS; i++)
    {
        if (this->_inventory[i] && (this->_inventory[i]->getType() == type))
            return (this->_inventory[i]->clone());
    }
    return (NULL);
}