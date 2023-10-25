/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 12:28:30 by lboulatr          #+#    #+#             */
/*   Updated: 2023/08/21 10:42:20 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <string>

static int ft_getline(void);

int main(int argc, char **argv)
{
    (void)argv;

    PhoneBook       phonebook;
    std::string     input;

    if (argc != 1)
    {
        std::cout << "Too many arguments." << std::endl;
        return (FAILURE);
    }
    
    while (ft_getline() && std::getline(std::cin, input))
    {
        if (input == "ADD")
            phonebook.add();
        else if (input == "SEARCH")
            phonebook.search();
        else if (input == "EXIT")
            break ;
        else
            std::cout << "Wrong command." << std::endl;
    }

    return (0);
}

static int ft_getline(void)
{
    std::cout << "\033[1;32m";
    std::cout << "\n----- ENTER A COMMAND -----\n\033[0m" << std::endl;
    std::cout << "1. ADD\n2. SEARCH\n3. EXIT\n" << std::endl;

    return (1);
}