/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 13:49:45 by lboulatr          #+#    #+#             */
/*   Updated: 2023/11/03 10:53:33 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm
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