/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 13:25:47 by lboulatr          #+#    #+#             */
/*   Updated: 2023/09/04 16:10:20 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) :
    Form("Robotomy Request Form", 72, 45)
{    
    return ;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const target) :
    Form("Robotomy Request Form", 72, 45), _target(target)
{
    return ;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src) :
    Form("Robotomy Request Form", 72, 45), _target(src._target)
{
    return ;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
    return ;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &src)
{
    (void)src;

    return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    static int count;
    
    if (executor.getGrade() > this->getGradeToExecute())
        throw Form::GradeTooLowException();
    else if (this->getSigned() == false)
        throw Form::NotSignedException();
        
    std::cout << "Drrrrrrrrrrrzzzzzzzzzzzzz" << std::endl;

    if ((count % 2) == 0)
        std::cout << this->_target << " has been robotomized successfully" << std::endl;
    else
        std::cout << this->_target << " has not been robotomized" << std::endl;
    
    count++;

    return ;
}