#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonction.h"
#include <gtk/gtk.h>
void ajouter(char file[],capteur c)
{

FILE *f;
 f=fopen("file.txt","a+");

if (f!=NULL)
  {
	fprintf(f,"%s %s %s %s %d %d %d \n",c.captID,c.captType,c.captMarque,c.valeur,c.Mdate_ajout.jour,c.Mdate_ajout.mois,c.Mdate_ajout.annee);       //ecriture dans le fichier
  }

	fclose(f);     //fermeture du fichier

}


capteur creation()
{
capteur c;
Mdate Mdate_ajout;

printf("ID du capteur:\n");
fflush(stdin);
scanf("%s",c.captID);

printf("type du capteur:\n");
fflush(stdin);
scanf("%s",c.captType);

printf("marque du capteur:\n");
fflush(stdin);
scanf("%s",c.captMarque);

printf("Valeur = \n");
scanf("%s",c.valeur);

printf("donner la date d'ajout : \n");
scanf("%d %d %d",&c.Mdate_ajout.jour,&c.Mdate_ajout.mois,&c.Mdate_ajout.annee);

return(c);
}
/*void afficher(char file[] )
{
capteur c;
FILE *f;
 f=fopen("file.txt","a+");
if(f !=NULL)
{
	while(fscanf(f,"%s %s %s %d %d %d %d \n",c.captID,c.captType,c.captMarque,&c.valeur,&c.date_ajout.jour,&c.date_ajout.mois,&c.date_ajout.annee)!=EOF)
	  {//parcours du fichier 
    		printf("%s %s %s %d %d %d %d \n",c.captID,c.captType,c.captMarque,c.valeur,c.date_ajout.jour,c.date_ajout.mois,c.date_ajout.annee);
  	  }	
}

}*/

enum
{
ID,
Marque,
Type,
Valeur,
Jour,
Mois,
Annee,
COLUMNS
};

void afficherhum(GtkWidget *liste)
{

GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;


	char captID[20];
	char captMarque[20];
	char captType[20];
	char valeur[20];
	int jour;
	int mois;
	int annee;
 

char hum[20]="Humidite";
capteur c;
store=NULL;
FILE *f;





store=gtk_tree_view_get_model(liste);
if(store==NULL)
{
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("ID",renderer,"text",ID,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Type",renderer,"text",Type,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Marque",renderer,"text",Marque,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Valeur",renderer,"text",Valeur,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Jour",renderer,"text",Jour,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Mois",renderer,"text",Mois,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Annee",renderer,"text",Annee,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
}
store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT);

f=fopen("file.txt","r");
if(f ==NULL)
{
return;
}
else
{
	f=fopen("file.txt","a+");
	while(fscanf(f,"%s %s %s %s %d %d %d \n",captID,captType,captMarque,valeur,&jour,&mois,&annee)!=EOF)
	  {
		
		if( strcmp(captType,hum)==0)
			{				
			gtk_list_store_append(store,&iter);			    gtk_list_store_set(store,&iter,ID,captID,Type,captType,Marque,captMarque,Valeur,valeur,Jour,jour,Mois,mois,Annee,annee,-1);
			}


	  }
	fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref(store);
}


}


