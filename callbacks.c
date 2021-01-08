#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "Bestouv.h"


void
on_buttonAFFICHERLOUVDELANNEE_clicked  (GtkWidget       *button,
                                        gpointer         user_data)
{
		GtkWidget *Ouvr;
		GtkWidget *windowbestouv;
		GtkWidget *treeview ;

                Ouvr=lookup_widget(button, "windowouv");
		windowbestouv = create_windowbestouv();
		treeview = lookup_widget(windowbestouv,"treeviewbestouv");
		gtk_widget_show(windowbestouv);//on affiche la prochaine fenêtre
		gtk_widget_destroy(Ouvr);//on ferme la première fenêtre
		afficher_bestouv(treeview);

}


void
on_treeviewbestouv_row_activated       (GtkTreeView     *treeview,
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
		//obtention des valeurs de la ligne selectionnée
		gtk_tree_model_get (GTK_LIST_STORE (model) , &iter, 0, &Nom, 1, &Prenom, 2, &Date_de_naissance, 3,  &adresse_mail,4, &CIN,5, &Numero_de_tel ,6, -1);	
		strcpy(o.Nom,Nom);
		strcpy(o.Prenom,Prenom);
		strcpy(o.Date_de_naissance,Date_de_naissance);
		strcpy(o.adresse_mail,adresse_mail);
		strcpy(o.CIN,CIN);
		strcpy(o.Numero_de_tel,Numero_de_tel);
		//mise à jour de l'affichage de la treeview
		afficher_bestouv(treeview);
	}
}



void
on_buttonactualiser_clicked            (GtkWidget       *button,
                                        gpointer         user_data)
{
		GtkWidget *windowbestouv1;
		GtkWidget *windowbestouv;
		GtkWidget *treeview;
		
                windowbestouv=lookup_widget(button, "windowbestouv");
		windowbestouv1=lookup_widget(button, "windowbestouv");
		treeview = lookup_widget(windowbestouv,"treeviewbestouv");
		windowbestouv1 = create_windowbestouv();
		gtk_widget_show(windowbestouv1);//on affiche la prochaine fenêtre
		gtk_widget_destroy(windowbestouv);//on ferme la première fenêtre
		afficher_bestouv(treeview);
}

