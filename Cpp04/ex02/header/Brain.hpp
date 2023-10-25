/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 12:39:57 by lboulatr          #+#    #+#             */
/*   Updated: 2023/08/05 11:06:08 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>

# define N_IDEAS    100

class Brain
{
    public:
    
        Brain(void);
        Brain(const Brain &src);
        ~Brain(void);
        
        Brain               &operator=(const Brain &src);
    
    private:
    
        std::string         _ideas[N_IDEAS];
};

#endif