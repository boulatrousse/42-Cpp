/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 08:57:43 by lboulatr          #+#    #+#             */
/*   Updated: 2023/08/24 07:57:54 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class ClapTrap
{
    public:

        ClapTrap(void);
        ClapTrap(std::string name);
        ClapTrap(const ClapTrap &src);
        ~ClapTrap(void);

        ClapTrap    &operator=(const ClapTrap &src);

        void                attack(const std::string &target);
        void                takeDamage(unsigned int amount);
        void                beRepaired(unsigned int amout);

        std::string         getName(void);

    protected:

        std::string         _name;
        int                 _hp;
        int                 _energyPoints;
        int                 _damage;
        
};

void        printDeath(ClapTrap *clap);
void        printNoEnergy(ClapTrap *clap);

#endif