/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:25:40 by lboulatr          #+#    #+#             */
/*   Updated: 2023/12/01 10:45:45 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

static int randomInt(void);

int main()
{
    Span sp = Span(5);

    try
    {
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    
    std::cout << "Test for shortestSpan = " << sp.shortestSpan() << std::endl;
    std::cout << "Test for longestSpan  = " << sp.longestSpan() << std::endl;

    Span sp0 = Span(0);
    Span sp1 = Span(1);
    Span sp2 = Span(3);

    std::cout << "Test for an empty Span0: ";
    try
    {
        sp0.shortestSpan();
    }
        catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "Test for Span1 with only one int: ";
    try
    {
        sp1.addNumber(1);
        sp1.shortestSpan();
    }
        catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "Test for Span2, span is full: " << std::endl;
    try
    {
        sp2.addNumber(1);
        std::cout << "number 1 has been added to Span2" << std::endl;
        sp2.addNumber(2);
        std::cout << "number 2 has been added to Span2" << std::endl;
        sp2.addNumber(3);
        std::cout << "number 3 has been added to Span2" << std::endl;
        sp2.addNumber(4);
        std::cout << "number 4 has been added to Span2" << std::endl;
        sp2.addNumber(5);
        std::cout << "number 5 has been added to Span2" << std::endl;
    }
        catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    Span largeSpan = Span(25000);
    
    std::vector<int> tmp_vector;
    int x = 0;
    
    for (int i = 0; i < 25000; i++)
    {
        x += randomInt();
        tmp_vector.push_back(x);   
    }

    std::vector<int>::iterator tmp_beg = tmp_vector.begin();
    std::vector<int>::iterator tmp_end = tmp_vector.end();

    std::cout << "Size of largeSpan = before addMultipleNumbers = " << largeSpan.sizeSpan() << std::endl;
    largeSpan.addMultipleNumbers(tmp_beg, tmp_end);
    std::cout << "Size of largeSpan after addMultipleNumbers = " << largeSpan.sizeSpan() << std::endl;
    std::cout << "Shortest span of largSpan = " << largeSpan.shortestSpan() << std::endl;
    std::cout << "Longest span of largSpan = " << largeSpan.longestSpan() << std::endl;

    return 0;
}

static int randomInt(void)
{
    srand(time(NULL));

    int i = rand() % 50;
    return (i);
}