#pragma once
#include <fstream>
#include "bibliotheque_cours.hpp"
#include <vector>
#include "Piece.h"
#include "Cuisine.h"
#include "Salon.h"
#include <algorithm>
#include <iostream>
#include "PetiteChambre.h"
#include "PetiteChambre.h"
#include "SalleR.h"
#include "Entree.h"
#include "Couloir.h"
#include "ObjetInteractif.h"
#include <string>

class Jeu {
public:
	Jeu() {
		pieces_.push_back(make_unique<Entree>());
		pieces_.push_back(make_unique<Salon>());
		pieces_.push_back(make_unique<Couloir>());
		pieces_.push_back(make_unique<PetiteChambre>());
		pieces_.push_back(make_unique<Cuisine>());
		pieces_.push_back(make_unique<SalleR>());
	};
	void affichageDepart() {
		cout << ">>> INF1015 DUNGEON CRAWLER 2023 <<< \n";
		cout << " > >  GAME OF THE YEAR EDITION  < < \n\n\n";

		auto& pieceActuelle1 = pieces_[pieceActuelle_];
		pieceActuelle1->afficherDescription();
	}
	void demarrer() {
		affichageDepart();
		while (true) {
			auto& pieceActuelle = pieces_[pieceActuelle_];
			if (look_) {
				pieceActuelle->afficherDescription();
				look_ = false;
			}

			string commande;
			cout << "> ";
			getline(cin, commande);

			if (commande == "exit") {
				pieces_.clear();
				exitGame();
			}
			if (commande.substr(0, 4) == "look") {
				if (commande.size() == 4) {
					look_ = true;
				}
				else {
					string objet = commande.substr(5);
					pieceActuelle->lookObjet(objet);
					look_ = true;
				}
				cout << "\n";
			}
			else if (commande.substr(0, 3) == "use") {
				string objet = commande.substr(4);
				pieceActuelle->utiliserObjet(objet);
				look_ = true;
			}
			else {
				cout << "\n";
				auto& pieceActuelle = pieces_[pieceActuelle_];
				int nouvelleSalle = pieceActuelle->changerDirectionValide(commande);

				if (nouvelleSalle != -1) {
					pieceActuelle_ = nouvelleSalle;
					look_ = true;
				}
			}
		}
	}
	void exitGame() {
		cout << "Merci, bonne journee!" << std::endl;
		ofstream out("nul");
		streambuf* coutbuf = std::cout.rdbuf();
		cout.rdbuf(out.rdbuf());
		exit(0);
	}
private:
	int pieceActuelle_ = 0;
	bool look_ = false;
	vector<unique_ptr<Piece>> pieces_;
};
