#include <stdbool.h>

#ifndef FRONTEND_H_INCLUDED
#define FRONTEND_H_INCLUDED
//Ovde ubacujes funkcije za frontend.c

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
void ispisiIgrackoPolje(bool igracevoPolje[][11]);
int pitajZaGadjanje(void);
int pitajZaLokaciju(void);
void ispisiIgrackoPoljeCrveni(bool igracevoPolje[][11]);
void ispisiIgrackoPoljePlavi(bool igracevoPolje[][11]);
bool proveriMesto(int velicina, int red, int kolona);
void dodajBrod(bool igracevoPolje[][11], int red, int kolona,int velicina);
void napuniMatricu(bool igracevoPolje[][11], bool plaviIgrac);
#endif // BACKEND_H_INCLUDED
