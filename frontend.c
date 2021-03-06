#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include "frontend.h"
#include "backend.h"

/**
* cisti ekran,
*
*/
void cls()
{
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
void color(char opcije[])
{
    char komanda[20] = "color ";
    strcat(komanda, opcije);
    system(komanda);
}

/*boji ekran u plavo*/

void plavi()
{
    color("97");
}

/* boji ekran u crveno*/

void crveni()
{
    color("47");
}

/*resetuje boju konzole*/

void resetujBoju()
{
    system("color");
}

/*ispisuje meni iz fajla*/

void ispisiMeni(char imeFajla[])
{
    FILE *file = fopen(imeFajla, "r"); //Otvori fajl u read modu
    char karakter;
    while(karakter != EOF)
    {
        karakter = fgetc(file);
        printf("%c", karakter);
    }
    printf("\n");
    fclose(file); //zatvori fajl da nebi pravio greske u op sistemu
}

/*Ispisuje polje igraca, matricu pretvara u polje.*/

void ispisiIgrackoPolje(bool igracevoPolje[][6])
{
    printf("  "); //namesti index slova

    //ispisi slovni index
    for(int i = 'A'; i < (REDOVI + 'A'); i++)
    {
        printf(" %c", i);
    }
    printf("\n");
    //ispisi matricu
    for(int i = 0; i < REDOVI; i++)
    {
        printf("%2d", i + 1);
        for(int j = 0; j < KOLONE; j++)
        {
            if(igracevoPolje[i][j])
            {
                printf(" x");
            }
            else
            {
                printf("  ");
            }
        }
        printf("\n");
    }
}


/*ispisuje polje za crvenog igraca*/

void ispisiIgrackoPoljeCrveni(bool igracevoPolje[][6])
{
    crveni();
    ispisiMeni("gui/crveni.txt");
    ispisiIgrackoPolje(igracevoPolje);
}

/*ispisuje polje za plavog igraca*/

void ispisiIgrackoPoljePlavi(bool igracevoPolje[][6])
{
    plavi();
    ispisiMeni("gui/plavi.txt");
    ispisiIgrackoPolje(igracevoPolje);
}



/*Proverava da li brod moze tu da stane.*/


bool proveriMesto(int velicina, int red, int kolona, bool igracevoPolje[][6])
{
    if(red < 0 || red > REDOVI)
    {
        return false;
    }
    if(kolona < 0 || kolona > KOLONE)
    {
        return false;
    }
    if(igracevoPolje[red][kolona]){
        return false;
    }
    return true;
}

/*dodaj brodove*/

void dodajBrod(bool igracevoPolje[][6], int red, int kolona,int velicina)
{
    for(int i = 0; i < velicina; i++)
    {
        igracevoPolje[red][kolona + i] = true;
    }
}

/*Napuni matricu,unose se brodovi*/

void napuniMatricu(bool igracevoPolje[][6], bool plaviIgrac)
{
    int i;
    int red;
    int kolona;

        for(i = 0; i < 10; i++)
        {
            do
            {
                cls();

                if(plaviIgrac)
                {
                    ispisiIgrackoPoljePlavi(igracevoPolje);
                }
                else
                {
                    ispisiIgrackoPoljeCrveni(igracevoPolje);
                }

                printf("Brod [%d. brod] \n", i+1);
                pitajZaLokaciju(&red, &kolona);

            }
            while(!proveriMesto(1, red, kolona, igracevoPolje));
            dodajBrod(igracevoPolje, red, kolona, 1);
        }

}

void debug(char poruka[])
{
    printf("[DEBUG] %s\n", poruka);
}

/*ispisuje liniju radi ulepsavanja*/

void ispisiLiniju(){
    for(int i = 0; i < 80; i++){
        printf("%c", 196);
    }
    printf("\n\n");
}

/*ispisuje tekst kada je igrac promasio*/

void promasaj(){
    cls();
    ispisiMeni("gui/promasaj.txt");
    ispisiLiniju();
    printf("Promasili ste, cekamo 2 sek za sledeceg igraca.\n");
    ispisiLiniju();
}

/*ispisuje tekst kada je igrac pogodio*/

void pogodak(){
    resetujBoju();
    cls();
    ispisiMeni("gui/pogodak.txt");
    ispisiLiniju();
    printf("Pogodili ste, cekamo 2 sek.\n");
    ispisiLiniju();
}

/*Pokreni ekran, glavna funkcija.*/

void pokreniEkran()
{
    char izabirniKarakter;
    ispisiMeni("gui/glavnimeni.txt");
    printf("\n");
    printf("[(I)graj] [(E)scape] \n");
    do
    {
        scanf("%c", &izabirniKarakter);
        izabirniKarakter = tolower(izabirniKarakter);
        if(izabirniKarakter == 'i')
        {
            /*
            *=========================
            *Ovde se zove backend igre
            *=========================
            */
            igra();
            resetujBoju();
            exit(0);
        }
        else if(izabirniKarakter == 'e')
        {
            printf("Escape");
            exit(0);
        }
    }
    while(izabirniKarakter != 'i' || izabirniKarakter != 'e');
}

