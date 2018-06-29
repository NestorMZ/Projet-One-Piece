#ifndef DEF_CARTE
#define DEF_CARTE

class Carte
{
	public:
	
	//Methodes sont rendues publiques pour pouvoir les appeler en dehors de l'objet
	
	Carte(); //Constructeur
	Carte(int val, int fam); //Constructeur surchargé avec valeur et famille
	
	int estRouge() const;//On met le constant que si la mehtode ne modifie pas l'objet
	int estNoire() const;
	int getVal() const;
	int getFam() const;
	void setVal(int val);
	void setFam(int fam);
	int estUneTete() const;
	void affiche() const;
	//TODO : si d'autres idées, completer...
	
	private:
	
	int valeur; //entre 1 et 13
	int famille; // entre 0 et 3 (coeur, pique, carreau, trèfle)
};

#endif
