/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 13:26:35 by lboulatr          #+#    #+#             */
/*   Updated: 2023/12/01 10:24:06 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <algorithm>
# include <vector>
# define SUCCESS EXIT_SUCCESS
# define FAILURE EXIT_FAILURE

template<typename T>
int    easyfind(T &ctn, int i)
{
    typename T::iterator it = std::find(ctn.begin(), ctn.end(), i);

    if (it != ctn.end())
    {
        std::cout << "\033[1;32m";
        std::cout << "The parameter `i` " << i << " was found !" << std::endl;
        std::cout << "\033[0m";
        
        return (SUCCESS);
    }
    std::cout << "\033[1;31m";
    std::cout << "The parameter `i` " << i << " was NOT found ." << std::endl;
    std::cout << "\033[0m";
    
    return (FAILURE);
}

#endif