/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 08:03:12 by lboulatr          #+#    #+#             */
/*   Updated: 2023/08/05 10:17:37 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>
# include <string>

class Weapon
{
    public:

        Weapon(void);
        Weapon(std::string type);
        ~Weapon(void);

        std::string const&  getType(void) const;
        void                setType(std::string new_type);
        
    private:

        std::string         _type;
    
};


#endif