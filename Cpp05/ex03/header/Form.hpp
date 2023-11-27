/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 10:02:55 by lboulatr          #+#    #+#             */
/*   Updated: 2023/09/04 16:34:34 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <fstream>
# include <stdexcept>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    public:

        Form(void);
        Form(std::string const name, int gradeToSign, int gradeToExecute);
        Form(Form const &src);
        virtual ~Form(void) = 0;

        Form &operator=(Form const &src);

        virtual std::string             getName(void) const;
        virtual bool                    getSigned(void) const;
        virtual int                     getGradeToSign(void) const;
        virtual int                     getGradeToExecute(void) const;
        virtual void                    beSigned(const Bureaucrat &bureaucrat);
        virtual void                    execute(Bureaucrat const &executor) const;
        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char      *what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char      *what() const throw();
        };

        class FormAlreadySignedException : public std::exception
        {
            public:
                virtual const char      *what() const throw();
        };

        class NotSignedException : public std::exception
        {
            public:
                virtual const char      *what() const throw();
        };

    private:

        std::string const               _name;
        bool                            _signed;
        int const                       _gradeToSign;
        int const                       _gradeToExecute;
};

std::ostream &operator<<(std::ostream &ostream, Form const &src);

#endif