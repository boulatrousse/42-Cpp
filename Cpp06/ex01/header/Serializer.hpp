/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osterger <osterger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 09:48:44 by osterger          #+#    #+#             */
/*   Updated: 2023/11/18 01:59:36 by osterger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <stdint.h>
# include "Data.hpp"

class Serializer
{
    public:

        ~Serializer(void);

        Serializer      &operator=(Serializer const &src);

        static uintptr_t       serialize(Data *ptr);
        static Data            *deserialize(uintptr_t raw);

    private:

        Serializer(void);
        Serializer(Serializer const &src);
};

#endif