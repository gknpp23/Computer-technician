#include "functions.h"

#include <math.h>

void ConvertBinDec(int dec,int *bin){

    int cont = BITS;
    int vlDec = dec;

    //inicializando vetor
    for(int i=0;i <= BITS;i++){
        bin[i] = 0;
    }

    //convers�o do n�mero decimal para binario

    do{
        bin[cont] = abs(vlDec) % 2;
        vlDec /= 2;
        cont--;

    }while(vlDec != 0);

    //representa��o do sinal do n�mero
    if(dec >= 0){
        bin[0] = 0;
    }
    else{
        bin[0] = 1;

    }



}
