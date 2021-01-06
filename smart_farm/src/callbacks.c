#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include <string.h>
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "client.h"
#include "fonction.h"
#include "commande.h"
#include "equipement.h"
#include "ouvrier.h"
#include "absence.h"
#include "absenteisme.h"
#include "fonctionMH.h"
#include "global.h"
#include "plantation.h"
#include "capteur.h"
#include "mb_seche.h"

//selected_capteur;
char file_name[50]="inscription.txt";
char file_name2[50]="commande.txt";
char file[50]="filex.txt";
void

/////////////////////////////////////////////////////////////////////1ére interface/////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


on_button_ouvriers_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget  *windowAuth;
windowAuth= create_RKcrud();
gtk_widget_show(windowAuth);
}


void
on_button_clients_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget  *windowAuth;
windowAuth= create_Fmcrud();
gtk_widget_show(windowAuth);



  GtkWidget *treeview1;
  treeview1=lookup_widget(windowAuth,"FMtreeview");
 afficher_client(treeview1);

}


void
on_buttons_equipements_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget  *windowAuth;
windowAuth= create_MBcrud();
GtkWidget *treeview1;
treeview1=lookup_widget(windowAuth,"treeview1");
afficherMB(treeview1);

gtk_widget_show(windowAuth);

}


void
on_button_capteurs_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{GtkWidget  *windowAuth;
windowAuth= create_BMwindowcapt();
gtk_widget_show(windowAuth);

}


void
on_buttons_troupeux_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
   GtkWidget  *windowAuth;
windowAuth= create_MHwindowrec();
gtk_widget_show(windowAuth);
}


void
on_button_plantation_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget
*Admin=lookup_widget(button,"Admin");
gtk_widget_destroy(Admin);
remove("/home/aminous/Desktop/smart_farm/photo.bin");
remove("/home/aminous/Desktop/smart_farm/src/photo.bin");
FILE *f=NULL;
GdkColor col;
char
data_base[]="plantation.bin",
head_color[]="head_color.bin",
body_color[]="body_color.bin",
button_color[]="button_color.bin",
calendar_color[]="calendar_color.bin",
TreeView_color[]="treeview_color.bin";
GtkWidget
*MABFcrud=create_MABFcrud(),
*GES=lookup_widget(MABFcrud,"MABFLabelGestion"),
*DAT=lookup_widget(MABFcrud,"MABFLabelDate"),
*ID=lookup_widget(MABFcrud,"MABFLabelID"),
*CAT=lookup_widget(MABFcrud,"MABFLabelCategorie"),
*IRG=lookup_widget(MABFcrud,"MABFLabelIrrigation"),
*ENG=lookup_widget(MABFcrud,"MABFLabelEngrais"),
*TRT=lookup_widget(MABFcrud,"MABFLabelTraitement"),
*REC=lookup_widget(MABFcrud,"MABFLabelRecolte"),
*ENGRAIS=lookup_widget(MABFcrud,"MABFComboBoxEngrais"),
*RECOLTE=lookup_widget(MABFcrud,"MABFComboBoxRecolte"),
*MABFButtonAjouter=lookup_widget(MABFcrud,"MABFButtonAjouter"),
*MABFButtonModifier=lookup_widget(MABFcrud,"MABFButtonModifier"),
*MABFButtonSupprimer=lookup_widget(MABFcrud,"MABFButtonSupprimer"),
*MABFButtonChercher=lookup_widget(MABFcrud,"MABFButtonChercher"),
*MABFCalendar=lookup_widget(MABFcrud,"MABFCalendar"),
*MABFTreeView=lookup_widget(MABFcrud,"MABFTreeView"),
*MABFEventBoxInsertion=lookup_widget(MABFcrud,"MABFEventBoxInsertion"),
*MABFEventBoxCouleur=lookup_widget(MABFcrud,"MABFEventBoxCouleur"),
*MABFEventBoxTri=lookup_widget(MABFcrud,"MABFEventBoxTri");
gtk_combo_box_set_active(GTK_COMBO_BOX(ENGRAIS),0);
gtk_combo_box_set_active(GTK_COMBO_BOX(RECOLTE),0);
afficher_plantation(data_base,MABFTreeView);
f=fopen(head_color,"rb");
if(f!=NULL){
fread(&col,sizeof(GdkColor),1,f);
gtk_widget_modify_fg(GES,GTK_STATE_NORMAL,&col);
fclose(f);}
f=fopen(body_color,"rb");
if(f!=NULL){
fread(&col,sizeof(GdkColor),1,f);
gtk_widget_modify_fg(DAT,GTK_STATE_NORMAL,&col);
gtk_widget_modify_fg(ID,GTK_STATE_NORMAL,&col);
gtk_widget_modify_fg(CAT,GTK_STATE_NORMAL,&col);
gtk_widget_modify_fg(IRG,GTK_STATE_NORMAL,&col);
gtk_widget_modify_fg(ENG,GTK_STATE_NORMAL,&col);
gtk_widget_modify_fg(TRT,GTK_STATE_NORMAL,&col);
gtk_widget_modify_fg(REC,GTK_STATE_NORMAL,&col);
fclose(f);}
f=fopen(button_color,"rb");
if(f!=NULL){
fread(&col,sizeof(GdkColor),1,f);
gtk_widget_modify_bg(MABFButtonAjouter,GTK_STATE_NORMAL,&col);
gtk_widget_modify_bg(MABFButtonModifier,GTK_STATE_NORMAL,&col);
gtk_widget_modify_bg(MABFButtonSupprimer,GTK_STATE_NORMAL,&col);
gtk_widget_modify_bg(MABFButtonChercher,GTK_STATE_NORMAL,&col);
fclose(f);}
f=fopen(calendar_color,"rb");
if(f!=NULL){
fread(&col,sizeof(GdkColor),1,f);
gtk_widget_modify_base(MABFCalendar,GTK_STATE_NORMAL,&col);
fclose(f);}
f=fopen(TreeView_color,"rb");
if(f!=NULL){
fread(&col,sizeof(GdkColor),1,f);
gtk_widget_modify_base(MABFTreeView,GTK_STATE_NORMAL,&col);
fclose(f);}
gtk_window_set_default_size(GTK_WINDOW(MABFcrud),1390,710);
gtk_widget_show(MABFcrud);}

void
on_button_commandes_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget  *windowAuth;
windowAuth= create_gestioncommande();
gtk_widget_show(windowAuth);


GtkWidget *treeviewcommande;
treeviewcommande=lookup_widget(windowAuth,"treeviewcommande");

afficher_commande(treeviewcommande);

}

///////////////////////////////////////////////////////////////Mahdi/////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void
on_BMtreeview3_row_activated           (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}

void
on_BMbuttonAfficher_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window1;
GtkWidget *Humidite;
GtkWidget *Temperature;
GtkWidget *BMwindowcapt;
GtkWidget *BMtreeviewAffichage;
BMwindowcapt=lookup_widget(GTK_WIDGET(button),"BMwindowcapt");
BMtreeviewAffichage=lookup_widget(BMwindowcapt,"BMtreeviewAffichage");
Humidite=lookup_widget(GTK_WIDGET(button),"BMcheckbuttonaffichage2");
Temperature=lookup_widget(GTK_WIDGET(button),"BMcheckbuttonaffichage1");
if( gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(Humidite)))
{
afficherhum(BMtreeviewAffichage);
}
if( gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON (Temperature)))
{
affichertmp(BMtreeviewAffichage);
}
if( gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON (Temperature)) && gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON (Humidite)) )
{
afficher(BMtreeviewAffichage);
}}

void
on_BMbuttonSupprimer_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *fenetre_afficher;
char id[30];
GtkWidget *treeview1;
GtkWidget *input1;
input1=lookup_widget(GTK_WIDGET(button),"BMentry10");
strcpy(id,gtk_entry_get_text(GTK_ENTRY(input1)));
supprimer3("file.txt",id);
fenetre_afficher=lookup_widget(GTK_WIDGET(button),"BMwindowcapt");
treeview1=lookup_widget(fenetre_afficher,"BMtreeviewAffichage");
afficher(treeview1);
}

void
on_BMbuttonAModifier_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *BMwindowmodifier;
/*
date date_ajout;
FILE *f;
GtkWidget *id,*mq,*tp,*val,*jour,*mois,*annee,*windowAuth;
capteur c;
id = lookup_widget (GTK_WIDGET(button),"entry2");
mq = lookup_widget (GTK_WIDGET(button),"entry3");
val = lookup_widget (GTK_WIDGET(button),"entry4");
jour = lookup_widget (GTK_WIDGET(button),"spinbutton4");
mois = lookup_widget (GTK_WIDGET(button),"spinbutton5");
annee = lookup_widget (GTK_WIDGET(button),"spinbutton6");
strcpy(c.captID,gtk_entry_get_text(GTK_ENTRY(id)));
strcpy(c.captMarque,gtk_entry_get_text(GTK_ENTRY(mq)));
strcpy(c.valeur,gtk_entry_get_text(GTK_ENTRY(val)));
c.date_ajout.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
c.date_ajout.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
c.date_ajout.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));
*/
BMwindowmodifier = create_BMwindowmodifier ();
  gtk_widget_show (BMwindowmodifier);
}


void
on_BMbuttonRechercher_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *BMwindowcapt;
GtkWidget *id;
id = lookup_widget (GTK_WIDGET(button),"BMentry10");
char IDs[20];
strcpy(IDs,gtk_entry_get_text(GTK_ENTRY(id)));
GtkWidget *BMtreeviewAffichage;
BMwindowcapt=lookup_widget (GTK_WIDGET(button),"BMwindowcapt");
BMtreeviewAffichage=lookup_widget (BMwindowcapt,"BMtreeviewAffichage");
rechercher_capteur(IDs,BMtreeviewAffichage);
}

void
on_BMbuttonAjouter_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
Mdate Mdate_ajout;
FILE *f;
GtkWidget *id,*mq,*tp,*val,*jour,*mois,*annee,*windowAuth,*Humidite,*Temperature;
capteur c;
id = lookup_widget (GTK_WIDGET(button),"BMentry8");
mq = lookup_widget (GTK_WIDGET(button),"BMentry9");
val = lookup_widget (GTK_WIDGET(button),"entry1");
jour = lookup_widget (GTK_WIDGET(button),"spinbutton1");
mois = lookup_widget (GTK_WIDGET(button),"spinbutton2");
annee = lookup_widget (GTK_WIDGET(button),"spinbutton3");
Humidite=lookup_widget(GTK_WIDGET(button),"radiobutton1");
Temperature=lookup_widget(GTK_WIDGET(button),"radiobutton2");
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(Humidite)))
{
strcpy(c.captType,"Humidite");
}

if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(Temperature)))
{
strcpy(c.captType,"Temperature");
}
strcpy(c.captID,gtk_entry_get_text(GTK_ENTRY(id)));
strcpy(c.captMarque,gtk_entry_get_text(GTK_ENTRY(mq)));
strcpy(c.valeur,gtk_entry_get_text(GTK_ENTRY(val)));
c.Mdate_ajout.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
c.Mdate_ajout.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
c.Mdate_ajout.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));
ajouter(f,c);
}


void
on_BMbuttonAfficherAlarm_clicked       (GtkButton       *objet,
                                        gpointer         user_data)
{/*
GtkWidget *window1;
GtkWidget *BMwindowcapt;//page affichage
//page ajout
GtkWidget *BMtreeview3;
capteuralarmant a;

BMwindowcapt=lookup_widget(objet,"BMwindowcapt");

BMtreeview3=lookup_widget(BMwindowcapt,"BMtreeview3");

//capteur_alarmant(a);

affiche_alarmant(BMtreeview3);*/
}


void
on_BMbuttonConfirmerModif_clicked      (GtkButton      *button,
                                        gpointer         user_data)
{
Mdate Mdate_ajout;

GtkWidget *id,*mq,*tp,*val,*jour,*mois,*annee,*windowAuth,*Humidite,*Temperature;
capteur c;
Humidite=lookup_widget(GTK_WIDGET(button),"BMradiobutton4");
Temperature=lookup_widget(GTK_WIDGET(button),"BMradiobutton5");
id = lookup_widget (GTK_WIDGET(button),"entry2");
mq = lookup_widget (GTK_WIDGET(button),"entry3");
val = lookup_widget (GTK_WIDGET(button),"entry4");
jour = lookup_widget (GTK_WIDGET(button),"spinbutton4");
mois = lookup_widget (GTK_WIDGET(button),"spinbutton5");
annee = lookup_widget (GTK_WIDGET(button),"spinbutton6");
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(Humidite)))
{
strcpy(c.captType,"Humidite");
}

if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(Temperature)))
{
strcpy(c.captType,"Temperature");
}
strcpy(c.captID,gtk_entry_get_text(GTK_ENTRY(id)));
strcpy(c.captMarque,gtk_entry_get_text(GTK_ENTRY(mq)));
strcpy(c.valeur,gtk_entry_get_text(GTK_ENTRY(val)));
c.Mdate_ajout.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
c.Mdate_ajout.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
c.Mdate_ajout.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));
supprimer_capt(c);
ajouter("filex.txt",c);
}


void
on_BMtreeviewAffichage_row_activated   (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
gchar* id;
gchar* type;
gchar* marque;
gchar* valeur;
gint* jour;
gint* mois;
gint* annee;
capteur c;
Mdate Mdate_ajout;

GtkTreeModel *model = gtk_tree_view_get_model(treeview);

if(gtk_tree_model_get_iter(model,&iter,path)){
gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&id,1,&marque,2,&valeur,3,&jour,4,&mois,5,&annee,-1);
strcpy(c.captID,id);
strcpy(c.captMarque,marque);
strcpy(c.captType,type);
strcpy(c.valeur,valeur);
c.Mdate_ajout.jour=jour;
c.Mdate_ajout.mois=mois;
c.Mdate_ajout.annee=annee;
supprimer1(c);
afficher(treeview);
}
}


void
on_BMrecherchemodif_clicked            (GtkButton      *button,
                                        gpointer         user_data)
{
GtkWidget *id, *mq,*typ1,*typ2,*valeur, *jour , *mois, *annee,*Humidite,*Temperature;
char ID[20];
char MARQUE[20];
char VALEUR [20];
capteur c;
Mdate Mdate_ajout;
char nom_fichier[100]="file.txt";
id = lookup_widget (GTK_WIDGET(button),"entry2");
strcpy(ID,gtk_entry_get_text(GTK_ENTRY(id)));
c=rechercher1(ID,nom_fichier);
if(c.Mdate_ajout.jour!=-1)
{
mq = lookup_widget (GTK_WIDGET(button),"entry3");
valeur = lookup_widget (GTK_WIDGET(button),"entry4");
jour=lookup_widget(GTK_WIDGET(button),"spinbutton4");
mois=lookup_widget(GTK_WIDGET(button),"spinbutton5");
annee=lookup_widget(GTK_WIDGET(button),"spinbutton6");
typ2=lookup_widget(GTK_WIDGET(button),"BMradiobutton4");
typ1=lookup_widget(GTK_WIDGET(button),"BMradiobutton5");
gtk_entry_set_text(mq,c.captMarque);
gtk_entry_set_text(valeur,c.valeur);

gtk_spin_button_set_value(jour,c.Mdate_ajout.jour);
gtk_spin_button_set_value(mois,c.Mdate_ajout.mois);
gtk_spin_button_set_value(annee,c.Mdate_ajout.annee);
if(strcmp(c.captType,"Temperature")==0)
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(typ1),1);
if(strcmp(c.captType,"Humidite")==0)
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(typ2),1);
}}

void
on_BMbuttonretour_clicked              (GtkButton         *button,
                                        gpointer         user_data)
{
GtkWidget *BMwindowcapt,*BMwindow;
BMwindow=lookup_widget(GTK_WIDGET(button),"BMwindowmodifier");
gtk_widget_destroy(BMwindow);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////           Fares     ////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void
on_FMconnectbutton_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{GtkWidget *username , *password, *windowEspaceAdmin, *window,*windowEspaceAdmin2,*adress;
char user[20];
char pasw[20];
int trouve;
char texte3[100];
GtkWidget* output ;
strcpy(texte3,"Mot de passe ou username incorrect");
username = lookup_widget (GTK_WIDGET(button), "FMnomentry");
password = lookup_widget (GTK_WIDGET(button),"FMmdpentry");
window=lookup_widget(GTK_WIDGET(button),"FMconnexion");
strcpy(user, gtk_entry_get_text(GTK_ENTRY(username)));
strcpy(pasw, gtk_entry_get_text(GTK_ENTRY(password)));
trouve=verif(user,pasw);
strcpy(login,user);
if(trouve==1)
{
windowEspaceAdmin=create_FMcrudcommandes();
 gtk_widget_show (windowEspaceAdmin);
 gtk_widget_destroy(window);

client c;
adress= lookup_widget(GTK_WIDGET(button),"entry428");
FILE *f;
char texte9[50];

f=fopen("inscription.txt","r");
if(f!=NULL)
{
while(fscanf(f,"%s %s %s %s %s %d %d %d %s %s %s \n",c.nom,c.prenom,c.username,c.password,c.email,&c.d.jour,&c.d.mois,&c.d.annee,c.adress,c.sexe,c.lieu)!=EOF)
{
if(strcmp(c.username,login)==0)
{

strcpy(texte9, c.username);

}
GtkWidget  *output2,*output3;
output2=lookup_widget(windowEspaceAdmin,"label409");
output3=lookup_widget(windowEspaceAdmin,"label456");


gtk_label_set_text(GTK_LABEL(output2),texte9);
gtk_label_set_text(GTK_LABEL(output3),texte9);
}
}
fclose(f);


}



else if ((strcmp(user,"admin")==0)&&(strcmp(pasw,"admin")==0)) {
windowEspaceAdmin2=create_Admin();
 gtk_widget_show (windowEspaceAdmin2);
 gtk_widget_destroy(window);

}
else{

output = lookup_widget(GTK_WIDGET(button), "label397") ;
gtk_label_set_text(GTK_LABEL(output),texte3);

}
}


void
on_FMcreercomptebutton_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{GtkWidget  *windowAuth,*window;
windowAuth= create_FMcreationcompte();
window=lookup_widget(GTK_WIDGET(button),"FMconnexion");
gtk_widget_show(windowAuth);

 gtk_widget_destroy(window);
//gtk_widget_destroy(GTK_WIDGET(button));


}




void
on_FMsinscrirebutton_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_FMannulbutton_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{

}

void
on_button56_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{FILE *f=NULL ;
GtkWidget *login, *pw ,*nom,*prenom,*adress,*jour,*mois,*annee,*email,*radiobutton9,*radiobutton10;
client c;
GtkWidget *FMcreationcompte;
GtkWidget  *windowAuth;
GtkWidget *CALENDAR;
//GtkComboBox *lieu;
GtkWidget *lieu;
char emaill[40];
int email_check=1;
int password_ok=0;
char userr[40];
char texte3[100];
GtkWidget* output ;
strcpy(texte3,"Username déja existant");
FMcreationcompte= lookup_widget(GTK_WIDGET(button),"FMcreationcompte");
nom= lookup_widget(GTK_WIDGET(button),"entry35");
prenom= lookup_widget(GTK_WIDGET(button),"entry36");
login= lookup_widget(GTK_WIDGET(button),"entry405");
pw= lookup_widget(GTK_WIDGET(button),"entry39");
email= lookup_widget(GTK_WIDGET(button),"entry34");
//jour= lookup_widget(GTK_WIDGET(button),"spinbutton13");
//mois= lookup_widget(GTK_WIDGET(button),"spinbutton14");
//annee= lookup_widget(GTK_WIDGET(button),"spinbutton15");
adress= lookup_widget(GTK_WIDGET(button),"entry38");
radiobutton9=lookup_widget(GTK_WIDGET(button),"radiobutton9");
radiobutton10=lookup_widget(GTK_WIDGET(button),"radiobutton10");
strcpy(c.nom, gtk_entry_get_text(GTK_ENTRY(nom)));
strcpy(c.prenom, gtk_entry_get_text(GTK_ENTRY(prenom)));
strcpy(c.username, gtk_entry_get_text(GTK_ENTRY(login)));
strcpy(c.password, gtk_entry_get_text(GTK_ENTRY(pw)));

CALENDAR=lookup_widget(button,"calendar2");
 gtk_calendar_get_date(GTK_CALENDAR(CALENDAR),&c.d.annee,&c.d.mois,&c.d.jour);
c.d.mois=c.d.mois+1;

lieu=lookup_widget(GTK_WIDGET(button), "comboboxentry1");
strcpy(c.lieu, gtk_combo_box_get_active_text(GTK_COMBO_BOX(lieu)));




strcpy(c.email, gtk_entry_get_text(GTK_ENTRY(email)));

if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(radiobutton9)))
  {strcpy(c.sexe,"Homme");}
  else if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(radiobutton10)))
  {strcpy(c.sexe,"Femme");}
//c.d.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
//c.d.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
//c.d.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));
strcpy(c.adress, gtk_entry_get_text(GTK_ENTRY(adress)));


strcpy(emaill, gtk_entry_get_text(GTK_ENTRY(email)));

strcpy(userr, gtk_entry_get_text(GTK_ENTRY(login)));

email_check=check_useremail(c.email);
password_ok=Verif_Password(c);
int test=existant(emaill,"inscription.txt"); 
int test2=existantusername(userr,"inscription.txt"); 

