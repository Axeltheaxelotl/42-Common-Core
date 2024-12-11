#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>

class Bureaucrat 
{
public:
    // Constructeur et destructeur
    Bureaucrat(const std::string &name, int grade);
    ~Bureaucrat();

    // Méthodes pour obtenir le nom et le grade
    std::string getName() const;
    int getGrade() const;
    // Méthodes pour incrémenter et décrémenter le grade
    void incrementGrade();
    void decrementGrade();

    // Exceptions personnalisées
    class GradeTooHighException : public std::exception {
    public:
        const char* what() const throw() {
            return "Grade is too high!";
        }
    };

    class GradeTooLowException : public std::exception {
    public:
        const char* what() const throw() {
            return "Grade is too low!";
        }
    };

private:
    const std::string _name; // Nom du bureaucrate
    int _grade; // Grade du bureaucrate
};

// Surcharge de l'opérateur <<
std::ostream &operator<<(std::ostream &out, const Bureaucrat &b);

#endif
