/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osterger <osterger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 02:42:14 by osterger          #+#    #+#             */
/*   Updated: 2023/11/26 11:32:46 by osterger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <string>
# include <cstdlib>
# include <map>

# define SUCCESS 0
# define FAILURE 1

class BitcoinExchange
{
    public:

        BitcoinExchange(void);
        BitcoinExchange(char *file);
        BitcoinExchange(BitcoinExchange const &src);
        ~BitcoinExchange(void);

        BitcoinExchange             &operator=(BitcoinExchange const &src);

        void                        bitcoinManager(void);
        void                        createMapInput(std::string file);
        void                        createMapData(void);

    private:

        std::string                             _filename;
        std::multimap<std::string, double>      _mapInput;
        std::multimap<std::string, double>      _mapData;
        
};

#endif