#include <gtk/gtk.h>



void
on_buttonAjouter_appareil_clicked      (GtkWidget       *Button,
                                        gpointer         user_data);

void
on_ButtonAfficher_liste_appareils_clicked
                                        (GtkWidget       *Button,
                                        gpointer         user_data);


void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);


void
on_buttonRetour_liste_clicked          (GtkWidget       *Button,
                                        gpointer         user_data);

void
on_buttonValidation_de_reservation_clicked
                                        (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_buttonConfirmer_clicked             (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_buttonsuivant_clicked               (GtkWidget       *button,
                                        gpointer         user_data);

void
on_buttonconfirmationfinale_clicked    (GtkWidget       *button,
                                        gpointer         user_data);

void
on_buttonRETOUR_WINDOW4_clicked        (GtkWidget       *button,
                                        gpointer         user_data);

void
on_buttonsuivantwindow3_clicked        (GtkWidget       *button,
                                        gpointer         user_data);

void
on_radiobuttonPanneexterne_toggled     (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonPanneinterne_toggled     (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonPanneexterne_toggled     (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonPanneinterne_toggled     (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbuttonoui_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbuttonNon_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_buttonokwindow5_clicked             (GtkWidget       *button,
                                        gpointer         user_data);

void
on_buttonretourwindow5_clicked         (GtkWidget       *button,
                                        gpointer         user_data);

void
on_buttonsuppressionwindow7_clicked    (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonmodifierwindow7_clicked       (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonrecherchewindow7_clicked      (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonsuppressionwindow8_clicked    (GtkButton       *button,
                                        gpointer         user_data);
