/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 02:41:36 by osterger          #+#    #+#             */
/*   Updated: 2023/12/13 10:28:55 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

static bool     errorManager(int argc, char *argv1);
static bool     checkFile(char *argv1);
static bool     checkFileIsEmtpy(std::ifstream &file);
static void     printError(std::string error);


int main(int argc, char **argv)
{
    if (errorManager(argc, argv[1]) != true)
        return (FAILURE);

    std::string         file;
    BitcoinExchange     btc;

    file = argv[1];
    btc.createMapInput(file);
    btc.createMapData();
    btc.displayExchangeRate();

    return (SUCCESS);
}

static bool  errorManager(int argc, char *argv1)
{
    if (argc != 2 || !checkFile(argv1))
        return (printError("Error: could not open file. \nUsage: ./btc [input.txt/csv]"), false);

    std::ifstream       ifs;
    ifs.open(argv1, std::ifstream::in);

    if (!ifs.is_open())
        return (printError("Error: this file does not exist."), false);
    if (checkFileIsEmtpy(ifs))
        return (printError("Error: this file is empty."), false);

    ifs.close();

    return (true);
}

static bool checkFile(char *argv1)
{
    std::string     file = argv1;

    if (file.find(".txt") != std::string::npos || file.find(".csv") != std::string::npos)
        return (true);
    return (false);
}

static bool checkFileIsEmtpy(std::ifstream &ifs)
{
    return (ifs.peek() == std::ifstream::traits_type::eof());
}

static void printError(std::string error)
{
    std::cout << "\033[1;31m";
    std::cout << error;
    std::cout << "\033[0m" << std::endl;
}