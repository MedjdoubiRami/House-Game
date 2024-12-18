#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "Piece.h"
using namespace std;

class Couloir : public Piece {
public:
    Couloir() : fleur("Fleur", "C'est une rose", "Vous la sentez, elle sent tres bon") {
        objetInteractifs_.push_back(fleur);
    }

    void afficherDescription() const override {
        cout << "-- Couloir --\n"
            "Cuisine est au nord (N)\n"
            "Petite chambre est à l'ouest (O)\n"
            "Entrée est au sud (S)\n"
            "Vous voyez : \n";
            fleur.afficherNom();
        if (Piece::boutonRougeAppuye()) {
            cout << "Piece Secrete est à l'est(E)\n";
        }
    }
    int changerDirectionValide(const string& direction) const override {
        if (direction == "S") {
            cout << "Nous allons au Sud." << endl;
            return 0;
        }
        if (direction == "N") {
            cout << "Nous allons au Nord." << endl;
            return 4;
        }
        if (direction == "O") {
            cout << "Nous allons a l'Ouest." << endl;
            return 3;
        }
        if (direction == "E") {
            if (Piece::boutonRougeAppuye()) {
                cout << "Nous allons a l'Est." << endl;
                return 5;
            }
            else {
                cout << "Impossible d'aller dans cette direction." << endl;
                return -1;
            }
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

    void lookObjet(const string& nomObjet) const override {
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
    ObjetInteractif fleur;
    vector<ObjetInteractif> objetInteractifs_;

};