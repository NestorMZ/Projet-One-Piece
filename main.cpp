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

void afficher_pile(vector<Carte*> Pile){
	for(size_t i = 0; i<Pile.size(); i++){
		Pile[i]->affiche();
	}
} 

void melanger_pile(vector<Carte*>& Pile){
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

int main()
{
	cout << "DUMBAL ETE 2018 - MARTINEZ AJANOHOUN" << endl << endl;

	cout << "How many players do you want ? (entre 2 et 4)" << endl;
	vector<Joueur> lesJoueurs(combienDeJoueurs());

	vector<Carte*> Pile(52);
	creer_cartes(Pile);
	melanger_pile(Pile);

	Joueur Nestor("Nestor");
	Joueur Jordy("Jordy");

	int z = 0;
	cout << endl;
	while(z++ != 7){
		Nestor.piocher(Pile);
		Jordy.piocher(Pile);
	}

	Nestor.afficher_main();
	cout << endl;
	Jordy.afficher_main();
	//afficher_pile(Pile);
	while(Pile.size()!=0){
		delete Pile[Pile.size()-1];
		Pile.pop_back();
	}

	return 0;
}