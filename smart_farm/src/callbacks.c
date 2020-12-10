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

selected_capteur;
char file_name[50]="inscription.txt";
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
}


void
on_buttons_equipements_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{

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

}


void
on_button_plantation_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{

}

void
on_button_commandes_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget  *windowAuth;
windowAuth= create_gestioncommande();
gtk_widget_show(windowAuth);

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
on_BMbuttonAfficher_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window1;
GtkWidget *Humidite;
GtkWidget *Temperature;
GtkWidget *BMwindowcapt;
GtkWidget *BMtreeviewAffichage;
BMwindowcapt=lookup_widget(objet,"BMwindowcapt");
BMtreeviewAffichage=lookup_widget(BMwindowcapt,"BMtreeviewAffichage");
Humidite=lookup_widget(objet,"BMcheckbuttonaffichage2");
Temperature=lookup_widget(objet,"BMcheckbuttonaffichage1");
if( gtk_toggle_button_get_active(GTK_CHECK_BUTTON (Humidite)))
{
afficherhum(BMtreeviewAffichage);
}
if( gtk_toggle_button_get_active(GTK_CHECK_BUTTON (Temperature)))
{
affichertmp(BMtreeviewAffichage);
}
if( gtk_toggle_button_get_active(GTK_CHECK_BUTTON (Temperature)) && gtk_toggle_button_get_active(GTK_CHECK_BUTTON (Humidite)) )
{
afficher(BMtreeviewAffichage);
}}

void
on_BMbuttonSupprimer_clicked           (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_afficher;
char id[30];
GtkWidget *treeview1;
GtkWidget *input1;
input1=lookup_widget(objet,"BMentry10");
strcpy(id,gtk_entry_get_text(GTK_ENTRY(input1)));
supprimer3("file.txt",id);
fenetre_afficher=lookup_widget(objet,"BMwindowcapt");
treeview1=lookup_widget(fenetre_afficher,"BMtreeviewAffichage");
afficher(treeview1);
}

