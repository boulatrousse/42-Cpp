/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 10:29:08 by lboulatr          #+#    #+#             */
/*   Updated: 2023/08/24 08:08:19 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"
# include <iostream>

class ScavTrap : public ClapTrap
{
    public:
    
        ScavTrap(void);
        ScavTrap(std::string name);
        ScavTrap(const ScavTrap &src);
        ~ScavTrap(void);

        ScavTrap    &operator=(const ScavTrap &src);

        void        attack(const std::string &target);
        void        guardGate();
    
};

void        printDeath(ScavTrap *scav);
void        printNoEnergy(ScavTrap *scav);

#endif