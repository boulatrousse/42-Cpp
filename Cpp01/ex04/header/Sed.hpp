/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 13:15:25 by lboulatr          #+#    #+#             */
/*   Updated: 2023/08/21 12:20:29 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SED_HPP
# define SED_HPP

# include <iostream>
# include <string>
# include <fstream>

# define SUCCESS        0
# define FAILURE        1
# define MAX_SIZE_T     65535

void                    sed_manager(char **argv);
std::string             getString(const char *filename);
std::string             replace(std::string one_string, std::string s1, std::string s2);
std::string             getFilename(char *str);
int                     check(std::string str, std::string s1);
int                     getCount(const char *filename);


#endif