/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 15:21:08 by lboulatr          #+#    #+#             */
/*   Updated: 2023/08/31 09:30:05 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
    public:
    
        Dog(void);
        Dog(std::string type);
        Dog(const Dog &src);
        ~Dog(void);
        
        Dog             &operator=(const Dog &src);
        void            makeSound() const;
        std::string     getType() const;
        Brain           *getBrain() const;
        
    private:

        Brain           *_brain;
};