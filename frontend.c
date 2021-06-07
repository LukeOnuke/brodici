#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include "frontend.h"
#include "backend.h"

/**
* Cisti ekran,
*
*/
void cls(){
    system("cls");
}

/**
* Boja ekrana radi po komandi color. Prvi heks broj je pozadina a drugi je boja teksta.
* Uzeto iz 'color ?' komande
* 0 = Black       8 = Gray
* 1 = Blue        9 = Light Blue
* 2 = Green       A = Light Green
* 3 = Aqua        B = Light Aqua
* 4 = Red         C = Light Red
* 5 = Purple      D = Light Purple
* 6 = Yellow      E = Light Yellow
* 7 = White       F = Bright White
*
*/
void color(char opcije[]){
    char komanda[20] = "color ";
    strcat(komanda, opcije);
    system(komanda);
}

/**
* Stavlja boje ekrana na boje plavog igraca.
*
*/
void plavi(){
    color("97");
}

/**
* Stavlja boje ekrana na boje crvenog igraca.
*
*/
void crveni(){
    color("47");
}

/**
* Resetuje boju konzole.
*
*/
void resetujBoju(){
    color("");
}

/**
* Ispisuje meni iz fajla.
*
*/
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

/**
* Ispisuje polje igraca, matricu pretvara u polje.
*/
void ispisiIgrackoPolje(bool igracevoPolje[][11]){
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
}

/**
* Pita za mesto na pucanje, vraca koordinate tipa 0201 (REDKOLONA) (ij)
*/
int pitajZaLokaciju(){
    //'1' = 49
    getchar();
    int odgovor = 0;
    int privremeno = 0;
    char milan[3];
    printf("Unesi koordinate broda (REDKOLONA) : ");

    gets(milan);

    odgovor = (milan[0] - 48) * 100;
    odgovor += toupper(milan[1]) - 65;
    return odgovor;
}

/**
* Ispise polje za crvenog igraca.
*/
void ispisiIgrackoPoljeCrveni(bool igracevoPolje[][11]){
    crveni();
    ispisiMeni("gui/crveni.txt");
    ispisiIgrackoPolje(igracevoPolje);
}

/**
* Ispise polje za plavog igraca.
*/
void ispisiIgrackoPoljePlavi(bool igracevoPolje[][11]){
    plavi();
    ispisiMeni("gui/plavi.txt");
    ispisiIgrackoPolje(igracevoPolje);
}

/**
*
* Proverava dal brod moze tu da stane.
*
*/
bool proveriMesto(int velicina, int red, int kolona){
    if(red < 0 || red > REDOVI){
        return false;
    }
    if(kolona < 0 || (kolona + velicina) > KOLONE){
        return false;
    }
    return true;
}

/**
*
* Dodaj brodove.
*
*/
void dodajBrod(bool igracevoPolje[][11], int red, int kolona,int velicina){
    for(int i = 0; i < velicina; i++){
        igracevoPolje[red][kolona + i] = true;
    }
}

/**
*
* Napuni matricu, unos koji je bitni tashi i marku.
*
*/
void napuniMatricu(bool igracevoPolje[][11], bool plaviIgrac){
    int i;
    int lokacija;

    for(i = 0; i < 5; i++){
        do{
            cls();
            if(plaviIgrac){
                ispisiIgrackoPoljePlavi(igracevoPolje);
            }else{
                ispisiIgrackoPoljeCrveni(igracevoPolje);
            }
            printf("Brod [%d. brod] \n", i);
            lokacija = pitajZaLokaciju();
        }while(!proveriMesto(5, lokacija / 100, lokacija % 100));
        dodajBrod(igracevoPolje, lokacija / 100, lokacija % 100, 1);
    }
}

/**
*
* Pokreni ekran, glavna funkcija.
*
*/
void pokreniEkran(){
    char izabirniKarakter;
    ispisiMeni("gui/glavnimeni.txt");
    printf("\n");
    printf("[(I)graj] [(E)scape] \n");
    do{
        scanf("%c", &izabirniKarakter);
        izabirniKarakter = tolower(izabirniKarakter);
        if(izabirniKarakter == 'i'){
            /*
            *=========================
            *Ovde se zove backend igre
            *=========================
            */
            igra();
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
