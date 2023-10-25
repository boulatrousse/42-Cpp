/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 14:41:35 by lboulatr          #+#    #+#             */
/*   Updated: 2023/08/27 10:40:48 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#define N_ANIMALS   10

int main()
{
    //Animal      bob;
    Animal*     tab[N_ANIMALS];
    Dog         doug;
    Dog         douggy;

    for (int i = 0; i < N_ANIMALS; i++)
    {
        if ((i % 2) == 0)
            tab[i] = new Cat();
        else
            tab[i] = new Dog();
    }
    
    for (int i = 0; i < N_ANIMALS; i++)
        delete tab[i];
        
    return 0;
}
