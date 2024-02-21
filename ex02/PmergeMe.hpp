/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsiffre <chsiffre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:31:20 by chsiffre          #+#    #+#             */
/*   Updated: 2024/02/21 17:54:05 by chsiffre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP
# include <iostream>
# include <deque>
# include <vector>
# include <cstdlib>

class PmergeMe {
  
    private :
    public :
        PmergeMe();
        ~PmergeMe();
        void groupByPairsDeque(const std::vector<int>& numbers);
        void groupByPairsVector(const std::vector<int>& numbers);
        void displayPairsDeque() const;
        void displayPairsVector() const;
        
        std::deque<std::pair<int, int> > pairsDeque;
        std::vector<std::pair<int, int> > pairsVector;
};


#endif