/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 13:34:19 by lboulatr          #+#    #+#             */
/*   Updated: 2023/09/04 11:07:38 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <stdexcept>

class Bureaucrat
{
    public:

        Bureaucrat(void);
        Bureaucrat(std::string const name, int grade);
        Bureaucrat(Bureaucrat const &src);
        ~Bureaucrat(void);

        Bureaucrat &operator=(Bureaucrat const &src);

        std::string const               getName(void) const;
        int                             getGrade(void) const;
        void                            incrementGrade(void);
        void                            decrementGrade(void);

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

    private:
    
        std::string const               _name;
        int                             _grade;

};

void operator<<(std::ostream &ostream, Bureaucrat const &src);

#endif