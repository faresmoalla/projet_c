#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include "client.h"
#include<gtk/gtk.h>

void inscription_client(char file_name[],client c)
{ FILE *f;
f=fopen("inscription.txt","a+");
if(f!=NULL)
{
fprintf(f," %s %s  %s  %s  %s   %d    %d   %d    %s %s  \n",c.nom,c.prenom,c.username,c.password,c.email,c.d.jour,c.d.mois,c.d.annee,c.adress,c.sexe);
}
fclose(f);
}

//------------------------------------------------------------------------------------------------------//
//-------------------------------------Supprimer--------------------------------------------------------//
void supprimer_client(char file_name[],char id[])
{
client c;
FILE* f1=NULL;
FILE* f2=NULL;
f1 = fopen("inscription.txt","r");
f2 = fopen("tmp.txt","w");
while ((fscanf(f1,"%s %s %s %s %s %d %d %d %s %s\n ",c.nom,c.prenom,c.username,c.password,c.email,&c.d.jour,&c.d.mois,&c.d.annee,c.adress,c.sexe)!=EOF)) {
if ((strcmp(id,c.email) != 0))
{
fprintf(f2,"%s %s %s %s %s %d %d %d %s %s \n",c.nom,c.prenom,c.username,c.password,c.email,c.d.jour,c.d.mois,c.d.annee,c.adress,c.sexe);
}}
fclose(f1);
fclose(f2);
remove("inscription.txt");
rename("tmp.txt","inscription.txt");
}
////////////////////////////////
void supprimer2(client c)
{
char nom[50] ,prenom[50], user[50],pass[50],mail[50],adresse[50],sexe[100];
int ddj,ddm,dda;

FILE *f;
FILE *f1;
f = fopen("inscription.txt","r");
f1 = fopen("tmp.txt","w");
if (f==NULL || f1==NULL)
	{ 
		return;
	}
else 
	{
		while ((fscanf(f,"%s %s %s %s %s %d %d %d %s\n ",nom,prenom,user,pass,mail,&ddj,&ddm,&dda,adresse,sexe)!=EOF)) 
	{
		if(strcmp(c.email,mail)!=0) 
			{
			fprintf(f1,"%s %s %s %s %s %d %d %d %s\n ",nom,prenom,user,pass,mail,ddj,ddm,dda,adresse,sexe);
			}
	}
fclose(f);
fclose(f1);
remove("inscription.txt");
rename("tmp.txt","inscription.txt");
}
}
//--------------------------------------------------------------------------------------------------//
//--------------------------------rechercher--------------------------------------------------------//

