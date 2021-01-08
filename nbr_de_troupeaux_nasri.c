#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nbr_de_troupeaux.h"
#include "callbacks.h"
#include <gtk/gtk.h>

enum
{
	EID,
	EFAMILLE,
	ESEXE,
	EPOIDS,
	COLUMNS,
};
// Nombre de troupeaux de chaque famille//
int nb_troup(char fich[], char *fam)
{
    animal a;
    FILE *f;
    int nb=0;
    f=fopen(fich,"r");
    if (f == NULL)
        printf("Erreur d'ouverture du fichier\n");
    else
        while (fscanf(f,"%d %s %s %d %d %d %d %d %d %d\n", &a.id, a.famille, a.sexe, &a.poids, &a.date.j, &a.date.m, &a.date.a, &a.sante.vac, &a.sante.malade, &a.sante.gestante)!=EOF)
        {
            if (strcmp(a.famille, fam)==0)
                nb=nb+1;
        }
    fclose(f);
    printf("Nombre de troupeaux de %s : %d", fam, nb);
    return nb;
}
/*-------affichage du nbr de troupeau----*/
void afficher_nbrtroup(GtkWidget *liste)
{
animal a;
date d;
sante s;
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
	char id;
    	char famille[20];
    	char sexe[20];
    	char poids;
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
	
	f=fopen("animal.txt","r");
	if(f==NULL)
	{
		return;
	}
	else
	{
		f=fopen("animal.txt","a+");
		while(fscanf(f,"%s %s %s %s \n", id, famille,sexe, poids)!=EOF)
		{
			gtk_list_store_append (store, &iter);
			gtk_list_store_set (store, &iter, EID, id, EFAMILLE, famille, ESEXE, sexe ,EPOIDS ,poids , -1);
		}
		fclose(f);
		gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
		g_object_unref (store);
	}
}
