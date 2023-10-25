/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 14:41:35 by lboulatr          #+#    #+#             */
/*   Updated: 2023/08/31 11:39:41 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

#define N_ANIMALS   6

int main()
{
    Animal*     tab[N_ANIMALS];
    Dog         *doug = new Dog();
    Dog         douggy = *doug;

    Cat         Zebulus("Cat");

    for (int i = 0; i < N_ANIMALS; i++)
    {
        if ((i % 2) == 0)
            tab[i] = new Cat();
        else
            tab[i] = new Dog();
    }

    std::cout << std::endl;
    std::cout << std::endl;
    for (int i = 0; i < N_ANIMALS; i++)
    {
        for (int j = 0; j < (N_IDEAS / 10); j++)
        {
            std::cout << tab[i]->getType() << " :";
            std::cout << tab[i]->getBrain()->getIdea(j) << std::endl;
        }
    }
    
    std::cout << std::endl;
    std::cout << std::endl;
    for (int i = 0; i < N_ANIMALS; i++)
    {
        std::cout << tab[i]->getType() << std::endl;
    }
    std::cout << std::endl;
    
    for (int i = 0; i < N_ANIMALS; i++)
        delete tab[i];
    
    delete doug;
        
    return 0;
}
