#include <iostream>
#include <array>
#include <chrono>
#include <thread>
#include <vector>


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
    std::cout << "Introduceti numele: ";
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

    std::cout << "Programul a terminat executia\n";
    return 0;
}
