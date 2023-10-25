/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 10:05:53 by lboulatr          #+#    #+#             */
/*   Updated: 2023/07/17 11:09:46 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie
{
    public:

        Zombie(void);
        Zombie(std::string name);
        ~Zombie(void);
        
        void announce(void);
        void setName(std::string name);

    private:

        std::string _name;
    
};

Zombie* zombieHorde(int N, std::string name);

#endif