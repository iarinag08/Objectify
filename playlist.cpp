#include "playlist.hpp"

Playlist::Playlist(const std::string& _nume) : nume(_nume) {}

void Playlist::addPiesa(const Piesa& piesa) { piese.push_back(piesa); }

Playlist Playlist::generateMix(const std::string& numeArtist) const {
    Playlist mix("Mix exclusiv: " + numeArtist);
    for (const auto& piesa : piese) {
        if (piesa.getArtist().getNume() == numeArtist) {
            mix.addPiesa(piesa);
        }
    }
    if (mix.piese.empty()) throw ArtistNecunoscutException();
    return mix;
}

std::string Playlist::durataFormat() const {
    int totalsec = 0;
    for (const auto& piesa : piese) totalsec += piesa.getDurata();
    if (totalsec == 0) return "0s";
    int ore = totalsec / 3600;
    int min = (totalsec % 3600) / 60;
    int sec = totalsec % 60;
    std::string rez = "";
    if (ore > 0) rez += std::to_string(ore) + "h ";
    if (min > 0 || ore > 0) rez += std::to_string(min) + "m ";
    rez += std::to_string(sec) + "s";
    return rez;
}

std::ostream& operator<<(std::ostream& os, const Playlist& p) {
    os << p.nume << " (Durata: " << p.durataFormat() << ")\n";
    if (p.piese.empty()) os << "[Playlist gol]\n";
    else {
        for (size_t i = 0; i < p.piese.size(); ++i)
            os << " " << i + 1 << ". " << p.piese[i] << "\n";
    }
    return os;
}