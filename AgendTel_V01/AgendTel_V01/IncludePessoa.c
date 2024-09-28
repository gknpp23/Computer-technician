#include <stdio.h>
#include <stdlib.h>
#include "Functions_Pessoa.h"


/*
Incluir Dados de Uma pessoa, sendo estes:
- Id Auto-incremento
- Nome (único)
- Data de Nascimento
*/

int IncludePessoa(){

    char nome[100];
    char DN[6];
    //int id;

    printf("\nForneça o Nome:");
    fgets(&nome,100,stdin);
    setbuf(stdin,NULL);

    printf("\nForneça a data de nascimento:");
    fgets(&DN,6,stdin);
    setbuf(stdin,NULL);



    //Validação das informaçoes
    //FormataText(nome);

    /*nome nao pode ser vazio


    se tudo Ok id +1 */

    /*gravando informações no arquivo*/

    return 0;



}

