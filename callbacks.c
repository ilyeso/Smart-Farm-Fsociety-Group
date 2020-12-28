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

void
on_buttonAjouter_appareil_clicked      (GtkWidget       *objet,
                                        gpointer         user_data)
{
appareil a;

GtkWidget *input1, *input2, *input3, *input4;
GtkWidget *fenetre_ajouter;

fenetre_ajouter=lookup_widget(objet,"fenetre_ajouter");

input1=lookup_widget(objet,"Id");
input2=lookup_widget(objet,"nom");
input3=lookup_widget(objet,"etat");
input4=lookup_widget(objet,"dateachat");

strcpy(a.id,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(a.nom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(a.etat,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(a.dateachat,gtk_entry_get_text(GTK_ENTRY(input4)));
ajouter_appareil(a);
}


void
on_ButtonAfficher_liste_appareils_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_ajouter;
GtkWidget *fenetre_afficher;
GtkWidget *treeview1;

fenetre_ajouter=lookup_widget(objet,"fenetre_ajouter");

gtk_widget_destroy(fenetre_ajouter);
fenetre_afficher=lookup_widget(objet,"fenetre_afficher");
fenetre_afficher=create_fenetre_afficher();

gtk_widget_show(fenetre_afficher);

treeview1=lookup_widget(fenetre_afficher,"treeview1");
afficher_appareil(treeview1);
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
on_buttonRetour_liste_clicked          (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_ajouter, *fenetre_afficher;
fenetre_afficher=lookup_widget(objet, "fenetre_afficher");

gtk_widget_destroy(fenetre_afficher);
fenetre_ajouter=create_fenetre_ajouter();
gtk_widget_show(fenetre_ajouter);
}


void
on_buttonValidation_de_reservation_clicked
                                        (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget* Jour;
GtkWidget* Mois;
GtkWidget* Annee;
GtkWidget* Combobox1;
GtkWidget* Combobox2;
GtkWidget* Combobox3;

char num[10];
Date date_rsrv;
char nom_atelier[50][10];
int heure_rsrv;
int i,n;

Jour = lookup_widget(objet_graphique,"Jour");
Mois = lookup_widget(objet_graphique,"Mois");
Annee = lookup_widget(objet_graphique,"Annee");
Combobox1 = lookup_widget(objet_graphique,"combobox1");
Combobox2 = lookup_widget(objet_graphique,"combobox2");
Combobox3 = lookup_widget(objet_graphique,"combobox3");

date_rsrv.Jour = gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (Jour));
date_rsrv.Mois = gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (Mois));
date_rsrv.Annee = gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (Annee));

if(strcmp("8h==>12h",gtk_combo_box_get_active_text(GTK_COMBO_BOX(Combobox1)))==0)
heure_rsrv=1;
else
heure_rsrv=2;


n=tab_atelier_dispo (nom_atelier,date_rsrv,heure_rsrv);

for(i=0;i<n;i++)
	{
  		gtk_combo_box_append_text(GTK_COMBO_BOX(Combobox3),_(nom_atelier[i]));
	}

}

void
on_buttonConfirmer_clicked             (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget* Jour;
GtkWidget* Mois;
GtkWidget* Annee;
GtkWidget* Combobox1;
GtkWidget* Combobox2;
GtkWidget* Combobox3;
GtkWidget* sortie;
reservationAtelier a;

Combobox1 = lookup_widget(objet_graphique,"combobox1");
sortie = lookup_widget(objet_graphique,"label15DATE");
Jour = lookup_widget(objet_graphique,"jour");
Mois = lookup_widget(objet_graphique,"mois");
Annee = lookup_widget(objet_graphique,"annee");
Combobox2 = lookup_widget(objet_graphique,"combobox2");
Combobox3 = lookup_widget(objet_graphique,"combobox3");
a.date_rsrv.Jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (Jour));
a.date_rsrv.Mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (Mois));
a.date_rsrv.Annee = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (Annee));
if(strcmp("8h==>12h",gtk_combo_box_get_active_text(GTK_COMBO_BOX (Combobox1)))==0)
a.heure_rsrv=1;
else
a.heure_rsrv=2;
strcpy(a.num,gtk_combo_box_get_active_text(GTK_COMBO_BOX(Combobox3)));
reserver_atelier(a);
gtk_label_set_text(GTK_LABEL(sortie),"Reservtion reussite");
}


