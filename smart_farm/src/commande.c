#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include "commande.h"
#include<gtk/gtk.h>
#include "client.h"

void commandes(char file_name[],commande co)
{ FILE *f;
f=fopen("commande.txt","a+");
if(f!=NULL)
{
co.prix=  co.tomate*2+co.carotte*2+co.epinard*1+co.pomme_de_terre*3+co.artichaud*5+co.brocoli*1;
fprintf(f," %d  %d  %d   %d   %d  %d  %d   \n",co.tomate,co.carotte,co.epinard,co.pomme_de_terre,co.artichaud,co.brocoli,co.prix);
}
fclose(f);
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void afficher_commande(GtkWidget *treeviewcommande)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;

char tomate[50];
char carotte[50];
char epinard[50];
char pomme_de_terre[50];
char artichaud[50];
char brocoli[50];
char Prix[50]; 
store=NULL;
FILE *f;
store=gtk_tree_view_get_model(treeviewcommande);
if (store == NULL)
{    

            renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("tomate",renderer,"text",TOMATE,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(treeviewcommande),column);

 renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("carotte",renderer,"text",CAROTTE,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(treeviewcommande),column);


 renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("epinard",renderer,"text",EPINARD,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(treeviewcommande),column);

 renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("pomme_de_terre",renderer,"text",POMMEDETERRE,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(treeviewcommande),column);

 renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("artichaud",renderer,"text",ARTICHAUD,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(treeviewcommande),column);

 renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("brocoli",renderer,"text",BROCOLI,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(treeviewcommande),column);
          renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("Prix",renderer,"text",PRIX,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(treeviewcommande),column);

            
           }
           
store=gtk_list_store_new(COLUMNS1,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
            f=fopen("commande.txt","r");
 if (f== NULL){
              return ;

}
           else {
            f=fopen("commande.txt","a+");
            while (fscanf(f,"%s %s %s %s %s %s %s  \n",tomate,carotte,epinard,pomme_de_terre,artichaud,brocoli,Prix)!=EOF)
{
            gtk_list_store_append(store,&iter);
            gtk_list_store_set(store,&iter,TOMATE,tomate,CAROTTE,carotte,EPINARD,epinard,POMMEDETERRE,pomme_de_terre,ARTICHAUD,artichaud,BROCOLI,brocoli,PRIX,Prix,-1);

}
fclose(f);
}
            gtk_tree_view_set_model(GTK_TREE_VIEW(treeviewcommande),GTK_TREE_MODEL(store));
            g_object_unref(store);
}
