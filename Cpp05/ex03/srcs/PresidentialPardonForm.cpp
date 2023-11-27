/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 13:51:27 by lboulatr          #+#    #+#             */
/*   Updated: 2023/09/04 16:10:11 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) :
    Form("Presidential Pardon Form", 25, 5)
{
    return ;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const target) :
    Form("Presidential Pardon Form", 25, 5), _target(target)
{
    return ;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src) :
    Form("Presidential Pardon Form", 25, 5), _target(src._target)
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
        throw Form::GradeTooLowException();
    else if (this->getSigned() == false)
        throw Form::NotSignedException();
    else
        std::cout << this->_target << " has been pardoned by Zafod Beeblebrox." << std::endl;
    

    return ;
}
