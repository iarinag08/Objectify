#include "Piesa.hpp"

Piesa::Piesa(const std::string& _titlu, int _durata, const Artist& _artist)
    : titlu(_titlu), durata(_durata), artist(_artist) {}

int Piesa::getDurata() const { return durata; }
const Artist& Piesa::getArtist() const { return artist; }

std::ostream& operator<<(std::ostream& os, const Piesa& p) {
    os << p.titlu << " | " << p.artist.getNume() << " | " << p.durata << "s";
    return os;
}