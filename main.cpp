#include <iostream>
#include <vector>
#include "Carte.h"

using namespace std;

int main()
{
	int val=1;
	int fam = 0;
	while(val!=14 or fam!=3){
		if (val==14){val = 1; fam++;}
		Carte* carte = new Carte(val,fam);
		carte->affiche();
		val++;
		delete carte;
	}
		
	return 0;
}