#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include <string.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "nbr_de_troupeaux.h"
animal a;

void
on_Afficher_le_nombre_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{

GtkWidget *treeview;
         GtkWidget  *listeTroup;
GtkWidget *page ;
page = lookup_widget(button, "Nombre_de_troupeaux_de_chaque_type");
listeTroup=lookup_widget(button, "liste_des_troupeaux");
treeview = lookup_widget(button, "treeview_nbr_de_troupeaux_de_chaque_types");


listeTroup=create_liste_des_troupeaux();
gtk_widget_show(listeTroup);
gtk_widget_destroy(page);
afficher_nbrtroup(treeview);
}

void
on_actualiser_la_page_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
         GtkWidget *treeview;
         GtkWidget  *listeTroup;
         GtkWidget  *listeTroup1;

listeTroup=lookup_widget(button, "liste_des_troupeaux");
listeTroup1=lookup_widget(button, "liste_des_troupeaux");
treeview = lookup_widget(listeTroup1, "treeview_nbr_de_troupeaux_de_chaque_types");
listeTroup1= create_liste_des_troupeaux();
gtk_widget_show(listeTroup1);
gtk_widget_destroy(listeTroup);
afficher_nbrtroup(treeview);


}


void
on_treeview_nbr_de_troupeaux_de_chaque_types_row_activated
                                        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
	gchar* id;
	gchar* famille;
	gchar* sexe;
	gchar* poids;
	animal a;

	GtkTreeModel *model = gtk_tree_view_get_model(treeview);

	if (gtk_tree_model_get_iter(model, &iter, path))
	{
		//obtention des valeurs de la ligne selectionnée
		gtk_tree_model_get (GTK_LIST_STORE (model) , &iter, 0, &id, 1, &famille, 2, &sexe, 3,  &poids,4, -1);	
		strcpy(a.id,id);
		strcpy(a.famille,famille);
		strcpy(a.sexe,sexe);
		strcpy(a.poids,poids);
		//mise à jour de l'affichage de la treeview
		afficher_nbrtroup(treeview);
	}
}

