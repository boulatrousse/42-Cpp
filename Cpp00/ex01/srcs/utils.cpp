/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 09:40:49 by lboulatr          #+#    #+#             */
/*   Updated: 2023/08/21 09:47:40 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <iomanip>
#include "utils.hpp"

void truncate(std::string str)
{
    if (str.size() > 10)
        std::cout << std::right << std::setw(10) << str.substr(0, 9) + "." << "|";
    else
        std::cout << std::right << std::setw(10) << str << "|";
}

void display(void)
{
    std::cout << "\033[1;32m";
    std::cout << "----------+----------+----------+----------+" << std::endl;
    std::cout << std::right << std::setw(10) << "INDEX" << "|";
    std::cout << std::right << std::setw(10) << "NAME" << "|";
    std::cout << std::right << std::setw(10) << "LAST NAME" << "|";
    std::cout << std::right << std::setw(10) << "NICK NAME" << "|\n";
    std::cout << "----------+----------+----------+----------+\033[0m" << std::endl;
}

int check_input(std::string input)
{
    size_t     i;
    size_t     count;

    i = 0;
    count = 0;
    while (i < input.size())
    {
        if (input[i] == ' ')
            count++;
        i++;
    }

    if (count == input.size())
        return (FAILURE);
    return (SUCCESS);
}