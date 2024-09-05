#include <iostream>
#include "Base.h"

using namespace std;

int main(int argc, const char* argv[])
{
	int taille = 5;
	int tab[taille] = {1,2,3,4,5};
	/*Film* film = new Film("BB","film.mp4",90,taille, tab);
	film->afficher(cout);

	taille = 3;
	int tab1[taille] = {10,11,12};
	film->set_chap(taille,tab1);
	film->afficher(cout);

	int* tab2 = film->get_chap();
	for(int i=0; i<film->get_num(); i++)
	{
		cout<<tab2[i]<<" ";
	}*/

	MultimediaPtr photo(new Photo("Paris", "photo1.jpg", 50, 72));
	MultimediaPtr video(new Video("Lisbonne", "video.mp4", 90));
	MultimediaPtr film(new Film("BB", "film.mp4", 120, taille,tab));

	 Groupe* g = new Groupe("vacances");
	 g->push_back(photo);
	 g->push_back(video);
	 g->push_back(film);

	 g->afficher(cout);

	 Base* base = new Base();
	 base->ajouterMultimedia(photo);
	 base->ajouterMultimedia(video);
	 base->ajouterMultimedia(film);

	 auto it = base->chercherMultimedia("Lisbonne");
	 it->afficher(cout);

     return 0;
}
