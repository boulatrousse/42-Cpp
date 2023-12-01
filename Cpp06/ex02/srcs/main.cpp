/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:39:40 by lboulatr          #+#    #+#             */
/*   Updated: 2023/10/10 14:14:22 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main(void)
{
    Base *x = generate();
    Base &y = *x;

    std::cout << "Pointer: " << x << std::endl;

    identify(x);
    identify(y);

    return (0);
}