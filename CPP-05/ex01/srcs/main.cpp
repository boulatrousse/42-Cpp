/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 13:33:58 by lboulatr          #+#    #+#             */
/*   Updated: 2023/10/31 09:20:06 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    Bureaucrat      *bureaucrat;
    Form            *form;

    try
    {
        bureaucrat = new Bureaucrat("Bureaucrat", 2);
        std::cout << "OK1" << std::endl;
        bureaucrat = new Bureaucrat("Bureaucrat", 0);
        std::cout << "OK1" << std::endl;
        bureaucrat = new Bureaucrat("Bureaucrat", 4);
        bureaucrat = new Bureaucrat("Bureaucrat", 5);
        
        delete bureaucrat;
    }
    catch (std::exception &e)
    {
        delete bureaucrat;
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;

    try
    {
        bureaucrat = new Bureaucrat("Bureaucrat", 150);
        form = new Form("Form", 149, 149);
        std::cout << "OK2" << std::endl;
        bureaucrat->signForm(*form);
        std::cout << "OK2" << std::endl;
        bureaucrat->signForm(*form);
        
        delete bureaucrat;
        delete form;
        
    }
    catch (std::exception &e)
    {
        delete bureaucrat;
        delete form;
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;

    try
    {
        bureaucrat = new Bureaucrat("Bureaucrat", 150);
        form = new Form("Form", 149, 149);
        std::cout << bureaucrat->getGrade() << std::endl;
        bureaucrat->incrementGrade();
        std::cout << bureaucrat->getGrade() << std::endl;
        bureaucrat->signForm(*form);
        std::cout << "OK3" << std::endl;
        
        delete bureaucrat;
        delete form;

    }
    catch (std::exception &e)
    {
        delete bureaucrat;
        delete form;
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;

    try
    {
        bureaucrat = new Bureaucrat("Bureaucrat", 149);
        form = new Form("Form", 149, 149);
        std::cout << bureaucrat->getGrade() << std::endl;
        bureaucrat->incrementGrade();
        std::cout << bureaucrat->getGrade() << std::endl;
        bureaucrat->signForm(*form);
        std::cout << "OK4" << std::endl;
        
        delete bureaucrat;
        delete form;
    }
    catch (std::exception &e)
    {
        delete bureaucrat;
        delete form;
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;

    try
    {
        bureaucrat = new Bureaucrat("Bureaucrat", 149);
        form = new Form("Form", 100, 100);
        std::cout << bureaucrat->getGrade() << std::endl;
        bureaucrat->incrementGrade();
        std::cout << bureaucrat->getGrade() << std::endl;
        bureaucrat->signForm(*form);
        std::cout << "OK5" << std::endl;
        
        delete bureaucrat;
        delete form;
    }
    catch (std::exception &e)
    {
        delete bureaucrat;
        delete form;
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;

    try
    {
        bureaucrat = new Bureaucrat("Bureaucrat", 10);
        form = new Form("Form", 11, 11);
        std::cout << bureaucrat->getGrade() << std::endl;
        bureaucrat->signForm(*form);
        std::cout << "OK5" << std::endl;
        bureaucrat->signForm(*form);
        
        delete bureaucrat;
        delete form;
    }
    catch (std::exception &e)
    {
        delete bureaucrat;
        delete form;
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;

    return (0);
}