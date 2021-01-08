#include <gtk/gtk.h>

// Structure Date de Naissance //
typedef struct date
{
    int j;
    int m;
    int a;
}   date;

// Structure Santé //
typedef struct sante
{
    int vac;
    int malade;
    int gestante;
}   sante;

// Structure Animal //
typedef struct animal
{
    int id;
    char famille[20];
    char sexe[20];
    int poids;
    date date;
    sante sante;
}   animal;
int nb_troup(char fich[], char *fam);
void afficher_nbrtroup(GtkWidget *liste);
