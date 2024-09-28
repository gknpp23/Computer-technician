#include "functions.h"

/*
Algoritmo de adi��o em complemento a 2
a)Somar os dois n�meros, bit a bit, inclusive o bit de sinal
***b)Desprezar o �ltimo vai 1(para fora do n�mero), se houver.
**c)Se, simultaneamente, ocorrer vai 1 para o bit de sinal e vai 1 para fora do n�mero, ou se ambos n�o ocorrerem, o resultado est� correto.
**d)Se ocorrer apenas um dos vai 1, o resultado est� incorreto. Ocorreu overflow.
O overflow somente pode ocorrer se ambos os n�meros tiverem o mesmo sinal e, nesse, caso, se o sinal do resultado for oposto ao dos n�meros.
*/

int SomaBin(int *bin1,int *bin2,int *binRes){

    int codComp;
    int vai1 = 0;
    int valid = 0;

    //inicializando vetor
    for(int i=0;i <= BITS;i++){
        binRes[i] = 0;
    }

    for(int i=BITS;i >= 0;i--){

        codComp = ComparaBit(bin1[i],bin2[i]);

        if(vai1)
        {
            codComp = ComparaBit(binRes[i+1],vai1);


        }

        //verificando se houve vai 1 no numero
        switch(codComp)
        {
            case 1:
                binRes[i] = 0;
                vai1 = 1;

                if(i <= 0)
                    valid++;

                break;

            case 2:
                binRes[i] = 0;
                vai1 = 0;
                break;

            case 3:
                binRes[i] = 1;
                vai1 = 0;
                break;

        }


    }
    if(valid == 1)
            return -1;
}
























/*if(bin1[i] == 0 && bin2[i] == 0)
        {

            binResult[i] = 1;
            vai1 = 0;

        }
        else
        {

            if(bin1[i] == 1 || bin2[i] == 1)
            {

                if(bin1[i] == 0 || bin2[i] == 0)
                {

                    binResult[i] = 1;
                    vai1 = 0;

                }
                else
                {

                    binResult[i] = 0;
                    vai1= 1;
                }
            }
        }*/
