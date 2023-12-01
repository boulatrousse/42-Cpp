/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toInt.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osterger <osterger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 08:10:05 by osterger          #+#    #+#             */
/*   Updated: 2023/11/04 04:50:30 by osterger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

static int checkPseudoLiterals(std::string &str);
static int checkZero(std::string &str);
static int checkLimits(std::string &str);

void    toInt(std::string &str)
{ 
    if (checkPseudoLiterals(str) != SUCCESS)
        return ;
    if (checkZero(str) != SUCCESS)
        return ;
    if (checkLimits(str) != SUCCESS)
        return ;
}

static int checkPseudoLiterals(std::string &str)
{
    if (str == "nan" || str == "nanf" || str == "-inf" || \
        str == "-inff" || str == "inf" || str == "+inf" || str == "inff" || str == "+inff")
    {
        std::cout << "int: impossible" << std::endl;
        return (FAILURE);
    }
    return (SUCCESS);
}

static int checkLimits(std::string &str)
{
    int     nbr = std::atoi(str.data());
    double  nbr_d = std::atof(str.data());
    int     j = str[0];

    if (nbr != 0)
    {
        if ((nbr_d < static_cast<double> (INT_MIN)) || nbr_d > static_cast<double> (INT_MAX))
        {
            std::cout << "int: impossible" << std::endl;
            return (FAILURE);
        }
        else
        {
            std::cout << "int: " << nbr << std::endl;
            return (SUCCESS);
        }
    }

    if ((j >= 32 && j < '0') || (j > '9' && j < 127))
    {
        std::cout << "int: " << j << std::endl;
        return (SUCCESS);
    }
    else if (j == 48)
    {
        std::cout << "int: 0" << std::endl;
        return (SUCCESS);
    }

    return (SUCCESS);
}

static int checkZero(std::string &str)
{
    if (str == "+0" || str == "-0")
    {
        std::cout << "int: 0" << std::endl;
        return (FAILURE);
    }
    return (SUCCESS);
}