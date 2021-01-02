#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include <string.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "liste_ouvriers.h"

int y=1;
int choix[]={0,0};

void
on_Ajouter_ouvrier_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{

ouvrier o;

GtkWidget *Nom_ouvrier, *Prenom_ouvrier, *Date_de_naissance_ouvrier, *adresse_mail_ouvrier, *CIN_ouvrier, *Numero_de_tel_ouvrier;
GtkWidget *ajouter_ouvrier;

fenetre_ajout=lookup_widget(objet, "ajouter_ouvrier");
Nom_ouvrier=lookup_widget(objet,"Nom_ouvrier");
Prenom_ouvrier=lookup_widget(objet,"Prenom_ouvrier");
Date_de_naissance_ouvrier=lookup_widget(objet,"Date_de_naissance_ouvrier");
adresse_mail_ouvrier=lookup_widget(objet,"adresse_mail_ouvrier");
CIN_ouvrier=lookup_widget(objet,"CIN_ouvrier");
Numero_de_tel_ouvrier=lookup_widget(objet,"Numero_de_tel_ouvrier");


strcpy(o.Nom,gtk_entry_get_text(GTK_ENTRY(Nom_ouvrier)));
strcpy(o.Prenom,gtk_entry_get_text(GTK_ENTRY(Prenom_ouvrier)));
strcpy(o.Date_de_naissance,gtk_entry_get_text(GTK_ENTRY(Date_de_naissance_ouvrier)));
strcpy(o.adresse_mail,gtk_entry_get_text(GTK_ENTRY(adresse_mail_ouvrier)));
strcpy(o.CIN,gtk_entry_get_text(GTK_ENTRY(CIN_ouvrier)));
strcpy(o.Numero_de_tel,gtk_entry_get_text(GTK_ENTRY(Numero_de_tel_ouvrier)));

ajouter_ouvrier(o);
}


void
on_Afficher_liste_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *ajouter_ouvrier;
GtkWidget *liste_des_ouvriers;
GtkWidget *treeview1;

ajouter_ouvrier = lookup_widget(objet,"ajouter_ouvrier");

gtk_widget_destroy(Ajouter_ouvrier);
liste_des_ouvriers=lookup_widget(objet,"liste_des_ouvriers");
liste_des_ouvriers=create_liste_des_ouvriers();

gtk_widget_show(liste_des_ouvriers);

treeview1=lookup_widget(liste_des_ouvriers,"treeview1");

afficher_ouvrier(treeview1);
GtkWidget *ajouter_ouvrier;
GtkWidget *liste_des_ouvriers;
GtkWidget *treeview1;

ajouter_ouvrier=lookup_widget(objet,"ajouter_ouvrier");

gtk_widget_destroy(ajouter_ouvrier);
liste_des_ouvriers=lookup_widget(objet,"liste_des_ouvriers");
liste_des_ouvriers=create_liste_des_ouvriers();

gtk_widget_show(liste_des_ouvriers);

treeview1=lookup_widget(liste_des_ouvriers,"treeview1");
afficher_ouvrier(treeview1);

}


void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
    
	GtkTreeIter iter;
	gchar* Nom;
	gchar* Prenom;
	gchar* Date_de_naissance;
	gchar* adresse_mail;
	gchar* CIN;
	gchar* Numero_de_tel;
	ouvrier o;

	GtkTreeModel *model = gtk_tree_view_get_model(treeview);

	if (gtk_tree_model_get_iter(model, &iter, path))

	{
		gtk_tree_model_get (GTK_LIST_STORE(model), &iter, 0, &Nom, 1, &Prenom, 2, &Date_de_naissance, 3, &adresse_mail, 4, &CIN, 5, &Numero_de_tel, -1);
		//obtention des valeurs de la ligne selectionnée

		strcpy(o.Nom,Nom);
		strcpy(o.Prenom,Prenom);
		strcpy(o.Date_de_naissance,Date_de_naissance);
		strcpy(o.adresse_mail,adresse_mail);
		strcpy(o.CIN,CIN);
		strcpy(o.Numero_de_tel,Numero_de_tel);
		//appael de la fct suppr
		supprimer_ouvrier(o);
		//mise à jour de l'affichage de la treeview
		afficher_ouvrier(treeview);
	}




}


void
on_retour_clicked                      (GtkWidget      *objet,
                                        gpointer         user_data)
{

	GtkWidget *ajouter_ouvrier, *liste_des_ouvriers;
	liste_des_ouvriers=lookup_widget(objet, "liste_des_ouvriers");

	gtk_widget_destroy(liste_des_ouvriers);
	ajouter_ouvrier=create_ajouter_ouvrier();
	gtk_widget_show(ajouter_ouvrier);

}

void
on_Pointage_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *Pointage_ouvrier, *liste_des_ouvriers;
	liste_des_ouvriers=lookup_widget(objet, "liste_des_ouvriers");

	gtk_widget_destroy(liste_des_ouvriers);
	Pointage_ouvrier=create_Pointage_ouvrier();
	gtk_widget_show(Pointage_ouvrier);
}


