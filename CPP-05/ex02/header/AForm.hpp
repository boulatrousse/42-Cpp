/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 10:02:55 by lboulatr          #+#    #+#             */
/*   Updated: 2023/11/03 10:52:54 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <fstream>
# include <stdexcept>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    public:

        AForm(void);
        AForm(std::string const name, int gradeToSign, int gradeToExecute);
        AForm(AForm const &src);
        virtual ~AForm(void) = 0;

        AForm &operator=(AForm const &src);

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

        class AFormAlreadySignedException : public std::exception
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

std::ostream &operator<<(std::ostream &ostream, AForm const &src);

#endif