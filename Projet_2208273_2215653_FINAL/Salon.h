#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "Piece.h"
#include "ObjetInteractif.h"
using namespace std;

class Salon : public Piece {
public:

    Salon() : boutonRouge("Bouton rouge", "C'est un 'Bouton rouge' tr�s �trange...", "Vous appuyez sur le bouton rouge. Une nouvelle zone, Salle R, est d�verrouill�e !") {
        objetInteractifs_.push_back(boutonRouge);
    }

    void afficherDescription() const override {
        cout << "-- Salon --\n"
            "Vous �tes dans le salon. La Champions League joue sur la television\n"
            "Vous voyez : \n";
        boutonRouge.afficherNom();
        cout << "Entr�e est � l'ouest (O)\n";
    }

    int changerDirectionValide(const string& direction) const override {
        if (direction == "O") {
            cout << "Nous allons a l'Ouest." << endl;
            return 0;
        }
        if (direction == "N") {
            cout << "Impossible d'aller dans cette direction.." << endl;
            return -1;
        }
        if (direction == "S") {
            cout << "Impossible d'aller dans cette direction." << endl;
            return -1;
        }
        if (direction == "E") {
            cout << "Impossible d'aller dans cette direction." << endl;
            return -1;
        }
        else {
            cout << "Je ne connais pas ca" << endl;
            return -1;
        }
    }

    void utiliserObjet(const string& nomObjet) override {
        for (const auto& objet : objetInteractifs_) {
            if (nomObjet == objet.getNom()) {
                objet.interagir();
                if (objet.getNom() == "Bouton rouge") {
                    Piece::setBoutonRougeAppuye(true);
                }
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
        cout << "Objet non reconnu." << std::endl;
    }

    vector<ObjetInteractif> getObjetInteractifs() override {
        return objetInteractifs_;
    }
private:
    ObjetInteractif boutonRouge;
    vector<ObjetInteractif> objetInteractifs_;
};