/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsiffre <chsiffre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:09:12 by chsiffre          #+#    #+#             */
/*   Updated: 2024/02/20 14:09:53 by chsiffre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>
# include <sstream>
# include <cmath>
# include <stdexcept>
# include <string>

bool isOperator(const std::string& token);
bool isNumeric(const std::string& token);
double evaluateRPN(const std::string& expression);

#endif 