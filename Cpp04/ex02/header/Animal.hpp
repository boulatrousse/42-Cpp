/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 14:49:26 by lboulatr          #+#    #+#             */
/*   Updated: 2023/08/15 08:58:26 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class Animal
{
    public:

        Animal(void);
        Animal(std::string type);
        Animal(const Animal &src);
        virtual ~Animal(void);
        
        Animal                  &operator=(const Animal &src);
        virtual void            makeSound(void) const = 0;
        virtual std::string     getType(void) const;

    protected:

        std::string     type;
        
};

#endif