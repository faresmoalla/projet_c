//struct Date
typedef struct 
{
 int j;
int m;
int a;
}date;

//struct equipement
typedef struct
{ 
 char type[20];
char marque[20];
int puissance_fiscale;
int annee;
char matricule[20];
date date_visite;
date date_entr;
}equipement; //nzid les entretiens

//les fonctions à traiter
void supprimer(char file_name[],char mat[]);
void modifier(char file_name[],char mat[]); //tzidha f equipement eli bech eddakhlou (nhott equipement fe les parametres)
void ajouter(char file_name[],equipement e);
void afficher(char file_name[]);
equipement* recherche(char file_name[],char mat[]); //trajja3lek equipement
equipement creation();
