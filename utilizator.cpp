#include "utilizator.hpp"
#include "abonament.hpp"
#include <iostream>

int Utilizator::totalUtilizatori = 0;

Utilizator::Utilizator(const std::string& _nume, const Abonament& _ab)
    : nume(_nume), tipAbonament(_ab.clone()) {
    totalUtilizatori++;
}

Utilizator::~Utilizator() { delete tipAbonament; }

Utilizator::Utilizator(const Utilizator& other)
    : nume(other.nume), tipAbonament(other.tipAbonament->clone()) {
    totalUtilizatori++;
}

void swap(Utilizator& first, Utilizator& second) noexcept {
    using std::swap;
    swap(first.nume, second.nume);
    swap(first.tipAbonament, second.tipAbonament);
}

Utilizator& Utilizator::operator=(Utilizator other) {
    swap(*this, other);
    return *this;
}

void Utilizator::afiseazaSituatieFinanciara() const {
    std::cout << "Utilizatorul " << nume << ": ";
    tipAbonament->afisare(std::cout);
    std::cout << "\n";

    if (auto* af = dynamic_cast<AbonamentFamily*>(tipAbonament)) {
        std::cout << " -> Info: Cost per membru: " << tipAbonament->calculeazaPret() / af->getNrMembri() << " EUR.\n";
    }
}

int Utilizator::getTotalUtilizatori() { return totalUtilizatori; }