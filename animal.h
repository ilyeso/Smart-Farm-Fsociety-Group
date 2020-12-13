
#include <gtk/gtk.h>

// Structure Animal //
typedef struct animal
{
    char id[20];
    char famille[20];
    char sexe[20];
    char poids[20];
}   animal;

void ajouter_animal(animal a);
void afficher_animal(GtkWidget *liste);
void supp_animal(animal a);
//void supp_animal(char fich[], char id []);// spp(" animal.txt", a.id);
