/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 10:02:55 by lboulatr          #+#    #+#             */
/*   Updated: 2023/09/02 12:58:40 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <stdexcept>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    public:

        Form(void);
        Form(std::string const name, int gradeToSign, int gradeToExecute);
        Form(Form const &src);
        ~Form(void);

        Form &operator=(Form const &src);

        std::string const               getName(void) const;
        bool                            getSigned(void) const;
        int                             getGradeToSign(void) const;
        int                             getGradeToExecute(void) const;
        void                            beSigned(const Bureaucrat &bureaucrat);

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

    private:

        std::string const               _name;
        bool                            _signed;
        int const                       _gradeToSign;
        int const                       _gradeToExecute;
};

std::ostream &operator<<(std::ostream &ostream, Form const &src);

#endif