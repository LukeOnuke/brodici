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
void igra()
{
    plaviBrodovi=4;
    crveniBrodovi=4;
    printf("Ucitavam igranopolje... \n");
    cls(); //Clearuje ekran
    napuniMatricu(poljePlavogIgraca,true);
    napuniMatricu(poljeCrvenogIgraca,false);
    cls();
    crvenoPlavo();
}


void gadjanjePlavi()
{
    int odgovor;
    ispisiIgrackoPoljePlavi(poljePlavogIgraca);
    bool imaSledeciPokret;
    do
    {
        odgovor=pitajZaLokaciju();
        imaSledeciPokret=false;
        if(poljeCrvenogIgraca[odgovor/100][odgovor%100])
        {
            printf("Pogodili ste!\n");
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
    ispisiIgrackoPoljeCrveni(poljePlavogIgraca);
    bool imaSledeciPokret;
    do
    {
        odgovor=pitajZaLokaciju();
        imaSledeciPokret=false;
        if(poljePlavogIgraca[odgovor/100][odgovor%100])
        {
            printf("Pogodili ste!\n");
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

void crvenoPlavo()
{
    while(plaviBrodovi!=0 || crveniBrodovi!=0)
    {
        cls();
        gadjanjePlavi();
        cls();
        gadjanjeCrveni();
        cls;
    }
}





