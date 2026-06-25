#ifndef UTILIZATOR_HPP
#define UTILIZATOR_HPP

#include "abonament.hpp"
#include <string>
#include <vector>

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

class PlatformaMuzica {
private:
    std::vector<Utilizator> utilizatori;
    PlatformaMuzica() = default;
public:
    PlatformaMuzica(const PlatformaMuzica&) = delete;
    PlatformaMuzica& operator=(const PlatformaMuzica&) = delete;

    static PlatformaMuzica& getInstance();
    void adaugaUtilizator(const Utilizator& u);
    void afiseazaTot() const;
};

#endif