/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 16:30:01 by lboulatr          #+#    #+#             */
/*   Updated: 2023/11/27 11:02:32 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

static void print(int const &i);
static void time5(int const &i);
static void addHello(std::string const &str);

int main(int argc, char **argv)
{
    (void)argv;
    if (argc != 1)
    {
        std::cout << "Usage: ./iter" << std::endl;
        return 1;
    }
    
    int array[] = {1, 2, 3, 4, 5};
    std::string str_array[] = {"Stockton", "World", "Mama", "Hello", "42"};

    iter(array, 5, print);
    std::cout << std::endl;

    iter(array, 5, time5);
    std::cout << std::endl;

    iter(str_array, 5, addHello);
    std::cout << std::endl;

    return 0;
}

static void print(int const &i)
{
    std::cout << i << std::endl;
}

static void time5(int const &i)
{
    int x = i;
    
    x *= 5;
    std::cout << x << std::endl;
}

static void addHello(std::string const &str)
{
    std::string tmp = str;
    
    tmp += " Hello";
    std::cout << tmp << std::endl;
}
