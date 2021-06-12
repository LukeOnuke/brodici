#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "frontend.h"
#include "backend.h"
#include <windows.h>

static bool poljePlavogIgraca[7][6];
static bool poljeCrvenogIgraca[7][6];

/*Ovo je 'main' funkcija logike igre*/
void igra()
{
    printf("Ucitavam igranopolje... \n");
    cls(); //Clearuje ekran
    napuniMatricu(poljePlavogIgraca,true);
    napuniMatricu(poljeCrvenogIgraca,false);
    cls();
    printf("Pritisnite enter za gadjanje");
    getchar();
    crvenoPlavo();
    pobednik();
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
        cls();
        if(plaviIgrac){
            ispisiIgrackoPoljePlavi(poljePlavogIgraca);
        }else{
            ispisiIgrackoPoljeCrveni(poljeCrvenogIgraca);
        }
        printf("\n");
        ispisiLiniju();
        pitajZaLokaciju(&red, &kolona);

        if(plaviIgrac){
            dalIma = poljeCrvenogIgraca[red][kolona];
            sledecePucanje = dalIma;

            if(dalIma){
                poljeCrvenogIgraca[red][kolona] = false;
                pogodak();
                sleep(2);
                sledecePucanje=true;
                if(prebrojBrodove(poljeCrvenogIgraca) == 0){
                    cls();
                    plavi();
                    ispisiMeni("gui/pobedaplavih.txt");
                    system("pause");
                    exit(0);
                }
            }else{
                promasaj();
            }
        }else{
            dalIma = poljePlavogIgraca[red][kolona];
            sledecePucanje = dalIma;

            if(dalIma){

                poljePlavogIgraca[red][kolona] = false;
                pogodak();
                sleep(2);
                sledecePucanje=true;
                if(prebrojBrodove(poljePlavogIgraca) == 0){
                    cls();
                    crveni();
                    ispisiMeni("gui/pobedacrvenih.txt");
                    system("pause");
                    exit(0);
                }
            }else{
                promasaj();
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
        crveni();
        ispisiMeni("gui/pobedacrvenih.txt");
    }
    else
    {
        plavi();
        ispisiMeni("gui/pobedaplavih.txt");
    }
}

void pitajZaLokaciju(int * red, int * kolona)
{
    //'1' = 49
    char milan[3];
    printf("Unesi koordinate broda (REDKOLONA) : ");

    gets(milan);

    *red = (milan[0] - 49);
    *kolona = toupper(milan[1]) - 65;
    return;
}





