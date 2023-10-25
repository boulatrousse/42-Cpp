/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 15:15:48 by lboulatr          #+#    #+#             */
/*   Updated: 2023/08/04 12:57:59 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

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
        
};

#endif