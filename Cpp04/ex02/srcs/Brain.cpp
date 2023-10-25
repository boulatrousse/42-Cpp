/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 10:46:13 by lboulatr          #+#    #+#             */
/*   Updated: 2023/08/05 11:11:33 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
    std::cout << "Default Brain constructor called." << std::endl;

    return ;
}

Brain::Brain(const Brain &src)
{
    std::cout << "Copy Brain constructor called." << std::endl;
    *this = src;

    return ;
}

Brain::~Brain(void)
{
    std::cout << "Destructor Brain called." << std::endl;

    return ;
}

Brain &Brain::operator=(Brain const &src)
{
    std::cout << "Copy assignment Brain operator called." << std::endl;
    
    for (int i = 0; i < N_IDEAS; i++)
    {
        this->_ideas[i] = src._ideas[i];
    }
    
    return (*this);
}