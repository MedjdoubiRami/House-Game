#pragma once
#include <string>
#include <iostream>
#include "ObjetInteractif.h"
using namespace std;

class Piece {
public:
    Piece() = default;
    virtual ~Piece() = default;
    virtual void afficherDescription() const = 0;
    virtual void utiliserObjet(const string& nomObjet) = 0;
    virtual vector<ObjetInteractif> getObjetInteractifs() = 0;
    virtual void lookObjet(const string& nomObjet) const = 0;
    virtual int changerDirectionValide(const string& direction) const = 0;

    static bool boutonRougeAppuye() {
        return boutonRougeAppuye_;
    }

    static void setBoutonRougeAppuye(bool value) {
        boutonRougeAppuye_ = value;
    }
protected:
    static bool boutonRougeAppuye_;
};

bool Piece::boutonRougeAppuye_ = false;