/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 12:28:01 by lboulatr          #+#    #+#             */
/*   Updated: 2023/08/04 14:07:38 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{
    return ;
}

Contact::~Contact(void)
{
    return ;
}

//-------------------------------------------------


std::string Contact::getName(void)
{
    return (this->_name);
}

std::string Contact::getLastName(void)
{
    return (this->_lastName);
}

std::string Contact::getNickName(void)
{
    return (this->_nickName);
}

std::string Contact::getPhoneNumber(void)
{
    return (this->_phoneNumber);
}

std::string Contact::getDarkestSecret(void)
{
    return (this->_darkestSecret);
}

//-------------------------------------------------


void Contact::setName(std::string str)
{
    this->_name = str;
}

void Contact::setLastName(std::string str)
{
    this->_lastName = str;
}

void Contact::setNickName(std::string str)
{
    this->_nickName = str;
}

void Contact::setPhoneNumber(std::string str)
{
    this->_phoneNumber = str;
}

void Contact::setDarkestSecret(std::string str)
{
    this->_darkestSecret = str;
}

