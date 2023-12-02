/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osterger <osterger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 08:00:21 by osterger          #+#    #+#             */
/*   Updated: 2023/12/02 12:11:45 by osterger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(void)
{
    this->_arg = "";
    this->_status = SUCCESS;

    return ;
}

RPN::RPN(std::string arg)
{
    this->_arg = arg;
    this->_status = SUCCESS;

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
    this->_arg = src._arg;
    this->_status = src._status;
    this->_stack = src._stack;

    return (*this);
}

bool RPN::checkArg(std::string arg)
{
    if (!isdigit(arg[0]))
        return (false);

    for (size_t i = 0; i < arg.size(); i++)
    {
        if (arg[i] == ' ')
            continue ;
        else if (strchr("1234567890+-/*", arg[i]) == NULL)
            return (false);
        else if ((i + 1 < arg.size()) && (arg[i + 1] != ' '))
            return (false);
    }
    return (true);
}

bool    RPN::operations(void)
{
    int         tmp = 0;

    for (size_t i = 0; i < _arg.size(); i++)
    {
        if (_arg[i] == ' ')
            continue ;
        else if (isdigit(_arg[i]))
        {
            tmp = _arg[i] - 48;
            this->_stack.push(tmp);
        }
        else if (_arg[i] == '+')
            addition();
        else if (_arg[i] == '-')
            subtraction();
        else if (_arg[i] == '*')
            multiplication();
        else if (_arg[i] == '/')
            division();

        if (this->_status == FAILURE)
            return (false);

    }
    std::cout << "Final result = " << this->_stack.top() << std::endl;

    return (true);
}

void RPN::addition()
{
    int     x;
    int     y;

    x = this->_stack.top();
    this->_stack.pop();
    if (this->_stack.size() == 0)
    {
        this->_status = FAILURE;
        return ;
    }
    y = this->_stack.top();

    this->_stack.pop();
    this->_stack.push(x + y);
}

void RPN::subtraction()
{
    int     x;
    int     y;

    x = this->_stack.top();
    this->_stack.pop();
    if (this->_stack.size() == 0)
    {
        this->_status = FAILURE;
        return ;
    }
    y = this->_stack.top();

    this->_stack.pop();
    this->_stack.push(y - x);
}

void RPN::multiplication()
{
    int     x;
    int     y;

    x = this->_stack.top();
    this->_stack.pop();
    if (this->_stack.size() == 0)
    {
        this->_status = FAILURE;
        return ;
    }
    y = this->_stack.top();

    this->_stack.pop();
    this->_stack.push(x * y);
}

void RPN::division()
{
    int     x;
    int     y;

    x = this->_stack.top();
    this->_stack.pop();
    if (this->_stack.size() == 0)
    {
        this->_status = FAILURE;
        return ;
    }
    y = this->_stack.top();

    this->_stack.pop();
    this->_stack.push(y / x);
}