if(test == 1)  
{
GtkWidget *dialog3;
	dialog3=create_dialog3();
	gtk_widget_show(dialog3);
}

 if(test2 == 1)  
{
GtkWidget *dialog10;
	dialog10=create_dialog10();
	gtk_widget_show(dialog10);
}


 if(email_check==0)
	{
	GtkWidget *dialog1;
	dialog1=create_dialog1();
	gtk_widget_show(dialog1);
	}


 if(password_ok==0)
	{
	GtkWidget *dialog2;
	dialog2=create_dialog2();
	gtk_widget_show(dialog2);
	}
 if(email_check==1 && password_ok==1 /*&&test==1 && test2==1*/){

inscription_client("inscription.txt",c);
windowAuth= create_FMconnexion();
gtk_widget_show(windowAuth);
 gtk_widget_destroy(FMcreationcompte);
}
}


void
on_button55_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

GtkWidget  *windowAuth,*window;
window=lookup_widget(GTK_WIDGET(button),"FMcreationcompte");
windowAuth= create_FMconnexion();
gtk_widget_show(windowAuth);
 gtk_widget_destroy(window);
 
  }


void
on_button57_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{GtkWidget *FMcreationcompte;
GtkWidget *Fmcrud;
GtkWidget *FMtreeview;
GtkWidget *Homme;
GtkWidget *Femme;

//FMcreationcompte= lookup_widget(GTK_WIDGET(button),"FMcreationcompte");
//gtk_widget_destroy(FMcreationcompte);
Fmcrud=lookup_widget(GTK_WIDGET(button),"Fmcrud");
//Fmcrud=create_Fmcrud();
//gtk_widget_show(Fmcrud);
FMtreeview=lookup_widget(Fmcrud,"FMtreeview");
//afficher_client(FMtreeview);
Homme=lookup_widget(GTK_WIDGET(button),"checkbutton6");

Femme=lookup_widget(GTK_WIDGET(button),"checkbutton7");
if( gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON (Homme)))
{
afficher_client_homme(FMtreeview);
}
if( gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON (Femme)))
{
afficher_client_femme(FMtreeview);
}


if( gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON (Femme)) && gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON (Homme)) )
{
afficher_client(FMtreeview);
}

}


void
on_Fmajout_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget  *windowAuth;
windowAuth= create_FMmodif();
gtk_widget_show(windowAuth);

}


void
on_FMmodif_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{

GtkWidget  *windowAuth;
windowAuth= create_FMmodif();
gtk_widget_show(windowAuth);



}





void
on_FMsupp_clicked                      (GtkButton       *button,
                                        gpointer         user_data)
{

GtkWidget *fenetre_afficher;

  char email[30];
  GtkWidget *treeview1;
  GtkWidget *input1;
  input1=lookup_widget(GTK_WIDGET(button),"entry41");
  strcpy(email,gtk_entry_get_text(GTK_ENTRY(input1)));
  supprimer_client("inscription.txt",email);



 fenetre_afficher=lookup_widget(GTK_WIDGET(button),"Fmcrud");
 gtk_widget_destroy(fenetre_afficher);


 fenetre_afficher=create_Fmcrud();
 gtk_widget_show(fenetre_afficher);

  treeview1=lookup_widget(fenetre_afficher,"FMtreeview");
 afficher_client(treeview1);




/*
 GtkTreeSelection *selection;
          GtkTreeModel     *model;
          GtkTreeIter iter;
          GtkWidget* p;
gchar* nom;
gchar* prenom;
gchar* username;
gchar* password;
gchar* email2 ;
gint* jour;
gint* mois;
gint* annee;
gchar* adress;
gchar *sexe;
gchar *lieu;
client c;
          p=lookup_widget(button,"FMtreeview");
          selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(p));
          if (gtk_tree_selection_get_selected(selection, &model, &iter))
          { FILE*  f=fopen("inscription.txt","w+");
              gtk_list_store_remove(GTK_LIST_STORE(model),&iter);
            gboolean  valid=gtk_tree_model_get_iter_first(model,&iter);
              while ( valid)
              {



                gtk_tree_model_get (model,&iter,0, &nom,1, &prenom,2, &username,3,&password,4,&email2,5,&jour,6,&mois,7,&annee,8,&adress,9,&sexe,10,&lieu,-1);
                fprintf(f,"%s %s %s %s %s %d %d %d %s %s \n",nom,prenom,username,password,email2,jour,mois,annee,adress,sexe,lieu);

                  valid=gtk_tree_model_iter_next (model,&iter);
              }fclose(f);}
*/

}


void
on_FMrech_clicked                      (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *emaill,*Fmcrud;
char c[20];
GtkWidget *FMtreeview;

emaill=lookup_widget(GTK_WIDGET(button),"entry41");
Fmcrud=lookup_widget(GTK_WIDGET(button),"Fmcrud");
strcpy(c,gtk_entry_get_text(GTK_ENTRY(emaill)));
FMtreeview=lookup_widget(Fmcrud,"FMtreeview");
rechercher_client(c,FMtreeview);
}


  



void
on_FMtreeview_row_activated            (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
gchar* nom;
gchar* prenom;
gchar* username;
gchar* password;
gchar* email ;
gint* jour;
gint* mois;
gint* annee;
gchar* adress;
gchar *sexe;
gchar *lieu;
client c;
int a;
GtkTreeModel *model = gtk_tree_view_get_model(treeview);
if (gtk_tree_model_get_iter(model, &iter , path)) {
gtk_tree_model_get (GTK_LIST_STORE(model), &iter,0, &nom,1, &prenom,2, &username,3,&password,4,&email,5,&jour,6,&mois,7,&annee,8,&adress,9,&sexe,10,&lieu,-1);
strcpy(c.nom,nom);
strcpy(c.prenom,prenom);
strcpy(c.username,username);
strcpy(c.password,password);
strcpy(c.email,email);

strcpy(c.lieu,lieu);
c.d.jour=jour;
c.d.mois=mois;
c.d.annee=annee;
strcpy(c.adress,adress);
strcpy(c.sexe,sexe);

supprimer_client("inscription.txt",email);
//modifier_client(c);
afficher_client(treeview);
//rechercher("inscription.txt",email,&a);
}
}


void
on_button58_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{GtkWidget  *windowAuth;
windowAuth= create_Fmcrud();
gtk_widget_show(windowAuth);
//gtk_widget_destroy(GTK_WIDGET(button));

}


void
on_button59_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{ FILE *f;
client c;
  GtkWidget *login, *pw ,*nom,*prenom,*adress,*jour,*mois,*annee,*email,*radiobutton14,*radiobutton15,*treeview1,*lieu;

char MAIL[30];

GtkWidget *radiobutton9 , *radiobutton10, *fenetre_afficher;
nom= lookup_widget(GTK_WIDGET(button),"entry407");
prenom= lookup_widget(GTK_WIDGET(button),"entry408");
login= lookup_widget(GTK_WIDGET(button),"entry411");
pw= lookup_widget(GTK_WIDGET(button),"entry410");

jour= lookup_widget(GTK_WIDGET(button),"spinbutton16");
mois= lookup_widget(GTK_WIDGET(button),"spinbutton17");
annee= lookup_widget(GTK_WIDGET(button),"spinbutton18");
adress= lookup_widget(GTK_WIDGET(button),"entry409");
radiobutton14=lookup_widget(GTK_WIDGET(button),"radiobutton14");
radiobutton15=lookup_widget(GTK_WIDGET(button),"radiobutton15");
lieu=lookup_widget(GTK_WIDGET(button), "combobox18");
email= lookup_widget(GTK_WIDGET(button),"entry406");
strcpy(MAIL, gtk_entry_get_text(GTK_ENTRY(email)));
  supprimer_client("inscription.txt",MAIL);


strcpy(c.nom, gtk_entry_get_text(GTK_ENTRY(nom)));
strcpy(c.prenom, gtk_entry_get_text(GTK_ENTRY(prenom)));
strcpy(c.username, gtk_entry_get_text(GTK_ENTRY(login)));
strcpy(c.password, gtk_entry_get_text(GTK_ENTRY(pw)));


strcpy(c.email, gtk_entry_get_text(GTK_ENTRY(email)));
c.d.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
c.d.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
c.d.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));
strcpy(c.adress, gtk_entry_get_text(GTK_ENTRY(adress)));

if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(radiobutton14)))
  {strcpy(c.sexe,"Homme");}
  else if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(radiobutton15)))   
  {strcpy(c.sexe,"Femme");}

strcpy(c.lieu, gtk_combo_box_get_active_text(GTK_COMBO_BOX(lieu)));


inscription_client("inscription.txt", c);


}


void
on_button60_clicked                    (GtkButton       *button,
                                        gpointer         user_data)

{

GtkWidget *email, *nom,*prenom,*user,*passw,*adress, *jour , *mois, *annee,*radiobutton14,*radiobutton15,*lieu;
char ch3[40];
client c;
FILE *f;
f=fopen("inscription.txt","a+");
nom= lookup_widget(GTK_WIDGET(button),"entry407");
prenom= lookup_widget(GTK_WIDGET(button),"entry408");
user= lookup_widget(GTK_WIDGET(button),"entry411");
passw= lookup_widget(GTK_WIDGET(button),"entry410");
email= lookup_widget(GTK_WIDGET(button),"entry406");
jour= lookup_widget(GTK_WIDGET(button),"spinbutton16");
mois= lookup_widget(GTK_WIDGET(button),"spinbutton17");
annee= lookup_widget(GTK_WIDGET(button),"spinbutton18");
adress= lookup_widget(GTK_WIDGET(button),"entry409");
radiobutton14=lookup_widget(GTK_WIDGET(button),"radiobutton14");
radiobutton15=lookup_widget(GTK_WIDGET(button),"radiobutton15");
lieu=lookup_widget(GTK_WIDGET(button), "combobox18");

strcpy(ch3,gtk_entry_get_text(GTK_ENTRY(email)));

int test=0;

test=veriffares(ch3);
if(test==0)
{
  GtkWidget *dialog11;
	dialog11=create_dialog11();
	gtk_widget_show(dialog11); 
}


else if(test==1){
if (f!=NULL)
{
     while (fscanf(f,"%s %s %s %s %s %d %d %d %s %s %s \n",c.nom,c.prenom,c.username,c.password,c.email,&c.d.jour,&c.d.mois,&c.d.annee,c.adress,c.sexe,c.lieu)!=EOF)
	{
		if(strcmp(ch3,c.email)==0)
		{	

gtk_entry_set_text(nom,c.nom);
gtk_entry_set_text(prenom,c.prenom);
gtk_entry_set_text(user,c.username);
gtk_entry_set_text(passw,c.password);
gtk_entry_set_text(adress,c.adress);
gtk_entry_set_text(email,c.email);
gtk_spin_button_set_value(jour,c.d.jour);
gtk_spin_button_set_value(mois,c.d.mois);
gtk_spin_button_set_value(annee,c.d.annee);
if (strcmp(c.sexe,"Homme")==0)
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(radiobutton14),1);
    else if (strcmp(c.sexe,"Femme")==0)
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(radiobutton15),1);  






if(strcmp(c.lieu,"Ariana")==0)						
   gtk_combo_box_set_active (GTK_COMBO_BOX(lieu), 0);
if(strcmp(c.lieu,"Tunis")==0)						
   gtk_combo_box_set_active (GTK_COMBO_BOX(lieu), 1);
if(strcmp(c.lieu,"Manouba")==0)						
   gtk_combo_box_set_active (GTK_COMBO_BOX(lieu), 2);
if(strcmp(c.lieu,"BenArous")==0)						
   gtk_combo_box_set_active (GTK_COMBO_BOX(lieu), 3);

if(strcmp(c.lieu,"Nabeul")==0)						
   gtk_combo_box_set_active (GTK_COMBO_BOX(lieu), 4);

}}
fclose(f);
}
}
 }



void
validez_achat                          (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_checkbutton6_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_checkbutton7_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}

void
on_confirmercommande_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget* output ;
int i=0,j=0;
commande co;
GtkWidget *FMcommande;
char texte3[50],texte4[50]="";
GtkWidget *fm_tomate= lookup_widget(GTK_WIDGET(button),"spinbutton26");
GtkWidget *fm_carotte= lookup_widget(GTK_WIDGET(button),"spinbutton25");
GtkWidget *fm_epinard= lookup_widget(GTK_WIDGET(button),"spinbutton24");
GtkWidget *fm_pomme_de_terre= lookup_widget(GTK_WIDGET(button),"spinbutton23");
GtkWidget *fm_artichaud= lookup_widget(GTK_WIDGET(button),"spinbutton22");
GtkWidget *fm_brocoli= lookup_widget(GTK_WIDGET(button),"spinbutton21");
//GtkWidget *adress= lookup_widget(GTK_WIDGET(button),"entry428");
co.tomate=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(fm_tomate));
co.carotte=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(fm_carotte));
co.epinard=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(fm_epinard));
co.pomme_de_terre=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(fm_pomme_de_terre));
co.artichaud=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(fm_artichaud));
co.brocoli=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(fm_brocoli));
//co.adress, gtk_entry_get_text(GTK_ENTRY(adress));
co.prix=co.tomate*2+co.carotte*2+co.epinard*1+co.pomme_de_terre*3+co.artichaud*5+co.brocoli*1;
sprintf(texte3,"%d",co.prix);
strcpy(texte4,"Votre prix est ");
strcat(texte4,texte3);
strcat(texte3," dt");
output=lookup_widget(GTK_WIDGET(button),"label205");
gtk_label_set_text(GTK_LABEL(output),texte4);
//commandes("commande.txt",co);

gtk_widget_destroy(GTK_WIDGET(button));




/*
adress= lookup_widget(GTK_WIDGET(button),"entry428");
username= lookup_widget(GTK_WIDGET(button),"FMnomentry");
strcpy(c.adress, gtk_entry_get_text(GTK_ENTRY(adress)));

char ch3[50];
FILE *f;
f=fopen("inscription.txt","a+");

strcpy(ch3,gtk_entry_get_text(GTK_ENTRY(username)));

int test=0;

test=veriffares2(ch3);

if(test==1){
if (f!=NULL)
{
     while (fscanf(f,"%s %s %s %s %s %d %d %d %s %s %s \n",c.nom,c.prenom,c.username,c.password,c.email,&c.d.jour,&c.d.mois,&c.d.annee,c.adress,c.sexe,c.lieu)!=EOF)
	{
		if(strcmp(ch3,c.username)==0)
		{	

gtk_entry_set_text(username,c.username);


}
fclose(f);
}}
}
*/














}




void
on_affichertreeview_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *gestioncommande;
GtkWidget *treeviewcommande;

gestioncommande=lookup_widget(GTK_WIDGET(button),"gestioncommande");
//gestioncommande=create_gestioncommande();
//gtk_widget_show(gestioncommande);

treeviewcommande=lookup_widget(gestioncommande,"treeviewcommande");

afficher_commande(treeviewcommande);

}


void
on_treeviewcommande_row_activated      (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
GtkTreeModel *model = gtk_tree_view_get_model(treeview);
commande co;
gint* tomate;
gint* carotte ;
gint* epinard;  
gint*  pomme_de_terre ;
gint* artichaud;
gint* brocoli;
gchar* adress;


if(gtk_tree_model_get_iter(model,&iter,path)){
gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&tomate,1,&carotte,2,&epinard,3,&pomme_de_terre,4,&artichaud,5,&brocoli,6,&adress,-1);
co.tomate=tomate;
co.carotte=carotte;
co.epinard=epinard;
co.pomme_de_terre=pomme_de_terre;
co.artichaud=artichaud;
co.brocoli=brocoli;
strcpy(co.adress,adress);
afficher_commande(treeview);

}
}


void
on_button62_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

GtkWidget* output ;
GtkWidget *tomate, *carotte, *epinard , *pomme_de_terre , *artichaud ,*brocoli,*adress;
FILE *f=NULL ;
commande co;
GtkWidget *FMcommande;
char texte3[100];
client c;
adress= lookup_widget(GTK_WIDGET(button),"entry428");
FMcommande= lookup_widget(GTK_WIDGET(button),"FMcrudcommandes");
tomate= lookup_widget(GTK_WIDGET(button),"spinbutton26");
carotte= lookup_widget(GTK_WIDGET(button),"spinbutton25");
epinard= lookup_widget(GTK_WIDGET(button),"spinbutton24");
pomme_de_terre= lookup_widget(GTK_WIDGET(button),"spinbutton23");
artichaud= lookup_widget(GTK_WIDGET(button),"spinbutton22");
brocoli= lookup_widget(GTK_WIDGET(button),"spinbutton21");

co.tomate=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(tomate));
co.carotte=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(carotte));
co.epinard=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(epinard));
co.pomme_de_terre=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(pomme_de_terre));
co.artichaud=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(artichaud));
co.brocoli=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(brocoli));

char texte9[50];
f=fopen("inscription.txt","r");
if(f!=NULL)
{
while(fscanf(f,"%s %s %s %s %s %d %d %d %s %s %s \n",c.nom,c.prenom,c.username,c.password,c.email,&c.d.jour,&c.d.mois,&c.d.annee,c.adress,c.sexe,c.lieu)!=EOF)
{
if(strcmp(c.username,login)==0)
{
strcpy(co.adress, c.adress);

}



//gtk_label_set_text(GTK_LABEL(output3),texte6);

}
}
fclose(f);
commandes("commande.txt",co);

}

void
on_okemail_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{GtkWidget *fenetre_afficher;
  fenetre_afficher=lookup_widget(GTK_WIDGET(button),"dialog1");
 gtk_widget_destroy(fenetre_afficher);
}


void
on_okpass_clicked                      (GtkButton       *button,
                                        gpointer         user_data)
{
 GtkWidget *fenetre_afficher;
  fenetre_afficher=lookup_widget(GTK_WIDGET(button),"dialog2");
 gtk_widget_destroy(fenetre_afficher);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////Radhwen/////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

choix[]={0,0};
void
on_RKannulerbutton_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget  *windowAuth;
windowAuth = create_RKcrud();
gtk_widget_show(windowAuth);
}


void
on_RKenregistrerbutton_clicked         (GtkButton       *objet,
                                        gpointer         user_data)
{
FILE *f=NULL ;
GtkWidget *nom, *prenom ,*jour,*mois,*annee,*lieu,*adresse,*numcin,*numtel,*affectation,*fonction,*heurtravail,*oui,*non,*resultat;
ouvrier o;

char file_ouvrier[30]="fichier_ouvrier.txt";
char cin[50];
GtkWidget *dialog5;
GtkWidget *dialog4;
GtkWidget *RKajout;
RKajout = lookup_widget(objet,"RKajout");


nom = lookup_widget(objet,"RKentrynom");
prenom = lookup_widget(objet,"RKentryprenom");
jour = lookup_widget(objet,"RKspinjour");
mois = lookup_widget(objet,"RKspinmois");
annee = lookup_widget(objet,"RKspinannee");
lieu = lookup_widget(objet,"RKentrylieu");
adresse = lookup_widget(objet,"RKentryadress");
numcin = lookup_widget(objet,"RKentrycin");
numtel = lookup_widget(objet,"RKentrytel");
oui = lookup_widget(objet,"RKradiooui");
non = lookup_widget(objet,"RKradionon");
affectation = lookup_widget(objet,"RKcomboboxentryaffect");
fonction = lookup_widget(objet,"RKentryfonction");
heurtravail = lookup_widget(objet,"spinbutton11");
resultat=lookup_widget(objet,"labelteste");
strcpy(cin, gtk_entry_get_text(GTK_ENTRY(numcin)));
int 	test=recherche_ajout_ouvrier(cin,file_ouvrier); 
if(test == 1)  
{

	dialog4=create_dialog4();
	gtk_widget_show(dialog4);
}


else
{
strcpy(o.nom, gtk_entry_get_text(GTK_ENTRY(nom)));
strcpy(o.prenom, gtk_entry_get_text(GTK_ENTRY(prenom)));
o.D.jour= gtk_spin_button_get_value_as_int(GTK_ENTRY(jour));
o.D.mois= gtk_spin_button_get_value_as_int(GTK_ENTRY(mois));
o.D.annee= gtk_spin_button_get_value_as_int(GTK_ENTRY(annee));
strcpy(o.lieu_n, gtk_entry_get_text(GTK_ENTRY(lieu)));
strcpy(o.adresse, gtk_entry_get_text(GTK_ENTRY(adresse)));
strcpy(o.n_cin, gtk_entry_get_text(GTK_ENTRY(numcin)));
strcpy(o.n_tel, gtk_entry_get_text(GTK_ENTRY(numtel)));
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(oui))==TRUE){
strcpy(o.permis,"");
strcpy(o.permis,"Oui");}
else if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(non))==TRUE){
strcpy(o.permis,"");
strcpy(o.permis,"Non");}
strcpy(o.affectation, gtk_combo_box_get_active_text(GTK_COMBO_BOX(affectation)));
strcpy(o.fonction, gtk_entry_get_text(GTK_ENTRY(fonction)));
strcpy(o.nh_travail, gtk_entry_get_text(GTK_ENTRY(heurtravail)));
	ajouter_ouvrier(o,file_ouvrier);


	dialog5=create_dialog5();
	gtk_widget_show(dialog5);
}
}


void
on_RKrecherchebutton_clicked           (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *input,*output,*treeview2,*RKcrud;
char cherche[20];
char file_ouvrier[30]="fichier_ouvrier.txt";
input = lookup_widget(objet,"RKentryrecherche");
RKcrud=lookup_widget(objet,"RKcrud");
strcpy(cherche,gtk_entry_get_text(GTK_ENTRY(input)));
treeview2=lookup_widget(RKcrud,"treeview2");
	cherche_ouvrier(cherche,treeview2,file_ouvrier);
}


