#ifndef UTILIZATOR_HPP
#define UTILIZATOR_HPP

#include "Abonament.hpp"
#include <string>

class Utilizator {
private:
    std::string nume;
    Abonament* tipAbonament;
    static int totalUtilizatori;

public:
    Utilizator(const std::string& _nume, const Abonament& _ab);
    ~Utilizator();
    Utilizator(const Utilizator& other);
    Utilizator& operator=(Utilizator other);
    friend void swap(Utilizator& first, Utilizator& second) noexcept;

    void afiseazaSituatieFinanciara() const;
    static int getTotalUtilizatori();
};

#endif