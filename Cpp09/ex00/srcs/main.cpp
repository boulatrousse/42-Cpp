/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osterger <osterger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 02:41:36 by osterger          #+#    #+#             */
/*   Updated: 2023/11/29 06:12:59 by osterger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

static int      errorManager(int argc, char *argv1);
static void     printError(std::string error);

int main(int argc, char **argv)
{
    if (errorManager(argc, argv[1]) != SUCCESS)
        return (FAILURE);

    std::string         file;
    BitcoinExchange     btc;

    file = argv[1];
    btc.createMapInput(file);
    btc.createMapData();
    btc.displayExchangeRate();

    return (SUCCESS);
}

static int  errorManager(int argc, char *argv1)
{
    if (argc != 2)
    {
        printError("Error: could not open file. \nUsage: ./btc [database.csv]");
        return (FAILURE);
    }

    std::ifstream       ifs;
    ifs.open(argv1, std::ifstream::in);

    if (!ifs.is_open())
    {
        printError("Error: this file does not exist.");
        return (FAILURE);
    }
    ifs.close();
    return (SUCCESS);
}

static void printError(std::string error)
{
    std::cout << "\033[1;31m";
    std::cout << error;
    std::cout << "\033[0m" << std::endl;
}