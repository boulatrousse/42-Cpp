/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osterger <osterger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 07:57:39 by osterger          #+#    #+#             */
/*   Updated: 2023/11/29 08:34:17 by osterger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <string>
# include <stack>
# include <cstring>
# include <cstdlib>

# define SUCCESS 0
# define FAILURE 1

class RPN
{
    public:

        RPN(void);
        RPN(std::string arg);
        RPN(RPN const &src);
        ~RPN(void);

        RPN             &operator=(RPN const &src);

        bool            checkArg(std::string arg);

    private:

        std::string         _validChars;
        std::string         _arg;
        std::stack<int>     _stack;
        
};

#endif