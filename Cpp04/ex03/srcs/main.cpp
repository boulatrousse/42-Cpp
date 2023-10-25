/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 14:00:28 by lboulatr          #+#    #+#             */
/*   Updated: 2023/09/06 13:55:28 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Cure.hpp"
#include "Ice.hpp"

int main()
{    
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    ICharacter* me = new Character("me");

    AMateria* tmp;    
    tmp = src->createMateria("cure");
    me->equip(tmp);
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    me->equip(tmp);
    
    
    std::cout << "\n========== USE ==========\n" << std::endl;
    ICharacter* Stockton = new Character("Stockton");
    std::cout << std::endl;
    me->use(0, *Stockton);
    std::cout << std::endl;
    me->use(1, *Stockton);
    std::cout << std::endl;
    me->use(2, *Stockton);
    std::cout << std::endl;
    me->use(22, *Stockton);
    std::cout << std::endl;

    std::cout << "\n========== EQUIP ==========\n" << std::endl;
    ICharacter* Alfred = new Character("Alfred");
    me->equip(src->createMateria("ice"));
    me->equip(src->createMateria("ice"));
    me->equip(src->createMateria("cure"));
    me->equip(src->createMateria("cure"));
    std::cout << "OK" << std::endl;
    //me->equip(src->createMateria("ice"));

    std::cout << "\n========== UNEQUIP ==========\n" << std::endl;
    me->unequip(0);
    me->unequip(1);
    me->unequip(2);
    me->unequip(3);
    me->unequip(4);
    me->equip(src->createMateria("ice"));
	me->equip(NULL);
	me->equip(src->createMateria("ice"));
    me->use(0, *Alfred);
	me->use(1, *Alfred); 
    me->use(2, *Alfred); 

    std::cout << std::endl;

    delete Stockton;
    delete Alfred;
    delete me;
    delete tmp;
    delete src;
    return 0;
}
