/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 13:33:58 by lboulatr          #+#    #+#             */
/*   Updated: 2023/11/03 10:53:01 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    Bureaucrat              *bureaucrat = new Bureaucrat("Stockton", 1);
    ShrubberyCreationForm   form("garden");
    RobotomyRequestForm     robot("Bender");
    PresidentialPardonForm  pardon("Osterger");

    try
    {
        bureaucrat->signForm(form);
        form.execute(*bureaucrat);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        bureaucrat->signForm(robot);
        robot.execute(*bureaucrat);
        robot.execute(*bureaucrat);
        robot.execute(*bureaucrat);
        robot.execute(*bureaucrat);
        robot.execute(*bureaucrat);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        bureaucrat->signForm(robot);
        pardon.execute(*bureaucrat);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        bureaucrat->signForm(pardon);
        bureaucrat->executeForm(pardon);
        bureaucrat->executeForm(pardon);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    delete bureaucrat;

    return (0);
}