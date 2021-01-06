#include<gtk/gtk.h>

enum
{NOMOUVRIER,
PRENOMOUVRIER,
JOUROUVRIER,
MOISOUVRIER,
ANNEEOUVRIER,
LIEUOUVRIER,
ADRESSEOUVRIER,
CINMOUVRIER,
NUMEROOUVRIER,
PERMISOUVRIER,
AFFECTATION,
FONCTION,
HEURESTRAVAIL,


COLUMN
};



/*typedef struct
{
int cin;
int jour;
int mois;
int annee;
int h_entree;
int h_sortie;
int valeur;
}absence;*/


typedef struct
{
int  jour;
int  mois;
int  annee;
}dat;
typedef struct
{
char nom[20];
char prenom[20];
dat D;
char lieu_n[20]; 
char adresse[20];
char n_cin[20];
char n_tel[20];
char affectation[20];
char permis[20];
char fonction[200];
char nh_travail[10];

}ouvrier;

//void supprimer1(char ouvrier_sup) ;
//ouvrier rechercher1(char cherche,char nom_fichier);
//ouvrier creation_ouvrier();
void ajouter_ouvrier(ouvrier o,char file_ouvrier[]);
int recherche_ajout_ouvrier(char cherche[],char file_ouvrier[]);



void RKsupprimer(char ouvrier_sup[],char file_ouvrier[]);
void cherche_ouvrier(char cherche[],GtkWidget *treeview,char file_ouvrier[]);



void affiche_ouvrier(GtkWidget *treeview,char file_ouvrier[]);
//void modifier_ouvrier(char cherche/*,char file_ouvrier*/);
int modifier_ouvrier(ouvrier* o ,char file_ouvrier[]);


//void pointer_ouvrier(absence p);
//void absents(int id ,absence a,float *taux_absenteisme);
//void nombre_ouvrier(absence a ,int *nb_ouvrier );

//void affiche_absence(GtkWidget *treeview);
