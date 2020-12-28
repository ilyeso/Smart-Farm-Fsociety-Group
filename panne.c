#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "panne.h"

void Resultat(int choix[], char texte[])
{
	strcpy(texte,"Le type de votre panne est:");
	if(choix[0]==1)
	strcat(texte," Panne externe");
	if(choix[1]==1)
	strcat(texte," Panne interne");
}
