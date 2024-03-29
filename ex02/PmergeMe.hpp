/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charles <charles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:31:20 by chsiffre          #+#    #+#             */
/*   Updated: 2024/03/14 19:45:49 by charles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP
# include <iostream>
# include <deque>
# include <vector>
# include <cstdlib>
#include <algorithm>
#include <math.h>

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
        void separatePairsVec();
        void separatePairsDeq();
        void makeGroupsVec();
        void makeGroupsDeq();
        void setIndexsVec();
        void setIndexsDeq();
        void insertByVec(std::vector<int>& sortedVec, const std::vector<int>& unsortedVec);
        void insertByVec(std::deque<int>& sortedDeq, const std::deque<int>& unsortedDeq);
        int dichoInsertVec(const std::vector<int>& sortedVec, int nb);
        int dichoInsertDeq(const std::deque<int>& sortedDeq, int nb);
        
        std::vector<std::pair<int, int> > pairsVector;
        std::vector<int> leftNumbersVector;
        std::vector<int> rightNumbersVector;
        std::vector<int> rightNumbersVectorIndexed;
        std::vector<int> sizeGroupsVec;
        std::vector<int> indexsVec;

        std::deque<std::pair<int, int> > pairsDeque;
        std::deque<int> leftNumbersDeq;
        std::deque<int> rightNumbersDeq;
        std::deque<int> rightNumbersDeqIndexed;
        std::deque<int> sizeGroupsDeq;
        std::deque<int> indexsDeq;
};


#endif