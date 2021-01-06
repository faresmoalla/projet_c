#ifndef CAPTEUR_H_
#define CAPTEUR_H_

#include <gtk/gtk.h>

enum{
DATE_cpt,
MARQUE_cpt,
IDENTIFIANT_cpt,
VALEUR_cpt,
TYPE_cpt,
COLUMNS_cpt
};

typedef struct{
int
Jour,
Mois,
Annee;
}date_cpt;

typedef struct{
date_cpt Date;
char
Marque[20],
Identifiant[20],
Type[20];
float Valeur;
}capteur_type;

void
afficher_TreeView(char data_capt[],GtkWidget *MABFTreeView);

#endif
