/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toFloat.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osterger <osterger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 08:31:39 by osterger          #+#    #+#             */
/*   Updated: 2023/11/04 04:47:08 by osterger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

static int checkPseudoLiterals(std::string &str);
static int checkZero(std::string &str);
static int checkFloat(std::string &str);

void    toFloat(std::string &str)
{
    if (checkPseudoLiterals(str) != SUCCESS)
        return ;
    if (checkZero(str) != SUCCESS)
        return ;
    if (checkFloat(str) != SUCCESS)
        return ;
}

static int checkPseudoLiterals(std::string &str)
{
    if (str == "nan" || str == "nanf")
    {
        std::cout << "float: nanf" << std::endl;
        return (FAILURE);
    }
    if (str == "-inf" || str == "-inff")
    {
        std::cout << "float: -inff" << std::endl;
        return (FAILURE);
    } 
    if (str == "+inf" || str == "inf" || str == "+inff" || str == "inff")
    {
        std::cout << "float: +inff" << std::endl;
        return (FAILURE);
    } 
    return (SUCCESS);
}

static int checkFloat(std::string &str)
{
    double      nbr_d = std::atof(str.data());
    float       nbr_f = static_cast<float>(nbr_d);
    double      j = str[0];

    if (nbr_d != 0 || nbr_f != 0)
    {
        std::cout << "float: " << nbr_f;
        if (nbr_f == static_cast<int>(nbr_f))
            std::cout << ".0";
        std::cout << "f" << std::endl;
        return (SUCCESS);
    }

    if ((j >= 32 && j < '0') || (j > '9' && j < 127))
    {
        std::cout << "float: " << j;
        std::cout << ".0f" << std::endl;
        return (SUCCESS);
    }
    else if (j == 48)
    {
        std::cout << "float: 0.0f" << std::endl;
        return (SUCCESS);
    }

    return (SUCCESS);
}

static int checkZero(std::string &str)
{
    if (str == "+0" || str == "-0")
    {
        std::cout << "float: 0.0f" << std::endl;
        return (FAILURE);
    }
    return (SUCCESS);
}