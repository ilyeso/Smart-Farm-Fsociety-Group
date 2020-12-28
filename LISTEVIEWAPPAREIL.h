#include<gtk/gtk.h>
typedef struct

{
	char id[20];
  	char nom[30];
	char etat[20];
	char dateachat[20];
}appareil;
//ajouter appareil//
void ajouter_appareil(appareil a);

//affichage appareil//
void afficher_appareil(GtkWidget *liste);

//supprimer appareil//
void supprimer_appareil(appareil a);

//rechercher appareil//
int rechercher_appareil(char id[]);

//fonction find//
LISTEVIEWAPPAREIL find_appareil(char cin[]);
