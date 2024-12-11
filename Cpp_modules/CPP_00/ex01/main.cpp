/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 14:06:25 by alanty            #+#    #+#             */
/*   Updated: 2024/07/15 14:06:34 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
// main.cpp
#include "PhoneBook.hpp"
#include <iostream>

void addContact(PhoneBook& phoneBook) {
    Contact contact;
    std::string input;
    
    std::cout << "Enter First Name: ";
    std::getline(std::cin, input);
    contact.setFirstName(input);
    
    std::cout << "Enter Last Name: ";
    std::getline(std::cin, input);
    contact.setLastName(input);
    
    std::cout << "Enter Nickname: ";
    std::getline(std::cin, input);
    contact.setNickname(input);
    
    std::cout << "Enter Phone Number: ";
    std::getline(std::cin, input);
    contact.setPhoneNumber(input);
    
    std::cout << "Enter Darkest Secret: ";
    std::getline(std::cin, input);
    contact.setDarkestSecret(input);
    
    phoneBook.addContact(contact);
}

int main() {
    PhoneBook phoneBook;
    std::string command;
    
    while (true) {
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin, command);
        
        if (command == "ADD") {
            addContact(phoneBook);
        } else if (command == "SEARCH") {
            phoneBook.displayContacts();
            std::cout << "Enter index to view details: ";
            std::getline(std::cin, command);
            try {
                int index = std::stoi(command);
                phoneBook.displayContact(index);
            } catch (...) {
                std::cerr << "Invalid index format" << std::endl;
            }
        } else if (command == "EXIT") {
            break;
        } else {
            std::cerr << "Unknown command" << std::endl;
        }
    }
    
    return 0;
}
