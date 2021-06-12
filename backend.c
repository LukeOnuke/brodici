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

int prebrojBrodove(bool poljeIgraca[][6])
{
    int brojac = 0;
    for(int i = 0; i < REDOVI; i++)
    {
        for(int j = 0; j < KOLONE; j++)
        {
            if(poljeIgraca[i][j])
            {
                brojac++;
            }
        }
    }
    return brojac;
}

void ispisiFalse(bool poljeIgraca[][6]){
    for(int i = 0; i < REDOVI; i++)
    {
        for(int j = 0; j < KOLONE; j++)
        {
            if(!poljeIgraca[i][j])
            {
                printf("%d(%d, %d)", poljeIgraca[i][j], i , j);
            }
        }
    }
}

void pucaj(bool plaviIgrac)
{
    int red = 0;
    int kolona = 0;
    bool dalIma = false;

    bool sledecePucanje=false;
    do
    {
        pitajZaLokaciju(&red, &kolona);

        if(plaviIgrac){
            dalIma = poljeCrvenogIgraca[red][kolona];
            sledecePucanje = dalIma;

            if(dalIma){
                poljeCrvenogIgraca[red][kolona] = false;
                printf("Pogodili ste\n");
                sledecePucanje=true;
            }else{
                printf("Promasili ste\n");
            }
        }else{
            dalIma = poljePlavogIgraca[red][kolona];
            sledecePucanje = dalIma;

            if(poljePlavogIgraca[red][kolona]){
                poljePlavogIgraca[red][kolona] = false;
                printf("Pogodili ste\n");
                sledecePucanje = true;
            }else{
                printf("Promasili ste\n");
            }
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
        sleep(3);
        cls();
        pucaj(false);
        sleep(3);
        cls();
    }
}

void pobednik()
{

    if(prebrojBrodove(poljePlavogIgraca)==0)
    {
        ispisiIgrackoPoljeCrveni(poljeCrvenogIgraca);
        printf("POBEDNIK JE CRVENI IGRAC!");
    }
    else
    {
        ispisiIgrackoPoljePlavi(poljePlavogIgraca);
        printf("POBEDNIK JE PLAVI IGRAC!");
    }

}

void pitajZaLokaciju(int * red, int * kolona)
{
    //'1' = 49
    char milan[3];
    printf("Unesi koordinate broda (REDKOLONA) : ");

    gets(milan);

    printf("Unos [0]:%d, [1]:%d\n", milan[0], milan[1]);
    *red = (milan[0] - 49);
    *kolona = toupper(milan[1]) - 65;
    return;
}





