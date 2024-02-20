/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsiffre <chsiffre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:50:30 by chsiffre          #+#    #+#             */
/*   Updated: 2024/02/20 14:36:43 by chsiffre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv) {
    if (argc != 2) 
    {
        std::cerr << "Usage: " << argv[0] << " <expression in RPN>" << std::endl;
        return 0; 
    }
    std::string expression(argv[1]);
    double result = evaluateRPN(argv[1]);

    std::cout << "Le résultat de l'expression en RPN est : " << result << std::endl;
    return 0;
}
