#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "equipement.h"

///////////////////////////////////////////////////////BOUTON ENREGISTRER FEL AJOUT////////////////////////////////////////////////////////////////////////////////////////////////////////////

void
on_MBbuttonenregistrer_clicked         (GtkWidget       *objet,
                                        gpointer         user_data)
{
	 GtkWidget *marque1,*marque2,*marque3,*marque4,*marque5, *mat, *puissfis, *annee;
GtkWidget *fenetre_ajout;
GtkSpinButton *datev_j,*datev_m,*datev_a, *datee_j,*datee_m,*datee_a;
GtkComboBox *type;
equipement e;


fenetre_ajout=lookup_widget(objet,"MBajout");

type=lookup_widget(objet, "MBcombotracteur");

puissfis=lookup_widget(objet, "MBentrypuissancefis");
annee=lookup_widget(objet, "MBspinannee");
mat=lookup_widget(objet, "MBentrymat1");
datev_j=lookup_widget(objet, "MBspinjour");
datev_m=lookup_widget(objet, "MBspinmois");
datev_a=lookup_widget(objet, "MBspinanneee");
datee_j=lookup_widget(objet, "MBspinjour2");
datee_m=lookup_widget(objet, "MBspinmois2");
datee_a=lookup_widget(objet, "MBspinanneee2");

//type input
gint item_selected = gtk_combo_box_get_active(type);
switch(item_selected)
{
    case 0:
   strcpy(e.type,"tracteur");
   break;
  case 1:
   strcpy(e.type,"charrure_a_disques");
   break;
case 2:
   strcpy(e.type,"chenille_agricole");
   break;
case 3:
   strcpy(e.type,"moissonneuse");
   break;
}

// marque input
marque1=lookup_widget(objet, "MBradiojhon");
marque2=lookup_widget(objet, "MBradiorenault");
marque3=lookup_widget(objet, "MBradiosomeca");
marque4=lookup_widget(objet, "MBradiofordoson");
marque5=lookup_widget(objet, "MBradiofiat");

if (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(marque1))==TRUE) strcpy(e.marque,"JHON_DEERE");
    else if (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(marque2))==TRUE) strcpy(e.marque,"RENAULT");
    else if (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(marque3))==TRUE) strcpy(e.marque,"SOMECA");
    else if (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(marque4))==TRUE) strcpy(e.marque,"FORDOSON");
    else if (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(marque5))==TRUE) strcpy(e.marque,"FIAT");
//annee input
    
e.annee= gtk_spin_button_get_value_as_int(annee);
//mat
strcpy(e.matricule,gtk_entry_get_text(GTK_ENTRY(mat)));

//datev input
int a,b,c;
char ch[50];
a= gtk_spin_button_get_value_as_int(datev_j);
b= gtk_spin_button_get_value_as_int(datev_m);
c= gtk_spin_button_get_value_as_int(datev_a);
sprintf(ch,"%d/%d/%d",a,b,c);
strcpy(e.date_visite,ch);
//datee input
a= gtk_spin_button_get_value_as_int(datee_j);
b= gtk_spin_button_get_value_as_int(datee_m);
c= gtk_spin_button_get_value_as_int(datee_a);
sprintf(ch,"%d/%d/%d",a,b,c);
strcpy(e.date_entr,ch);
//puissance input
strcpy(e.puissance_fiscale,gtk_entry_get_text(GTK_ENTRY(puissfis)));

ajout(e);

}

///////////////////////////////////////////////////////////////////////////////////////AFFICHER EL TREEVIEW///////////////////////////////////////////////////////////////////////////

void
on_MBbuttonaffich_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{
	
	

GtkWidget *treeview1;
GtkWidget *crud,*type1,*type2, *type3,*type4;
char ch2[30];


type1=lookup_widget(objet, "MBchecktrac");
type2=lookup_widget(objet, "MBcheckchar");
type3=lookup_widget(objet, "MBcheckcheni");
type4=lookup_widget(objet, "MBcheckmois");

crud= lookup_widget(objet,"MBcrud");
treeview1=lookup_widget(crud,"treeview1");

if(gtk_toggle_button_get_active (GTK_CHECK_BUTTON(type1))==TRUE)  //if tracteur checked
{
	strcpy(ch2,"tracteur");
	affichertyp(treeview1,ch2);
}
else if(gtk_toggle_button_get_active (GTK_CHECK_BUTTON(type2))==TRUE) //if charrure a disques checked
{
	strcpy(ch2,"charrure_a_disques");
	affichertyp(treeview1,ch2);
}
else if(gtk_toggle_button_get_active (GTK_CHECK_BUTTON(type3))==TRUE) //if chenille checked
{
	strcpy(ch2,"chenille_agricole");
	affichertyp(treeview1,ch2);
}
 else if(gtk_toggle_button_get_active (GTK_CHECK_BUTTON(type4))==TRUE) //if moissonneuse checked
{
	strcpy(ch2,"moissonneuse");
	affichertyp(treeview1,ch2);
}
else
afficher(treeview1);


}

//////////////////////////////////////////////////////////////t7ell fenetre ajout/////////////////////////////////////////////////////////////////////////////

