#include <iostream>
#include <vector>
#include <string>
#include "Carte.h"
#include "Joueur.h"

using namespace std;

void triBulle(vector<Carte*>& Choix)
{
	bool change = false;
	size_t j=0;
	Carte* tempCarte = NULL;

	while(!change){
		change = true;
		for(size_t i = Choix.size()-1; i > j; --i){
			if(Choix[i]->getVal() < Choix[i-1]->getVal()){//l element le plus petit remonte vers le debut
				tempCarte = Choix[i];
				Choix[i] = Choix[i-1];
				Choix[i-1] = tempCarte;
				change = false;
			}
		}
		j++;
	}
}


int combine_possible(vector<Carte*> Choix)
{
	int nb_cartes = Choix.size();
	cout << nb_cartes << endl;

	if(!nb_cartes){cout << "Choix de cartes vide" << endl; return 0;}
	
	else if(nb_cartes==1)
		return 1;
	else if(nb_cartes==2)
		return Choix[0]->getVal()==Choix[1]->getVal();
	else if(nb_cartes==3)
		return (Choix[0]->getVal()==Choix[1]->getVal() and Choix[0]->getVal()==Choix[2]->getVal());
	else if(nb_cartes==4 and Choix[0]->getVal()==Choix[1]->getVal() and Choix[0]->getVal()==Choix[2]->getVal() and Choix[0]->getVal()==Choix[3]->getVal())
		return 1;
	else{
		triBulle(Choix);
		for(size_t i = 0; i<Choix.size()-1; i++){
			if(Choix[i]->getVal() != Choix[i+1]->getVal()-1 and Choix[i]->sameColor(Choix[i+1]))
				return 0;
		}
		return 1;
	}
	return 0;
}

int stringValide(string reponse, size_t max)
{
	string test = "1";
	size_t cpp = 1;

	if(reponse == test) return 1;
	cpp++;
	if(cpp > max) return 0;

	test = "2";
	if(reponse == test) return 1;
	cpp++;
	if(cpp > max) return 0;

	test = "3";
	if(reponse == test) return 1;
	cpp++;
	if(cpp > max) return 0;

	test = "4";
	if(reponse == test) return 1;
	cpp++;
	if(cpp > max) return 0;

	test = "5";
	if(reponse == test) return 1;
	cpp++;
	if(cpp > max) return 0;

	test = "6";
	if(reponse == test) return 1;
	cpp++;
	if(cpp > max) return 0;

	test = "7";
	if(reponse == test) return 1;
	return 0;
}

int dejaChoisie(vector<int> Ou, int reponse){
	for (size_t i =0; i<Ou.size(); i++){
		if(Ou[i]==0)
			break;
		if(Ou[i]==reponse-48)
			return 1;
	}
	return 0;
}

Joueur::Joueur() : name("Inconnu"), points_vie(100), liste_cartes(NULL)
{

}

Joueur::Joueur(std::string nom) : name(nom), points_vie(100), liste_cartes(NULL)
{

}

Joueur::Joueur(std::string nom,Liste cartes) : name(nom), points_vie(100), liste_cartes(cartes)
{

}

//destructeur
Joueur::~Joueur()
{
	Noeud* temp = liste_cartes;
	while(liste_cartes!=NULL){
		liste_cartes = liste_cartes->p_suivante;
		delete temp->p_maCarte;
		delete temp;
		temp = liste_cartes;
	}
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
	points_vie -= this->getHandPoints();
	if(points_vie < 0)
		points_vie = 0;
}

