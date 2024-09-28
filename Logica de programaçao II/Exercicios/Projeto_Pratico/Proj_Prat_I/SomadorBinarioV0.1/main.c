#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "functions.h"
#include "ConvertBinDec.c"
#include "ToComplemDeDois.c"
#include "ComparaBit.c"
#include "SomaBin.c"
#include "SubtBin.c"

int main()
{
    setlocale(LC_ALL,"Portuguese");

    int vetDec[LIM];

    int matBin[LIM][BITS];

    int resultado[BITS];

    int op;

    int saida = -1;

    //entrada de dados
    do{

        printf("\n\t---------------Somador_Bin�rio-------------------\n");

        printf("\nDigite o 1� n�mero inteiro:\n");
        scanf("%d",&vetDec[0]);

        printf("\nDigite o 2� n�mero inteiro:\n");
        scanf("%d",&vetDec[1]);

        printf("\nQual Opera��o deseja realizar? 1 - Adi��o ou 2 - Subtra��o:\n");
        scanf("%d",&op);

        //Convertendo os valores decimais para bin�rios

        ConvertBinDec(vetDec[0],matBin[0]);
        ConvertBinDec(vetDec[1],matBin[1]);

        if(vetDec[1] < 0)
            ToComplemDeDois(matBin[1]);


        //realizando a opera��o escolhida
        if(op == 1){
            if(SomaBin(matBin[0],matBin[1],resultado) == -1){
                printf("N�o � poss�vel calcular o resultado!");
            }else{
                SomaBin(matBin[0],matBin[1],resultado);
            }

        }else{
            if(SubtBin(matBin[0],matBin[1],resultado) == -1){
                printf("N�o � poss�vel calcular o resultado!");
            }else{
                SubtBin(matBin[0],matBin[1],resultado);
            }


        }

        //impress�o de resultados
        printf("\nPrimeiro numero convertido");
        for(int i=0;i <= BITS;i++){

            printf("%d\n",matBin[0][i]);

        }

        printf("\nSegundo n�mero convertido");

        for(int i=0;i <= BITS;i++){

            printf("%d\n",matBin[1][i]);

        }

        printf("\nResultado (em Bin�rio)");
        for(int i=0;i <= BITS;i++){

            printf("%d\n",resultado[i]);

        }

        printf("\nResultado (em Decimal):");
        if(op == 1)
            printf("\t%d",vetDec[0] + vetDec[1]);
        else
           printf("\t%d",vetDec[0] - vetDec[1]);

        printf("\nDeseja executar novamente? 1 - Sim ; 2 - N�o:\n");
        scanf("%d",&saida);


    }while(saida != 2);

    return 0;
}
