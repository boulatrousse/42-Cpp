/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 02:42:14 by osterger          #+#    #+#             */
/*   Updated: 2023/12/01 13:38:25 by lboulatr         ###   ########.fr       */
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

        void                        displayExchangeRate(void);
        void                        createMapInput(std::string file);
        void                        createMapData(void);
        bool                        getExchangeRate(std::string input, std::string data);


    private:

        std::string                                _filename;
        std::multimap<std::string, float>          _mapInput;
        std::multimap<std::string, float>          _mapData;
        
};

#endif