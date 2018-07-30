#ifndef DEF_CARTE
#define DEF_CARTE

class Carte
{
	public:
	
	//Methodes sont rendues publiques pour pouvoir les appeler en dehors de l'objet
	
	Carte(); //Constructeur
	Carte(int val, int fam); //Constructeur surchargé avec valeur et famille
	
	//On met le constant que si la mehtode ne modifie pas l'objet
	int estRouge() const; //retourne 1 si carreau ou coeur
	int estNoire() const; // inversement
	int getVal() const; //retourne la valeur de la carte
	int getFam() const; //retourne la famille de la carte
	void setVal(int val); 
	void setFam(int fam);
	int estUneTete() const; //verifie si on est sur une tête
	void affiche() const; //affiche le nom de la carte entier
	int getPoints() const; //retourne le nombre de points réels d'une carte (poids dans une main)
	int getUniqueSign() const;
	int sameColor(Carte* autreCarte) const;
	//TODO : si d'autres idées, completer...
	
	private:
	
	int valeur; //entre 1 et 13
	int famille; // entre 0 et 3 (coeur, pique, carreau, trèfle)
};

#endif
