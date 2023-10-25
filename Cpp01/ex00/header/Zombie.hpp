/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 10:05:53 by lboulatr          #+#    #+#             */
/*   Updated: 2023/07/17 10:31:24 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie
{
    public:

        Zombie(std::string name);
        ~Zombie(void);
        
        void announce(void);

    private:

        std::string _name;
    
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif