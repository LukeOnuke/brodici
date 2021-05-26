#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include "frontend.h"
#include "backend.h"

void cls(){
    system("cls");
}

void color(char opcije[]){
    char komanda[20] = "color ";
    strcat(komanda, opcije);
    system(komanda);
}

void plavi(){
    color("97");
}

void crveni(){
    color("47");
}

void resetujBoju(){
    color("");
}

void pokreniIgru(){
    printf("Ucitavam igranopolje... \n");
    cls();
    napuniMatricu(poljeCrvenogIgraca);
    printf("%d", ispisiIgrackoPoljePlavi(poljeCrvenogIgraca));
}

void ispisiMeni(char imeFajla[]){
    FILE *file = fopen(imeFajla, "r"); //Otvori faj u read modu
    char karakter;
    while(karakter != EOF){
        karakter = fgetc(file);
        printf("%c", karakter);
    }
    printf("\n");
    fclose(file); //zatvori fajl da nebi pravio greske u op sistemu
}

int ispisiIgrackoPolje(bool igracevoPolje[][11]){
    int odgovor = 0;
    int privremeno;
    printf("  "); //namesti index slova

    //ispisi slovni index
    for(int i = 'A'; i < 'G'; i++){
        printf(" %c", i);
    }
    printf("\n");
    //ispisi matricu
    for(int i = 0; i < REDOVI; i++){
        printf("%2d", i + 1);
        for(int j = 0; j < KOLONE; j++){
            if(igracevoPolje[i][j]){
                printf(" x");
            }else{
                printf("  ");
            }
        }
        printf("\n");
    }
    printf("Unesi x gadjana : ");
    scanf("%d", &privremeno);
    odgovor = privremeno * 100;
    printf("Unesi y gadjana (kao veliko slovo): ");
    scanf("%d", &privremeno - 'A');
    odgovor += privremeno;
    return odgovor;
}

int ispisiIgrackoPoljeCrveni(bool igracevoPolje[][11]){
    crveni();
    ispisiMeni("gui/crveni.txt");
    return ispisiIgrackoPolje(igracevoPolje);
}

int ispisiIgrackoPoljePlavi(bool igracevoPolje[][11]){
    plavi();
    ispisiMeni("gui/plavi.txt");
    return ispisiIgrackoPolje(igracevoPolje);
}

void napuniMatricu(bool igracevoPolje[][11]){
    for(int i = 0; i < REDOVI; i++){
        for(int j = 0; j < KOLONE; j++){
            igracevoPolje[i][j] = true;
        }
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
            resetujBoju();
            exit(0);
        }else if(izabirniKarakter == 'e'){
            printf("Escape");
            exit(0);
        }else{
            printf("Pogresan unos, probajte ponovo. ");
        }
    }while(izabirniKarakter != 'i' || izabirniKarakter != 'j');
}

/*Front end (sprednja-logika) ide ovde*/
