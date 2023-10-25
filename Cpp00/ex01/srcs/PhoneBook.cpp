/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 12:28:03 by lboulatr          #+#    #+#             */
/*   Updated: 2023/08/21 10:04:41 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iomanip>

PhoneBook::PhoneBook(void)
{
    this->index = 0;
    return ;
}

PhoneBook::~PhoneBook(void)
{
    return ;
}

void PhoneBook::add(void)
{
    if (this->index > MAX_CONTACT - 1)
        this->index = 0;

    std::string     input = "";

    while (input == "" && !std::cin.eof())
    {
        std::cout << "Enter the first name :" << std::endl;
        std::getline(std::cin, input);
        if (check_input(input) != SUCCESS)
            input = "";   
    }
    this->_contact[this->index].setName(input);
    input = "";

    while (input == "" && !std::cin.eof())
    {
        std::cout << "Enter the last name :" << std::endl;
        std::getline(std::cin, input);
        if (check_input(input) != SUCCESS)
            input = "";
    }   
    this->_contact[this->index].setLastName(input);
    input = "";
    
    while (input == "" && !std::cin.eof())
    {
        std::cout << "Enter the nick name :" << std::endl;
        std::getline(std::cin, input);
        if (check_input(input) != SUCCESS)
            input = "";
    }   
    this->_contact[this->index].setNickName(input);
    input = "";
    
    while (input == "" && !std::cin.eof())
    {
        std::cout << "Enter the phone number :" << std::endl;
        std::getline(std::cin, input);
        if (check_input(input) != SUCCESS)
            input = "";
    }   
    this->_contact[this->index].setPhoneNumber(input);
    input = "";
    
    while (input == "" && !std::cin.eof())
    {
        std::cout << "Enter the darkest secret :" << std::endl;
        std::getline(std::cin, input);
        if (check_input(input) != SUCCESS)
            input = "";
    }   
    this->_contact[this->index].setDarkestSecret(input);
    
    this->index++;

    return ;
}

void PhoneBook::search(void)
{
    int     i;
    int     n_contact;

    i = 0;
    display();
   
    while (i < MAX_CONTACT)
    {
        std::cout << std::right << std::setw(10) << i + 1 << "|";
        truncate(this->_contact[i].getName());
        truncate(this->_contact[i].getLastName());
        truncate(this->_contact[i].getNickName());
        std::cout << std::endl;
        i++;
    }

    std::cout << "\nPlease choose a contact to display :" << std::endl;
    std::cin >> n_contact;
    std::cin.ignore();
    if (!std::cin)
    {
        std::cin.clear();
        std::cin.ignore();
    }
    if (n_contact <= 0 || n_contact > MAX_CONTACT)
    {
        std::cout << "Error. This number is not valid." << std::endl;
        std::cin.ignore();
        return ;
    }

    displayOneContact(n_contact - 1);
    
    return ;    
}

void PhoneBook::displayOneContact(int index)
{
    std::cout << "Name : " << this->_contact[index].getName() << std::endl;
    std::cout << "Last name : " << this->_contact[index].getLastName() << std::endl;
    std::cout << "Nick name : " << this->_contact[index].getNickName() << std::endl;
    std::cout << "Phone number : " << this->_contact[index].getPhoneNumber() << std::endl;
    std::cout << "Darkest secret : " << this->_contact[index].getDarkestSecret() << std::endl;
    
    return ;
}