void
on_RKbuttonpagedacceuil_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_modif_button_annuler_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget  *windowAuth;
windowAuth = create_RKcrud();
gtk_widget_show(windowAuth);
}


void
on_RKbutton_valider_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *m_nom;
GtkWidget *m_prenom ;
GtkWidget *m_jour;
GtkWidget *m_mois;
GtkWidget *m_annee;
GtkWidget *m_lieu;
GtkWidget *m_adresse;
GtkWidget *m_numcin;
GtkWidget *m_numtel;
GtkWidget *m_oui;
GtkWidget *m_non;
GtkWidget *m_affectation;
GtkWidget *m_fonction;
GtkWidget *m_heurtravail;
GtkWidget *m_resultat;


ouvrier *o;
char file_ouvrier[30]="fichier_ouvrier.txt";
o=malloc(sizeof (ouvrier));

// IDENTIFIANT ENTRY TEXT
m_nom = lookup_widget(button,"entry416");
m_prenom = lookup_widget(button,"entry417");
m_jour= lookup_widget(button, "spinbutton15");
m_mois= lookup_widget(button, "spinbutton16");
m_annee= lookup_widget(button,"spinbutton17");
m_lieu = lookup_widget(button,"entry419");
m_adresse = lookup_widget(button,"entry420");
m_numcin = lookup_widget(button,"entry421");
m_numtel = lookup_widget(button,"entry422");
m_oui = lookup_widget(button,"radiobutton7");
m_non = lookup_widget(button,"radiobutton6");
m_affectation = lookup_widget(button,"aff");
m_fonction = lookup_widget(button,"entry418");
m_heurtravail = lookup_widget(button,"spinbutton18");

strcpy(o->nom, gtk_entry_get_text(GTK_ENTRY(m_nom)));
strcpy(o->prenom, gtk_entry_get_text(GTK_ENTRY(m_prenom)));
 o->D.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(m_jour));
 o->D.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(m_mois));
 o->D.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(m_annee));
strcpy(o->lieu_n, gtk_entry_get_text(GTK_ENTRY(m_lieu)));
strcpy(o->adresse, gtk_entry_get_text(GTK_ENTRY(m_adresse)));
strcpy(o->n_cin, gtk_entry_get_text(GTK_ENTRY(m_numcin)));
strcpy(o->n_tel, gtk_entry_get_text(GTK_ENTRY(m_numtel)));


if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(m_oui))==TRUE){
strcpy(o->permis,"");
strcpy(o->permis,"Oui");}
else if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(m_non))==TRUE){
strcpy(o->permis,"");
strcpy(o->permis,"Non");}


strcpy(o->affectation, gtk_combo_box_get_active_text(GTK_COMBO_BOX(m_affectation)));
strcpy(o->fonction, gtk_entry_get_text(GTK_ENTRY(m_fonction)));
////////////////o->nh_travail=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(m_heurtravail));
strcpy(o->nh_travail, gtk_entry_get_text(GTK_ENTRY(m_heurtravail)));





m_resultat=lookup_widget(button,"affichage");
if(( strcmp(o->nom,"")==0) || (strcmp(o->prenom,"")==0) || (strcmp(o->lieu_n,"")==0) || (strcmp(o->adresse,"")==0)||(strcmp(o->n_cin,"")==0) || (strcmp(o->n_tel,"")==0) ||(strcmp(gtk_combo_box_get_active_text(GTK_COMBO_BOX(m_affectation)),"")==0) || (strcmp(o->fonction,"")==0))
{
GtkWidget *dialog6;
	dialog6=create_dialog6();
	gtk_widget_show(dialog6);
}
else {
//strcpy(o->affectation, gtk_combo_box_get_active_text(GTK_COMBO_BOX(m_affectation)));

	int res= modifier_ouvrier( o,file_ouvrier);
	if (res==-1){
GtkWidget *dialog7;
	dialog7=create_dialog7();
	gtk_widget_show(dialog7);

}
	else if (res==0)
{
GtkWidget *dialog8;
	dialog8=create_dialog8();
	gtk_widget_show(dialog8);

}
	else if (res==1)
{GtkWidget *dialog9;
	dialog9=create_dialog9();
	gtk_widget_show(dialog9);

}
}

}


void
on_RKafficherbotton_clicked            (GtkButton       *objet,
                                        gpointer         user_data)
{
char file_ouvrier[30]="fichier_ouvrier.txt";
GtkWidget *RKajout;
GtkWidget *RKcrud;
GtkWidget *treeview2;

//RKajout = lookup_widget(objet,"RKajout");
//gtk_widget_destroy(RKajout);
RKcrud = lookup_widget(objet,"RKcrud");
//RKcrud = create_RKcrud();
gtk_widget_show(RKcrud);
treeview2 = lookup_widget(RKcrud,"treeview2");
affiche_ouvrier(treeview2,file_ouvrier);
}


void
on_RKsupprimbutton_clicked             (GtkButton       *objet,
                                        gpointer         user_data)
{GtkWidget *fenetre_afficher;
  char cherche[30];
  char file_ouvrier[30]="fichier_ouvrier.txt";
  GtkWidget *treeview1;
  GtkWidget *input1;
if(choix[1]==1)
{
  input1=lookup_widget(objet,"RKentryrecherche");
  strcpy(cherche,gtk_entry_get_text(GTK_ENTRY(input1)));
  RKsupprimer(cherche,file_ouvrier);
g_print("erreur recherche");
  fenetre_afficher=lookup_widget(objet,"RKcrud");
  gtk_widget_destroy(fenetre_afficher);
  fenetre_afficher=create_RKcrud();
  gtk_widget_show(fenetre_afficher);
  treeview1=lookup_widget(fenetre_afficher,"treeview2");
  affiche_ouvrier(treeview1,file_ouvrier);
  g_print("erreur affichage");
}

}

void
on_RKcheckselection_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton))
{choix[0]=1;}

}


void
on_RKcheckbouton_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton))
{choix[1]=1;}
}




void
on_RKmodif_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget  *windowAuth;
windowAuth = create_Rkmodifier();
gtk_widget_show(windowAuth);
}


void
on_RKajoutbutton_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget  *windowAuth;
windowAuth =create_RKajout();
gtk_widget_show(windowAuth);
}


void
on_treeview3_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;

gint* cin;
gint* jour;
gint* mois;
gint* annee;
gint* valeur;

absence p;

GtkTreeModel *model = gtk_tree_view_get_model(treeview);
if (gtk_tree_model_get_iter(model, &iter , path)) 
{
gtk_tree_model_get (GTK_LIST_STORE(model), &iter,0, &cin,1,&jour,2,&mois,3,&annee,4,&valeur,-1);
p.cin=cin;
p.jour=jour;
p.mois=mois;
p.annee=annee;
p.valeur=valeur;
	affiche_absence(treeview);

}
}


void
on_RKconfirmerbutton_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
absence p;
GtkWidget *cin;
/*GtkWidget *jour;
GtkWidget *mois;
GtkWidget *annee;*/
GtkWidget *CALENDAR;
GtkWidget *h_entree;
GtkWidget *h_sortie;

 cin= lookup_widget(button,"spinbutton21");
 CALENDAR=lookup_widget(button,"calendar1");

 /*jour= lookup_widget(button,"RKjourpresbutton");
 mois= lookup_widget(button,"RKmoispresbutton");
 annee= lookup_widget(button,"RKanneepresbutton");*/
 h_entree=lookup_widget(button,"spinbutton19");
 h_sortie=lookup_widget(button,"spinbutton20");
 
 p.cin=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(cin));
 /*p.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
 p.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
 p.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));*/
 gtk_calendar_get_date(GTK_CALENDAR(CALENDAR),&p.annee,&p.mois,&p.jour);
 p.mois=p.mois+1;
 p.h_entree=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(h_entree));
 p.h_sortie=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(h_sortie));
	pointer_ouvrier(p);
}


void
on_RKaffiche_absence_clicked           (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *RKcrud;
GtkWidget *treeview3;
RKcrud = lookup_widget(objet,"RKcrud");
gtk_widget_show(RKcrud);
treeview3 = lookup_widget(RKcrud,"treeview3");
	affiche_absence(treeview3);
}


void
on_RKacceuilpresence_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}
void
on_treeview2_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
char ouvrier_sup[30];
char file_ouvrier[30]="fichier_ouvrier.txt";
GtkTreeIter iter;
gchar* nom;
gchar* prenom;
gint* jour;
gint* mois;
gint* annee;
gchar* lieu;
gchar* adresse;
gchar* numcin;
gchar* numtel;
gchar* permis;
gchar* affectation;
gchar* fonction;
gchar* heurtravail;
ouvrier o;

GtkTreeModel *model = gtk_tree_view_get_model(treeview);
if (gtk_tree_model_get_iter(model, &iter , path)) 
{
gtk_tree_model_get (GTK_LIST_STORE(model), &iter,0, &nom,1, &prenom,2,&jour,3,&mois,4,&annee,5,&lieu,6,&adresse,7,&numcin,8,&numtel,9,&permis,10,&affectation,11,&fonction,12,&heurtravail,-1);
strcpy(o.nom,nom);
strcpy(o.prenom,prenom);
o.D.jour=jour;
o.D.mois=mois;
o.D.annee=annee;
strcpy(o.lieu_n,lieu);
strcpy(o.adresse,adresse);
strcpy(o.n_cin,numcin);
strcpy(o.n_tel,numtel);
strcpy(o.permis,permis);
strcpy(o.affectation,affectation);
strcpy(o.fonction,fonction);
strcpy(o.nh_travail,heurtravail);
if(choix[0]==1)
 { RKsupprimer(numcin,file_ouvrier) ;}
else if(choix[1]==1)
	{RKsupprimer(ouvrier_sup,file_ouvrier) ;}
	
	affiche_ouvrier(treeview,file_ouvrier);

}
}



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////Meriam/////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



/*selected= 999;
void on_treeview1_select_cursor_row()*/

void
on_row_selected                        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
  GtkTreeIter iter;
 
  
}

////////////////////////////////////////////////////////////////////////////button recherche/////////////////////////////////////////////////////////////////////////////////////

void
on_button1_clicked                     (GtkWidget       *objet,
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
if(verifMB(matr)==1)
{
   recherche(treeview1,matr);
}
else 
{
   ref2=create_MBwarn();
   gtk_widget_show(ref2);
   GtkWidget *misaj;
   char misa[30];
   strcpy(misa,"MATRICULE    INEXISTANT !");
   misaj=lookup_widget(ref2,"label30");
   gtk_label_set_text(GTK_LABEL(misaj),misa);
   
}


}

///////////////////////////////////////////////////////////////////////////////////////AFFICHER EL TREEVIEW///////////////////////////////////////////////////////////////////////////

void
on_MBbuttonaffich_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{
    GtkWidget *treeview1;
GtkWidget *crud;
char ch2[30];
crud= lookup_widget(objet,"MBcrud");
treeview1=lookup_widget(crud,"treeview1");
afficherMB(treeview1);


}

//////////////////////////////////////////////////////////////t7ell fenetre ajout/////////////////////////////////////////////////////////////////////////////

void
on_MBbuttonajout_clicked               (GtkWidget       *objet,
                                        gpointer         user_data)
{

	GtkWidget *MBajout;
       MBajout=create_MBajout();
gtk_widget_show(MBajout);
ref=lookup_widget(objet,"MBcrud");
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
supprimerMB(mat);
fenetre_afficher=lookup_widget(objet,"MBcrud");

treeview1=lookup_widget(fenetre_afficher,"treeview1");
afficherMB(treeview1);
}

///////////////////////////////////////////////////////////////////////t7ell fenetre modifier///////////////////////////////////////////////////////////////////////////
void
on_MBbuttonmodif_clicked               (GtkWidget       *objet,
                                        gpointer         user_data)
{
    GtkWidget *MBmodif;

 MBmodif=create_MBmodif();
gtk_widget_show(MBmodif);

ref=lookup_widget(objet,"MBcrud");
}
/////////////////////////////////////////////////////////////////////////Button filtre////////////////////////////////////////////////////////////////////////////////////////

void
on_MBbuttonfiltre_clicked              (GtkWidget      *objet,
                                        gpointer         user_data)
{
   GtkWidget *crud, *treeview1, *type1, *type2, *type3, *type4;
   char ch1[50], ch2[50], ch3[50], ch4[50];
   crud=lookup_widget(objet,"MBcrud");
   treeview1=lookup_widget(crud,"treeview1");
   type1=lookup_widget(objet, "MBchecktrac");
   type2=lookup_widget(objet, "MBcheckchar");
   type3=lookup_widget(objet, "MBcheckcheni");
   type4=lookup_widget(objet, "MBcheckmois");
   
if (gtk_toggle_button_get_active (GTK_CHECK_BUTTON(type1))==TRUE && gtk_toggle_button_get_active (GTK_CHECK_BUTTON(type2))==TRUE && gtk_toggle_button_get_active (GTK_CHECK_BUTTON(type3))==TRUE && gtk_toggle_button_get_active (GTK_CHECK_BUTTON(type4))==TRUE) 
   {
      strcpy(ch1,"tracteur");
      strcpy(ch2,"charrure_a_disques");
      strcpy(ch3,"chenille_agricole");
      strcpy(ch4,"moissonneuse");
      affichertyp4(treeview1, ch1, ch2, ch3,ch4);
   }
   else if (gtk_toggle_button_get_active (GTK_CHECK_BUTTON(type1))==TRUE && gtk_toggle_button_get_active (GTK_CHECK_BUTTON(type2))==TRUE && gtk_toggle_button_get_active (GTK_CHECK_BUTTON(type3))==TRUE ) 
   {
      strcpy(ch1,"tracteur");
      strcpy(ch2,"charrure_a_disques");
      strcpy(ch3,"chenille_agricole");
      affichertyp3(treeview1,ch1,ch2, ch3);
   }
   else if (gtk_toggle_button_get_active (GTK_CHECK_BUTTON(type1))==TRUE && gtk_toggle_button_get_active (GTK_CHECK_BUTTON(type2))==TRUE && gtk_toggle_button_get_active (GTK_CHECK_BUTTON(type4))==TRUE) 
   {
      strcpy(ch1,"tracteur");
      strcpy(ch2,"charrure_a_disques");
      strcpy(ch3,"moissonneuse");
      affichertyp3(treeview1,ch1,ch2, ch3);
   }
   else if (gtk_toggle_button_get_active (GTK_CHECK_BUTTON(type1))==TRUE && gtk_toggle_button_get_active (GTK_CHECK_BUTTON(type3))==TRUE && gtk_toggle_button_get_active (GTK_CHECK_BUTTON(type4))==TRUE) 
   {
      strcpy(ch1,"tracteur");
      strcpy(ch2,"chenille_agricole");
      strcpy(ch3,"moissonneuse");
      affichertyp3(treeview1,ch1,ch2, ch3);
   }
   else if (gtk_toggle_button_get_active (GTK_CHECK_BUTTON(type2))==TRUE && gtk_toggle_button_get_active (GTK_CHECK_BUTTON(type3))==TRUE && gtk_toggle_button_get_active (GTK_CHECK_BUTTON(type4))==TRUE)
   {
      strcpy(ch1,"charrure_a_disques");
      strcpy(ch2,"chenille_agricole");
      strcpy(ch3,"moissonneuse");
      affichertyp3(treeview1,ch1,ch2, ch3);
   }
   else if (gtk_toggle_button_get_active (GTK_CHECK_BUTTON(type1))==TRUE && gtk_toggle_button_get_active (GTK_CHECK_BUTTON(type2))==TRUE)
   {
      strcpy(ch1,"tracteur");
      strcpy(ch2,"charrure_a_disques");
      affichertyp2(treeview1,ch1,ch2);
   }
   else if (gtk_toggle_button_get_active (GTK_CHECK_BUTTON(type1))==TRUE && gtk_toggle_button_get_active (GTK_CHECK_BUTTON(type3))==TRUE)
   {
      strcpy(ch1,"tracteur");
      strcpy(ch2,"chenille_agricole");
      affichertyp2(treeview1,ch1,ch2);
   }
   else if (gtk_toggle_button_get_active (GTK_CHECK_BUTTON(type1))==TRUE && gtk_toggle_button_get_active (GTK_CHECK_BUTTON(type4))==TRUE)
   {
      strcpy(ch1,"tracteur");
      strcpy(ch2,"moissonneuse");
      affichertyp2(treeview1,ch1,ch2);
   }
    else if (gtk_toggle_button_get_active (GTK_CHECK_BUTTON(type2))==TRUE && gtk_toggle_button_get_active (GTK_CHECK_BUTTON(type3))==TRUE)
   {
      strcpy(ch1,"charrure_a_disques");
      strcpy(ch2,"chenille_agricole");
      affichertyp2(treeview1,ch1,ch2);
   }
   else if (gtk_toggle_button_get_active (GTK_CHECK_BUTTON(type2))==TRUE && gtk_toggle_button_get_active (GTK_CHECK_BUTTON(type4))==TRUE)
   {
      strcpy(ch1,"charrure_a_disques");
      strcpy(ch2,"moissonneuse");
      affichertyp2(treeview1,ch1,ch2);
   }
   else if (gtk_toggle_button_get_active (GTK_CHECK_BUTTON(type3))==TRUE && gtk_toggle_button_get_active (GTK_CHECK_BUTTON(type4))==TRUE)
   {
      strcpy(ch1,"chenille_agricole");
      strcpy(ch2,"moissonneuse");
      affichertyp2(treeview1,ch1,ch2);
   }

    else if (gtk_toggle_button_get_active (GTK_CHECK_BUTTON(type1))==TRUE) 
    {
         strcpy(ch1,"tracteur");
         affichertyp1(treeview1,ch1);
    }
    
    else if (gtk_toggle_button_get_active (GTK_CHECK_BUTTON(type2))==TRUE)
    {
       strcpy(ch1,"charrure_a_disques");
       affichertyp1(treeview1,ch1);
    } 
    else if (gtk_toggle_button_get_active (GTK_CHECK_BUTTON(type3))==TRUE) 
    {
       strcpy(ch1,"chenille_agricole");
       affichertyp1(treeview1,ch1);
    }
    else if (gtk_toggle_button_get_active (GTK_CHECK_BUTTON(type4))==TRUE) 
    {
       strcpy(ch1,"moissonneuse");
       affichertyp1(treeview1,ch1);
    }
    
   
    
   
}

///////////////////////////////////////////////////////BOUTON ENREGISTRER FEL AJOUT////////////////////////////////////////////////////////////////////////////////////////////////////////////

void
on_MBbuttonenregistrer_clicked         (GtkWidget      *objet,
                                        gpointer         user_data)
{

	
	 GtkWidget *marque1,*marque2,*marque3,*marque4,*marque5, *mat, *puissfis, *annee;
GtkWidget *fenetre_ajout,*MBmsg;
GtkSpinButton *datev_j,*datev_m,*datev_a, *datee_j,*datee_m,*datee_a;
GtkComboBox *type;
equipement e;
char msg[60];


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
MBmsg=lookup_widget(fenetre_ajout,"MBmsg");

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
GtkWidget* Calendar;
Calendar=lookup_widget(objet,"calendarMB");
 gtk_calendar_get_date(GTK_CALENDAR(Calendar),&c,&b,&a);
b=b+1;
sprintf(ch,"%d/%d/%d",a,b,c);
strcpy(e.date_entr,ch);
//puissance input
strcpy(e.puissance_fiscale,gtk_entry_get_text(GTK_ENTRY(puissfis)));
if(verifMB(e.matricule)==1)
{
	strcpy(msg,"Erreur: Matricule existe deja!");
}
else
{
ajoutMB(e);
strcpy(msg,"Ajout avec succees.");
}
gtk_label_set_text(GTK_LABEL(MBmsg),msg);

GtkWidget *crud, *tv;
crud=ref;
tv=lookup_widget(crud,"treeview1");
afficherMB(tv);


}


//////////////////////////////////////////////////////////////////////////////////modifier t3ammer wa7adha/////////////////////////////////////////////////////////////////////

void
on_rechmat_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{  FILE* f=NULL;
equipement e;
int j,m,a;
	GtkWidget *matricule,*type, *marque1,*marque2,*marque3,*marque4,*marque5,*p,*annee, *datevj, *datevm, *dateva, *dateej, *dateem, *dateea,*msginex, *MBmsg ;
char ch3[40],msg[50],ch[20]=" ";
f=fopen("equipements.txt","a+");
matricule=lookup_widget(objet,"Matmodif");
annee=lookup_widget(objet, "anneemodif");
marque1=lookup_widget(objet, "marka1");
marque2=lookup_widget(objet, "marka2");
marque3=lookup_widget(objet, "marka3");
marque4=lookup_widget(objet, "marka4");
marque5=lookup_widget(objet, "marka5");
type=lookup_widget(objet, "typemodif");
datevj=lookup_widget(objet, "jmodif");
datevm=lookup_widget(objet, "mmodif");
dateva=lookup_widget(objet, "amodif");
dateej=lookup_widget(objet, "j1modif");
dateem=lookup_widget(objet, "m1modif");
dateea=lookup_widget(objet, "a1modif");
p=lookup_widget(objet, "puissancemodif");
GtkWidget *fenetre_modif;
fenetre_modif=lookup_widget(objet,"MBmodif");
msginex=lookup_widget(fenetre_modif,"msginex");
MBmsg=lookup_widget(fenetre_modif,"label25");

strcpy(ch3,gtk_entry_get_text(GTK_ENTRY(matricule)));
gtk_label_set_text(GTK_LABEL(MBmsg),ch);
gtk_label_set_text(GTK_LABEL(msginex),ch);
if(verifMB(ch3)==0)
{
    strcpy(msg,"Matricule inexistant!");
    gtk_label_set_text(GTK_LABEL(msginex),msg);
}


else if(f!=NULL)
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
 //COMBO BOX
if(strcmp(e.type,"tracteur")==0)						
   gtk_combo_box_set_active (GTK_COMBO_BOX(type), 0);
if(strcmp(e.type,"charrure_a_disques")==0)						
   gtk_combo_box_set_active (GTK_COMBO_BOX(type), 1);
if(strcmp(e.type,"chenille_agricole")==0)						
   gtk_combo_box_set_active (GTK_COMBO_BOX(type), 2);
if(strcmp(e.type,"moissonneuse")==0)						
   gtk_combo_box_set_active (GTK_COMBO_BOX(type), 3);
			
		}
	}
    fclose(f);
}


}

