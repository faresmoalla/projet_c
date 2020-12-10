/*
 * DO NOT EDIT THIS FILE - it is generated by Glade.
 */

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

#include <gdk/gdkkeysyms.h>
#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"

#define GLADE_HOOKUP_OBJECT(component,widget,name) \
  g_object_set_data_full (G_OBJECT (component), name, \
    gtk_widget_ref (widget), (GDestroyNotify) gtk_widget_unref)

#define GLADE_HOOKUP_OBJECT_NO_REF(component,widget,name) \
  g_object_set_data (G_OBJECT (component), name, widget)

GtkWidget*
create_MBcrud (void)
{
  GtkWidget *MBcrud;
  GtkWidget *fixed1;
  GtkWidget *treeview1;
  GtkWidget *entry1;
  GtkWidget *label1;
  GtkWidget *button1;
  GtkWidget *image1;
  GtkWidget *MBbuttonaffich;
  GtkWidget *alignment1;
  GtkWidget *hbox1;
  GtkWidget *image2;
  GtkWidget *label2;
  GtkWidget *MBbuttonajout;
  GtkWidget *alignment2;
  GtkWidget *hbox2;
  GtkWidget *image3;
  GtkWidget *label3;
  GtkWidget *MBbuttonsupprim;
  GtkWidget *alignment3;
  GtkWidget *hbox3;
  GtkWidget *image4;
  GtkWidget *label4;
  GtkWidget *_;
  GtkWidget *MBcheckmois;
  GtkWidget *MBcheckcheni;
  GtkWidget *MBcheckchar;
  GtkWidget *MBchecktrac;
  GtkWidget *MBbuttonmodif;
  GtkWidget *alignment4;
  GtkWidget *hbox4;
  GtkWidget *image5;
  GtkWidget *label5;

  MBcrud = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (MBcrud), _("Equipements agricoles"));

  fixed1 = gtk_fixed_new ();
  gtk_widget_show (fixed1);
  gtk_container_add (GTK_CONTAINER (MBcrud), fixed1);

  treeview1 = gtk_tree_view_new ();
  gtk_widget_show (treeview1);
  gtk_fixed_put (GTK_FIXED (fixed1), treeview1, 48, 136);
  gtk_widget_set_size_request (treeview1, 896, 248);

  entry1 = gtk_entry_new ();
  gtk_widget_show (entry1);
  gtk_fixed_put (GTK_FIXED (fixed1), entry1, 104, 16);
  gtk_widget_set_size_request (entry1, 160, 27);
  gtk_entry_set_invisible_char (GTK_ENTRY (entry1), 8226);

  label1 = gtk_label_new (_("Recherche:"));
  gtk_widget_show (label1);
  gtk_fixed_put (GTK_FIXED (fixed1), label1, 8, 24);
  gtk_widget_set_size_request (label1, 104, 17);

  button1 = gtk_button_new ();
  gtk_widget_show (button1);
  gtk_fixed_put (GTK_FIXED (fixed1), button1, 272, 16);
  gtk_widget_set_size_request (button1, 32, 32);

  image1 = gtk_image_new_from_stock ("gtk-find", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image1);
  gtk_container_add (GTK_CONTAINER (button1), image1);

  MBbuttonaffich = gtk_button_new ();
  gtk_widget_show (MBbuttonaffich);
  gtk_fixed_put (GTK_FIXED (fixed1), MBbuttonaffich, 104, 408);
  gtk_widget_set_size_request (MBbuttonaffich, 80, 29);

  alignment1 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_show (alignment1);
  gtk_container_add (GTK_CONTAINER (MBbuttonaffich), alignment1);

  hbox1 = gtk_hbox_new (FALSE, 2);
  gtk_widget_show (hbox1);
  gtk_container_add (GTK_CONTAINER (alignment1), hbox1);

  image2 = gtk_image_new_from_stock ("gtk-justify-center", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image2);
  gtk_box_pack_start (GTK_BOX (hbox1), image2, FALSE, FALSE, 0);

  label2 = gtk_label_new_with_mnemonic (_("afficher"));
  gtk_widget_show (label2);
  gtk_box_pack_start (GTK_BOX (hbox1), label2, FALSE, FALSE, 0);

  MBbuttonajout = gtk_button_new ();
  gtk_widget_show (MBbuttonajout);
  gtk_fixed_put (GTK_FIXED (fixed1), MBbuttonajout, 192, 408);
  gtk_widget_set_size_request (MBbuttonajout, 88, 29);

  alignment2 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_show (alignment2);
  gtk_container_add (GTK_CONTAINER (MBbuttonajout), alignment2);

  hbox2 = gtk_hbox_new (FALSE, 2);
  gtk_widget_show (hbox2);
  gtk_container_add (GTK_CONTAINER (alignment2), hbox2);

  image3 = gtk_image_new_from_stock ("gtk-add", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image3);
  gtk_box_pack_start (GTK_BOX (hbox2), image3, FALSE, FALSE, 0);

  label3 = gtk_label_new_with_mnemonic (_("ajouter"));
  gtk_widget_show (label3);
  gtk_box_pack_start (GTK_BOX (hbox2), label3, FALSE, FALSE, 0);

  MBbuttonsupprim = gtk_button_new ();
  gtk_widget_show (MBbuttonsupprim);
  gtk_fixed_put (GTK_FIXED (fixed1), MBbuttonsupprim, 296, 408);
  gtk_widget_set_size_request (MBbuttonsupprim, 104, 29);

  alignment3 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_show (alignment3);
  gtk_container_add (GTK_CONTAINER (MBbuttonsupprim), alignment3);

  hbox3 = gtk_hbox_new (FALSE, 2);
  gtk_widget_show (hbox3);
  gtk_container_add (GTK_CONTAINER (alignment3), hbox3);

  image4 = gtk_image_new_from_stock ("gtk-delete", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image4);
  gtk_box_pack_start (GTK_BOX (hbox3), image4, FALSE, FALSE, 0);

  label4 = gtk_label_new_with_mnemonic (_("supprimer"));
  gtk_widget_show (label4);
  gtk_box_pack_start (GTK_BOX (hbox3), label4, FALSE, FALSE, 0);

  _ = gtk_label_new (_("Afficher :"));
  gtk_widget_show (_);
  gtk_fixed_put (GTK_FIXED (fixed1), _, 424, 32);
  gtk_widget_set_size_request (_, 128, 25);

  MBcheckmois = gtk_check_button_new_with_mnemonic (_("Moissonneuse"));
  gtk_widget_show (MBcheckmois);
  gtk_fixed_put (GTK_FIXED (fixed1), MBcheckmois, 448, 80);
  gtk_widget_set_size_request (MBcheckmois, 128, 24);

  MBcheckcheni = gtk_check_button_new_with_mnemonic (_("Chenille agricole"));
  gtk_widget_show (MBcheckcheni);
  gtk_fixed_put (GTK_FIXED (fixed1), MBcheckcheni, 584, 80);
  gtk_widget_set_size_request (MBcheckcheni, 152, 24);

  MBcheckchar = gtk_check_button_new_with_mnemonic (_("Charrure a disques"));
  gtk_widget_show (MBcheckchar);
  gtk_fixed_put (GTK_FIXED (fixed1), MBcheckchar, 728, 80);
  gtk_widget_set_size_request (MBcheckchar, 152, 24);

  MBchecktrac = gtk_check_button_new_with_mnemonic (_("Tracteur"));
  gtk_widget_show (MBchecktrac);
  gtk_fixed_put (GTK_FIXED (fixed1), MBchecktrac, 888, 80);
  gtk_widget_set_size_request (MBchecktrac, 88, 24);

  MBbuttonmodif = gtk_button_new ();
  gtk_widget_show (MBbuttonmodif);
  gtk_fixed_put (GTK_FIXED (fixed1), MBbuttonmodif, 424, 408);
  gtk_widget_set_size_request (MBbuttonmodif, 96, 32);

  alignment4 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_show (alignment4);
  gtk_container_add (GTK_CONTAINER (MBbuttonmodif), alignment4);

  hbox4 = gtk_hbox_new (FALSE, 2);
  gtk_widget_show (hbox4);
  gtk_container_add (GTK_CONTAINER (alignment4), hbox4);

  image5 = gtk_image_new_from_stock ("gtk-edit", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image5);
  gtk_box_pack_start (GTK_BOX (hbox4), image5, FALSE, FALSE, 0);

  label5 = gtk_label_new_with_mnemonic (_("modifier"));
  gtk_widget_show (label5);
  gtk_box_pack_start (GTK_BOX (hbox4), label5, FALSE, FALSE, 0);

  g_signal_connect ((gpointer) button1, "clicked",
                    G_CALLBACK (on_button1_clicked),
                    NULL);
  g_signal_connect ((gpointer) MBbuttonaffich, "clicked",
                    G_CALLBACK (on_MBbuttonaffich_clicked),
                    NULL);
  g_signal_connect ((gpointer) MBbuttonajout, "clicked",
                    G_CALLBACK (on_MBbuttonajout_clicked),
                    NULL);
  g_signal_connect ((gpointer) MBbuttonsupprim, "clicked",
                    G_CALLBACK (on_MBbuttonsupprim_clicked),
                    NULL);
  g_signal_connect ((gpointer) MBbuttonmodif, "clicked",
                    G_CALLBACK (on_MBbuttonmodif_clicked),
                    NULL);

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (MBcrud, MBcrud, "MBcrud");
  GLADE_HOOKUP_OBJECT (MBcrud, fixed1, "fixed1");
  GLADE_HOOKUP_OBJECT (MBcrud, treeview1, "treeview1");
  GLADE_HOOKUP_OBJECT (MBcrud, entry1, "entry1");
  GLADE_HOOKUP_OBJECT (MBcrud, label1, "label1");
  GLADE_HOOKUP_OBJECT (MBcrud, button1, "button1");
  GLADE_HOOKUP_OBJECT (MBcrud, image1, "image1");
  GLADE_HOOKUP_OBJECT (MBcrud, MBbuttonaffich, "MBbuttonaffich");
  GLADE_HOOKUP_OBJECT (MBcrud, alignment1, "alignment1");
  GLADE_HOOKUP_OBJECT (MBcrud, hbox1, "hbox1");
  GLADE_HOOKUP_OBJECT (MBcrud, image2, "image2");
  GLADE_HOOKUP_OBJECT (MBcrud, label2, "label2");
  GLADE_HOOKUP_OBJECT (MBcrud, MBbuttonajout, "MBbuttonajout");
  GLADE_HOOKUP_OBJECT (MBcrud, alignment2, "alignment2");
  GLADE_HOOKUP_OBJECT (MBcrud, hbox2, "hbox2");
  GLADE_HOOKUP_OBJECT (MBcrud, image3, "image3");
  GLADE_HOOKUP_OBJECT (MBcrud, label3, "label3");
  GLADE_HOOKUP_OBJECT (MBcrud, MBbuttonsupprim, "MBbuttonsupprim");
  GLADE_HOOKUP_OBJECT (MBcrud, alignment3, "alignment3");
  GLADE_HOOKUP_OBJECT (MBcrud, hbox3, "hbox3");
  GLADE_HOOKUP_OBJECT (MBcrud, image4, "image4");
  GLADE_HOOKUP_OBJECT (MBcrud, label4, "label4");
  GLADE_HOOKUP_OBJECT (MBcrud, _, "_");
  GLADE_HOOKUP_OBJECT (MBcrud, MBcheckmois, "MBcheckmois");
  GLADE_HOOKUP_OBJECT (MBcrud, MBcheckcheni, "MBcheckcheni");
  GLADE_HOOKUP_OBJECT (MBcrud, MBcheckchar, "MBcheckchar");
  GLADE_HOOKUP_OBJECT (MBcrud, MBchecktrac, "MBchecktrac");
  GLADE_HOOKUP_OBJECT (MBcrud, MBbuttonmodif, "MBbuttonmodif");
  GLADE_HOOKUP_OBJECT (MBcrud, alignment4, "alignment4");
  GLADE_HOOKUP_OBJECT (MBcrud, hbox4, "hbox4");
  GLADE_HOOKUP_OBJECT (MBcrud, image5, "image5");
  GLADE_HOOKUP_OBJECT (MBcrud, label5, "label5");

  return MBcrud;
}

