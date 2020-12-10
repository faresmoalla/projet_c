#include<stdio.h>
#include<string.h>
#include"fichier2.h"
equipement creation()
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
}
void ajout(char file_name[],equipement e)
{
    FILE* f;
    f=fopen(file_name,"a+");
    if(f!=NULL)
    {
        fprintf(f,"%s  %s  %d  %d  %s %d %d %d %d %d %d \n",e.type,e.marque,e.puissance_fiscale,e.annee,e.matricule,e.date_visite.j,e.date_visite.m,e.date_visite.a,e.date_entr.j,e.date_entr.m,e.date_entr.a);
    }
    fclose(f);
}
void supprimer(char file_name[],char mat[])
{
    FILE *f=NULL, *f2=NULL;
    f=fopen(file_name,"a+");
    f2=fopen("temporaire.txt","a+");

    equipement e;
    if(f!= NULL)
    {
        while(fscanf(f,"%s  %s  %d  %d  %s %d %d %d %d %d %d  \n",e.type,e.marque,&e.puissance_fiscale,&e.annee,e.matricule,&e.date_visite.j,&e.date_visite.m,&e.date_visite.a,&e.date_entr.j,&e.date_entr.m,&e.date_entr.a)!=EOF)
        {
            if(strcmp(e.matricule,mat)!=0)
            {
                fprintf(f2,"%s  %s  %d  %d  %s %d %d %d %d %d %d  \n",e.type,e.marque,e.puissance_fiscale,e.annee,e.matricule,e.date_visite.j,e.date_visite.m,e.date_visite.a,e.date_entr.j,e.date_entr.m,e.date_entr.a);
            }
        }
    }
    fclose(f);
    fclose(f2);
    remove("equipements.txt");
    rename("temporaire.txt","equipements.txt");
}
void modifier(char file_name[],char mat[])
{
    FILE *f=NULL, *f2=NULL;
    f=fopen(file_name,"a+");
    f2=fopen("temporaire.txt","a+");
    equipement e;
    if(f!=NULL)
    {
        while(fscanf(f,"%s  %s  %d  %d  %s %d %d %d %d %d %d \n",e.type,e.marque,&e.puissance_fiscale,&e.annee,e.matricule,&e.date_visite.j,&e.date_visite.m,&e.date_visite.a,&e.date_entr.j,&e.date_entr.m,&e.date_entr.a)!=EOF)
        {
            if(strcmp(e.matricule,mat)!=0)
            {
                fprintf(f2,"%s  %s  %d  %d  %s %d %d %d %d %d %d \n",e.type,e.marque,e.puissance_fiscale,e.annee,e.matricule,e.date_visite.j,e.date_visite.m,e.date_visite.a,e.date_entr.j,e.date_entr.m,e.date_entr.a);
            }
            else
            {
                printf("donner le nouveau type: \n");
                fflush(stdin);
                scanf("%s",e.type);
                printf("donner la nouvelle marque de l equipement: \n");
                fflush(stdin);
                scanf("%s",e.marque);
                printf("donner sa nouvelle puissance fiscale: \n");
                scanf("%d",&e.puissance_fiscale);
                printf("donner la nouvelle annee: \n");
                scanf("%d", &e.annee);
                printf("donner sa nouvelle matricule: \n");
                fflush(stdin);
                scanf("%s", e.matricule);
                printf("donner la nouvelle date de la prochaine visite technique: \n");
                scanf("%d",&e.date_visite.j);
                scanf("%d",&e.date_visite.m);
                scanf("%d",&e.date_visite.a);
                printf ("donner la nouvelle date du prochain entretien: \n");
                scanf("%d",&e.date_entr.j);
                scanf("%d",&e.date_entr.m);
                scanf("%d",&e.date_entr.a);
                fprintf(f2,"%s  %s  %d  %d  %s %d %d %d %d %d %d \n",e.type,e.marque,e.puissance_fiscale,e.annee,e.matricule,e.date_visite.j,e.date_visite.m,e.date_visite.a,e.date_entr.j,e.date_entr.m,e.date_entr.a);
            }
        }
    }
    fclose(f);
    fclose(f2);
    remove("equipements.txt");
    rename("temporaire.txt","equipements.txt");
}
void afficher(char file_name[])
{
    FILE* f=NULL;
    f=fopen(file_name,"a+");
    int i=1;
    equipement e;
    if(f!=NULL)
    {
        fflush(stdin);
        while(fscanf(f,"%s  %s  %d  %d  %s %d %d %d %d %d %d  \n",e.type,e.marque,&e.puissance_fiscale,&e.annee,e.matricule,&e.date_visite.j,&e.date_visite.m,&e.date_visite.a,&e.date_entr.j,&e.date_entr.m,&e.date_entr.a)!=EOF)
        {
            printf("%d. Type: %s, Marque: %s, Puissance Fiscale: %d, Annee: %d, Matricule: %s Date de la prochaine visite technique: %d-%d-%d , Date du prochain entretien: %d-%d-%d \n",i,e.type,e.marque,e.puissance_fiscale,e.annee,e.matricule,e.date_visite.j,e.date_visite.m,e.date_visite.a,e.date_entr.j,e.date_entr.m,e.date_entr.a);
            i++;
        }
    }
    fclose(f);

}
equipement* recherche(char file_name[],char mat[])
{
    FILE* f=NULL;
    f=fopen(file_name,"a+");
    equipement* e1=malloc(sizeof(equipement));
    if(f!=NULL)
    {
        while(fscanf(f,"%s  %s  %d  %d  %s %d %d %d %d %d %d  \n",e.type,e.marque,&e.puissance_fiscale,&e.annee,e.matricule,&e.date_visite.j,&e.date_visite.m,&e.date_visite.a,&e.date_entr.j,&e.date_entr.m,&e.date_entr.a)!=EOF)
        {
            if(strcmp(e.matricule,mat)==0)
            {
                return e1;
            }
        }
	else return NULL;
    }
    fclose(f);
}
int main()
{
    char file_name[50];
    equipement e;
    int x;
    char mat[20];
    strcpy(file_name,"equipements.txt");
    while(1)
    {
        printf("------------------EQUIPEMENTS AGRICOLES------------------\n");
        printf("1. Ajouter un nouvel equipement.\n");
        printf("2. Supprimer un equipement.\n");
        printf("3. Modifier un equipement.\n");
        printf("4. Afficher les equipements disponibles.\n");
        printf("6. Recherche d un equipement.\n");
        printf("7. Quitter.\n");
        printf("-------------------------------------------------------\n");
        printf("choix: \n");
        scanf("%d",&x);
        switch(x)
        {
        case 1:
        {

            e=creation();
            ajout(file_name,e);
            break;
        }
        case 2:
        {

            printf("donner la matricule de l equipement a supprimer: \n");
            scanf("%s",mat);
            supprimer(file_name,mat);
            printf("EQUIPEMENT SUPPRIME AVEC SUCCEES. \n");
            break;
        }
        case 3:
        {

            printf("donner la matricule de l equipement a modifier: \n");
            scanf("%s",mat);
            modifier(file_name,mat);
            printf("EQUIPEMENT MODIFIE AVEC SUCCEES. \n");
            break;
        }
        case 4:
        {

            printf("VOICI LA LISTE DES EQUIPEMENTS DISPONIBLES: \n");
            afficher(file_name);
            break;
        }
        case 6:
        {

            printf("donner la matricule de l equipement a afficher: \n");
            scanf("%s",mat);
            printf("VOICI L EQUIPEMENT CHERCHE: \n");
            recherche(file_name,mat);
            break;
        }

        case 7:
            return 0;
        }
    }

    return 0;
}

