/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 14:01:13 by lboulatr          #+#    #+#             */
/*   Updated: 2023/08/31 11:35:52 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>

# define N_MATERIAS 4

class ICharacter;

class AMateria
{
    public:

        AMateria(void);
        AMateria(const AMateria &src);
        AMateria(std::string const &type);
        virtual ~AMateria(void);

        AMateria                &operator=(const AMateria &src);

        std::string const       &getType() const;
        virtual AMateria        *clone() const = 0;
        virtual void            use(ICharacter &target);
    
    protected:

        std::string             _type;
};

#endif