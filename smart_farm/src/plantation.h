#ifndef PLANTATION_H_
#define PLANTATION_H_
#include <gtk/gtk.h>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

enum{
DATE,
CATEGORIE,
IDENTIFIANT,
IRRIGATION,
DOSE_ENGRAIS,
TRAITEMENT,
POIDS_RECOLTE,
COLUMNS_plt
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

typedef struct{
int
Jour,
Mois,
Annee;
}date_plt;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

typedef struct{
date_plt Date;
char
Categorie[20],
Identifiant[20],
Irrigation[20],
Engrais[20],
Traitement[40],
Recolte[20],
Image[100];
}plantation;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void
ajouter_plantation(char data_base[],plantation p),
modifier_plantation(char data_base[],plantation *p),
supprimer_plantation(char data_base[],char Identifiant[]),
afficher_plantation(char data_base[],GtkWidget *MABFTreeView),
chercher_plantation(char data_base[],char identifiant[],GtkWidget *MABFTreeView,GtkWidget *MABFImageInsertion);

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int
date_valide_plt(date_plt Date),
influence_lunaire(date_plt Date),
identifiant_existant(char data_base[],char Identifiant[]),
chercher_calendrier(char data_base[],char date_cible[],GtkWidget *MABFTreeView);

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif