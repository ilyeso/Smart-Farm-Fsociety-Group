#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "LISTEVIEWAPPAREIL.h"
#include "reservation.h"
#include "panne.h"
int choix[]={0,0};
int y=1;

void
on_ButtonAfficher_liste_appareils_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *Ajouter_un_equipement;
GtkWidget *Afficher_la_liste_des_equipements;
GtkWidget *treeview1;

Ajouter_un_equipement=lookup_widget(objet,"Ajouter_un_equipement");

gtk_widget_destroy(Ajouter_un_equipement);
Afficher_la_liste_des_equipements=lookup_widget(objet,"Afficher_la_liste_des_equipements");
Afficher_la_liste_des_equipements=create_Afficher_la_liste_des_equipements();

gtk_widget_show(Afficher_la_liste_des_equipements);

treeview1=lookup_widget(Afficher_la_liste_des_equipements,"treeview1");
afficher_appareil(treeview1);
}


void
on_buttonRetour_liste_clicked          (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *Ajouter_un_equipement, *Afficher_la_liste_des_equipements;
Afficher_la_liste_des_equipements=lookup_widget(objet, "Afficher_la_liste_des_equipements");

gtk_widget_destroy(Afficher_la_liste_des_equipements);
Ajouter_un_equipement=create_Ajouter_un_equipement();
gtk_widget_show(Ajouter_un_equipement);
}


void
on_buttonValidation_de_reservation_clicked
                                        (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget* spinbuttonJOUR;
GtkWidget* spinbuttonMOIS;
GtkWidget* spinbuttonANNEE;
GtkWidget* comboboxheure_de_reservation;
GtkWidget* comboboxNOM_DES_ATELIERS;
GtkWidget* comboboxFiliere;

char num[10];
Date date_rsrv;
char NomAtelier[50];
int heure_rsrv;
int i,n;


spinbuttonJOUR = lookup_widget(objet_graphique,"Jour");
spinbuttonMOIS = lookup_widget(objet_graphique,"Mois");
spinbuttonANNEE = lookup_widget(objet_graphique,"Annee");
comboboxheure_de_reservation = lookup_widget(objet_graphique,"comboboxheure_de_reservation");
comboboxNOM_DES_ATELIERS = lookup_widget(objet_graphique,"comboboxNOM_DES_ATELIERS");
comboboxFiliere = lookup_widget(objet_graphique,"comboboxFiliere");

date_rsrv.Jour = gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (spinbuttonJOUR));
date_rsrv.Mois = gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (spinbuttonMOIS));
date_rsrv.Annee = gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (spinbuttonANNEE));

if(strcmp("8h==>12h",gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxheure_de_reservation)))==0)
heure_rsrv=1;
else
heure_rsrv=2;


//n= tab_atelier_dispo (NomAtelier,date_rsrv,heure_rsrv);

for(i=0;i<n;i++)
	{
  		gtk_combo_box_append_text(GTK_COMBO_BOX(comboboxNOM_DES_ATELIERS),(NomAtelier[i]));
	}
}


void
on_buttonsuivantwindow3_clicked        (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *Prenez_un_rendez_vous, *Afficher_la_liste_des_equipements;
Afficher_la_liste_des_equipements=lookup_widget(objet, "Afficher_la_liste_des_equipements");

gtk_widget_destroy(Afficher_la_liste_des_equipements);
Prenez_un_rendez_vous=create_Prenez_un_rendez_vous();
gtk_widget_show(Prenez_un_rendez_vous);
}


void
on_buttonConfirmer_clicked             (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget* spinbuttonJOUR;
GtkWidget* spinbuttonMOIS;
GtkWidget* spinbuttonANNEE;
GtkWidget* comboboxheure_de_reservation;
GtkWidget* comboboxNOM_DES_ATELIERS;
GtkWidget* comboboxFiliere;
reservationAtelier a;

comboboxheure_de_reservation = lookup_widget(objet_graphique,"comboboxheure_de_reservation");
spinbuttonJOUR = lookup_widget(objet_graphique,"jour");
spinbuttonMOIS = lookup_widget(objet_graphique,"mois");
spinbuttonANNEE = lookup_widget(objet_graphique,"annee");
comboboxNOM_DES_ATELIERS = lookup_widget(objet_graphique,"comboboxNOM_DES_ATELIERS");
comboboxFiliere = lookup_widget(objet_graphique,"comboboxFiliere");
a.date_rsrv.Jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (spinbuttonJOUR));
a.date_rsrv.Mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (spinbuttonMOIS));
a.date_rsrv.Annee = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (spinbuttonANNEE));
if(strcmp("8h==>12h",gtk_combo_box_get_active_text(GTK_COMBO_BOX (comboboxheure_de_reservation)))==0)
a.heure_rsrv=1;
else
a.heure_rsrv=2;
strcpy(a.num,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxFiliere)));
//reserver_atelier(a);
}


void
on_buttonconfirmationfinale_clicked    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
char texte[100]="";
GtkWidget* output;
output = lookup_widget(objet_graphique,"label2");
Resultat(choix,texte);
gtk_label_set_text(GTK_LABEL(output),texte);
}


void
on_checkbuttonNon_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{choix[1]=1;}
}


void
on_checkbuttonoui_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{choix[0]=1;}
}


void
on_radiobuttonPanneinterne_toggled     (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{y=2;}
}


void
on_radiobuttonPanneexterne_toggled     (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{y=1;}
}


void
on_buttonRETOUR_WINDOW4_clicked        (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *Ajouter_un_equipement, *Verifiez_letat_de_lequipement;
Verifiez_letat_de_lequipement=lookup_widget(objet, "Verifiez_letat_de_lequipement");

gtk_widget_destroy(Verifiez_letat_de_lequipement);
Ajouter_un_equipement=create_Ajouter_un_equipement();
gtk_widget_show(Ajouter_un_equipement);
}


