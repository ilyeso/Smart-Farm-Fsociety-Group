#include <gtk/gtk.h>


void
on_Afficher_le_nombre_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_actualiser_la_page_clicked          (GtkButton       *button,
                                        gpointer         user_data);



void
on_treeviewwindownbrtroup              (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
nbr_de_troupeaux_de_chaque_types       (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_treeview_nbr_de_troupeaux_de_chaque_types_row_activated
                                        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);
