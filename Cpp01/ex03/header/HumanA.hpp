/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 08:12:41 by lboulatr          #+#    #+#             */
/*   Updated: 2023/08/05 10:17:06 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"

class HumanA
{
    public:

        HumanA(std::string name, Weapon& weapon);
        ~HumanA(void);
        
        void            attack(void);
        
    private:

        std::string     _name;
        Weapon&         _weapon;
};

#endif