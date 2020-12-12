#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h" 
#include "support.h"
#include "capteur.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
GtkTreeIter iter1;
GtkListStore *listf;
void toggled_func(GtkCellRendererToggle *cell_renderer,gchar *paths,gpointer user_data) //selection
{
    GtkTreeIter iter;
    GtkTreePath *path;
    gboolean boolean;
    FILE* f;
    gchar *Numero;
    path = gtk_tree_path_new_from_string (paths);
    gtk_tree_model_get_iter (GTK_TREE_MODEL (user_data),&iter,path);
    gtk_tree_model_get (GTK_TREE_MODEL (user_data),&iter,SELECTION,&boolean,Eid,&Numero,-1);
    gtk_list_store_set (user_data, &iter,SELECTION, !boolean,-1);
    listf=user_data;
    iter1=iter;
    if (!boolean){
    f=fopen("idtmp.txt","a");
    if(f!=NULL) 
    {
    fprintf(f,"%s \n",Numero);
    fclose(f);}}       
}


void
on_treeview2_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
capteur c;

GtkTreeIter iter ;
gchar* id ;
gchar* type;
gchar* marque;
gchar* place; 
gchar* valMin  ;
gchar* valMax ;
gchar* inOut ;
gchar* perm ;


GtkTreeModel *model = gtk_tree_view_get_model(treeview);
if (gtk_tree_model_get_iter(model,&iter,path))
{
gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&id,1,&type,2,&marque,3,&place,4,&valMin,5,&valMax,6,&inOut,7,&perm,-1);


strcpy(c.id,id);

strcpy(c.type,type);
strcpy(c.marque,marque);
strcpy(c.place,place);

strcpy(c.valMin,valMin);

strcpy(c.valMax,valMax);

strcpy(c.inOut,inOut);
strcpy(c.perm,perm);

//c= rech_capteur("capteur.txt",c.id) ; /// a verifier si la selection prends charge 



}

}


void
on_buttonAlerte_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_buttonRechercheCapteur_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_buttonModifierCap_clicked           (GtkWidget       *button,
                                        gpointer         user_data) //// 1er  modifier clicked
{
GtkWidget *formulaire;
GtkWidget *principal;
 GtkWidget *combobox;
 GtkWidget *entry1 ;
 GtkWidget *entry2;
 GtkWidget *entry3;
 GtkWidget *spinbutton1;
 GtkWidget *spinbutton2;
 GtkWidget *radiobutton1;
 GtkWidget *radiobutton2;
 GtkWidget *radiobutton3;
   GtkWidget *checkbox1 ;
    GtkWidget *checkbox2 ;
    GtkWidget *test ;
 FILE *f, *f1;
capteur c ; 
 char id[20] ;
 int valmin , valmax;

  principal=lookup_widget(button,"windowGestion_Capteur");
  

  formulaire=lookup_widget(button,"windowAjouterCap");
  formulaire=create_windowAjouterCap();

 entry1=lookup_widget(formulaire,"entryNumCap");
 combobox=lookup_widget(button,"comboboxTypeCapteur");
 entry2=lookup_widget(button,"entryMarqueCap");
 entry3=lookup_widget(button,"entryPlace");
 spinbutton1=lookup_widget(button,"spinbuttonValMin");
 spinbutton2=lookup_widget(button,"spinbuttonValMax");
 radiobutton1=lookup_widget(button,"radiobutton_etanche");
 radiobutton2=lookup_widget(button,"radiobutton_perm");
 radiobutton3=lookup_widget(button,"radiobuttonNone");
checkbox1 =lookup_widget(button,"checkbutton_Inter");
 checkbox2 =lookup_widget(button,"checkbutton_exter");
  f=fopen("idtmp.txt","r");
  fscanf(f,"%s \n",id);  
  fclose(f);
 c= rech_capteur("capteur.txt",id) ; 
  gtk_entry_set_text (GTK_ENTRY (entry1), _(c.id));
  gtk_entry_set_text (GTK_ENTRY (entry2), _(c.marque));
  gtk_entry_set_text (GTK_ENTRY (entry3), _(c.place));
  /*gtk_combo_box_set_active(GTK_COMBO_BOX (combobox),0);
  valmin=atoi(c.valMin) ; 
  valmax = atoi(c.valMax) ;
  gtk_spin_button_set_value(GTK_SPIN_BUTTON(spinbutton1),valmin);
  gtk_spin_button_set_value(GTK_SPIN_BUTTON(spinbutton1),valmax);
   if(strcmp(c.inOut,"Interieur")==0)
  {gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(checkbox1),TRUE);}
   if(strcmp(c.inOut,"Exterieur")==0)
  {gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(checkbox2),TRUE);}

  if(strcmp(c.perm,"Permeable")==0)
  {gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(radiobutton2),TRUE);}
  else if (strcmp(c.inOut,"Etanche")==0)
  {gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(radiobutton1),TRUE);}
 */
 test=lookup_widget(formulaire,"labeltest");
  gtk_label_set_text (GTK_LABEL (test), _(c.marque));
  
  gtk_widget_show(formulaire);


}


