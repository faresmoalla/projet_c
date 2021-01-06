#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"ouvrier.h"
#include"absence.h"
#include<gtk/gtk.h>
#include"absenteisme.h"


///////////////////////////////////////////////////////
void ajouter_ouvrier(ouvrier o,char file_ouvrier[])
{FILE *f;
 f=fopen(file_ouvrier,"a+");
   if(f!=NULL)
   {
    fprintf(f,"%s %s %d %d %d %s %s %s %s %s %s %s %s \n", o.nom,o.prenom,o.D.jour,o.D.mois,o.D.annee,o.lieu_n,o.adresse,o.n_cin,o.n_tel,o.permis,o.affectation,o.fonction,o.nh_travail);

   }
fclose(f);
}
///////////////////////////////////////////////////////

void RKsupprimer(char ouvrier_sup[],char file_ouvrier[])   
{FILE* f1=NULL;
FILE* f2=NULL;
ouvrier o;


f1=fopen(file_ouvrier,"a+");
f2=fopen("tmp.txt","a+");

//if(f1!=NULL)
while(fscanf(f1,"%s %s %d %d  %d %s %s %s %s %s %s %s %s\n",o.nom,o.prenom,&o.D.jour,&o.D.mois,&o.D.annee,o.lieu_n,o.adresse,o.n_cin,o.n_tel,o.permis,o.affectation,o.fonction,o.nh_travail)!=EOF)
{if(strcmp(o.n_cin,ouvrier_sup) != 0)
{fprintf(f2,"%s %s %d  %d  %d %s %s %s %s %s %s %s %s \n", o.nom,o.prenom,o.D.jour,o.D.mois,o.D.annee,o.lieu_n,o.adresse,o.n_cin,o.n_tel,o.permis,o.affectation,o.fonction,o.nh_travail);
}


}
 	fclose(f1);
 	fclose(f2);
	remove(file_ouvrier);
 	rename("tmp.txt",file_ouvrier);
 	
 
}
////////////////////////////////////////////////
void cherche_ouvrier(char cherche[],GtkWidget *treeview,char file_ouvrier[])
{GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
ouvrier o;
char nom[20];
char prenom[20];
char jour[20];
char  mois[20];
char  annee[20];
char lieu_n[20]; 
char adresse[20];
char n_cin[20];
char n_tel[20];
char permis[20];
char affectation[20];
char fonction[200];
char nh_travail[2];
store=NULL;
FILE *f;
	store = gtk_tree_view_get_model(treeview);
if (store == NULL)
{    
            renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("nom",renderer,"text",NOMOUVRIER,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(treeview),column);
       
            renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("prenom",renderer,"text",PRENOMOUVRIER,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(treeview),column);

            renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("jour",renderer,"text",JOUROUVRIER,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(treeview),column);

            renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("mois",renderer,"text",MOISOUVRIER,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(treeview),column);

            renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("annee",renderer,"text",ANNEEOUVRIER,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(treeview),column);
           
            renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("lieu_n",renderer,"text",LIEUOUVRIER,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(treeview),column);

            renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("adresse",renderer,"text",ADRESSEOUVRIER,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(treeview),column);

            renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("n_cin",renderer,"text",CINMOUVRIER,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(treeview),column);

           renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("n_tel",renderer,"text",NUMEROOUVRIER,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(treeview),column);

            renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("permis",renderer,"text",PERMISOUVRIER,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(treeview),column);

            renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("affectation",renderer,"text",AFFECTATION,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(treeview),column);

            renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("fonction",renderer,"texte",FONCTION,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(treeview),column);

            renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("nh_travail",renderer,"texte",HEURESTRAVAIL,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(treeview),column);
           
}
           
store = gtk_list_store_new(COLUMN,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING ,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
            f=fopen( file_ouvrier,"a+");
 if (f== NULL)
  {
   return ;
  }
           else {
            f=fopen(file_ouvrier,"a+");
                 while (fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s %s %s \n",nom,prenom,jour,mois,annee,lieu_n,adresse,n_cin,n_tel,permis,affectation,fonction,nh_travail)!=EOF)
                 {
	          if(strcmp(n_cin,cherche)==0)
                  {
                 gtk_list_store_append(store,&iter);
                                           gtk_list_store_set(store,&iter,NOMOUVRIER,nom,PRENOMOUVRIER,prenom,JOUROUVRIER,jour,MOISOUVRIER,mois,ANNEEOUVRIER,annee,LIEUOUVRIER,lieu_n,ADRESSEOUVRIER,adresse,CINMOUVRIER,n_cin,NUMEROOUVRIER,n_tel,PERMISOUVRIER,permis,AFFECTATION,affectation,FONCTION,fonction,HEURESTRAVAIL,nh_travail-1);
                 }}
fclose(f);

            gtk_tree_view_set_model(GTK_TREE_VIEW(treeview),GTK_TREE_MODEL(store));
            g_object_unref(store);


}}
//////////////////////////////////////////////////////////////

int modifier_ouvrier(ouvrier* o,char file_ouvrier[])
{
FILE * f;
FILE * f1;
ouvrier o2;
int trouve=0;
char temp[20]="temp.txt";
f=fopen(file_ouvrier,"a+");
f1=fopen(temp,"a+");
if(f!=NULL && f1!=NULL)
{
while (fscanf(f,"%s %s %d %d %d %s %s %s %s %s %s %s %s \n",o2.nom,o2.prenom,&o2.D.jour,&o2.D.mois,&o2.D.annee,o2.lieu_n,o2.adresse,o2.n_cin,o2.n_tel,o2.permis,o2.affectation,o2.fonction,o2.nh_travail)!=EOF)
{
if (strcmp(o2.n_cin,o->n_cin)==0)
{
fprintf(f1,"%s %s %d %d %d %s %s %s %s %s %s %s %s \n", o->nom,o->prenom,o->D.jour,o->D.mois,o->D.annee,o->lieu_n,o->adresse,o->n_cin,o->n_tel,o->permis,o->affectation,o->fonction,o->nh_travail);
trouve=-1;}
else
{
fprintf(f1,"%s %s %d %d %d %s %s %s %s %s %s %s %s \n", o2.nom,o2.prenom,o2.D.jour,o2.D.mois,o2.D.annee,o2.lieu_n,o2.adresse,o2.n_cin,o2.n_tel,o2.permis,o2.affectation,o2.fonction,o2.nh_travail);
}
}
fclose(f);
fclose(f1);
remove(file_ouvrier);
rename(temp,file_ouvrier);
if(trouve)
{return 1;}
else
{return 0;}

}
return -1;

}
///////////////////////////////////////////////
/*void pointer_ouvrier(absence p)
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

}*/
////////////////////////////////////////////////////////////////////////////







void absents(int id ,absence2 a,float *taux_absenteisme)
{
int j=0 ;
int i=0;

FILE *f;
f=fopen("absenteisme.txt","r");
if(f!=NULL)
{
while(fscanf(f,"%d  %d  %d  %d  %d \n",&a.n_cin,&a.jour,&a.mois,&a.annee,&a.valeur)!= EOF )
{
if(id == a.n_cin )
{i++;}

}

}
fclose(f);
f=fopen("absenteisme.txt","r");
if(f!=NULL)
{
while(fscanf(f,"%d  %d  %d  %d  %d \n",&a.n_cin,&a.jour,&a.mois,&a.annee,&a.valeur)!= EOF )
{
if(id == a.n_cin && a.valeur==1)
{j++;}

}

}
fclose(f);
*taux_absenteisme=((float)j/i)*100;

}





/////////////////////////////////////////////////////////


/*void nombre_ouvrier(absence a ,int *nb_ouvrier )
{int i=1;
FILE *f;
f=fopen("absenteisme.txt","r");
if(f!=NULL)
{
while(fscanf(f,"%d  %d  %d  %d  %d \n",&a.n_cin,&a.jour,&a.mois,&a.annee,&a.valeur)!= EOF )
{

  if(i == a.n_cin) 
 {    i++ ;}
else
 {fclose(f);}
}}  
*nb_ouvrier=i-1;

}*/



//////////////////////////////////////////////////////////////////////
void affiche_ouvrier(GtkWidget *treeview,char file_ouvrier[])
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
ouvrier o;
char nom[20];
char prenom[20];
char jour[20];
char mois[20];
char annee[20];
char lieu_n[20]; 
char adresse[20];
char n_cin[20];
char n_tel[20];
char permis[20];
char affectation[20];
char fonction[200];
char nh_travail[10];
store=NULL;
FILE *f;
	store = gtk_tree_view_get_model(treeview);
if (store == NULL)
{    
            renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("Nom",renderer,"text",NOMOUVRIER,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(treeview),column);
       
            renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("Prenom",renderer,"text",PRENOMOUVRIER,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(treeview),column);

            renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("jour",renderer,"text",JOUROUVRIER,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(treeview),column);

            renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("mois",renderer,"text",MOISOUVRIER,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(treeview),column);

            renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("annee",renderer,"text",ANNEEOUVRIER,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(treeview),column);
           
            renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("lieu_n",renderer,"text",LIEUOUVRIER,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(treeview),column);

            renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("adresse",renderer,"text",ADRESSEOUVRIER,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(treeview),column);

            renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("n_cin",renderer,"text",CINMOUVRIER,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(treeview),column);

            renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("n_tel",renderer,"text",NUMEROOUVRIER,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(treeview),column);

	    renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("permis",renderer,"text",PERMISOUVRIER,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(treeview),column);

            renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("affectation",renderer,"text",AFFECTATION,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(treeview),column);

            renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("fonction",renderer,"text",FONCTION,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(treeview),column);

            renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("nh_travail",renderer,"text",HEURESTRAVAIL,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(treeview),column);
           
}
           
store = gtk_list_store_new(COLUMN,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING ,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
            f=fopen( file_ouvrier,"r");
 if (f== NULL)
  {
   return ;
  }
           else {
            f=fopen(file_ouvrier,"a+");
                 while (fscanf(f,"%s  %s  %s  %s  %s  %s  %s  %s  %s  %s  %s  %s %s  \n",nom,prenom,jour,mois,annee,lieu_n,adresse,n_cin,n_tel,permis,affectation,fonction,nh_travail)!=EOF)
                 {
                 gtk_list_store_append(store,&iter);
                                           gtk_list_store_set(store,&iter,NOMOUVRIER,nom,PRENOMOUVRIER,prenom,JOUROUVRIER,jour,MOISOUVRIER,mois,ANNEEOUVRIER,annee,LIEUOUVRIER,lieu_n,ADRESSEOUVRIER,adresse,CINMOUVRIER,n_cin,NUMEROOUVRIER,n_tel,PERMISOUVRIER,permis,AFFECTATION,affectation,FONCTION,fonction,HEURESTRAVAIL,nh_travail,-1);
                 }
fclose(f);
}
            gtk_tree_view_set_model(GTK_TREE_VIEW(treeview),GTK_TREE_MODEL(store));
            g_object_unref(store);
}
///////////////////////////////////////////////////////////////////////////////////////////////
int recherche_ajout_ouvrier(char cherche[],char file_ouvrier[])
{FILE *f;
ouvrier o;
int teste=0;
f=fopen(file_ouvrier,"a+");
if (f!=NULL)
{
     while (fscanf(f,"%s %s %d %d  %d %s %s %s %s %s %s %s %s\n",o.nom,o.prenom,&o.D.jour,&o.D.mois,&o.D.annee,o.lieu_n,o.adresse,o.n_cin,o.n_tel,o.permis,o.affectation,o.fonction,o.nh_travail)!=EOF)
    {
      if (strcmp(o.n_cin,cherche)==0)
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

////////////////////////////////////////////////////////
///////////////////////////////////////////////////////
///////////////////////////////////////////////////////

/*int main(int argc,char *argv)
{
ouvrier o;
char file_ouvrier[30];
strcpy(file_ouvrier[],"fichier_ouvrire.txt");

char ouvrier_sup[20];
char cherche[20];
char n;
int resultat;
int existe=0;
absence a;
float test=0;
float taux_absenteisme;
int id=1;
int nb_ouvrier=1;
int i=0;

strcpy(file_ouvrier[],"fichier_ouvrire.txt");

printf("donner un commende de 1 a 4:\n");
printf("--------------------1 : ajouter---------------------------\n");
printf("------------------- 2 : afficher--------------------------\n");
printf("--------------------3 : modifier--------------------------\n");
printf("--------------------4 : suprimer--------------------------\n");
printf("--------------------5 : rechercher------------------------\n");
printf("--------------------6 : faire l abcence-------------------\n");
printf("--------------------7 : taux de mailleure ouvrier --------\n");
scanf("%c",&n);
	switch (n)
{

    case '1':
	o=creation_ouvrier();
	ajouter_ouvrier(o,file_ouvrier[]);
      break;
    case '2':
	afficher_ouvrier(o,file_ouvrier[]);
      break;
    case '3':
      printf("donner cin de l ouvrier a modifieer\n");
      scanf("%s",cherche);
	modifier_ouvrier(cherche,file_ouvrier[]);
      break;
    case '4':
      printf("donner cin de l ouvrier a supprimer\n");                 
      scanf("%s",ouvrier_sup);
	supprimer(ouvrier_sup,file_ouvrier[]);
      break;
    case '5':
        printf("donner cin de l ouvrier a rechercher\n");
        scanf("%s",cherche);
	existe=cherche_ouvrier(cherche,file_ouvrier[]);
        if(existe==1)
        printf("il existe\n");
        else
        printf("n'existe pas\n");
     break;
 case '6':
	pointer_ouvrier(o);
      break;
 case '7':
	nombre_ouvrier(a,&nb_ouvrier);
        printf("le nombre douvrier = %d \n",nb_ouvrier);
        for(id=1;id<=nb_ouvrier;id++)
   
        {
	absents(id,a,&taux_absenteisme);
        printf("le taux absenteisme de ouvrier numero %d = %f pourcent\n",id,taux_absenteisme);
          if (taux_absenteisme > test)
          {          
            test=taux_absenteisme;
            i=id;   
     
          }
        }
        printf("le meilleur ouvrier est louvrier numero %d de teaux de presencen = %f\n",i,test);
	    
      break;
    default:
      printf("erreur\n");
      
}
	
   
	
return 0;
}*/
/*void affiche_absence(GtkWidget *treeview)
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
           
store = gtk_list_store_new(COLUMN,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING );
            f=fopen("fiche_absenteisme.txt","r");
 if (f== NULL)
  {
   return ;
  }
           else {
            f=fopen("fiche_absenteisme","a+");
                 while (fscanf(f,"%s  %s  %s  %s  %s   \n",cin,jour,mois,annee,valeur)!=EOF)
                 {
                 gtk_list_store_append(store,&iter);
                                           gtk_list_store_set(store,&iter,CIN,cin,JOUVRIER,jour,MOUVRIER,mois,AOUVRIER,annee,VALEUR,valeur,-1);
                 }
fclose(f);
}
            gtk_tree_view_set_model(GTK_TREE_VIEW(treeview),GTK_TREE_MODEL(store));
            g_object_unref(store);
}*/

