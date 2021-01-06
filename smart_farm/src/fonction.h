#include <gtk/gtk.h>
typedef struct
{
	int jour;
	int mois;
	int annee;
}Mdate;


typedef struct
{
	char captID[20];
	char captMarque[20];
	char captType[20];
	char valeur[20];
	Mdate Mdate_ajout;
}capteur;

typedef struct
{
	int etatAlarma;
	char captIDalarm[20];

}etatAlarm;

void afficherhum(GtkWidget *liste);
void ajouter(char file[],capteur c);
void supprimer(capteur c);
void supprimer1(capteur c);
void rechercher(char file[] ,char id[]);
void modifier(char file[],capteur c);
capteur creation();
void rechercher_capteur(char IDa[],GtkWidget *liste);
void supprimer_capt(capteur c);
void supprimer3(char file[],char IDs[]);
capteur rechercher1(char id[],char nom_fichier[]);
void afficher(GtkWidget *liste);
void affichertmp(GtkWidget *liste);
