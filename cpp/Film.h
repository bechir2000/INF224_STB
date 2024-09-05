#ifndef FILM_H_
#define FILM_H_

#include "Video.h"
#include <string>

/**
 * @class Film
 * @brief Represents a film, which is a specific type of video with chapters.
 *
 * This class extends the Video class and adds chapter information to represent
 * different sections in a film.
 */

class Film: public Video {
protected:
	int num_chap {};
	int* chap = nullptr;

public:
	/**
	 * @brief Default constructor for Film class.
	 */
	Film():Video(), num_chap(0), chap(nullptr){};

	/**
	 * @brief Parameterized constructor for Film class.
	 * @param name The name of the film.
	 * @param path The file name of the film.
	 * @param duree The duration of the film in minutes.
	 * @param tab An array representing the chapters of the film.
	 * @param taille The number of chapters in the film.
	 */
	Film(const std::string& name, const std::string& path, int duree, int taille, int tab[])
	:Video(name, path, duree), num_chap(taille)
	{
		if(taille>0){
			this->chap = new int[taille];
			for(int i=0; i<taille; i++){
				chap[i] = tab[i];
			}
		}
		else{
			chap = nullptr;
		}
	}

    /**
     * @brief Gets the array representing the chapters of the film.
     * @return A constant pointer to the array of chapters.
     */
	int* get_chap() const {return chap;}

	int get_num() const {return num_chap;}

    /**
     * @brief Sets the chapters of the film with a new array and size.
     * @param tab The new array representing the chapters.
     * @param taille The new number of chapters in the film.
     */
	void set_chap(int taille, int tab[]){
		this->num_chap = taille;
		if(taille>0) {
			if(chap)
				delete[] chap;
			chap = new int[taille];
			num_chap = taille;
			for(int i=0; i<taille; i++){
				chap[i] = tab[i];
			}
		}
		else
			throw std::invalid_argument("taille invalide pour chapitres!");
	}

    /**
     * @brief Overrides the print function from the Video class to include
     * chapter information.
     * @param output The output stream to write the information to.
     * @return A reference to the output stream.
     */
	virtual std::ostream& afficher(std::ostream& output) const override{
		Video::afficher(output)<< "Chapitres:\n";
		for(int i=0 ; i<num_chap;i++){
			if(chap[i] != 0){
				output << "\tchapitre" << i+1 << ": " << chap[i] << "min, \n" ;
			}
		}
		return output;
	    }

	/**
	 * @brief Destructor for Film class.
	 */

	virtual ~Film(){delete [] chap;}
};

#endif
