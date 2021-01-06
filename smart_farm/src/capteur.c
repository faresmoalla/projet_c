#include "capteur.h"

#include <string.h>
#include <gtk/gtk.h>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void afficher_TreeView(char data_capt[],GtkWidget *MABFTreeView){
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
FILE *f=NULL;
capteur_type cpt;
char jour[20],mois[20],annee[20],date_revision[50];
GtkTreeModel *model=gtk_tree_view_get_model(GTK_TREE_VIEW(MABFTreeView));
if(model==NULL){
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Date",renderer,"text",DATE_cpt,NULL);
gtk_tree_view_column_set_alignment(column,0.5);
gtk_cell_renderer_set_alignment(renderer,0.5,0.5);
gtk_tree_view_append_column(GTK_TREE_VIEW(MABFTreeView),column);
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Marque",renderer,"text",MARQUE_cpt,NULL);
gtk_tree_view_column_set_alignment(column,0.5);
gtk_cell_renderer_set_alignment(renderer,0.5,0.5);
gtk_tree_view_append_column(GTK_TREE_VIEW(MABFTreeView),column);
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Identifiant",renderer,"text",IDENTIFIANT_cpt,NULL);
gtk_tree_view_column_set_alignment(column,0.5);
gtk_cell_renderer_set_alignment(renderer,0.5,0.5);
gtk_tree_view_append_column(GTK_TREE_VIEW(MABFTreeView),column);
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Valeur",renderer,"text",VALEUR_cpt,NULL);
gtk_tree_view_column_set_alignment(column,0.5);
gtk_cell_renderer_set_alignment(renderer,0.5,0.5);
gtk_tree_view_append_column(GTK_TREE_VIEW(MABFTreeView), column);
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Type",renderer,"text",TYPE_cpt, NULL);
gtk_tree_view_column_set_alignment(column,0.5);
gtk_cell_renderer_set_alignment(renderer,0.5,0.5);
gtk_tree_view_append_column(GTK_TREE_VIEW(MABFTreeView),column);}
GtkListStore *store=gtk_list_store_new(COLUMNS_cpt,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_FLOAT,G_TYPE_STRING);
f=fopen(data_capt,"r");
if(f!=NULL){
while(fscanf(f,"%d %d %d %s %s %f %s\n",&cpt.Date.Jour,&cpt.Date.Mois,&cpt.Date.Annee,cpt.Marque,cpt.Identifiant,&cpt.Valeur,cpt.Type)!=EOF){
sprintf(jour,"%d",cpt.Date.Jour);
if(strlen(jour)==1){
strcpy(date_revision,"0");}
else if(strlen(jour)==2){
strcpy(date_revision,"");}
strcat(date_revision,jour);
sprintf(mois,"%d",cpt.Date.Mois);
if(strlen(mois)==1){
strcat(date_revision,"/0");}
else if(strlen(mois)==2){
strcat(date_revision,"/");}
strcat(date_revision,mois);
strcat(date_revision,"/");
sprintf(annee,"%d",cpt.Date.Annee);
strcat(date_revision,annee);
gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,DATE_cpt,date_revision,MARQUE_cpt,cpt.Marque,IDENTIFIANT_cpt,cpt.Identifiant,VALEUR_cpt,cpt.Valeur,TYPE_cpt,cpt.Type,-1);}
fclose(f);}
gtk_tree_view_set_model(GTK_TREE_VIEW(MABFTreeView),GTK_TREE_MODEL(store));
g_object_unref(store);}
