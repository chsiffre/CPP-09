/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsiffre <chsiffre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:31:16 by chsiffre          #+#    #+#             */
/*   Updated: 2024/02/27 15:58:18 by chsiffre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::~PmergeMe()
{
    
}


bool comparePairs(const std::pair<int, int>& pair1, const std::pair<int, int>& pair2) {
    return pair1.first < pair2.first;
}

void PmergeMe::printVectors() 
{
    std::cout << "Left Numbers Vector: ";
    printVector(leftNumbersVector);

    std::cout << "Right Numbers Vector: ";
    printVector(rightNumbersVector);
}

void PmergeMe::groupByPairsDeque(const std::vector<int>& numbers) 
{
    
    pairsDeque.clear();

    for (size_t i = 0; i < numbers.size(); i += 2) {
        if (i + 1 < numbers.size()) {
            std::pair<int, int> currentPair = std::make_pair(numbers[i], numbers[i + 1]);
            if (currentPair.first < currentPair.second) {
                std::swap(currentPair.first, currentPair.second);
            }
            pairsDeque.push_back(currentPair);
        }
    }
    std::sort(pairsDeque.begin(), pairsDeque.end(), comparePairs);
}

void PmergeMe::separatePairs() {
    leftNumbersVector.clear(); 
    rightNumbersVector.clear();

    for (size_t i = 0; i < pairsDeque.size(); ++i) {
        leftNumbersVector.push_back(pairsDeque[i].first);
        rightNumbersVector.push_back(pairsDeque[i].second);
    }
}

void PmergeMe::groupByPairsVector(const std::vector<int>& numbers) 
{
    pairsVector.clear();

    for (size_t i = 0; i < numbers.size(); i += 2) {
        if (i + 1 < numbers.size()) {
            std::pair<int, int> currentPair = std::make_pair(numbers[i], numbers[i + 1]);
        if (currentPair.first < currentPair.second) {
                std::swap(currentPair.first, currentPair.second);
            }
            pairsVector.push_back(currentPair);
        }
    }
    std::sort(pairsVector.begin(), pairsVector.end(), comparePairs);
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