void
on_buttonSupprimerCap_clicked          (GtkWidget       *objet,
                                        gpointer         user_data)  /// Supprimer un capteur 
{
GtkWidget *message;
GtkWidget *principal;

message=lookup_widget(objet,"windowConfirmSupp");
message=create_windowConfirmSupp();
gtk_widget_show(message);
}


void
on_buttonAjoutercap_clicked            (GtkWidget       *objet,
                                        gpointer         user_data) /// ajouter un capteur 
{
GtkWidget *formulaire;
GtkWidget *principal;


principal=lookup_widget(objet,"windowGestion_Capteur");
gtk_widget_destroy(principal);
formulaire=lookup_widget(objet,"windowAjouterCap");
formulaire=create_windowAjouterCap();
gtk_widget_show(formulaire);
}


void
on_buttonHomeGestCap_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_buttonAnnulerSuppCap_clicked        (GtkWidget       *objet,
                                        gpointer         user_data)
{

}


void
on_radiobutton_exter_group_changed     (GtkRadioButton  *radiobutton,
                                        gpointer         user_data)
{

}


void
on_radiobutton_Inter_group_changed     (GtkRadioButton  *radiobutton,
                                        gpointer         user_data)
{

}


void
on_buttonAjoutFinalCap_clicked         (GtkWidget       *button,
                                        gpointer         user_data)   /// ajout final du capteur 
{
  GtkWidget *window ;
 GtkWidget *combobox;
 GtkWidget *entry1 ;
 GtkWidget *entry2;
 GtkWidget *entry3;
 GtkWidget *spinbutton1;
 GtkWidget *spinbutton2;
 GtkWidget *radiobutton1;
 GtkWidget *radiobutton2;
 GtkWidget *radiobutton3;
 GtkWidget *checkbox1 ;
 GtkWidget *checkbox2 ;
 GtkWidget *dialog1;
 capteur c;
 FILE *f;
 int valmin,valmax;
 
 window=lookup_widget(button,"windowAjouterCap");
 entry1=lookup_widget(button,"entryNumCap");
 combobox=lookup_widget(window,"comboboxTypeCapteur");
 entry2=lookup_widget(button,"entryMarqueCap");
 entry3=lookup_widget(button,"entryPlace");
 spinbutton1=lookup_widget(button,"spinbuttonValMin");
 spinbutton2=lookup_widget(button,"spinbuttonValMax");
 radiobutton1=lookup_widget(button,"radiobutton_etanche");
 radiobutton2=lookup_widget(button,"radiobutton_perm");
 radiobutton3=lookup_widget(button,"radiobuttonNone");
 checkbox1 =lookup_widget(button,"checkbutton_Inter");
 checkbox2 =lookup_widget(button,"checkbutton_exter");
 
 strcpy(c.id,gtk_entry_get_text(GTK_ENTRY(entry1)));
 strcpy(c.marque,gtk_entry_get_text(GTK_ENTRY(entry2)));
 strcpy(c.place,gtk_entry_get_text(GTK_ENTRY(entry3)));
 strcpy(c.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox)));
 valmin =gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (spinbutton1));
 sprintf(c.valMin ,"%d",valmin) ;
 valmax =gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (spinbutton2));
 sprintf(c.valMax ,"%d",valmax) ;
 if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(radiobutton1)))
  {strcpy(c.perm,"Etanche");}
 else if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(radiobutton2)))
  {strcpy(c.perm,"Permeable");}
 else  {strcpy(c.inOut,"None");}
 if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(checkbox1)))
  {strcpy(c.inOut,"Interieur");}
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(checkbox2)))
  {strcpy(c.inOut,"Exterieur");}
  
 if ( ajout_capteur("capteur.txt",c ) ) 
  {   dialog1 = create_dialogAjoutSucc ();
      gtk_widget_show (dialog1); 
   }  
 
 
}


