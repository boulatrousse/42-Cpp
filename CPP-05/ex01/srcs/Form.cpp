/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osterger <osterger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 10:09:10 by lboulatr          #+#    #+#             */
/*   Updated: 2023/11/04 03:40:29 by osterger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void) : _name("Basic Form"), 
    _signed(false), _gradeToSign(150), _gradeToExecute(150)
{
    return ;
}

Form::Form(std::string const name, int gradeToSign, int gradeToExecute) : 
    _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw Form::GradeTooHighException();
    else if (gradeToSign > 150 || gradeToExecute > 150)
        throw Form::GradeTooLowException();
    else
        this->_signed = false;

    return ;
}

Form::Form(Form const &src) : _name(src.getName()), 
    _gradeToSign(src.getGradeToSign()), _gradeToExecute(src.getGradeToExecute())
{
    *this = src;
    
    return ;
}

Form::~Form(void)
{
    return ;
}

Form &Form::operator=(Form const &src)
{
    this->_signed = src.getSigned();
    
    return (*this);
}

std::string const Form::getName(void) const
{
    return (this->_name);
}

bool Form::getSigned(void) const
{
    return (this->_signed);
}

int Form::getGradeToSign(void) const
{
    return (this->_gradeToSign);
}

int Form::getGradeToExecute(void) const
{
    return (this->_gradeToExecute);
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > this->_gradeToSign)
        throw Form::GradeTooLowException();
    else
        this->_signed = true;
            
    return ;
}

const char *Form::GradeTooHighException::what() const throw()
{
    return ("Form grade is too high");
}

const char *Form::GradeTooLowException::what() const throw()
{
    return ("Form grade is too low");
}

const char *Form::FormAlreadySignedException::what() const throw()
{
    return ("Form already signed");
}

std::ostream &operator<<(std::ostream &ostream, Form const &src)
{
    ostream << src.getName() << " form, grade to sign: " << src.getGradeToSign() 
        << ", grade to execute: " << src.getGradeToExecute() << ", signed: " 
        << src.getSigned() << std::endl;

    return (ostream);
}