/////////////////////////////////////////////////////////////////////////yfassa5 w yzid/////////////////////////////////////////////////////////////////////////////////////

void
on_MBbaddel_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
    FILE* f=NULL;
equipement e; 
    GtkWidget *matricule,*type, *marque1,*marque2,*marque3,*marque4,*marque5,*p,*annee, *datevj, *datevm, *dateva, *dateej, *dateem, *dateea, *fenetre_modif,*MBmsg ;
char msg[40];
f=fopen("equipements.txt","a+");
matricule=lookup_widget(objet,"Matmodif");
annee=lookup_widget(objet, "anneemodif");
marque1=lookup_widget(objet, "marka1");
marque2=lookup_widget(objet, "marka2");
marque3=lookup_widget(objet, "marka3");
marque4=lookup_widget(objet, "marka4");
marque5=lookup_widget(objet, "marka5");
type=lookup_widget(objet, "typemodif");
datevj=lookup_widget(objet, "jmodif");
datevm=lookup_widget(objet, "mmodif");
dateva=lookup_widget(objet, "amodif");
dateej=lookup_widget(objet, "j1modif");
dateem=lookup_widget(objet, "m1modif");
dateea=lookup_widget(objet, "a1modif");
p=lookup_widget(objet, "puissancemodif");
fenetre_modif=lookup_widget(objet,"MBmodif");
MBmsg=lookup_widget(fenetre_modif,"label25");

//mat
strcpy(e.matricule,gtk_entry_get_text(GTK_ENTRY(matricule)));
supprimerMB(e.matricule);

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


if (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(marque1))==TRUE) strcpy(e.marque,"JHON_DEERE");
    else if (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(marque2))==TRUE) strcpy(e.marque,"RENAULT");
    else if (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(marque3))==TRUE) strcpy(e.marque,"SOMECA");
    else if (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(marque4))==TRUE) strcpy(e.marque,"FORDOSON");
    else if (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(marque5))==TRUE) strcpy(e.marque,"FIAT");
//annee input
    
e.annee= gtk_spin_button_get_value_as_int(annee);


//datev input
int a,b,c;
char ch[50];
a= gtk_spin_button_get_value_as_int(datevj);
b= gtk_spin_button_get_value_as_int(datevm);
c= gtk_spin_button_get_value_as_int(dateva);
sprintf(ch,"%d/%d/%d",a,b,c);
strcpy(e.date_visite,ch);
//datee input
a= gtk_spin_button_get_value_as_int(dateej);
b= gtk_spin_button_get_value_as_int(dateem);
c= gtk_spin_button_get_value_as_int(dateea);
sprintf(ch,"%d/%d/%d",a,b,c);
strcpy(e.date_entr,ch);
//puissance input
strcpy(e.puissance_fiscale,gtk_entry_get_text(GTK_ENTRY(p)));

ajoutMB(e);
strcpy(msg,"Modifie avec succees.");

gtk_label_set_text(GTK_LABEL(MBmsg),msg);

GtkWidget *crud, *treeview1;
crud= ref;
treeview1=lookup_widget(ref,"treeview1");
afficherMB(treeview1);

}

////////////////////////////////////////////////////Retour lel crud///////////////////////////////////////////////////////
void
on_retourmodif_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
   GtkWidget *MBcrud, *MBajout;
   
       MBcrud=create_MBcrud();
gtk_widget_show(MBcrud);
MBajout=lookup_widget(objet,"MBajout");
gtk_widget_destroy (MBajout);

}


void
on_retourajout_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{  
    GtkWidget *MBcrud, *MBmodif;
       MBcrud=create_MBcrud();
gtk_widget_show(MBcrud);
MBmodif=lookup_widget(objet,"MBmodif");
gtk_widget_destroy (MBmodif);

}






///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////






void
on_okbutton1_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *dialog1;
dialog1= lookup_widget(GTK_WIDGET(button),"dialog1");

 gtk_widget_destroy(dialog1);
}


void
on_okbutton2_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *dialog2;
dialog2= lookup_widget(GTK_WIDGET(button),"dialog2");

 gtk_widget_destroy(dialog2);
}


void
on_okbutton3_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *dialog3;
dialog3= lookup_widget(GTK_WIDGET(button),"dialog3");

 gtk_widget_destroy(dialog3);
}




void
on_button69_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *fenetre_afficher;
GtkWidget  *FMconnexion;
FMconnexion= create_FMconnexion();

  fenetre_afficher=lookup_widget(GTK_WIDGET(button),"FMcrudcommandes");
 gtk_widget_destroy(fenetre_afficher);
gtk_widget_show(FMconnexion);
}





///////////////////////////////////////////////////MAROUA/////////////////////////////////////////////////////////////////////////

char nomfich[150]="naissance.txt";

void
on_MarouaHamdibuttonNaissance_clicked  (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_MarouaHamdibuttonRecensement001_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_MarouaHamdibuttonRetour_clicked     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *MHwindownaissance, *MHwindowrec;
MHwindowrec=lookup_widget(objet,"MHwindowrec");
gtk_widget_destroy(MHwindownaissance);
MHwindowrec=create_MHwindowrec();
gtk_widget_show(MHwindowrec);

}

void
on_MHbuttonsupp_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
char id[30];
GtkWidget *treeviewMH;
GtkWidget *input1;

input1=lookup_widget(objet,"MHentryIdcherch");
strcpy(id,gtk_entry_get_text(GTK_ENTRY(input1)));
supprimer_tr("naissance.txt",id);

treeviewMH=lookup_widget(objet,"treeviewMH");

afficher_tr(treeviewMH);


}


void
on_MHbuttonrecherche_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_MHbuttonmodif_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{GtkWidget  *windowAuth;
windowAuth= create_MHwindowmodif();
gtk_widget_show(windowAuth);  
/*GtkWidget *MHwindowmodif =lookup_widget(objet,"MHwindowmodif");
gtk_widget_show(MHwindowmodif);*/
}

void
on_MHbuttonvalider_clicked             (GtkButton       *Window,
                                        gpointer         user_data)
{
GtkWidget* Male;
GtkWidget* femelle;
GtkWidget* jour;
GtkWidget* mois;
GtkWidget* annee;
GtkWidget* jourV;
GtkWidget* moisV;
GtkWidget* anneeV;
GtkWidget* ComboBox;
GtkWidget* Identifiant;
GtkWidget* resultat;
char type[10];
char Identif [20];
char Sexe[10];
naissance m;



Identifiant = lookup_widget(Window, "MarouaHamdientryIdentifiant");
strcpy(m.identifiant,gtk_entry_get_text(GTK_ENTRY(Identifiant)));
g_print("Identifiant est %s\n",m.identifiant);


Male = lookup_widget(Window, "MHradiobuttonMale");
femelle = lookup_widget(Window, "MHradiobuttonFemelle");
if (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(femelle)))
{ 
 strcpy(m.sexe,"femelle");

}
else if (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(Male)))
{
 strcpy(m.sexe,"male");
 
}
g_print("sexe=%s\n",m.sexe);

jour= lookup_widget(Window, "MarouaHamdispinbuttonJour");
mois= lookup_widget(Window, "MarouaHamdispinbuttonMois");
annee= lookup_widget(Window,"MarouaHamdispinbuttonAnnee");
m.date_naissance.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
m.date_naissance.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
m.date_naissance.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));
g_print("j=%d,m=%d,a=%d\n",m.date_naissance.jour,m.date_naissance.mois,m.date_naissance.annee);

GtkWidget* Calendar;
Calendar=lookup_widget(Window,"calendarMH");
 gtk_calendar_get_date(GTK_CALENDAR(Calendar),&m.date_vaccin.annee,&m.date_vaccin.mois,&m.date_vaccin.jour);
m.date_vaccin.mois=m.date_vaccin.mois+1;

g_print("j=%d,m=%d,a=%d\n",m.date_vaccin.jour,m.date_vaccin.mois,m.date_vaccin.annee);


 resultat=lookup_widget(Window, "MHlabelRes");


ComboBox= lookup_widget(Window,"MHcomboboxType");


 if ((strcmp(m.identifiant," ")==0) || gtk_combo_box_get_active_text(GTK_COMBO_BOX(ComboBox))==NULL) {
gtk_label_set_text(GTK_LABEL(resultat),"Champs vides");
}

else{
strcpy(m.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(ComboBox)));
g_print("type = %s\n",m.type);

}

int r=ajout (m,nomfich);
if (r==1)
	gtk_label_set_text(GTK_LABEL(resultat),"Ajout termine avec succes!");
else if(r==-1)
	gtk_label_set_text(GTK_LABEL(resultat),"Identifiant existant!");
else if(r==2)
	gtk_label_set_text(GTK_LABEL(resultat),"Erreur date de naissance!");
else 
	gtk_label_set_text(GTK_LABEL(resultat),"Erreur date vaccin!");
}





void
on_button3_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_MHbuttonchercher_clicked            (GtkWidget       *window,
                                        gpointer         user_data)
{
GtkWidget *identifiant,*MHwindowrec;
char d[20];
GtkWidget *treeviewMH;

identifiant=lookup_widget(window,"MHentryIdcherch");
MHwindowrec=lookup_widget(window,"MHwindowrec");
strcpy(d,gtk_entry_get_text(GTK_ENTRY(identifiant)));
treeviewMH=lookup_widget(MHwindowrec,"treeviewMH");
rechercher_animal(d,treeviewMH);

}


void
on_treeviewMH_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
	GtkTreeIter iter;
	gchar* identifiant;
	gchar* type;
	gchar* sexe;
	gint* jour;
	gint* mois;
	gint* annee;
	gint* jourV;
	gint* moisV;
	gint* anneeV;
	naissance n;

	GtkTreeModel *model = gtk_tree_view_get_model(treeview);
	if (gtk_tree_model_get_iter(model, &iter, path))
	{
		gtk_tree_model_get (GTK_LIST_STORE(model), &iter, 0, &identifiant, 1, &type,2,&sexe,3,&jour,4,&mois,5,&annee,6,&jourV,7,&moisV,8,&anneeV, -1);
	strcpy(n.identifiant,identifiant);
	strcpy(n.type,type);
	strcpy(n.sexe,sexe);
	n.date_naissance.jour=jour;
	n.date_naissance.mois=mois;
	n.date_naissance.annee=annee;
	n.date_vaccin.jour=jourV;
	n.date_vaccin.mois=moisV;
	n.date_vaccin.annee=anneeV;
	
	supprimer_tr("naissance.txt",identifiant);
	afficher_tr(treeview);
}

}


void
on_MHbuttonAfficher_clicked            (GtkWidget       *window,
                                        gpointer         user_data)
{
GtkWidget *MHwindownaissance;
GtkWidget *MHwindowrec;
GtkWidget *treeviewMH;

MHwindownaissance=lookup_widget(window,"MHwindownaissance");
gtk_widget_destroy(MHwindownaissance);
MHwindowrec=lookup_widget(window,"MHwindowrec");
MHwindowrec=create_MHwindowrec();

gtk_widget_show(MHwindowrec);

treeviewMH=lookup_widget(MHwindowrec,"treeviewMH");

afficher_tr(treeviewMH);



}


void
on_MHbuttonMAJ_clicked                 (GtkWidget       *Window,
                                        gpointer         user_data)
{
GtkWidget* Male;
GtkWidget* femelle;
GtkWidget* jour;
GtkWidget* mois;
GtkWidget* annee;
GtkWidget* jourV;
GtkWidget* moisV;
GtkWidget* anneeV;
GtkWidget* ComboBox;
GtkWidget* Identifiant;
GtkWidget* resultat;
char type[10];
char Identif [20];
char Sexe[10];
naissance m;



Identifiant = lookup_widget(Window, "MHentryNvId");
strcpy(m.identifiant,gtk_entry_get_text(GTK_ENTRY(Identifiant)));

Male = lookup_widget(Window, "MHradiobuttonM");
femelle = lookup_widget(Window, "MHradiobuttonF");
if (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(femelle)))
{ 
 strcpy(m.sexe,"femelle");

}
else if (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(Male)))
{
 strcpy(m.sexe,"male");
 
}


jour= lookup_widget(Window, "MHspinbuttonNJ");
mois= lookup_widget(Window, "MHspinbuttonNM");
annee= lookup_widget(Window,"MHspinbuttonNA");
m.date_naissance.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
m.date_naissance.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
m.date_naissance.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));

jourV= lookup_widget(Window, "MHspinbuttonVJ");
moisV= lookup_widget(Window, "MHspinbuttonVM");
anneeV= lookup_widget(Window,"MHspinbuttonVA");
 m.date_vaccin.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jourV));
 m.date_vaccin.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(moisV));
 m.date_vaccin.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(anneeV));


 //resultat=lookup_widget(Window, "MHlabelRes");


ComboBox= lookup_widget(Window,"MHcomboboxmodif");


 if ((strcmp(m.identifiant," ")==0) || gtk_combo_box_get_active_text(GTK_COMBO_BOX(ComboBox))==NULL) {
gtk_label_set_text(GTK_LABEL(resultat),"Champs vides");
}

else{
strcpy(m.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(ComboBox)));
}

int r=modifierMH (&m,nomfich);
/*if (r==1)
	gtk_label_set_text(GTK_LABEL(resultat),"Ajout termine avec succes!");
else    gtk_label_set_text(GTK_LABEL(resultat),"Identifiant existant!");
*/
}


void
on_MHbuttonQM_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *MHwindowmodif, *MHwindowrec;
MHwindowrec=lookup_widget(objet,"MHwindowrec");
gtk_widget_destroy(MHwindowmodif);
MHwindowrec=create_MHwindowrec();
gtk_widget_show(MHwindowrec);

}


void
on_MHbuttonRechMod_clicked             (GtkWidget       *Window,
                                        gpointer         user_data)
{
GtkWidget *id, *type,*male, *femelle,*nj,*nm,*na, *vj , *vm, *va;
char identifiant[20];
naissance *n;
char nomfich[100]="naissance.txt";

id = lookup_widget (Window,"MHentryRechMod");
strcpy(identifiant,gtk_entry_get_text(GTK_ENTRY(id)));

n=chercher (identifiant,nomfich);
if(n!=NULL)
{

id= lookup_widget(Window,"MHentryNvId");
gtk_entry_set_text(id,n->identifiant);
male = lookup_widget(Window, "MHradiobuttonM");
femelle = lookup_widget(Window, "MHradiobuttonF");
if (strcmp(n->sexe,"femelle")==0)
{
    gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON(femelle),TRUE);
}
else 
{	gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON(male),TRUE);
}

nj= lookup_widget(Window, "MHspinbuttonNJ");
nm= lookup_widget(Window, "MHspinbuttonNM");
na= lookup_widget(Window,"MHspinbuttonNA");
gtk_spin_button_set_value(GTK_SPIN_BUTTON(nj),n->date_naissance.jour);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(nm),n->date_naissance.mois);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(na),n->date_naissance.annee);

vj= lookup_widget(Window, "MHspinbuttonVJ");
vm= lookup_widget(Window, "MHspinbuttonVM");
va= lookup_widget(Window,"MHspinbuttonVA");
gtk_spin_button_set_value(GTK_SPIN_BUTTON(vj),n->date_vaccin.jour);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(vm),n->date_vaccin.mois);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(vm),n->date_vaccin.annee);

type= lookup_widget(Window,"MHcomboboxmodif");
int t=-1;
if (strcmp(n->type,"vache")==0)
t=0;
else if (strcmp(n->type,"chevre")==0)
t=1;
else if (strcmp(n->type,"brebis")==0)
t=2;
else if (strcmp(n->type,"veau")==0)
t=3;
gtk_combo_box_set_active(GTK_COMBO_BOX(type),t);

}

}

void
on_MHbuttonAfficherType_clicked        (GtkWidget       *window,
                                        gpointer         user_data)
{
GtkWidget *MHwindowrec;
GtkWidget *vache;
GtkWidget *veau;
GtkWidget *chevre;
GtkWidget *brebis;
GtkWidget *tr;
int va, vo, ch,bre;
MHwindowrec=lookup_widget(window,"MHwindowrec");
vache=lookup_widget(window,"MHcheckbuttonVache");
veau=lookup_widget(window,"MHcheckbuttonVeau");
brebis=lookup_widget(window,"MHcheckbuttonBrebis");
chevre=lookup_widget(window,"MHcheckbuttonChevre");
tr=lookup_widget(window,"treeviewMH");

va=gtk_toggle_button_get_active(GTK_CHECK_BUTTON(vache));
vo=gtk_toggle_button_get_active(GTK_CHECK_BUTTON(veau));
bre=gtk_toggle_button_get_active(GTK_CHECK_BUTTON(brebis));
ch=gtk_toggle_button_get_active(GTK_CHECK_BUTTON(chevre));
afficher_type(tr,va,vo,ch,bre);


}


void
on_MHbuttonAfficherT_clicked        (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget  *windowAuth;
windowAuth= create_MHwindowAffichage();
gtk_widget_show(windowAuth); 
}





void
on_MHbuttonajout_clicked               (GtkWidget       *objet,
                                        gpointer         user_data)
{GtkWidget  *windowAuth;
windowAuth= create_MHwindownaissance();
gtk_widget_show(windowAuth); 


}


void
on_MHbuttonAfficherP2_clicked          (GtkWidget       *objet,
                                        gpointer         user_data)
{
int v=0,c=0,b=0,vo=0;
char buffer [50];
GtkWidget *mhentry1, *mhentry2 , *mhentry3, *mhentry4;
afficher_nbre_troupeaux(&v, &c, &b, &vo, "naissance.txt");

mhentry1=lookup_widget(objet,"MHentryVache1");
sprintf(buffer,"%d",v);
gtk_entry_set_text(GTK_ENTRY(mhentry1),buffer);

mhentry2=lookup_widget(objet,"MHentryChevre1");
sprintf(buffer,"%d",c);
gtk_entry_set_text(GTK_ENTRY(mhentry2),buffer);

mhentry3=lookup_widget(objet,"MHentryBrebis1");
sprintf(buffer,"%d",b);
gtk_entry_set_text(GTK_ENTRY(mhentry3),buffer);

mhentry4=lookup_widget(objet,"MHentryVeau1");
sprintf(buffer,"%d",vo);
gtk_entry_set_text(GTK_ENTRY(mhentry4),buffer);
}






void
on_okbutton4_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *dialog4;
dialog4= lookup_widget(GTK_WIDGET(button),"dialog4");

 gtk_widget_destroy(dialog4);
}


void
on_okbutton5_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *dialog5;
dialog5= lookup_widget(GTK_WIDGET(button),"dialog5");

 gtk_widget_destroy(dialog5);
}


void
on_okbutton6_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *dialog6;
dialog6= lookup_widget(GTK_WIDGET(button),"dialog6");

 gtk_widget_destroy(dialog6);
}


void
on_okbutton7_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *dialog7;
dialog7= lookup_widget(GTK_WIDGET(button),"dialog7");

 gtk_widget_destroy(dialog7);
}


void
on_okbutton8_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *dialog8;
dialog8= lookup_widget(GTK_WIDGET(button),"dialog8");

 gtk_widget_destroy(dialog8);
}


void
on_okbutton9_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *dialog9;
dialog9= lookup_widget(GTK_WIDGET(button),"dialog9");

 gtk_widget_destroy(dialog9);
}





void
on_okbutton10_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *dialog10;
dialog10= lookup_widget(GTK_WIDGET(button),"dialog10");

 gtk_widget_destroy(dialog10);
}





void
on_button72_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *FMcommande;
GtkWidget* output ;
GtkWidget* output2 ;
GtkWidget* output3 ;
absence2 aa;
float ab;
int c;
int i;
int id;

float test=100;
float taux_absenteisme;
absence a;
GtkWidget* c1 ;
char texte3[50];
char texte4[50];
char texte5[50];
char texte6[50];
char texte7[50];
output=lookup_widget(GTK_WIDGET(button),"FMtaux1");
c1 = lookup_widget (GTK_WIDGET(button),"spinbutton30");
c= gtk_spin_button_get_value_as_int(GTK_ENTRY(c1));


absents2(aa,&ab,c);
sprintf(texte3,"%.2f ",ab);
strcpy(texte4,"%");
strcat(texte3,texte4);
gtk_label_set_text(GTK_LABEL(output),texte3);


output2=lookup_widget(GTK_WIDGET(button),"RKmeilleur1");
output3=lookup_widget(GTK_WIDGET(button),"RKmeilleur2");
for(i=1;i<10;i++)
{
absents (i,aa,&taux_absenteisme);
if (taux_absenteisme < test)
          {          
            test=taux_absenteisme;
            id=i;   
     
          }
        }
