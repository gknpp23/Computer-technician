#include <stdio.h>
#include <locale.h>
#define LIN 3
#define COL 2

int main(){

    setlocale(LC_ALL,"portuguese");

    int SomLin[LIN],SomCol[COL],matriz[LIN][COL];

    //inicializando vetores de soma coluna e soma linha
    for(int i=0; i < LIN; i++)
        SomLin[i] = 0;


    for(int i = 0; i < COL; i++)
        SomCol[i] = 0;


    //preenchenco a matriz
    printf("\n-------------------- Forneça os dados ------------------------\n");
    for(int i = 0; i < LIN; i++)
        for(int k = 0; k < COL; k++){
            printf("\nForneça um valor inteiro para posição %dx%d:",i+1,k+1);
            scanf("%d",&matriz[i][k]);
        }

    //fazendo o somatorio da linha e colunas

    for(int i=0;i < LIN; i++){
        for(int k=0; k < COL; k++){
            SomLin[i] += matriz[i][k]; // somando as linhas
            SomCol[k] += matriz[i][k]; //somando as colunas
        }
    }

    //Imprimindo a SOMA
    printf("\n-------------------- Soma ---------------------\n");
    for(int i = 0; i < LIN; i++)
        printf("soma da linha %d: %d\n",i+1,SomLin[i]);

    printf("\n");

    for(int i = 0; i < COL; i++)
        printf("soma da coluna %d: %d\n",i+1,SomCol[i]);

    return 0;
}
