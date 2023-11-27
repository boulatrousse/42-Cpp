/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 13:49:45 by lboulatr          #+#    #+#             */
/*   Updated: 2023/09/04 16:12:09 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "Form.hpp"

class PresidentialPardonForm : public Form
{
    public:
    
        PresidentialPardonForm(std::string const target);
        PresidentialPardonForm(PresidentialPardonForm const &src);
        ~PresidentialPardonForm(void);

        PresidentialPardonForm &operator=(PresidentialPardonForm const &src);

        void                                    execute(Bureaucrat const &executor) const;

    private:
        
        PresidentialPardonForm(void);
        
        std::string const                       _target;

};

#endif