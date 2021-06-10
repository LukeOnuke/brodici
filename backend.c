#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "frontend.h"
#include "backend.h"
#include <windows.h>

bool poljePlavogIgraca[11][7];
bool poljeCrvenogIgraca[11][7];
int plaviBrodovi;
int crveniBrodovi;

/*Ovo je "main" funkcija logike igre*/
void igra()
{
    plaviBrodovi=10;
    crveniBrodovi=10;
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
        printf("%d %d %d",odgovor,odgovor/100,odgovor%100);
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
    while(plaviBrodovi!=0 && crveniBrodovi!=0)
    {
        cls();
        gadjanjePlavi();
        sleep(4);
        cls();
        gadjanjeCrveni();
        sleep(4);
        cls;
    }
}

int pitajZaLokaciju(){
    //'1' = 49
    int odgovor = 0;
    int privremeno = 0;
    char milan[3];
    printf("Unesi koordinate broda (REDKOLONA) : ");

    gets(milan);

    odgovor = (milan[0] - 49) * 100;
    odgovor += toupper(milan[1]) - 65;
    return odgovor;
}





