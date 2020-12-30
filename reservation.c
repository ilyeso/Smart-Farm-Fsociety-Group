#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "reservation.h"

//remplir le tableau reservationAtelier à partir d'un fichier.txt

int tab_atelier_rsrv(reservationAtelier tab[])
{
int n=0;
FILE *f=openf("atelierreserve.txt","r");
if(f!=NULL)
{
while(fscanf(f,"%s %s %d \n",tab[n].num,&tab[n].date_rsrv,&tab[n].heure_rsrv)!=EOF)
{ n++;}
fclose(f);
}
return;
}

//Verfier si l'atelier est reservé ou pas
int verifier_rsrv(reservationAtelier a)
{
reservationAtelier ra;
int v=0;
FILE* f=openf("atelierreserve.txt","r");
if (f!=NULL)
{
while(!v && fscanf(f,"%s %s %d %d %d %d" ,a.num,a.date_rsrv.Jour,&a.date_rsrv.Mois,&a.date_rsrv.Annee,&a.heure_rsrv)!=EOF)
{ if (strcmp(a.num,ra.num)==0)
	{if ((a.date_rsrv.Jour==ra.date_rsrv.Jour)&&(a.date_rsrv.Mois==ra.date_rsrv.Mois)&&(a.date_rsrv.Annee==ra.date_rsrv.Annee)&&(a.heure_rsrv==ra.heure_rsrv))
           {v++;}
        }
}
fclose(f);
//Liste des ateliers dispos
int tab_atelier_dispo(char NomAtelier[100][5], Date date_rsrv, int heure_rsrv)
{
int i,nA=0;
FILE *f;
f=fopen("atelier.txt","r");
reservationAtelier a;
a.date_rsrv = date_rsrv;
a.heure_rsrv =heure_rsrv;
if(f!=NULL)
{
	while(fscanf(f,"%s",a.num)!=EOF)
	{
	  if( a.num[0]==NomAtelier)
            {
		int v =verifier_rsrv(a);
	      if(!v)
		{
		  strcpy(NomAtelier[nA],a.num);
		  nA++;
		}
	}
}
}
fclose(f);

return (nA);
}
//reserver et enregistrer dans un fichier Atelier.txt
void reserver_atelier(reservationAtelier a)
{
FILE* f;
f=fopen("atelierreserve.txt","a");
	if(f!=NULL)
	{
	fprintf(f,"%s %d %d %d %d \n",a.num,a.date_rsrv.Jour,a.date_rsrv.Mois,a.date_rsrv.Annee,a.heure_rsrv);
	fclose(f);
	}
}
}
}

