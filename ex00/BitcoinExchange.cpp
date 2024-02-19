/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsiffre <chsiffre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 11:27:08 by chsiffre          #+#    #+#             */
/*   Updated: 2024/02/19 16:39:39 by chsiffre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
    std::string line;
    std::ifstream file("data.csv");
    if (!file.is_open())
    {
        std::cout << "cannot open this file";
        return ;
    }
    getline(file ,line);
    int i = 0;
    while (getline(file, line))
    {
        fillStruct(line);
        i++;
    }
    file.close();
    // std::map<std::string, float>::iterator it;
    // for (it = KeyValue.begin(); it != KeyValue.end(); ++it) {
    //     std::cout << "Clé : " << it->first << ", Valeur : " << it->second << std::endl;
    // }

}

void BitcoinExchange::fillStruct(std::string line)
{
    bool first = true;
    std::string token;
    std::stringstream ss(line);
    while (getline(ss, token, ','))
    {
        if (first)
        {
            DataStruct.date = token;
            first = false;
        }
        DataStruct.value = atoi(token.c_str());
    }
    KeyValue.insert(std::make_pair(DataStruct.date, DataStruct.value));
}

void BitcoinExchange::parseAndFind(std::string Filename)
{
    int month;
    int year;
    int day;
    char other;
    float value;
    std::string line;
    
    std::ifstream file(Filename.c_str());
    if (!file.is_open())
    {
        std::cout << "cannot open this file";
        return ;
    }
    getline(file ,line);
    if (line != "date | value")
    {
        std::cout << "error : format file" << std::endl;
        return ;
    }
    while (getline(file, line))
    {
        if (sscanf(line.c_str(), "%d-%d-%d | %f%c", &year, &month, &day, &value, &other) == 4)
        {
            if  (line[11] != '|' || std::isspace(line[13]) || line[line.length() - 1] == '.')
            {
                std::cout << "bad input : " << line << std::endl;
                continue;
            }
            try
            {
                checkValue(value);
                checkDate(year, month, day);
            
            }
            catch (std::string error)
            {
                std::cout << "Error : " << error << std::endl;
                continue;
            }
        }
        else
        {
            std::cout << "bad input : " << line << std::endl;
            continue;
        }
        size_t pos;
        pos = line.find(' ');
        DataStruct.date = line.substr(0, pos);
        DataStruct.value = value;
        findAndResult();
    }
    file.close();
}

void BitcoinExchange::checkDate(int year, int month, int day)
{
    int months[] = {31, 28 , 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && leapYear(year))
        months[1] = 29;
    if (month < 1 || month > 12 || day < 1 || day > 31 || year > 2024)
        throw(std::string) "Invalid date";
    if (year < 2009 || (year == 2009 && month == 1 && day < 2))
        throw(std::string) "No price before 2009-01-02";
    if (day > months[month - 1])
        throw(std::string) "Invalid day oh the month";
}

void BitcoinExchange::checkValue(float value)
{
    if (value > 1000)
        throw(std::string) "Value too high";
    if (value < 0)
        throw(std::string) "Value too low";
}

bool BitcoinExchange::leapYear(int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        return true;
    return false;
}
    
void BitcoinExchange::findAndResult()
{
    std::map<std::string, float>::iterator it;
    it = this->KeyValue.lower_bound(DataStruct.date);
    if (it == this->KeyValue.end())
    {
        it--;
        std::cout << DataStruct.date << " => " << DataStruct.value << " = " << std::setprecision(7) << DataStruct.value * (*it).second <<  std::endl;
        return ;
    }
    if ( it == this->KeyValue.begin())
    {
        std::cout << "cannot find any date" << std::endl;
        return ;
    }
    else
    {
        if ((*it).first != DataStruct.date)
            it--;
        std::cout << DataStruct.date << " => " << DataStruct.value << " = " << std::setprecision(7) << DataStruct.value * (*it).second << std::endl;
    }
}


BitcoinExchange::~BitcoinExchange(){
    
}