void supprimer3(char file[],char IDs[20])
{

capteur c;
FILE *b;
FILE *f;
f=fopen("file.txt","r");
b=fopen("tmp.txt","a+");

    while (fscanf(f,"%s %s %s %s %d %d %d \n",c.captID,c.captType,c.captMarque,c.valeur,&c.Mdate_ajout.jour,&c.Mdate_ajout.mois,&c.Mdate_ajout.annee)!=EOF)
	{
	if(strcmp(IDs,c.captID)!=0)
          { 
		fprintf(b,"%s %s %s %s %d %d %d \n",c.captID,c.captType,c.captMarque,c.valeur,c.Mdate_ajout.jour,c.Mdate_ajout.mois,c.Mdate_ajout.annee);

	  }
	}
fclose(b);
fclose(f);
remove("file.txt");
rename("tmp.txt","file.txt");
}
/*
void supprimer(capteur c)
{
char IDs[20];
FILE *f;
FILE *b;

f=fopen("file.txt","r");
b=fopen("tmp.txt","a+");
if (f!=NULL)
    {
	    printf("donner ID du Capteur que vous voulez supprimer : ");
            scanf("%s",IDs);
    while (fscanf(f,"%s %s %s \n",c.captID,c.captType,c.captMarque)!=EOF)
	{
	if(strcmp(IDs,c.captID)!=0)
          { fprintf(b,"%s %s %s \n",c.captID,c.captType,c.captMarque);

}
}
}
fclose(b);
fclose(f);
remove("file.txt");
rename("tmp.txt","file.txt");
}
*/
void supprimer1(capteur c)
{
char id[20];
char type[20];
char marque[20];
char valeur[20];
int jour;
int mois;
int annee;
Mdate Mdate_ajout;
FILE *f;
FILE *g;

f=fopen("file.txt","r");
g=fopen("tmp.txt","w");
if (f==NULL || g==NULL)
{
return;
}
else{
	while(fscanf(f,"%s %s %s %s %d %d %d \n",id,type,marque,valeur,&jour,&mois,&annee)!=EOF)
	{
		if( strcmp(c.captID,id)!=0 || strcmp(c.captType,type)!=0 || strcmp(c.captMarque,marque)!=0 || strcmp(c.valeur,valeur)!=0 || jour!=c.Mdate_ajout.jour || mois!=c.Mdate_ajout.mois ||annee!=c.Mdate_ajout.annee)
fprintf(g," %s %s %s %s %d %d %d \n",id,type,marque,valeur,jour,mois,annee );
	}
	fclose(f);
	fclose(g);
remove("file.txt");
rename("tmp.txt","file.txt");
}
}


void supprimer_capt(capteur c)
{
char id[20];
char type[20];
char marque[20];
char valeur[20];
int jour;
int mois;
int annee;
Mdate Mdate_ajout;
FILE *f;
FILE *g;
capteur s;

f=fopen("file.txt","r");
g=fopen("tmp.txt","w");
if (f==NULL || g==NULL)
{
return;
}
else{
	while(fscanf(f,"%s %s %s %s %d %d %d \n",id,type,marque,valeur,&jour,&mois,&annee)!=EOF)
	{
		if( strcmp(c.captID,id)!=0) 
			{
			fprintf(g," %s %s %s %s %d %d %d \n",id,type,marque,valeur,jour,mois,annee );
			}
	}
	fclose(f);
	fclose(g);
remove("file.txt");
rename("tmp.txt","file.txt");
}
}









void rechercher(char file[] ,char id[])
{
FILE *f;
capteur c;
f=fopen("file.txt","r");
if(f !=NULL)
{
	while (fscanf(f,"%s %s %s %d %d %d \n",c.captID,/*c.captType,*/c.captMarque,c.valeur,&c.Mdate_ajout.jour,&c.Mdate_ajout.mois,&c.Mdate_ajout.annee)!=EOF)
	   {
		if(strcmp(id,c.captID)==0)
		   {
	printf("les donneés du capteur que vous rechercher est  %s %s %s %s %d %d %d \n",c.captID,c.captType,c.captMarque,c.valeur,c.Mdate_ajout.jour,c.Mdate_ajout.mois,c.Mdate_ajout.annee);
		   }
	   }
	fclose(f); 		 

}

}
capteur rechercher1(char id[],char nom_fichier[])
{
FILE *f;

capteur c;
c.Mdate_ajout.jour=-1;
//char nom_fichier[20]="file.txt";
f=fopen("file.txt","r");

if(f !=NULL)
{
	while (fscanf(f,"%s %s %s %s %d %d %d \n",c.captID,c.captType,c.captMarque,c.valeur,&c.Mdate_ajout.jour,&c.Mdate_ajout.mois,&c.Mdate_ajout.annee)!=EOF)
	   {
		if(strcmp(id,c.captID)==0)
		   {
			fclose(f);
			return c ;
		   }
	   }

	fclose(f);
}
return c ;

}
/*
void modifier(char file[],capteur c)
{
/*FILE*f;
char IDs[20];
 supprimer(f,IDs);
 ajouter(f,c);

FILE*f;
FILE*b;
capteur s;
f=fopen("file.txt","r");
b=fopen("tempo.txt","a+");

if(f !=NULL)
{
	printf("capteur ID:");
	scanf("%s",s.captID);
	while (fscanf(f,"%s %s %s  %d %d %d %d \n",c.captID/*,c.captType,c.captMarque,c.valeur,&c.Mdate_ajout.jour,&c.Mdate_ajout.mois,&c.Mdate_ajout.annee)!=EOF)
	   {
		if(strcmp(s.captID,c.captID)==0)
		{
			printf("ID du capteur:\n");
			fflush(stdin);
			scanf("%s",s.captID);
			/*
			printf("type du capteur:\n");
			fflush(stdin);
			scanf("%s",s.captType);
			
			printf("marque du capteur:\n");
			fflush(stdin);
			scanf("%s",s.captMarque);

			printf("Valeur = \n");
			scanf("%d",&s.valeur);

			printf("donner la date d'ajout : \n");
			scanf("%d %d %d",&s.Mdate_ajout.jour,&s.Mdate_ajout.mois,&s.Mdate_ajout.annee);
			fprintf(b,"%s %s %s %d %d %d \n",s.captID,/*s.captType,s.captMarque,s.valeur,s.Mdate_ajout.jour,s.Mdate_ajout.mois,s.Mdate_ajout.annee);
		}
		else
			fprintf(b,"%s %s %s %d %d %d %d \n",c.captID,/*c.captType,c.captMarque,c.valeur,c.Mdate_ajout.jour,c.Mdate_ajout.mois,c.Mdate_ajout.annee);
	   }
}
fclose(f);
fclose(b);
remove("file.txt");
rename("tempo.txt","file.txt");
}
*/


