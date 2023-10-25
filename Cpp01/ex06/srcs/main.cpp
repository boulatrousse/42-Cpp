/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 09:54:05 by lboulatr          #+#    #+#             */
/*   Updated: 2023/08/21 11:06:38 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv)
{    
    if (argc != 2)
    {
        std::cout << "Wrong number of arguments." << std::endl;
        return (1);
    }
    
    Harl                TrueHarl;
    std::string         level(argv[1]);

    TrueHarl.complain(level);

    return (0);
}