void
on_buttonAnullerAjout_clicked          (GtkWidget       *objet,
                                        gpointer         user_data) /// 1er bouton ajouter clicked
{
GtkWidget *form;
GtkWidget *princ;
GtkListStore *treeview;
GtkWidget *scrolledwindow1;


form=lookup_widget(objet,"windowAjouterCap");
gtk_widget_destroy(form);
princ=lookup_widget(objet,"windowGestion_Capteur");
princ=create_windowGestion_Capteur();
gtk_widget_show(princ);
//gtk_container_add (GTK_CONTAINER (scrolledwindow1), treeview);
//gtk_container_add (GTK_CONTAINER (princ), scrolledwindow1);
  treeview=lookup_widget(princ,"treeview2");
afficher_cap(treeview);
}


void
on_modifFinalCap_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_buttonDeconnexion_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_closebutton_AjoutSucc_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_closebutton_Erreur_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button1_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data) /// acceder a l'espace gestion des capteurs
{


GtkWidget *affichage;
GtkWidget *fenetre1;
GtkListStore *treeview2;
GtkWidget *scrolledwindow1;


fenetre1=lookup_widget(objet,"window1");
gtk_widget_destroy(fenetre1);
affichage=lookup_widget(objet,"windowGestion_Capteur");
affichage=create_windowGestion_Capteur();
gtk_widget_show(affichage);
//gtk_container_add (GTK_CONTAINER (scrolledwindow1), treeview2);
//gtk_container_add (GTK_CONTAINER (affichage), scrolledwindow1);
treeview2=lookup_widget(affichage,"treeview2");
afficher_cap(treeview2);
}


void
on_buttonValiderSuppCap_clicked        (GtkWidget       *objet,
                                        gpointer         user_data)  /// valider la suppression du capteur 
{
   GtkWidget *affichage;
   GtkWidget  *message ;
   GtkListStore *treeview2;
   GtkWidget *liste;



    FILE* f1;
    capteur c ; 
     char id[20] ;
  

f1=fopen("idtmp.txt","r");
  if(f1!=NULL) 
  {
  fscanf(f1,"%s \n",id);
  fclose(f1);}
  remove("idtmp.txt");

  gtk_list_store_set (listf,&iter1,SELECTION, FALSE,-1);
 if ( supp_capteur("capteur.txt", id ))  
{
  affichage = lookup_widget(objet,"windowGestion_Capteur"); 
  //affichage=create_windowGestion_Capteur();
  
 
  // gtk_widget_show(affichage);
   message=lookup_widget(objet,"windowConfirmSupp");

    gtk_widget_hide(message);
 gtk_widget_hide(affichage);
 gtk_widget_show(affichage);
treeview2=lookup_widget(affichage,"treeview2");

   // store=gtk_tree_view_get_model(GTK_TREE_VIEW(liste));
    afficher_cap(treeview2);
}
      /// segmentation error !!!!
  


}


