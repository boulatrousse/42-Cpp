/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 12:18:38 by osterger          #+#    #+#             */
/*   Updated: 2023/12/10 10:11:29 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <PmergeMe.hpp>

static void printError(std::string error);

int main(int argc, char **argv)
{
    PmergeMe pmerge(argc, argv);

    if (argc < 2)
        return (printError("Error.\nUsage: ./PmergeMe [args1], ..., [argn]."), 1);
    if (!pmerge.checkArg())
        return (printError("Error.\nWrong arguments."), 1);

    pmerge.displayInfo();
    pmerge.insertionSortVector();

    return (0);
}

static void printError(std::string error)
{
    std::cout << "\033[1;31m";
    std::cout << error;
    std::cout << "\033[0m" << std::endl;
}