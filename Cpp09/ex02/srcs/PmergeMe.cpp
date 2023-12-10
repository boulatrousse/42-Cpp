/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 12:17:14 by osterger          #+#    #+#             */
/*   Updated: 2023/12/10 10:48:49 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <PmergeMe.hpp>

static bool checkIfValidChars(char *str);
static bool checkIfDuplicates(std::vector<int> vec);

PmergeMe::PmergeMe(void)
{
    this->_argc = 0;
    this->_argv = NULL;

    return ;
}

PmergeMe::PmergeMe(int argc, char **argv)
{
    this->_argc = argc;
    this->_argv = argv;

    return ;
}

PmergeMe::PmergeMe(PmergeMe const &src)
{
    *this = src;

    return ;
}

PmergeMe::~PmergeMe(void)
{
    return ;
}

PmergeMe &PmergeMe::operator=(PmergeMe const &src)
{
    this->_argc = src._argc;
    this->_argv = src._argv;
    this->_v = src._v;
    
    return (*this);
}

bool PmergeMe::checkArg(void)
{
    int         tmpI = 0;
    double      tmpD = 0;
    
    for (int i = 1; i < _argc; i++)
    {
        if (!checkIfValidChars(_argv[i]))
            return (false);

        tmpD = atof(_argv[i]);
        if (tmpD < 0 || tmpD > 2147483647)
            return (false);
        else if (tmpD == 0 && _argv[i][0] != '0')
            return (false);

        tmpI = tmpD;
        _v.push_back(tmpI);
    }

    if (!checkIfDuplicates(_v))
        return (false);
    return (true);
}

void PmergeMe::insertionSortVector(void)
{
    int         tmp = 0;
    
    for (size_t i = 0; i < _v.size(); i ++)
    {
        for (size_t j = i; j > 0; j--)
        {
            if (_v[j] < _v[j - 1])
            {
                tmp = _v[j];
                _v[j] = _v[j - 1];
                _v[j - 1] = tmp;
            }
        }
    }
    return ;
}

// void PmergeMe::mergeSortVector(void)
// {
//     return ;
// }

void PmergeMe::displayInfo(void)
{
    std::vector<int>    tmpVector = this->_v;
    
    std::cout << "\033[1;36m";
    std::cout << "Integer sequence BEFORE sorting :  ";
    std::cout << "\033[0m";
    
    for (size_t i = 0; i < tmpVector.size(); i++)
        std::cout << tmpVector[i] << " ";
    std::cout << std::endl;

    std::cout << "\033[1;32m";
    std::cout << "Integer sequence AFTER sorting :   ";
    std::cout << "\033[0m";

    std::sort(tmpVector.begin(), tmpVector.end());

    for (size_t i = 0; i < tmpVector.size(); i++)
        std::cout << tmpVector[i] << " ";
    std::cout << std::endl;
}



// ===== STATIC FUNCTIONS =====

static bool checkIfValidChars(char *str)
{
    std::string     tmp = str;

    for (size_t i = 0; i < tmp.size(); i++)
    {
        if (strchr("1234567890-+", tmp[i]) == NULL)
            return (false);
    }
    return (true);
}

static bool checkIfDuplicates(std::vector<int> vec)
{
    std::set<int>       dup(vec.begin(), vec.end());
    
    if (vec.size() != dup.size())
        return (false);
    return (true);
}