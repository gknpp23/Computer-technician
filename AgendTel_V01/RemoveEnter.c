#include "Functions_Pessoa.h"

//Funcção para substituir o \n pelo nulo da string

void RemoveEnter(char *string){

    for(int i = 0; i < strlen(string); i++)
    {
        if(string[i] == '\n')
            string[i] = '\0';

    }


}
