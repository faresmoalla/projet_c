#include<gtk/gtk.h>
typedef struct {
int id,jour,mois,annee,valeur;

} absence ;


enum {
NOMCLIENT,
PRENOMCLIENT,
USERNAMECLIENT,
PASSWORDCLIENT,
EMAILCLIENT,
ADRESSCLIENT,
DDJCLIENT,
DDMCLIENT,
DDACLIENT,
SEXE,
COLUMNS
};


typedef struct {
int jour ;
int mois;
int annee;
}date;

typedef struct {
char nom[20];
char prenom[20];
char username[20];
char password[20];
char email[30];
char adress[50];
date d;
char sexe[100];
}client;

/*
typedef struct {
char num[5];
char troupeaux;
char agricoles;
}achat;
*/

void modifier_client(client c);
client rechercher2(char email[],char nom_fichier[]);
//void modifier_client(char file_name[],char email[],client c);
client creation_client();
void inscription_client(char file_name[],client c);
void supprimer_client(char file_name[],char id[]);
void supprimer2(client c);
void frechercher(char file_name[],char recherche[], int *ch);
void fafficher(char file_name[]);
void absents(int idd ,absence a,float *taux_absenteisme);
int verif(char log[] , char Pw[] );
void afficher_client(GtkWidget *FMtreeview);
