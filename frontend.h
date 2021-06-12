#include <stdbool.h>

#ifndef FRONTEND_H_INCLUDED
#define FRONTEND_H_INCLUDED
//Ovde se ubacuju funkcije za frontend.c

#define PLAVI_BOJE 97
#define CRVENI_BOJE 47

void cls(void);
void color(char opcije[]);
void pokreniEkran(void);
void pokreniIgru(void);
void crveni(void);
void plavi(void);
void resetujBoju(void);
void ispisiMeni(char imeFajla[]);
void ispisiIgrackoPolje(bool igracevoPolje[][6]);
void ispisiIgrackoPoljeCrveni(bool igracevoPolje[][6]);
void ispisiIgrackoPoljePlavi(bool igracevoPolje[][6]);
bool proveriMesto(int velicina, int red, int kolona);
void dodajBrod(bool igracevoPolje[][6], int red, int kolona,int velicina);
void popuniNBrodova(int n, bool igracevoPolje[][6]);
void napuniMatricu(bool igracevoPolje[][6], bool plaviIgrac);
void debug(char poruka[]);
#endif // BACKEND_H_INCLUDED
