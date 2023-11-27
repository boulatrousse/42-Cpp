/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 13:15:29 by lboulatr          #+#    #+#             */
/*   Updated: 2023/09/04 14:20:33 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "Form.hpp"

class RobotomyRequestForm : public Form
{
    public:

        RobotomyRequestForm(std::string const target);
        RobotomyRequestForm(RobotomyRequestForm const &src);
        ~RobotomyRequestForm(void);

        RobotomyRequestForm &operator=(RobotomyRequestForm const &src);

        void                                    execute(Bureaucrat const &executor) const;

        private:
        
        RobotomyRequestForm(void);
        
        std::string const                       _target;

};

#endif