sprintf(texte5,"%d ",id);
gtk_label_set_text(GTK_LABEL(output2),texte5);


sprintf(texte6,"%.2f ",test);
strcpy(texte7,"%");
strcat(texte6,texte7);
gtk_label_set_text(GTK_LABEL(output3),texte6);

}



void
on_btooon_clicked                      (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *fenetre_afficher;
GtkWidget  *FMconnexion;
FMconnexion= create_FMconnexion();

  fenetre_afficher=lookup_widget(GTK_WIDGET(button),"Admin");
 gtk_widget_destroy(fenetre_afficher);
gtk_widget_show(FMconnexion);
}


void
on_ffffzzzz_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *fenetre_afficher;
GtkWidget *fenetre_afficher2;
GtkWidget  *FMconnexion;
FMconnexion= create_FMconnexion();
fenetre_afficher2=lookup_widget(GTK_WIDGET(button),"Admin");
  fenetre_afficher=lookup_widget(GTK_WIDGET(button),"Fmcrud");
 gtk_widget_destroy(fenetre_afficher);
 gtk_widget_destroy(fenetre_afficher2);
gtk_widget_show(FMconnexion);
}




void
on_supprimercommande_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
GtkTreeSelection *selection;
          GtkTreeModel     *model;
          GtkTreeIter iter;
          GtkWidget* p;
;
gint*  tomate;
gint* carotte;
gint* epinard;
gint* pomme_de_terre;
gint* artichaud;
gint* brocoli;
gint* prix;
gchar* adress;

          p=lookup_widget(button,"treeviewcommande");
          selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(p));
          if (gtk_tree_selection_get_selected(selection, &model, &iter))
          { FILE*  f=fopen("commande.txt","w+");
              gtk_list_store_remove(GTK_LIST_STORE(model),&iter);
            gboolean  valid=gtk_tree_model_get_iter_first(model,&iter);
              while ( valid)
              {



                gtk_tree_model_get (model,&iter,0, &tomate,1, &carotte,2, &epinard,3,&pomme_de_terre,4,&artichaud,5,&brocoli,6,&prix,-1);
                fprintf(f," %d %d %d %d %d %d %d %s  \n",tomate,carotte,epinard,pomme_de_terre,artichaud,brocoli,prix,adress);

                  valid=gtk_tree_model_iter_next (model,&iter);
              }fclose(f);}

}

////////////////////////////////////////////////////////////////////////////////////////////////////MABF crud///////////////////////////////////////////////////////////////////////////////////////////////////////

