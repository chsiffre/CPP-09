/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMeDeq.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charles <charles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 19:30:46 by charles           #+#    #+#             */
/*   Updated: 2024/03/14 19:50:01 by charles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

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

void PmergeMe::makeGroupsDeq()
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
    sizeGroupsDeq.push_back(2);
    // std::cout << rightNumbersVector.size() << std::endl;
    while (i < rightNumbersDeq.size())
    {
        sizeGroup = pow(2, power) - sizeGroup;
        power++;
        end = i + sizeGroup;
        
        if (end > rightNumbersDeq.size())
            end = rightNumbersDeq.size();
        if (sizeGroup > rightNumbersDeq.size() - i)
            sizeGroupsDeq.push_back(rightNumbersDeq.size() - i);
        else
            sizeGroupsDeq.push_back(sizeGroup);
        i = end;
    }
    
    
    for (size_t x = 0; x < sizeGroups.size(); x++)
    {
        std::cout << sizeGroups[x] << std::endl;
    }
    
}

void PmergeMe::setIndexsDeq()
{
    size_t i = 0;
    int iBySizeGroup = 0;
    std::deque<int> reverser;

    while (i < sizeGroupsDeq.size())
    {
        int x = -1;
        while (++x < sizeGroupsDeq[i])
            reverser.push_back(rightNumbersDeq[iBySizeGroup++]);
        std::reverse(reverser.begin(), reverser.end());
        // imprimerVecteur(reverser);
        size_t y = -1;
        // std::cout << reverser.size() << std::endl;
        while (++y < reverser.size())
            rightNumbersDeqIndexed.push_back(reverser[y]);
        reverser.clear();
        i++;
    }
    imprimerVecteur(rightNumbersDeqIndexed);
    insertByDeq(leftNumbersDeq ,rightNumbersDeqIndexed);
}

int PmergeMe::dichoInsertDeq(const std::deque<int>& sortedDeq, int nb) 
{
    int start = 0;
    int end = sortedDeq.size() - 1;

    while (start <= end)
    {
        int middle = (start + end) / 2;
        if (sortedDeq[middle] == nb)
            return middle;
        else if (sortedDeq[middle] < nb)
            start = middle + 1;
        else
            end = middle - 1;
    }
    return start;
}


void PmergeMe::insertByDeq(std::deque<int>& sortedDeq, const std::deque<int>& unsortedDeq) 
{
    for (std::deque<int>::const_iterator it = unsortedDeq.begin(); it != unsortedDeq.end(); ++it) 
    {
        int pos = dichoInsertDeq(sortedDeq, *it);
        sortedDeq.insert(sortedDeq.begin() + pos, *it);
    }
    imprimerVecteur(sortedDeq);
}



void PmergeMe::separatePairsDeq()
{
    leftnumberDeq.clear(); 
    rightNumbersDeq.clear();

    for (size_t i = 0; i < pairsDeque.size(); ++i) {
        leftnumberDeq.push_back(pairsDeque[i].first);
        rightNumbersDeq.push_back(pairsDeque[i].second);
    }
    leftnumberDeq.insert(leftnumberDeq.begin(), rightNumbersDeq[0]);
    rightNumbersDeq.erase(rightNumbersDeq.begin());
}

void PmergeMe::displayPairsDeque() const {
    for (std::deque<std::pair<int, int> >::const_iterator it = pairsDeque.begin(); it != pairsDeque.end(); ++it) {
        const std::pair<int, int>& pair = *it;
        std::cout << "(" << pair.first << ", " << pair.second << ") ";
    }
    std::cout << std::endl;
}
