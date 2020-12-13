
#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "animal.h"
#include <gtk/gtk.h>

enum
{
	EID,
	EFAMILLE,
	ESEXE,
	EPOIDS,
	COLUMNS,
};

// Fonction Ajouter //
void ajouter_animal(animal a)
{
    FILE *f;
    f=fopen("Troupeaux.txt","a+");
    if(f!=NULL)
    {
        fprintf(f,"%s %s %s %s\n", a.id, a.famille, a.sexe, a.poids);
        fclose(f);
    }
}

// Fonction Afficher //
void afficher_animal(GtkWidget *liste)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;

	char id[20];
  	char famille[20];
	char sexe[20];
	char poids[20];
	store=NULL;
	
	FILE *f;

	store=gtk_tree_view_get_model(liste);
 
	if (store==NULL)
	{
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("id", renderer, "text", EID, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("famille", renderer, "text", EFAMILLE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("sexe", renderer, "text", ESEXE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("poids", renderer, "text", EPOIDS, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	}
	store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
	
	f=fopen("Troupeaux.txt","r");
	if(f==NULL)
	{
		return;
	}
	else
	{
		f=fopen("Troupeaux.txt","a+");
		while(fscanf(f,"%s %s %s %s\n", id, famille, sexe, poids)!=EOF)
		{
			gtk_list_store_append (store, &iter);
			gtk_list_store_set (store, &iter, EID, id, EFAMILLE, famille, ESEXE, sexe, EPOIDS, poids, -1);
		}
		fclose(f);
		gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
		g_object_unref (store);
	}
}

// Fonction Supprimer //
void supp_animal(animal a)
{
animal b;
FILE *f,*g;

    f=fopen("Troupeaux.txt","r");
    g=fopen("Troupeaux2.txt","w");

    if ((f==NULL) || (g==NULL))
    	return;
    else
    {
    	while(fscanf(f,"%s %s %s %s\n", b.id, b.famille, b.sexe, b.poids)!=EOF)
	{
        	if ((strcmp(a.id,b.id)!=0) || (strcmp(a.famille,b.famille)!=0) || (strcmp(a.sexe,b.sexe)!=0) || (strcmp(a.poids,b.poids)!=0))  
		fprintf(g,"%s %s %s %s\n", b.id, b.famille, b.sexe, b.poids);
        }
	fclose(f);
        fclose(g);

remove("Troupeaux.txt");
rename("Troupeaux2.txt","Troupeaux.txt");
    }
}

