/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 14:29:56 by lboulatr          #+#    #+#             */
/*   Updated: 2023/08/29 08:46:42 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class Cure : public AMateria
{
    public:
    
        Cure(void);
        Cure(const Cure &src);
        ~Cure(void);

        Cure             &operator=(const Cure &src);
        
        AMateria        *clone() const;
        void            use(ICharacter &target);

};

#endif