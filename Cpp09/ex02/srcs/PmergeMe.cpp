/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 12:17:14 by osterger          #+#    #+#             */
/*   Updated: 2023/12/12 10:50:12 by lboulatr         ###   ########.fr       */
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
    std::cout << "\033[1;36mInteger sequence before sorting :   \033[0m";;
    
    for (size_t i = 0; i < _v.size(); i++)
        std::cout << _v[i] << " ";
    std::cout << std::endl;

    std::cout << "\033[1;32mInteger sequence after sorting :   \033[0m";

    clock_t     startVector = clock();
    mergeSort(this->_v);
    clock_t     endVector = clock();

    clock_t     startDeque = clock();
    mergeSort(this->_d);
    clock_t     endDeque = clock();

    for (size_t i = 0; i < _v.size(); i++)
        std::cout << _v[i] << " ";
    std::cout << "\n\n";

    double durationVector = (double)(endVector - startVector) / CLOCKS_PER_SEC;
    double durationDeque = (double)(endDeque - startDeque) / CLOCKS_PER_SEC;
    
    std::cout << "Time to process a range of " << _v.size() << " elements with std::vector : " << durationVector << " us\n";
    std::cout << "Time to process a range of " << _d.size() << " elements with std::deque : " << durationDeque << " us\n";
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