void
on_RetourP_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *Pointage_ouvrier, *liste_des_ouvriers;
	Pointage_ouvrier=lookup_widget(objet, "Pointage_ouvrier");

	gtk_widget_destroy(Pointage_ouvrier);
	liste_des_ouvriers=create_liste_des_ouvriers();
	gtk_widget_show(liste_des_ouvriers);
}


void
on_Rechercher_ouvrier_clicked          (GtkWidget       *button,
                                        gpointer         user_data)
{
ouvrier o ;
int r;
char texte[100];
char texte2[100];
GtkWidget *CIN_rech;
GtkWidget *Nv_Nom;
GtkWidget *Nv_Prenom;
GtkWidget *Nv_Date_de_naissance;
GtkWidget *Nv_adresse_mail;
GtkWidget *Nv_CIN;
GtkWidget *Nv_Numero_de_tel;


	CIN_rech = lookup_widget(objet_graphique,"CIN_rech");
	Nv_Nom = lookup_widget(objet_graphique,"Nv_Nom");
	Nv_Prenom = lookup_widget(objet_graphique,"Nv_Prenom");
	Nv_Date_de_naissance = lookup_widget(objet_graphique,"Nv_Date_de_naissance");
	Nv_adresse_mail = lookup_widget(objet_graphique,"Nv_adresse_mail");
	Nv_CIN = lookup_widget(objet_graphique,"Nv_CIN_ouvrier");
	Nv_Numero_de_tel = lookup_widget(objet_graphique,"Nv_Numero_de_tel");
	CIN_rech = lookup_widget(objet_graphique,"label_CIN_rech");
strcpy(texte,gtk_entry_get_text(GTK_ENTRY(input1)));
r= rechercher_CIN(texte);
if (r==0)
{
strcpy(texte2,"CIN NON DISPONIBLE");
gtk_label_set_text(GTK_LABEL(CIN_rech),texte2);
} 
else {
	strcpy(texte2,"CIN DISPONIBLE");
	gtk_label_set_text(GTK_LABEL(CIN_rech),texte2);	
	strcpy(o.Nom,rech_ouvrier(texte).Nom);
	strcpy(o.Prenom,rech_ouvrier(texte).Prenom);
	strcpy(o.Date_de_naissance,rech_ouvrier(texte).Date_de_naissance);
	strcpy(o.adresse_mail,rech_ouvrier(texte).adresse_mail);
	strcpy(o.CIN,rech_ouvrier(texte).CIN);
	strcpy(o.Numero_de_tel,rech_ouvrier(texte).Numero_de_tel);
	gtk_entry_set_text(GTK_ENTRY(Nv_Nom),o.Nom);
	gtk_entry_set_text(GTK_ENTRY(Nv_Prenom),o.Prenom);
	gtk_entry_set_text(GTK_ENTRY(Nv_Date_de_naissance),o.Date_de_naissance);
	gtk_entry_set_text(GTK_ENTRY(Nv_adresse_mail),o.adresse_mail);
	gtk_entry_set_text(GTK_ENTRY(Nv_CIN),o.CIN);
	gtk_entry_set_text(GTK_ENTRY(Nv_Numero_de_tel),o.Numero_de_tel);

}
}





void
on_Modifier_ouvrier_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{
ouvrier o;

GtkWidget *Nom_ouvrier, *Prenom_ouvrier, *Date_de_naissance_ouvrier, *adresse_mail_ouvrier, *CIN_ouvrier, *Numero_de_tel_ouvrier;
GtkWidget *ajouter_ouvrier;

modifier_ouvrier=lookup_widget(objet, "modifier_ouvrier");
Nom_ouvrier=lookup_widget(objet,"Nv_Nom");
Prenom_ouvrier=lookup_widget(objet,"Nv_Prenom");
Date_de_naissance_ouvrier=lookup_widget(objet,"Nv_Date_de_naissance");
adresse_mail_ouvrier=lookup_widget(objet,"Nv_adresse_mail");
CIN_ouvrier=lookup_widget(objet,"Nv_CIN");
Numero_de_tel_ouvrier=lookup_widget(objet,"Nv_Numero_de_tel");


strcpy(o.Nom,gtk_entry_get_text(GTK_ENTRY(Nom_ouvrier)));
strcpy(o.Prenom,gtk_entry_get_text(GTK_ENTRY(Prenom_ouvrier)));
strcpy(o.Date_de_naissance,gtk_entry_get_text(GTK_ENTRY(Date_de_naissance_ouvrier)));
strcpy(o.adresse_mail,gtk_entry_get_text(GTK_ENTRY(adresse_mail_ouvrier)));
strcpy(o.CIN,gtk_entry_get_text(GTK_ENTRY(CIN_ouvrier)));
strcpy(o.Numero_de_tel,gtk_entry_get_text(GTK_ENTRY(Numero_de_tel_ouvrier)));

modifier_ouvrier(o);
}


void
on_Retour_Modification_clicked         (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *Modifier_ouvrier, *Pointage_ouvrier;
	Modifier_ouvrier=lookup_widget(objet,"Modifier_ouvrier");

	gtk_widget_destroy(Modifier_ouvrier);
	Pointage_ouvrier=create_Pointage_ouvrier();
	gtk_widget_show(Pointage_ouvrier);
}


