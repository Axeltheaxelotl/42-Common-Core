/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 17:50:18 by alanty            #+#    #+#             */
/*   Updated: 2024/08/21 14:54:51 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main() {
    // Test des constructeurs
    Fixed a;                     // Test du constructeur par défaut
    Fixed const b(10);           // Test du constructeur avec un entier
    Fixed const c(42.42f);       // Test du constructeur avec un flottant
    Fixed const d(b);            // Test du constructeur de copie
    Fixed e;                     // Un autre objet pour tester l'affectation

    e = Fixed(1234.4321f);       // Test de l'opérateur d'affectation

    // Affichage des valeurs
    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;
    std::cout << "c: " << c << std::endl;
    std::cout << "d: " << d << std::endl;
    std::cout << "e: " << e << std::endl;

    // Test des comparaisons
    std::cout << "b > c: " << (b > c) << std::endl;
    std::cout << "b < c: " << (b < c) << std::endl;
    std::cout << "b >= d: " << (b >= d) << std::endl;
    std::cout << "b <= c: " << (b <= c) << std::endl;
    std::cout << "b == d: " << (b == d) << std::endl;
    std::cout << "b != c: " << (b != c) << std::endl;

    // Test des opérations arithmétiques
    std::cout << "c + b: " << (c + b) << std::endl;
    std::cout << "c - b: " << (c - b) << std::endl;
    std::cout << "c * b: " << (c * b) << std::endl;
    std::cout << "c / b: " << (c / b) << std::endl;

    // Test de l'incrémentation et de la décrémentation
    Fixed f;
    std::cout << "f: " << f << std::endl;
    std::cout << "++f: " << ++f << std::endl;  // Pré-incrémentation
    std::cout << "f++: " << f++ << std::endl;  // Post-incrémentation
    std::cout << "f: " << f << std::endl;
    std::cout << "--f: " << --f << std::endl;  // Pré-décrémentation
    std::cout << "f--: " << f-- << std::endl;  // Post-décrémentation
    std::cout << "f: " << f << std::endl;

    // Test des fonctions min et max
    std::cout << "min(b, c): " << Fixed::min(b, c) << std::endl;
    std::cout << "max(b, c): " << Fixed::max(b, c) << std::endl;

    return 0;
}

