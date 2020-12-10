#ifdef HAVE_CONFIG_H
# include <config.h>
#endif



#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"equipement.h"
#include<gtk/gtk.h>

enum
{
   ETYPE,
   EMARQUE,
   EPFISC,
   EANNEE,
   EMATRICULE,
   EVISITE,
   EENTRETIEN,
   COLUMNS
};
////////////////////////////////////////////////////CREATION/////////////////////////////////////////////////////////////////////

/*equipement creation()
{
    equipement e;
    printf("donner le type de l equipement: \n");
    fflush(stdin);
    scanf("%s",e.type);
    printf("donner la marque de l equipement: \n");
    fflush(stdin);
    scanf("%s",e.marque);
    printf("donner sa puissance fiscale: \n");
    scanf("%d",&e.puissance_fiscale);
    printf("donner l annee: \n");
    scanf("%d", &e.annee);
    printf("donner sa matricule: \n");
    fflush(stdin);
    scanf("%s", e.matricule);
    printf("donner la date de la prochaine visite technique: \n");
    scanf("%d",&e.date_visite.j);
    scanf("%d",&e.date_visite.m);
    scanf("%d",&e.date_visite.a);
    printf ("donner la date du prochain entretien: \n");
    scanf("%d",&e.date_entr.j);
    scanf("%d",&e.date_entr.m);
    scanf("%d",&e.date_entr.a);
    return(e);
}*/
////////////////////////////////////////////////////AJOUT///////////////////////////////////////////////////////////////////////

void ajout(equipement e)
{
    FILE* f;
    f=fopen("equipements.txt","a+");
    if(f!=NULL)
    {
        fprintf(f,"%s  %s  %s  %d  %s %s %s \n",e.type,e.marque,e.puissance_fiscale,e.annee,e.matricule,e.date_visite,e.date_entr);
    }
    fclose(f);
}
/////////////////////////////////////////////////////////////////////AFFICHER///////////////////////////////////////////////////////////////////////////////////////////////

