#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "frontend.h"
#include "backend.h"
#include <windows.h>

static bool poljePlavogIgraca[7][6];
static bool poljeCrvenogIgraca[7][6];

/*Ovo je "main" funkcija logike igre*/
void igra()
{
    printf("Ucitavam igranopolje... \n");
    cls(); //Clearuje ekran
    napuniMatricu(poljePlavogIgraca,true);
    napuniMatricu(poljeCrvenogIgraca,false);
    cls();
    getchar();
    crvenoPlavo();
}

int prebrojBrodove(bool poljeIgraca[][6]){
    int brojac = 0;
    for(int i = 0; i < REDOVI; i++){
        for(int j = 0; j < KOLONE; j++){
            if(poljeIgraca[i][j]){
                brojac++;
            }
        }
    }
    return brojac;
}

void pucaj(bool plaviIgac){
    int red = 0;
    int kolona = 0;

    if(plaviIgac){
        ispisiIgrackoPoljePlavi(poljePlavogIgraca);
    }else{
        ispisiIgrackoPoljeCrveni(poljeCrvenogIgraca);
    }

    bool sledecePucanje=true;
    do
    {
    pitajZaLokaciju(&red, &kolona);
    if((plaviIgac && poljePlavogIgraca[red][kolona]) || (!plaviIgac && poljeCrvenogIgraca[red][kolona]))
        {
            printf("Pogodili ste\n");
            if(plaviIgac)
                {
                    poljeCrvenogIgraca[red][kolona] = false;
                }
            else
                {
                    poljePlavogIgraca[red][kolona] = false;
                }
        }
    else
    {
        printf("Promasili ste");
        sledecePucanje=false;

    }

    }
    while(sledecePucanje);




}

void crvenoPlavo()
{
    while(prebrojBrodove(poljePlavogIgraca) !=0 && prebrojBrodove(poljeCrvenogIgraca) !=0)
    {
        cls();
        pucaj(true);
        sleep(4);
        cls();
        pucaj(false);
        sleep(4);
        cls();
    }
}

void pitajZaLokaciju(int * red, int * kolona){
    //'1' = 49
    char milan[3];
    printf("Unesi koordinate broda (REDKOLONA) : ");

    gets(milan);

    printf("Unos [0]:%d, [1]:%d\n", milan[0], milan[1]);
    *red = (milan[0] - 49);
    *kolona = toupper(milan[1]) - 65;
    return;
}





