#include <iostream>
#include "playlist.hpp"
#include "utilizator.hpp"
#include "abonament.hpp"
#include "exceptions.hpp"
#include "artist.hpp"
#include "piesa.hpp"


int main() {
    try {
        std::string numeAscultator;
        std::cout << "Introduceti numele tau: ";
        std::cin >> numeAscultator;

        Artist a1("Irina Rimes", 1500000);
        Artist a2("Taylor Swift", 100000000);

        Piesa p1("Cosmos", 210, a1);
        Piesa p2("Bolnavi amandoi", 205, a1);
        Piesa p3("All Too Well", 613, a2);

        Playlist chill("My Chill Mix");
        chill.addPiesa(p1);
        chill.addPiesa(p2);
        chill.addPiesa(p3);

        std::cout << "\n" << chill << "\n";
        Playlist mixTaylor = chill.generateMix("Taylor Swift");
        std::cout << mixTaylor << "\n";

        Utilizator u1(numeAscultator, AbonamentPremium());
        Utilizator u2("Maria", AbonamentFamily(4));

        u1.afiseazaSituatieFinanciara();
        u2.afiseazaSituatieFinanciara();

        std::cout << "\nTotal utilizatori in aplicatie: " << Utilizator::getTotalUtilizatori() << "\n";


        AbonamentFamily abEroare(10);

    }
    catch (const MusicAppException& e) {
        std::cerr << "\n[EROARE SPECIFICA] " << e.what() << "\n";
    }
    catch (const std::exception& e) {
        std::cerr << "\n[EROARE SISTEM] " << e.what() << "\n";
    }

    std::cout << "\nProgramul s-a incheiat.\n";
    return 0;
}