void
on_MBbuttonajout_clicked               (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *MBajout;
       MBajout=create_MBajout();
gtk_widget_show(MBajout);
}


void
on_MBbuttonmodif_clicked               (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *MBajout;
 MBajout=create_MBajout();
gtk_widget_show(MBajout);

}
/////////////////////////////////////////////////////////////////////supprimer//////////////////////////////////////////////////////////////////////////////////

void
on_MBbuttonsupprim_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *fenetre_afficher;
      char mat[50];
      GtkWidget *treeview1;
   GtkWidget *input1;
input1=lookup_widget(objet,"entry1");
strcpy(mat,gtk_entry_get_text(GTK_ENTRY(input1)));
supprimer(mat);
fenetre_afficher=lookup_widget(objet,"MBcrud");

treeview1=lookup_widget(fenetre_afficher,"treeview1");
afficher(treeview1);
}
////////////////////////////////////////////////////////////////////////////modifier/////////////////////////////////////////////////////////////////////////////////////

void
on_button1_clicked                     (GtkWidget      *objet,
                                        gpointer         user_data)
{
     GtkWidget *MBcrud;
    GtkWidget *mat;
    mat=lookup_widget(objet,"entry1");
char matr[50];
strcpy(matr,gtk_entry_get_text(GTK_ENTRY(mat)));
GtkWidget *treeview1;
MBcrud=lookup_widget(objet,"MBcrud");
treeview1=lookup_widget(MBcrud,"treeview1");
recherche(treeview1,matr);

}

//////////////////////////////////////////////////////////////////////////////////modifier t3ammer wa7adha/////////////////////////////////////////////////////////////////////
void
on_buttonmat_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{ FILE* f=NULL;
equipement e;
int j,m,a;
	GtkWidget *matricule,*type, *marque1,*marque2,*marque3,*marque4,*marque5,*p,*annee, *datevj, *datevm, *dateva, *dateej, *dateem, *dateea ;
char ch3[40];
f=fopen("equipements.txt","a+");
matricule=lookup_widget(objet,"MBentrymat1");
annee=lookup_widget(objet, "MBspinannee");
marque1=lookup_widget(objet, "MBradiojhon");
marque2=lookup_widget(objet, "MBradiorenault");
marque3=lookup_widget(objet, "MBradiosomeca");
marque4=lookup_widget(objet, "MBradiofordoson");
marque5=lookup_widget(objet, "MBradiofiat");
type=lookup_widget(objet, "MBcombotracteur");
datevj=lookup_widget(objet, "MBspinjour");
datevm=lookup_widget(objet, "MBspinmois");
dateva=lookup_widget(objet, "MBspinanneee");
dateej=lookup_widget(objet, "MBspinjour2");
dateem=lookup_widget(objet, "MBspinmois2");
dateea=lookup_widget(objet, "MBspinanneee2");
p=lookup_widget(objet, "MBentrypuissancefis");
strcpy(ch3,gtk_entry_get_text(GTK_ENTRY(matricule)));
if(f!=NULL)
{
	while(fscanf(f,"%s  %s  %s  %d  %s %s %s   \n",e.type,e.marque,e.puissance_fiscale,&e.annee,e.matricule,e.date_visite,e.date_entr)!=EOF)
	{
		if(strcmp(ch3,e.matricule)==0)
		{	
			
			gtk_entry_set_text(p,e.puissance_fiscale);//ENTRY
			//SPIN BUTTON
			gtk_spin_button_set_value(annee,e.annee);
			sscanf(e.date_visite, "%d/%d/%d", &j, &m, &a);
			gtk_spin_button_set_value(datevj,j);
			gtk_spin_button_set_value(datevm,m);
			gtk_spin_button_set_value(dateva,a);
			sscanf(e.date_entr, "%d/%d/%d", &j, &m, &a);
			gtk_spin_button_set_value(dateej,j);
			gtk_spin_button_set_value(dateem,m);
			gtk_spin_button_set_value(dateea,a);
//RADIO BUTTON
	if(strcmp(e.marque,"JHON_DEERE")==0)
		gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON(marque1),1);
	if(strcmp(e.marque,"RENAULT")==0)
		gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON(marque2),1);
	if(strcmp(e.marque,"SOMECA")==0)
		gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON(marque3),1);
	if(strcmp(e.marque,"FORDOSON")==0)
		gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON(marque4),1);
	if(strcmp(e.marque,"FIAT")==0)
		gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON(marque5),1);
/* //COMBO BOX
if(strcmp(e.type,"tracteur")==0)						
   gtk_combo_box_set_active (GTK_COMBO_BOX(type), 0);
if(strcmp(e.type,"charrure_a_disques")==0)						
   gtk_combo_box_set_active (GTK_COMBO_BOX(type), 1);
if(strcmp(e.type,"chenille_agricole")==0)						
   gtk_combo_box_set_active (GTK_COMBO_BOX(type), 2);
if(strcmp(e.type,"moissonneuse")==0)						
   gtk_combo_box_set_active (GTK_COMBO_BOX(type), 3);*/
			
		}
	}
}

}

