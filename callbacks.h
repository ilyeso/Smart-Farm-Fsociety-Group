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
on_retour_clicked                      (GtkWidget      *button,
                                        gpointer         user_data);



void
on_valider_clicked                     (GtkWidget       *button,
                                        gpointer         user_data);

void
on_Pointage_clicked                    (GtkWidget       *button,
                                        gpointer         user_data);

void
on_RetourP_clicked                     (GtkWidget       *button,
                                        gpointer         user_data);

void
on_buttonsuivant1_clicked              (GtkWidget       *button,
                                        gpointer         user_data);



void
on_Rechercher_ouvrier_clicked          (GtkWidget       *button,
                                        gpointer         user_data);

void
on_Modifier_ouvrier_clicked            (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_Retour_Modification_clicked         (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_Non_attention_clicked               (GtkWidget       *button,
                                        gpointer         user_data);

void
on_Oui_attention_clicked               (GtkWidget       *button,
                                        gpointer         user_data);

void
on_supprimer_ouvrier_clicked           (GtkWidget       *button,
                                        gpointer         user_data);

void
on_OK_op_clicked                       (GtkWidget       *button,
                                        gpointer         user_data);

void
on_radiobuttonPresent_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonabsent_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_Okattention_clicked                 (GtkWidget       *button,
                                        gpointer         user_data);

void
on_checkbuttonnon_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbuttonoui_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_Confirmer_p_clicked                 (GtkWidget      *objet_graphique,
                                        gpointer         user_data);

void
on_Supprimer_modification_clicked      (GtkButton       *button,
                                        gpointer         user_data);

void
on_Modifier_liste_ouvrier_clicked      (GtkWidget       *button,
                                        gpointer         user_data);
