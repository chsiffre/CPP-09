/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsiffre <chsiffre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:31:16 by chsiffre          #+#    #+#             */
/*   Updated: 2024/02/21 17:55:56 by chsiffre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::~PmergeMe()
{
    
}

void PmergeMe::groupByPairsDeque(const std::vector<int>& numbers) 
{
    // pairsDeque.clear();  // Effacer le deque avant de le remplir à nouveau

    for (size_t i = 0; i < numbers.size(); i += 2) {
        if (i + 1 < numbers.size()) {
            pairsDeque.push_back(std::make_pair(numbers[i], numbers[i + 1]));
        }
    }
}

void PmergeMe::groupByPairsVector(const std::vector<int>& numbers) 
{
    pairsVector.clear();  // Effacer le vector avant de le remplir à nouveau

    for (size_t i = 0; i < numbers.size(); i += 2) {
        if (i + 1 < numbers.size()) {
                pairsVector.push_back(std::make_pair(numbers[i], numbers[i + 1]));
        }
    }
}

void PmergeMe::displayPairsDeque() const {
    for (std::deque<std::pair<int, int> >::const_iterator it = pairsDeque.begin(); it != pairsDeque.end(); ++it) {
        const std::pair<int, int>& pair = *it;
        std::cout << "(" << pair.first << ", " << pair.second << ") ";
    }
    std::cout << std::endl;
}


void PmergeMe::displayPairsVector() const {
    for (std::vector<std::pair<int, int> >::const_iterator it = pairsVector.begin(); it != pairsVector.end(); ++it) {
            const std::pair<int, int>& pair = *it;
            std::cout << "(" << pair.first << ", " << pair.second << ") ";
        }
    std::cout << std::endl;
}