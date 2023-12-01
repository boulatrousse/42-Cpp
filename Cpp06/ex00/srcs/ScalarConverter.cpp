/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osterger <osterger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 03:05:18 by osterger          #+#    #+#             */
/*   Updated: 2023/11/18 01:55:34 by osterger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void)
{
    return ;
}

ScalarConverter::ScalarConverter(ScalarConverter const &src)
{
    (void)src;
    
    return ;
}

ScalarConverter::~ScalarConverter(void)
{
    return ;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &src)
{
    (void)src;

    return (*this);
}

ScalarConverter &ScalarConverter::getInstance()
{
    static ScalarConverter instance;

    return (instance);
}

void ScalarConverter::convert(std::string &str)
{
    toChar(str);
    toInt(str);
    toFloat(str);
    toDouble(str);

    return ;
}