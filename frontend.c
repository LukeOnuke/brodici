#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "frontend.h"

#define PLAVI_BOJE 97
#define CRVENI_BOJE 47

void plavi(){
    color(PLAVI_BOJE);
}

void crveni(){
    color(CRVENI_BOJE);
}

void resetujBoju(){
    color("");
}

void color(char opcije[]){
    char komanda[10] = "color ";
    strcat(komanda, opcije);
    system(komanda);
}

void pokreniIgru(){
    printf("Pokreni igru \n");
}

void ispisiMeni(char imeFajla[]){
    FILE *file = fopen(imeFajla, "r"); //Otvori faj u read modu
    char karakter;
    while(karakter != EOF){
        karakter = fgetc(file);
        printf("%c", karakter);
    }
}

void pokreniEkran(){
    char izabirniKarakter;
    ispisiMeni("gui/glavnimeni.txt");
    printf("\n");
    printf("[(I)graj] [(E)scape] \n");
    do{
        scanf("%c", &izabirniKarakter);
        izabirniKarakter = tolower(izabirniKarakter);
        if(izabirniKarakter == 'i'){
            pokreniIgru();
            color("FC");
        }else if(izabirniKarakter == 'e'){
            printf("Escape");
            exit(0);
        }else{
            printf("Pogresan unos");
        }
    }while(izabirniKarakter != 'i' || izabirniKarakter != 'j');
}

/*Front end (sprednja-logika) ide ovde*/
