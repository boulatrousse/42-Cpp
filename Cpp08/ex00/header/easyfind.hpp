/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osterger <osterger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 13:26:35 by lboulatr          #+#    #+#             */
/*   Updated: 2023/11/04 05:10:44 by osterger         ###   ########.fr       */
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
    for (typename T::iterator it = ctn.begin(); it != ctn.end(); it++)
    {
        if (*it == i)
        {
            std::cout << "the parameter `i` was found : " << i << std::endl;
            return (SUCCESS);
        }
    }
    std::cout << "the parameter `i` was NOT found." << std::endl;
    return (FAILURE);
}

#endif