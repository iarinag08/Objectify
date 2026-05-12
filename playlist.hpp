#ifndef PLAYLIST_HPP
#define PLAYLIST_HPP

#include "Piesa.hpp"
#include "Exceptions.hpp"
#include <vector>
#include <string>

class Playlist {
private:
    std::string nume;
    std::vector<Piesa> piese;
public:
    explicit Playlist(const std::string& _nume = "Playlist nou");
    void addPiesa(const Piesa& piesa);
    Playlist generateMix(const std::string& numeArtist) const;
    std::string durataFormat() const;
    friend std::ostream& operator<<(std::ostream& os, const Playlist& p);
};

#endif