void
on_buttonsuppressionwindow7_clicked    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *Modification_ou_suppression, *Alerte;
Modification_ou_suppression=lookup_widget(objet, "Modification_ou_suppression");

gtk_widget_destroy(Modification_ou_suppression);
Alerte=create_Alerte();
gtk_widget_show(Alerte);
}


void
on_buttonmodifierwindow7_clicked       (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *Ajouter_un_equipement;
	GtkWidget *Modification_ou_suppression;
	Ajouter_un_equipement = lookup_widget(objet,"Ajouter_un_equipement");
	Modification_ou_suppression = create_Modification_ou_suppression();
	gtk_widget_destroy(Ajouter_un_equipement);
	gtk_widget_show(Modification_ou_suppression);
}


void
on_buttonrecherchewindow7_clicked      (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
appareil a;
int r;
char texte[100];
char texte2[100];
GtkWidget *nouv_id_appareil;
GtkWidget *nouv_nom_appareil;
GtkWidget *nouv_etat_appareil;
GtkWidget *nouv_date_achat_appareil;
GtkWidget *id_rech;

	nouv_id_appareil = lookup_widget(objet_graphique,"nouv_id_appareil");
	nouv_nom_appareil = lookup_widget(objet_graphique,"nouv_nom_appareil");
	nouv_etat_appareil = lookup_widget(objet_graphique,"nouv_etat_appareil");
	nouv_date_achat_appareil = lookup_widget(objet_graphique,"nouv_date_achat_appareil");
	id_rech = lookup_widget(objet_graphique,"id_rech");
strcpy(texte,gtk_entry_get_text(GTK_ENTRY(nouv_id_appareil)));
r= rechercher_appareil(texte);
if (r==0)
{
strcpy(texte2,"id non trouvé");
gtk_label_set_text(GTK_LABEL(id_rech),texte2);
} 
else {
	strcpy(texte2,"id trouvé");
	gtk_label_set_text(GTK_LABEL(id_rech),texte2);	
	strcpy(a.id,find_appareil(texte).id);
	strcpy(a.nom,find_appareil(texte).nom);
	strcpy(a.etat,find_appareil(texte).etat);
	strcpy(a.dateachat,find_appareil(texte).dateachat);
	gtk_entry_set_text(GTK_ENTRY(nouv_id_appareil),a.id);
	gtk_entry_set_text(GTK_ENTRY(nouv_nom_appareil),a.nom);
	gtk_entry_set_text(GTK_ENTRY(nouv_etat_appareil),a.etat);
	gtk_entry_set_text(GTK_ENTRY(nouv_date_achat_appareil),a.dateachat);
	
}
}


void
on_buttonsuppressionwindow8_clicked    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *input1;
GtkWidget *output1;           
	appareil a;
	char id[50];
	char resultat[50];

 	input1=lookup_widget (objet_graphique,"entry5");          
 	output1 = lookup_widget(objet_graphique, "labelID");

	strcpy (resultat,"cet appareil n'existe pas");
 
        strcpy(id,gtk_entry_get_text (GTK_ENTRY(input1)));
       
	supprimer_appareil(a);
	gtk_label_set_text(GTK_LABEL(output1),resultat);
}


void
on_buttonAjouter_appareil_clicked      (GtkWidget       *objet,
                                        gpointer         user_data)
{
appareil a;

GtkWidget *id_appareil;
GtkWidget *nom_appareil;
GtkWidget *etat_appareil;
GtkWidget *date_achat_appareil;
GtkWidget *Ajouter_un_equipement;

Ajouter_un_equipement=lookup_widget(objet,"Ajouter_un_equipement");

id_appareil=lookup_widget(objet,"id_appareil");
nom_appareil=lookup_widget(objet,"nom_appareil");
etat_appareil=lookup_widget(objet,"etat_appareil");
date_achat_appareil=lookup_widget(objet,"date_achat_appareil");

strcpy(a.id,gtk_entry_get_text(GTK_ENTRY(id_appareil)));
strcpy(a.nom,gtk_entry_get_text(GTK_ENTRY(nom_appareil)));
strcpy(a.etat,gtk_entry_get_text(GTK_ENTRY(etat_appareil)));
strcpy(a.dateachat,gtk_entry_get_text(GTK_ENTRY(date_achat_appareil)));
ajouter_appareil(a);
}


void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
	gchar* id;
	gchar* nom;
	gchar* etat;
	gchar* dateachat;
	appareil a;

	GtkTreeModel *model = gtk_tree_view_get_model(treeview);

	if (gtk_tree_model_get_iter(model, &iter, path))
	{
		//obtention des valeurs de la ligne selectionnée
		gtk_tree_model_get (GTK_LIST_STORE (model) , &iter, 0, &id, 1, &nom, 2, &etat, 3,  &dateachat,4,-1);	
		strcpy(a.id,id);
		strcpy(a.nom,nom);
		strcpy(a.etat,etat);
		strcpy(a.dateachat,dateachat);
		//appel de la fonction de suppression 
		supprimer_appareil(a);
		//mise à jour de l'affichage de la treeview
		afficher_appareil(treeview);
	}
}


void
on_buttonmodifierousupprimerappareil_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *Afficher_la_liste_des_equipements, *Modification_ou_suppression;
Afficher_la_liste_des_equipements=lookup_widget(objet, "Afficher_la_liste_des_equipements");

gtk_widget_destroy(Afficher_la_liste_des_equipements);
Modification_ou_suppression=create_Modification_ou_suppression();
gtk_widget_show(Modification_ou_suppression);
}

