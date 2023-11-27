/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 07:52:00 by lboulatr          #+#    #+#             */
/*   Updated: 2023/11/03 10:56:29 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) :
    AForm("Shrubbery form", 145, 137)
{
    return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const target) :
    AForm("Shrubbery form", 145, 137), _target(target)
{
    return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src) :
    AForm("Shrubbery form", 145, 137), _target(src._target)
{
    return ;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
    return ;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &src)
{
    (void)src;

    return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    std::string         filename;
    std::ofstream       file;
    
    if (executor.getGrade() > this->getGradeToExecute())
        throw AForm::GradeTooLowException();
    else if (this->getSigned() == false)
        throw AForm::NotSignedException();
    else
    {
        filename = this->_target + "_shrubbery";
        file.open(filename.data());
        if (!file.is_open())
            throw ShrubberyCreationForm::FileNotOpenException();
        else
        {
            file << "                                               .\n";
            file << "                                      .         ;\n";  
            file << "         .              .              ;%     ;;\n";   
            file << "           ,           ,                :;%  %;\n";   
            file << "            :         ;                   :;%;'     .,\n";   
            file << "   ,.        %;     %;            ;        %;'    ,;\n";
            file << "     ;       ;%;  %%;        ,     %;    ;%;    ,%'\n";
            file << "      %;       %;%;      ,  ;       %;  ;%;   ,%;'\n"; 
            file << "       ;%;      %;        ;%;        % ;%;  ,%;'\n";
            file << "        `%;.     ;%;     %;'         `;%%;.%;'\n";
            file << "         `:;%.    ;%%. %@;        %; ;@%;%'\n";
            file << "            `:%;.  :;bd%;          %;@%;'\n";
            file << "              `@%:.  :;%.         ;@@%;'\n";   
            file << "                `@%.  `;@%.      ;@@%;\n";         
            file << "                  `@%%. `@%%    ;@@%;\n";        
            file << "                    ;@%. :@%%  %@@%;\n";       
            file << "                      %@bd%%%bd%%:;\n";     
            file << "                        #@%%%%%:;;\n";
            file << "                        %@@%%%::;\n";
            file << "                        %@@@%(o);  . '\n";         
            file << "                        %@@@o%;:(.,'\n";         
            file << "                    `.. %@@@o%::;\n";         
            file << "                       `)@@@o%::;\n";         
            file << "                        %@@(o)::;\n";        
            file << "                       .%@@@@%::;\n";         
            file << "                       ;%@@@@%::;.\n";          
            file << "                      ;%@@@@%%:;;;.\n"; 
            file << "                  ...;%@@@@@%%:;;;;,..\n";
            file.close();
        }
    }
}

const char *ShrubberyCreationForm::FileNotOpenException::what() const throw()
{
    return ("File is not open.\n");
}