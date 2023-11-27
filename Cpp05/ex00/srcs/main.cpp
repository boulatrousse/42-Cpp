/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 13:33:58 by lboulatr          #+#    #+#             */
/*   Updated: 2023/11/03 10:39:24 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    Bureaucrat *bureaucrat;

    try
    {
        bureaucrat = new Bureaucrat("Bureaucrat", 2);
        std::cout << "OK1" << std::endl;
        bureaucrat = new Bureaucrat("Bureaucrat", 0);
        std::cout << "OK1" << std::endl;
        bureaucrat = new Bureaucrat("Bureaucrat", 4);
        bureaucrat = new Bureaucrat("Bureaucrat", 5);
    }
    catch (std::exception &e)
    {
        delete bureaucrat;
        std::cout << e.what() << std::endl;
    }

    try
    {
        bureaucrat = new Bureaucrat("Bureaucrat", 150);
        std::cout << "OK2" << std::endl;
        bureaucrat = new Bureaucrat("Bureaucrat", 151);
        std::cout << "OK2" << std::endl;
    }
    catch (std::exception &e)
    {
        delete bureaucrat;
        std::cout << e.what() << std::endl;
    }

    try
    {
        Bureaucrat clement("Clement", 2);
        std::cout << clement;
        bureaucrat = new Bureaucrat("Bureaucrat", 1);
        std::cout << "OK3" << std::endl;
        bureaucrat->incrementGrade();
        std::cout << "OK3" << std::endl;
        std::cout << bureaucrat->getGrade() << std::endl;
        bureaucrat->incrementGrade();
        std::cout << bureaucrat->getGrade() << std::endl;
    }
    catch (std::exception &e)
    {
        delete bureaucrat;
        std::cout << e.what() << std::endl;
    }

    try
    {
        bureaucrat = new Bureaucrat("Bureaucrat", 150);
        std::cout << "OK4" << std::endl;
        bureaucrat->decrementGrade();
        std::cout << "OK4" << std::endl;
        std::cout << bureaucrat->getGrade() << std::endl;
        bureaucrat->decrementGrade();
        std::cout << bureaucrat->getGrade() << std::endl;
    }
    catch (std::exception &e)
    {
        delete bureaucrat;
        std::cout << e.what() << std::endl;
    }

    bureaucrat = new Bureaucrat("Cooper", 42);
    std::cout << *bureaucrat;

    delete bureaucrat;

    return (0);
}