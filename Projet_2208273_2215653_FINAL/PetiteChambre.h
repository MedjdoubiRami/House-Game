#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "Piece.h"
using namespace std;

class PetiteChambre : public Piece {
public:
    PetiteChambre() : interrupteur("Interrupteur", "Un 'Interrupteur' de lumiere", "Vous appuyez sur l'interrupteur, la salle est maintenant illuminee"), lit("Lit", "Le 'Lit' a l'air tres inconfortable", "Vous vous couchez sur le lit et vous vous endormez") {
        objetInteractifs_.push_back(interrupteur);
        objetInteractifs_.push_back(lit);
    }

    void afficherDescription() const override {
        cout << "-- Chambre --\n";
        if (lumiere_ == false) {
            cout << "Il fait trop noir pour voir, vous discernez un 'Interrupteur' \n"
                "Couloir est à l'est (E)\n";
        }
        if (lumiere_) {
            cout << "Vous êtes dans une petite chambre. Vous voulez dormir.\n"
                "Vous voyez : \n";
            lit.afficherNom();
            interrupteur.afficherNom();
            cout << "Couloir est à l'est (E)\n";
        }
    }
    int changerDirectionValide(const string& direction) const override {
        if (direction == "E") {
            cout << "Nous allons a l'Est." << endl;
            return 2;
        }
        if (direction == "N") {
            cout << "Impossible d'aller dans cette direction." << endl;
            return -1;
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
        for (const auto& objet : objetInteractifs_) {
            if (nomObjet == objet.getNom()) {
                objet.interagir();
                if (objet.getNom() == "Interrupteur") {
                    lumiere_ = true;
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
        std::cout << "Objet non reconnu." << std::endl;
    }
    vector<ObjetInteractif> getObjetInteractifs() override {
        return objetInteractifs_;
    }
private:
    ObjetInteractif lit;
    ObjetInteractif interrupteur;
    bool lumiere_ = false;
    vector<ObjetInteractif> objetInteractifs_;
};