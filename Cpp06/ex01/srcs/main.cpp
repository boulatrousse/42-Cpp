/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 09:48:22 by osterger          #+#    #+#             */
/*   Updated: 2023/11/13 08:13:53 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(int argc, char **argv)
{
    (void)argv;
    
    if (argc != 1)
    {
        std::cout << "Usage: ./serialize" << std::endl;    
        return (1);
    }

    Data data;

    data.n = 42;
    data.s1 = "Hello";
    data.s2 = "World";

    std::cout << data.s1 << std::endl;
    std::cout << data.n << std::endl;
    std::cout << data.s2 << std::endl;

    uintptr_t raw = Serializer::serialize(&data);
    std::cout << "Raw = " << raw << std::endl;    
    
    Data *rest = Serializer::deserialize(raw);

    std::cout << rest->s1 << std::endl;
    std::cout << rest->n << std::endl;
    std::cout << rest->s2 << std::endl;
    
    return (0);
}