/*void afficher_captAlarm()
{
etatAlarm al;
capteur c;
FILE *f;
FILE *A;

char ID[20];
int valmin,valmax;
int captvalenr;
A=fopen("etatAlarm.txt","a+");
f=fopen("file.txt","r");

if(f!=NULL)
{printf("capteur ID: ");
scanf("%s",ID);
printf("Entrer l'intervalle des valeurs Alarmantes:\n");
printf("le minimum est: ");
scanf("%d",&valmin);
printf("le maximum est: ");
scanf("%d",&valmax);
printf("valeur enregistré ");
scanf("%d",&captvalenr);

while (fscanf(f,"%s %s %s \n",c.captID,c.captType,c.captMarque)!=EOF)
	   {
		if(strcmp(ID,c.captID)==0)
		   {
			if( (captvalenr>=valmin)&&(captvalenr<=valmax) )
			 {
				printf("le capteur n'est pas alarmant\n");
				al.etatAlarma=0;
				strcpy(al.captIDalarm,ID);
				fprintf(A,"%s %d \n",al.captIDalarm,al.etatAlarma);	
			 }
			 else
			 {	
				printf("le capteur est alarmant\n");
				al.etatAlarma=1;
				strcpy(al.captIDalarm,ID);
				fprintf(A,"%s %d \n",al.captIDalarm,al.etatAlarma);
			 }
		   }
	   }
fclose(f);
fclose(A);
}

A=fopen("etatAlarm.txt","r");
if(A!=NULL)
{
 while (fscanf(A,"%s %d \n",al.captIDalarm,&al.etatAlarma)!=EOF)
	{
		printf("capteur ID: %s | capteur etat (1 alarmant / 0 non alarmant): %d \n",al.captIDalarm,al.etatAlarma);
	}
fclose(A);
}

}
*/


void rechercher_capteur(char IDa[20],GtkWidget *liste)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;


	char captID[20];
	char captMarque[20];
	char captType[20];
	char valeur[20];
	int jour;
	int mois;
	int annee;
 


capteur c;
store=NULL;
FILE *f;


store=gtk_tree_view_get_model(liste);
if(store==NULL)
{
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("ID",renderer,"text",ID,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Type",renderer,"text",Type,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Marque",renderer,"text",Marque,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);



renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Valeur",renderer,"text",Valeur,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Jour",renderer,"text",Jour,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Mois",renderer,"text",Mois,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Annee",renderer,"text",Annee,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
}
store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT);

f=fopen("file.txt","r");
if(f ==NULL)
{
return;
}
else
{
	f=fopen("file.txt","a+");
	while(fscanf(f,"%s %s %s %s %d %d %d \n",captID,captType,captMarque,valeur,&jour,&mois,&annee)!=EOF)
	  {
if((strcmp(captID,IDa)==0))
{
gtk_list_store_append(store,&iter);			   gtk_list_store_set(store,&iter,ID,captID,Type,captType,Marque,captMarque,Valeur,valeur,Jour,jour,Mois,mois,Annee,annee,-1);
	  }
	  }
	fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref(store);
}


}


