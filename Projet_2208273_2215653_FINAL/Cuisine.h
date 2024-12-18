#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "Piece.h"
using namespace std;

class Cuisine : public Piece {
public:
    Cuisine() : pizza("Pizza", "C'est une pizza pourrie", "Vous mangez une pointe, vous vomissez par terre") {
        objetInteractifs_.push_back(pizza);
    }

    void afficherDescription() const override {
        cout << "-- Cuisine --\n"
            "Vous etes dans la cuisine. Ca pue.\n"
            "Vous voyez : \n";
        pizza.afficherNom();
        cout << "Couloir est au sud (S)\n";
    }
    int changerDirectionValide(const string& direction) const override {
        if (direction == "S") {
            cout << "Nous allons au Sud." << endl;
            return 2;
        }
        if (direction == "N") {
            cout << "Impossible d'aller dans cette direction." << endl;
            return -1;
        }
        if (direction == "E") {
            cout << "Impossible d'aller dans cette direction." << endl;
            return -1;
        }
        if (direction == "O") {
            cout << "Impossible d'aller dans cette direction." << endl;
            return -1;
        }
        else {
            cout << "Je ne connais pas ca" << endl;
            return -1;
        }
    }

    void utiliserObjet(const string& nomObjet) override {
        for (int i = 0; i < objetInteractifs_.size(); i++) {
            if (nomObjet == objetInteractifs_[i].getNom()) {
                objetInteractifs_[i].interagir();
                cout << endl;
                return;
            }
        }
        cout << "Objet non reconnu." << endl << endl;
    }

    void lookObjet(const std::string& nomObjet) const override {
        for (const auto& objet : objetInteractifs_) {
            if (nomObjet == objet.getNom()) {
                objet.afficherDescription();
                return;
            }
        }
        std::cout << "Objet non reconnu." << std::endl;
    }

    vector<ObjetInteractif> getObjetInteractifs() override {
        return objetInteractifs_;
    }

private:
    ObjetInteractif pizza;
    vector<ObjetInteractif> objetInteractifs_;
};
