/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osterger <osterger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 03:05:49 by osterger          #+#    #+#             */
/*   Updated: 2023/11/18 01:53:33 by osterger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
    std::string         arg;
    ScalarConverter     &scalarInstance = ScalarConverter::getInstance();
    
    if (argc != 2)
    {
        std::cout << "\033[1;31m";
        std::cout << "Error: wrong number of arguments." << std::endl;
        std::cout << "./convert [string]";
        std::cout << "\033[0m" << std::endl;
        return (1);
    }

    arg = argv[1];

    scalarInstance.convert(arg);

    return (0);
}