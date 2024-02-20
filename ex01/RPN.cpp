/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsiffre <chsiffre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:50:07 by chsiffre          #+#    #+#             */
/*   Updated: 2024/02/20 14:31:09 by chsiffre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"


bool isOperator(const std::string& token) {
    return token == "+" || token == "-" || token == "*" || token == "/";
}

bool isNumeric(const std::string& token) 
{
    double is_num = atof(token.c_str());
    if (is_num >= 0 && is_num <= 10)
        return true;
    else
        return false;
}

double evaluateRPN(const std::string& expression) {
    std::stack<double> operandStack;

    std::stringstream ss(expression);
    std::string token;

    while (ss >> token) 
    {
        if (!isOperator(token) && !isNumeric(token)) 
        {
            std::cerr << "Erreur : '" << token << "' n'est ni un opérateur valide ni un opérande valide." << std::endl;
            exit(1);
        }
        if (isOperator(token)) 
        {
            if (operandStack.size() < 2) 
            {
                std::cerr << "Erreur : pas assez d'opérandes pour l'opérateur '" << token << "'." << std::endl;
                exit(1);
            }

            double operand2 = operandStack.top();
            operandStack.pop();
            double operand1 = operandStack.top();
            operandStack.pop();

            if (token == "+") 
                operandStack.push(operand1 + operand2);
            else if (token == "-") 
                operandStack.push(operand1 - operand2);
            else if (token == "*") 
                operandStack.push(operand1 * operand2);
            else if (token == "/") 
            {
                if (operand2 == 0) 
                {
                    std::cerr << "Erreur : division par zéro." << std::endl;
                    exit(1);
                }
                operandStack.push(operand1 / operand2);
            }
        } 
        else 
        {
            double numericValue = atof(token.c_str());
            operandStack.push(numericValue);
        }
    }
    if (operandStack.size() != 1) 
    {
        std::cerr << "Erreur : expression mal formée." << std::endl;
        exit(1);
    }
    return operandStack.top();
}
