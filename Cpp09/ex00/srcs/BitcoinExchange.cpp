/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osterger <osterger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 06:02:21 by osterger          #+#    #+#             */
/*   Updated: 2023/11/26 13:03:48 by osterger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

static bool dateIsValid(std::string date);

BitcoinExchange::BitcoinExchange(void)
{
    return ;
}

BitcoinExchange::BitcoinExchange(char *file)
{
    this->_filename = file;

    return ;
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &src)
{
    *this = src;

    return ;
}

BitcoinExchange::~BitcoinExchange(void)
{
    return ;
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &src)
{
    (void)src;

    return (*this);
}

void BitcoinExchange::bitcoinManager(void)
{
    std::multimap<std::string, double>::iterator      tmpIt;

    for (typename std::multimap<std::string, double>::const_iterator itInput = this->_mapInput.begin(); itInput != this->_mapInput.end(); ++itInput)
    {
        for (typename std::multimap<std::string, double>::const_iterator itData = this->_mapData.begin(); itData != this->_mapData.end(); ++itData)
        {
            dateIsValid(itInput->first);
            tmpIt = this->_mapData.lower_bound((*itData).first);

            std::cout << "lower = " << tmpIt->first << std::endl;
            std::cout << "itDataFirst = " << itData->first;
            std::cout << "\n\n";
        }
    }
}

void BitcoinExchange::createMapInput(std::string file)
{
    std::ifstream                   ifs;
    std::string                     line;
    std::string                     date;
    std::string                     value;
    size_t                          pos;
    double                          convertValue;

    ifs.open(file.data(), std::ifstream::in);
    while (ifs.good() && !ifs.eof())
    {
        std::getline(ifs, line);
        pos = line.find('|', 0);
        if (pos != std::string::npos)
        {
            date = line.substr(0, pos - 1);
            value = line.substr(pos + 2, line.size());
            convertValue = atof(value.data());
            if (date != "date" && date != "Date")
                this->_mapInput.insert(std::make_pair(date, convertValue));
        }
        else
            this->_mapInput.insert(std::make_pair(line, -1));
    }
}

void BitcoinExchange::createMapData(void)
{
    std::ifstream                   ifs;
    std::string                     fileData = "data.txt";
    std::string                     line;
    std::string                     date;
    std::string                     value;
    size_t                          pos;
    double                          convertValue;

    ifs.open(fileData.data(), std::ifstream::in);
    while (ifs.good() && !ifs.eof())
    {
        std::getline(ifs, line);
        pos = line.find(',', 0);
        if (pos != std::string::npos)
        {
            date = line.substr(0, pos);
            value = line.substr(pos + 2, line.size());
            convertValue = atof(value.data());
            this->_mapData.insert(std::make_pair(date, convertValue));
        }
    }
}

static bool dateIsValid(std::string date)
{
    std::string         year;
    std::string         month;
    std::string         day;

    double         yearDouble;
    double         monthDouble;
    double         dayDouble;

    if (date.size() != 10)
        return (false);

    year = date.substr(0, 4);
    date = date.substr(4, date.size());
    month = date.substr(1, 2);
    day = date.substr(4, date.size());

    yearDouble = atof(year.data());
    monthDouble = atof(month.data());
    dayDouble = atof(day.data());

    if (yearDouble < 2009 || yearDouble > 2023)
        return (false);
    if (monthDouble <= 0 || monthDouble > 12)
        return (false);
    if (dayDouble <= 0 || monthDouble > 31)
        return (false);
    return (true);
}