void afficher(GtkWidget *liste)
{

GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;


	char captID[20];
	char captMarque[20];
	char captType[20];
	char valeur[20];
	int jour;
	int mois;
	int annee;
 


capteur c;
store=NULL;
FILE *f;





store=gtk_tree_view_get_model(liste);
if(store==NULL)
{
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("ID",renderer,"text",ID,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Type",renderer,"text",Type,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Marque",renderer,"text",Marque,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Valeur",renderer,"text",Valeur,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Jour",renderer,"text",Jour,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Mois",renderer,"text",Mois,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Annee",renderer,"text",Annee,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
}
store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT);

f=fopen("file.txt","r");
if(f ==NULL)
{
return;
}
else
{
	f=fopen("file.txt","a+");
	while(fscanf(f,"%s %s %s %s %d %d %d \n",captID,captType,captMarque,valeur,&jour,&mois,&annee)!=EOF)
	  {
gtk_list_store_append(store,&iter);			    gtk_list_store_set(store,&iter,ID,captID,Type,captType,Marque,captMarque,Valeur,valeur,Jour,jour,Mois,mois,Annee,annee,-1);
			

	  }
	fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref(store);
}


}

void affichertmp(GtkWidget *liste)
{

GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;


	char captID[20];
	char captMarque[20];
	char captType[20];
	char valeur[20];
	int jour;
	int mois;
	int annee;
 

char temp[20]="Temperature";
capteur c;
store=NULL;
FILE *f;





store=gtk_tree_view_get_model(liste);
if(store==NULL)
{
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("ID",renderer,"text",ID,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Type",renderer,"text",Type,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Marque",renderer,"text",Marque,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Valeur",renderer,"text",Valeur,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Jour",renderer,"text",Jour,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Mois",renderer,"text",Mois,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Annee",renderer,"text",Annee,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
}
store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT);

f=fopen("file.txt","r");
if(f ==NULL)
{
return;
}
else
{
	f=fopen("file.txt","a+");
	while(fscanf(f,"%s %s %s %s %d %d %d \n",captID,captType,captMarque,valeur,&jour,&mois,&annee)!=EOF)
	  {
		
		if( strcmp(captType,temp)==0)
			{				
			gtk_list_store_append(store,&iter);			    gtk_list_store_set(store,&iter,ID,captID,Type,captType,Marque,captMarque,Valeur,valeur,Jour,jour,Mois,mois,Annee,annee,-1);
			}


	  }
	fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref(store);
}


}

/*
enum
{
IDs,
Types,
Marques,
Valeurs,
Jours,
Moiss,
Annees,
COLUMNSs
};

void affiche_alarmant(GtkWidget *liste)
{

GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;

char temp[20]="Temperature";
char hum[20]="Humidite";
char id[20];
char val[20];
int jour;
int mois;
int annee;
 
store=NULL;
FILE *f;
capteuralarmant a;
char captID[20];
char captMarque[20];
char captType[20];
char valeur[20];




store=gtk_tree_view_get_model(liste);
if(store==NULL)
{
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("ID",renderer,"text",IDs,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);



renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Type",renderer,"text",Types,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Marque",renderer,"text",Marques,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Valeur",renderer,"text",Valeurs,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Jour",renderer,"text",Jours,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Mois",renderer,"text",Moiss,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Annee",renderer,"text",Annees,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


}
store=gtk_list_store_new(COLUMNSs,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT);
//capteur_alarmant(a);
f=fopen("file.txt","r");
if(f ==NULL)
{
return;
}
else
{
f=fopen("file.txt","a+");
while(fscanf(f,"%s %s %s %s %d %d %d \n",captID,captType,captMarque,valeur,&jour,&mois,&annee)!=EOF)
 {

if(  ((strcmp(captType,temp)==0) && ( (atoi(valeur)<0) || (atoi(valeur)>50) ) ) || ( (strcmp(captType,hum)==0) &&( (atoi(valeur)<40) || (atoi(valeur)>90) ) ))
{
gtk_list_store_append(store,&iter);    gtk_list_store_set(store,&iter,ID,captID,Type,captType,Marque,captMarque,Valeur,valeur,Jour,jour,Mois,mois,Annee,annee,-1);
}


 }
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref(store);
}


}
*/








