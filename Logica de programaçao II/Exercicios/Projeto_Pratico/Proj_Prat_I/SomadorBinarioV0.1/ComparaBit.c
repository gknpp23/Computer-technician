#include "functions.h"

/*
Compara dois bits, retornando um c�digo para cada situa��o, sendo:
cod    situa��o
1       1 e 1
2       0 e 0
3       1 e 0
*/
int ComparaBit(int bit1,int bit2){
    if(bit1 == bit2)
    {
        if(bit1)
            return 1;
        else
            return 2;
    }
    else
    {
        return 3;
    }
}
