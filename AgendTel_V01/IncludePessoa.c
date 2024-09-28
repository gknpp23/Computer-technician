#include <stdio.h>
#include <stdlib.h>
#include "Functions_Pessoa.h"
#include "ValidData.c"
#include "nameIsUniq.c"


/*
Incluir Dados de Uma pessoa, sendo estes:
- Id Auto-incremento
- Nome (único)
- Data de Nascimento valida
*/

int IncludePessoa(Pessoa p1){


    ArquivoPessoa = fopen("ArqPessoa.dat","rb");
    if(ArquivoPessoa != NULL)
    {
        while(fread(&p1,sizeof(Pessoa),1,ArquivoPessoa) == 1){
            ID += 1; //id está funcionando porem bate um a menos
        }
    }
    fclose(ArquivoPessoa);

    ArquivoPessoa = fopen("ArqPessoa.dat","ab");

    if(ArquivoPessoa == NULL)
    {

        return 0;
    }
    else
    {
        printf("\nForneça o Nome:");
        fgets(p1.Nome,100,stdin);
        setbuf(stdin,NULL);
        RemoveEnter(&p1.Nome);
        //verificar se o nome e unico
        NameIsUniq(p1.Nome);

        printf("\nForneça a Data de Nascimento(DDMMAAAA):");
        fgets(p1.DatNasc,10,stdin);
        setbuf(stdin,NULL);
        RemoveEnter(&p1.DatNasc);



        //Validação/Formatação das informaçoes

        if(!NotNullOrEmpty(&p1.Nome) || !NotNullOrEmpty(&p1.DatNasc)){
            return 0;

        }
        FormataText(p1.Nome); // erro na retirada de acentos, possivel erro leitura de entrada de dados

        //validar Data
        if(!ValidData(p1.DatNasc))
        {
            return 0;
        }

        //incrementar Id

        p1.id = ID;


        //gravando no arquivo



        fwrite(&p1,sizeof(Pessoa),1,ArquivoPessoa);


    }

    fclose(ArquivoPessoa);







    //printf("Nome: %s",p1.Nome);


    /*
    se tudo Ok id +1 */

    /*gravando informações no arquivo*/

    return 1;



}

