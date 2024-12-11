#include "Bureaucrat.hpp"

// Constructeur avec validation du grade
Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name), _grade(grade)
{
    if (grade < 1) {
        throw GradeTooHighException();
    } else if (grade > 150) {
        throw GradeTooLowException();
    }
}

Bureaucrat::~Bureaucrat() {}

// Retourne le nom du bureaucrate
std::string Bureaucrat::getName() const
{
    return _name;
}

// Retourne le grade du bureaucrate
int Bureaucrat::getGrade() const
{
    return _grade;
}

// Diminue le grade, lève une exception si le grade devient trop haut
void Bureaucrat::incrementGrade()
{
    if (_grade <= 1) {
        throw GradeTooHighException();
    }
    _grade--;
}

// Augmente le grade, lève une exception si le grade devient trop bas
void Bureaucrat::decrementGrade()
{
    if (_grade >= 150) {
        throw GradeTooLowException();
    }
    _grade++;
}

// Surcharge de l'opérateur << pour afficher un Bureaucrat
std::ostream &operator<<(std::ostream &out, const Bureaucrat &b)
{
    out << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return out;
}
