/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsiffre <chsiffre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:31:16 by chsiffre          #+#    #+#             */
/*   Updated: 2024/02/29 17:43:23 by chsiffre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void imprimerVecteur(const std::vector<int>& vec) {
    std::cout << "Contenu du vecteur : ";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}

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
    leftNumbersVector.insert(leftNumbersVector.begin(), rightNumbersVector[0]);
    rightNumbersVector.erase(rightNumbersVector.begin());
    
    
}

void PmergeMe::makeGroups()
{
    // for (size_t i = 0; i < rightNumbersVector.size(); i++)
    // {
    //     std::cout << rightNumbersVector[i] << " ";
    // }
    // std::cout << std::endl;
    // if (rightNumbersVector.size() < 2) {
    //     std::cerr << "Le nombre de groupes doit être au moins 2." << std::endl;
    //     return;
    // }
    int power = 2;
    bool firstCalc = true;
    size_t i = 2;
    size_t sizeGroup = 2;
    size_t end = 0;
    sizeGroups.push_back(2);
    // std::cout << rightNumbersVector.size() << std::endl;
    while (i < rightNumbersVector.size())
    {
        sizeGroup = pow(2, power) - sizeGroup;
        power++;
        end = i + sizeGroup;
        
        firstCalc = false;
        if (end > rightNumbersVector.size())
            end = rightNumbersVector.size();
        if (sizeGroup > rightNumbersVector.size() - i)
            sizeGroups.push_back(rightNumbersVector.size() - i);
        else
            sizeGroups.push_back(sizeGroup);
        i = end;
    }
    
    
    for (size_t x = 0; x < sizeGroups.size(); x++)
    {
        std::cout << sizeGroups[x] << std::endl;
    }
    
}

void PmergeMe::setIndexs()
{
    size_t i = 0;
    int iBySizeGroup = 0;
    std::vector<int> reverser;

    while (i < sizeGroups.size())
    {
        int x = -1;
        while (++x < sizeGroups[i])
            reverser.push_back(rightNumbersVector[iBySizeGroup++]);
        std::reverse(reverser.begin(), reverser.end());
        // imprimerVecteur(reverser);
        size_t y = -1;
        // std::cout << reverser.size() << std::endl;
        while (++y < reverser.size())
            rightNumbersVectorIndexed.push_back(reverser[y]);
        reverser.clear();
        i++;
    }
    imprimerVecteur(rightNumbersVectorIndexed);
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