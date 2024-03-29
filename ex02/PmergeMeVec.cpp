/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMeVec.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charles <charles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:31:16 by chsiffre          #+#    #+#             */
/*   Updated: 2024/03/14 19:42:26 by charles          ###   ########.fr       */
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


void PmergeMe::separatePairsVec()
{
    leftNumbersVector.clear(); 
    rightNumbersVector.clear();

    for (size_t i = 0; i < pairsVector.size(); ++i) {
        leftNumbersVector.push_back(pairsVector[i].first);
        rightNumbersVector.push_back(pairsVector[i].second);
    }
    leftNumbersVector.insert(leftNumbersVector.begin(), rightNumbersVector[0]);
    rightNumbersVector.erase(rightNumbersVector.begin());
}

void PmergeMe::makeGroupsVec()
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
    size_t i = 2;
    size_t sizeGroup = 2;
    size_t end = 0;
    sizeGroupsVec.push_back(2);
    // std::cout << rightNumbersVector.size() << std::endl;
    while (i < rightNumbersVector.size())
    {
        sizeGroup = pow(2, power) - sizeGroup;
        power++;
        end = i + sizeGroup;
        
        if (end > rightNumbersVector.size())
            end = rightNumbersVector.size();
        if (sizeGroup > rightNumbersVector.size() - i)
            sizeGroupsVec.push_back(rightNumbersVector.size() - i);
        else
            sizeGroupsVec.push_back(sizeGroup);
        i = end;
    }
    
    
    for (size_t x = 0; x < sizeGroups.size(); x++)
    {
        std::cout << sizeGroups[x] << std::endl;
    }
    
}

void PmergeMe::setIndexsVec()
{
    size_t i = 0;
    int iBySizeGroup = 0;
    std::vector<int> reverser;

    while (i < sizeGroupsDeq.size())
    {
        int x = -1;
        while (++x < sizeGroupsDeq[i])
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
    insertByVec(leftNumbersVector ,rightNumbersVectorIndexed);
}

int PmergeMe::dichoInsertVec(const std::vector<int>& sortedVec, int nb) 
{
    int start = 0;
    int end = sortedVec.size() - 1;

    while (start <= end) 
    {
        int middle = (start + end) / 2;
        if (sortedVec[middle] == nb)
            return middle;
        else if (sortedVec[middle] < nb)
            start = middle + 1;
        else
            end = middle - 1;
    }
    return start;
}

void PmergeMe::insertByVec(std::vector<int>& sortedVec, const std::vector<int>& unsortedVec) 
{
    for (std::vector<int>::const_iterator it = unsortedVec.begin(); it != unsortedVec.end(); ++it) 
    {
        int pos = dichoInsertVec(sortedVec, *it);
        sortedVec.insert(sortedVec.begin() + pos, *it);
    }
    imprimerVecteur(sortedVec);
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


void PmergeMe::displayPairsVector() const {
    for (std::vector<std::pair<int, int> >::const_iterator it = pairsVector.begin(); it != pairsVector.end(); ++it) {
            const std::pair<int, int>& pair = *it;
            std::cout << "(" << pair.first << ", " << pair.second << ") ";
        }
    std::cout << std::endl;
}