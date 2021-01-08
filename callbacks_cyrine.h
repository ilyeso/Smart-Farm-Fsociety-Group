#include <gtk/gtk.h>


void
on_Ajouter_ouvrier_clicked             (GtkWidget       *button,
                                        gpointer         user_data);

void
on_Afficher_liste_clicked              (GtkWidget       *button,
                                        gpointer         user_data);

void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_Pointage_clicked                    (GtkWidget       *button,
                                        gpointer         user_data);

void
on_Modifier_ouvrier_clicked            (GtkWidget       *button,
                                        gpointer         user_data);

void
on_retour_clicked                      (GtkWidget       *button,
                                        gpointer         user_data);

void
on_radiobuttonabsentpointage_toggled   (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonPresentpointage_toggled  (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbuttonoui_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbuttonnon_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_Confirmer_p_clicked                 (GtkWidget       *button,
                                        gpointer         user_data);

void
on_RetourP_clicked                     (GtkWidget      *button,
                                        gpointer         user_data);

void
on_Rechercher_ouvrier_clicked          (GtkWidget       *button,
                                        gpointer         user_data);

void
on_Supprimer_modification_clicked      (GtkWidget       *button,
                                        gpointer         user_data);

void
on_Okalerte_clicked                    (GtkWidget       *button,
                                        gpointer         user_data);
