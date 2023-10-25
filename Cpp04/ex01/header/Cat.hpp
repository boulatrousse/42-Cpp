/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 15:15:48 by lboulatr          #+#    #+#             */
/*   Updated: 2023/08/31 09:24:59 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
    public:
    
        Cat(void);
        Cat(std::string type);
        Cat(const Cat &src);
        ~Cat(void);
        
        Cat             &operator=(const Cat &src);
        void            makeSound() const;
        std::string     getType() const;
        Brain           *getBrain() const;

    private:

        Brain           *_brain;
        
};

#endif