#include <iostream>
#include <vector>
#include <string>
#include <cstdlib> //pour avoir la fonction rand
#include "time.h" //pour pouvoir faire time(NULL) et avoir des melanges differents

#include "Carte.h"
#include "Joueur.h"

using namespace std;

int combienDeJoueurs(){
	string reponse;
	cin >> reponse;
	while(reponse!="2" and reponse!="3" and reponse !="4"){
		cout << "Erreur de saisie veuillez reessayer : " << endl;
		cin >> reponse;
	}
	return reponse[0]-'0';

}

void creerJoueurs(vector<Joueur>& lesJoueurs){
	size_t i = 0;
	string name;
	Joueur joueur;
	while(i < lesJoueurs.size()){
		cout << "Nom du joueur " << i+1 << " : " ;
		cin >> name;
		joueur.setName(name);
		lesJoueurs[i] = joueur;
		cout << endl;
		i++;
	}
}

int joueursAlive(vector<Joueur> lesJoueurs){
	int resultat = 0;
	for(size_t i = 0; i<lesJoueurs.size(); i++){
		if(lesJoueurs[i].getPV() > 0)
			resultat++;
	}
	return resultat;
}

void creer_cartes(vector<Carte*>& Pile){
	int val=1;
	int fam = 0;
	while(val!=14 or fam!=3){
		if (val==14){val = 1; fam++;}
		Carte* carte = new (nothrow) Carte(val,fam);
		Pile[val+fam*13-1] = carte;
		//Carte carte(val,fam);
		//carte.valeur = 0;
		//carte->affiche();
		val++;
		//delete carte;
	}
}

void distribuer_cartes(vector<Carte*>&Pile, vector<Joueur>& lesJoueurs){
	int cpt = 0;
	size_t joueur = 0;

	while(cpt != 7){
		while(joueur < lesJoueurs.size()){
			lesJoueurs[joueur].piocher(Pile);
			joueur++;
		}
		joueur = 0;
		cpt++;
	}
}

void afficher_vCartes(vector<Carte*> Pile){
	for(size_t i = 0; i<Pile.size(); i++){
		Pile[i]->affiche();
	}
} 

void melanger_cartes(vector<Carte*>& Pile){
	srand(time(NULL));
	Carte* p_temp = NULL;
	int nrand = 0;
	for(size_t i = 0; i<Pile.size(); i++){
		nrand = rand()%52;
		p_temp = Pile[nrand];
		Pile[nrand] = Pile[i];
		Pile[i] = p_temp;
	}
}

/*TOUR PAR TOUR
C'est au tour de ...
Affiche ses cartes
Que voulez vous jouer ? Which cards do you want to play ?*/

int main()
{
	cout << "DUMBAL ETE 2018 - MARTINEZ AJANOHOUN" << endl << endl;

	cout << "How many players do you want ? (entre 2 et 4)" << endl;
	int nb_joueurs = combienDeJoueurs();
	vector<Joueur> lesJoueurs(nb_joueurs);
	creerJoueurs(lesJoueurs);

	vector<Carte*> Pile(52);
	creer_cartes(Pile);
	melanger_cartes(Pile);

	vector<Carte*> Tas;
	vector<Carte*> TasTemporaire;

	distribuer_cartes(Pile, lesJoueurs);

	//afficher_vCartes(Pile);
	lesJoueurs[0].jouer(Pile, TasTemporaire, Tas);
	//cout << Pile[0]->sameColor(Pile[1]);
	//int x = lesJoueurs[0].jouer(Pile, Tas, TasTemporaire);
	//cout << x;


	while(Pile.size()!=0){
		delete Pile[Pile.size()-1];
		Pile.pop_back();
	}

	return 0;
}