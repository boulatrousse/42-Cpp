/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 14:25:22 by osterger          #+#    #+#             */
/*   Updated: 2023/08/31 11:35:57 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"

# define N_SURROUND 8

class Character : public ICharacter
{
    public:

        Character(void);
        Character(const std::string &name);
        Character(const Character &src);
        ~Character(void);

        Character       &operator=(const Character &src);

        const                   std::string &getName() const;
        void                    equip(AMateria *m);
        void                    unequip(int idx);
        void                    use(int idx, ICharacter &target);

    private:
        
        std::string             _name;
        AMateria                *_inventory[N_MATERIAS];
        AMateria                *_surround[N_SURROUND];

};

//void handleSurroundings(Character *c, int idx);

#endif