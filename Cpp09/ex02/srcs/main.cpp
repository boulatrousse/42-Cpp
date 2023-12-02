/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osterger <osterger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 12:18:38 by osterger          #+#    #+#             */
/*   Updated: 2023/12/02 16:04:43 by osterger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <PmergeMe.hpp>

static void printError(std::string error);

int main(int argc, char **argv)
{
    PmergeMe pmerge(argc, argv);

    if (argc < 2)
    {
        printError("Error.\nUsage: ./PmergeMe [args1], ..., [argn].");
        return (1);
    }

    if (!pmerge.checkArg())
    {
        printError("Error.\nWrong arguments.");
        return (1);
    }

    pmerge.displayInfo();

    return (0);
}

static void printError(std::string error)
{
    std::cout << "\033[1;31m";
    std::cout << error;
    std::cout << "\033[0m" << std::endl;
}