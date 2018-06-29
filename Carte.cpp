#include <iostream>
#include "Carte.h"

using namespace std;

Carte::Carte() : valeur(1), famille(0)
{
	//Le constructeur initialise la carte en As de Coeur
}

Carte::Carte(int val, int fam) : valeur(val), famille(fam)
{
	//Le constructeur initialise la carte avec les parametres rentres
}

int Carte::estRouge() const
{
	return (famille%2)==0;
}

int Carte::estNoire() const
{
	return (famille%2)==1;
}

int Carte::getVal() const
{
	return valeur;
}

int Carte::getFam() const
{
	return famille;
}

void Carte::setVal(int val)
{
	valeur = val;
}

void Carte::setFam(int fam)
{
	famille = fam;
}

int Carte::estUneTete() const
{
	return valeur > 10;
}

void Carte::affiche() const
{
	std::string fam;
	if(famille==0){fam = "Coeur";}
	else if(famille==1){fam = "Pique";}
	else if(famille==2){fam = "Carreau";}
	else{fam = "Trefle";}
	
	if(valeur == 1){
		cout << "As de " << fam << endl;
		return;
	}

	if(valeur < 11){
		cout << valeur << " de " << fam << endl;
		return;
	}
	
	std::string tete;
	if(valeur==11)
		tete = "Valet";
	else if(valeur==12)
		tete = "Dame";
	else 
		tete = "Roi";
	cout << tete << " de " << fam << endl;
}