GtkWidget*
create_MBajout (void)
{
  GtkWidget *MBajout;
  GtkWidget *fixed2;
  GtkWidget *MBentrypuissancefis;
  GtkObject *MBspinannee_adj;
  GtkWidget *MBspinannee;
  GtkWidget *MBentrymat1;
  GtkObject *MBspinjour_adj;
  GtkWidget *MBspinjour;
  GtkObject *MBspinmois_adj;
  GtkWidget *MBspinmois;
  GtkObject *MBspinanneee_adj;
  GtkWidget *MBspinanneee;
  GtkObject *MBspinjour2_adj;
  GtkWidget *MBspinjour2;
  GtkObject *MBspinmois2_adj;
  GtkWidget *MBspinmois2;
  GtkObject *MBspinanneee2_adj;
  GtkWidget *MBspinanneee2;
  GtkWidget *_;
  GtkWidget *MBcombotracteur;
  GtkWidget *label7;
  GtkWidget *MBradiojhon;
  GSList *MBradiojhon_group = NULL;
  GtkWidget *MBradiorenault;
  GtkWidget *MBradiosomeca;
  GtkWidget *MBradiofordoson;
  GtkWidget *label8;
  GtkWidget *label9;
  GtkWidget *label10;
  GtkWidget *label11;
  GtkWidget *label12;
  GtkWidget *label13;
  GtkWidget *MBbuttonenregistrer;
  GtkWidget *alignment5;
  GtkWidget *hbox5;
  GtkWidget *image6;
  GtkWidget *label14;
  GtkWidget *buttonmat;
  GtkWidget *image7;
  GtkWidget *MBradiofiat;

  MBajout = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (MBajout), _("Ajouter un nouvel equipement"));

  fixed2 = gtk_fixed_new ();
  gtk_widget_show (fixed2);
  gtk_container_add (GTK_CONTAINER (MBajout), fixed2);

  MBentrypuissancefis = gtk_entry_new ();
  gtk_widget_show (MBentrypuissancefis);
  gtk_fixed_put (GTK_FIXED (fixed2), MBentrypuissancefis, 184, 208);
  gtk_widget_set_size_request (MBentrypuissancefis, 56, 24);
  gtk_entry_set_invisible_char (GTK_ENTRY (MBentrypuissancefis), 8226);

  MBspinannee_adj = gtk_adjustment_new (2020, 2020, 2030, 1, 10, 10);
  MBspinannee = gtk_spin_button_new (GTK_ADJUSTMENT (MBspinannee_adj), 1, 0);
  gtk_widget_show (MBspinannee);
  gtk_fixed_put (GTK_FIXED (fixed2), MBspinannee, 128, 264);
  gtk_widget_set_size_request (MBspinannee, 60, 27);

  MBentrymat1 = gtk_entry_new ();
  gtk_widget_show (MBentrymat1);
  gtk_fixed_put (GTK_FIXED (fixed2), MBentrymat1, 120, 328);
  gtk_widget_set_size_request (MBentrymat1, 112, 27);
  gtk_entry_set_invisible_char (GTK_ENTRY (MBentrymat1), 8226);

  MBspinjour_adj = gtk_adjustment_new (1, 1, 31, 1, 10, 10);
  MBspinjour = gtk_spin_button_new (GTK_ADJUSTMENT (MBspinjour_adj), 1, 0);
  gtk_widget_show (MBspinjour);
  gtk_fixed_put (GTK_FIXED (fixed2), MBspinjour, 224, 392);
  gtk_widget_set_size_request (MBspinjour, 60, 27);

  MBspinmois_adj = gtk_adjustment_new (1, 1, 12, 1, 10, 10);
  MBspinmois = gtk_spin_button_new (GTK_ADJUSTMENT (MBspinmois_adj), 1, 0);
  gtk_widget_show (MBspinmois);
  gtk_fixed_put (GTK_FIXED (fixed2), MBspinmois, 312, 392);
  gtk_widget_set_size_request (MBspinmois, 60, 27);

  MBspinanneee_adj = gtk_adjustment_new (2020, 2020, 2030, 1, 10, 10);
  MBspinanneee = gtk_spin_button_new (GTK_ADJUSTMENT (MBspinanneee_adj), 1, 0);
  gtk_widget_show (MBspinanneee);
  gtk_fixed_put (GTK_FIXED (fixed2), MBspinanneee, 392, 392);
  gtk_widget_set_size_request (MBspinanneee, 60, 27);

  MBspinjour2_adj = gtk_adjustment_new (1, 1, 31, 1, 10, 10);
  MBspinjour2 = gtk_spin_button_new (GTK_ADJUSTMENT (MBspinjour2_adj), 1, 0);
  gtk_widget_show (MBspinjour2);
  gtk_fixed_put (GTK_FIXED (fixed2), MBspinjour2, 232, 456);
  gtk_widget_set_size_request (MBspinjour2, 60, 27);

  MBspinmois2_adj = gtk_adjustment_new (1, 1, 12, 1, 10, 10);
  MBspinmois2 = gtk_spin_button_new (GTK_ADJUSTMENT (MBspinmois2_adj), 1, 0);
  gtk_widget_show (MBspinmois2);
  gtk_fixed_put (GTK_FIXED (fixed2), MBspinmois2, 320, 456);
  gtk_widget_set_size_request (MBspinmois2, 60, 27);

  MBspinanneee2_adj = gtk_adjustment_new (2020, 2020, 2030, 1, 10, 10);
  MBspinanneee2 = gtk_spin_button_new (GTK_ADJUSTMENT (MBspinanneee2_adj), 1, 0);
  gtk_widget_show (MBspinanneee2);
  gtk_fixed_put (GTK_FIXED (fixed2), MBspinanneee2, 408, 456);
  gtk_widget_set_size_request (MBspinanneee2, 60, 27);

  _ = gtk_label_new (_("Type: "));
  gtk_widget_show (_);
  gtk_fixed_put (GTK_FIXED (fixed2), _, 40, 56);
  gtk_widget_set_size_request (_, 80, 24);

  MBcombotracteur = gtk_combo_box_entry_new_text ();
  gtk_widget_show (MBcombotracteur);
  gtk_fixed_put (GTK_FIXED (fixed2), MBcombotracteur, 144, 56);
  gtk_widget_set_size_request (MBcombotracteur, 189, 29);
  gtk_combo_box_append_text (GTK_COMBO_BOX (MBcombotracteur), _("tracteur"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (MBcombotracteur), _("charrure a disques"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (MBcombotracteur), _("chenille agricole"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (MBcombotracteur), _("moissonneuse"));

  label7 = gtk_label_new (_("Marque :"));
  gtk_widget_show (label7);
  gtk_fixed_put (GTK_FIXED (fixed2), label7, 40, 112);
  gtk_widget_set_size_request (label7, 96, 17);

  MBradiojhon = gtk_radio_button_new_with_mnemonic (NULL, _("JHON DEERE"));
  gtk_widget_show (MBradiojhon);
  gtk_fixed_put (GTK_FIXED (fixed2), MBradiojhon, 64, 152);
  gtk_widget_set_size_request (MBradiojhon, 116, 24);
  gtk_radio_button_set_group (GTK_RADIO_BUTTON (MBradiojhon), MBradiojhon_group);
  MBradiojhon_group = gtk_radio_button_get_group (GTK_RADIO_BUTTON (MBradiojhon));

  MBradiorenault = gtk_radio_button_new_with_mnemonic (NULL, _("RENAULT"));
  gtk_widget_show (MBradiorenault);
  gtk_fixed_put (GTK_FIXED (fixed2), MBradiorenault, 208, 152);
  gtk_widget_set_size_request (MBradiorenault, 116, 24);
  gtk_radio_button_set_group (GTK_RADIO_BUTTON (MBradiorenault), MBradiojhon_group);
  MBradiojhon_group = gtk_radio_button_get_group (GTK_RADIO_BUTTON (MBradiorenault));

  MBradiosomeca = gtk_radio_button_new_with_mnemonic (NULL, _("SOMECA"));
  gtk_widget_show (MBradiosomeca);
  gtk_fixed_put (GTK_FIXED (fixed2), MBradiosomeca, 352, 152);
  gtk_widget_set_size_request (MBradiosomeca, 116, 24);
  gtk_radio_button_set_group (GTK_RADIO_BUTTON (MBradiosomeca), MBradiojhon_group);
  MBradiojhon_group = gtk_radio_button_get_group (GTK_RADIO_BUTTON (MBradiosomeca));

  MBradiofordoson = gtk_radio_button_new_with_mnemonic (NULL, _("FORDOSON"));
  gtk_widget_show (MBradiofordoson);
  gtk_fixed_put (GTK_FIXED (fixed2), MBradiofordoson, 504, 152);
  gtk_widget_set_size_request (MBradiofordoson, 116, 24);
  gtk_radio_button_set_group (GTK_RADIO_BUTTON (MBradiofordoson), MBradiojhon_group);
  MBradiojhon_group = gtk_radio_button_get_group (GTK_RADIO_BUTTON (MBradiofordoson));

  label8 = gtk_label_new (_("Puissance fiscale :"));
  gtk_widget_show (label8);
  gtk_fixed_put (GTK_FIXED (fixed2), label8, 40, 208);
  gtk_widget_set_size_request (label8, 144, 17);

  label9 = gtk_label_new (_("CV"));
  gtk_widget_show (label9);
  gtk_fixed_put (GTK_FIXED (fixed2), label9, 248, 216);
  gtk_widget_set_size_request (label9, 41, 17);

  label10 = gtk_label_new (_("Annee :"));
  gtk_widget_show (label10);
  gtk_fixed_put (GTK_FIXED (fixed2), label10, 40, 272);
  gtk_widget_set_size_request (label10, 49, 17);

  label11 = gtk_label_new (_("Matricule :"));
  gtk_widget_show (label11);
  gtk_fixed_put (GTK_FIXED (fixed2), label11, 24, 336);
  gtk_widget_set_size_request (label11, 88, 17);

  label12 = gtk_label_new (_("Date prochaine visite :"));
  gtk_widget_show (label12);
  gtk_fixed_put (GTK_FIXED (fixed2), label12, 0, 400);
  gtk_widget_set_size_request (label12, 232, 17);

  label13 = gtk_label_new (_("Date prochain entretien :"));
  gtk_widget_show (label13);
  gtk_fixed_put (GTK_FIXED (fixed2), label13, 24, 464);
  gtk_widget_set_size_request (label13, 184, 16);

  MBbuttonenregistrer = gtk_button_new ();
  gtk_widget_show (MBbuttonenregistrer);
  gtk_fixed_put (GTK_FIXED (fixed2), MBbuttonenregistrer, 704, 496);
  gtk_widget_set_size_request (MBbuttonenregistrer, 128, 29);

  alignment5 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_show (alignment5);
  gtk_container_add (GTK_CONTAINER (MBbuttonenregistrer), alignment5);

  hbox5 = gtk_hbox_new (FALSE, 2);
  gtk_widget_show (hbox5);
  gtk_container_add (GTK_CONTAINER (alignment5), hbox5);

  image6 = gtk_image_new_from_stock ("gtk-apply", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image6);
  gtk_box_pack_start (GTK_BOX (hbox5), image6, FALSE, FALSE, 0);

  label14 = gtk_label_new_with_mnemonic (_("Enregistrer"));
  gtk_widget_show (label14);
  gtk_box_pack_start (GTK_BOX (hbox5), label14, FALSE, FALSE, 0);

  buttonmat = gtk_button_new ();
  gtk_widget_show (buttonmat);
  gtk_fixed_put (GTK_FIXED (fixed2), buttonmat, 240, 328);
  gtk_widget_set_size_request (buttonmat, 32, 29);

  image7 = gtk_image_new_from_stock ("gtk-find", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image7);
  gtk_container_add (GTK_CONTAINER (buttonmat), image7);

  MBradiofiat = gtk_radio_button_new_with_mnemonic (NULL, _("FIAT"));
  gtk_widget_show (MBradiofiat);
  gtk_fixed_put (GTK_FIXED (fixed2), MBradiofiat, 664, 152);
  gtk_widget_set_size_request (MBradiofiat, 116, 24);
  gtk_radio_button_set_group (GTK_RADIO_BUTTON (MBradiofiat), MBradiojhon_group);
  MBradiojhon_group = gtk_radio_button_get_group (GTK_RADIO_BUTTON (MBradiofiat));

  g_signal_connect ((gpointer) MBbuttonenregistrer, "clicked",
                    G_CALLBACK (on_MBbuttonenregistrer_clicked),
                    NULL);
  g_signal_connect ((gpointer) buttonmat, "clicked",
                    G_CALLBACK (on_buttonmat_clicked),
                    NULL);

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (MBajout, MBajout, "MBajout");
  GLADE_HOOKUP_OBJECT (MBajout, fixed2, "fixed2");
  GLADE_HOOKUP_OBJECT (MBajout, MBentrypuissancefis, "MBentrypuissancefis");
  GLADE_HOOKUP_OBJECT (MBajout, MBspinannee, "MBspinannee");
  GLADE_HOOKUP_OBJECT (MBajout, MBentrymat1, "MBentrymat1");
  GLADE_HOOKUP_OBJECT (MBajout, MBspinjour, "MBspinjour");
  GLADE_HOOKUP_OBJECT (MBajout, MBspinmois, "MBspinmois");
  GLADE_HOOKUP_OBJECT (MBajout, MBspinanneee, "MBspinanneee");
  GLADE_HOOKUP_OBJECT (MBajout, MBspinjour2, "MBspinjour2");
  GLADE_HOOKUP_OBJECT (MBajout, MBspinmois2, "MBspinmois2");
  GLADE_HOOKUP_OBJECT (MBajout, MBspinanneee2, "MBspinanneee2");
  GLADE_HOOKUP_OBJECT (MBajout, _, "_");
  GLADE_HOOKUP_OBJECT (MBajout, MBcombotracteur, "MBcombotracteur");
  GLADE_HOOKUP_OBJECT (MBajout, label7, "label7");
  GLADE_HOOKUP_OBJECT (MBajout, MBradiojhon, "MBradiojhon");
  GLADE_HOOKUP_OBJECT (MBajout, MBradiorenault, "MBradiorenault");
  GLADE_HOOKUP_OBJECT (MBajout, MBradiosomeca, "MBradiosomeca");
  GLADE_HOOKUP_OBJECT (MBajout, MBradiofordoson, "MBradiofordoson");
  GLADE_HOOKUP_OBJECT (MBajout, label8, "label8");
  GLADE_HOOKUP_OBJECT (MBajout, label9, "label9");
  GLADE_HOOKUP_OBJECT (MBajout, label10, "label10");
  GLADE_HOOKUP_OBJECT (MBajout, label11, "label11");
  GLADE_HOOKUP_OBJECT (MBajout, label12, "label12");
  GLADE_HOOKUP_OBJECT (MBajout, label13, "label13");
  GLADE_HOOKUP_OBJECT (MBajout, MBbuttonenregistrer, "MBbuttonenregistrer");
  GLADE_HOOKUP_OBJECT (MBajout, alignment5, "alignment5");
  GLADE_HOOKUP_OBJECT (MBajout, hbox5, "hbox5");
  GLADE_HOOKUP_OBJECT (MBajout, image6, "image6");
  GLADE_HOOKUP_OBJECT (MBajout, label14, "label14");
  GLADE_HOOKUP_OBJECT (MBajout, buttonmat, "buttonmat");
  GLADE_HOOKUP_OBJECT (MBajout, image7, "image7");
  GLADE_HOOKUP_OBJECT (MBajout, MBradiofiat, "MBradiofiat");

  return MBajout;
}
