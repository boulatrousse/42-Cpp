/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 16:32:41 by lboulatr          #+#    #+#             */
/*   Updated: 2023/09/05 08:47:26 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void)
{
    return ;
}

Intern::Intern(Intern const &src)
{
    *this = src;

    return ;
}

Intern::~Intern(void)
{
    return ;
}

Intern &Intern::operator=(Intern const &src)
{
    (void)src;

    return (*this);
}

Form *Intern::makeForm(std::string const formName, std::string const target)
{
    Form        *formTmp;
    int         index;
    
    index = -1;
    std::string     levels[3] =
    {
        "robotomy request",
        "presidential pardon",
        "shrubbery creation",
    };
    
    for(int i = 0; i < 3; i++)
    {
        if (levels[i] == formName)
        {
            std::cout << "Intern creates " << formName << std::endl;
            index = i;
            break ;
        }
    }

    switch (index)
    {
        case 0:
            formTmp = new RobotomyRequestForm(target);
            break ;
        case 1:
            formTmp = new PresidentialPardonForm(target);
            break ;
        case 2:
            formTmp = new ShrubberyCreationForm(target);
            break ;
        default:
            throw Intern::FormNotFoundException();
    }
    
    return (formTmp);
}

const char *Intern::FormNotFoundException::what() const throw()
{
    return ("Form not found");
}