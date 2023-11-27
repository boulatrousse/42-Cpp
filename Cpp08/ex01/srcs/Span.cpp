/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osterger <osterger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:56:10 by lboulatr          #+#    #+#             */
/*   Updated: 2023/11/18 02:21:50 by osterger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int N) : _N(N)
{
    return ;
}

Span::Span(Span const & src)
{
    *this = src;
    
    return ;
}

Span::~Span(void)
{
    return ;
}

Span & Span::operator=(Span const & rhs)
{
    if (this != &rhs)
    {
        this->_N = rhs._N;
    }
    
    return (*this);
}

void    Span::addNumber(int n)
{
    if (this->_N == this->_v.size())
        throw Span::SpanIsFull();
    this->_v.push_back(n);
}

int     Span::shortestSpan(void)
{
    int         shortest = INT_MAX;
    int         tmp = 0;

    if (this->_v.size() <= 1)
        throw Span::NoPossibleSpan();
    
    for (std::vector<int>::iterator it = this->_v.begin(); it != this->_v.end(); it++)
    {
        tmp = abs(*it - *(it + 1));
        if (tmp < shortest)
            shortest = tmp;
    }
    
    return (shortest);
}

int     Span::longestSpan(void)
{
    int         max = INT_MIN;
    int         min = INT_MAX;

    if (this->_v.size() <= 1)
        throw Span::NoPossibleSpan();

    for (std::vector<int>::iterator it = this->_v.begin(); it != this->_v.end(); it++)
    {
        if (*it > max)
            max = *it;
        if (*it < min)
            min = *it;
    }

    return (max - min);
}

int     Span::sizeSpan(void) const
{
    return (this->_v.size());
}

void    Span::addMultipleNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    if (this->_N < std::distance(begin, end))
        throw Span::SpanIsFull();
    this->_v.insert(this->_v.end(), begin, end);
}

void    Span::displaySpan(void)
{
    for (std::vector<int>::iterator it = this->_v.begin(); it != this->_v.end(); it++)
    {
        std::cout << *it << std::endl;
    }
}
