#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "frontend.h"
#include "backend.h"

bool poljePlavogIgraca[11][7];
bool poljeCrvenogIgraca[11][7];
int plaviBrodovi;
int crveniBrodovi;

/*Ovo je "main" funkcija logike igre*/
void igra(){
    plaviBrodovi=10;
    crveniBrodovi=10;
    printf("Ucitavam igranopolje... \n");
    cls(); //Clearuje ekran
    napuniMatricu(poljePlavogIgraca,true);
    napuniMatricu(poljeCrvenogIgraca,false);
    cls();
    int odgovor;
    odgovor=pitajZaLokaciju;
    gadjanjePlavi(odgovor);
}
void gadjanjePlavi(int odgovor)
{
    ispisiIgrackoPoljePlavi(poljePlavogIgraca);
    bool imaSledeciPokret;
    do
    {
        imaSledeciPokret=false;
        if(poljeCrvenogIgraca[odgovor/100][odgovor%100])
        {
            printf("Pogodili ste!");
            poljeCrvenogIgraca[odgovor/100][odgovor%100]=false;
            imaSledeciPokret=true;
            crveniBrodovi--;
        }
        else
        {
            printf("Promasili ste!");

        }
    }
    while(imaSledeciPokret);
}
void gadjanjeCrveni()
{
    int odgovor;
    ispisiIgrackoPoljeCrveni(poljeCrvenogIgraca);
    odgovor=pitajZaLokaciju;
    bool imaSledeciPokret;
    do
    {
        imaSledeciPokret=false;
        if(poljePlavogIgraca[odgovor/100][odgovor%100])
        {
            printf("Pogodili ste!");
            poljePlavogIgraca[odgovor/100][odgovor%100]=false;
            imaSledeciPokret=true;
            plaviBrodovi--;
        }
        else
        {
            printf("Promasili ste!");
        }
    }
    while(imaSledeciPokret);
}


