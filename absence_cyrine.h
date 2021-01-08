#ifndef ABSCENCE_H_INCLUDED
#define ABSCENCE_H_INCLUDED
#include <config.h>
#include <gtk/gtk.h>
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "string.h"

typedef struct{
char Nom[30];
char Prenom[30];
char lundi[30];
char mardi[30]; 
char mercredi[30];
char jeudi[30];
char vendredi[30];
char samedi[30];
}absence;


int moyenne_presence(char Nom[], char Prenom[]);
#endif


