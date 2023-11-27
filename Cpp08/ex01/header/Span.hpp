/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osterger <osterger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:56:16 by lboulatr          #+#    #+#             */
/*   Updated: 2023/11/18 02:21:54 by osterger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <stdlib.h>
# include <limits.h>

class Span
{
    public:

        Span(unsigned int N);
        Span(Span const & src);
        ~Span(void);

        Span & operator=(Span const & rhs);

        void    addNumber(int n);
        int     shortestSpan(void);
        int     longestSpan(void);
        int     sizeSpan(void) const;
        void    addMultipleNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);
        void    displaySpan(void);

        class SpanIsFull : public std::exception
        {
            public:
                virtual const char      *what() const throw()
                {
                    return ("\033[1;31mSpan is full.\n\033[0m");
                };
        }; 

        class NoPossibleSpan : public std::exception
        {
            public:
                virtual const char      *what() const throw()
                {
                    return ("\033[1;31mNo span can be found.\033[0m");
                };
        }; 
        
    private:

        unsigned int            _N;
        std::vector<int>        _v;
        
};

#endif