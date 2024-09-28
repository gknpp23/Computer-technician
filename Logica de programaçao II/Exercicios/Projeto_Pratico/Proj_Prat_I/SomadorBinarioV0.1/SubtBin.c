#include "functions.h"

/*
Algoritmo de subtração em complemento a 2
a) Complementar a 2 o subtraendo.
independentemente se é um valor positivo ou negativo.
Somar ambos os números, utilizando o algoritmo da adição
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
