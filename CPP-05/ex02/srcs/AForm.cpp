/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 10:09:10 by lboulatr          #+#    #+#             */
/*   Updated: 2023/11/03 10:51:53 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(void) : _name("Basic Form"), 
    _signed(false), _gradeToSign(150), _gradeToExecute(150)
{
    return ;
}

AForm::AForm(std::string const name, int gradeToSign, int gradeToExecute) : 
    _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw AForm::GradeTooHighException();
    else if (gradeToSign > 150 || gradeToExecute > 150)
        throw AForm::GradeTooLowException();
    else
        this->_signed = false;

    return ;
}

AForm::AForm(AForm const &src) : _name(src.getName()), 
    _gradeToSign(src.getGradeToSign()), _gradeToExecute(src.getGradeToExecute())
{
    *this = src;
    
    return ;
}

AForm::~AForm(void)
{
    return ;
}

AForm &AForm::operator=(AForm const &src)
{
    this->_signed = src.getSigned();
    
    return (*this);
}

std::string AForm::getName(void) const
{
    return (this->_name);
}

bool AForm::getSigned(void) const
{
    return (this->_signed);
}

int AForm::getGradeToSign(void) const
{
    return (this->_gradeToSign);
}

int AForm::getGradeToExecute(void) const
{
    return (this->_gradeToExecute);
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > this->_gradeToSign)
        throw Bureaucrat::GradeTooLowException();
    else
        this->_signed = true;
            
    return ;
}

void AForm::execute(Bureaucrat const &executor) const
{
    if (executor.getGrade() > this->getGradeToExecute())
        throw AForm::GradeTooLowException();
    else if (this->getSigned() == false)
        throw AForm::NotSignedException();
    else
        std::cout << executor.getName() << " executes " << this->getName() << std::endl;

    return ;
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return ("AForm grade is too high");
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return ("AForm grade is too low");
}

const char *AForm::AFormAlreadySignedException::what() const throw()
{
    return ("AForm already signed");
}

const char *AForm::NotSignedException::what() const throw()
{
    return ("AForm not signed");
}

std::ostream &operator<<(std::ostream &ostream, AForm const &src)
{
    ostream << src.getName() << " form, grade to sign: " << src.getGradeToSign() 
        << ", grade to execute: " << src.getGradeToExecute() << ", signed: " 
        << src.getSigned() << std::endl;

    return (ostream);
}