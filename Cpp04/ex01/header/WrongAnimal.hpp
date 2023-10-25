/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 14:49:26 by lboulatr          #+#    #+#             */
/*   Updated: 2023/08/05 10:01:54 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
# include <string>

class WrongAnimal
{
    public:

        WrongAnimal(void);
        WrongAnimal(std::string type);
        WrongAnimal(const WrongAnimal &src);
        virtual ~WrongAnimal(void);
        
        WrongAnimal                  &operator=(const WrongAnimal &src);
        void                makeSound(void) const;
        virtual std::string         getType(void) const;

    protected:

        std::string     type;
        
};

#endif