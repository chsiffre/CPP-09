/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsiffre <chsiffre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:11:53 by chsiffre          #+#    #+#             */
/*   Updated: 2024/03/13 11:55:23 by chsiffre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main (int ac, char **argv)
{
    if (ac < 2) {
        std::cerr << "More args needed" << std::endl;
        return 1;
    }
    std::vector<int> vecNum;
    for (int i = 1; i < ac; ++i)
    {
        int num = atoi(argv[i]);
        if (num > 0)
        {
            vecNum.push_back(num);
        }
        else
        {
            std::cerr << "Warning: Ignoring non-positive integer argument: " << argv[i] << std::endl;
            return 1;
        }
    }
    PmergeMe merge;
    merge.groupByPairsDeque(vecNum);
    merge.groupByPairsVector(vecNum);
    merge.separatePairs();
    merge.printVectors(); 
    merge.makeGroups();
    merge.setIndexs();
    
    return 0;
}