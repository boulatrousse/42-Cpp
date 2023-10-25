/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 12:28:06 by lboulatr          #+#    #+#             */
/*   Updated: 2023/08/21 09:59:33 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include "Contact.hpp"
# include "utils.hpp"

# define SUCCESS        0
# define FAILURE        1
# define MAX_CONTACT    8

class PhoneBook
{
    public:

        int     index;

        PhoneBook(void);
        ~PhoneBook(void);
        
        void        add(void);
        void        search(void);
        void        displayOneContact(int index);
    
    private:
    
        Contact _contact[MAX_CONTACT];
    
};

#endif