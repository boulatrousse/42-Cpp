/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osterger <osterger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 14:26:01 by lboulatr          #+#    #+#             */
/*   Updated: 2023/08/23 16:13:23 by osterger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice : public AMateria
{
    public:

        Ice(void);
        Ice(const Ice &src);
        ~Ice(void);

        Ice             &operator=(const Ice &src);
        
        AMateria        *clone() const;
        void            use(ICharacter &target);

};

#endif