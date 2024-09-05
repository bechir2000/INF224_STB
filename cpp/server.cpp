//
//  server.cpp
//  TP C++
//  Eric Lecolinet - Telecom ParisTech - 2016.
//

#include <memory>
#include <string>
#include <iostream>
#include <sstream>
#include "tcpserver.h"
#include "Base.h"

const int PORT = 3331;


int main(int argc, char* argv[])
{
	// Creation de la base de donnee
	int taille = 5;
	int tab[taille] = {1,2,3,4,5};
	MultimediaPtr photo(new Photo("Paris", "photo1.jpg", 50, 72));
	MultimediaPtr video(new Video("Lisbonne", "video.mp4", 90));
	MultimediaPtr film(new Film("BB", "film.mp4", 120, taille,tab));

	 GroupePtr g(new Groupe("vacances"));
	 g->push_back(photo);
	 g->push_back(video);
	 g->push_back(film);

	 Base* base = new Base();
	 base->ajouterMultimedia(photo);
	 base->ajouterMultimedia(video);
	 base->ajouterMultimedia(film);
	 base->ajouterGroupe(g);

  // cree le TCPServer
  auto* server =
  new TCPServer( [&](std::string const& request, std::string& response) {

    // the request sent by the client to the server
    std::cout << "request: " << request << std::endl;

    // the response that the server sends back to the client
    base->gerer(request,response);

    // return false would close the connecytion with the client
    return true;
  });


  // lance la boucle infinie du serveur
  std::cout << "Starting Server on port " << PORT << std::endl;

  int status = server->run(PORT);

  // en cas d'erreur
  if (status < 0) {
    std::cerr << "Could not start Server on port " << PORT << std::endl;
    return 1;
  }

  return 0;
}

