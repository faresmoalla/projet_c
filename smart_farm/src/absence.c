#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"absence.h"
#include<gtk/gtk.h>

void pointer_ouvrier(absence p)
{
int min=4;

FILE *f;
f=fopen("fiche_absenteisme.txt","a+");
if(f!=NULL)
{
if ((p.h_sortie-p.h_entree)>min)
{p.valeur=1;}
else
{p.valeur=0;}

fprintf(f,"%d  %d  %d  %d  %d \n", p.cin,p.jour,p.mois,p.annee,p.valeur);

}
fclose(f);

}
//////////////////////////////////////////////////////////////////////////
void affiche_absence(GtkWidget *treeview)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
absence p;
char cin[10];
char jour[20];
char mois[20];
char annee[20];
char valeur[20]; 

store=NULL;
FILE *f;
	store = gtk_tree_view_get_model(treeview);
if (store == NULL)
{    
            renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("cin",renderer,"text",CIN,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(treeview),column);
       
           

            renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("jour",renderer,"text",JOUVRIER,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(treeview),column);

            renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("mois",renderer,"text",MOUVRIER,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(treeview),column);

         
            renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("annee",renderer,"text",AOUVRIER,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(treeview),column);
           
           

            renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("valeur",renderer,"text",VALEUR,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(treeview),column);

           
}
           
store = gtk_list_store_new(COLONE,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING );
            f=fopen("fiche_absenteisme.txt","r");
 if (f== NULL)
  {
   return ;
  }
           else {
            f=fopen("fiche_absenteisme.txt","a+");
                 while (fscanf(f,"%s  %s  %s  %s  %s   \n",cin,jour,mois,annee,valeur)!=EOF)
                 {
                 gtk_list_store_append(store,&iter);
                                           gtk_list_store_set(store,&iter,CIN,cin,JOUVRIER,jour,MOUVRIER,mois,AOUVRIER,annee,VALEUR,valeur,-1);
                 }
fclose(f);
}
            gtk_tree_view_set_model(GTK_TREE_VIEW(treeview),GTK_TREE_MODEL(store));
            g_object_unref(store);
}

