#include <stdbool.h>
#include <windows.h>

#ifndef BACKEND_H_INCLUDED
#define BACKEND_H_INCLUDED
//Ovde ubacujes funkcije za backend.c

bool poljePlavogIgraca[11][7];
bool poljeCrvenogIgraca[11][7];
int plaviBrodovi;
int crveniBrodovi;
void igra(void);

#define REDOVI 6
#define KOLONE 6

#endif // BACKEND_H_INCLUDED
