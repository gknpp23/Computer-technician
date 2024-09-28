#include "functions.h"

void ToComplemDeDois(int *bin){

    int cont = 0;

    //varrendo o vetor repetindo os valores até encontrar o primeiro bit com valor de 1

    for(int i=BITS-1;i >= 0;i--){
        if(bin[i]){
            cont = i;
            break;
        }
        cont++;

    }

    //invertendo o restante dos bits (exceto o de sinal)
    for(int i = 1;i <= cont;i++){
        if(bin[i])
            bin[i] = 0;
        else
            bin[i] = 1;
    }



}
