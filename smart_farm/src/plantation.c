#include <gtk/gtk.h>
#include <string.h>
#include "plantation.h"

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int date_valide_plt(date_plt Date){
int bissextile=0;
switch(Date.Mois){
case 1: case 3: case 5: case 7: case 8: case 10: case 12: if((Date.Jour>=1)&&(Date.Jour<=31)){return 1;}
break;
case 2: if(((Date.Annee%4==0)&&(Date.Annee%100!=0))||(Date.Annee%400==0)){bissextile=1;}
if(((Date.Jour>=1)&&(Date.Jour<=29)&&(bissextile==1))||((Date.Jour>=1)&&(Date.Jour<=28)&&(!bissextile))){return 1;}
break;
case 4: case 6: case 9: case 11: if((Date.Jour>=1)&&(Date.Jour<=30)){return 1;}
break;}}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*Copyright © 2021 by Moon & Garden. All rights reserved*/
int influence_lunaire(date_plt Date){
switch(Date.Annee){
case 2020:
switch(Date.Mois){
case 1: switch(Date.Jour){case 2: case 10: case 13: case 22: case 29: return 1;}
break;
case 2: switch(Date.Jour){case 6: case 10: case 19: case 26: return 1;}
break;
case 3: switch(Date.Jour){case 4: case 10: case 17: case 24: case 31: return 1;}
break;
case 4: switch(Date.Jour){case 7: case 13: case 20: case 27: return 1;}
break;
case 5: switch(Date.Jour){case 6: case 10: case 18: case 24: return 1;}
break;
case 6: switch(Date.Jour){case 3: case 6: case 15: case 21: case 30: return 1;}
break;
case 7: switch(Date.Jour){case 4: case 12: case 18: case 25: case 31: return 1;}
break;
case 8: switch(Date.Jour){case 9: case 14: case 21: case 27: return 1;}
break;
case 9: switch(Date.Jour){case 6: case 11: case 18: case 23: return 1;}
break;
case 10: switch(Date.Jour){case 3: case 8: case 17: case 20: case 30: return 1;}
break;
case 11: switch(Date.Jour){case 4: case 14: case 17: case 27: return 1;}
break;
case 12: switch(Date.Jour){case 1: case 12: case 14: case 24: case 28: return 1;}
break;}
break;
case 2021:
switch(Date.Mois){
case 1: switch(Date.Jour){case 9: case 10: case 21: case 24: return 1;}
break;
case 2: switch(Date.Jour){case 3: case 7: case 18: case 21: return 1;}
break;
case 3: switch(Date.Jour){case 2: case 6: case 18: case 20: case 30: return 1;}
break;
case 4: switch(Date.Jour){case 2: case 14: case 16: case 27: case 29: return 1;}
break;
case 5: switch(Date.Jour){case 11: case 13: case 26: return 1;}
break;
case 6: switch(Date.Jour){case 8: case 9: case 23: return 1;}
break;
case 7: switch(Date.Jour){case 5: case 6: case 20: case 21: return 1;}
break;
case 8: switch(Date.Jour){case 2: case 3: case 16: case 17: case 30: return 1;}
break;
case 9: switch(Date.Jour){case 11: case 12: case 26: return 1;}
break;
case 10: switch(Date.Jour){case 8: case 9: case 23: case 24: return 1;}
break;
case 11: switch(Date.Jour){case 5: case 6: case 19: case 21: return 1;}
break;
case 12: switch(Date.Jour){case 3: case 4: case 17: case 18: case 31: return 1;}
break;}
break;
case 2022:
switch(Date.Mois){
case 1: switch(Date.Jour){case 1: case 13: case 14: case 27: case 30: return 1;}
break;
case 2: switch(Date.Jour){case 9: case 11: case 23: case 26: return 1;}
break;
case 3: switch(Date.Jour){case 8: case 11: case 22: case 24: return 1;}
break;
case 4: switch(Date.Jour){case 4: case 7: case 18: case 19: return 1;}
break;
case 5: switch(Date.Jour){case 1: case 5: case 16: case 17: case 29: return 1;}
break;
case 6: switch(Date.Jour){case 2: case 12: case 15: case 25: case 29: return 1;}
break;
case 7: switch(Date.Jour){case 9: case 13: case 22: case 26: return 1;}
break;
case 8: switch(Date.Jour){case 5: case 10: case 18: case 22: return 1;}
break;
case 9: switch(Date.Jour){case 1: case 7: case 14: case 19: case 29: return 1;}
break;
case 10: switch(Date.Jour){case 4: case 11: case 17: case 26: case 29: return 1;}
break;
case 11: switch(Date.Jour){case 8: case 14: case 22: case 26: return 1;}
break;
case 12: switch(Date.Jour){case 5: case 12: case 20: case 24: return 1;}
break;}
break;
case 2023:
switch(Date.Mois){
case 1: switch(Date.Jour){case 1: case 8: case 16: case 21: case 28: return 1;}
break;
case 2: switch(Date.Jour){case 4: case 12: case 19: case 24: return 1;}
break;
case 3: switch(Date.Jour){case 3: case 11: case 19: case 24: case 31: return 1;}
break;
case 4: switch(Date.Jour){case 7: case 16: case 20: case 28: return 1;}
break;
case 5: switch(Date.Jour){case 4: case 11: case 17: case 26: return 1;}
break;
case 6: switch(Date.Jour){case 1: case 7: case 14: case 22: case 28: return 1;}
break;
case 7: switch(Date.Jour){case 4: case 11: case 20: case 25: return 1;}
break;
case 8: switch(Date.Jour){case 2: case 7: case 16: case 21: case 30: return 1;}
break;
case 9: switch(Date.Jour){case 3: case 12: case 17: case 28: case 30: return 1;}
break;
case 10: switch(Date.Jour){case 10: case 15: case 26: case 28: return 1;}
break;
case 11: switch(Date.Jour){case 6: case 11: case 21: case 24: return 1;}
break;
case 12: switch(Date.Jour){case 4: case 8: case 16: case 21: return 1;}
break;}
break;
}}
/*Copyright © 2021 by Moon & Garden. All rights reserved*/

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int identifiant_existant(char data_base[],char Identifiant[]){
FILE *f=NULL;
plantation c;
f=fopen(data_base,"rb");
if(f!=NULL){
while(!feof(f)){
fread(&c,sizeof(plantation),1,f);
if(strcmp(Identifiant,c.Identifiant)==0){return 1;}}
fclose(f);}}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ajouter_plantation(char data_base[],plantation p){
FILE *f=NULL;
f=fopen(data_base,"ab");
if(f!=NULL){fwrite(&p,sizeof(plantation),1,f); fclose(f);}}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void modifier_plantation(char data_base[],plantation *p){
FILE *f1=NULL,*f2=NULL;
plantation c;
char temp[]="temp.bin";
int i=0,j=0;
f1=fopen(data_base,"rb");
f2=fopen(temp,"wb");
if(f1!=NULL){
if(f2!=NULL){
while(!feof(f1)){
fread(&c,sizeof(plantation),1,f1);
if(strcmp(p->Identifiant,c.Identifiant)!=0){fwrite(&c,sizeof(plantation),1,f2);}
else if(strcmp(p->Identifiant,c.Identifiant)==0){fwrite(p,sizeof(plantation),1,f2);}}
fclose(f2);}
fclose(f1);}
remove(data_base);
rename(temp,data_base);
f1=fopen(data_base,"rb");
if(f1!=NULL){
while(!feof(f1)){
fread(&c,sizeof(plantation),1,f1);
i++;}
fclose(f1);}
f1=fopen(data_base,"rb");
f2=fopen(temp,"wb");
if(f1!=NULL){
if(f2!=NULL){
while((j<i-2)&&(!feof(f1))){
fread(&c,sizeof(plantation),1,f1);
fwrite(&c,sizeof(plantation),1,f2);
j++;}
fclose(f2);}
fclose(f1);}
remove(data_base);
rename(temp,data_base);}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void supprimer_plantation(char data_base[],char Identifiant[]){
FILE *f1=NULL,*f2=NULL;
plantation p;
char temp[]="temp.bin";
int i=0,j=0;
f1=fopen(data_base,"rb");
if(f1!=NULL){
while(!feof(f1)){
fread(&p,sizeof(plantation),1,f1);
i++;}
fclose(f1);}
f1=fopen(data_base,"rb");
f2=fopen(temp,"wb");
if(f1!=NULL){
if(f2!=NULL){
while((!feof(f1))&&(j<i-1)){
fread(&p,sizeof(plantation),1,f1);
if(strcmp(p.Identifiant,Identifiant)!=0){fwrite(&p,sizeof(plantation),1,f2);}
j++;}
fclose(f2);}
fclose(f1);}
remove(data_base);
rename(temp,data_base);}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void afficher_plantation(char data_base[],GtkWidget *MABFTreeView){
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
FILE *f=NULL;
plantation p;
int i=0,j=0;
char jour[20],mois[20],annee[20],date_plantation[50];
GtkTreeModel *model=gtk_tree_view_get_model(GTK_TREE_VIEW(MABFTreeView));
if(model==NULL){
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Date",renderer,"text",DATE,NULL);
gtk_tree_view_column_set_alignment(column,0.5);
gtk_cell_renderer_set_alignment(renderer,0.5,0.5);
gtk_tree_view_append_column(GTK_TREE_VIEW(MABFTreeView),column);
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Catégorie",renderer,"text",CATEGORIE,NULL);
gtk_tree_view_column_set_alignment(column,0.5);
gtk_cell_renderer_set_alignment(renderer,0.5,0.5);
gtk_tree_view_append_column(GTK_TREE_VIEW(MABFTreeView),column);
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Identifiant",renderer,"text",IDENTIFIANT,NULL);
gtk_tree_view_column_set_alignment(column,0.5);
gtk_cell_renderer_set_alignment(renderer,0.5,0.5);
gtk_tree_view_append_column(GTK_TREE_VIEW(MABFTreeView),column);
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Irrigation",renderer,"text",IRRIGATION,NULL);
gtk_tree_view_column_set_alignment(column,0.5);
gtk_cell_renderer_set_alignment(renderer,0.5,0.5);
gtk_tree_view_append_column(GTK_TREE_VIEW(MABFTreeView), column);
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Engrais",renderer,"text",DOSE_ENGRAIS, NULL);
gtk_tree_view_column_set_alignment(column,0.5);
gtk_cell_renderer_set_alignment(renderer,0.5,0.5);
gtk_tree_view_append_column(GTK_TREE_VIEW(MABFTreeView),column);
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Traitement",renderer,"text",TRAITEMENT,NULL);
gtk_tree_view_column_set_alignment(column,0.5);
gtk_cell_renderer_set_alignment(renderer,0.5,0.5);
gtk_tree_view_append_column(GTK_TREE_VIEW(MABFTreeView),column);
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Récolte",renderer,"text",POIDS_RECOLTE,NULL);
gtk_tree_view_column_set_alignment(column,0.5);
gtk_cell_renderer_set_alignment(renderer,0.5,0.5);
gtk_tree_view_append_column(GTK_TREE_VIEW(MABFTreeView),column);}
GtkListStore *store=gtk_list_store_new(COLUMNS_plt,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,
G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
f=fopen(data_base,"rb");
if(f!=NULL){
while(!feof(f)){
fread(&p,sizeof(plantation),1,f);
i++;}
fclose(f);}
f=fopen(data_base,"rb");
if(f!=NULL){
while((j<i-1)&&(!feof(f))){
fread(&p,sizeof(plantation),1,f);
sprintf(jour,"%d",p.Date.Jour);
if(strlen(jour)==1){
strcpy(date_plantation,"0");}
else if(strlen(jour)==2){
strcpy(date_plantation,"");}
strcat(date_plantation,jour);
sprintf(mois,"%d",p.Date.Mois);
if(strlen(mois)==1){
strcat(date_plantation,"/0");}
else if(strlen(mois)==2){
strcat(date_plantation,"/");}
strcat(date_plantation,mois);
strcat(date_plantation,"/");
sprintf(annee,"%d",p.Date.Annee);
strcat(date_plantation,annee);
if(strlen(p.Engrais)==4){
char Engrais[10]="";
strcpy(Engrais,p.Engrais);
strcpy(p.Engrais,"0");
strcat(p.Engrais,Engrais);}
if(strlen(p.Recolte)==4){
char Recolte[10]="";
strcpy(Recolte,p.Recolte);
strcpy(p.Recolte,"0");
strcat(p.Recolte,Recolte);}
gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,DATE,date_plantation,CATEGORIE,p.Categorie,IDENTIFIANT,p.Identifiant,IRRIGATION,p.Irrigation,DOSE_ENGRAIS,p.Engrais,TRAITEMENT,p.Traitement,POIDS_RECOLTE,p.Recolte,-1);
j++;}
fclose(f);}
gtk_tree_view_set_model(GTK_TREE_VIEW(MABFTreeView),GTK_TREE_MODEL(store));
g_object_unref(store);}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void chercher_plantation(char data_base[],char Identifiant[],GtkWidget *MABFTreeView,GtkWidget *MABFImageInsertion){
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
FILE *f=NULL;
plantation p;
GtkListStore *store=NULL;
GtkTreeModel *model=NULL;
char jour[20],mois[20],annee[20],date_plantation[50],temp[]="temp.bin";
int i=0,j=0;
model=gtk_tree_view_get_model(GTK_TREE_VIEW(MABFTreeView));
store=gtk_list_store_new(COLUMNS_plt,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
f=fopen(data_base,"rb");
if(f!=NULL){
while(!feof(f)){
fread(&p,sizeof(plantation),1,f);
i++;}
fclose(f);}
f=fopen(data_base,"rb");
if(f!=NULL){
while((j<i-1)&&(!feof(f))){
fread(&p,sizeof(plantation),1,f);
if(strcmp(Identifiant,p.Identifiant)==0){
strcpy(date_plantation,"");
sprintf(jour,"%d",p.Date.Jour); strcat(date_plantation,jour); strcat(date_plantation,"/");
sprintf(mois,"%d",p.Date.Mois); strcat(date_plantation,mois); strcat(date_plantation,"/");
sprintf(annee,"%d",p.Date.Annee); strcat(date_plantation,annee);
gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,DATE,date_plantation,CATEGORIE,p.Categorie,IDENTIFIANT,p.Identifiant,IRRIGATION,p.Irrigation,DOSE_ENGRAIS,p.Engrais,TRAITEMENT,p.Traitement,POIDS_RECOLTE,p.Recolte,-1);
gtk_image_set_from_file(GTK_IMAGE(MABFImageInsertion),p.Image);}
j++;}
fclose(f);}
gtk_tree_view_set_model(GTK_TREE_VIEW(MABFTreeView),GTK_TREE_MODEL(store));
g_object_unref(store);}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int chercher_calendrier(char data_base[],char date_cible[],GtkWidget *MABFTreeView){
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
FILE *f=NULL;
plantation p;
GtkTreeModel *model=NULL;
GtkListStore *store=NULL;
char jour[20],mois[20],annee[20],date_plantation[50],temp[]="temp.bin";
int i=0,j=0,nbr=0; 
model=gtk_tree_view_get_model(GTK_TREE_VIEW(MABFTreeView));
store=gtk_list_store_new(COLUMNS_plt,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
f=fopen(data_base,"rb");
if(f!=NULL){
while(!feof(f)){
fread(&p,sizeof(plantation),1,f);
i++;}
fclose(f);}
f=fopen(data_base,"rb");
if(f!=NULL){
while((j<i-1)&&(!feof(f))){
fread(&p,sizeof(plantation),1,f);
strcpy(date_plantation,"");
sprintf(jour,"%d",p.Date.Jour); strcat(date_plantation,jour); strcat(date_plantation,"/");
sprintf(mois,"%d",p.Date.Mois); strcat(date_plantation,mois); strcat(date_plantation,"/");
sprintf(annee,"%d",p.Date.Annee); strcat(date_plantation,annee);
if(strcmp(date_cible,date_plantation)==0){
nbr++;
gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,DATE,date_plantation,CATEGORIE,p.Categorie,IDENTIFIANT,p.Identifiant,IRRIGATION,p.Irrigation,DOSE_ENGRAIS,p.Engrais,TRAITEMENT,p.Traitement,POIDS_RECOLTE,p.Recolte,-1);}
j++;}
fclose(f);}
gtk_tree_view_set_model(GTK_TREE_VIEW(MABFTreeView),GTK_TREE_MODEL(store));
g_object_unref(store);
return nbr;}
