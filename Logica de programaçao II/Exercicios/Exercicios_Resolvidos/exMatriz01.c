#include <stdio.h>
#include <locale.h>
#define LIN 2
#define COL 2

int main(){

    setlocale(LC_ALL,"portuguese");

    int matriz[LIN][COL],maior=0; // declarando variaveis

    //preenchendo a matriz
    for(int i = 0;i < LIN;i++)
        for(int k = 0; k < COL; k++){

            printf("\nForneça um número para posição %dx%d:\n",i,k);
            scanf("%d",&matriz[i][k]);
        }

    //encontrando o maior valor
    maior = matriz[0][0];
    for(int i = 0;i < LIN;i++){
        for(int k = 0; k < COL; k++)
        if(matriz[i][k] >= maior){
            maior = matriz[i][k];
        }
    }

    //exibindo a posição do maior valor
    printf("\nO maior valor da matriz e: %d\n",maior);
    for(int i = 0;i < LIN;i++)
        for(int k = 0; k < COL; k++){
            if(matriz[i][k] == maior)
                printf("\nO maior valor se encontra na(s) posição(ões): %dx%d\n",i,k);


        }

    return 0;
}
