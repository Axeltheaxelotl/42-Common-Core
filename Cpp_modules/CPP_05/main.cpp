#include "Bureaucrat.hpp"
#include <iostream>

int main() 
{
    try 
    {
        // Créer un Bureaucrat avec un grade valide
        Bureaucrat bob("Bob", 2);
        std::cout << bob << std::endl;
        // Incrémenter le grade
        bob.incrementGrade();
        std::cout << bob << std::endl;
        // Incrémenter le grade au-delà de la limite, devrait lever une exception
        bob.incrementGrade();
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    try 
    {
        // Créer un Bureaucrat avec un grade valide
        Bureaucrat alice("Alice", 149);
        std::cout << alice << std::endl;
        // Décrémenter le grade
        alice.decrementGrade();
        std::cout << alice << std::endl;
        // Décrémenter le grade au-delà de la limite, devrait lever une exception
        alice.decrementGrade();
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
