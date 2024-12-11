/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 14:07:15 by alanty            #+#    #+#             */
/*   Updated: 2024/07/15 14:07:19 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// PhoneBook.hpp
#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <iomanip>

class PhoneBook {
private:
    Contact contacts[8];
    int nextIndex;

public:
    PhoneBook();
    void addContact(const Contact& contact);
    void displayContacts() const;
    void displayContact(int index) const;
};

#endif
