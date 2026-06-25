#include "utilizator.hpp"
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

    if (const auto* af = dynamic_cast<const AbonamentFamily*>(tipAbonament)) {
        std::cout << " -> Info: Cost per membru: " << tipAbonament->calculeazaPret() / af->getNrMembri() << " EUR.\n";
    }
}

int Utilizator::getTotalUtilizatori() { return totalUtilizatori; }

PlatformaMuzica& PlatformaMuzica::getInstance() {
    static PlatformaMuzica instance;
    return instance;
}

void PlatformaMuzica::adaugaUtilizator(const Utilizator& u) {
    utilizatori.push_back(u);
}

void PlatformaMuzica::afiseazaTot() const {
    std::cout << "\n--- UTILIZATORI PLATFORMA ---\n";
    for (const auto& u : utilizatori) {
        u.afiseazaSituatieFinanciara();
    }
}