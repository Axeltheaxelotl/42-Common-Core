/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 14:08:33 by alanty            #+#    #+#             */
/*   Updated: 2024/07/15 14:08:37 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : nextIndex(0) {}

void PhoneBook::addContact(const Contact& contact) {
    contacts[nextIndex] = contact;
    nextIndex = (nextIndex + 1) % 8;
}

void PhoneBook::displayContacts() const {
    std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << std::endl;
    for (int i = 0; i < 8; i++) {
        std::cout << std::setw(10) << i << "|"
                  << std::setw(10) << (contacts[i].getFirstName().size() > 10 ? contacts[i].getFirstName().substr(0, 9) + "." : contacts[i].getFirstName()) << "|"
                  << std::setw(10) << (contacts[i].getLastName().size() > 10 ? contacts[i].getLastName().substr(0, 9) + "." : contacts[i].getLastName()) << "|"
                  << std::setw(10) << (contacts[i].getNickname().size() > 10 ? contacts[i].getNickname().substr(0, 9) + "." : contacts[i].getNickname()) << std::endl;
    }
}

void PhoneBook::displayContact(int index) const {
    if (index < 0 || index >= 8) {
        std::cerr << "Invalid index" << std::endl;
        return;
    }
    std::cout << "First Name: " << contacts[index].getFirstName() << std::endl;
    std::cout << "Last Name: " << contacts[index].getLastName() << std::endl;
    std::cout << "Nickname: " << contacts[index].getNickname() << std::endl;
    std::cout << "Phone Number: " << contacts[index].getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret: " << contacts[index].getDarkestSecret() << std::endl;
}
