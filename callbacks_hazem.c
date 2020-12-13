#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <gtk/gtk.h>
#include <string.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "animal.h"


void
on_buttonAff_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window1;
GtkWidget *window2;
GtkWidget *treeview1;

window1=lookup_widget(objet,"window1");

gtk_widget_destroy(window1);
window2=lookup_widget(objet,"window2");
window2=create_window2();

gtk_widget_show(window2);

treeview1=lookup_widget(window2,"treeview1");
afficher_animal(treeview1);
}


void
on_buttonConf_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
animal a;

GtkWidget *input1, *input2, *input3, *input4;
GtkWidget *window1;

window1=lookup_widget(objet,"window1");

input1=lookup_widget(objet,"Identifiant");
input2=lookup_widget(objet,"Famille");
input3=lookup_widget(objet,"Sexe");
input4=lookup_widget(objet,"Poids");

strcpy(a.id,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(a.famille,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(a.sexe,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(a.poids,gtk_entry_get_text(GTK_ENTRY(input4)));

ajouter_animal(a);
}


void
on_treeview1_row_activated             (GtkTreeView     *treeview,
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
		gtk_tree_model_get (GTK_LIST_STORE(model), &iter, 0, &id, 1, &famille, 2, &sexe, 3, &poids, -1);	
		strcpy(a.id,id);
		strcpy(a.famille,famille);
		strcpy(a.sexe,sexe);
		strcpy(a.poids,poids);
		//appel de la fonction de suppression 
		supp_animal(a);
		//mise à jour de l'affichage de la treeview
		afficher_animal(treeview);
	}

}


void
on_buttonRet_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window1, *window2;
window2=lookup_widget(objet, "window2");

gtk_widget_destroy(window2);
window1=create_window1();
gtk_widget_show(window1);
}

