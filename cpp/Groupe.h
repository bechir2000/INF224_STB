#ifndef GROUPE_H_
#define GROUPE_H_

#include <list>
#include <memory>
#include "Multimedia.h"

using namespace std;

using MultimediaPtr = shared_ptr<Multimedia>;

class Groupe : public list<MultimediaPtr> {
protected:
    string nom;

public:
    Groupe(const string& nom) : nom(nom) {}

    string get_name() const {
        return nom;
    }

    ostream& afficher(ostream &f) const {
        string s = "Groupe " + nom +" : ";
        f<< "Groupe " << nom << "-------------";
        for (auto& objet : *this) {
            objet->afficher(f);
            f<<"---------------";
        }
        return f;
    }
};

#endif
