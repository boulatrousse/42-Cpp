/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 09:54:22 by lboulatr          #+#    #+#             */
/*   Updated: 2023/08/05 10:28:53 by lboulatr         ###   ########.fr       */
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
    int             i;
    std::string     levels[4] =
    {
        "DEBUG",
        "INFO",
        "WARNING",
        "ERROR",
    };
    void            (Harl::*function[4])(void) = 
    {  
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error,
    };
  
    i = 0;
    while (i < 4)
    {
        if (level == levels[i])
            (this->*function[i])();
        i++;
    }

    return ;
}

void Harl::debug(void)
{
    std::cout << "I love having extra bacon for my ";
    std::cout << "SCR McGriddle burger. I really do !" << std::endl;
    
    return ;
}

void Harl::info(void)
{
    std::cout << "I cannot believe adding extra bacon costs more money.";
    std::cout << " You didn’t put enough bacon in my burger ! If you did, I wouldn’t be asking for more !" << std::endl;
    
    return ;
}

void Harl::warning(void)
{
    std::cout << "I think I deserve to have some extra bacon for free.";
    std::cout << " I’ve been coming for years whereas you started working here since last month." << std::endl;
    
    return ;
}

void Harl::error(void)
{
    std::cout << "This is unacceptable ! I want to speak to the manager now." << std::endl;
    
    return ;
}