void rechercher_client(char email[20],GtkWidget *liste)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
char Nom[50] ,Prenom[50], Username[50],Password[50],Tel[50],Email[50],Adresse[50],Jour[50],Mois[50],Annee[50],Sexe[100]; 
client c;
FILE *f;
store=NULL;
store=gtk_tree_view_get_model(liste);
if (store == NULL){
renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("Nom",renderer,"text",NOMCLIENT,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
       
   renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("Prenom",renderer,"text",PRENOMCLIENT,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


            renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("Username",renderer,"text",USERNAMECLIENT,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

   renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("Password",renderer,"text",PASSWORDCLIENT,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

         
            renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("Email",renderer,"text",EMAILCLIENT,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
           
           

            renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("Jour",renderer,"text",DDJCLIENT,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

  renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("Mois",renderer,"text",DDMCLIENT,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

  renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("Annee",renderer,"text",DDACLIENT,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

 renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("Adresse",renderer,"text",ADRESSCLIENT,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("Sexe",renderer,"text",SEXE,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
} store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING ,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
            f=fopen("inscription.txt","r");
 if (f== NULL){
              return ;

}
           else {
            f=fopen("inscription.txt","a+");
            while (fscanf(f,"%s %s %s %s %s %s %s %s %s %s \n",Nom,Prenom,Username,Password,Email,Jour,Mois,Annee,Adresse,Sexe)!=EOF)
{
if((strcmp(Email,email)==0))
{ gtk_list_store_append(store,&iter);
            gtk_list_store_set(store,&iter,NOMCLIENT,Nom,PRENOMCLIENT,Prenom,USERNAMECLIENT,Username,PASSWORDCLIENT,Password,EMAILCLIENT,Email,DDJCLIENT,Jour,DDMCLIENT,Mois,DDACLIENT,Annee,ADRESSCLIENT,Adresse,SEXE,Sexe-1);
}}
fclose(f);

            gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
            g_object_unref(store);
}  }       

//------------------------------------------------------------------------------------------------------//
//-------------------------------------afficher-----------------------------------------------------------//
void fafficher(char file_name[])
{
FILE *f;
client c;
f=fopen("inscription.txt","r");
if(f!=NULL)
{
while ((fscanf(f,"%s %s %s %s %s %d %d %d %s %s\n ",c.nom,c.prenom,c.username,c.password,c.email,&c.d.jour,&c.d.mois,&c.d.annee,c.adress,c.sexe)!=EOF))
{
printf("%s %s %s %s %s %d %d %d %s %s \n",c.nom,c.prenom,c.username,c.password,c.email,c.d.jour,c.d.mois,c.d.annee,c.adress,c.sexe);
}}
else
printf("le fichier est vide !");
fclose(f);
}


void afficher_client(GtkWidget *FMtreeview)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
client c;
char Nom[50] ,Prenom[50], Username[50],Password[50],Tel[50],Email[50],Adresse[50],Jour[50],Mois[50],Annee[50],Sexe[100]; 
store=NULL;
FILE *f;
store=gtk_tree_view_get_model(FMtreeview);
if (store == NULL)
{    
            renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("Nom",renderer,"text",NOMCLIENT,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(FMtreeview),column);
          renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("Prenom",renderer,"text",PRENOMCLIENT,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(FMtreeview),column);

            renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("User",renderer,"text",USERNAMECLIENT,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(FMtreeview),column);
   renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("Password",renderer,"text",PASSWORDCLIENT,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(FMtreeview),column);

                     renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("Elail",renderer,"text",EMAILCLIENT,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(FMtreeview),column);
                    
            renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("Jour",renderer,"text",DDJCLIENT,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(FMtreeview),column);

  renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("Mois",renderer,"text",DDMCLIENT,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(FMtreeview),column);
  renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("Annee",renderer,"text",DDACLIENT,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(FMtreeview),column);
 renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("Adresse",renderer,"text",ADRESSCLIENT,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(FMtreeview),column);
renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("Sexe",renderer,"text",SEXE,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(FMtreeview),column);
           }
           
store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING ,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
            f=fopen("inscription.txt","r");
 if (f== NULL){
              return ;

}
           else {
            f=fopen("inscription.txt","a+");
            while (fscanf(f,"%s %s %s %s %s %s %s %s %s %s \n",Nom,Prenom,Username,Password,Email,Jour,Mois,Annee,Adresse,Sexe)!=EOF)
{
            gtk_list_store_append(store,&iter);
            gtk_list_store_set(store,&iter,NOMCLIENT,Nom,PRENOMCLIENT,Prenom,USERNAMECLIENT,Username,PASSWORDCLIENT,Password,EMAILCLIENT,Email,DDJCLIENT,Jour,DDMCLIENT,Mois,DDACLIENT,Annee,ADRESSCLIENT,Adresse,SEXE,Sexe,-1);
}
fclose(f);
}
            gtk_tree_view_set_model(GTK_TREE_VIEW(FMtreeview),GTK_TREE_MODEL(store));
            g_object_unref(store);
}

//------------------------------------------------------------------------------------------------------//
//------------------------------------------------------------------------------------------------------//
client rechercher2(char email[],char nom_fichier[])
{
FILE *f;

client c;
c.d.jour=-1;
f=fopen("inscription.txt","r");

if(f !=NULL)
{
while (fscanf(f,"%s %s %s %s %s %d %d %d %s %s  \n",c.nom,c.prenom,c.username,c.password,c.email,&c.d.jour,&c.d.mois,&c.d.annee,c.adress,c.sexe)!=EOF)
  {
if(strcmp(email,c.email)==0)
  {
fclose(f);
return c ;
  }
  }

fclose(f);
}
return c ;
}
//------------------------------------------------------------------------------------------------------//
//------------------------verifier le mot de passe et username dans authentification------------------//
   int verif(char log[] , char Pw[] )
{
int trouve=-1;
FILE *f=NULL;
char ch1[20];
char ch2[20];
f=fopen("inscription.txt","r");
if(f!=NULL)
 {
while(fscanf(f," %s %s ",ch1,ch2)!=EOF)
{
if((strcmp(ch1,log)==0)&&(strcmp(ch2,Pw)==0))
trouve=1;
}
fclose(f);
}
return (trouve);
}


//------------------------------------------------------------------------------------------------------//
//------------------------------------------------------------------------------------------------------//


void afficher_client_homme(GtkWidget *FMtreeview)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;

char homme[20]="Homme";
client c;
char Nom[50] ,Prenom[50], Username[50],Password[50],Tel[50],Email[50],Adresse[50],Jour[50],Mois[50],Annee[50],Sexe[100]; 
store=NULL;
FILE *f;
store=gtk_tree_view_get_model(FMtreeview);
if (store == NULL)
{    
            renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("Nom",renderer,"text",NOMCLIENT,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(FMtreeview),column);
          renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("Prenom",renderer,"text",PRENOMCLIENT,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(FMtreeview),column);

            renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("Username",renderer,"text",USERNAMECLIENT,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(FMtreeview),column);
   renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("Password",renderer,"text",PASSWORDCLIENT,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(FMtreeview),column);

                     renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("Email",renderer,"text",EMAILCLIENT,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(FMtreeview),column);
                    
            renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("Jour",renderer,"text",DDJCLIENT,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(FMtreeview),column);

  renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("Mois",renderer,"text",DDMCLIENT,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(FMtreeview),column);
  renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("Annee",renderer,"text",DDACLIENT,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(FMtreeview),column);
 renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("Adresse",renderer,"text",ADRESSCLIENT,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(FMtreeview),column);
renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("Sexe",renderer,"text",SEXE,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(FMtreeview),column);
           }
           
store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING ,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
            f=fopen("inscription.txt","r");
 if (f== NULL){
              return ;

}
           else {
            f=fopen("inscription.txt","a+");
            while (fscanf(f,"%s %s %s %s %s %s %s %s %s %s \n",Nom,Prenom,Username,Password,Email,Jour,Mois,Annee,Adresse,Sexe)!=EOF)
{
            if( strcmp(Sexe,homme)==0)
			{				
			gtk_list_store_append(store,&iter);
            gtk_list_store_set(store,&iter,NOMCLIENT,Nom,PRENOMCLIENT,Prenom,USERNAMECLIENT,Username,PASSWORDCLIENT,Password,EMAILCLIENT,Email,DDJCLIENT,Jour,DDMCLIENT,Mois,DDACLIENT,Annee,ADRESSCLIENT,Adresse,SEXE,Sexe,-1);
}
}
fclose(f);
}
            gtk_tree_view_set_model(GTK_TREE_VIEW(FMtreeview),GTK_TREE_MODEL(store));
            g_object_unref(store);
}


//------------------------------------------------------------------------------------------------------//
//------------------------------------------------------------------------------------------------------//




void afficher_client_femme(GtkWidget *FMtreeview)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;

char femme[20]="Femme";
client c;
char Nom[50] ,Prenom[50], Username[50],Password[50],Tel[50],Email[50],Adresse[50],Jour[50],Mois[50],Annee[50],Sexe[100]; 
store=NULL;
FILE *f;
store=gtk_tree_view_get_model(FMtreeview);
if (store == NULL)
{    
            renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("Nom",renderer,"text",NOMCLIENT,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(FMtreeview),column);
          renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("Prenom",renderer,"text",PRENOMCLIENT,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(FMtreeview),column);

            renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("Username",renderer,"text",USERNAMECLIENT,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(FMtreeview),column);
   renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("Password",renderer,"text",PASSWORDCLIENT,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(FMtreeview),column);

                     renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("Email",renderer,"text",EMAILCLIENT,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(FMtreeview),column);
                    
            renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("Jour",renderer,"text",DDJCLIENT,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(FMtreeview),column);

  renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("Mois",renderer,"text",DDMCLIENT,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(FMtreeview),column);
  renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("Annee",renderer,"text",DDACLIENT,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(FMtreeview),column);
 renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("Adresse",renderer,"text",ADRESSCLIENT,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(FMtreeview),column);
renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("Sexe",renderer,"text",SEXE,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(FMtreeview),column);
           }
           
store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING ,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
            f=fopen("inscription.txt","r");
 if (f== NULL){
              return ;

}
           else {
            f=fopen("inscription.txt","a+");
            while (fscanf(f,"%s %s %s %s %s %s %s %s %s %s \n",Nom,Prenom,Username,Password,Email,Jour,Mois,Annee,Adresse,Sexe)!=EOF)
{
            if( strcmp(Sexe,femme)==0)
			{				
			gtk_list_store_append(store,&iter);
            gtk_list_store_set(store,&iter,NOMCLIENT,Nom,PRENOMCLIENT,Prenom,USERNAMECLIENT,Username,PASSWORDCLIENT,Password,EMAILCLIENT,Email,DDJCLIENT,Jour,DDMCLIENT,Mois,DDACLIENT,Annee,ADRESSCLIENT,Adresse,SEXE,Sexe,-1);
}
}
fclose(f);
}
            gtk_tree_view_set_model(GTK_TREE_VIEW(FMtreeview),GTK_TREE_MODEL(store));
            g_object_unref(store);
}

//------------------------------------------------------------------------------------------------------//
//------------------------------------------------------------------------------------------------------//
























