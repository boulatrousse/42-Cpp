/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 09:54:05 by lboulatr          #+#    #+#             */
/*   Updated: 2023/08/05 10:30:28 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(void)
{
    Harl TheTrueHarl;
    
    TheTrueHarl.complain("DEBUG");
    TheTrueHarl.complain("INFO");
    TheTrueHarl.complain("WARNING");
    TheTrueHarl.complain("ERROR");

    return (0);
}