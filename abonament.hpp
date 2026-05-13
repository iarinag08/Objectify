#ifndef ABONAMENT_HPP
#define ABONAMENT_HPP

#include <string>
#include <iostream>
#include "exceptions.hpp"

class Abonament {
protected:
    std::string cod;
public:
    explicit Abonament(const std::string& _cod);
    virtual ~Abonament() = default;
    virtual Abonament* clone() const = 0;
    virtual double calculeazaPret() const = 0;
    void afisare(std::ostream& os) const;
protected:
    virtual void print(std::ostream& os) const = 0;
};

class AbonamentPremium : public Abonament {
public:
    AbonamentPremium();
    Abonament* clone() const override;
    double calculeazaPret() const override;
protected:
    void print(std::ostream& os) const override;
};

class AbonamentFamily : public Abonament {
private:
    int nrMembri;
public:
    explicit AbonamentFamily(int membri);
    int getNrMembri() const;
    Abonament* clone() const override;
    double calculeazaPret() const override;
protected:
    void print(std::ostream& os) const override;
};

class AbonamentFree : public Abonament {
public:
    AbonamentFree();
    Abonament* clone() const override;
    double calculeazaPret() const override;
protected:
    void print(std::ostream& os) const override;
};

class AbonamentStudent : public Abonament {
public:
    AbonamentStudent();
    Abonament* clone() const override;
    double calculeazaPret() const override;
protected:
    void print(std::ostream& os) const override;
};

#endif