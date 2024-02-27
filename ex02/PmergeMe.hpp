/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsiffre <chsiffre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:31:20 by chsiffre          #+#    #+#             */
/*   Updated: 2024/02/27 15:19:58 by chsiffre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP
# include <iostream>
# include <deque>
# include <vector>
# include <cstdlib>
#include <algorithm>

class PmergeMe {
  
    private :

        template <typename T>
        void printVector(const std::vector<T>& vec) 
        {
            std::cout << "[";
            for (size_t i = 0; i < vec.size(); ++i) {
                std::cout << vec[i];
                if (i < vec.size() - 1) {
                    std::cout << ", ";
                }
            }
            std::cout << "]\n";
        }
    public :
        PmergeMe();
        ~PmergeMe();
        void groupByPairsDeque(const std::vector<int>& numbers);
        void groupByPairsVector(const std::vector<int>& numbers);
        void displayPairsDeque() const;
        void displayPairsVector() const;
        void printVectors();
        void separatePairs();
        
        std::deque<std::pair<int, int> > pairsDeque;
        std::vector<std::pair<int, int> > pairsVector;
        std::vector<int> leftNumbersVector; 
        std::vector<int> rightNumbersVector;
};


#endif