char
data_base[]="plantation.bin",
head_color[]="head_color.bin",
body_color[]="body_color.bin",
button_color[]="button_color.bin",
calendar_color[]="calendar_color.bin",
TreeView_color[]="treeview_color.bin",
background_color[]="background_color.bin",
dialog_color[]="dialog_color.bin",
data_photo[]="photo.bin",
default_photo[]="/home/aminous/Desktop/smart_farm/pixmaps/add_photo.png",
broken_photo[]="/home/aminous/Desktop/smart_farm/pixmaps/broken_photo.png";

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void on_MABFButtonAjouter_clicked(GtkWidget *MABFWidget,gpointer user_data){
FILE *f=NULL;
GdkColor col;
plantation p;
char filename[100]="";
GtkWidget
*MABFCrud=lookup_widget(MABFWidget,"MABFcrud"),
*JJ=lookup_widget(MABFWidget,"MABFSpinButtonJour"),
*MM=lookup_widget(MABFWidget,"MABFSpinButtonMois"),
*AAAA=lookup_widget(MABFWidget,"MABFSpinButtonAnnee"),
*CAT=lookup_widget(MABFWidget,"MABFEntryCategorie"),
*ID=lookup_widget(MABFWidget,"MABFEntryID"),
*RBN=lookup_widget(MABFWidget,"MABFRadioButtonNaturelle"),
*RBA=lookup_widget(MABFWidget,"MABFRadioButtonAgricole"),
*ENG=lookup_widget(MABFWidget,"MABFComboBoxEngrais"),
*CBI=lookup_widget(MABFWidget,"MABFCheckButtonInsecticide"),
*CBF=lookup_widget(MABFWidget,"MABFCheckButtonFongicide"),
*CBH=lookup_widget(MABFWidget,"MABFCheckButtonHerbicide"),
*REC=lookup_widget(MABFWidget,"MABFComboBoxRecolte"),
*MABFImageInsertion=lookup_widget(MABFWidget,"MABFImageInsertion"),
*MABFTreeView=lookup_widget(MABFWidget,"MABFTreeView"),
*MABFDialogSucc=gtk_dialog_new_with_buttons("Felicitations",GTK_WINDOW(MABFCrud),GTK_DIALOG_DESTROY_WITH_PARENT,"OK",GTK_RESPONSE_OK,NULL),
*MABFDialogEchec=gtk_dialog_new_with_buttons("Erreur",GTK_WINDOW(MABFCrud),GTK_DIALOG_DESTROY_WITH_PARENT,"OK",GTK_RESPONSE_OK,NULL),
*MABFLabelSucc=gtk_label_new(""),
*MABFLabelEchec=gtk_label_new("");
gtk_window_set_deletable(GTK_WINDOW(MABFDialogSucc),FALSE);
gtk_window_set_deletable(GTK_WINDOW(MABFDialogEchec),FALSE);
p.Date.Jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(JJ));
p.Date.Mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(MM));
p.Date.Annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(AAAA));
strcpy(p.Categorie,gtk_entry_get_text(GTK_ENTRY(CAT)));
strcpy(p.Identifiant,gtk_entry_get_text(GTK_ENTRY(ID)));
strcpy(p.Engrais,gtk_combo_box_get_active_text(GTK_COMBO_BOX(ENG)));
strcpy(p.Recolte,gtk_combo_box_get_active_text(GTK_COMBO_BOX(REC)));
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(RBN))==TRUE){strcpy(p.Irrigation,"");strcpy(p.Irrigation,"Naturelle");}
else if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(RBA))==TRUE){strcpy(p.Irrigation,"");strcpy(p.Irrigation,"Agricole");}
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(CBI))==TRUE){
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(CBF))==TRUE){
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(CBH))==TRUE){
strcpy(p.Traitement,"");strcpy(p.Traitement,"Insecticide + Fongicide + Herbicide");}
else if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(CBH))==FALSE){
strcpy(p.Traitement,"");strcpy(p.Traitement,"Insecticide + Fongicide");}}
else if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(CBF))==FALSE){
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(CBH))==TRUE){
strcpy(p.Traitement,"");strcpy(p.Traitement,"Insecticide + Herbicide");}
else if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(CBH))==FALSE){
strcpy(p.Traitement,"");strcpy(p.Traitement,"Insecticide");}}}
else if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(CBI))==FALSE){
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(CBF))==TRUE){
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(CBH))==TRUE){
strcpy(p.Traitement,"");strcpy(p.Traitement,"Fongicide + Herbicide");}
else if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(CBH))==FALSE){
strcpy(p.Traitement,"");strcpy(p.Traitement,"Fongicide");}}
else if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(CBF))==FALSE){
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(CBH))==TRUE){
strcpy(p.Traitement,"");strcpy(p.Traitement,"Herbicide");}
else{strcpy(p.Traitement,"");}}}
gtk_container_add(GTK_CONTAINER(GTK_VBOX(gtk_dialog_get_content_area(GTK_DIALOG(MABFDialogSucc)))),MABFLabelSucc);
gtk_widget_set_size_request(MABFDialogSucc,400,200);
gtk_container_add(GTK_CONTAINER(GTK_VBOX(gtk_dialog_get_content_area(GTK_DIALOG(MABFDialogEchec)))),MABFLabelEchec);
gtk_widget_set_size_request(MABFDialogEchec,400,200);
f=fopen(data_photo,"rb");
if(f!=NULL){
fgets(filename,100,f);
strcpy(p.Image,filename);
fclose(f);
remove(data_photo);}
else{strcpy(p.Image,"");}
if((date_valide_plt(p.Date)==1)&&(influence_lunaire(p.Date)!=1)&&(identifiant_existant(data_base,p.Identifiant)!=1)&&(strcmp(p.Categorie,"")!=0)&&(strcmp(p.Identifiant,"")!=0)&&(strcmp(p.Traitement,"")!=0)){
while((strcmp(p.Image,"")==0)||(strcmp(p.Image,default_photo)==0)){
GtkWidget
*MABFDialogAlerte=gtk_dialog_new_with_buttons("Alerte",GTK_WINDOW(MABFCrud),GTK_DIALOG_DESTROY_WITH_PARENT,"OK",GTK_RESPONSE_OK,"Ignore",GTK_RESPONSE_REJECT,NULL),
*MABFLabelAlerte=gtk_label_new("");
gtk_window_set_deletable(GTK_WINDOW(MABFDialogAlerte),FALSE);
gtk_container_add(GTK_CONTAINER(GTK_VBOX(gtk_dialog_get_content_area(GTK_DIALOG(MABFDialogAlerte)))),MABFLabelAlerte);
gtk_widget_set_size_request(MABFDialogAlerte,400,200);
gtk_label_set_markup(GTK_LABEL(MABFLabelAlerte),"<span size='medium'><b>Veuillez ajouter une photo !</b></span>");
gtk_widget_show_all(MABFDialogAlerte);
f=fopen(dialog_color,"rb");
if(f!=NULL){
fread(&col,sizeof(GdkColor),1,f);
gtk_widget_modify_bg(MABFDialogAlerte,GTK_STATE_NORMAL,&col);
fclose(f);}
gint response_a=gtk_dialog_run(GTK_DIALOG(MABFDialogAlerte));
if(response_a==GTK_RESPONSE_REJECT){
strcpy(p.Image,broken_photo);
gtk_widget_destroy(MABFDialogAlerte);}
else if(response_a==GTK_RESPONSE_OK){
strcpy(p.Image,broken_photo);
gtk_widget_destroy(MABFDialogAlerte);
char *filename=on_MABFEventBoxInsertion_button_press_event(MABFWidget,user_data);
if(filename!=NULL){
strcpy(p.Image,filename);
remove(data_photo);}}}
ajouter_plantation(data_base,p);afficher_plantation(data_base,MABFTreeView);
gtk_label_set_markup(GTK_LABEL(MABFLabelSucc),"<span size='medium'><b>Ajout avec succès !</b></span>");
gtk_widget_show_all(MABFDialogSucc);
f=fopen(dialog_color,"rb");
if(f!=NULL){
fread(&col,sizeof(GdkColor),1,f);
gtk_widget_modify_bg(MABFDialogSucc,GTK_STATE_NORMAL,&col);
fclose(f);}
gint response_s=gtk_dialog_run(GTK_DIALOG(MABFDialogSucc));
if(response_s==GTK_RESPONSE_OK){gtk_widget_destroy(MABFDialogSucc);}}
else if((strcmp(p.Categorie,"")==0)||(strcmp(p.Identifiant,"")==0)||(strcmp(p.Traitement,"")==0)){
gtk_label_set_markup(GTK_LABEL(MABFLabelEchec),"<span size='medium'><b>Donnée(s) manquante(s) !</b></span>");
gtk_widget_show_all(MABFDialogEchec);
f=fopen(dialog_color,"rb");
if(f!=NULL){
fread(&col,sizeof(GdkColor),1,f);
gtk_widget_modify_bg(MABFDialogEchec,GTK_STATE_NORMAL,&col);
fclose(f);}
gint response_e=gtk_dialog_run(GTK_DIALOG(MABFDialogEchec));
if(response_e==GTK_RESPONSE_OK){
gtk_widget_destroy(MABFDialogEchec);}}
else if(identifiant_existant(data_base,p.Identifiant)==1){
gtk_label_set_markup(GTK_LABEL(MABFLabelEchec),"<span size='medium'><b>Cet identifiant est déjà utilisé !</b></span>");
gtk_widget_show_all(MABFDialogEchec);
f=fopen(dialog_color,"rb");
if(f!=NULL){
fread(&col,sizeof(GdkColor),1,f);
gtk_widget_modify_bg(MABFDialogEchec,GTK_STATE_NORMAL,&col);
fclose(f);}
gint response_e=gtk_dialog_run(GTK_DIALOG(MABFDialogEchec));
if(response_e==GTK_RESPONSE_OK){
gtk_widget_destroy(MABFDialogEchec);}}
else if(date_valide_plt(p.Date)!=1){
gtk_label_set_markup(GTK_LABEL(MABFLabelEchec),"<span size='medium'><b>Cette date est invalide !</b></span>");
gtk_widget_show_all(MABFDialogEchec);
f=fopen(dialog_color,"rb");
if(f!=NULL){
fread(&col,sizeof(GdkColor),1,f);
gtk_widget_modify_bg(MABFDialogEchec,GTK_STATE_NORMAL,&col);
fclose(f);}
gint response_e=gtk_dialog_run(GTK_DIALOG(MABFDialogEchec));
if(response_e==GTK_RESPONSE_OK){
gtk_widget_destroy(MABFDialogEchec);}}
else if(influence_lunaire(p.Date)==1){
gtk_label_set_markup(GTK_LABEL(MABFLabelEchec),"<span size='medium'><b>Influence lunaire détectée lors de cette date !</b></span>");
gtk_widget_show_all(MABFDialogEchec);
f=fopen(dialog_color,"rb");
if(f!=NULL){
fread(&col,sizeof(GdkColor),1,f);
gtk_widget_modify_bg(MABFDialogEchec,GTK_STATE_NORMAL,&col);
fclose(f);}
gint response_e=gtk_dialog_run(GTK_DIALOG(MABFDialogEchec));
if(response_e==GTK_RESPONSE_OK){
gtk_widget_destroy(MABFDialogEchec);}}
gtk_spin_button_set_value(GTK_SPIN_BUTTON(JJ),1);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(MM),1);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(AAAA),2020);
gtk_entry_set_text(GTK_ENTRY(CAT),"");
gtk_entry_set_text(GTK_ENTRY(ID),"");
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(RBN),TRUE);
gtk_combo_box_set_active(GTK_COMBO_BOX(ENG),0);
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(CBI),FALSE);
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(CBF),FALSE);
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(CBH),FALSE);
gtk_combo_box_set_active(GTK_COMBO_BOX(REC),0);
gtk_image_set_from_file(GTK_IMAGE(MABFImageInsertion),default_photo);}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void on_MABFButtonModifier_clicked(GtkWidget *MABFWidget,gpointer user_data){
FILE *f=NULL;
GdkColor col;
plantation c,
*p=(plantation*)malloc(sizeof(plantation));
char
jour[20]="",
mois[20]="",
annee[20]="",
date_cible[50]="",
date_plantation[50]="",
filename[100]="";
int
EXIT=0;
GtkWidget
*MABFCrud=lookup_widget(MABFWidget,"MABFcrud"),
*JJ=lookup_widget(MABFWidget,"MABFSpinButtonJour"),
*MM=lookup_widget(MABFWidget,"MABFSpinButtonMois"),
*AAAA=lookup_widget(MABFWidget,"MABFSpinButtonAnnee"),
*CAT=lookup_widget(MABFWidget,"MABFEntryCategorie"),
*ID=lookup_widget(MABFWidget,"MABFEntryID"),
*RBN=lookup_widget(MABFWidget,"MABFRadioButtonNaturelle"),
*RBA=lookup_widget(MABFWidget,"MABFRadioButtonAgricole"),
*ENG=lookup_widget(MABFWidget,"MABFComboBoxEngrais"),
*CBI=lookup_widget(MABFWidget,"MABFCheckButtonInsecticide"),
*CBF=lookup_widget(MABFWidget,"MABFCheckButtonFongicide"),
*CBH=lookup_widget(MABFWidget,"MABFCheckButtonHerbicide"),
*REC=lookup_widget(MABFWidget,"MABFComboBoxRecolte"),
*MABFImageInsertion=lookup_widget(MABFWidget,"MABFImageInsertion"),
*MABFTreeView=lookup_widget(MABFWidget,"MABFTreeView"),
*MABFDialogSucc=gtk_dialog_new_with_buttons("Felicitations",GTK_WINDOW(MABFCrud),GTK_DIALOG_DESTROY_WITH_PARENT,"OK",GTK_RESPONSE_OK,NULL),
*MABFDialogEchec=gtk_dialog_new_with_buttons("Erreur",GTK_WINDOW(MABFCrud),GTK_DIALOG_DESTROY_WITH_PARENT,"OK",GTK_RESPONSE_OK,NULL),
*MABFLabelSucc=gtk_label_new(""),
*MABFLabelEchec=gtk_label_new("");
gtk_window_set_deletable(GTK_WINDOW(MABFDialogSucc),FALSE);
gtk_window_set_deletable(GTK_WINDOW(MABFDialogEchec),FALSE);
p->Date.Jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(JJ));
p->Date.Mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(MM));
p->Date.Annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(AAAA));
strcpy(p->Categorie,gtk_entry_get_text(GTK_ENTRY(CAT)));
strcpy(p->Identifiant,gtk_entry_get_text(GTK_ENTRY(ID)));
strcpy(p->Engrais,gtk_combo_box_get_active_text(GTK_COMBO_BOX(ENG)));
strcpy(p->Recolte,gtk_combo_box_get_active_text(GTK_COMBO_BOX(REC)));
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(RBN))==TRUE){
strcpy(p->Irrigation,"");
strcpy(p->Irrigation,"Naturelle");}
else if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(RBA))==TRUE){
strcpy(p->Irrigation,"");
strcpy(p->Irrigation,"Agricole");}
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(CBI))==TRUE){
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(CBF))==TRUE){
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(CBH))==TRUE){
strcpy(p->Traitement,"");
strcpy(p->Traitement,"Insecticide + Fongicide + Herbicide");}
else if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(CBH))==FALSE){
strcpy(p->Traitement,"");
strcpy(p->Traitement,"Insecticide + Fongicide");}}
else if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(CBF))==FALSE){
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(CBH))==TRUE){
strcpy(p->Traitement,"");
strcpy(p->Traitement,"Insecticide + Herbicide");}
else if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(CBH))==FALSE){
strcpy(p->Traitement,"");
strcpy(p->Traitement,"Insecticide");}}}
else if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(CBI))==FALSE){
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(CBF))==TRUE){
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(CBH))==TRUE){
strcpy(p->Traitement,"");
strcpy(p->Traitement,"Fongicide + Herbicide");}
else if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(CBH))==FALSE){
strcpy(p->Traitement,"");
strcpy(p->Traitement,"Fongicide");}}
else if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(CBF))==FALSE){
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(CBH))==TRUE){
strcpy(p->Traitement,"");
strcpy(p->Traitement,"Herbicide");}
else{
strcpy(p->Traitement,"");}}}
gtk_container_add(GTK_CONTAINER(GTK_VBOX(gtk_dialog_get_content_area(GTK_DIALOG(MABFDialogSucc)))),MABFLabelSucc);
gtk_widget_set_size_request(MABFDialogSucc,400,200);
gtk_container_add(GTK_CONTAINER(GTK_VBOX(gtk_dialog_get_content_area(GTK_DIALOG(MABFDialogEchec)))),MABFLabelEchec);
gtk_widget_set_size_request(MABFDialogEchec,400,200);
sprintf(jour,"%d",p->Date.Jour);
strcat(date_cible,jour);
strcat(date_cible,"/");
sprintf(mois,"%d",p->Date.Mois);
strcat(date_cible,mois);
strcat(date_cible,"/");
sprintf(annee,"%d",p->Date.Annee);
strcat(date_cible,annee);
if((date_valide_plt(p->Date)==1)&&(influence_lunaire(p->Date)!=1)&&(strcmp(p->Categorie,"")!=0)&&(identifiant_existant(data_base,p->Identifiant)==1)&&(strcmp(p->Traitement,"")!=0)){
f=fopen(data_base,"rb");
if(f!=NULL){
while((!feof(f))&&(EXIT==0)){
fread(&c,sizeof(plantation),1,f);
if(strcmp(p->Identifiant,c.Identifiant)==0){
EXIT=1;
strcpy(p->Image,c.Image);}}
fclose(f);}
f=fopen(data_photo,"rb");
if(f!=NULL){
fgets(filename,100,f);
strcpy(p->Image,filename);
fclose(f);
remove(data_photo);}
strcpy(date_plantation,"");
sprintf(jour,"%d",c.Date.Jour);
strcat(date_plantation,jour);
strcat(date_plantation,"/");
sprintf(mois,"%d",c.Date.Mois);
strcat(date_plantation,mois);
strcat(date_plantation,"/");
sprintf(annee,"%d",c.Date.Annee);
strcat(date_plantation,annee);
if((strcmp(date_cible,date_plantation)==0)&&(strcmp(p->Categorie,c.Categorie)==0)&&(strcmp(p->Irrigation,c.Irrigation)==0)&&(strcmp(p->Engrais,c.Engrais)==0)&&(strcmp(p->Traitement,c.Traitement)==0)&&(strcmp(p->Recolte,c.Recolte)==0)&&(strcmp(p->Image,c.Image)==0)){
GtkWidget
*MABFDialogAlerte=gtk_dialog_new_with_buttons("Alerte",GTK_WINDOW(MABFCrud),GTK_DIALOG_DESTROY_WITH_PARENT,"OK",GTK_RESPONSE_OK,NULL),
*MABFLabelAlerte=gtk_label_new("");
gtk_window_set_deletable(GTK_WINDOW(MABFDialogAlerte),FALSE);
gtk_container_add(GTK_CONTAINER(GTK_VBOX(gtk_dialog_get_content_area(GTK_DIALOG(MABFDialogAlerte)))),MABFLabelAlerte);
gtk_widget_set_size_request(MABFDialogAlerte,400,200);
gtk_label_set_markup(GTK_LABEL(MABFLabelAlerte),"<span size='medium'><b>Rien à faire !</b></span>");
gtk_widget_show_all(MABFDialogAlerte);
f=fopen(dialog_color,"rb");
if(f!=NULL){
fread(&col,sizeof(GdkColor),1,f);
gtk_widget_modify_bg(MABFDialogAlerte,GTK_STATE_NORMAL,&col);
fclose(f);}
gint response_a=gtk_dialog_run(GTK_DIALOG(MABFDialogAlerte));
if(response_a==GTK_RESPONSE_OK){
gtk_widget_destroy(MABFDialogAlerte);}}
else if((strcmp(date_cible,date_plantation)!=0)||(strcmp(p->Categorie,c.Categorie)!=0)||(strcmp(p->Irrigation,c.Irrigation)!=0)||(strcmp(p->Engrais,c.Engrais)!=0)||(strcmp(p->Traitement,c.Traitement)!=0)||(strcmp(p->Recolte,c.Recolte)!=0)||(strcmp(p->Image,c.Image)!=0)){
while(strcmp(p->Image,default_photo)==0){
GtkWidget
*MABFDialogAlerte=gtk_dialog_new_with_buttons("Alerte",GTK_WINDOW(MABFCrud),GTK_DIALOG_DESTROY_WITH_PARENT,"OK",GTK_RESPONSE_OK,"Ignore",GTK_RESPONSE_REJECT,NULL),
*MABFLabelAlerte=gtk_label_new("");
gtk_window_set_deletable(GTK_WINDOW(MABFDialogAlerte),FALSE);
gtk_container_add(GTK_CONTAINER(GTK_VBOX(gtk_dialog_get_content_area(GTK_DIALOG(MABFDialogAlerte)))),MABFLabelAlerte);
gtk_widget_set_size_request(MABFDialogAlerte,400,200);
gtk_label_set_markup(GTK_LABEL(MABFLabelAlerte),"<span size='medium'><b>Veuillez ajouter une photo !</b></span>");
gtk_widget_show_all(MABFDialogAlerte);
f=fopen(dialog_color,"rb");
if(f!=NULL){
fread(&col,sizeof(GdkColor),1,f);
gtk_widget_modify_bg(MABFDialogAlerte,GTK_STATE_NORMAL,&col);
fclose(f);}
gint response_a=gtk_dialog_run(GTK_DIALOG(MABFDialogAlerte));
if(response_a==GTK_RESPONSE_REJECT){
strcpy(p->Image,broken_photo);
gtk_widget_destroy(MABFDialogAlerte);}
else if(response_a==GTK_RESPONSE_OK){
strcpy(p->Image,broken_photo);
gtk_widget_destroy(MABFDialogAlerte);
char *filename=on_MABFEventBoxInsertion_button_press_event(MABFCrud,user_data);
if(filename!=NULL){
strcpy(p->Image,filename);
remove(data_photo);}}}
modifier_plantation(data_base,p);afficher_plantation(data_base,MABFTreeView);
gtk_label_set_markup(GTK_LABEL(MABFLabelSucc),"<span size='medium'><b>Modif avec succès !</b></span>");
gtk_widget_show_all(MABFDialogSucc);
f=fopen(dialog_color,"rb");
if(f!=NULL){
fread(&col,sizeof(GdkColor),1,f);
gtk_widget_modify_bg(MABFDialogSucc,GTK_STATE_NORMAL,&col);
fclose(f);}
gint response_s=gtk_dialog_run(GTK_DIALOG(MABFDialogSucc));
if(response_s==GTK_RESPONSE_OK){
gtk_widget_destroy(MABFDialogSucc);}}}
else if((strcmp(p->Categorie,"")==0)||(strcmp(p->Identifiant,"")==0)||(strcmp(p->Traitement,"")==0)){
gtk_label_set_markup(GTK_LABEL(MABFLabelEchec),"<span size='medium'><b>Donnée(s) manquante(s) !</b></span>");
gtk_widget_show_all(MABFDialogEchec);
f=fopen(dialog_color,"rb");
if(f!=NULL){
fread(&col,sizeof(GdkColor),1,f);
gtk_widget_modify_bg(MABFDialogEchec,GTK_STATE_NORMAL,&col);
fclose(f);}
gint response_e=gtk_dialog_run(GTK_DIALOG(MABFDialogEchec));
if(response_e==GTK_RESPONSE_OK){
gtk_widget_destroy(MABFDialogEchec);}}
else if(identifiant_existant(data_base,p->Identifiant)!=1){
gtk_label_set_markup(GTK_LABEL(MABFLabelEchec),"<span size='medium'><b>Aucune correspondance !</b></span>");
gtk_widget_show_all(MABFDialogEchec);
f=fopen(dialog_color,"rb");
if(f!=NULL){
fread(&col,sizeof(GdkColor),1,f);
gtk_widget_modify_bg(MABFDialogEchec,GTK_STATE_NORMAL,&col);
fclose(f);}
gint response_e=gtk_dialog_run(GTK_DIALOG(MABFDialogEchec));
if(response_e==GTK_RESPONSE_OK){
gtk_widget_destroy(MABFDialogEchec);}}
else if(date_valide_plt(p->Date)!=1){
gtk_label_set_markup(GTK_LABEL(MABFLabelEchec),"<span size='medium'><b>Cette date est invalide !</b></span>");
gtk_widget_show_all(MABFDialogEchec);
f=fopen(dialog_color,"rb");
if(f!=NULL){
fread(&col,sizeof(GdkColor),1,f);
gtk_widget_modify_bg(MABFDialogEchec,GTK_STATE_NORMAL,&col);
fclose(f);}
gint response_e=gtk_dialog_run(GTK_DIALOG(MABFDialogEchec));
if(response_e==GTK_RESPONSE_OK){
gtk_widget_destroy(MABFDialogEchec);}}
else if(influence_lunaire(p->Date)==1){
gtk_label_set_markup(GTK_LABEL(MABFLabelEchec),"<span size='medium'><b>Influence lunaire détectée lors de cette date !</b></span>");
gtk_widget_show_all(MABFDialogEchec);
f=fopen(dialog_color,"rb");
if(f!=NULL){
fread(&col,sizeof(GdkColor),1,f);
gtk_widget_modify_bg(MABFDialogEchec,GTK_STATE_NORMAL,&col);
fclose(f);}
gint response_e=gtk_dialog_run(GTK_DIALOG(MABFDialogEchec));
if(response_e==GTK_RESPONSE_OK){
gtk_widget_destroy(MABFDialogEchec);}}
gtk_spin_button_set_value(GTK_SPIN_BUTTON(JJ),1);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(MM),1);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(AAAA),2020);
gtk_entry_set_text(GTK_ENTRY(CAT),"");
gtk_entry_set_text(GTK_ENTRY(ID),"");
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(RBN),TRUE);
gtk_combo_box_set_active(GTK_COMBO_BOX(ENG),0);
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(CBI),FALSE);
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(CBF),FALSE);
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(CBH),FALSE);
gtk_combo_box_set_active(GTK_COMBO_BOX(REC),0);
gtk_image_set_from_file(GTK_IMAGE(MABFImageInsertion),default_photo);
free(p);}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void on_MABFButtonSupprimer_clicked(GtkWidget *MABFWidget,gpointer user_data){
FILE *f=NULL;
GdkColor col;
char Identifiant[20]="";
GtkWidget
*MABFCrud=lookup_widget(MABFWidget,"MABFcrud"),
*JJ=lookup_widget(MABFWidget,"MABFSpinButtonJour"),
*MM=lookup_widget(MABFWidget,"MABFSpinButtonMois"),
*AAAA=lookup_widget(MABFWidget,"MABFSpinButtonAnnee"),
*CAT=lookup_widget(MABFWidget,"MABFEntryCategorie"),
*ID=lookup_widget(MABFWidget,"MABFEntryID"),
*RBN=lookup_widget(MABFWidget,"MABFRadioButtonNaturelle"),
*RBA=lookup_widget(MABFWidget,"MABFRadioButtonAgricole"),
*ENG=lookup_widget(MABFWidget,"MABFComboBoxEngrais"),
*CBI=lookup_widget(MABFWidget,"MABFCheckButtonInsecticide"),
*CBF=lookup_widget(MABFWidget,"MABFCheckButtonFongicide"),
*CBH=lookup_widget(MABFWidget,"MABFCheckButtonHerbicide"),
*REC=lookup_widget(MABFWidget,"MABFComboBoxRecolte"),
*MABFImageInsertion=lookup_widget(MABFWidget,"MABFImageInsertion"),
*MABFTreeView=lookup_widget(MABFWidget,"MABFTreeView"),
*MABFDialogSucc=gtk_dialog_new_with_buttons("Felicitations",GTK_WINDOW(MABFCrud),GTK_DIALOG_DESTROY_WITH_PARENT,"OK",GTK_RESPONSE_OK,NULL),
*MABFDialogEchec=gtk_dialog_new_with_buttons("Erreur",GTK_WINDOW(MABFCrud),GTK_DIALOG_DESTROY_WITH_PARENT,"OK",GTK_RESPONSE_OK,NULL),
*MABFLabelSucc=gtk_label_new(""),
*MABFLabelEchec=gtk_label_new("");
gtk_window_set_deletable(GTK_WINDOW(MABFDialogSucc),FALSE);
gtk_window_set_deletable(GTK_WINDOW(MABFDialogEchec),FALSE);
strcpy(Identifiant,gtk_entry_get_text(GTK_ENTRY(ID)));
gtk_container_add(GTK_CONTAINER(GTK_VBOX(gtk_dialog_get_content_area(GTK_DIALOG(MABFDialogSucc)))),MABFLabelSucc);
gtk_widget_set_size_request(MABFDialogSucc,400,200);
gtk_container_add(GTK_CONTAINER(GTK_VBOX(gtk_dialog_get_content_area(GTK_DIALOG(MABFDialogEchec)))),MABFLabelEchec);
gtk_widget_set_size_request(MABFDialogEchec,400,200);
if(identifiant_existant(data_base,Identifiant)==1){
GtkWidget
*MABFDialogAlerte=gtk_dialog_new_with_buttons("Alerte",GTK_WINDOW(MABFCrud),GTK_DIALOG_DESTROY_WITH_PARENT,"OK",GTK_RESPONSE_OK,"Cancel",GTK_RESPONSE_CANCEL,NULL),
*MABFLabelAlerte=gtk_label_new("");
gtk_window_set_deletable(GTK_WINDOW(MABFDialogAlerte),FALSE);
gtk_container_add(GTK_CONTAINER(GTK_VBOX(gtk_dialog_get_content_area(GTK_DIALOG(MABFDialogAlerte)))),MABFLabelAlerte);
gtk_widget_set_size_request(MABFDialogAlerte,400,200);
gtk_label_set_markup(GTK_LABEL(MABFLabelAlerte),"<span size='medium'><b>Vous êtes en train de supprimer cette plantation !\n\n				   Continuer ?</b></span>");
gtk_widget_show_all(MABFDialogAlerte);
f=fopen(dialog_color,"rb");
if(f!=NULL){
fread(&col,sizeof(GdkColor),1,f);
gtk_widget_modify_bg(MABFDialogAlerte,GTK_STATE_NORMAL,&col);
fclose(f);}
gint response_a=gtk_dialog_run(GTK_DIALOG(MABFDialogAlerte));
if(response_a==GTK_RESPONSE_OK){
gtk_widget_destroy(MABFDialogAlerte);
supprimer_plantation(data_base,Identifiant);afficher_plantation(data_base,MABFTreeView);
gtk_label_set_markup(GTK_LABEL(MABFLabelSucc),"<span size='medium'><b>Suppr avec succès !</b></span>");
gtk_widget_show_all(MABFDialogSucc);
f=fopen(dialog_color,"rb");
if(f!=NULL){
fread(&col,sizeof(GdkColor),1,f);
gtk_widget_modify_bg(MABFDialogSucc,GTK_STATE_NORMAL,&col);
fclose(f);}
gint response_s=gtk_dialog_run(GTK_DIALOG(MABFDialogSucc));
if(response_s==GTK_RESPONSE_OK){
gtk_widget_destroy(MABFDialogSucc);}}
else if(response_a==GTK_RESPONSE_CANCEL){
gtk_widget_destroy(MABFDialogAlerte);
GtkWidget
*MABFDialogAlerte=gtk_dialog_new_with_buttons("Alerte",GTK_WINDOW(MABFCrud),GTK_DIALOG_DESTROY_WITH_PARENT,"OK",GTK_RESPONSE_OK,NULL),
*MABFLabelAlerte=gtk_label_new("");
gtk_window_set_deletable(GTK_WINDOW(MABFDialogAlerte),FALSE);
gtk_container_add(GTK_CONTAINER(GTK_VBOX(gtk_dialog_get_content_area(GTK_DIALOG(MABFDialogAlerte)))),MABFLabelAlerte);
gtk_widget_set_size_request(MABFDialogAlerte,400,200);
gtk_label_set_markup(GTK_LABEL(MABFLabelAlerte),"<span size='medium'><b>Supp annulée !</b></span>");
gtk_widget_show_all(MABFDialogAlerte);
f=fopen(dialog_color,"rb");
if(f!=NULL){
fread(&col,sizeof(GdkColor),1,f);
gtk_widget_modify_bg(MABFDialogAlerte,GTK_STATE_NORMAL,&col);
fclose(f);}
gint response_a=gtk_dialog_run(GTK_DIALOG(MABFDialogAlerte));
if(response_a==GTK_RESPONSE_OK){
gtk_widget_destroy(MABFDialogAlerte);}}}
else if(strcmp(Identifiant,"")==0){
gtk_label_set_markup(GTK_LABEL(MABFLabelEchec),"<span size='medium'><b>Veuillez fournir un identifiant !</b></span>");
gtk_widget_show_all(MABFDialogEchec);
f=fopen(dialog_color,"rb");
if(f!=NULL){
fread(&col,sizeof(GdkColor),1,f);
gtk_widget_modify_bg(MABFDialogEchec,GTK_STATE_NORMAL,&col);
fclose(f);}
gint response_e=gtk_dialog_run(GTK_DIALOG(MABFDialogEchec));
if(response_e==GTK_RESPONSE_OK){
gtk_widget_destroy(MABFDialogEchec);}}
else if(identifiant_existant(data_base,Identifiant)!=1){
gtk_label_set_markup(GTK_LABEL(MABFLabelEchec),"<span size='medium'><b>Aucune correspondance !</b></span>");
gtk_widget_show_all(MABFDialogEchec);
f=fopen(dialog_color,"rb");
if(f!=NULL){
fread(&col,sizeof(GdkColor),1,f);
gtk_widget_modify_bg(MABFDialogEchec,GTK_STATE_NORMAL,&col);
fclose(f);}
gint response_e=gtk_dialog_run(GTK_DIALOG(MABFDialogEchec));
if(response_e==GTK_RESPONSE_OK){
gtk_widget_destroy(MABFDialogEchec);}}
gtk_spin_button_set_value(GTK_SPIN_BUTTON(JJ),1);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(JJ),1);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(MM),1);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(AAAA),2020);
gtk_entry_set_text(GTK_ENTRY(CAT),"");
gtk_entry_set_text(GTK_ENTRY(ID),"");
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(RBN),TRUE);
gtk_combo_box_set_active(GTK_COMBO_BOX(ENG),0);
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(CBI),FALSE);
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(CBF),FALSE);
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(CBH),FALSE);
gtk_combo_box_set_active(GTK_COMBO_BOX(REC),0);
gtk_image_set_from_file(GTK_IMAGE(MABFImageInsertion),default_photo);}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void on_MABFButtonChercher_clicked(GtkWidget *MABFWidget,gpointer user_data){
FILE *f=NULL;
GdkColor col;
char Identifiant[20]="";
GtkWidget
*MABFCrud=lookup_widget(MABFWidget,"MABFcrud"),
*JJ=lookup_widget(MABFWidget,"MABFSpinButtonJour"),
*MM=lookup_widget(MABFWidget,"MABFSpinButtonMois"),
*AAAA=lookup_widget(MABFWidget,"MABFSpinButtonAnnee"),
*CAT=lookup_widget(MABFWidget,"MABFEntryCategorie"),
*ID=lookup_widget(MABFWidget,"MABFEntryID"),
*RBN=lookup_widget(MABFWidget,"MABFRadioButtonNaturelle"),
*RBA=lookup_widget(MABFWidget,"MABFRadioButtonAgricole"),
*ENG=lookup_widget(MABFWidget,"MABFComboBoxEngrais"),
*CBI=lookup_widget(MABFWidget,"MABFCheckButtonInsecticide"),
*CBF=lookup_widget(MABFWidget,"MABFCheckButtonFongicide"),
*CBH=lookup_widget(MABFWidget,"MABFCheckButtonHerbicide"),
*REC=lookup_widget(MABFWidget,"MABFComboBoxRecolte"),
*MABFImageInsertion=lookup_widget(MABFWidget,"MABFImageInsertion"),
*MABFTreeView=lookup_widget(MABFWidget,"MABFTreeView"),
*MABFDialogSucc=gtk_dialog_new_with_buttons("Felicitations",GTK_WINDOW(MABFCrud),GTK_DIALOG_DESTROY_WITH_PARENT,"OK",GTK_RESPONSE_OK,NULL),
*MABFDialogEchec=gtk_dialog_new_with_buttons("Erreur",GTK_WINDOW(MABFCrud),GTK_DIALOG_DESTROY_WITH_PARENT,"OK",GTK_RESPONSE_OK,NULL),
*MABFLabelSucc=gtk_label_new(""),
*MABFLabelEchec=gtk_label_new("");
gtk_window_set_deletable(GTK_WINDOW(MABFDialogSucc),FALSE);
gtk_window_set_deletable(GTK_WINDOW(MABFDialogEchec),FALSE);
strcpy(Identifiant,gtk_entry_get_text(GTK_ENTRY(ID)));
gtk_container_add(GTK_CONTAINER(GTK_VBOX(gtk_dialog_get_content_area(GTK_DIALOG(MABFDialogSucc)))),MABFLabelSucc);
gtk_widget_set_size_request(MABFDialogSucc,400,200);
gtk_container_add(GTK_CONTAINER(GTK_VBOX(gtk_dialog_get_content_area(GTK_DIALOG(MABFDialogEchec)))),MABFLabelEchec);
gtk_widget_set_size_request(MABFDialogEchec,400,200);
if(identifiant_existant(data_base,Identifiant)==1){
chercher_plantation(data_base,Identifiant,MABFTreeView,MABFImageInsertion);
gtk_label_set_markup(GTK_LABEL(MABFLabelSucc),"<span size='medium'><b>Plantation trouvée !</b></span>");
gtk_widget_show_all(MABFDialogSucc);
f=fopen(dialog_color,"rb");
if(f!=NULL){
fread(&col,sizeof(GdkColor),1,f);
gtk_widget_modify_bg(MABFDialogSucc,GTK_STATE_NORMAL,&col);
fclose(f);}
gint response_s=gtk_dialog_run(GTK_DIALOG(MABFDialogSucc));
if(response_s==GTK_RESPONSE_OK){gtk_widget_destroy(MABFDialogSucc);}}
else{
if(strcmp(Identifiant,"")==0){
gtk_label_set_markup(GTK_LABEL(MABFLabelEchec),"<span size='medium'><b>Veuillez fournir un identifiant !</b></span>");
gtk_widget_show_all(MABFDialogEchec);
f=fopen(dialog_color,"rb");
if(f!=NULL){
fread(&col,sizeof(GdkColor),1,f);
gtk_widget_modify_bg(MABFDialogEchec,GTK_STATE_NORMAL,&col);
fclose(f);}
gint response_e=gtk_dialog_run(GTK_DIALOG(MABFDialogEchec));
if(response_e==GTK_RESPONSE_OK){gtk_widget_destroy(MABFDialogEchec);}}
else if((strcmp(Identifiant,"")!=0)&&(identifiant_existant(data_base,Identifiant)!=1)){
gtk_label_set_markup(GTK_LABEL(MABFLabelEchec),"<span size='medium'><b>Aucune correspondance !</b></span>");
gtk_widget_show_all(MABFDialogEchec);
f=fopen(dialog_color,"rb");
if(f!=NULL){
fread(&col,sizeof(GdkColor),1,f);
gtk_widget_modify_bg(MABFDialogEchec,GTK_STATE_NORMAL,&col);
fclose(f);}
gint response_e=gtk_dialog_run(GTK_DIALOG(MABFDialogEchec));
if(response_e==GTK_RESPONSE_OK){gtk_widget_destroy(MABFDialogEchec);}}
afficher_plantation(data_base,MABFTreeView);
gtk_image_set_from_file(GTK_IMAGE(MABFImageInsertion),default_photo);}
gtk_spin_button_set_value(GTK_SPIN_BUTTON(JJ),1);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(MM),1);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(AAAA),2020);
gtk_entry_set_text(GTK_ENTRY(CAT),"");
gtk_entry_set_text(GTK_ENTRY(ID),"");
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(RBN),TRUE);
gtk_combo_box_set_active(GTK_COMBO_BOX(ENG),0);
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(CBI),FALSE);
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(CBF),FALSE);
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(CBH),FALSE);
gtk_combo_box_set_active(GTK_COMBO_BOX(REC),0);}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void on_MABFTreeView_row_activated(GtkWidget *MABFWidget,gpointer user_data){
FILE *f=NULL;
plantation p;
GtkTreeIter iter;
GtkTreeModel *model;
gchar
*Date,
*Categorie,
*Identifiant,
*Irrigation,
*Engrais,
*Traitement,
*Recolte;
int
Jour=0,
Mois=0,
Annee=0;
GtkWidget
*JJ=lookup_widget(MABFWidget,"MABFSpinButtonJour"),
*MM=lookup_widget(MABFWidget,"MABFSpinButtonMois"),
*AAAA=lookup_widget(MABFWidget,"MABFSpinButtonAnnee"),
*CAT=lookup_widget(MABFWidget,"MABFEntryCategorie"),
*ID=lookup_widget(MABFWidget,"MABFEntryID"),
*RBN=lookup_widget(MABFWidget,"MABFRadioButtonNaturelle"),
*RBA=lookup_widget(MABFWidget,"MABFRadioButtonAgricole"),
*ENG=lookup_widget(MABFWidget,"MABFComboBoxEngrais"),
*CBI=lookup_widget(MABFWidget,"MABFCheckButtonInsecticide"),
*CBF=lookup_widget(MABFWidget,"MABFCheckButtonFongicide"),
*CBH=lookup_widget(MABFWidget,"MABFCheckButtonHerbicide"),
*REC=lookup_widget(MABFWidget,"MABFComboBoxRecolte"),
*MABFImageInsertion=lookup_widget(MABFWidget,"MABFImageInsertion"),
*MABFTreeView=lookup_widget(MABFWidget,"MABFTreeView");
GtkTreeSelection
*selection=gtk_tree_view_get_selection(GTK_TREE_VIEW(MABFTreeView));
if(gtk_tree_selection_get_selected(selection,&model,&iter)){
gtk_tree_model_get(model,&iter,0,&Date,1,&Categorie,2,&Identifiant,3,&Irrigation,4,&Engrais,5,&Traitement,6,&Recolte,-1);
sscanf(Date,"%d/%d/%d",&Jour,&Mois,&Annee);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(JJ),Jour);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(MM),Mois);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(AAAA),Annee);
gtk_entry_set_text(GTK_ENTRY(CAT),Categorie);
gtk_entry_set_text(GTK_ENTRY(ID),Identifiant);
if(strcmp(Irrigation,"Naturelle")==0){
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(RBN),TRUE);}
else if(strcmp(Irrigation,"Agricole")==0){
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(RBA),TRUE);}
if(strcmp(Engrais,"00 KG")==0){gtk_combo_box_set_active(GTK_COMBO_BOX(ENG),0);}
else if(strcmp(Engrais,"01 KG")==0){gtk_combo_box_set_active(GTK_COMBO_BOX(ENG),1);}
else if(strcmp(Engrais,"02 KG")==0){gtk_combo_box_set_active(GTK_COMBO_BOX(ENG),2);}
else if(strcmp(Engrais,"03 KG")==0){gtk_combo_box_set_active(GTK_COMBO_BOX(ENG),3);}
else if(strcmp(Engrais,"04 KG")==0){gtk_combo_box_set_active(GTK_COMBO_BOX(ENG),4);}
else if(strcmp(Engrais,"05 KG")==0){gtk_combo_box_set_active(GTK_COMBO_BOX(ENG),5);}
else if(strcmp(Engrais,"06 KG")==0){gtk_combo_box_set_active(GTK_COMBO_BOX(ENG),6);}
else if(strcmp(Engrais,"07 KG")==0){gtk_combo_box_set_active(GTK_COMBO_BOX(ENG),7);}
else if(strcmp(Engrais,"08 KG")==0){gtk_combo_box_set_active(GTK_COMBO_BOX(ENG),8);}
else if(strcmp(Engrais,"09 KG")==0){gtk_combo_box_set_active(GTK_COMBO_BOX(ENG),9);}
else if(strcmp(Engrais,"10 KG")==0){gtk_combo_box_set_active(GTK_COMBO_BOX(ENG),10);}
else if(strcmp(Engrais,"11 KG")==0){gtk_combo_box_set_active(GTK_COMBO_BOX(ENG),11);}
else if(strcmp(Engrais,"12 KG")==0){gtk_combo_box_set_active(GTK_COMBO_BOX(ENG),12);}
else if(strcmp(Engrais,"13 KG")==0){gtk_combo_box_set_active(GTK_COMBO_BOX(ENG),13);}
else if(strcmp(Engrais,"14 KG")==0){gtk_combo_box_set_active(GTK_COMBO_BOX(ENG),14);}
else if(strcmp(Engrais,"15 KG")==0){gtk_combo_box_set_active(GTK_COMBO_BOX(ENG),15);}
else if(strcmp(Engrais,"16 KG")==0){gtk_combo_box_set_active(GTK_COMBO_BOX(ENG),16);}
else if(strcmp(Engrais,"17 KG")==0){gtk_combo_box_set_active(GTK_COMBO_BOX(ENG),17);}
else if(strcmp(Engrais,"18 KG")==0){gtk_combo_box_set_active(GTK_COMBO_BOX(ENG),18);}
else if(strcmp(Engrais,"19 KG")==0){gtk_combo_box_set_active(GTK_COMBO_BOX(ENG),19);}
else if(strcmp(Engrais,"20 KG")==0){gtk_combo_box_set_active(GTK_COMBO_BOX(ENG),20);}
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(CBI),FALSE);
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(CBF),FALSE);
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(CBH),FALSE);
if(strcmp(Traitement,"Insecticide")==0){gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(CBI),TRUE);}
else if(strcmp(Traitement,"Fongicide")==0){gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(CBF),TRUE);}
else if(strcmp(Traitement,"Herbicide")==0){
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(CBH),TRUE);}
else if(strcmp(Traitement,"Insecticide + Fongicide")==0){
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(CBI),TRUE);
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(CBF),TRUE);}
else if(strcmp(Traitement,"Insecticide + Herbicide")==0){
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(CBI),TRUE);
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(CBH),TRUE);}
else if(strcmp(Traitement,"Fongicide + Herbicide")==0){
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(CBF),TRUE);
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(CBH),TRUE);}
else if(strcmp(Traitement,"Insecticide + Fongicide + Herbicide")==0){
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(CBI),TRUE);
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(CBF),TRUE);
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(CBH),TRUE);}
if(strcmp(Recolte,"00 KG")==0){gtk_combo_box_set_active(GTK_COMBO_BOX(REC),0);}
else if(strcmp(Recolte,"01 KG")==0){gtk_combo_box_set_active(GTK_COMBO_BOX(REC),1);}
else if(strcmp(Recolte,"02 KG")==0){gtk_combo_box_set_active(GTK_COMBO_BOX(REC),2);}
else if(strcmp(Recolte,"03 KG")==0){gtk_combo_box_set_active(GTK_COMBO_BOX(REC),3);}
else if(strcmp(Recolte,"04 KG")==0){gtk_combo_box_set_active(GTK_COMBO_BOX(REC),4);}
else if(strcmp(Recolte,"05 KG")==0){gtk_combo_box_set_active(GTK_COMBO_BOX(REC),5);}
else if(strcmp(Recolte,"06 KG")==0){gtk_combo_box_set_active(GTK_COMBO_BOX(REC),6);}
else if(strcmp(Recolte,"07 KG")==0){gtk_combo_box_set_active(GTK_COMBO_BOX(REC),7);}
else if(strcmp(Recolte,"08 KG")==0){gtk_combo_box_set_active(GTK_COMBO_BOX(REC),8);}
else if(strcmp(Recolte,"09 KG")==0){gtk_combo_box_set_active(GTK_COMBO_BOX(REC),9);}
else if(strcmp(Recolte,"10 KG")==0){gtk_combo_box_set_active(GTK_COMBO_BOX(REC),10);}
else if(strcmp(Recolte,"11 KG")==0){gtk_combo_box_set_active(GTK_COMBO_BOX(REC),11);}
else if(strcmp(Recolte,"12 KG")==0){gtk_combo_box_set_active(GTK_COMBO_BOX(REC),12);}
else if(strcmp(Recolte,"13 KG")==0){gtk_combo_box_set_active(GTK_COMBO_BOX(REC),13);}
else if(strcmp(Recolte,"14 KG")==0){gtk_combo_box_set_active(GTK_COMBO_BOX(REC),14);}
else if(strcmp(Recolte,"15 KG")==0){gtk_combo_box_set_active(GTK_COMBO_BOX(REC),15);}
else if(strcmp(Recolte,"16 KG")==0){gtk_combo_box_set_active(GTK_COMBO_BOX(REC),16);}
else if(strcmp(Recolte,"17 KG")==0){gtk_combo_box_set_active(GTK_COMBO_BOX(REC),17);}
else if(strcmp(Recolte,"18 KG")==0){gtk_combo_box_set_active(GTK_COMBO_BOX(REC),18);}
else if(strcmp(Recolte,"19 KG")==0){gtk_combo_box_set_active(GTK_COMBO_BOX(REC),19);}
else if(strcmp(Recolte,"20 KG")==0){gtk_combo_box_set_active(GTK_COMBO_BOX(REC),20);}
f=fopen(data_base,"rb");
if(f!=NULL){
while(!feof(f)){
fread(&p,sizeof(plantation),1,f);
if(strcmp(Identifiant,p.Identifiant)==0){
gtk_image_set_from_file(GTK_IMAGE(MABFImageInsertion),p.Image);}}
fclose(f);}}}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void on_MABFCalendar_day_selected_double_click(GtkWidget *MABFWidget,gpointer user_data){
FILE *f=NULL;
GdkColor col;
char
jour[20]="",
mois[20]="",
annee[20]="",
date_cible[50]="",
nbr[50]="";
int
Jour=0,
Mois=0,
Annee=0,
NBR=0;
GtkWidget
*MABFCrud=lookup_widget(MABFWidget,"MABFcrud"),
*CALENDAR=lookup_widget(MABFWidget,"MABFCalendar"),
*MABFTreeView=lookup_widget(MABFWidget,"MABFTreeView"),
*MABFDialogSucc=gtk_dialog_new_with_buttons("Felicitations",GTK_WINDOW(MABFCrud),GTK_DIALOG_DESTROY_WITH_PARENT,"OK",GTK_RESPONSE_OK,NULL),
*MABFDialogEchec=gtk_dialog_new_with_buttons("Erreur",GTK_WINDOW(MABFCrud),GTK_DIALOG_DESTROY_WITH_PARENT,"OK",GTK_RESPONSE_OK,NULL),
*MABFLabelSucc=gtk_label_new(""),
*MABFLabelEchec=gtk_label_new("");
gtk_window_set_deletable(GTK_WINDOW(MABFDialogSucc),FALSE);
gtk_window_set_deletable(GTK_WINDOW(MABFDialogEchec),FALSE);
gtk_calendar_get_date(GTK_CALENDAR(CALENDAR),&Annee,&Mois,&Jour);
sprintf(jour,"%d",Jour);
strcat(date_cible,jour);
strcat(date_cible,"/");
sprintf(mois,"%d",Mois+1);
strcat(date_cible,mois);
strcat(date_cible,"/");
sprintf(annee,"%d",Annee);
strcat(date_cible,annee);
NBR=chercher_calendrier(data_base,date_cible,MABFTreeView);
gtk_container_add(GTK_CONTAINER(GTK_VBOX(gtk_dialog_get_content_area(GTK_DIALOG(MABFDialogSucc)))),MABFLabelSucc);
gtk_widget_set_size_request(MABFDialogSucc,400,200);
gtk_container_add(GTK_CONTAINER(GTK_VBOX(gtk_dialog_get_content_area(GTK_DIALOG(MABFDialogEchec)))),MABFLabelEchec);
gtk_widget_set_size_request(MABFDialogEchec,400,200);
if(NBR==0){
gtk_label_set_markup(GTK_LABEL(MABFLabelEchec),"<span size='medium'><b>0 plantations trouvées !</b></span>");
gtk_widget_show_all(MABFDialogEchec);
f=fopen(dialog_color,"rb");
if(f!=NULL){
fread(&col,sizeof(GdkColor),1,f);
gtk_widget_modify_bg(MABFDialogEchec,GTK_STATE_NORMAL,&col);
fclose(f);}
gint response_e=gtk_dialog_run(GTK_DIALOG(MABFDialogEchec));
if(response_e==GTK_RESPONSE_OK){
gtk_widget_destroy(MABFDialogEchec);}}
else{
char aux[100]="<span size='medium'><b>";
sprintf(nbr,"%d",NBR);
strcat(aux,nbr);
strcat(aux," plantation(s) trouvée(s) !</b></span>");
gtk_label_set_markup(GTK_LABEL(MABFLabelSucc),aux);
gtk_widget_show_all(MABFDialogSucc);
f=fopen(dialog_color,"rb");
if(f!=NULL){
fread(&col,sizeof(GdkColor),1,f);
gtk_widget_modify_bg(MABFDialogSucc,GTK_STATE_NORMAL,&col);
fclose(f);}
gint response_s=gtk_dialog_run(GTK_DIALOG(MABFDialogSucc));
if(response_s==GTK_RESPONSE_OK){
gtk_widget_destroy(MABFDialogSucc);}}}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void on_MABFCalendar_day_selected(GtkWidget *MABFWidget,gpointer user_data){
GtkWidget
*JJ=lookup_widget(MABFWidget,"MABFSpinButtonJour"),
*MM=lookup_widget(MABFWidget,"MABFSpinButtonMois"),
*AAAA=lookup_widget(MABFWidget,"MABFSpinButtonAnnee"),
*CAT=lookup_widget(MABFWidget,"MABFEntryCategorie"),
*ID=lookup_widget(MABFWidget,"MABFEntryID"),
*RBN=lookup_widget(MABFWidget,"MABFRadioButtonNaturelle"),
*RBA=lookup_widget(MABFWidget,"MABFRadioButtonAgricole"),
*ENG=lookup_widget(MABFWidget,"MABFComboBoxEngrais"),
*CBI=lookup_widget(MABFWidget,"MABFCheckButtonInsecticide"),
*CBF=lookup_widget(MABFWidget,"MABFCheckButtonFongicide"),
*CBH=lookup_widget(MABFWidget,"MABFCheckButtonHerbicide"),
*REC=lookup_widget(MABFWidget,"MABFComboBoxRecolte"),
*MABFTreeView=lookup_widget(MABFWidget,"MABFTreeView"),
*MABFImageInsertion=lookup_widget(MABFWidget,"MABFImageInsertion");
afficher_plantation(data_base,MABFTreeView);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(JJ),1);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(MM),1);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(AAAA),2020);
gtk_entry_set_text(GTK_ENTRY(CAT),"");
gtk_entry_set_text(GTK_ENTRY(ID),"");
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(RBN),TRUE);
gtk_combo_box_set_active(GTK_COMBO_BOX(ENG),0);
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(CBI),FALSE);
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(CBF),FALSE);
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(CBH),FALSE);
gtk_combo_box_set_active(GTK_COMBO_BOX(REC),0);
gtk_image_set_from_file(GTK_IMAGE(MABFImageInsertion),default_photo);}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

