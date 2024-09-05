#ifndef BASE_H_
#define BASE_H_

#include <iostream>
#include <map>
#include <memory>
#include <string>
#include <sstream>

#include "Multimedia.h"
#include "Photo.h"
#include "Video.h"
#include "Film.h"
#include "Groupe.h"

using namespace std;

typedef shared_ptr<Multimedia> MultimediaPtr;
typedef shared_ptr<Groupe> GroupePtr;
typedef map<string, MultimediaPtr> MultimediaMap;
typedef map<string, GroupePtr> GroupeMap;

class Base {

private:
    MultimediaMap multimediaTable;
    GroupeMap groupeTable;

public:

    Base(){};
    ~Base();

    MultimediaPtr ajouterPhoto(const string& name, const string& pathname, float lat, float lon) {
        MultimediaPtr photo(new Photo(name, pathname, lat, lon));
        multimediaTable[name] = photo;
        return photo;
    }

    MultimediaPtr ajouterVideo(const string& name, const string& pathname, float d) {
        MultimediaPtr video(new Video(name, pathname, d));
        multimediaTable[name] = video;
        return video;
    }

    MultimediaPtr ajouterFilm(const string& name, const string& pathname, int d, int* chapitres, const int nbChapitres) {
        MultimediaPtr film(new Film(name, pathname, d, nbChapitres, chapitres));
        multimediaTable[name] = film;
        return film;
    }

    void ajouterMultimedia(MultimediaPtr m){
        multimediaTable[m->get_name()]=m;
    }

    GroupePtr ajouterGroupe(string name) {
        GroupePtr group(new Groupe(name));
        groupeTable[name] = group;
        return group;
    }

    GroupePtr ajouterGroupe(GroupePtr g){
        groupeTable[g->get_name()]=g;
        return g;
    }

    MultimediaPtr chercherMultimedia(string name) {
        MultimediaMap::iterator it = multimediaTable.find(name);
        if (it != multimediaTable.end()) {
            return it->second;
        }
        else {
            return nullptr;
        }
    }

    string jouerMultimedia(string name) {
        MultimediaMap::iterator it = multimediaTable.find(name);
        if (it != multimediaTable.end()) {
            it->second->play();
            return "fichier joué";
        }
        else {
            return "Fichier n'est pas trouvé";
        }
    }
    string listerMultimedias() const {
	    std::string resultat = "All multimedias : | ";
	    for(auto m : multimediaTable) {
		resultat += "- Name : "+ m.first + +", Path : " +  m.second->get_path() + " | ";
	    }
	    return resultat;
	}


    GroupePtr chercherGroupe(string name) {
        GroupeMap::iterator it = groupeTable.find(name);
        if (it != groupeTable.end()) {
            return it->second;
        }
        else {
            return nullptr;
        }
    }

    bool gerer(const std::string& request, std::string& response) {

        std::stringstream stream, response_stream;
        stream << request;

        std::string operation, target;
        stream >> operation >> target;

        if(operation == "SEARCH_MULTIMEDIA") {
            MultimediaPtr res = chercherMultimedia(target);
            if(res == nullptr) {
                response = "File with the name '"+ target + "' not found! |";
            }
            else {
                res->afficher(response_stream);
                response = response_stream.str();
            }
        }
        else if(operation == "SEARCH_GROUP") {
            GroupePtr res = chercherGroupe(target);
            if(res == nullptr) {
                response = "No such group! |";
            }
            else {
                res->afficher(response_stream);
                response = response_stream.str();
            }
        }
        else if(operation == "LIST_ALL") {
        response = listerMultimedias();
    }
        else if(operation == "PLAY") {
            MultimediaPtr res= chercherMultimedia(target);
            if(res == nullptr) {
                response = "File with the name '"+ target + "' not found! |";
            }
            else {
                res->play();
                response = target + " playing ... | ";
            }
        }
        else {
            response = "Sorry, unknown request! |";
        }
        std::cerr << "response: " << response << std::endl;
        return true;
    }



};

#endif /* BASE_H_ */