void Joueur::contreDumbal()
{
	points_vie = points_vie - 35 - this->getHandPoints();
	if(points_vie < 0)
		points_vie = 0;
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

void Joueur::afficher_cartes() const{
	Noeud* noeud = liste_cartes;
	int indice = 1;
	cout << "Indice --- Nom de la carte" << endl;
	while(noeud!=NULL){
		cout << indice << " ->       " ;
		noeud->p_maCarte->affiche();
		noeud = noeud -> p_suivante;
		indice++;
	}
}

int Joueur::getHandPoints() const
{
	int resultat = 0;
	Noeud* noeud = liste_cartes;
	while(noeud!=NULL){
		resultat += noeud->p_maCarte->getPoints();
		noeud = noeud -> p_suivante;
	}
	return resultat;
}

int Joueur::nb_cartes() const
{
	int resultat = 0;
	Noeud* noeud = liste_cartes;
	while(noeud!=NULL){
		resultat ++;
		noeud = noeud -> p_suivante;
	}
	return resultat;
}

void Joueur::recupRempli(std::vector<int> Ou, std::vector<Carte*>& Choix) const
{
	int i=0, stop=0, enCours = 0;
	Noeud* monNoeud = liste_cartes;

	while (!stop){
		if(Ou[i]==0)
			break;
		while(Ou[i]!=enCours+1){
			enCours++;
			monNoeud = monNoeud->p_suivante;
		}
		Choix.push_back(monNoeud->p_maCarte);
		i++;
	}
}

int Joueur::jouer(std::vector<Carte*>& Pile, std::vector<Carte*>& Tas, std::vector<Carte*>& TasTemp)
{	
	string reponse;
	if(this->getHandPoints() < 12){
		cout << "Voulez-vous declencher le Dumbal ?(o/n)" << endl;
		cin >> reponse;
		while(reponse!= "o" and reponse!= "n"){
			cout << "Erreur de saisie, reessayer : ";
			cin >> reponse;
		}
		if(reponse == "o")
			return 1;
	}

	//Initialisations 
	vector<Carte*> Choix; //tableau des cartes defaussées
	int max_cartes = this->nb_cartes();
	int deuxiemeFois=0;

	do{
		int cb_cartes=0;
		while(Choix.size()>0)
			Choix.pop_back();

		vector<int> Ou(8, 0); //tableau d'indices
		if(deuxiemeFois == 1)
			cout << "La combinaison des cartes choisies est impossible, veuillez entrer une combinaison correcte. Essayez a nouveau." << endl;

		this->afficher_cartes(); 
		cout << "Quelle/s carte/s voulez-vous jeter ? (Indiquer l'indice de la premiere carte)" <<endl;
		cin >> reponse;
		while(!stringValide(reponse,max_cartes)){
			cout << "Erreur de saisie, veuillez reessayer" << endl;
			cin >> reponse;
		}

		cout<< "Carte à l'indice " <<  reponse << " selectionnee." << endl ;
		Ou[cb_cartes] = reponse[0] - 48;
		cb_cartes++;

		while (1){
			cout << "Pour ajouter une autre carte, indiquez son indice, sinon mettez 0 : " << endl;
			cin >> reponse;
			if(reponse == "0")
				break;
			while(!stringValide(reponse,max_cartes) or dejaChoisie(Ou, reponse[0])){
				if(reponse == "0")
					break;
				cout << "Erreur de saisie, veuillez reessayer (indice impossible ou deja utilise)" << endl;
				cin >> reponse;
			}
			cout<< "Carte à l'indice " <<  reponse << " selectionnee." << endl ;
			Ou[cb_cartes] = reponse[0] - 48;
			cb_cartes++;
		}

		cout << "Cartes chosies : ";
		for(size_t i = 0; i<Ou.size(); i++){
			if(Ou[i] == 0)
				break;
			cout << Ou[i] << " ";
		}
		cout << endl;

		this->recupRempli(Ou, Choix);
		for(size_t i = 0; i<Choix.size(); i++){
			if(Choix[i]==NULL)
				break;
			Choix[i]->affiche();
			cout << endl;
		} 
		deuxiemeFois = 1;

		//cout << Choix.size() <<  endl;
	//	cout << combine_possible(Choix) << endl;
	} while(!combine_possible(Choix));

		return 0;
}

//Choix est au depart vide il faut le remplir avec des pushback et le vider de nouveau si des erreurs sont comises !