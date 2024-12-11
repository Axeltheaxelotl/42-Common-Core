/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 14:08:16 by alanty            #+#    #+#             */
/*   Updated: 2024/07/15 14:08:20 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void Contact::setFirstName(const std::string& firstName) {
    this->firstName = firstName;
}

void Contact::setLastName(const std::string& lastName) {
    this->lastName = lastName;
}

void Contact::setNickname(const std::string& nickname) {
    this->nickname = nickname;
}

void Contact::setPhoneNumber(const std::string& phoneNumber) {
    this->phoneNumber = phoneNumber;
}

void Contact::setDarkestSecret(const std::string& darkestSecret) {
    this->darkestSecret = darkestSecret;
}

std::string Contact::getFirstName() const {
    return firstName;
}

std::string Contact::getLastName() const {
    return lastName;
}

std::string Contact::getNickname() const {
    return nickname;
}

std::string Contact::getPhoneNumber() const {
    return phoneNumber;
}

std::string Contact::getDarkestSecret() const {
    return darkestSecret;
}
