/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 13:10:50 by lboulatr          #+#    #+#             */
/*   Updated: 2023/08/21 11:14:49 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

    // recoder replace
    // append

#include "Sed.hpp"
#include <stdio.h>

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cout << "Wrong number of arguments." << std::endl;
        return (FAILURE);
    }
    else
        sed_manager(argv);
        
    return (SUCCESS);
}
