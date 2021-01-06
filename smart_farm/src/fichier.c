#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <gtk/gtk.h>
#include "fonctionMH.h"
enum
{
	EIDENTIFIANT,
	ETYPE,	
	ESEXE,
	EDATENAISSANCEJOUR,
	EDATENAISSANCEMOIS,
	EDATENAISSANCEANNEE,
	EDATEVACCINJOUR,
	EDATEVACCINMOIS,
	EDATEVACCINANNEE,
	COLUMNS
};
int date_valide (Date D){
int bisextille=0;

if (D.annee<0 || D.jour<1 || D.jour>31 || D.mois<1 || D.mois>12)
	return 0;

if ((D.annee%4==0)&& (D.annee%100==0) || (D.annee%400==0)) {

	bisextille=1;
		}


switch(D.mois){
case 2:

	if((bisextille==0 && D.jour>28)||(bisextille==1 && D.jour>29))
		return 0;
	
	else
		return 1;
break;

case 4:
case 6:
case 9:
case 11:
	if (D.jour>30)
		return 0;
	else
		return 1;
break;
}

return 1;
}

int ajout (naissance n,char nomfich [])
{
FILE* f;
naissance n1;
if(date_valide(n.date_naissance)==0)
return 2;
if(date_valide(n.date_vaccin)==0)
return 3;
f=fopen(nomfich,"r");
if (f!=NULL)
{while (fscanf(f,"%s %s %s %d %d %d %d %d %d",
n1.identifiant,
n1.type,
n1.sexe,
&n1.date_naissance.jour,
&n1.date_naissance.mois,
&n1.date_naissance.annee,
&n1.date_vaccin.jour,
&n1.date_vaccin.mois,
&n1.date_vaccin.annee)!=EOF)
{
if ( strcmp(n1.identifiant,n.identifiant)==0)
   { fclose(f); return -1; }
     }
fclose(f);}

f=fopen(nomfich,"a+");
if (f!=NULL){
fprintf(f,"%s %s %s %d %d %d %d %d %d\n",
n.identifiant,
n.type,
n.sexe,
n.date_naissance.jour,
n.date_naissance.mois,
n.date_naissance.annee,
n.date_vaccin.jour,
n.date_vaccin.mois,
n.date_vaccin.annee);
fclose(f);
}

return 1;}



int supprimerMH (char id[], char nomfich [])
{ FILE *f=NULL,*f2=NULL;
char temp[20]="temporaire.txt";
f=fopen(nomfich,"r");
f2=fopen(temp,"w");
int trouve=0;
naissance n1;

if(f!=NULL && f2!=NULL)
{
while(fscanf(f,"%s %s %s %d %d %d %d %d %d\n",n1.identifiant,n1.type,n1.sexe,&n1.date_naissance.jour,&n1.date_naissance.mois,&n1.date_naissance.annee,&n1.date_vaccin.jour,&n1.date_vaccin.mois,&n1.date_vaccin.annee)!=EOF)
{if(strcmp(n1.identifiant,id)==0)
trouve=1;
else 
fprintf(f2,"%s %s %s %d %d %d %d %d %d\n",n1.identifiant,n1.type,n1.sexe,n1.date_naissance.jour,n1.date_naissance.mois,n1.date_naissance.annee,n1.date_vaccin.jour,n1.date_vaccin.mois,n1.date_vaccin.annee);

}
fclose(f);
fclose(f2);
remove(nomfich);
rename(temp,nomfich);
if (trouve)
return 1;
else return 0;
} return -1;}

