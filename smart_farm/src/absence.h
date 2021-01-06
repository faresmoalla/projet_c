#include<gtk/gtk.h>
enum
{
CIN,
JOUVRIER,
MOUVRIER,
AOUVRIER,
VALEUR,

COLONE
};

typedef struct
{
int cin;
int jour;
int mois;
int annee;
int h_entree;
int h_sortie;
int valeur;
}absence;


void pointer_ouvrier(absence p);
void affiche_absence(GtkWidget *treeview);
