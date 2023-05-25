#include "head.h"

string Contact::getNume()
{
    return nume;
}

TipContact Prieten::getTip()
{
    return PRIETEN;
}

string Prieten::getDataNastere()
{
    return dataNastere;
}

string Prieten::getNumarTelefon() 
{
    return numarTelefon;
}

string Prieten::getAdresa() 
{
    return adresa;
}

TipContact Cunoscut::getTip() 
{
    return CUNOSCUT;
}

string Cunoscut::getNumarTelefon() 
{
    return numarTelefon;
}

TipContact Coleg::getTip() 
{
    return COLEG;
}

string Coleg::getNumarTelefon() 
{
    return numarTelefon;
}

string Coleg::getFirma() 
{
    return firma;
}

string Coleg::getAdresa() 
{
    return adresa;
}

Agenda::~Agenda()
{
    for (auto contact : contacte)
    {
        delete contact;
    }
}

void Agenda::adaugaContact(Contact* contact)
{
    contacte.push_back(contact);
}

Contact* Agenda::cautaContact(string nume)
{
    for (auto contact : contacte)
    {
        if (contact->getNume() == nume)
        {
            return contact;
        }
    }
    return nullptr;
}

vector<Prieten*> Agenda::getPrieteni()
{
    vector<Prieten*> prieteni;
    for (auto contact : contacte)
    {
        if (contact->getTip() == PRIETEN)
        {
            prieteni.push_back(static_cast<Prieten*>(contact));
        }
    }
    return prieteni;
}

void Agenda::stergeContact(string nume)
{
    for (auto it = contacte.begin(); it != contacte.end(); ++it)
    {
        if ((*it)->getNume() == nume)
        {
            delete* it;
            contacte.erase(it);
            break;
        }
    }
}