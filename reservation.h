typedef struct
{
int Jour;
int Mois;
int Annee;
}Date;

typedef struct
{
char num[10];
Date date_rsrv;
int heure_rsrv;
}reservationAtelier;

//tableau des ateliers reservés
int tab_atelier_rsrv(reservationAtelier tab[50]);
//Verfier si l'atelier est reservé ou pas
int verifier_rsrv(reservationAtelier a);
//Liste des ateliers dispos
int tab_atelier_dispo(char NomAtelier[100][5], Date date_rsrv, int heure_rsrv);
//reserver et enregistrer dans un fichier Atelier.txt
void reserver_atelier(reservationAtelier a);

