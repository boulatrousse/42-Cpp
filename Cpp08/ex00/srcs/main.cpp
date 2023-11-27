/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osterger <osterger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 13:26:20 by lboulatr          #+#    #+#             */
/*   Updated: 2023/11/04 05:11:50 by osterger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#define MAX 10

int main()
{
    std::vector<int> v;

    for (int i = 0; i < MAX; i++)
        v.push_back(i + 10);

    easyfind(v, 15);
    easyfind(v, -999);

    v.push_back(-999);
    v.push_back(999);

    easyfind(v, -999);

    return (0);
}
