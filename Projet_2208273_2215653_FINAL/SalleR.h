#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "Piece.h"
using namespace std;

class SalleR : public Piece {
public:
    SalleR() : tache_("Tache", "Il y a une tache rouge, on dirait du sang.", "Vous touchez la tache, le sang est encore frais") {
        objetInteractifs_.push_back(tache_);
    }

    void afficherDescription() const override {
        cout << "?¿?¿? Salle Secrete ?¿?¿?\n"
            "Vous êtes dans une piece secrete. Tout les murs sont rouges\n"
            "Couloir est à l'ouest (O)\n";
    }

    int changerDirectionValide(const string& direction) const override {
        if (direction == "O") {
            cout << "Nous allons a l'Ouest." << endl;
            return 2;
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
                    boutonRougeAppuye_ = true;
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
    ObjetInteractif tache_;
    vector<ObjetInteractif> objetInteractifs_;
};
