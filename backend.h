#include <stdbool.h>
#include <windows.h>

#ifndef BACKEND_H_INCLUDED
#define BACKEND_H_INCLUDED
//Ovde ubacujes funkcije za backend.c

void pitajZaLokaciju(int * red, int * kolona);
int prebrojBrodove(bool poljeIgraca[][6]);
void pucaj(bool plaviIgac);
void crvenoPlavo(void);
void igra(void);

#define REDOVI 6
#define KOLONE 6

#endif // BACKEND_H_INCLUDED
