#include<gtk/gtk.h>

//struct Date
/*typedef struct 
{
 int j;
int m;
int a;
}date;*/

//struct equipement
typedef struct
{ 
 char type[20];
char marque[20];
char puissance_fiscale[40];
int annee;
char matricule[20];
char date_visite[20];
char date_entr[20];
}equipement; //nzid les entretiens

//les fonctions à traiter
void afficher(GtkWidget *liste);
void supprimer(char mat[]);
void modifier(char file_name[],char mat[]); //tzidha f equipement eli bech eddakhlou (nhott equipement fe les parametres)
void ajout(equipement e);
void recherche(GtkWidget *liste,char mat[]); //trajja3lek equipement
//equipement creation();
void affichertyp(GtkWidget *liste, char type[]);
