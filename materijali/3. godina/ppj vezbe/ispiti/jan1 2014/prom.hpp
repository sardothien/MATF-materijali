#ifndef _PROMENLJIVE_
#define _PROMENLJIVE_

#include<string>
using namespace std;

#define INT 12345
#define LISTA 67890

typedef struct {
  char* ime;
  void* vred;
} promenljiva;

void  sacuvaj(char*, void*, int);
void* nadji(char*);

#endif
