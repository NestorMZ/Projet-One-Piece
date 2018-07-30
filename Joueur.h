#ifndef DEF_JOUEUR
#define DEF_JOUEUR

typedef struct Noeud {
	class Carte* p_maCarte;
	Noeud* p_suivante;
} Noeud, *PtNoeud, *Liste;

void triBulle(std::vector<Carte*>& Choix); //Tri a bulle de droite vers la gauche d'un vecteur de pointeurs de Cartes

int combine_possible(std::vector<Carte*> Choix); //retourn 1 si la combinaison des cartes que le joueur veut déposer est possible et 0 sinon

int stringValide(std::string reponse, size_t max);

int dejaChoisie(std::vector<int> Ou, int reponse);

class Joueur
{
	public:
	//Constructeurs
	Joueur();
	Joueur(std::string nom);
	Joueur(std::string nom,Liste cartes);
	~Joueur(); //Destructeur qui libère la mémoire allouée par les cartes et les noeuds en main

	//Methodes
	std::string getName() const; //retourne le nom du joueur
	void setName(std::string nom); //nomme le joueur avec le parametre
	int getPV() const; //retourne le nombre de points de vie
	void setPV(); //si nouvelle partie on remet la vie a 100
	void dammages(); //enleve aux points de vie du joueur la valeur de sa main
	void contreDumbal();//enleve aux points de vie du joueur 35 + la valeur de sa main
	void piocher(std::vector<Carte*>& Pile);//piocher une carte sur le dessus du jeu (dernier indice du tableau), la rajoute a son jeu et l'enleve du paquet
	void afficher_cartes() const;//affiche chaque carte présente dans la main du joueur en utilisant la methode affiche() de la classe Carte
	int getHandPoints() const; //retourne le nombre de points dans la main du joueur
	int nb_cartes() const; //retourne le nombre de cartes qu'a le joueur dans sa main
	void recupRempli(std::vector<int> Ou, std::vector<Carte*>& Choix) const; // Va chercher les cartes aux indices choisis
	int jouer(std::vector<Carte*>& Pile, std::vector<Carte*>& Tas, std::vector<Carte*>& TasTemp); //demande à l'utilisateur ce qu'il veut jouer, verifie si c'est possible
	
	private:
	//Attributs
	std::string name;
	int points_vie;
	Liste liste_cartes;
};


#endif