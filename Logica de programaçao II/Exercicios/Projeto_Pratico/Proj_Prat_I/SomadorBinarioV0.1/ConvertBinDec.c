#include "functions.h"

#include <math.h>

void ConvertBinDec(int dec,int *bin){

    int cont = BITS;
    int vlDec = dec;

    //inicializando vetor
    for(int i=0;i <= BITS;i++){
        bin[i] = 0;
    }

    //conversão do número decimal para binario

    do{
        bin[cont] = abs(vlDec) % 2;
        vlDec /= 2;
        cont--;

    }while(vlDec != 0);

    //representação do sinal do número
    if(dec >= 0){
        bin[0] = 0;
    }
    else{
        bin[0] = 1;

    }



}
