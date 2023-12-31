/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:56:10 by lboulatr          #+#    #+#             */
/*   Updated: 2023/12/12 11:04:39 by lboulatr         ###   ########.fr       */
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

Span & Span::operator=(Span const & src)
{
    if (this != &src)
    {
        this->_v.resize(src._v.size());
        std::copy(src._v.begin(), src._v.end(), this->_v.begin());
        this->_N = src._N;
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

    std::sort(this->_v.begin(), this->_v.end());

    for (size_t i = 1; i < this->_v.size(); i++)
    {
        tmp = abs(this->_v[i]) - abs(this->_v[i - 1]);
        if (tmp < shortest)
            shortest = tmp;
    }
    
    return (shortest);
}

int     Span::longestSpan(void)
{
    int         smallest = INT_MAX;
    int         longest;
    
    if (this->_v.size() <= 1)
        throw Span::NoPossibleSpan();
    
    smallest = *std::min_element(this->_v.begin(), this->_v.end());
    longest = *std::max_element(this->_v.begin(), this->_v.end());

    return (abs(longest) - abs(smallest));
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
