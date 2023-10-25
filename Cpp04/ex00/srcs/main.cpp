/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 14:41:35 by lboulatr          #+#    #+#             */
/*   Updated: 2023/08/31 11:24:27 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
    const Animal* Meta = new Animal();
    const Animal* Yeti = new Cat("Maine Coone");
    const Animal* Maiko = new Dog("Golden");
    const Animal* Dodge;
    const WrongAnimal* Wrong = new WrongCat();

    Dog     Borg("Australian Sheperd");
    Cat     Berry("Chartreux");

    Dodge = &Borg;
    
    std::cout << std::endl;
    std::cout << "Type: " << Yeti->getType() << std::endl;
    Yeti->makeSound(); //will output the cat sound!
    std::cout << "Type: " << Maiko->getType() << std::endl;
    Maiko->makeSound();
    
    std::cout << std::endl;
    std::cout << "Type: " << Meta->getType() << std::endl;
    Meta->makeSound();
    std::cout << std::endl;

    std::cout << "Type: " << Dodge->getType() << std::endl;
    Dodge->makeSound();
    std::cout << "Type: " << Borg.getType() << std::endl;
    Borg.makeSound();
    std::cout << "Type: " << Berry.getType() << std::endl;
    Berry.makeSound();

    std::cout << std::endl;
    std::cout << "Type: " << Wrong->getType() << std::endl;
    Wrong->makeSound();
    std::cout << std::endl;
    
    delete Meta;
    delete Yeti;
    delete Maiko;
    delete Wrong;
    
    return 0;
}
