#include "Multimedia.h"

Multimedia::Multimedia() {}
Multimedia::Multimedia(const std::string &name, const std::string &path):name(name),path(path){}

void Multimedia::set_name(const std::string& name){
	this->name = name;
}

void Multimedia::set_path(const std::string& path){
	this->path = path;
}

const std::string& Multimedia::get_name() const {return this->name;}
const std::string& Multimedia::get_path() const {return this->path;}

std::ostream& Multimedia::afficher(std::ostream& f) const {
	f<<"Name: "<<this->name<<"----"<<"Path: "<<this->path<<"----";
	return f;
}

Multimedia::~Multimedia() {}

