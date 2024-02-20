/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsiffre <chsiffre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 11:27:05 by chsiffre          #+#    #+#             */
/*   Updated: 2024/02/20 10:58:45 by chsiffre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP
# include <iostream>
# include <fstream>
# include <map>
# include <string>
# include <sstream>
# include <cstdlib>
# include <iomanip>

class BitcoinExchange {

    private :
        struct {
            float value;
            std::string date;
        }DataStruct;
        std::map<std::string, float> KeyValue;
    public :
        BitcoinExchange();
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &other);
        BitcoinExchange &operator=(const BitcoinExchange &other);
        void fillStruct(std::string line);
        void parseAndFind(std::string Filename);
        void checkDate(int year, int month, int day);
        void checkValue(float value);
        void findAndResult();
        bool leapYear(int year);
};
#endif