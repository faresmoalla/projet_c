#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include "absenteisme.h"

/*
int nombre_jours(char *absenteisme)
{int nb_jours_totale;
FILE *f;
ouvrier o;

f=fopen("absenteisme.txt","r");
if(f!=NULL){
while(fprintf(f,"%d %d %d %d %d \n",o.id,o.jour,o.mois,o.annee,o.valeur)!= EOF ){
nb_jours_totale++;
}}
return nb_jours_totale;
}

int nombre_ouvrier(char *absenteisme)
{
FILE *f;
ouvrier o;

int nb_ouvrier=1;
f=fopen("absenteisme.txt","r");
if(f!=NULL){
while(fprintf(f,"%d %d %d %d %d \n",o.id,o.jour,o.mois,o.annee,o.valeur)!= EOF )
{
  if(nb_ouvrier==o.id)  {
 nb_ouvrier=nb_ouvrier+1 ;
}
else {
 f= NULL;}
}  }

return nb_ouvrier;
}


float absents(int id)
{int nb_jours_totale,nb_ouvrier;
ouvrier o;
int sommepresence=0;
char absenteisme[999];
int i,j;
float taux_absenteisme;
nb_ouvrier=nombre_ouvrier(absenteisme);
nb_jours_totale=nombre_jours(absenteisme);
FILE *f;
f=fopen("absenteisme.txt","r");
if(f!=NULL)
{
while(fprintf(f,"%d %d %d %d %d \n",o.id,o.jour,o.mois,o.annee,o.valeur)!= EOF ){
for(i=1;i<nb_jours_totale-nb_ouvrier+id;i=i+nb_ouvrier){
    sommepresence=sommepresence+o.valeur;
    j++;
 }}}
taux_absenteisme=(float)(sommepresence/j)*100 ;
fclose(f);
return taux_absenteisme;
}
int main(){
    int id;
    float t;

printf("donner id de louvrier");
scanf("%d",&id);

t=absents(id);
printf("le taux absenteisme de ouvrier numero %d =  %f",id,t);
}*/



/*


void absents(int id ,absence a,float *taux_absenteisme)
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

fclose(f);
}*/

/////////////////////////////////////////
void absents2(absence2 a,float *taux_absenteisme, int c)
{
int j=0 ;
int i=0;

FILE *f;
f=fopen("absenteisme.txt","r");
if(f!=NULL)
{
while(fscanf(f,"%d  %d  %d  %d  %d \n",&a.n_cin,&a.jour,&a.mois,&a.annee,&a.valeur)!= EOF )
{
if(a.mois==c)
{i=i+a.valeur;
j++;}
}
}
fclose(f);
*taux_absenteisme=((float)i/j)*100;
}

//////////////////////////////////////////////////////

/*
int main (int argc,char *argv[]) 
{

absence aa;
float ab;
int c;
for(c=1;c<13;c++)
{
absents(aa,&ab,c);
printf("taux d'absenteisme du mois= %d est %f pourcent \n",c,ab);
}
return 0 ;  }
*/







/*int idd;
absence aa;
float ab;
printf("donner id de louvrier\n");
scanf("%d",&idd);*/




