char *on_MABFEventBoxInsertion_button_press_event(GtkWidget *MABFWidget,gpointer user_data){
FILE *f=NULL;
GdkColor col;
char *filename=NULL;
GtkWidget
*MABFFileChooserDialog=gtk_file_chooser_dialog_new("Open File",NULL,GTK_FILE_CHOOSER_ACTION_OPEN,"Open",GTK_RESPONSE_ACCEPT,"Cancel",GTK_RESPONSE_CANCEL,NULL);
gtk_window_set_deletable(GTK_WINDOW(MABFFileChooserDialog),FALSE);
f=fopen(dialog_color,"rb");
if(f!=NULL){
fread(&col,sizeof(GdkColor),1,f);
gtk_widget_modify_bg(MABFFileChooserDialog,GTK_STATE_NORMAL,&col);
fclose(f);}
gint response=gtk_dialog_run(GTK_DIALOG(MABFFileChooserDialog));
if(response==GTK_RESPONSE_ACCEPT){
filename=gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(MABFFileChooserDialog));
GtkWidget *MABFImageInsertion=lookup_widget(MABFWidget,"MABFImageInsertion");
gtk_image_set_from_file(GTK_IMAGE(MABFImageInsertion),filename);
f=fopen(data_photo,"wb");
if(f!=NULL){fputs(filename,f);fclose(f);}}
gtk_widget_destroy(MABFFileChooserDialog);
return filename;}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void on_MABFEventBoxTri_button_press_event(GtkWidget *MABFWidget,gpointer user_data){
FILE *f=NULL;
GdkColor col;
plantation p;
int i=0,j=0;
GtkWidget
*MABFCrud=lookup_widget(MABFWidget,"MABFcrud"),
*MABFTreeView=lookup_widget(MABFWidget,"MABFTreeView"),
*MABFDialog=gtk_dialog_new_with_buttons("Recherche",GTK_WINDOW(MABFCrud),GTK_DIALOG_DESTROY_WITH_PARENT,"OK",GTK_RESPONSE_OK,"Cancel",GTK_RESPONSE_CANCEL,NULL),
*MABFFixed=gtk_fixed_new(),
*MABFLabel=gtk_label_new(""),
*MABFComboBox=gtk_combo_box_entry_new_text();
gtk_window_set_deletable(GTK_WINDOW(MABFDialog),FALSE);
GtkTreeSortable *sortable=GTK_TREE_SORTABLE(gtk_tree_view_get_model(GTK_TREE_VIEW(MABFTreeView)));
GtkSortType order;
gint sort_column_id;
gtk_label_set_markup(GTK_LABEL(MABFLabel),"<span size='medium'><b>Trier par :</b></span>");
gtk_container_add(GTK_CONTAINER(GTK_DIALOG(MABFDialog)->vbox),MABFFixed);
gtk_widget_set_size_request(MABFDialog,400,200);
gtk_fixed_put(GTK_FIXED(MABFFixed),MABFLabel,55,85);
gtk_fixed_put(GTK_FIXED(MABFFixed),MABFComboBox,140,78);
gtk_widget_set_size_request(MABFLabel,70,15);
gtk_widget_set_size_request(MABFComboBox,150,30);
gtk_combo_box_append_text(GTK_COMBO_BOX(MABFComboBox),"Catégorie");
gtk_combo_box_append_text(GTK_COMBO_BOX(MABFComboBox),"Identifiant");
gtk_combo_box_append_text(GTK_COMBO_BOX(MABFComboBox),"Irrigation");
gtk_combo_box_append_text(GTK_COMBO_BOX(MABFComboBox),"Engrais");
gtk_combo_box_append_text(GTK_COMBO_BOX(MABFComboBox),"Récolte");
f=fopen(dialog_color,"rb");
if(f!=NULL){
fread(&col,sizeof(GdkColor),1,f);
gtk_widget_modify_bg(MABFDialog,GTK_STATE_NORMAL,&col);
fclose(f);}
gtk_widget_show_all(MABFDialog);
gint response=gtk_dialog_run(GTK_DIALOG(MABFDialog));
if(response==GTK_RESPONSE_OK){
if(strcmp(gtk_combo_box_get_active_text(GTK_COMBO_BOX(MABFComboBox)),"Catégorie")==0){
if((gtk_tree_sortable_get_sort_column_id(sortable,&sort_column_id,&order)==TRUE)&&(sort_column_id==CATEGORIE)){
GtkSortType neworder=(order==GTK_SORT_ASCENDING)?GTK_SORT_DESCENDING:GTK_SORT_ASCENDING;
gtk_tree_sortable_set_sort_column_id(sortable,CATEGORIE,neworder);}
else{
gtk_tree_sortable_set_sort_column_id(sortable,CATEGORIE,GTK_SORT_ASCENDING);}}
else if(strcmp(gtk_combo_box_get_active_text(GTK_COMBO_BOX(MABFComboBox)),"Identifiant")==0){
if((gtk_tree_sortable_get_sort_column_id(sortable,&sort_column_id,&order)==TRUE)&&(sort_column_id==IDENTIFIANT)){
GtkSortType neworder=(order==GTK_SORT_ASCENDING)?GTK_SORT_DESCENDING:GTK_SORT_ASCENDING;
gtk_tree_sortable_set_sort_column_id(sortable,IDENTIFIANT,neworder);}
else{
gtk_tree_sortable_set_sort_column_id(sortable,IDENTIFIANT,GTK_SORT_ASCENDING);}}
else if(strcmp(gtk_combo_box_get_active_text(GTK_COMBO_BOX(MABFComboBox)),"Irrigation")==0){
if((gtk_tree_sortable_get_sort_column_id(sortable,&sort_column_id,&order)==TRUE)&&(sort_column_id==IRRIGATION)){
GtkSortType neworder=(order==GTK_SORT_ASCENDING)?GTK_SORT_DESCENDING:GTK_SORT_ASCENDING;
gtk_tree_sortable_set_sort_column_id(sortable,IRRIGATION,neworder);}
else{
gtk_tree_sortable_set_sort_column_id(sortable,IRRIGATION,GTK_SORT_ASCENDING);}}
else if(strcmp(gtk_combo_box_get_active_text(GTK_COMBO_BOX(MABFComboBox)),"Engrais")==0){
if((gtk_tree_sortable_get_sort_column_id(sortable,&sort_column_id,&order)==TRUE)&&(sort_column_id==DOSE_ENGRAIS)){
GtkSortType neworder=(order==GTK_SORT_ASCENDING)?GTK_SORT_DESCENDING:GTK_SORT_ASCENDING;
gtk_tree_sortable_set_sort_column_id(sortable,DOSE_ENGRAIS,neworder);}
else{
gtk_tree_sortable_set_sort_column_id(sortable,DOSE_ENGRAIS,GTK_SORT_ASCENDING);}}
else if(strcmp(gtk_combo_box_get_active_text(GTK_COMBO_BOX(MABFComboBox)),"Récolte")==0){
if((gtk_tree_sortable_get_sort_column_id(sortable,&sort_column_id,&order)==TRUE)&&(sort_column_id==POIDS_RECOLTE)){
GtkSortType neworder=(order==GTK_SORT_ASCENDING)?GTK_SORT_DESCENDING:GTK_SORT_ASCENDING;
gtk_tree_sortable_set_sort_column_id(sortable,POIDS_RECOLTE,neworder);}
else{
gtk_tree_sortable_set_sort_column_id(sortable,POIDS_RECOLTE,GTK_SORT_ASCENDING);}}}
gtk_widget_destroy(MABFDialog);}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void on_MABFEventBoxCouleur_button_press_event(GtkWidget *MABFWidget,gpointer user_data){
FILE *f=NULL;
GdkColor col;
GtkWidget
*MABFCrud=lookup_widget(MABFWidget,"MABFcrud"),
*MABFDialog=gtk_dialog_new_with_buttons("Paramètres couleur",GTK_WINDOW(MABFCrud),GTK_DIALOG_DESTROY_WITH_PARENT,"OK",GTK_RESPONSE_OK,"Cancel",GTK_RESPONSE_CANCEL,NULL),
*MABFFixed=gtk_fixed_new(),
*MABFLabel=gtk_label_new(""),
*MABFComboBox=gtk_combo_box_entry_new_text();
gtk_window_set_deletable(GTK_WINDOW(MABFDialog),FALSE);
gtk_label_set_markup(GTK_LABEL(MABFLabel),"<span size='medium'><b>Choisir une option :</b></span>");
gtk_container_add(GTK_CONTAINER(GTK_DIALOG(MABFDialog)->vbox),MABFFixed);
gtk_widget_set_size_request(MABFDialog,400,200);
gtk_fixed_put(GTK_FIXED(MABFFixed),MABFLabel,25,85);
gtk_fixed_put(GTK_FIXED(MABFFixed),MABFComboBox,180,78);
gtk_widget_set_size_request(MABFLabel,140,15);
gtk_widget_set_size_request(MABFComboBox,150,30);
gtk_combo_box_append_text(GTK_COMBO_BOX(MABFComboBox),"Titre");
gtk_combo_box_append_text(GTK_COMBO_BOX(MABFComboBox),"Sous titres");
gtk_combo_box_append_text(GTK_COMBO_BOX(MABFComboBox),"Boutons");
gtk_combo_box_append_text(GTK_COMBO_BOX(MABFComboBox),"Calendrier");
gtk_combo_box_append_text(GTK_COMBO_BOX(MABFComboBox),"TreeView");
gtk_combo_box_append_text(GTK_COMBO_BOX(MABFComboBox),"Arrière-plan");
gtk_combo_box_append_text(GTK_COMBO_BOX(MABFComboBox),"Dialogues");
f=fopen(dialog_color,"rb");
if(f!=NULL){
fread(&col,sizeof(GdkColor),1,f);
gtk_widget_modify_bg(MABFDialog,GTK_STATE_NORMAL,&col);
fclose(f);}
gtk_widget_show_all(MABFDialog);
gint res=gtk_dialog_run(GTK_DIALOG(MABFDialog));
if(res==GTK_RESPONSE_OK){
if(strcmp(gtk_combo_box_get_active_text(GTK_COMBO_BOX(MABFComboBox)),"Titre")==0){
GtkWidget
*GES=lookup_widget(MABFWidget,"MABFLabelGestion"),
*MABFColorSelectionDialog=gtk_color_selection_dialog_new("Select Color");
gtk_window_set_deletable(GTK_WINDOW(MABFColorSelectionDialog),FALSE);
GtkColorSelection
*colorsel=GTK_COLOR_SELECTION(GTK_COLOR_SELECTION_DIALOG(MABFColorSelectionDialog)->colorsel);
f=fopen(dialog_color,"rb");
if(f!=NULL){
fread(&col,sizeof(GdkColor),1,f);
gtk_widget_modify_bg(MABFColorSelectionDialog,GTK_STATE_NORMAL,&col);
fclose(f);}
gint response=gtk_dialog_run(GTK_DIALOG(MABFColorSelectionDialog));
gtk_color_selection_get_current_color(colorsel,&col);
if(response==GTK_RESPONSE_OK){
gtk_widget_modify_fg(GES,GTK_STATE_NORMAL,&col);
}
gtk_widget_destroy(MABFColorSelectionDialog);
f=fopen(head_color,"wb");
if(f!=NULL){fwrite(&col,sizeof(GdkColor),1,f);fclose(f);}}
else if(strcmp(gtk_combo_box_get_active_text(GTK_COMBO_BOX(MABFComboBox)),"Sous titres")==0){
GtkWidget
*DAT=lookup_widget(MABFWidget,"MABFLabelDate"),
*ID=lookup_widget(MABFWidget,"MABFLabelID"),
*CAT=lookup_widget(MABFWidget,"MABFLabelCategorie"),
*IRG=lookup_widget(MABFWidget,"MABFLabelIrrigation"),
*ENG=lookup_widget(MABFWidget,"MABFLabelEngrais"),
*TRT=lookup_widget(MABFWidget,"MABFLabelTraitement"),
*REC=lookup_widget(MABFWidget,"MABFLabelRecolte"),
*MABFColorSelectionDialog=gtk_color_selection_dialog_new("Select Color");
gtk_window_set_deletable(GTK_WINDOW(MABFColorSelectionDialog),FALSE);
GtkColorSelection
*colorsel=GTK_COLOR_SELECTION(GTK_COLOR_SELECTION_DIALOG(MABFColorSelectionDialog)->colorsel);
f=fopen(dialog_color,"rb");
if(f!=NULL){
fread(&col,sizeof(GdkColor),1,f);
gtk_widget_modify_bg(MABFColorSelectionDialog,GTK_STATE_NORMAL,&col);
fclose(f);}
gint response=gtk_dialog_run(GTK_DIALOG(MABFColorSelectionDialog));
gtk_color_selection_get_current_color(colorsel,&col);
if(response==GTK_RESPONSE_OK){
gtk_widget_modify_fg(DAT,GTK_STATE_NORMAL,&col);
gtk_widget_modify_fg(ID,GTK_STATE_NORMAL,&col);
gtk_widget_modify_fg(CAT,GTK_STATE_NORMAL,&col);
gtk_widget_modify_fg(IRG,GTK_STATE_NORMAL,&col);
gtk_widget_modify_fg(ENG,GTK_STATE_NORMAL,&col);
gtk_widget_modify_fg(TRT,GTK_STATE_NORMAL,&col);
gtk_widget_modify_fg(REC,GTK_STATE_NORMAL,&col);
}
gtk_widget_destroy(MABFColorSelectionDialog);
f=fopen(body_color,"wb");
if(f!=NULL){fwrite(&col,sizeof(GdkColor),1,f);fclose(f);}}
else if(strcmp(gtk_combo_box_get_active_text(GTK_COMBO_BOX(MABFComboBox)),"Boutons")==0){
GtkWidget
*MABFButtonAjouter=lookup_widget(MABFWidget,"MABFButtonAjouter"),
*MABFButtonModifier=lookup_widget(MABFWidget,"MABFButtonModifier"),
*MABFButtonSupprimer=lookup_widget(MABFWidget,"MABFButtonSupprimer"),
*MABFButtonChercher=lookup_widget(MABFWidget,"MABFButtonChercher"),
*MABFColorSelectionDialog=gtk_color_selection_dialog_new("Select Color");
gtk_window_set_deletable(GTK_WINDOW(MABFColorSelectionDialog),FALSE);
GtkColorSelection
*colorsel=GTK_COLOR_SELECTION(GTK_COLOR_SELECTION_DIALOG(MABFColorSelectionDialog)->colorsel);
f=fopen(dialog_color,"rb");
if(f!=NULL){
fread(&col,sizeof(GdkColor),1,f);
gtk_widget_modify_bg(MABFColorSelectionDialog,GTK_STATE_NORMAL,&col);
fclose(f);}
gint response=gtk_dialog_run(GTK_DIALOG(MABFColorSelectionDialog));
gtk_color_selection_get_current_color(colorsel,&col);
if(response==GTK_RESPONSE_OK){
gtk_widget_modify_bg(MABFButtonAjouter,GTK_STATE_NORMAL,&col);
gtk_widget_modify_bg(MABFButtonModifier,GTK_STATE_NORMAL,&col);
gtk_widget_modify_bg(MABFButtonSupprimer,GTK_STATE_NORMAL,&col);
gtk_widget_modify_bg(MABFButtonChercher,GTK_STATE_NORMAL,&col);}
gtk_widget_destroy(MABFColorSelectionDialog);
f=fopen(button_color,"wb");
if(f!=NULL){fwrite(&col,sizeof(GdkColor),1,f);fclose(f);}}
else if(strcmp(gtk_combo_box_get_active_text(GTK_COMBO_BOX(MABFComboBox)),"Calendrier")==0){
GtkWidget
*MABFCalendar=lookup_widget(MABFWidget,"MABFCalendar"),
*MABFColorSelectionDialog=gtk_color_selection_dialog_new("Select Color");
gtk_window_set_deletable(GTK_WINDOW(MABFColorSelectionDialog),FALSE);
GtkColorSelection
*colorsel=GTK_COLOR_SELECTION(GTK_COLOR_SELECTION_DIALOG(MABFColorSelectionDialog)->colorsel);
f=fopen(dialog_color,"rb");
if(f!=NULL){
fread(&col,sizeof(GdkColor),1,f);
gtk_widget_modify_bg(MABFColorSelectionDialog,GTK_STATE_NORMAL,&col);
fclose(f);}
gint response=gtk_dialog_run(GTK_DIALOG(MABFColorSelectionDialog));
gtk_color_selection_get_current_color(colorsel,&col);
if(response==GTK_RESPONSE_OK){
gtk_widget_modify_base(MABFCalendar,GTK_STATE_NORMAL,&col);}
gtk_widget_destroy(MABFColorSelectionDialog);
f=fopen(calendar_color,"wb");
if(f!=NULL){fwrite(&col,sizeof(GdkColor),1,f);fclose(f);}}
else if(strcmp(gtk_combo_box_get_active_text(GTK_COMBO_BOX(MABFComboBox)),"TreeView")==0){
GtkWidget
*MABFTreeView=lookup_widget(MABFWidget,"MABFTreeView"),
*MABFColorSelectionDialog=gtk_color_selection_dialog_new("Select Color");
gtk_window_set_deletable(GTK_WINDOW(MABFColorSelectionDialog),FALSE);
GtkColorSelection
*colorsel=GTK_COLOR_SELECTION(GTK_COLOR_SELECTION_DIALOG(MABFColorSelectionDialog)->colorsel);
f=fopen(dialog_color,"rb");
if(f!=NULL){
fread(&col,sizeof(GdkColor),1,f);
gtk_widget_modify_bg(MABFColorSelectionDialog,GTK_STATE_NORMAL,&col);
fclose(f);}
gint response=gtk_dialog_run(GTK_DIALOG(MABFColorSelectionDialog));
gtk_color_selection_get_current_color(colorsel,&col);
if(response==GTK_RESPONSE_OK){
gtk_widget_modify_base(MABFTreeView,GTK_STATE_NORMAL,&col);}
gtk_widget_destroy(MABFColorSelectionDialog);
f=fopen(TreeView_color,"wb");
if(f!=NULL){fwrite(&col,sizeof(GdkColor),1,f);fclose(f);}}
else if(strcmp(gtk_combo_box_get_active_text(GTK_COMBO_BOX(MABFComboBox)),"Arrière-plan")==0){
GtkWidget
*MABFEventBoxInsertion=lookup_widget(MABFWidget,"MABFEventBoxInsertion"),
*MABFEventBoxCouleur=lookup_widget(MABFWidget,"MABFEventBoxCouleur"),
*MABFEventBoxTri=lookup_widget(MABFWidget,"MABFEventBoxTri"),
*MABFColorSelectionDialog=gtk_color_selection_dialog_new("Select Color");
gtk_window_set_deletable(GTK_WINDOW(MABFColorSelectionDialog),FALSE);
GtkColorSelection
*colorsel=GTK_COLOR_SELECTION(GTK_COLOR_SELECTION_DIALOG(MABFColorSelectionDialog)->colorsel);
f=fopen(dialog_color,"rb");
if(f!=NULL){
fread(&col,sizeof(GdkColor),1,f);
gtk_widget_modify_bg(MABFColorSelectionDialog,GTK_STATE_NORMAL,&col);
fclose(f);}
gint response=gtk_dialog_run(GTK_DIALOG(MABFColorSelectionDialog));
gtk_color_selection_get_current_color(colorsel,&col);
if(response==GTK_RESPONSE_OK){
gtk_widget_modify_bg(MABFCrud,GTK_STATE_NORMAL,&col);
gtk_widget_modify_bg(MABFEventBoxInsertion,GTK_STATE_NORMAL,&col);
gtk_widget_modify_bg(MABFEventBoxCouleur,GTK_STATE_NORMAL,&col);
gtk_widget_modify_bg(MABFEventBoxTri,GTK_STATE_NORMAL,&col);}
gtk_widget_destroy(MABFColorSelectionDialog);
f=fopen(background_color,"wb");
if(f!=NULL){fwrite(&col,sizeof(GdkColor),1,f);fclose(f);}}
else if(strcmp(gtk_combo_box_get_active_text(GTK_COMBO_BOX(MABFComboBox)),"Dialogues")==0){
GtkWidget
*MABFColorSelectionDialog=gtk_color_selection_dialog_new("Select Color");
gtk_window_set_deletable(GTK_WINDOW(MABFColorSelectionDialog),FALSE);
GtkColorSelection
*colorsel=GTK_COLOR_SELECTION(GTK_COLOR_SELECTION_DIALOG(MABFColorSelectionDialog)->colorsel);
f=fopen(dialog_color,"rb");
if(f!=NULL){
fread(&col,sizeof(GdkColor),1,f);
gtk_widget_modify_bg(MABFColorSelectionDialog,GTK_STATE_NORMAL,&col);
fclose(f);}
gint response=gtk_dialog_run(GTK_DIALOG(MABFColorSelectionDialog));
gtk_color_selection_get_current_color(colorsel,&col);
if(response==GTK_RESPONSE_OK){
f=fopen(dialog_color,"wb");
if(f!=NULL){fwrite(&col,sizeof(GdkColor),1,f);fclose(f);}}
gtk_widget_destroy(MABFColorSelectionDialog);}}
gtk_widget_destroy(MABFDialog);}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void on_MABFButtonDeconnexion_clicked(GtkWidget *MABFWidget,gpointer user_data){
FILE *f=NULL;
GdkColor col;
GtkWidget
*MABFCrud=lookup_widget(MABFWidget,"MABFcrud"),
*MABFDialogAlerte=gtk_dialog_new_with_buttons("Alerte",GTK_WINDOW(MABFCrud),GTK_DIALOG_DESTROY_WITH_PARENT,"OK",GTK_RESPONSE_OK,"Cancel",GTK_RESPONSE_CANCEL,NULL),
*MABFLabelAlerte=gtk_label_new("");
gtk_label_set_markup(GTK_LABEL(MABFLabelAlerte),"<span size='medium'><b>Voulez-vous vraiment se déconnecter ?</b></span>");
gtk_window_set_deletable(GTK_WINDOW(MABFDialogAlerte),FALSE);
gtk_container_add(GTK_CONTAINER(GTK_VBOX(gtk_dialog_get_content_area(GTK_DIALOG(MABFDialogAlerte)))),MABFLabelAlerte);
gtk_widget_set_size_request(MABFDialogAlerte,400,200);
f=fopen(dialog_color,"rb");
if(f!=NULL){
fread(&col,sizeof(GdkColor),1,f);
gtk_widget_modify_bg(MABFDialogAlerte,GTK_STATE_NORMAL,&col);
fclose(f);}
gtk_widget_show_all(MABFDialogAlerte);
gint response_a=gtk_dialog_run(GTK_DIALOG(MABFDialogAlerte));
if(response_a==GTK_RESPONSE_OK){
gtk_widget_destroy(MABFCrud);
GtkWidget *FMconnexion=create_FMconnexion();
gtk_widget_show(FMconnexion);}
if(response_a==GTK_RESPONSE_CANCEL){
gtk_widget_destroy(MABFDialogAlerte);}}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void on_MABFButtonAccueil_clicked(GtkWidget *MABFWidget,gpointer user_data){
FILE *f=NULL;
GtkWidget
*MABFCrud=lookup_widget(MABFWidget,"MABFcrud"),
*Admin=create_Admin();
gtk_widget_destroy(MABFCrud);
gtk_widget_show(Admin);}

