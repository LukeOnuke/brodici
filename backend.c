#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "frontend.h"
#include "backend.h"
#include <windows.h>

bool poljePlavogIgraca[11][7];
bool poljeCrvenogIgraca[11][7];

/*Ovo je "main" funkcija logike igre*/
void igra()
{
    printf("Ucitavam igranopolje... \n");
    cls(); //Clearuje ekran
    napuniMatricu(poljePlavogIgraca,true);
    napuniMatricu(poljeCrvenogIgraca,false);
    cls();
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

//"Pewpew, ovo_je_funkcija_trolololo." -Tasha
void pucaj(bool plaviIgac){
    int odgovor = 0;

    if(plaviIgac){
        ispisiIgrackoPoljePlavi(poljePlavogIgraca);
    }else{
        ispisiIgrackoPoljeCrveni(poljeCrvenogIgraca);
    }

    printf("Pewpew brod...\n");
    scanf("%c");
    odgovor = pitajZaLokaciju();

    if(plaviIgac && poljePlavogIgraca[odgovor / 100][odgovor % 100] || !plaviIgac && poljeCrvenogIgraca[odgovor / 100][odgovor % 100]){
        printf("Pogodili ste");
        if(plaviIgac){
            poljeCrvenogIgraca[odgovor / 100][odgovor % 100] = false;
        }else{
            poljePlavogIgraca[odgovor / 100][odgovor % 100] = false;
        }
    }else{
        printf("Promasili ste. -_-");
    }


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

int pitajZaLokaciju(){
    //'1' = 49
    int odgovor = 0;
    char milan[3];
    printf("Unesi koordinate broda (REDKOLONA) : ");

    gets(milan);

    odgovor = (milan[0] - 49) * 100 + toupper(milan[1]) - 65; //broj 1 || '1' - 49 = 1
    return odgovor;
}





