/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 12:17:11 by osterger          #+#    #+#             */
/*   Updated: 2023/12/10 15:48:12 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <cstdlib>
# include <cstring>
# include <algorithm>
# include <vector>
# include <list>
# include <set>

class PmergeMe
{
    public:

        PmergeMe(void);
        PmergeMe(int argc, char **argv);
        PmergeMe(PmergeMe const &src);
        ~PmergeMe(void);

        PmergeMe                &operator=(PmergeMe const &src);

        void                    launcher(void);
        bool                    checkArg(void);
        void                    displayInfo(void);

        void                    insertSortVector(std::vector<int> &vec);
        void                    mergeSortVector(std::vector<int> &vec);

        // void                    insertSortList(std::list<int> &list);
        // void                    mergeSortList(std::list<int> &list);

    private:

        int                     _argc;
        char                    **_argv;

        std::vector<int>        _v;

};

#endif