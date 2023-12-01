/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osterger <osterger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 02:58:30 by osterger          #+#    #+#             */
/*   Updated: 2023/11/18 01:51:38 by osterger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include "Convert.hpp"

class ScalarConverter
{
    public:

        ~ScalarConverter(void);

        ScalarConverter     &operator=(ScalarConverter const &src);

        static ScalarConverter      &getInstance();
        static void                 convert(std::string &str);

    private:

        ScalarConverter(void);
        ScalarConverter(ScalarConverter const &src);
};

#endif