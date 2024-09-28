#include "cliente.h"
#include "RemoveEnter.c"
#include "NotNullOrEmpty.c"
#include "ValidTelefone.c"
#include <string.h>

int CadastroCliente(int *reg){

    Cliente c;
    int op = 0;

    ArqCliente = fopen("Cliente.dat","ab");

    if(ArqCliente == NULL)
        ArqCliente = fopen("Cliente.dat","wb");

    if(ArqCliente != NULL)
    {


        printf("\nForneça o Nome do Cliente:\n");
        fgets(c.Nome,100,stdin);
        setbuf(stdin,NULL);
        RemoveEnter(&c.Nome);
        FormataText(&c.Nome);

        if(!NotNullOrEmpty(&c.Nome))
        {

            do
            {
                printf("\n\t\t\t\t\t\t***Nome Inválido***\n\n");

                //opção de oferecer nome novamente ou encerrar cadastro;
                printf("Selecione um opção:\t1 - Fornecer um novo Nome\n\t\t\t2 - Encerrar Cadastro\n");
                op = 0;
                printf("\nDigite:");
                scanf("%d",&op);
                setbuf(stdin,NULL);

                if(op == 2)
                {

                    return 1;
                }
                else
                {
                     printf("\nForneça o Nome do Cliente:\n");
                     fgets(c.Nome,100,stdin);
                     setbuf(stdin,NULL);
                     RemoveEnter(&c.Nome);
                     FormataText(&c.Nome);

                }

            }while(!NotNullOrEmpty(&c.Nome));
        }


        printf("\nForneça o CPF do Cliente:\n");
        fgets(c.CPF,12,stdin);
        setbuf(stdin,NULL);
        RemoveEnter(&c.CPF);


        if(!ValidCPF(&c.CPF))
            //bug do cpf salvo junto com email
            // verificar se cpf é unico
        {

            do
            {
                printf("\n\t\t\t\t\t\t***CPF Inválido***\n\n");

                //opção de oferecer CPF novamente ou encerrar cadastro;
                printf("Selecione um opção:\t1 - Fornecer um novo CPF\n\t\t\t2 - Encerrar Cadastro\n");
                op = 0;
                printf("\nDigite:");
                scanf("%d",&op);
                setbuf(stdin,NULL);

                if(op == 2)
                {

                    return 1;
                }
                else
                {
                    printf("\nForneça o CPF do Cliente:\n");
                    fgets(c.CPF,12,stdin);
                    setbuf(stdin,NULL);
                    RemoveEnter(&c.CPF);

                }

            }while(!ValidCPF(&c.CPF));
        }


        printf("\nForneça o E-mail do Cliente:\n");
        fgets(c.Email,50,stdin);
        setbuf(stdin,NULL);
        RemoveEnter(&c.Email);
        FormataText(&c.Email);

        if(!NotNullOrEmpty(&c.Email))
        {

            do
            {
                printf("\n\t\t\t\t\t\t***E-mail Inválido***\n\n");

                //opção de oferecer email novamente ou encerrar cadastro;
                printf("Selecione um opção:\t1 - Fornecer um novo E-mail\n\t\t\t2 - Encerrar Cadastro\n");
                op = 0;
                printf("\nDigite:");
                scanf("%d",&op);
                setbuf(stdin,NULL);

                if(op == 2)
                {

                    return 1;
                }
                else
                {
                     printf("\nForneça o E-mail do Cliente:\n");
                     fgets(c.Email,50,stdin);
                     setbuf(stdin,NULL);
                     RemoveEnter(&c.Email);
                     FormataText(&c.Email);

                }

            }while(!NotNullOrEmpty(&c.Email));
        }


        printf("\nForneça o Telefone do Cliente:\n");
        fgets(c.Telefone,15,stdin);
        setbuf(stdin,NULL);
        RemoveEnter(&c.Telefone);


        if(!ValidTelefone(&c.Telefone))
        {

            do
            {
                printf("\n\t\t\t\t\t\t***Telefone Inválido***\n\n");

                //opção de oferecer telefone novamente ou encerrar cadastro;
                printf("Selecione um opção:\t1 - Fornecer um novo Telefone\n\t\t\t2 - Encerrar Cadastro\n");
                op = 0;
                printf("\nDigite:");
                scanf("%d",&op);
                setbuf(stdin,NULL);

                if(op == 2)
                {

                    return 1;
                }
                else
                {
                    printf("\nForneça o Telefone do Cliente:\n");
                    fgets(c.Telefone,15,stdin);
                    setbuf(stdin,NULL);
                    RemoveEnter(c.Telefone);


                }

            }while(!ValidTelefone(&c.Telefone));
        }
     }
    else
    {
        printf("\n\t\t\t\t\t\t***Erro ao Abrir o Registro!***\n\n");
    }



   //auto-incremento do ID


   fwrite(&c,sizeof(Cliente),1,ArqCliente);

   fclose(ArqCliente);

    return 0;
}



int ConsultaCliente(){
    //receber ID, CPF ou Prefixo do nome para consulta

    //a partir da entrada, percorrer o arquivo de clientes
    //caso o cliente seja encontrado, exibi-lo
    //caso negativo, retornar codigo de erro
    //opcao de consultar novamente ou abandonar consulta
}

/*
Atualizar();

Deletar();
*/

