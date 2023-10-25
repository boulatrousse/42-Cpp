/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 09:02:37 by osterger          #+#    #+#             */
/*   Updated: 2023/08/21 11:14:42 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

void sed_manager(char **argv)
{   
    std::string         one_str;
    std::string         filename;
    std::string         s1(argv[2]);
    std::string         s2(argv[3]);
    std::ifstream       stream;

    if (s1.empty())
    {
        std::cout << "You cannot replace something empty." << std::endl;
        return ;
    }

    one_str = getString(argv[1]);
    if (one_str.empty())
        return ;
        
    while (check(one_str, s1) != FAILURE)
        one_str = replace(one_str, s1, s2);

    filename = getFilename(argv[1]);
    std::ofstream outfile(filename.append(".replace").data());
    outfile << one_str;
}

std::string getString(const char *filename)
{
    int                 count;
    char                c;
    std::string         final_string;
    std::ifstream       entryFile;

    entryFile.open(filename, std::fstream::in);
    if (!entryFile.is_open())
    {
        std::cout << "Error: this file does not exist." << std::endl;
        entryFile.close();
        return ("");
    }
    
    count = getCount(filename);

    while (count > 1)
    {
        c = entryFile.get();
        final_string += c;
        count--;
    }
    
    entryFile.close();
    return (final_string);
}

int getCount(const char *filename)
{
    int                 count;
    char                c;
    std::ifstream       entryFile;

    count = 0;
    
    entryFile.open(filename, std::fstream::in);
    
    while (entryFile.good() && !entryFile.eof())
    {
        c = entryFile.get();
        count++;
    }
    entryFile.close();
    return (count);
}

std::string replace(std::string one_string, std::string s1, std::string s2)
{
    std::size_t         found;
    std::string         before;
    std::string         after;
    std::string         str_replace;
    
    found = one_string.find(s1);
    if (found >= MAX_SIZE_T)
        return (one_string);
    before = one_string.substr(0, found);
    after = one_string.substr(found + s1.size());
    str_replace = before + s2 + after;
    
    return (str_replace);
}

int check(std::string str, std::string s1)
{
    size_t              found;
    
    found = str.find(s1);
    if (found >= MAX_SIZE_T)
        return (FAILURE);
    return (SUCCESS);
}

std::string getFilename(char *str)
{
    std::string         filename(str);
    std::string         final_filename;
    size_t              last_slash;

    last_slash = filename.find_last_of("/");
    final_filename = filename.substr(last_slash + 1);

    return (final_filename);
}