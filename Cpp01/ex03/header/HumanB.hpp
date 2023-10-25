/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 12:31:20 by lboulatr          #+#    #+#             */
/*   Updated: 2023/07/19 13:07:34 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

class HumanB
{
    public:

        HumanB(std::string name);
        ~HumanB(void);
        
        void attack(void);
        void setWeapon(Weapon& weapon);

    private:

        Weapon*         _weapon;
        std::string     _name;
};

#endif
