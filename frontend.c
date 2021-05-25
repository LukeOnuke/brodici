#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "frontend.h"

void color(char opcije[]){

}

void pokreniIgru(){
    printf("Pokreni igru \n");
}

void pokreniEkran(){
    char izabirniKarakter;

    printf("Pew Pew Brodici.\n");
    printf("[(I)graj] [(E)scape] \n");
    do{
        scanf("%c", &izabirniKarakter);
        izabirniKarakter = tolower(izabirniKarakter);
        if(izabirniKarakter == 'i'){

        }else if(izabirniKarakter == 'e'){
            printf("Escape");
            exit(0);
        }else{
            printf("Pogresan unos");
        }
    }while(izabirniKarakter != 'i' || izabirniKarakter != 'j');
}

/*Front end (sprednja-logika) ide ovde*/
