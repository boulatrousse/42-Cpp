/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toChar.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osterger <osterger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 03:41:47 by osterger          #+#    #+#             */
/*   Updated: 2023/11/04 04:46:13 by osterger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

static int checkPseudoLiterals(std::string &str);
static int checkZero(std::string &str);
static int checkAscii(std::string &str);

void    toChar(std::string &str)
{ 
    if (checkPseudoLiterals(str) != SUCCESS)
        return ;
    if (checkZero(str) != SUCCESS)
        return ;
    if (checkAscii(str) != SUCCESS)
        return ;
}

static int checkPseudoLiterals(std::string &str)
{
    if (str == "nan" || str == "nanf" || str == "-inf" || \
        str == "-inff" || str == "inf" || str == "+inf" || str == "inff" || str == "+inff")
    {
        std::cout << "char: impossible" << std::endl;
        return (FAILURE);
    }
    return (SUCCESS);
}

static int checkAscii(std::string &str)
{
    int     i = std::atoi(str.data());
    int     j = str[0];
    char    c;

    if (i != 0)
    {
        if (i >= 32 && i < 127)
            std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
        else
        {
            std::cout << "char: non displayable" << std::endl;
            return (FAILURE);
        }
    }
    
    if ((j >= 32 && j < '0') || (j > '9' && j < 127))
    {
        c = j;
        std::cout << "char: '" << c << "'" << std::endl;
        return (FAILURE);
    }
    else if (j == 48)
        std::cout << "char: non displayable" << std::endl;

    return (SUCCESS);
}

static int checkZero(std::string &str)
{
    if (str == "+0" || str == "-0")
    {
        std::cout << "char: non displayable" << std::endl;
        return (FAILURE);
    }
    return (SUCCESS);
}