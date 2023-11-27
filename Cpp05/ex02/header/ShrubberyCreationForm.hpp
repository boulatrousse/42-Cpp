/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 14:03:11 by lboulatr          #+#    #+#             */
/*   Updated: 2023/11/03 10:53:37 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
    public:

        ShrubberyCreationForm(std::string const target);
        ShrubberyCreationForm(ShrubberyCreationForm const &src);
        ~ShrubberyCreationForm(void);

        ShrubberyCreationForm &operator=(ShrubberyCreationForm const &src);

        void                                    execute(Bureaucrat const &executor) const;

        class FileNotOpenException : public std::exception
        {
            public:
                virtual const char              *what() const throw();
        };

    private:

        ShrubberyCreationForm(void);

        std::string const                       _target;
    
};

#endif