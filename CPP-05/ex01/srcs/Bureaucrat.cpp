/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 13:40:44 by lboulatr          #+#    #+#             */
/*   Updated: 2023/09/02 13:28:30 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("Winston Smith")
{
    this->_grade = 150;
    
    return ;
}
Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    else
        this->_grade = grade;

    return ;
}

Bureaucrat::Bureaucrat(Bureaucrat const & src)
{
    *this = src;

    return ;
}

Bureaucrat::~Bureaucrat(void)
{
    return ;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &src)
{
    this->_grade = src.getGrade();

    return (*this);
}

std::string const Bureaucrat::getName(void) const
{
    return (this->_name);
}

int Bureaucrat::getGrade(void) const
{
    return (this->_grade);
}

void Bureaucrat::incrementGrade(void)
{
    if (this->_grade == 1)
        throw Bureaucrat::GradeTooHighException();
    else
        this->_grade--;

    return ;
}

void Bureaucrat::decrementGrade(void)
{
    if (this->_grade == 150)
        throw Bureaucrat::GradeTooLowException();
    else
        this->_grade++;

    return ;
}

void Bureaucrat::signForm(Form &form) const
{
    if (form.getSigned() == true)
    {
        std::cout << this->_name << " couldn't sign " << form.getName() << " because ";
        throw Form::FormAlreadySignedException();
    }
    form.beSigned(*this);
            
    return ;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Grade of the Bureaucrat is too high.\n");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Grade of the Bureaucrat is too low.\n");
}

std::ostream &operator<<(std::ostream &ostream, Bureaucrat const &src)
{
    ostream << src.getName() << ", bureaucrat grade " << src.getGrade() << std::endl;

    return (ostream);
}