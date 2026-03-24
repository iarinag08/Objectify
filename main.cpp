#include <iostream>
#include <array>
#include <chrono>
#include <thread>

//#include <SFML/Graphics.hpp>

#include "include/Example.h"
// This also works if you do not want `include/`, but some editors might not like it
// #include "Example.h"

//////////////////////////////////////////////////////////////////////
/// This class is used to test that the memory leak checks work as expected even when using a GUI
class SomeClass {
public:
    explicit SomeClass(int) {}
};

SomeClass *getC() {
    return new SomeClass{2};
}
//////////////////////////////////////////////////////////////////////
class Artist
{

private:
    std::string nume;
    int ascultatori;

public:
    Artist(const std::string& _nume = "Unknown", int _ascultatori = 0)
        : nume(_nume), ascultatori(_ascultatori) {}

    const std::string& getNume() const { return nume; }

    friend std::ostream& operator<<(std::ostream& os, const Artist& a)
    {
        os << a.nume << " (" << a.ascultatori << " ascultatori lunari)";
        return os;
    }

};
class Piesa
{
private:
    std::string titlu;
    int durata;
    Artist artist;
public:
    Piesa(const std::string& _titlu = "fara titlu", int _durata = 0,const Artist& _artist = Artist())
        : titlu(_titlu), durata(_durata), artist(_artist) {}

    int getDurata() const { return durata;}
    const Artist getArtist() const { return artist;}

    friend std::ostream& operator<<(std::ostream& os, const Piesa& p)
    {
        os<< p.titlu << " " << p.artist.getNume() << " " << p.durata << "s";
        return os;
    }
};

class Playlist
{
private:
    std::string nume;
    std::vector<Piesa> piese;
public:
    Playlist(const std::string& _nume = "Playlist nou")
        : nume(_nume) {}

    Playlist(const Playlist& other)
        : nume(other.nume), piese(other.piese)
    {
        std::cout << nume << "\n";
    }
    Playlist& operator=(const Playlist& other)
    {
        if (this != &other)
        {
            nume = other.nume;
            piese = other.piese;
            std::cout << nume << "\n";
        }
        return *this;
    }

    ~Playlist() {}

    void addPiesa(const Piesa& piesa)
    {
        piese.push_back(piesa);
    }

    Playlist generateMix(const std::string& numeArtist) const
    {
        Playlist mix("Mix exclusiv: " +numeArtist);
        for (const auto& piesa: piese)
        {
            if (piesa.getArtist().getNume() == numeArtist)
            {
                mix.addPiesa(piesa);
            }
        }
        return mix;
    }

    std::string durataFormat() const
    {
        int totalsec = 0;
        for (const auto& piesa : piese)
        {
            totalsec += piesa.getDurata();
        }
        int ore = totalsec / 3600;
        int min = (totalsec % 3600) / 60;
        int sec = totalsec % 60;

        std::string rez = "";
        if (ore > 0) rez += std::to_string(ore) + "h ";
        if (min > 0 || ore > 0) rez += std::to_string(min) + "m ";
        rez += std::to_string(sec) + "s";
        return rez.empty() ? "0s" : rez;
    }

    friend std::ostream& operator<<(std::ostream& os, const Playlist& p)
    {
        os << "Playlist: " << p.nume << " (Durata: " << p.durataFormat() << ") \n";
        if (p.piese.empty())
        {
            os << "[Playlist gol]\n";
            return os;
        }
        for (size_t i = 0; i<p.piese.size(); ++i)
        {
            os << " " << i + 1 << ". " << p.piese[i] << "\n";
        }
        return os;
    }
};

class Album
{
private:
    std::string titlu;
    int anlansare;
    Playlist tracklist;

public:
    Album(const std::string& _titlu, int _an, const Playlist& _tracklist)
        : titlu(_titlu), anlansare(_an), tracklist(_tracklist) {}

    friend std::ostream& operator<<(std::ostream& os, const Album& a)
    {
        os << "Album: " << a.titlu << " *" << a.anlansare << " *\n" << a.tracklist;
        return os;
    }

};

