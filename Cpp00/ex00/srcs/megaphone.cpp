/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 09:52:02 by lboulatr          #+#    #+#             */
/*   Updated: 2023/08/21 15:39:40 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(int argc, char **argv)
{
    size_t              i;
    size_t              j;
    std::string         str;

    i = 1;
    j = 0;
    if (argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else
    {
        while (argv[i])
        {
            j = 0;
            str = argv[i];
            while (j < str.size())
            {
                str[j] = toupper(str[j]);
                std::cout << str[j];
                j++;
            }
            i++;
        }
        std::cout << std::endl;
    }
    
    return (0);
}

