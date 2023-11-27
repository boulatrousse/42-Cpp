/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 13:51:27 by lboulatr          #+#    #+#             */
/*   Updated: 2023/11/03 10:56:59 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) :
    AForm("Presidential Pardon Form", 25, 5)
{
    return ;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const target) :
    AForm("Presidential Pardon Form", 25, 5), _target(target)
{
    return ;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src) :
    AForm("Presidential Pardon Form", 25, 5), _target(src._target)
{
    *this = src;

    return ;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
    return ;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &src)
{
    (void)src;

    return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    if (executor.getGrade() > this->getGradeToExecute())
        throw AForm::GradeTooLowException();
    else if (this->getSigned() == false)
        throw AForm::NotSignedException();
    else
        std::cout << this->_target << " has been pardoned by Zafod Beeblebrox." << std::endl;
    

    return ;
}
