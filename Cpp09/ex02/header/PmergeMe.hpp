/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 12:17:11 by osterger          #+#    #+#             */
/*   Updated: 2023/12/12 10:43:35 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <cstdlib>
# include <cstring>
# include <algorithm>
# include <vector>
# include <deque>
# include <ctime>
# include <time.h>

# define N 11

class PmergeMe
{
    public:

        PmergeMe(void);
        PmergeMe(int argc, char **argv);
        PmergeMe(PmergeMe const &src);
        ~PmergeMe(void);

        PmergeMe                &operator=(PmergeMe const &src);

        bool                    checkArg(void);
        void                    displayInfo(void);


    private:

        int                     _argc;
        char                    **_argv;

        std::vector<int>        _v;
        std::deque<int>         _d;

};

template <typename T>
bool checkIfDuplicates(T cont)
{
    typename T::iterator    begin = cont.begin();
    typename T::iterator    end = cont.end();

    while (begin != end)
    {
        if (std::count(cont.begin(), cont.end(), *begin) > 1)
            return (false);
        begin++;
    }
    return (true);
}

template <typename T>
void insertSort(T &cont)
{
    int         tmp = 0;
    
    for (size_t i = 0; i < cont.size(); i ++)
    {
        for (size_t j = i; j > 0; j--)
        {
            if (cont[j] < cont[j - 1])
            {
                tmp = cont[j];
                cont[j] = cont[j - 1];
                cont[j - 1] = tmp;
            }
        }
    }
}

template <typename T>
void mergeSort(T &cont)
{
    typename T::iterator      middle = cont.begin() + (cont.size() / 2);
    
    if (cont.size() <= N)
    {
        insertSort(cont);
        return ;
    }
    
    T    left(cont.begin(), middle);
    T    right(middle, cont.end());

    mergeSort(left);
    mergeSort(right);
    std::merge(left.begin(), left.end(), right.begin(), right.end(), cont.begin());

    return ;
}

#endif