void
on_BMbuttonAModifier_clicked           (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *BMwindowmodifier;
/*
date date_ajout;
FILE *f;
GtkWidget *id,*mq,*tp,*val,*jour,*mois,*annee,*windowAuth;
capteur c;
id = lookup_widget (objet_graphique,"entry2");
mq = lookup_widget (objet_graphique,"entry3");
val = lookup_widget (objet_graphique,"entry4");
jour = lookup_widget (objet_graphique,"spinbutton4");
mois = lookup_widget (objet_graphique,"spinbutton5");
annee = lookup_widget (objet_graphique,"spinbutton6");
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
on_BMbuttonRechercher_clicked          (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *BMwindowcapt;
GtkWidget *id;
id = lookup_widget (objet,"BMentry10");
char IDs[20];
strcpy(IDs,gtk_entry_get_text(GTK_ENTRY(id)));
GtkWidget *BMtreeviewAffichage;
BMwindowcapt=lookup_widget (objet,"BMwindowcapt");
BMtreeviewAffichage=lookup_widget (BMwindowcapt,"BMtreeviewAffichage");
rechercher_capteur(IDs,BMtreeviewAffichage);
}

void
on_BMbuttonAjouter_clicked             (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
Mdate Mdate_ajout;
FILE *f;
GtkWidget *id,*mq,*tp,*val,*jour,*mois,*annee,*windowAuth,*Humidite,*Temperature;
capteur c;
id = lookup_widget (objet_graphique,"BMentry8");
mq = lookup_widget (objet_graphique,"BMentry9");
val = lookup_widget (objet_graphique,"entry1");
jour = lookup_widget (objet_graphique,"spinbutton1");
mois = lookup_widget (objet_graphique,"spinbutton2");
annee = lookup_widget (objet_graphique,"spinbutton3");
Humidite=lookup_widget(objet_graphique,"radiobutton1");
Temperature=lookup_widget(objet_graphique,"radiobutton2");
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
on_BMbuttonAfficherAlarm_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_BMbuttonConfirmerModif_clicked      (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{
Mdate Mdate_ajout;
FILE *f;
GtkWidget *id,*mq,*tp,*val,*jour,*mois,*annee,*windowAuth,*Humidite,*Temperature;
capteur c;
Humidite=lookup_widget(objet_graphique,"BMradiobutton4");
Temperature=lookup_widget(objet_graphique,"BMradiobutton5");
id = lookup_widget (objet_graphique,"entry2");
mq = lookup_widget (objet_graphique,"entry3");
val = lookup_widget (objet_graphique,"entry4");
jour = lookup_widget (objet_graphique,"spinbutton4");
mois = lookup_widget (objet_graphique,"spinbutton5");
annee = lookup_widget (objet_graphique,"spinbutton6");
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
ajouter(f,c);
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
on_BMrecherchemodif_clicked            (GtkWidget      *button,
                                        gpointer         user_data)
{
GtkWidget *id, *mq,*typ1,*typ2,*valeur, *jour , *mois, *annee,*Humidite,*Temperature;
char ID[20];
char MARQUE[20];
char VALEUR [20];
capteur c;
Mdate Mdate_ajout;
char nom_fichier[100]="file.txt";
id = lookup_widget (button,"entry2");
strcpy(ID,gtk_entry_get_text(GTK_ENTRY(id)));
c=rechercher1(ID,nom_fichier);
if(c.Mdate_ajout.jour!=-1)
{
mq = lookup_widget (button,"entry3");
valeur = lookup_widget (button,"entry4");
jour=lookup_widget(button,"spinbutton4");
mois=lookup_widget(button,"spinbutton5");
annee=lookup_widget(button,"spinbutton6");
typ2=lookup_widget(button,"BMradiobutton4");
typ1=lookup_widget(button,"BMradiobutton5");
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
on_BMbuttonretour_clicked              (GtkWidget         *objet,
                                        gpointer         user_data)
{
GtkWidget *BMwindowcapt,*BMwindow;
BMwindow=lookup_widget(objet,"BMwindowmodifier");
gtk_widget_destroy(BMwindow);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////           Fares     ////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void
on_FMconnectbutton_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{GtkWidget *username , *password, *windowEspaceAdmin, *window;
char user[20];
char pasw[20];
int trouve;
char texte3[100];
GtkWidget* output ;
strcpy(texte3,"Mot de passe ou username incorrect");
username = lookup_widget (button, "FMnomentry");
password = lookup_widget (button,"FMmdpentry");
window=lookup_widget(button,"FMconnexion");
strcpy(user, gtk_entry_get_text(GTK_ENTRY(username)));
strcpy(pasw, gtk_entry_get_text(GTK_ENTRY(password)));
trouve=verif(user,pasw);
if(trouve==1)
{
windowEspaceAdmin=create_FMcrudcommandes();
 gtk_widget_show (windowEspaceAdmin);
 gtk_widget_destroy(window);

}
else{
//sprintf(texte3,"Mot de passe ou username incorrect");
output = lookup_widget(button, "label167") ;
gtk_label_set_text(GTK_LABEL(output),texte3);

}
}


void
on_FMcreercomptebutton_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{GtkWidget  *windowAuth,*window;
windowAuth= create_FMcreationcompte();
window=lookup_widget(button,"FMconnexion");
gtk_widget_show(windowAuth);

 gtk_widget_destroy(window);
//gtk_widget_destroy(GTK_WIDGET(button));


}


void
on_Forgetpass_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{

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
on_button56_clicked                    (GtkButton       *objet,
                                        gpointer         user_data)
{FILE *f=NULL ;
GtkWidget *login, *pw ,*nom,*prenom,*adress,*jour,*mois,*annee,*email,*radiobutton9,*radiobutton10;
client c;
GtkWidget *FMcreationcompte;
GtkWidget  *windowAuth;
FMcreationcompte= lookup_widget(objet,"FMcreationcompte");

nom= lookup_widget(objet,"entry35");
prenom= lookup_widget(objet,"entry36");
login= lookup_widget(objet,"entry405");
pw= lookup_widget(objet,"entry39");
email= lookup_widget(objet,"entry34");


jour= lookup_widget(objet,"spinbutton13");
mois= lookup_widget(objet,"spinbutton14");
annee= lookup_widget(objet,"spinbutton15");
adress= lookup_widget(objet,"entry38");
radiobutton9=lookup_widget(objet,"radiobutton9");
radiobutton10=lookup_widget(objet,"radiobutton10");
strcpy(c.nom, gtk_entry_get_text(GTK_ENTRY(nom)));
strcpy(c.prenom, gtk_entry_get_text(GTK_ENTRY(prenom)));
strcpy(c.username, gtk_entry_get_text(GTK_ENTRY(login)));
strcpy(c.password, gtk_entry_get_text(GTK_ENTRY(pw)));
strcpy(c.email, gtk_entry_get_text(GTK_ENTRY(email)));

if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(radiobutton9)))
  {strcpy(c.sexe,"Homme");}
  else if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(radiobutton10)))
  {strcpy(c.sexe,"Femme");}
c.d.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
c.d.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
c.d.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));
strcpy(c.adress, gtk_entry_get_text(GTK_ENTRY(adress)));
inscription_client("inscription.txt",c);

windowAuth= create_FMconnexion();
gtk_widget_show(windowAuth);
 gtk_widget_destroy(FMcreationcompte);

}


void
on_button55_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget  *windowAuth,*window;
window=lookup_widget(button,"FMcreationcompte");
windowAuth= create_FMconnexion();
gtk_widget_show(windowAuth);
 gtk_widget_destroy(window);


}


void
on_button57_clicked                    (GtkButton       *objet,
                                        gpointer         user_data)
{GtkWidget *FMcreationcompte;
GtkWidget *Fmcrud;
GtkWidget *FMtreeview;
GtkWidget *Homme;
GtkWidget *Femme;

//FMcreationcompte= lookup_widget(objet,"FMcreationcompte");
//gtk_widget_destroy(FMcreationcompte);
Fmcrud=lookup_widget(objet,"Fmcrud");
//Fmcrud=create_Fmcrud();
//gtk_widget_show(Fmcrud);
FMtreeview=lookup_widget(Fmcrud,"FMtreeview");
//afficher_client(FMtreeview);
Homme=lookup_widget(objet,"checkbutton6");

Femme=lookup_widget(objet,"checkbutton7");
if( gtk_toggle_button_get_active(GTK_CHECK_BUTTON (Homme)))
{
afficher_client_homme(FMtreeview);
}
if( gtk_toggle_button_get_active(GTK_CHECK_BUTTON (Femme)))
{
afficher_client_femme(FMtreeview);
}


if( gtk_toggle_button_get_active(GTK_CHECK_BUTTON (Femme)) && gtk_toggle_button_get_active(GTK_CHECK_BUTTON (Homme)) )
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
on_FMmodif_clicked                     (GtkButton       *objet,
                                        gpointer         user_data)
{

GtkWidget  *windowAuth;
windowAuth= create_FMmodif();
gtk_widget_show(windowAuth);



}





void
on_FMsupp_clicked                      (GtkButton       *objet,
                                        gpointer         user_data)
{GtkWidget *fenetre_afficher;

  char email[30];
  GtkWidget *treeview1;
  GtkWidget *input1;
  input1=lookup_widget(objet,"entry41");
  strcpy(email,gtk_entry_get_text(GTK_ENTRY(input1)));
  supprimer_client("inscription.txt",email);
 fenetre_afficher=lookup_widget(objet,"Fmcrud");
 gtk_widget_destroy(fenetre_afficher);

 fenetre_afficher=create_Fmcrud();
 gtk_widget_show(fenetre_afficher);

  treeview1=lookup_widget(fenetre_afficher,"FMtreeview");
 afficher_client(treeview1);


}


void
on_FMrech_clicked                      (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *emaill,*Fmcrud;
char c[20];
GtkWidget *FMtreeview;

emaill=lookup_widget(objet,"entry41");
Fmcrud=lookup_widget(objet,"Fmcrud");
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
client c;
int a;
GtkTreeModel *model = gtk_tree_view_get_model(treeview);
if (gtk_tree_model_get_iter(model, &iter , path)) {
gtk_tree_model_get (GTK_LIST_STORE(model), &iter,0, &nom,1, &prenom,2, &username,3,&password,4,&email,5,&jour,6,&mois,7,&annee,8,&adress,9,&sexe,-1);
strcpy(c.nom,nom);
strcpy(c.prenom,prenom);
strcpy(c.username,username);
strcpy(c.password,password);
strcpy(c.email,email);
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
on_button59_clicked                    (GtkButton       *objet,
                                        gpointer         user_data)
{ FILE *f;
client c;
  GtkWidget *login, *pw ,*nom,*prenom,*adress,*jour,*mois,*annee,*email,*radiobutton14,*radiobutton15,*treeview1;

GtkWidget *radiobutton9 , *radiobutton10, *fenetre_afficher;
 nom= lookup_widget(objet,"entry408");
prenom= lookup_widget(objet,"entry409");
login= lookup_widget(objet,"entry411");
pw= lookup_widget(objet,"entry410");
email= lookup_widget(objet,"entry406");
jour= lookup_widget(objet,"spinbutton16");
mois= lookup_widget(objet,"spinbutton17");
annee= lookup_widget(objet,"spinbutton18");
adress= lookup_widget(objet,"entry409");
radiobutton9=lookup_widget(objet,"radiobutton14");
radiobutton10=lookup_widget(objet,"radiobutton15");
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

supprimer2(c);
inscription_client(f, c);

 fenetre_afficher=lookup_widget(objet,"Fmcrud");
 gtk_widget_destroy(fenetre_afficher);

 fenetre_afficher=create_Fmcrud();
 gtk_widget_show(fenetre_afficher);

  treeview1=lookup_widget(fenetre_afficher,"FMtreeview");
 afficher_client(treeview1);
}


void
on_button60_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{GtkWidget *email, *nom,*prenom,*user,*passw,*adress, *jour , *mois, *annee,*radiobutton14,*radiobutton15;
char MAIL[20];
client c;
char nom_fichier[100]="inscription.txt";
email = lookup_widget (button,"entry406");
strcpy(MAIL,gtk_entry_get_text(GTK_ENTRY(email)));
c=rechercher2(MAIL,nom_fichier);
if(c.d.jour!=-1)
{
nom= lookup_widget(button,"entry407");
prenom= lookup_widget(button,"entry408");
user= lookup_widget(button,"entry411");
passw= lookup_widget(button,"entry410");
email= lookup_widget(button,"entry406");
jour= lookup_widget(button,"spinbutton16");
mois= lookup_widget(button,"spinbutton17");
annee= lookup_widget(button,"spinbutton18");
adress= lookup_widget(button,"entry409");
radiobutton14=lookup_widget(button,"radiobutton14");
radiobutton15=lookup_widget(button,"radiobutton15");
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
 }}


void
validez_achat                          (GtkButton       *objet,
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
on_confirmercommande_clicked           (GtkButton       *objet,
                                        gpointer         user_data)
{

GtkWidget* output ;


commande co;
GtkWidget *FMcommande;
char texte3[50];
sprintf(texte3,"Prix totale est : %d  dt ",co.prix);
output = lookup_widget(objet, "label205") ;
gtk_label_set_text(GTK_LABEL(output),texte3);
gtk_widget_destroy(GTK_WIDGET(objet));

}




void
on_affichertreeview_clicked            (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *gestioncommande;
GtkWidget *treeviewcommande;

gestioncommande=lookup_widget(objet,"gestioncommande");
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

}


void
on_button62_clicked                    (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget* output ;
GtkWidget *tomate, *carotte, *epinard , *pomme_de_terre , *artichaud ,*brocoli;
FILE *f=NULL ;
commande co;
GtkWidget *FMcommande;
char texte3[100];

FMcommande= lookup_widget(objet,"FMcrudcommandes");
tomate= lookup_widget(objet,"spinbutton26");
carotte= lookup_widget(objet,"spinbutton25");
epinard= lookup_widget(objet,"spinbutton24");
pomme_de_terre= lookup_widget(objet,"spinbutton23");
artichaud= lookup_widget(objet,"spinbutton22");
brocoli= lookup_widget(objet,"spinbutton21");
co.tomate=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(tomate));
co.carotte=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(carotte));
co.epinard=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(epinard));
co.pomme_de_terre=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(pomme_de_terre));
co.artichaud=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(artichaud));
co.brocoli=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(brocoli));
commandes("commande.txt",co);


}

