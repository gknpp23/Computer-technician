#ifndef FUNCTIONS_PESSOA_INCLUDED
#define FUNCTIONS_PESSOA_INCLUDED
#include <stdio.h>
#include <ctype.h>
#include <string.h>

typedef struct{
    int id;
    char DatNasc[10] ;
    char Nome[100] ;
}Pessoa;

FILE *ArquivoPessoa;
int ID;


int IncludePessoa(Pessoa);
void FormataText(char*);
int NotNullOrEmpty(char*);
void RemoveEnter(char*);
int ValidData(char*);
int NameIsUniq(char*);

#endif // FUNCTIONS_PESSOA_INCLUDED
