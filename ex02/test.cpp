/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsiffre <chsiffre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 14:45:18 by chsiffre          #+#    #+#             */
/*   Updated: 2024/02/29 12:57:50 by chsiffre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <math.h>

void generateSizes(std::vector<int>& sizes, int numGroups) {
    int power = 2;
    int i = 0;
    int firstgroup = 2;
    int end = 0;
    if (numGroups < 2) {
        std::cerr << "Le nombre de groupes doit être au moins 2." << std::endl;
        return;
    }

    sizes.clear();
    sizes.reserve(numGroups);

    // Initialisation des deux premières tailles
    sizes.push_back(2);
    sizes.push_back(2);
    // Génération des tailles suivantes en utilisant la formule Tn = 2 * Tn-2 + 2^(n-2)
    for (int i = 2; i < numGroups; i++) {
        sizes.push_back(pow(2, i) - sizes[i - 1]);
    }
}

int main() {
    // Nombre de groupes à générercd
    int numGroups = 10;

    // Vecteur pour stocker les tailles
    std::vector<int> sizes;

    // Générer les tailles
    generateSizes(sizes, numGroups);

    // Afficher la séquence générée
    std::cout << "Tailles des groupes : ";
    for (const int& size : sizes) {
        std::cout << size << " ";
    }
    std::cout << std::endl;

    return 0;
}