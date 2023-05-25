#pragma once
#include <iostream>
#include <vector>
using namespace std;

enum TipContact
{
    PRIETEN,
    CUNOSCUT,
    COLEG
};

class Contact
{
private:
    string nume;

public:
    Contact(string nume) : nume(nume) {}
    virtual ~Contact() {}
    virtual TipContact getTip() = 0;
    string getNume();
};

class Prieten : public Contact
{
private:
    string dataNastere;
    string numarTelefon;
    string adresa;

public:
    Prieten(string nume, string dataNastere, string numarTelefon, string adresa) : Contact(nume), dataNastere(dataNastere), numarTelefon(numarTelefon), adresa(adresa) {}

    TipContact getTip() override;

    string getDataNastere();
    string getNumarTelefon();
    string getAdresa();
};

class Cunoscut : public Contact
{
private:
    string numarTelefon;

public:
    Cunoscut(string nume, string numarTelefon) : Contact(nume), numarTelefon(numarTelefon) {}

    TipContact getTip() override;

    string getNumarTelefon();
};

class Coleg : public Contact
{
private:
    string numarTelefon;
    string firma;
    string adresa;

public:
    Coleg(string nume, string numarTelefon, string firma, string adresa) : Contact(nume), numarTelefon(numarTelefon), firma(firma), adresa(adresa) {}

    TipContact getTip() override;

    string getNumarTelefon();
    string getFirma();
    string getAdresa();
};

class Agenda
{
private:
    vector<Contact*> contacte;

public:
    ~Agenda();


    Contact* cautaContact(string nume);

    vector<Prieten*> getPrieteni();

    void stergeContact(string nume);

    void adaugaContact(Contact* contact);
};