int main() {

    std::string numeAscultator;
    std::cout << "Introduceti numele";
    std::cin >> numeAscultator;
    std::cout << "\nSalut, " << numeAscultator << "! Aceasta este biblioteca ta muzicala: \n";

    //artisti
    Artist a1("Irina Rimes", 1500000);
    Artist a2("Taylor Swiift", 10000000);

    //piese
    Piesa p1("Cosmos", 360, a1);
    Piesa p2("Bolnavi amandoi", 340, a1);
    Piesa p3("All too well", 600, a2);
    Piesa p4("False God", 400, a2);

    //playlist
    Playlist playlistchill("Chill mix");
    playlistchill.addPiesa(p1);
    playlistchill.addPiesa(p2);
    playlistchill.addPiesa(p3);
    playlistchill.addPiesa(p4);

    std::cout<< playlistchill << "\n";

    Playlist mixIrina = playlistchill.generateMix("Irina Rimes");
    std::cout << mixIrina << "\n";



    // std::cout << "Hello, world!\n";
    // Example e1;
    // e1.g();
    // std::array<int, 100> v{};
    // int nr;
    // std::cout << "Introduceți nr: ";
    /////////////////////////////////////////////////////////////////////////
    /// Observație: dacă aveți nevoie să citiți date de intrare de la tastatură,
    /// dați exemple de date de intrare folosind fișierul tastatura.txt
    /// Trebuie să aveți în fișierul tastatura.txt suficiente date de intrare
    /// (în formatul impus de voi) astfel încât execuția programului să se încheie.
    /// De asemenea, trebuie să adăugați în acest fișier date de intrare
    /// pentru cât mai multe ramuri de execuție.
    /// Dorim să facem acest lucru pentru a automatiza testarea codului, fără să
    /// mai pierdem timp de fiecare dată să introducem de la zero aceleași date de intrare.
    ///
    /// Pe GitHub Actions (bife), fișierul tastatura.txt este folosit
    /// pentru a simula date introduse de la tastatură.
    /// Bifele verifică dacă programul are erori de compilare, erori de memorie și memory leaks.
    ///
    /// Dacă nu puneți în tastatura.txt suficiente date de intrare, îmi rezerv dreptul să vă
    /// testez codul cu ce date de intrare am chef și să nu pun notă dacă găsesc vreun bug.
    /// Impun această cerință ca să învățați să faceți un demo și să arătați părțile din
    /// program care merg (și să le evitați pe cele care nu merg).
    ///
    /////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////
    /// Pentru date citite din fișier, NU folosiți tastatura.txt. Creați-vă voi
    /// alt fișier propriu cu ce alt nume doriți.
    /// Exemplu:
    /// std::ifstream fis("date.txt");
    /// for(int i = 0; i < nr2; ++i)
    ///     fis >> v2[i];
    ///
    ///////////////////////////////////////////////////////////////////////////

    // SomeClass *c = getC();
    // std::cout << c << "\n";
    // delete c;  // comentarea acestui rând ar trebui să ducă la semnalarea unui mem leak

    /**
    sf::RenderWindow window;
    ///////////////////////////////////////////////////////////////////////////
    /// NOTE: sync with env variable APP_WINDOW from .github/workflows/cmake.yml:31
    window.create(sf::VideoMode({800, 700}), "My Window", sf::Style::Default);
    ///////////////////////////////////////////////////////////////////////////
    std::cout << "Fereastra a fost creata\n";
    ///////////////////////////////////////////////////////////////////////////
    /// NOTE: mandatory use one of vsync or FPS limit (not both)            ///
    /// This is needed so we do not burn the GPU                            ///
    window.setVerticalSyncEnabled(true);                                    ///
    /// window.setFramerateLimit(60);                                       ///
    ///////////////////////////////////////////////////////////////////////////

    while(window.isOpen()) {
        bool shouldExit = false;

        while(const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
                std::cout << "Fereastra a fost închisă\n";
            }
            else if (event->is<sf::Event::Resized>()) {
                std::cout << "New width: " << window.getSize().x << '\n'
                          << "New height: " << window.getSize().y << '\n';
            }
            else if (event->is<sf::Event::KeyPressed>()) {
                const auto* keyPressed = event->getIf<sf::Event::KeyPressed>();
                std::cout << "Received key " << (keyPressed->scancode == sf::Keyboard::Scancode::X ? "X" : "(other)") << "\n";
                if(keyPressed->scancode == sf::Keyboard::Scancode::Escape) {
                    shouldExit = true;
                }
            }
        }
        if(shouldExit) {
            window.close();
            std::cout << "Fereastra a fost închisă (shouldExit == true)\n";
            break;
        }
        using namespace std::chrono_literals;
        std::this_thread::sleep_for(300ms);

        window.clear();
        window.display();
    }
    */

    std::cout << "Programul a terminat execuția\n";
    return 0;
}