void afficher(GtkWidget *liste)
{	
    GtkCellRenderer *renderer;
    GtkTreeViewColumn *column;
    GtkTreeIter iter;
    GtkListStore *store;
    store= NULL;
    FILE* f=NULL;
    f=fopen("equipements.txt","r");
    equipement e;
   store=gtk_tree_view_get_model(liste);
if (store==NULL)
{
    renderer= gtk_cell_renderer_text_new();
    column= gtk_tree_view_column_new_with_attributes("Type", renderer, "text", ETYPE, NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	renderer= gtk_cell_renderer_text_new();
    column= gtk_tree_view_column_new_with_attributes("Marque", renderer, "text", EMARQUE, NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	renderer= gtk_cell_renderer_text_new();
    column= gtk_tree_view_column_new_with_attributes("Puissance fiscale", renderer, "text", EPFISC, NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	renderer= gtk_cell_renderer_text_new();
    column= gtk_tree_view_column_new_with_attributes("Annee", renderer, "text", EANNEE, NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	renderer= gtk_cell_renderer_text_new();
    column= gtk_tree_view_column_new_with_attributes("Matricule", renderer, "text", EMATRICULE, NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	renderer= gtk_cell_renderer_text_new();
    column= gtk_tree_view_column_new_with_attributes("Date visite", renderer, "text", EVISITE, NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
	
	renderer= gtk_cell_renderer_text_new();
    column= gtk_tree_view_column_new_with_attributes("Date entretien", renderer, "text", EENTRETIEN, NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

}
store=gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_INT, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
	

    if(f==NULL)
    {
        return;
       
    }
    else
    {
     	 fflush(stdin);
        while(fscanf(f,"%s  %s  %s  %d  %s %s %s   \n",e.type,e.marque,e.puissance_fiscale,&e.annee,e.matricule,e.date_visite,e.date_entr)!=EOF)
      {
        gtk_list_store_append(store,&iter);
	gtk_list_store_set(store, &iter, ETYPE, e.type, EMARQUE, e.marque, EPFISC, e.puissance_fiscale, EANNEE, e.annee, EMATRICULE, e.matricule, EVISITE, e.date_visite, EENTRETIEN, e.date_entr,-1);
        
      }
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL (store));
g_object_unref(store);
    }
    

}
/////////////////////////////////////////////////////////SUPPRESSION//////////////////////////////////////////////////////////////////////////////

void supprimer(char mat[])
{
    FILE *f=NULL, *f2=NULL;
    f=fopen("equipements.txt","a+");
    f2=fopen("temporaire.txt","a+");

    equipement e;
    if(f== NULL || f2== NULL)
    {
       return;
    }
    else
    {
        while(fscanf(f,"%s  %s  %s  %d  %s %s %s   \n",e.type,e.marque,e.puissance_fiscale,&e.annee,e.matricule,e.date_visite,e.date_entr)!=EOF)
        {
            if(strcmp(e.matricule,mat)!=0)
            {
                fprintf(f2,"%s  %s  %s  %d  %s %s %s   \n",e.type,e.marque,e.puissance_fiscale,e.annee,e.matricule,e.date_visite,e.date_entr);
            }
        }
    }
    fclose(f);
    fclose(f2);
    remove("equipements.txt");
    rename("temporaire.txt","equipements.txt");
}

////////////////////////////////////////////////////////MODIFIER///////////////////////////////////////////////////////////////////////////////////

/*void modifier(char file_name[],char mat[])
{
    FILE *f=NULL, *f2=NULL;
    f=fopen(file_name,"a+");
    f2=fopen("temporaire.txt","a+");
    equipement e;
    if(f==NULL || f2==NULL)
     {
        return;
     }
     else
    {
        while(fscanf(f,"%s  %s  %s  %d  %s %s %s \n",e.type,e.marque,e.puissance_fiscale,&e.annee,e.matricule,e.date_visite,e.date_entr)!=EOF)
        {
            if(strcmp(e.matricule,mat)!=0)
            {
                fprintf(f2,"%s  %s  %s  %d  %s %s %s \n",e.type,e.marque,e.puissance_fiscale,e.annee,e.matricule,e.date_visite,e.date_entr);
            }
            else
            {
                
            }
        }
    }
    fclose(f);
    fclose(f2);
    remove("equipements.txt");
    rename("temporaire.txt","equipements.txt");
}
*/
///////////////////////////////////////////////////////////////////////RECHERCHE/////////////////////////////////////////////////////////////////////////////////////
void recherche(GtkWidget *liste,char mat[])
{
    GtkCellRenderer *renderer;
    GtkTreeViewColumn *column;
    GtkTreeIter iter;
    GtkListStore *store;
    store= NULL;
    FILE* f=NULL;
    f=fopen("equipements.txt","r");
    equipement e;
   store=gtk_tree_view_get_model(liste);
if (store==NULL)
{
    renderer= gtk_cell_renderer_text_new();
    column= gtk_tree_view_column_new_with_attributes("Type", renderer, "text", ETYPE, NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	renderer= gtk_cell_renderer_text_new();
    column= gtk_tree_view_column_new_with_attributes("Marque", renderer, "text", EMARQUE, NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	renderer= gtk_cell_renderer_text_new();
    column= gtk_tree_view_column_new_with_attributes("Puissance fiscale", renderer, "text", EPFISC, NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	renderer= gtk_cell_renderer_text_new();
    column= gtk_tree_view_column_new_with_attributes("Annee", renderer, "text", EANNEE, NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	renderer= gtk_cell_renderer_text_new();
    column= gtk_tree_view_column_new_with_attributes("Matricule", renderer, "text", EMATRICULE, NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	renderer= gtk_cell_renderer_text_new();
    column= gtk_tree_view_column_new_with_attributes("Date visite", renderer, "text", EVISITE, NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
	
	renderer= gtk_cell_renderer_text_new();
    column= gtk_tree_view_column_new_with_attributes("Date entretien", renderer, "text", EENTRETIEN, NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

}
store=gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_INT, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
	

    if(f==NULL)
    {
        return;
       
    }
    else
    {
     	 fflush(stdin);
        while(fscanf(f,"%s  %s  %s  %d  %s %s %s   \n",e.type,e.marque,e.puissance_fiscale,&e.annee,e.matricule,e.date_visite,e.date_entr)!=EOF)
      { 
        if(strcmp(mat,e.matricule)==0)
      {
        gtk_list_store_append(store,&iter);
	gtk_list_store_set(store, &iter, ETYPE, e.type, EMARQUE, e.marque, EPFISC, e.puissance_fiscale, EANNEE, e.annee, EMATRICULE, e.matricule, EVISITE, e.date_visite, EENTRETIEN, e.date_entr,-1);
}
        
      }
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL (store));
g_object_unref(store);
}
}

///////////////////////////////////////////////////////////////////////Affichage selon type/////////////////////////////////////////////////////////////////////////////////////////////////////
void affichertyp(GtkWidget *liste, char type[])
{	
    GtkCellRenderer *renderer;
    GtkTreeViewColumn *column;
    GtkTreeIter iter;
    GtkListStore *store;
    store= NULL;
    FILE* f=NULL;
    f=fopen("equipements.txt","r");
    equipement e;
   store=gtk_tree_view_get_model(liste);
if (store==NULL)
{
    renderer= gtk_cell_renderer_text_new();
    column= gtk_tree_view_column_new_with_attributes("Type", renderer, "text", ETYPE, NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	renderer= gtk_cell_renderer_text_new();
    column= gtk_tree_view_column_new_with_attributes("Marque", renderer, "text", EMARQUE, NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	renderer= gtk_cell_renderer_text_new();
    column= gtk_tree_view_column_new_with_attributes("Puissance fiscale", renderer, "text", EPFISC, NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	renderer= gtk_cell_renderer_text_new();
    column= gtk_tree_view_column_new_with_attributes("Annee", renderer, "text", EANNEE, NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	renderer= gtk_cell_renderer_text_new();
    column= gtk_tree_view_column_new_with_attributes("Matricule", renderer, "text", EMATRICULE, NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	renderer= gtk_cell_renderer_text_new();
    column= gtk_tree_view_column_new_with_attributes("Date visite", renderer, "text", EVISITE, NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
	
	renderer= gtk_cell_renderer_text_new();
    column= gtk_tree_view_column_new_with_attributes("Date entretien", renderer, "text", EENTRETIEN, NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

}
store=gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_INT, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
	

    if(f==NULL)
    {
        return;
       
    }
    else
    {
     	 fflush(stdin);
        while(fscanf(f,"%s  %s  %s  %d  %s %s %s   \n",e.type,e.marque,e.puissance_fiscale,&e.annee,e.matricule,e.date_visite,e.date_entr)!=EOF)
      {
        if(strcmp(e.type,type)==0)
	{
	gtk_list_store_append(store,&iter);
	gtk_list_store_set(store, &iter, ETYPE, e.type, EMARQUE, e.marque, EPFISC, e.puissance_fiscale, EANNEE, e.annee, EMATRICULE, e.matricule, EVISITE, e.date_visite, EENTRETIEN, e.date_entr,-1);
	}
        
      }
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL (store));
g_object_unref(store);
    }
    

}


