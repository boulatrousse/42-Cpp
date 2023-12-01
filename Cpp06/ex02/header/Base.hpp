/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:41:43 by lboulatr          #+#    #+#             */
/*   Updated: 2023/10/10 14:03:00 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

# include <iostream>
# include <stdlib.h>

class Base
{
    public:
        virtual ~Base(void) {};
};

class A : public Base
{
    public:

        A(void) {};
        ~A(void) {};
};

class B : public Base
{
    public:

        B(void) {};
        ~B(void) {};
};

class C : public Base
{
    public:

        C(void) {};
        ~C(void) {};
};

Base    *generate(void);
void    identify(Base* p);
void    identify(Base& p);

#endif