/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toDouble.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osterger <osterger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 08:57:42 by osterger          #+#    #+#             */
/*   Updated: 2023/11/04 04:47:58 by osterger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

static int checkPseudoLiterals(std::string &str);
static int checkDouble(std::string &str);
static int checkZero(std::string &str);

void    toDouble(std::string &str)
{
    if (checkPseudoLiterals(str) != SUCCESS)
        return ;
    if (checkZero(str) != SUCCESS)
        return ;
    if (checkDouble(str) != SUCCESS)
        return ;
}

static int checkPseudoLiterals(std::string &str)
{
    if (str == "nan" || str == "nanf")
    {
        std::cout << "double: nan" << std::endl;
        return (FAILURE);
    }
    if (str == "-inf" || str == "-inff")
    {
        std::cout << "double: -inf" << std::endl;
        return (FAILURE);
    } 
    if (str == "+inf" || str == "inf" || str == "+inff" || str == "inff")
    {
        std::cout << "double: +inf" << std::endl;
        return (FAILURE);
    } 
    return (SUCCESS);
}

static int checkDouble(std::string &str)
{
    double      nbr_d = std::atof(str.data());
    double      j = str[0];

    if (nbr_d != 0)
    {
        std::cout << "double: " << nbr_d;
        if (nbr_d == static_cast<int>(nbr_d))
            std::cout << ".0";
        std::cout << std::endl;
        return (SUCCESS);
    }
    
    if ((j >= 32 && j < '0') || (j > '9' && j < 127))
    {
        std::cout << "double: " << j;
        std::cout << ".0" << std::endl;
        return (SUCCESS);
    }
    else if (j == 48)
    {
        std::cout << "double: 0.0" << std::endl;
        return (SUCCESS);
    }

    return (SUCCESS);
}

static int checkZero(std::string &str)
{
    if (str == "+0" || str == "-0")
    {
        std::cout << "double: 0.0" << std::endl;
        return (FAILURE);
    }
    return (SUCCESS);
}