void rechercher_animal(char identif[20],GtkWidget *liste)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
char Identifiant[50] ,Type[50], Sexe[50];
int Jour_Naissance,Mois_Naissance,Annee_Naissance,JourV,MoisV,AnneeV;
naissance n;
FILE *f;
store=NULL;
store=gtk_tree_view_get_model(liste);
if (store == NULL){
		
	renderer=gtk_cell_renderer_text_new ();
        column=gtk_tree_view_column_new_with_attributes      	 ("Identifiant",renderer,"text",EIDENTIFIANT,NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
       
        renderer=gtk_cell_renderer_text_new ();
        column=gtk_tree_view_column_new_with_attributes ("Type",renderer,"text",ETYPE,NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


        renderer=gtk_cell_renderer_text_new ();
        column=gtk_tree_view_column_new_with_attributes ("Sexe",renderer,"text",ESEXE,NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

        renderer=gtk_cell_renderer_text_new ();
        column=gtk_tree_view_column_new_with_attributes ("Jour_Naissance",renderer,"text",EDATENAISSANCEJOUR,NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

         
        renderer=gtk_cell_renderer_text_new ();
        column=gtk_tree_view_column_new_with_attributes ("Mois_Naissance",renderer,"text",EDATENAISSANCEMOIS,NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
           
        renderer=gtk_cell_renderer_text_new ();
        column=gtk_tree_view_column_new_with_attributes ("Annee_Naissance",renderer,"text",EDATENAISSANCEANNEE,NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

        renderer=gtk_cell_renderer_text_new ();
        column=gtk_tree_view_column_new_with_attributes ("JourV",renderer,"text",EDATEVACCINJOUR,NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

        renderer=gtk_cell_renderer_text_new ();
        column=gtk_tree_view_column_new_with_attributes ("MoisV",renderer,"text",EDATEVACCINMOIS,NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

        renderer=gtk_cell_renderer_text_new ();
        column=gtk_tree_view_column_new_with_attributes ("AnneeV",renderer,"text",EDATEVACCINANNEE,NULL);
         gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
} store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT ,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT);
            f=fopen("naissance.txt","r");
 if (f== NULL){
              return ;

}
           else {
            f=fopen("naissance.txt","a+");
            while (fscanf(f,"%s %s %s %d %d %d %d %d %d  \n",Identifiant,Type,Sexe,&Jour_Naissance,&Mois_Naissance,&Annee_Naissance,&JourV,&MoisV,&AnneeV)!=EOF)
{
if((strcmp(Identifiant,identif)==0))
{ gtk_list_store_append(store,&iter);
            gtk_list_store_set(store,&iter,EIDENTIFIANT,Identifiant,ETYPE,Type,ESEXE,Sexe,EDATENAISSANCEJOUR,Jour_Naissance,EDATENAISSANCEMOIS,Mois_Naissance,EDATENAISSANCEANNEE,Annee_Naissance,EDATEVACCINJOUR,JourV,EDATEVACCINMOIS,MoisV,EDATEVACCINANNEE,AnneeV,-1);
}}
fclose(f);

            gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
            g_object_unref(store);
}  }      





int modifierMH (naissance *n, char nomfich [])
{
FILE *f=NULL,*f1=NULL;
naissance n1;
int trouve=0;
char temp[20]="temporaire.txt";
f=fopen(nomfich,"r");
f1=fopen(temp,"w");

if(f!=NULL && f1!=NULL)
{
while(fscanf(f,"%s %s %s %d %d %d %d %d %d\n",n1.identifiant,n1.type,n1.sexe,&n1.date_naissance.jour,&n1.date_naissance.mois,&n1.date_naissance.annee,&n1.date_vaccin.jour,&n1.date_vaccin.mois,&n1.date_vaccin.annee)!=EOF)
{if(strcmp(n1.identifiant,n->identifiant)==0)
{
fprintf(f1,"%s %s %s %d %d %d %d %d %d\n",n->identifiant,n->type,n->sexe,n->date_naissance.jour,n->date_naissance.mois,n->date_naissance.annee,n->date_vaccin.jour,n->date_vaccin.mois,n->date_vaccin.annee);
trouve=1;}
else

fprintf(f1,"%s %s %s %d %d %d %d %d %d\n",n1.identifiant,n1.type,n1.sexe,n1.date_naissance.jour,n1.date_naissance.mois,n1.date_naissance.annee,n1.date_vaccin.jour,n1.date_vaccin.mois,n1.date_vaccin.annee);
}

fclose(f);
fclose(f1);
remove(nomfich);
rename(temp,nomfich);
if (trouve)
return 1;
else return 0;
}
return -1;
}


void afficher_type(GtkWidget *liste, int vache, int  veau, int chevre, int brebis)
{
	GtkCellRenderer  *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter    iter;
	GtkListStore  *store;

char Identifiant[50];
char type [20];
char sexe [20];
char DateNaissanceJour[20];
char DateNaissanceMois[20];
char DateNaissanceAnnee[20];
char DateVaccinJour[20];
char DateVaccinMois[20];
char DateVaccinAnnee[20];
store =NULL;
int jour;
int mois;
int annee;
int jourV;
int moisV;
int anneeV;
int aff;
FILE * f;


store=gtk_tree_view_get_model(liste);
if (store == NULL){
renderer = gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Identifiant",renderer,"text",EIDENTIFIANT,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


renderer = gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("type",renderer,"text",ETYPE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("sexe",renderer,"text",ESEXE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


renderer = gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Date Naissance Jour",renderer,"text",EDATENAISSANCEJOUR,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Date Naissance Mois",renderer,"text",EDATENAISSANCEMOIS,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Date Naissance Annee",renderer,"text",EDATENAISSANCEANNEE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


renderer = gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Date Vaccin Jour",renderer,"text",EDATEVACCINJOUR,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Date Vaccin Mois",renderer,"text",EDATEVACCINMOIS,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Date Vaccin Annee",renderer,"text",EDATEVACCINANNEE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
}
store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);


f=fopen("naissance.txt","r");

if (f==NULL){return;}
else
{
f=fopen("naissance.txt","a+");

while (fscanf(f,"%s %s %s %s %s %s %s %s %s\n",
Identifiant,
type,
sexe,
DateNaissanceJour,
DateNaissanceMois,
DateNaissanceAnnee,
DateVaccinJour,
DateVaccinMois,
DateVaccinAnnee)!=EOF)
{
aff=0;
if ((strcmp(type,"veau")==0 || strcmp(type,"Veau")==0) &&  veau)
aff=1;
if ((strcmp(type,"vache")==0 || strcmp(type,"Vache")==0) &&  vache)
aff=1;
if ((strcmp(type,"chevre")==0 || strcmp(type,"Chevre")==0) &&  chevre)
aff=1;
if ((strcmp(type,"brebis")==0 || strcmp(type,"Brebis")==0) &&  brebis)
aff=1;

if (aff==1)
{
gtk_list_store_append(store,&iter);
/*fflush(stdin);*/	gtk_list_store_set(store,&iter,EIDENTIFIANT,Identifiant,ETYPE,type,ESEXE,sexe,EDATENAISSANCEJOUR,DateNaissanceJour,EDATENAISSANCEMOIS,DateNaissanceMois,EDATENAISSANCEANNEE,DateNaissanceAnnee,EDATEVACCINJOUR,DateVaccinJour,EDATEVACCINMOIS,DateVaccinMois,EDATEVACCINANNEE,DateVaccinAnnee,-1);

}
}
	fclose(f);
	gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
	g_object_unref(store);

}



}




void afficherMH(char nomfich [])
{FILE* f=NULL;
f=fopen(nomfich,"a+");
naissance n;
if (f!=NULL)
{while(fscanf(f,"%s %s %s %d %d %d %d %d %d\n",n.identifiant,n.type,n.sexe,&n.date_naissance.jour,&n.date_naissance.mois,&n.date_naissance.annee,&n.date_vaccin.jour,&n.date_vaccin.mois,&n.date_vaccin.annee)!=EOF)
{printf("l identifiant est %s, le type est %s, le sexe est %s,la date de naissance est %d-%d-%d et enfin la date de son prochain vaccin est %d-%d-%d\n\n",n.identifiant,n.type,n.sexe,n.date_naissance.jour,n.date_naissance.mois,n.date_naissance.annee,n.date_vaccin.jour,n.date_vaccin.mois,n.date_vaccin.annee);
}
}fclose(f);
}

naissance * chercher (char id[], char nomfich [])
{FILE *f;
f=fopen(nomfich,"a+");
naissance *n1= malloc(sizeof(naissance));
if(f!=NULL)
{while(fscanf(f,"%s %s %s %d %d %d %d %d %d\n",n1->identifiant,n1->type,n1->sexe,&n1->date_naissance.jour,&n1->date_naissance.mois,&n1->date_naissance.annee,&n1->date_vaccin.jour,&n1->date_vaccin.mois,&n1->date_vaccin.annee)!=EOF)
{if(strcmp(n1->identifiant,id)==0)
{fclose(f); return n1;}

}fclose(f);
}
return NULL;
}


void afficher_nbre_troupeaux(int *v, int *c, int *b,int *vo, char nomfich[])
{FILE *f;
naissance n;
f=fopen(nomfich,"r");
if (f!=NULL)
{while (fscanf(f,"%s %s %s %d %d %d %d %d %d\n",n.identifiant,n.type,n.sexe,&n.date_naissance.jour,&n.date_naissance.mois,&n.date_naissance.annee,&n.date_vaccin.jour,&n.date_vaccin.mois,&n.date_vaccin.annee)!=EOF)
{if (strcmp(n.type,"vache")==0 || strcmp(n.type,"Vache")==0)
(*v)++;
else if (strcmp(n.type,"chevre")==0 || strcmp(n.type,"Chevre")==0)
(*c)++;
else if (strcmp(n.type,"brebis")==0 || strcmp(n.type,"Brebis")==0)
(*b)++;
else if (strcmp(n.type,"veau")==0 || strcmp(n.type,"Veau")==0)
(*vo)++;
}
fclose(f);
}
}

void supprimer_tr(char file_name[],char id[])
{
naissance n;
FILE* f1=NULL;
FILE* f2=NULL;
f1 = fopen("naissance.txt","r");
f2 = fopen("tmp.txt","w");
while ((fscanf(f1,"%s %s %s %d %d %d %d %d %d\n ",n.identifiant,n.type,n.sexe,&n.date_naissance.jour,&n.date_naissance.mois,&n.date_naissance.annee,&n.date_vaccin.jour,&n.date_vaccin.mois,&n.date_vaccin.annee)!=EOF)) {
if ((strcmp(id,n.identifiant) != 0))
{
fprintf(f2,"%s %s %s %d %d %d %d %d %d \n",n.identifiant,n.type,n.sexe,n.date_naissance.jour,n.date_naissance.mois,n.date_naissance.annee,n.date_vaccin.jour,n.date_vaccin.mois,n.date_vaccin.annee);
}}
fclose(f1);
fclose(f2);
remove("naissance.txt");
rename("tmp.txt","naissance.txt");
}



void  afficher_tr(GtkWidget *liste)
{
	GtkCellRenderer  *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter    iter;
	GtkListStore  *store;

char Identifiant[50];
char type [20];
char sexe [20];
char DateNaissanceJour[20];
char DateNaissanceMois[20];
char DateNaissanceAnnee[20];
char DateVaccinJour[20];
char DateVaccinMois[20];
char DateVaccinAnnee[20];
store =NULL;
int jour;
int mois;
int annee;
int jourV;
int moisV;
int anneeV;
FILE * f;


store=gtk_tree_view_get_model(liste);
if (store == NULL){
renderer = gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Identifiant",renderer,"text",EIDENTIFIANT,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


renderer = gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("type",renderer,"text",ETYPE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("sexe",renderer,"text",ESEXE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


renderer = gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Date Naissance Jour",renderer,"text",EDATENAISSANCEJOUR,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Date Naissance Mois",renderer,"text",EDATENAISSANCEMOIS,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Date Naissance Annee",renderer,"text",EDATENAISSANCEANNEE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


renderer = gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Date Vaccin Jour",renderer,"text",EDATEVACCINJOUR,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Date Vaccin Mois",renderer,"text",EDATEVACCINMOIS,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Date Vaccin Annee",renderer,"text",EDATEVACCINANNEE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
}
store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);


f=fopen("naissance.txt","r");

if (f==NULL){return;}
else
{
f=fopen("naissance.txt","a+");

while (fscanf(f,"%s %s %s %s %s %s %s %s %s\n",
Identifiant,
type,
sexe,
DateNaissanceJour,
DateNaissanceMois,
DateNaissanceAnnee,
DateVaccinJour,
DateVaccinMois,
DateVaccinAnnee)!=EOF)
{
gtk_list_store_append(store,&iter);
fflush(stdin);	gtk_list_store_set(store,&iter,EIDENTIFIANT,Identifiant,ETYPE,type,ESEXE,sexe,EDATENAISSANCEJOUR,DateNaissanceJour,EDATENAISSANCEMOIS,DateNaissanceMois,EDATENAISSANCEANNEE,DateNaissanceAnnee,EDATEVACCINJOUR,DateVaccinJour,EDATEVACCINMOIS,DateVaccinMois,EDATEVACCINANNEE,DateVaccinAnnee,-1);
}
	fclose(f);
	gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
	g_object_unref(store);

}

}

