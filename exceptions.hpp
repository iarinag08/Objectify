#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP

#include <exception>
#include <string>

class MusicAppException : public std::exception {
protected:
    std::string mesaj;
public:
    explicit MusicAppException(const std::string& m) : mesaj("Eroare Aplicatie Muzica: " + m) {}
    const char* what() const noexcept override { return mesaj.c_str(); }
};

class MembriInvaliziException : public MusicAppException {
public:
    MembriInvaliziException() : MusicAppException("Numar de membri invalid pentru abonamentul Family (min 2, max 6).") {}
};

class PlaylistVidException : public MusicAppException {
public:
    PlaylistVidException() : MusicAppException("Nu se poate reda un playlist care nu are piese.") {}
};

class ArtistNecunoscutException : public MusicAppException {
public:
    ArtistNecunoscutException() : MusicAppException("Artistul cautat nu are piese in acest playlist.") {}
};

#endif