#pragma once
#include <string>
#include <iostream>
using namespace std;

class ObjetInteractif {
public:
    ObjetInteractif() = default;

    ObjetInteractif(const string& nom, const string& description, const string& interaction)
        : nom_(nom), description_(description), interaction_(interaction) {}

    void afficherNom() const {
        cout << "   Un(e) " << nom_ << endl;
    }
    void afficherDescription() const {
        cout << description_ << endl;
    }
    void interagir() const {
        cout << interaction_ << endl;
    }
    string getNom() const {
        return nom_;
    }

private:
    string nom_;
    string description_;
    string interaction_;
};
