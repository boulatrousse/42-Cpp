/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osterger <osterger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 02:37:13 by osterger          #+#    #+#             */
/*   Updated: 2023/11/18 02:33:52 by osterger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>
# include <stdlib.h>

template <typename T>
class MutantStack : public std::stack<T>
{

    public:

        MutantStack(void) {};
        MutantStack(const MutantStack<T> &src) 
        { 
            *this = src; 
        }
        ~MutantStack(void) {};

        MutantStack &operator=(MutantStack const &src) 
        {
            if (this != &src)
                std::stack<T>::operator=(src);
            return (*this);
        }
        
        typedef typename std::stack<T>::container_type::iterator iterator;

        iterator begin()
        {
            return (this->c.begin());
        }

        iterator end()
        {
            return (this->c.end());
        }
};

#endif