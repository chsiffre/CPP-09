/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsiffre <chsiffre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 11:32:42 by chsiffre          #+#    #+#             */
/*   Updated: 2024/02/19 15:02:06 by chsiffre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main (int ac, char **argv)
{
    if (ac == 2)
    {
        BitcoinExchange btc;
        btc.parseAndFind(argv[1]);
    }
    else
        std::cout << "error : invalid number of args" << std::endl;
    return 0;
}