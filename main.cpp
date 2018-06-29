#include <iostream>
#include <vector>
#include <string>
#include <cstdlib> //pour avoir la fonction rand
#include "time.h" //pour pouvoir faire time(NULL) et avoir des melanges differents

#include "Carte.h"
#include "Joueur.h"

using namespace std;

void afficher_jeu(vector<Carte*> Pile){
	for(size_t i = 0; i<Pile.size(); i++){
		Pile[i]->affiche();
	}
} 

void melanger_jeu(vector<Carte*>& Pile){
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
	int val=1;
	int fam = 0;
	vector<Carte*> Pile(52);
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
	//afficher_jeu(Pile);
	melanger_jeu(Pile);
	//afficher_jeu(Pile);

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
	//afficher_jeu(Pile);

	return 0;
}

