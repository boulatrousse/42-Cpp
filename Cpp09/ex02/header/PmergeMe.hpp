/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osterger <osterger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 12:17:11 by osterger          #+#    #+#             */
/*   Updated: 2023/12/02 16:05:06 by osterger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <cstdlib>
# include <cstring>

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

};

#endif