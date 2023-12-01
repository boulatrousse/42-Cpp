/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 03:39:54 by osterger          #+#    #+#             */
/*   Updated: 2023/11/08 15:38:07 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_HPP
# define CONVERT_HPP

# include <iostream>
# include <string>
# include <cstdlib>
# include <limits.h>

# define SUCCESS    EXIT_SUCCESS
# define FAILURE    EXIT_FAILURE

void    toChar(std::string &str);
void    toInt(std::string &str);
void    toFloat(std::string &str);
void    toDouble(std::string &str);

#endif