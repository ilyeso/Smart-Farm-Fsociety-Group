#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "liste_ouvriers.h"
#include <gtk/gtk.h>
enum 
{
	ENOM,
	EPRENOM,
	EDATE_DE_NAISSANCE,
	EADRESSE_MAIL,
	ECIN,
	ENUMERO_DE_TEL,
	COLUMNS,
};

//////////////////////////////////////////////////////////////
void ajouter_ouvrier(ouvrier o)
{
	FILE *f;
	f=fopen("liste.txt","a+");
	if (f!=NULL)
	{
		fprintf(f,"%s %s %s %s %s %s \n",o.Nom,o.Prenom,o.Date_de_naissance,o.adresse_mail,o.CIN,o.Numero_de_tel);
		fclose(f);
	}
}
//////////////////////////////////////////////////////////////////////////////////////////
void afficher_ouvrier(GtkWidget *liste)
{
ouvrier o;
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
 
	char Nom[40];
    	char Prenom [40];
    	char Date_de_naissance [40];
    	char adresse_mail [40];
    	char CIN;
    	char Numero_de_tel;
	store=NULL;

	FILE *f;
	store=gtk_tree_view_get_model(liste);
	if (store==NULL)
	{

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("Nom", renderer, "text",ENOM, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("Prenom", renderer, "text",EPRENOM, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("Date_de_naissance", renderer, "text",EDATE_DE_NAISSANCE, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("adresse_mail", renderer, "text",EADRESSE_MAIL, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("CIN", renderer, "text",ECIN, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer= gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("Numero_de_tel", renderer, "text",ENUMERO_DE_TEL, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	}
	store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

	f=fopen("liste.txt","r");
	if(f==NULL)
	{
		return;
	}
	else
	{
		f = fopen("liste.txt", "a+");
		while(fscanf(f,"%s %s %s %s %s %s  \n",o.Nom,o.Prenom,o.Date_de_naissance,o.adresse_mail,o.CIN,o.Numero_de_tel)!=EOF)
	{
		gtk_list_store_append (store, &iter);
		gtk_list_store_set (store, &iter, ENOM, Nom, EPRENOM, Prenom, EDATE_DE_NAISSANCE, Date_de_naissance, EADRESSE_MAIL, 		adresse_mail, ECIN, CIN, ENUMERO_DE_TEL, Numero_de_tel, -1);
	}
	fclose(f);
	gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
	g_object_unref (store);
	}
}
/////////////////////////////////////////////////////////////////////////////////////
void supprimer_ouvrier(ouvrier o)
{
ouvrier b;
FILE *f,*g;

	f=fopen("liste.txt","r");
	g=fopen("liste01.txt","w");
	if ((f==NULL)  || (g==NULL))
		return;
	else
	{
		while(fscanf(f,"%s %s %s %s %s %s \n",b.Nom,b.Prenom,b.Date_de_naissance,b.adresse_mail,b.CIN,b.Numero_de_tel)!=EOF)
		
		{
			if(( strcmp(o.Nom,b.Nom)!=0) || (strcmp(o.Prenom,b.Prenom)!=0) || (strcmp(o.Date_de_naissance,b.Date_de_naissance)!=0) ||( strcmp(o.adresse_mail,b.adresse_mail)!=0) || (strcmp(o.CIN,b.CIN)!=0) || (strcmp(o.Numero_de_tel,b.Numero_de_tel)!=0))
			fprintf(g,"%s %s %s %s %s %s \n",b.Nom,b.Prenom,b.Date_de_naissance,b.adresse_mail,b.CIN,b.Numero_de_tel);
		}
		fclose(f);
		fclose(g);
remove("liste.txt");
rename("liste01.txt","liste.txt");
	}
}
////////////////////////////////////////////////////////////////////////////////
void modifier_ouvrier(ouvrier o)
{
ouvrier d;
FILE *f,*h;
	
	f=fopen("liste.txt","r");
	h=fopen("liste01.txt","w");
	if (f!=NULL && h!=NULL)
	 {
		while(fscanf(f,"%s %s %s %s %s %s \n",d.Nom,d.Prenom,d.Date_de_naissance,d.adresse_mail,d.CIN,d.Numero_de_tel)!=EOF)

			{ if(strcmp(o.CIN,h.CIN)==0)
		{
				fprintf(h,"%s %s %s %s %s %s \n",o.Nom,o.Prenom,o.Date_de_naissance,o.adresse_mail,o.CIN,o.Numero_de_tel);
}
			else
	{
				fprintf(h,"%s %s %s %s %s %s \n",d.Nom,d.Prenom,d.Date_de_naissance,d.adresse_mail,d.CIN,d.Numero_de_tel);
}
			}
		}
	fclose(f);
	fclose(h);
	remove("liste.txt");
	rename("liste01.txt","liste.txt");
}
////////////////////////////////////////////////////////////////
int rechercher_ouvrier(char CIN[])
{
    ouvrier y;
    FILE *f;
    f = fopen("liste.txt","r");
    if(f != NULL)
{
    	while(fscanf(f,"%s %s %s %s %s %s \n",y.Nom,y.Prenom,y.Date_de_naissance,y.adresse_mail,y.CIN,y.Numero_de_tel)!=EOF)
{
        	if(strcmp(y.CIN,CIN) == 0)
{
       		     return 1;
        	}
    	}
}
    fclose(f);
    return 0;
}
    
/////////////////////////////////////////////////////////////////////////

ouvrier rech_ouvrier(char CIN[]){
    ouvrier y;
    FILE *f;
    f = fopen("liste.txt","r");
    if(f != NULL){
    	while(fscanf(f,"%s %s %s %s %s %s \n",y.Nom,y.Prenom,y.Date_de_naissance,y.adresse_mail,y.CIN,y.Numero_de_tel) != EOF){
        	if(strcmp(y.CIN,CIN) == 0){
       		     return y;
        	}
    	}
}
    fclose(f);
    return;
}

