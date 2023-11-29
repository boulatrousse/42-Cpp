/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osterger <osterger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 08:00:21 by osterger          #+#    #+#             */
/*   Updated: 2023/11/29 08:51:31 by osterger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(void)
{
    this->_validChars = "0123456789+-/* ";
    this->_arg = "";

    return ;
}

RPN::RPN(std::string arg)
{
    this->_validChars = "0123456789+-/* ";
    this->_arg = arg;

    return ;
}

RPN::RPN(RPN const &src)
{
    *this = src;

    return ;
}

RPN::~RPN(void)
{
    return ;
}

RPN &RPN::operator=(RPN const &src)
{
    this->_validChars = src._validChars;
    this->_arg = src._arg;
    this->_stack = src._stack;

    return (*this);
}

bool RPN::checkArg(std::string arg)
{
    int             tmp = 0;
    
    for (size_t i = 0; i < arg.size(); i++)
    {
        if (strchr(this->_validChars.data(), arg[i]) == NULL)
            return (false);
    }
    
    for (size_t i = 0; i < arg.size(); i++)
    {
        if (isdigit(arg[i]))
        {
            tmp = atoi(arg.data() + i);
            if (tmp < 0 || tmp >= 10)
                return (false);
        }
    }   
    return (true);
}