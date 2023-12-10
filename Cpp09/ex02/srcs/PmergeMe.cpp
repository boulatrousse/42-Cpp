/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 12:17:14 by osterger          #+#    #+#             */
/*   Updated: 2023/12/10 16:32:15 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <PmergeMe.hpp>

static bool checkIfValidChars(char *str);

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
    this->_d = src._d;
    
    return (*this);
}

void PmergeMe::launcher(void)
{
    this->displayInfo();
    
    return ;
}

// ===== SORT FUNCTIONS =====

void PmergeMe::mergeSortVector(std::vector<int> &vec)
{
    std::vector<int>::iterator      middle = vec.begin() + (vec.size() / 2);
    
    if (vec.size() < 2)
    {
       insertSort(vec);
        return ;
    }
    
    std::vector<int>                left(vec.begin(), middle);
    std::vector<int>                right(middle, vec.end());

    mergeSortVector(left);
    mergeSortVector(right);
    std::merge(left.begin(), left.end(), right.begin(), right.end(), vec.begin());
    
    return ;
}

void PmergeMe::mergeSortDeque(std::deque<int> &deque)
{
    std::deque<int>::iterator      middle = deque.begin() + (deque.size() / 2);
    
    if (deque.size() < 2)
    {
       insertSort(deque);
        return ;
    }
    
    std::deque<int>                left(deque.begin(), middle);
    std::deque<int>                right(middle, deque.end());

    mergeSortDeque(left);
    mergeSortDeque(right);
    std::merge(left.begin(), left.end(), right.begin(), right.end(), deque.begin());
    
    return ;
}



// ===== UTILS FUNCTIONS =====

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
        _d.push_back(tmpI);
    }

    if (!checkIfDuplicates(_v) || !checkIfDuplicates(_d))
        return (false);
    return (true);
}

void PmergeMe::displayInfo(void)
{    
    std::cout << "\033[1;36m";
    std::cout << "Integer sequence BEFORE sorting :  ";
    std::cout << "\033[0m";
    
    for (size_t i = 0; i < _v.size(); i++)
        std::cout << _v[i] << " ";
    std::cout << std::endl;

    std::cout << "\033[1;32m";
    std::cout << "Integer sequence AFTER sorting :   ";
    std::cout << "\033[0m";

    mergeSortVector(this->_v);

    for (size_t i = 0; i < _v.size(); i++)
        std::cout << _v[i] << " ";
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