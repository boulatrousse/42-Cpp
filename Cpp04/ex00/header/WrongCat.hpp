/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 15:15:48 by lboulatr          #+#    #+#             */
/*   Updated: 2023/08/04 12:59:49 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
    public:
    
        WrongCat(void);
        WrongCat(std::string type);
        WrongCat(const WrongCat &src);
        ~WrongCat(void);
        
        WrongCat             &operator=(const WrongCat &src);
        void                makeSound() const;
        std::string         getType() const;
        
};

#endif