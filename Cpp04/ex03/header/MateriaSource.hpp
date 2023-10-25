/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osterger <osterger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 15:35:53 by osterger          #+#    #+#             */
/*   Updated: 2023/08/23 15:45:42 by osterger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
    public:

    	MateriaSource(void);
	    MateriaSource(const MateriaSource &src);
	    ~MateriaSource(void);
	
	    MateriaSource       &operator=(const MateriaSource &src);

        void                learnMateria(AMateria *m);
        AMateria            *createMateria(const std::string &type);

    private:

        AMateria            *_inventory[N_MATERIAS];

};

#endif