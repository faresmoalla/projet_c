
#include<gtk/gtk.h>

enum {
TOMATE,
CAROTTE,
EPINARD,
POMMEDETERRE,
ARTICHAUD,
BROCOLI,
PRIX,
ADRESS,
COLUMNS1
};


typedef struct {
int tomate;
int carotte;
int epinard;
int pomme_de_terre;
int artichaud;
int brocoli;
int prix;
char adress[50];
}commande;



void commandes(char file_name2[],commande co);
void afficher_commande(GtkWidget *treeviewcommande);
