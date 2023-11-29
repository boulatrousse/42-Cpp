/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osterger <osterger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 06:02:21 by osterger          #+#    #+#             */
/*   Updated: 2023/11/29 07:52:13 by osterger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

static bool dateIsValid(std::string date);
static bool numberIsValid(float n);
static void printRate(std::multimap<std::string, float>::iterator it, float rate);

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

void BitcoinExchange::displayExchangeRate(void)
{
    std::multimap<std::string, float>::iterator      itInput;
    std::multimap<std::string, float>::iterator      itData;
    std::multimap<std::string, float>::iterator      tmp;

    for (itInput = this->_mapInput.begin(); itInput != this->_mapInput.end(); itInput++)
    {
        if (!dateIsValid((*itInput).first))
            std::cout << "Error: bad input => " << (*itInput).first << std::endl;
        else if (!numberIsValid((*itInput).second))
            continue ;
        else
        {
            for (itData = this->_mapData.begin(); itData != this->_mapData.end(); itData++)
            {
                if (getExchangeRate(((*itInput).first), (*itData).first))
                {
                    tmp = this->_mapData.lower_bound((*itData).first);

                    if (this->_mapData.find((*itInput).first) !=  this->_mapData.end())
                        printRate(itInput, (*tmp).second);
                    else
                    {
                        tmp--;
                        printRate(itInput, (*tmp).second);
                    }
                    break ;
                }
            }
        }
    }
    
}

bool BitcoinExchange::getExchangeRate(std::string input, std::string data)
{
    float               yearInput;
    float               monthInput;
    float               dayInput;
    float               yearData;
    float               monthData;
    float               dayData;

    yearInput = atof(input.substr(0).data());
    monthInput = atof(input.substr(5).data());
    dayInput = atof(input.substr(8).data());
    yearData = atof(data.substr(0).data());
    monthData = atof(data.substr(5).data());
    dayData = atof(data.substr(8).data());

    if (yearData >= yearInput && monthData >= monthInput && dayData >= dayInput)
        return (true);
    return (false);
}

void BitcoinExchange::createMapInput(std::string file)
{
    std::ifstream                   ifs;
    std::string                     line;
    std::string                     date;
    std::string                     value;
    size_t                          pos;
    float                          convertValue;

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
    std::string                     fileData = "data.csv";
    std::string                     line;
    std::string                     date;
    std::string                     value;
    size_t                          pos;
    float                          convertValue;

    ifs.open(fileData.data(), std::ifstream::in);
    while (ifs.good() && !ifs.eof())
    {
        std::getline(ifs, line);
        pos = line.find(',', 0);
        if (pos != std::string::npos)
        {
            date = line.substr(0, pos);
            value = line.substr(pos + 1, line.size());
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
    float               yearfloat;
    float               monthfloat;
    float               dayfloat;

    if (date.size() != 10)
        return (false);

    year = date.substr(0, 4);
    date = date.substr(4, date.size());
    month = date.substr(1, 2);
    day = date.substr(4, date.size());

    yearfloat = atof(year.data());
    monthfloat = atof(month.data());
    dayfloat = atof(day.data());

    if (yearfloat < 2009 || yearfloat > 2023)
        return (false);
    if (monthfloat <= 0 || monthfloat > 12)
        return (false);
    if (dayfloat <= 0 || monthfloat > 31)
        return (false);
    return (true);
}

static bool numberIsValid(float n)
{
    if (n < 0)
    {
        std::cout << "Error: not a positive number." << std::endl;
        return (false);
    }
    else if (n > 1000)
    {
        std::cout << "Error: number too large." << std::endl;
        return (false);
    }
    return (true);
}

static void printRate(std::multimap<std::string, float>::iterator it, float rate)
{
    std::cout << (*it).first << " => " << (*it).second << " = " << (*it).second * rate << std::endl;
}