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
int ispisiIgrackoPolje(bool igracevoPolje[][11]);
int ispisiIgrackoPoljeCrveni(bool igracevoPolje[][11]);
int ispisiIgrackoPoljePlavi(bool igracevoPolje[][11]);
void napuniMatricu(bool igracevoPolje[][11]);
#endif // BACKEND_H_INCLUDED
