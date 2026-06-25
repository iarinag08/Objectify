#include "abonament.hpp"
#include "artist.hpp"
#include "piesa.hpp"
#include "playlist.hpp"
#include "utilizator.hpp"
#include <iostream>

int main() {
    Abonament* ab1 = AbonamentFactory::creareAbonament("Premium");
    Abonament* ab2 = AbonamentFactory::creareAbonament("Family", 4);

    Utilizator u1("Alexandru", *ab1);
    Utilizator u2("Maria", *ab2);

    PlatformaMuzica::getInstance().adaugaUtilizator(u1);
    PlatformaMuzica::getInstance().adaugaUtilizator(u2);
    PlatformaMuzica::getInstance().afiseazaTot();

    Artist a1("The Weeknd", 110000000);
    Artist a2("Daft Punk", 40000000);

    Piesa p1("Starboy", 230, a1);
    Piesa p2("Get Lucky", 248, a2);

    std::cout << "\n--- CATALOG ARTISTI (Instantiere 1 Template Class) ---\n";
    Catalog<Artist> catalogArtisti;
    catalogArtisti.adauga(a1);
    catalogArtisti.adauga(a2);
    catalogArtisti.afiseazaCatalog();

    std::cout << "\n--- CATALOG PIESE (Instantiere 2 Template Class) ---\n";
    Catalog<Piesa> catalogPiese;
    catalogPiese.adauga(p1);
    catalogPiese.adauga(p2);
    catalogPiese.afiseazaCatalog();

    playItem(p1);

    Playlist playlistVara("Vara 2026");
    playlistVara.addPiesa(p1);
    playlistVara.addPiesa(p2);

    playItem(playlistVara);

    delete ab1;
    delete ab2;

    return 0;
}