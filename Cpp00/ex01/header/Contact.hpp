/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 12:27:57 by lboulatr          #+#    #+#             */
/*   Updated: 2023/08/04 14:05:52 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>

class Contact
{
    public:
        
        Contact(void);
        ~Contact(void);

        std::string     getName(void);
        std::string     getLastName(void);
        std::string     getNickName(void);
        std::string     getPhoneNumber(void);
        std::string     getDarkestSecret(void);

        void            setName(std::string str);
        void            setLastName(std::string str);
        void            setNickName(std::string str);
        void            setPhoneNumber(std::string str);
        void            setDarkestSecret(std::string str);
        
    private:
    
        std::string     _name;
        std::string     _lastName;
        std::string     _nickName;
        std::string     _phoneNumber;
        std::string     _darkestSecret;
        
};

#endif