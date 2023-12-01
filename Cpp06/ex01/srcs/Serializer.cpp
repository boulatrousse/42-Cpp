/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osterger <osterger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 09:50:42 by osterger          #+#    #+#             */
/*   Updated: 2023/09/13 10:05:07 by osterger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer(void)
{
    return ;
}

Serializer::Serializer(Serializer const &src)
{
    (void)src;
    
    return ;
}

Serializer::~Serializer(void)
{
    return ;
}

Serializer &Serializer::operator=(Serializer const &src)
{
    (void)src;

    return (*this);
}

uintptr_t Serializer::serialize(Data *ptr)
{
    return (reinterpret_cast<uintptr_t>(ptr));
}

Data *Serializer::deserialize(uintptr_t raw)
{
    return (reinterpret_cast<Data *>(raw));
}