//////////////////////////////////////////////////////////////////////////////////////////////////MABF calcul///////////////////////////////////////////////////////////////////////////////////////////////////////

char
data_capt[]="capteur.txt";

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void on_MABFButtonCaptDef_clicked(GtkWidget *MABFWidget,gpointer user_data){
FILE *f=NULL;
capteur_type cpt;
int
i=0,
S=0,
H=0,
L=0,
G=0;
char
Marque[20]="";
GtkWidget
*MQ=lookup_widget(MABFWidget,"MABFEntryMark");
f=fopen(data_capt,"r");
if(f!=NULL){
while(fscanf(f,"%d %d %d %s %s %f %s\n",&cpt.Date.Jour,&cpt.Date.Mois,&cpt.Date.Annee,cpt.Marque,cpt.Identifiant,&cpt.Valeur,cpt.Type)!=EOF){
if(cpt.Valeur>100){
if(strcmp(cpt.Marque,"sauermann")==0){
S++;}
if(strcmp(cpt.Marque,"HITEC")==0){
H++;}
if(strcmp(cpt.Marque,"LINDY")==0){
L++;}
if(strcmp(cpt.Marque,"Galvatek")==0){
G++;}}}
fclose(f);}
int
T[4]={S,H,L,G},
MAXIMUM=S;
for(i=1;i<4;i++){
if(T[i]>MAXIMUM){
MAXIMUM=T[i];}}
if(MAXIMUM==S){
strcpy(Marque,"sauermann");}
else if(MAXIMUM==H){
strcpy(Marque,"HITEC");}
else if(MAXIMUM==L){
strcpy(Marque,"LINDY");}
else{
strcpy(Marque,"Galvatek");}
if(MAXIMUM!=0){
gtk_entry_set_text(GTK_ENTRY(MQ),Marque);}}

void
on_decoMB_clicked                      (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *fenetre_afficher2;
GtkWidget  *FMconnexion;
FMconnexion= create_FMconnexion();
fenetre_afficher2=lookup_widget(GTK_WIDGET(button),"MBcrud");
 gtk_widget_destroy(fenetre_afficher2);
gtk_widget_show(FMconnexion);
}


void
on_decoMH_clicked                      (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *fenetre_afficher2;
GtkWidget  *FMconnexion;
FMconnexion= create_FMconnexion();
fenetre_afficher2=lookup_widget(GTK_WIDGET(button),"MHwindowrec");
 gtk_widget_destroy(fenetre_afficher2);
gtk_widget_show(FMconnexion);
}


void
on_MHdash_clicked                      (GtkButton       *button,
                                        gpointer         user_data)
{
  
GtkWidget  *MHwindowAffichage;
MHwindowAffichage= create_MHwindowAffichage();

gtk_widget_show(MHwindowAffichage); 
}


void
on_okbutton11_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *dialog11;
dialog11= lookup_widget(GTK_WIDGET(button),"dialog11");

 gtk_widget_destroy(dialog11);
}


void
on_button73_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *fenetre_afficher2;
GtkWidget  *FMconnexion;
FMconnexion= create_FMconnexion();
fenetre_afficher2=lookup_widget(GTK_WIDGET(button),"RKcrud");
 gtk_widget_destroy(fenetre_afficher2);
gtk_widget_show(FMconnexion);
}


void
on_dashbord_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget  *dashbord;
dashbord= create_dashbord();


//SECHE
  int s_2017;
  int s_2018;
  int s_2019;
  int s_2020;

  int seche_max;

  
  char labbb[50];

  seche_max=seche_f(&s_2017,&s_2018,&s_2019,&s_2020);
  GtkWidget *sch;

  sch=lookup_widget(dashbord,"MB_2017_c");
  sprintf(labbb,"%d",s_2017);
  gtk_label_set_text(GTK_LABEL(sch),labbb);

  sch=lookup_widget(dashbord,"MB_2018_c");
  sprintf(labbb,"%d",s_2018);
  gtk_label_set_text(GTK_LABEL(sch),labbb);

  sch=lookup_widget(dashbord,"MB_2019_c");
  sprintf(labbb,"%d",s_2019);
  gtk_label_set_text(GTK_LABEL(sch),labbb);

  sch=lookup_widget(dashbord,"MB_2020_c");
  sprintf(labbb,"%d",s_2020);
  gtk_label_set_text(GTK_LABEL(sch),labbb);

  sch=lookup_widget(dashbord,"MB_seche_c");
  sprintf(labbb,"%d",seche_max);
  gtk_label_set_text(GTK_LABEL(sch),labbb);
 //gtk_widget_show(dashbord);
}

