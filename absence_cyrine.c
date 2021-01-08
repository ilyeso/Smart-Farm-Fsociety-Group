#include <stdio.h>
#include <string.h>
#include "absence.h"
#include "callbacks.h"
#include "liste_ouvriers.h"
#include <gtk/gtk.h>


int moyenne_presence (char Nom[], char Prenom[])
{FILE *	f;
int s;
absence ab;
f=fopen("absence.txt","r");
s=0;
while(fscanf(f,"%s %s %s %s %s %s %s %s \n",ab.Nom, ab.Prenom,ab.lundi,ab.mardi,ab.mercredi,ab.jeudi,ab.vendredi,ab.samedi)!=EOF)
{
if ((strcmp(ab.Nom,Nom)==0)&&(strcmp(ab.Prenom,Prenom)==0))
{
if (strcmp (ab.lundi,"0")==0)
{s++;}
if (strcmp (ab.mardi,"0")==0)
{s++;}
if (strcmp (ab.mercredi,"0")==0)
{s++;}
if (strcmp (ab.jeudi,"0")==0)
{s++;}
if (strcmp (ab.vendredi,"0")==0)
{s++;}
if (strcmp (ab.samedi,"0")==0)
{s++;}
}
}
fclose(f);
return (s);
}
