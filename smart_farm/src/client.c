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
fprintf(f," %s %s  %s  %s  %s   %d    %d   %d    %s %s %s  \n",c.nom,c.prenom,c.username,c.password,c.email,c.d.jour,c.d.mois,c.d.annee,c.adress,c.sexe,c.lieu);
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
while ((fscanf(f1,"%s %s %s %s %s %d %d %d %s %s %s\n ",c.nom,c.prenom,c.username,c.password,c.email,&c.d.jour,&c.d.mois,&c.d.annee,c.adress,c.sexe,c.lieu)!=EOF)) {
if ((strcmp(id,c.email) != 0))
{
fprintf(f2,"%s %s %s %s %s %d %d %d %s %s %s \n",c.nom,c.prenom,c.username,c.password,c.email,c.d.jour,c.d.mois,c.d.annee,c.adress,c.sexe,c.lieu);
}}
fclose(f1);
fclose(f2);
remove("inscription.txt");
rename("tmp.txt","inscription.txt");
}

//--------------------------------------------------------------------------------------------------//
//--------------------------------rechercher--------------------------------------------------------//

void rechercher_client(char email[50],GtkWidget *liste)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
char Nom[50] ,Prenom[50], Username[50],Password[50],Lieu[50],Email[50],Adresse[50],Jour[50],Mois[50],Annee[50],Sexe[100]; 
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

renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("Lieu",renderer,"text",LIEU,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
} store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING ,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
            f=fopen("inscription.txt","r");
 if (f== NULL){
              return ;

}
           else {
            f=fopen("inscription.txt","a+");
            while (fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s \n",Nom,Prenom,Username,Password,Email,Jour,Mois,Annee,Adresse,Sexe,Lieu)!=EOF)
{
if((strcmp(Email,email)==0))
{ gtk_list_store_append(store,&iter);
            gtk_list_store_set(store,&iter,NOMCLIENT,Nom,PRENOMCLIENT,Prenom,USERNAMECLIENT,Username,PASSWORDCLIENT,Password,EMAILCLIENT,Email,DDJCLIENT,Jour,DDMCLIENT,Mois,DDACLIENT,Annee,ADRESSCLIENT,Adresse,SEXE,Sexe,LIEU,Lieu,-1);
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
while ((fscanf(f,"%s %s %s %s %s %d %d %d %s %s %s\n ",c.nom,c.prenom,c.username,c.password,c.email,&c.d.jour,&c.d.mois,&c.d.annee,c.adress,c.sexe,c.lieu)!=EOF))
{
printf("%s %s %s %s %s %d %d %d %s %s \n",c.nom,c.prenom,c.username,c.password,c.email,c.d.jour,c.d.mois,c.d.annee,c.adress,c.sexe,c.lieu);
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
char Nom[50] ,Prenom[50], Username[50],Password[50],Tel[50],Email[50],Adresse[50],Jour[50],Mois[50],Annee[50],Sexe[100],Lieu[100]; 
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
renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("Lieu",renderer,"text",LIEU,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(FMtreeview),column);
           }
           
store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING ,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
            f=fopen("inscription.txt","r");
 if (f== NULL){
              return ;

}
           else {
            f=fopen("inscription.txt","a+");
            while (fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s \n",Nom,Prenom,Username,Password,Email,Jour,Mois,Annee,Adresse,Sexe,Lieu)!=EOF)
{
            gtk_list_store_append(store,&iter);
            gtk_list_store_set(store,&iter,NOMCLIENT,Nom,PRENOMCLIENT,Prenom,USERNAMECLIENT,Username,PASSWORDCLIENT,Password,EMAILCLIENT,Email,DDJCLIENT,Jour,DDMCLIENT,Mois,DDACLIENT,Annee,ADRESSCLIENT,Adresse,SEXE,Sexe,LIEU,Lieu,-1);
}
fclose(f);
}
            gtk_tree_view_set_model(GTK_TREE_VIEW(FMtreeview),GTK_TREE_MODEL(store));
            g_object_unref(store);
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
if((strcmp(ch1,log)==0)&&(strcmp(ch2,Pw)==0)&&(strcmp("admin",Pw)!=0)&&(strcmp("admin",log)!=0))
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
char Nom[50] ,Prenom[50], Username[50],Password[50],Tel[50],Email[50],Adresse[50],Jour[50],Mois[50],Annee[50],Sexe[100],Lieu[50]; 
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

renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("Lieu",renderer,"text",LIEU,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(FMtreeview),column);
           }
           
store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING ,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
            f=fopen("inscription.txt","r");
 if (f== NULL){
              return ;

}
           else {
            f=fopen("inscription.txt","a+");
            while (fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s \n",Nom,Prenom,Username,Password,Email,Jour,Mois,Annee,Adresse,Sexe,Lieu)!=EOF)
{
            if( strcmp(Sexe,homme)==0)
			{				
			gtk_list_store_append(store,&iter);
            gtk_list_store_set(store,&iter,NOMCLIENT,Nom,PRENOMCLIENT,Prenom,USERNAMECLIENT,Username,PASSWORDCLIENT,Password,EMAILCLIENT,Email,DDJCLIENT,Jour,DDMCLIENT,Mois,DDACLIENT,Annee,ADRESSCLIENT,Adresse,SEXE,Sexe,LIEU,Lieu,-1);
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
char Nom[50] ,Prenom[50], Username[50],Password[50],Tel[50],Email[50],Adresse[50],Jour[50],Mois[50],Annee[50],Sexe[100],Lieu[50]; 
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

renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("Lieu",renderer,"text",LIEU,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(FMtreeview),column);
           }
           
store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING ,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
            f=fopen("inscription.txt","r");
 if (f== NULL){
              return ;

}
           else {
            f=fopen("inscription.txt","a+");
            while (fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s \n",Nom,Prenom,Username,Password,Email,Jour,Mois,Annee,Adresse,Sexe,Lieu)!=EOF)
{
            if( strcmp(Sexe,femme)==0)
			{				
			gtk_list_store_append(store,&iter);
            gtk_list_store_set(store,&iter,NOMCLIENT,Nom,PRENOMCLIENT,Prenom,USERNAMECLIENT,Username,PASSWORDCLIENT,Password,EMAILCLIENT,Email,DDJCLIENT,Jour,DDMCLIENT,Mois,DDACLIENT,Annee,ADRESSCLIENT,Adresse,SEXE,Sexe,LIEU,Lieu-1);
}
}
fclose(f);
}
            gtk_tree_view_set_model(GTK_TREE_VIEW(FMtreeview),GTK_TREE_MODEL(store));
            g_object_unref(store);
}

//------------------------------------------------------------------------------------------------------//
//------------------------------------------------------------------------------------------------------//

int check_useremail(char email[])
{int i;int at=0;
//g_print("\nChecking eamail\n");
for(i=0;i<=50&&email[i]!='\0';i++)
	{
	if(email[i]=='@'){at++;}
	}

if(at==1)return 1;
else return 0;
}

//------------------------------------------------------------------------------------------------------//
//------------------------------------------------------------------------------------------------------//


int Verif_Password(client c)
{
int password_ok=0;
int Maj=0;
int Min=0;
int Num=0;int i=0; long ascii = 0;
for(i=0;i<20;i++)
	{ascii = c.password[i];
	if(ascii>=64&&ascii<=90)Maj++;
	if(ascii>=97&&ascii<=122)Min++;
	if(ascii>=48&&ascii<=57)Num++;
	}
if(Maj>0 &&  Min>0  &&  Num>0  &&  strlen(c.password)>7)

password_ok=1;

return password_ok;
}



//------------------------------------------------------------------------------------------------------//
//------------------------------------------------------------------------------------------------------//
int existant(char ch[],char file_name[])
{FILE *f;
client c;
int test;
f=fopen("inscription.txt","a+");
if (f!=NULL)
{
     while (fscanf(f,"%s %s %s %s %s %d %d %d %s %s %s \n",c.nom,c.prenom,c.username,c.password,c.email,&c.d.jour,&c.d.mois,&c.d.annee,c.adress,c.sexe,c.lieu)!=EOF)
    {
      if (strcmp(c.email,ch)==0)
      {
       fclose(f);
       return 1;
      }
    }
}
else

{
return 0 ;
}
}

//------------------------------------------------------------------------------------------------------//
//------------------------------------------------------------------------------------------------------//
int existantusername(char ch[],char file_name[])
{FILE *f;
client c;
int test;
f=fopen("inscription.txt","a+");
if (f!=NULL)
{
     while (fscanf(f,"%s %s %s %s %s %d %d %d %s %s  \n",c.nom,c.prenom,c.username,c.password,c.email,&c.d.jour,&c.d.mois,&c.d.annee,c.adress,c.sexe,c.lieu)!=EOF)
    {
      if (strcmp(c.username,ch)==0)
      {
       fclose(f);
       return 1;
      }
    }
}
else

{
return 0 ;
}
}




int veriffares(char you[])
{

FILE *f=NULL;
client c;
int i=0;
f=fopen("inscription.txt","r");
if (f!=NULL)
{
        while(fscanf(f,"%s %s %s %s %s %d %d %d %s %s %s \n",c.nom,c.prenom,c.username,c.password,c.email,&c.d.jour,&c.d.mois,&c.d.annee,c.adress,c.sexe,c.lieu)!=EOF)
{
  if (strcmp(c.email,you)==0)
  {
      i=1;
      break;
  }
  else
  i=0;
}
fclose(f);

}




return i;
}













