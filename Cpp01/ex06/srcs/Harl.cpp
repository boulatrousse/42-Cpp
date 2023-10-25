/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 09:54:22 by lboulatr          #+#    #+#             */
/*   Updated: 2023/08/21 10:56:44 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void)
{
    return ;
}

Harl::~Harl(void)
{
    return ;
}

void Harl::complain(std::string level)
{
    int             index;
  
    index = getLevelIndex(level);
    switch (index)
    {
        case 0:
            this->debug();
            break ;
        case 1:
            this->info();
            break ;
        case 2:
            this->warning();
            break ;
        case 3:
            this->error();
            break ;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
            break ;
    }

    return ;
}

void Harl::debug(void)
{
    std::cout << "\033[1;36m[ DEBUG ]\033[0m" << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do !" << std::endl;
    std::cout << std::endl;
    info();
    
    return ;
}

void Harl::info(void)
{
    std::cout << "\033[1;32m[ INFO ]\033[0m" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger ! If you did, I wouldn’t be asking for more !" << std::endl;
    std::cout << std::endl;
    warning();

    return ;
}

void Harl::warning(void)
{
    std::cout << "\033[1;34m[ WARNING ]\033[0m" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
    std::cout << std::endl;
    error();
    
    return ;
}

void Harl::error(void)
{
    std::cout << "\033[1;31m[ ERROR ]\033[0m" << std::endl;
    std::cout << "This is unacceptable ! I want to speak to the manager now." << std::endl;
    std::cout << std::endl;

    return ;
}

int getLevelIndex(std::string level)
{
    int             index;
    std::string     levels[4] =
    {
        "DEBUG",
        "INFO",
        "WARNING",
        "ERROR",
    };

    index = 0;
    while (index < 4)
    {
        if (level == levels[index])
            return (index);
        index++;
    }
    return (-1);
}