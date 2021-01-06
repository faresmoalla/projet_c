#include<gtk/gtk.h>
typedef struct {
int id,jour,mois,annee,valeur;

} absencefares ;


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
LIEU,
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
char email[50];
char adress[50];
date d;
char sexe[100];
char lieu[100];
}client;




int existant(char ch[],char file_name[]);
int Verif_Password(client c);
int check_useremail(char email[]);
void modifier_client(client c);
client rechercher2(char email[],char nom_fichier[]);
client creation_client();
void inscription_client(char file_name[],client c);
void supprimer_client(char file_name[],char id[]);
void supprimer2(char mail[50],client c);
void frechercher(char file_name[],char recherche[], int *ch);
void fafficher(char file_name[]);

int verif(char log[] , char Pw[] );
void afficher_client(GtkWidget *FMtreeview);
int veriffares(char you[]);
int existantusername(char ch[],char file_name[]);

int veriffares2(char you[]);






