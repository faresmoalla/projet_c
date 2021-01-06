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
void afficherMB(GtkWidget *liste);
void supprimerMB(char mat[]);
void modifierMB(char file_name[],char mat[]); //tzidha f equipement eli bech eddakhlou (nhott equipement fe les parametres)
void ajoutMB(equipement e);
void recherche(GtkWidget *liste,char mat[]); //trajja3lek equipement
//equipement creation();
void affichertyp1(GtkWidget *liste, char type[]);
void affichertyp2(GtkWidget *liste, char type1[], char type2[]);
void affichertyp3(GtkWidget *liste, char type1[], char type2[], char type3[]);
void affichertyp4(GtkWidget *liste, char type1[], char type2[], char type3[], char type4[]);
int verifMB(char mat []);

//GtkListStore *store_f;
