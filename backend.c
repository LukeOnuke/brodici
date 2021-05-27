#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "frontend.h"
#include "backend.h"

bool poljePlavogIgraca[11][7];
bool poljeCrvenogIgraca[11][7];

/*Ovo je "main" funkcija logike igre*/
void igra(){
    printf("Ucitavam igranopolje... \n");
    cls(); //Clearuje ekran
    napuniMatricu(poljePlavogIgraca, true); //Puni matricu plavog igraca sa brodovima
    ispisiIgrackoPoljePlavi(poljePlavogIgraca); //Ispisuje mu igrano polje
    printf("%d", pitajZaGadjanje()); //Pita gde ce da gadja i ispisuje njegov izbor
}
