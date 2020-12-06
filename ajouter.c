#include <stdio.h>
#include <string.h>
#include<stdlib.h>

typedef struct capteur
{
  int id  ;
  char type[50]  ;
  char marque[50] ;
  char place[50] ;
  float valMin  ;
  float valMax ;
  char inOut[50];
  float valeur;

 }capteur ;
 ///fonction recherche :
capteur rech_capteur(char *fi,int idRech)
{
    capteur vide ={-1,"vide","vide","vide",0,0,"vide"} ;
    capteur c ;
    FILE *f;
    f=fopen(fi,"r");



        while (fscanf(f,"%d %s %s %s %f %f %s\n",&c.id,c.type,c.marque,c.place,&c.valMin,&c.valMax,c.inOut)!=EOF)
        {
          if (c.id==idRech )
          {
           fclose(f);
           return c ;
           }
        }

   fclose(f);
   return vide;
}
///---------------------------------------------------------------------------


///-----------------<<< fonction ajouter >>>------------------------------------

int ajout_capteur(char *fi, capteur c )
{
    FILE *f;
    f=fopen(fi,"a");
    if(f!=NULL)
    {
        if ((rech_capteur(fi,c.id).id) != c.id)
       {
           fprintf(f,"%d %s %s %s %.2f %.2f %s\n",c.id,c.type,c.marque,c.place,c.valMin,c.valMax,c.inOut);
           fclose(f);
           return 1 ;
       }
       else
        {
        fclose(f);
        return 0;
        }

    }
}
///**************************************************************************************

///fonction supprimer

int supp_capteur(char *fi, int id )
{
FILE *f1 ;
FILE *f2;
capteur c ;
int k=0;
f1=fopen(fi,"r");

if(f1!=NULL)
{
   f2=fopen("cap_temp.txt","w");
    if(f2!=NULL)
       {
           while(fscanf(f1,"%d %s %s %s %f %f %s\n",&c.id,c.type,c.marque,c.place,&c.valMin,&c.valMax,c.inOut)!= EOF)
           {

             if ((c.id) != id)
                    fprintf(f2,"%d %s %s %s %.2f %.2f %s\n",c.id,c.type,c.marque,c.place,c.valMin,c.valMax,c.inOut) ;
             else
               k=1 ;

            }
           fclose(f1);
           fclose(f2);
       }
}
if (k==1)
{
    remove("capteur.txt");
    rename("cap_temp.txt","capteur.txt");
    return 1;
}
else
{
    remove("cap_temp.txt");
    return 0;
}

}
///-------------------------------------------------------------

///fonction modifier
void modif_capteur (char *fi , capteur k  )
{

FILE *f1 ;
FILE *f2;
capteur c ;
f1=fopen(fi,"r");

if(f1!=NULL)
{
   f2=fopen("modif_temp.txt","w");
    if(f2!=NULL)
       {
           while(fscanf(f1,"%d %s %s %s %f %f %s",&c.id,c.type,c.marque,c.place,&c.valMin,&c.valMax,c.inOut)!=EOF)
           {

            if ((c.id) == k.id)
            fprintf(f2,"%d %s %s %s %.2f %.2f %s\n",k.id,k.type,k.marque,k.place,k.valMin,k.valMax,k.inOut);
            else
            fprintf(f2,"%d %s %s %s %.2f %.2f %s\n",c.id,c.type,c.marque,c.place,c.valMin,c.valMax,c.inOut);

            }
           fclose(f1);
           fclose(f2);
       }
}
remove("capteur.txt");
rename("modif_temp.txt","capteur.txt");
}





int main()
{
        capteur c ={3,"test1","A","test",50.00,100.00,"test"};
 //  int k = ajout_capteur ("capteur.txt",rech_capteur("testrech.txt",3));
 //int k =  ajout_capteur("capteur.txt",c);
 //if(k) printf("ajout avec succee");
// else printf("deja existant");

  /* if( supp_capteur("capteur.txt",0))
       printf("supprime avec succee");
    else printf("introuvable ") ;           */

//modif_capteur("capteur.txt",c) ;
float k ;
k= rech_capteur("capteur.txt",0).valMax ;
printf("valeur max est %f",k);
  return 0;
}







