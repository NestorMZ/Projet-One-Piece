#include <iostream>
#include <vector>
#include "Carte.h"
#include "Joueur.h"

using namespace std;


Joueur::Joueur() : name("Inconnu"), points_vie(100), liste_cartes(NULL)
{

}

Joueur::Joueur(std::string nom) : name(nom), points_vie(100), liste_cartes(NULL)
{

}

Joueur::Joueur(std::string nom,Liste cartes) : name(nom), points_vie(100), liste_cartes(cartes)
{

}

std::string Joueur::getName() const
{
	return name;
}

void Joueur::setName(std::string nom)
{
	name = nom;
}

int Joueur::getPV() const
{
	return points_vie;
}

void Joueur::setPV()
{
	points_vie = 100;
}

void Joueur::dammages()
{
	//points_vie -= //Valeur de la main
}

void Joueur::contreDumbal()
{
	//points_vie = points_vie - 35 - //Valeur de la main : main.valeur ?
}

void ajout_en_tete(Liste* cartes_joueur, Carte* carte){
	Noeud* noeud = new Noeud;
	noeud->p_suivante = (*cartes_joueur);
	noeud->p_maCarte = carte;
	(*cartes_joueur) = noeud; 
}

void Joueur::piocher(std::vector<Carte*>& Pile){
	Carte* carte = Pile[Pile.size()-1];
	ajout_en_tete(&(liste_cartes), carte);
	Pile.pop_back();
}

void Joueur::afficher_main() const{
	Noeud* noeud = liste_cartes;
	while(noeud!=NULL){
		noeud->p_maCarte->affiche();
		noeud = noeud -> p_suivante;
	}
}