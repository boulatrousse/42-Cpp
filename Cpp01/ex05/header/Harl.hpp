/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 09:54:36 by lboulatr          #+#    #+#             */
/*   Updated: 2023/07/23 09:58:39 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <string>

class Harl
{
    
    public:

        Harl(void);
        ~Harl(void);

        void complain(std::string level);

    private:

        void debug(void);
        void info(void);
        void warning(void);
        void error(void);

};

#endif