/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osterger <osterger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 07:55:10 by osterger          #+#    #+#             */
/*   Updated: 2023/12/02 12:10:54 by osterger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

static void printError(std::string error);

int main(int argc, char **argv)
{
    std::string     arg;

    if (argc != 2)
    {
        printError("Error.\nUsage : ./RPN [arg]");
        return (FAILURE);
    }
    
    arg = argv[1];
    RPN rpn(arg);

    if (!rpn.checkArg(arg))
    {
        printError("Error.\nWrong arguments.");
        return (FAILURE);
    }

    if (!rpn.operations())
    {
        printError("Error.\nWrong arguments.");
        return (FAILURE);
    }
    
    return (SUCCESS);
}

static void printError(std::string error)
{
    std::cout << "\033[1;31m";
    std::cout << error;
    std::cout << "\033[0m" << std::endl;
}