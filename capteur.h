#include <gtk/gtk.h>


enum
{
	SELECTION,
        Eid,
  	Etype,
  	Emarque,
  	Eplace,
  	EvalMin,
  	EvalMax,
  	EinOut,
	Eperm,
	COLUMNS ,
};

typedef struct capteur
{
  char id[50]  ;
  char type[50]  ;
  char marque[50] ;
  char place[50] ;
  char valMin[50]  ;
  char valMax[50] ;
  char inOut[50];
  char perm[50] ;
 }capteur ;

//---------------------------
capteur rech_capteur(char *fi,char *idRech);
//--------------------------------
int ajout_capteur(char *fi, capteur c ) ;
//-------------------------------------
int supp_capteur(char *fi, char *id );
//------------------------------------
void modif_capteur (char *fi , capteur k  ) ;
//-------------------------------------------
void afficher_cap(GtkWidget *liste);
