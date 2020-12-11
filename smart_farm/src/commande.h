
#include<gtk/gtk.h>

enum {
TOMATE,
CAROTTE,
EPINARD,
POMMEDETERRE,
ARTICHAUD,
BROCOLI,
PRIX,
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
}commande;



void commandes(char file_name2[],commande co);
void afficher_commande(GtkWidget *treeviewcommande);
