#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

enum TipContact {
    PRIETEN,
    CUNOSTINTA,
    COLEG
};

class Contact {
protected:
    std::string nume;
public:
    Contact(std::string nume) : nume(nume) {}
    virtual ~Contact() {}

    std::string getNume() const {
        return nume;
    }

    virtual TipContact getTip() const = 0;
};

class Prieten : public Contact {
private:
    std::string dataNasterii;
    std::string telefon;
    std::string adresa;
public:
    Prieten(std::string nume, std::string dataNasterii, std::string telefon, std::string adresa)
        : Contact(nume), dataNasterii(dataNasterii), telefon(telefon), adresa(adresa) {}

    TipContact getTip() const override {
        return PRIETEN;
    }
};

class Cunostinta : public Contact {
private:
    std::string telefon;
public:
    Cunostinta(std::string nume, std::string telefon)
        : Contact(nume), telefon(telefon) {}

    TipContact getTip() const override {
        return CUNOSTINTA;
    }
};

class Coleg : public Contact {
private:
    std::string telefon;
    std::string companie;
    std::string adresa;
public:
    Coleg(std::string nume, std::string telefon, std::string companie, std::string adresa)
        : Contact(nume), telefon(telefon), companie(companie), adresa(adresa) {}

    TipContact getTip() const override {
        return COLEG;
    }
};

class Agenda {
private:
    std::vector<Contact*> contacte;
public:
    ~Agenda() {
        for (Contact* contact : contacte) {
            delete contact;
        }
    }

    void adaugaContact(Contact* contact) {
        contacte.push_back(contact);
    }

    Contact* cautaDupaNume(const std::string& nume) {
        for (Contact* contact : contacte) {
            if (contact->getNume() == nume) {
                return contact;
            }
        }
        return nullptr;
    }

    std::vector<Prieten*> listeazaPrieteni() {
        std::vector<Prieten*> prieteni;
        for (Contact* contact : contacte) {
            if (contact->getTip() == PRIETEN) {
                prieteni.push_back(static_cast<Prieten*>(contact));
            }
        }
        return prieteni;
    }

    void stergeDupaNume(const std::string& nume) {
        contacte.erase(std::remove_if(contacte.begin(), contacte.end(),
            [&](Contact* contact) {
                if (contact->getNume() == nume) {
                    delete contact;
                    return true;
                }
                return false;
            }), contacte.end());
    }
};

int main() {
    Agenda agenda;

    agenda.adaugaContact(new Prieten("Ana", "1990-01-01", "555-1234", "Strada Marului 123"));
    agenda.adaugaContact(new Cunostinta("Bogdan", "555-5678"));
    agenda.adaugaContact(new Coleg("Cristi", "555-8765", "Initech", "Strada Portocalelor 456"));

    Contact* gasit = agenda.cautaDupaNume("Ana");
    if (gasit) {
        std::cout << "Gasit: " << gasit->getNume() << std::endl;
    }

    std::vector<Prieten*> prieteni = agenda.listeazaPrieteni();
    std::cout << "Prieteni:" << std::endl;
    for (Prieten* prieten : prieteni) {
        std::cout << prieten->getNume() << std::endl;
    }

    agenda.stergeDupaNume("Bogdan");
    Contact* nuGasit = agenda.cautaDupaNume("Bogdan");
    if (!nuGasit) {
        std::cout << "Bogdan nu a fost gasit in agenda." << std::endl;
    }

    return 0;
}
