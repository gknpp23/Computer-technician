#include "functions.h"

/*
Algoritmo de subtra��o em complemento a 2
a) Complementar a 2 o subtraendo.
independentemente se � um valor positivo ou negativo.
Somar ambos os n�meros, utilizando o algoritmo da adi��o
*/


int SubtBin(int *min,int *subtr,int *SubRes){

    //inicializando vetor
    for(int i=0;i <= BITS;i++){
        SubRes[i] = 0;
    }

    //passando o subtraendo para compl. de 2
    ToComplemDeDois(subtr);

    if(SomaBin(min,subtr,SubRes) == -1)
        return -1;
    else
        SomaBin(min,subtr,SubRes);



}
