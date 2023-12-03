/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osterger <osterger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 12:17:11 by osterger          #+#    #+#             */
/*   Updated: 2023/12/03 14:38:37 by osterger         ###   ########.fr       */
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
# include <set>

class PmergeMe
{
    public:

        PmergeMe(void);
        PmergeMe(int argc, char **argv);
        PmergeMe(PmergeMe const &src);
        ~PmergeMe(void);

        PmergeMe                &operator=(PmergeMe const &src);

        bool                    checkArg(void);
        void                    algo(void);
        void                    displayInfo(void);

    private:

        int                     _argc;
        char                    **_argv;

        std::vector<int>        _v;

};

#endif