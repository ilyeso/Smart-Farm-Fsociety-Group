#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <gdk/gdkkeysyms.h>
#include "support.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "capteur.h"
#include <gtk/gtk.h>
#include "callbacks.h"

//---------------------------------------<<<<< recherche >>>-------------------------
capteur rech_capteur(char *fi,char *idRech)

{
    capteur vide ={"-1","vide","vide","vide","0","0","vide","vide"} ;
    capteur c ;
    FILE *f;
    f=fopen(fi,"r");

    while (fscanf(f,"%s %s %s %s %s %s %s %s\n",c.id,c.type,c.marque,c.place,c.valMin,c.valMax,c.inOut,c.perm)!=EOF)
        {
          if(strcmp (c.id,idRech )==0)
          {
           fclose(f);
           return c ;
           }
        }

   fclose(f);
   return vide;
}

//-----------------------------------------------------------------------------------------
//---------------------------------------<<<<< Ajout >>>-----------------------------------

int ajout_capteur(char *fi, capteur c )
{
    FILE *f;
    f=fopen(fi,"a");
    if(f!=NULL)
    {
        if (   strcmp(rech_capteur(fi,c.id).id,c.id)!=0    )
       {
           fprintf(f,"%s %s %s %s %s %s %s %s\n",c.id,c.type,c.marque,c.place,c.valMin,c.valMax,c.inOut,c.perm);
           fclose(f);
           return 1 ;
       }
       else
        {
        fclose(f);
        return 0;
        }

    }
}
//----------------------------------------------------------------------------------
//---------------------------------------<<<<< Suppression >>>-------------------------
int supp_capteur(char *fi, char *id )
{
FILE *f1 ;
FILE *f2;
capteur c ;
int k=0;
f1=fopen(fi,"r");

if(f1!=NULL)
 {
   f2=fopen("cap_temp.txt","w");
    if(f2!=NULL)
    {
           while(fscanf(f1,"%s %s %s %s %s %s %s %s\n",c.id,c.type,c.marque,c.place,c.valMin,c.valMax,c.inOut,c.perm)!= EOF)
           {

             if(strcmp (c.id,id )!=0)
                    fprintf(f2,"%s %s %s %s %s %s %s %s\n",c.id,c.type,c.marque,c.place,c.valMin,c.valMax,c.inOut,c.perm) ;
             else
               k=1 ;

            }
           fclose(f1);
           fclose(f2);
   }
}
if (k==1)
{
    remove("capteur.txt");
    rename("cap_temp.txt","capteur.txt");
    return 1;
}
else
{
    remove("cap_temp.txt");
    return 0;
}

}

//------------------------------------------------------------------------------------
//---------------------------------------<<<<< Modification >>>-------------------------
void modif_capteur (char *fi , capteur k  )
{

FILE *f1 ;
FILE *f2;
capteur c ;
f1=fopen(fi,"r");

if(f1!=NULL)
{
   f2=fopen("modif_temp.txt","w");
    if(f2!=NULL)
       {
           while(fscanf(f1,"%s %s %s %s %s %s %s %s",c.id,c.type,c.marque,c.place,c.valMin,c.valMax,c.inOut,c.perm)!=EOF)
           {

            if(strcmp (c.id,k.id )==0)
            fprintf(f2,"%s %s %s %s %s %s %s %s\n",k.id,k.type,k.marque,k.place,k.valMin,k.valMax,k.inOut,k.perm);
            else
            fprintf(f2,"%s %s %s %s %s %s %s %s\n",c.id,c.type,c.marque,c.place,c.valMin,c.valMax,c.inOut,c.perm);

            }
           fclose(f1);
           fclose(f2);
       }
}
remove("capteur.txt");
rename("modif_temp.txt","capteur.txt");
}
//-----------------------------------------------------------------------------------------
//--------------------<<<<< AFFICHAGE >>>------------------------------------------------
 
void afficher_cap(GtkWidget *liste)
{
	GtkCellRenderer *renderer;
	GtkCellRenderer *renderer1;
	GtkTreeViewColumn *column;
	GtkTreeIter    iter;
	GtkListStore *store;

  char Numero [50]  ;
  char Type[50]  ;
  char Marque[50] ;
  char Emplacement[50] ;
  char valeurMin[50]  ;
  char valeurMax[50] ;
  char internExtern[50];
  char Permeabilite[50];

	// store = NULL ;
	FILE *f ; 
	
	store=gtk_tree_view_get_model(liste);
		if (store == NULL ) 
		{
 		renderer = gtk_cell_renderer_toggle_new();
		renderer1=renderer;
		column = gtk_tree_view_column_new_with_attributes("SELECTION", renderer, "active",SELECTION, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Numero", renderer, "text",Eid, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Type", renderer, "text",Etype, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Marque", renderer, "text",Emarque, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Emplacement", renderer, "text",Eplace, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("valeurMin", renderer, "text",EvalMin, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("valeurMax", renderer, "text",EvalMax, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("internExtern", renderer, "text",EinOut, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Permeabilite", renderer, "text",Eperm, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
		
		

  store=gtk_list_store_new (COLUMNS,G_TYPE_BOOLEAN, G_TYPE_STRING,  G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
		}

		f=fopen("capteur.txt","r");
		if(f==NULL)
		{
		return;
		}
		else
 		{
                f=fopen("capteur.txt","a+");
		while(fscanf(f,"%s %s %s %s %s %s %s %s\n",Numero,Type,Marque,Emplacement,valeurMin,valeurMax,internExtern,Permeabilite)!=EOF)
		{
 	gtk_list_store_append (store, &iter);
	gtk_list_store_set(store, &iter, SELECTION, FALSE, Eid, Numero,Etype, Type, Emarque, Marque,Eplace,Emplacement,EvalMin,valeurMin,EvalMax,valeurMax,EinOut,internExtern,Eperm,Permeabilite, -1);
		}

              fclose(f);
	      gtk_tree_view_set_model (GTK_TREE_VIEW (liste),  GTK_TREE_MODEL (store));
              g_signal_connect(G_OBJECT(renderer1), "toggled", (GCallback)toggled_func, store);
              g_object_unref (store);

		
}

}

























