#include <stdio.h>
#include <stdlib.h>
#include "Functions_Pessoa.h"
#include "IncludePessoa.c"

int main()
{


    int op = 0;


    do{
        printf("\n--------------------------------------------------------------------------------\n");

        printf("\t\t\t\t Agenda Eletrônica\n\t\t\t\t\t_v.01_\n\n");

        printf("\n---------------------------------|Menu Principal|-------------------------------\n");

        printf("\nEscolha uma opção:\t-Incluir uma Pessoa(1)\n\t\t\ncluir um Telefone(2)\n\t\t\tIncluir um E-mail(3)\n\t\t\tPesquisar pessoas por Prefixo(4)\n\t\t\tConsultar dados de uma pessoa(5)\n\t\t\t-Encerrar(0)\n");

        printf("\nDigite o número da opção:");

        scanf("%d",&op);

        setbuf(stdin,NULL);


        if(op <= 0 || op > 5){
            printf("\n--------------------------------|Confirmar saída|-------------------------------\n");
            printf("\nDeseja Encerrar o Programa?\t-Sim(1)\n\t\t\t\t-Não(2)");
            printf("\nDigite a Opção:");
            scanf("%d",&op);
            setbuf(stdin,NULL);

            if(op == 1)

                break;
            else
                continue;
        }


        switch(op){
            case 1:
                //printf("teste1");
                //chamadas de funções
                IncludePessoa();
                break;
            case 2:
                printf("teste2");
                break;
            case 3:
                printf("teste3");
                break;
            case 4:
                printf("teste4");
                break;
            case 5:
                printf("teste5");
                break;
        }

    }while(op != 0);








    return 0;
}