void
on_buttonsuivant_clicked               (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_reservation, *fenetre_afficher;
fenetre_afficher=lookup_widget(objet, "fenetre_afficher");

gtk_widget_destroy(fenetre_afficher);
fenetre_reservation=create_fenetre_reservation();
gtk_widget_show(fenetre_reservation);
}

int choix[]={0,0};
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
on_buttonRETOUR_WINDOW4_clicked        (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_ajouter, *fenetre_panne;
fenetre_panne=lookup_widget(objet, "fenetre_panne");

gtk_widget_destroy(fenetre_panne);
fenetre_ajouter=create_fenetre_ajouter();
gtk_widget_show(fenetre_ajouter);
}


void
on_buttonsuivantwindow3_clicked        (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_reservation, *fenetre_panne;
fenetre_reservation=lookup_widget(objet, "fenetre_reservation");

gtk_widget_destroy(fenetre_reservation);
fenetre_panne=create_fenetre_panne();
gtk_widget_show(fenetre_panne);
}


void
on_radiobuttonPanneexterne_toggled     (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{choix[0]=1;}
}



void
on_radiobuttonPanneinterne_toggled     (GtkToggleButton *togglebutton,
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
on_checkbuttonNon_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{choix[1]=1;}
}


void
on_buttonokwindow5_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_ajouter, *fenetre_operationreussite;
fenetre_operationreussite=lookup_widget(objet, "fenetre_operationreussite");

gtk_widget_destroy(fenetre_operationreussite);
fenetre_ajouter=create_fenetre_ajouter();
gtk_widget_show(fenetre_ajouter);
}


void
on_buttonretourwindow5_clicked         (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_ajouter, *fenetre_operationnonreussite;
fenetre_operationnonreussite=lookup_widget(objet, "fenetre_operationnonreussite");

gtk_widget_destroy(fenetre_operationnonreussite);
fenetre_ajouter=create_fenetre_ajouter();
gtk_widget_show(fenetre_ajouter);
}


void
on_buttonsuppressionwindow7_clicked    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_buttonmodifierwindow7_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window2;
	GtkWidget *window7;
	window2 = lookup_widget(objet_graphique,"fenetre_ajouter");
	window7 = create_fenetre_modificationousuppression();
	gtk_widget_destroy(window2);
	gtk_widget_show(window7);
}


void
on_buttonrecherchewindow7_clicked      (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
appareil a;
int r;
char texte[100];
char texte2[100];
GtkWidget *input1;
GtkWidget *input2;
GtkWidget *input3;
GtkWidget *input4;
GtkWidget *status;

	input1 = lookup_widget(objet_graphique,"entry10");
	input2 = lookup_widget(objet_graphique,"entry7");
	input3 = lookup_widget(objet_graphique,"entry8");
	input4 = lookup_widget(objet_graphique,"entry9");
	status = lookup_widget(objet_graphique,"label_status");
strcpy(texte,gtk_entry_get_text(GTK_ENTRY(input1)));
r= rechercher_appareil(texte);
if (r==0)
{
strcpy(texte2,"id non trouvé");
gtk_label_set_text(GTK_LABEL(status),texte2);
} 
else {
	strcpy(texte2,"id trouvé");
	gtk_label_set_text(GTK_LABEL(status),texte2);	
	strcpy(a.id,find_appareil(texte).a);
	strcpy(a.nom,find_appareil(texte).nom);
	strcpy(a.etat,find_appareil(texte).etat);
	strcpy(a.dateachat,find_appareil(texte).dateachat);
	gtk_entry_set_text(GTK_ENTRY(input1),a.id);
	gtk_entry_set_text(GTK_ENTRY(input2),a.nom);
	gtk_entry_set_text(GTK_ENTRY(input3),a.etat);
	gtk_entry_set_text(GTK_ENTRY(input4),a.dateachat);
	
}
}


void
on_buttonsuppressionwindow8_clicked    (GtkButton       *button,
                                        gpointer         user_data)
{

}

