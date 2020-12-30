#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LISTEVIEWAPPAREIL.h"
#include <gtk/gtk.h>
enum
{
	EID,
	ENOM,
	EETAT,
	EDATE,
	COLUMNS,
};


/*--------------Fonction Ajouter-----------------*/
void ajouter_appareil(appareil a)
{
    FILE *f;
    f=fopen("Appareil.txt","W");
    if(f!=NULL)
    {
        fprintf(f,"%s %s %s %s \n", a.id,a.nom,a.etat,a.dateachat);
        fclose(f);
    }
}


/*---------------Fonction Supprimer----------------*/
void supprimer_appareil(appareil a)
{
appareil b;
FILE *f,*g;

    f=fopen("Appareil.txt","r");
    g=fopen("Appareil2.txt","w");

    if ((f==NULL) || (g==NULL))
    	return;
    else
    {
    	while(fscanf(f,"%s %s %s %s  \n",b.id,b.nom,b.etat,b.dateachat)!=EOF)
	{
        	if ((strcmp(a.id,b.id)!=0) || (strcmp(a.nom,b.nom)!=0) || (strcmp(a.etat,b.etat)!=0) || (strcmp(a.dateachat,b.dateachat)!=0)|| (strcmp(a.dateachat,b.dateachat)!=0))  
		fprintf(g,"%s %s %s %s \n",b.id,b.nom,b.etat,b.dateachat);
        }
	fclose(f);
        fclose(g);

remove("Appareil.txt");
rename("Appareil2.txt","Appareil.txt");
    }
}


/*-------------------Fonction Afficher----------------------*/
void afficher_appareil(GtkWidget *liste)
{
appareil a;
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;

	char id[20];
  	char nom[30];
	char etat[20];
	char dateachat[20];
	store=NULL;
	
	FILE *f;

	store=gtk_tree_view_get_model(liste);
 
	if (store==NULL)
	{
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("id", renderer, "text", EID, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("nom", renderer, "text", ENOM, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("etat", renderer, "text", EETAT, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("dateachat", renderer, "text", EDATE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	}
	store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
	
	f=fopen("Appareil.txt","r");
	if(f==NULL)
	{
		return;
	}
	else
	{
		f=fopen("Appareil.txt","a+");
		while(fscanf(f,"%s %s %s %s  \n", id, nom, etat, dateachat)!=EOF)
		{
			gtk_list_store_append (store, &iter);
			gtk_list_store_set (store, &iter, EID, id, ENOM, nom, EETAT, etat,EDATE,dateachat -1);
		}
		fclose(f);
		gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
		g_object_unref (store);
	}
}

/*-------------fonction rechercher---------------*/
int rechercher_appareil(char id[])
{
    appareil a;
    FILE *f;
    f = fopen("appareil.txt","r");
    if(f != NULL){
    	while(f,"%s %s %s %s  \n", id, nom, etat, dateachat)!=EOF)
{
        	if(strcmp(a.id,id) == 0){
       		     return 1;
        	}
    	}
}
    fclose(f);
    return 0;
    

}
/*-----------------fonction find-----------*/
LISTEVIEWAPPAREIL find_appareil(char cin[])
{
    appareil a;
    FILE *f;
    f = fopen("appareil.txt","r");
    if(f != NULL){
    	while(f,"%s %s %s %s  \n", id, nom, etat, dateachat)!=EOF)
{
        	if(strcmp(a.id) == 0)
{
       		     return a;
        	}
    	}
}
    fclose(f);
    return;
}


