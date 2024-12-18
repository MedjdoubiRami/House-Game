#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "Piece.h"
using namespace std;

class Entree : public Piece {
public:
    Entree() : tapis("Tapis", "C'est un tres vieux tapis", "Vous essuyez vos souliers sur le tapis") {
        objetInteractifs_.push_back(tapis);
    }

    void afficherDescription() const override {
        cout << "-- Entree --\n"
            "Vous êtes dans l'entrée. Il y a un tapis sur le sol.\n"
            "Vous voyez : \n";
        tapis.afficherNom();
        cout << "Couloir est au nord (N)\n"
            "Salon est à l'est (E)\n";
    }

    int changerDirectionValide(const string& direction) const override {
        if (direction == "E") {
            cout << "Nous allons a l'Est." << endl;
            return 1;
        }
        if (direction == "N") {
            cout << "Nous allons au Nord." << endl;
            return 2;
        }
        if (direction == "S") {
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
        cout << "Objet non reconnu." << endl;
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
    ObjetInteractif tapis;
    vector<ObjetInteractif> objetInteractifs_;
};