#ifndef PIESA_HPP
#define PIESA_HPP

#include "Artist.hpp"
#include <string>

class Piesa {
private:
    std::string titlu;
    int durata;
    Artist artist;
public:
    explicit Piesa(const std::string& _titlu = "fara titlu", int _durata = 0, const Artist& _artist = Artist());
    int getDurata() const;
    const Artist& getArtist() const;
    friend std::ostream& operator<<(std::ostream& os, const Piesa& p);
};

#endif