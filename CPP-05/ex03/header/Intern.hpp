/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 16:25:05 by lboulatr          #+#    #+#             */
/*   Updated: 2023/09/04 16:35:13 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "Form.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern 
{
    public:
    
        Intern(void);
        Intern(Intern const &src);
        ~Intern(void);

        Intern &operator=(Intern const &src);

        class FormNotFoundException : public std::exception
        {
            public:
                virtual const char      *what() const throw();
        };

        Form            *makeForm(std::string const formName, std::string const target);
        
};

#endif