void
on_Non_attention_clicked               (GtkWidget       *button,
                                        gpointer         user_data)
{

}


void
on_Oui_attention_clicked               (GtkWidget       *button,
                                        gpointer         user_data)
{

}


void
on_supprimer_ouvrier_clicked           (GtkWidget       *button,
                                        gpointer         user_data)
{

}


void
on_OK_op_clicked                       (GtkWidget       *button,
                                        gpointer         user_data)
{

}


void
on_radiobuttonPresent_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{y=1;}
}


void
on_radiobuttonabsent_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{y=2;}
}


void
on_Okattention_clicked                 (GtkWidget       *button,
                                        gpointer         user_data)
{

}


void
on_checkbuttonnon_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{choix[0]=1;}
}


void
on_checkbuttonoui_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{choix[1]=1;}
}


void
on_Confirmer_p_clicked                 (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{


GtkWidget* spinbuttonanneepointage;
GtkWidget* Comboboxjourpointage;
GtkWidget* Comboboxmoispointage;
int jour_ab;
int mois_ab;


jour_ab=0;
mois_ab=0;
spinbuttonanneepointage = lookup_widget(objet_graphique,"annee");
Comboboxjourpointage = lookup_widget(objet_graphique,"comboboxjourpointage");
Comboboxmoispointage = lookup_widget(objet_graphique,"comboboxmoispointage");

spinbuttonanneepointage = gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (spinbuttonanneepointage));

if(strcmp("lundi",gtk_combo_box_get_active_text(GTK_COMBO_BOX(Comboboxjourpointage)))==0)
jour_ab=1;
else
	if(strcmp("Mardi",gtk_combo_box_get_active_text(GTK_COMBO_BOX(Comboboxjourpointage)))==0)
	{jour_ab=2;}
else
	if(strcmp("Mercredi",gtk_combo_box_get_active_text(GTK_COMBO_BOX(Comboboxjourpointage)))==0)
	{jour_ab=3;}
else
	if(strcmp("jeudi",gtk_combo_box_get_active_text(GTK_COMBO_BOX(Comboboxjourpointage)))==0)
	{jour_ab=4;}
else
	if(strcmp("vendredi",gtk_combo_box_get_active_text(GTK_COMBO_BOX(Comboboxjourpointage)))==0)
	{jour_ab=5;}
else
	if(strcmp("samedi",gtk_combo_box_get_active_text(GTK_COMBO_BOX(Comboboxjourpointage)))==0)
	{jour_ab=6;}


	if(strcmp("janvier",gtk_combo_box_get_active_text(GTK_COMBO_BOX(Comboboxmoispointage)))==0)
	{mois_ab=1;}
else
	if(strcmp("Février",gtk_combo_box_get_active_text(GTK_COMBO_BOX(Comboboxmoispointage)))==0)
	{mois_ab=2;}
else
	if(strcmp("Mars",gtk_combo_box_get_active_text(GTK_COMBO_BOX(Comboboxmoispointage)))==0)
	{mois_ab=3;}
else
	if(strcmp("Avril",gtk_combo_box_get_active_text(GTK_COMBO_BOX(Comboboxmoispointage)))==0)
	{mois_ab=4;}
else
	if(strcmp("Mai",gtk_combo_box_get_active_text(GTK_COMBO_BOX(Comboboxmoispointage)))==0)
	{mois_ab=5;}
else
	if(strcmp("juin",gtk_combo_box_get_active_text(GTK_COMBO_BOX(Comboboxmoispointage)))==0)
	{mois_ab=6;}
else
	if(strcmp("juillet",gtk_combo_box_get_active_text(GTK_COMBO_BOX(Comboboxmoispointage)))==0)
	{mois_ab=7;}
else
	if(strcmp("Aout",gtk_combo_box_get_active_text(GTK_COMBO_BOX(Comboboxmoispointage)))==0)
	{mois_ab=8;}
else
	if(strcmp("Septembre",gtk_combo_box_get_active_text(GTK_COMBO_BOX(Comboboxmoispointage)))==0)
	{mois_ab=9;}
	if(strcmp("Octobre",gtk_combo_box_get_active_text(GTK_COMBO_BOX(Comboboxmoispointage)))==0)
	{mois_ab=10;}
else
	if(strcmp("Novembre",gtk_combo_box_get_active_text(GTK_COMBO_BOX(Comboboxmoispointage)))==0)
	{mois_ab=11;}
else
	if(strcmp("Decembre",gtk_combo_box_get_active_text(GTK_COMBO_BOX(Comboboxmoispointage)))==0)
	{mois_ab=12;}

}


void
on_Supprimer_modification_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{

}



void
on_Modifier_liste_ouvrier_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *liste_des_ouvrier, *Modifier_ouvrier;
	Modifier_ouvrier=lookup_widget(objet,"Modifier_ouvrier");

	gtk_widget_destroy(liste_des_ouvrier);
	Modifier_ouvrier=create_Modifier_ouvrier();
	gtk_widget_show(Modifier_ouvrier);
}
}

