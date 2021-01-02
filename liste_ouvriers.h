#include<gtk/gtk.h>

typedef struct {

    char Nom[40];
    char Prenom [40];
    char Date_de_naissance [40];
    char adresse_mail [40];
    char CIN;
    char Numero_de_tel;
}ouvrier;

void ajouter_ouvrier(ouvrier o);
void afficher_ouvrier(GtkWidget *liste);
void supprimer_ouvrier(ouvrier o);
void modifier_ouvrier(ouvrier o);
int rechercher_ouvrier(char CIN[]);
ouvrier rech_ouvrier(char CIN[]);
