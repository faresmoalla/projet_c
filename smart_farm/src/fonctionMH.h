#include <gtk/gtk.h>
typedef struct {
	int jour;
	int mois;
	int annee;
}Date;
typedef struct 
{
	char identifiant [20];
	char type [10];
	char sexe [20];
	Date date_naissance;
	Date date_vaccin;
}naissance;
void afficher_type(GtkWidget *list, int vache, int veau, int chevre, int brebis);
void rechercher_animal(char identif[20],GtkWidget *liste);
void  afficher_tr(GtkWidget *liste);
int ajout (naissance n,char nomfich []);
naissance* chercher (char id[], char nomfich []);
int modifierMH (naissance *n, char nomfich []);
int supprimerMH (char id[], char nomfich []);
void supprimer_tr(char file_name[],char id[]);
void afficherMH (char nomfich []);
void afficher_nbre_troupeaux(int * v, int * c, int * b,int * vo, char nomfich[]);
