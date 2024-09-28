#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "cliente.h"
#include "Cliente.c"
#include "FormataText.c"
#include "ValidCPF.c"

//"CRUD (acrónimo do inglês Create, Read, Update and Delete)  das   tabelas(arquivos c/ registros)   Clien
//te,   Produto,Vendedor e Fornecedor"
// Fazer a manutenção das tabelas Cliente (cadastro, alteração, consulta e Listagem).A consulta deve ser feita pelo id, CPF e o prefixo do nome.
//ID é auto-incremento e cpf e unico

int main()
{
    int op = 0;
    int tb = 0;
    char CPF[12];
    unsigned long *IdCliente;
    Cliente cli;
    setlocale(LC_ALL,"Portuguese");

    //solução para setar acentuação na entrada de dados
    SetConsoleCP(1252);                                 //Estabelecendo o codepage de entrada 1252(latin2)
    SetConsoleOutputCP(1252);

    do
    {
         //Menu de Opções
        printf("\n==================================================| Sistema de Gestão |=================================================\n\t\t\t\t\t\t\t   v0.1\n\n");

        printf("-----------------------------------------------------------//-----------------------------------------------------------");
        printf("\nQual operação deseja realizar?\t1 - Cadastrar\n\t\t\t\t2 - Consultar\n\t\t\t\t3 - Atualizar\n\t\t\t\t4 - Excluir\n\t\t\t\t5 - Encerrar\n");
        printf("\nDigite: ");
        scanf("%d",&op);

        if(op == 5)
            break;

        setbuf(stdin,NULL);
        printf("-----------------------------------------------------------//-----------------------------------------------------------");
        printf("\nSelecione a Tabela:\t\t1 - Cliente\n\t\t\t\t2 - Produto\n\t\t\t\t3 - Vendedor\n\t\t\t\t4 - Fornecedor");
        printf("\nDigite: ");
        scanf("%d",&tb);
        setbuf(stdin,NULL);
        printf("-----------------------------------------------------------//-----------------------------------------------------------");


        //Escolha de Opções e chamadas de Funções
        switch(tb)
        {
        case 1:
            switch(op)
            {
            case 1:
                if(CadastroCliente(&IdCliente))
                {
                    printf("\n-------------------------------------------------- Cadastro Encerrado -------------------------------------------------\n");
                }
                else
                {
                    IdCliente += 1;
                    printf("\n-------------------------------------------- Cadastro Realizado com Sucesso! -------------------------------------------\n");
                    printf("\nDeseja:\t\t1 - Cadastrar um novo cliente\n\t\t2 - Voltar ao Menu Principal\n");
                    printf("\nDigite:");
                    scanf("%d",&op);
                    setbuf(stdin,NULL);

                    while(op == 1)
                    {
                        CadastroCliente(&IdCliente);
                        printf("\n-------------------------------------------- Cadastro Realizado com Sucesso! -------------------------------------------\n");
                        printf("\nDeseja:\t\t1 - Cadastrar um novo cliente\n\t\t2 - Voltar ao Menu Principal\n");
                        scanf("%d",&op);
                        setbuf(stdin,NULL);
                    }
                    continue;
                }
                break;
            case 2:
                //ConsultaCliente();
                break;
            case 3:
                //AtualizaCliente();
                break;
            case 4:
                //ExcluirCliente();
                break;
            }
            break;
        case 2:
            switch(op)
            {
            case 1:
                //CadastroProduto();
                break;
            case 2:
                //ConsultaProduto();
                break;
            case 3:
                //AtualizaProduto();
                break;
            case 4:
                //ExcluirProduto();
                break;
            }
            break;
        case 3:
            switch(op)
            {
            case 1:
                //CadastroVend();
                break;
            case 2:
                //ConsultaVend();
                break;
            case 3:
                //AtualizaVend();
                break;
            case 4:
                //ExcluirVend();
                break;
            }
            break;
        case 4:
            switch(op)
            {
            case 1:
                //CadastroForn();
                break;
            case 2:
                //ConsultaForn();
                break;
            case 3:
                //AtualizaForn();
                break;
            case 4:
                //ExcluirForn();
                break;
            }
            break;
    }

    }while(op != 5);

    /*//Menu de Opções
    printf("\n==================================================| Sistema de Gestão |=================================================\n\t\t\t\t\t\t\t   v0.1\n\n");

    printf("-----------------------------------------------------------//-----------------------------------------------------------");
    printf("\nQual operação deseja realizar?\t1 - Cadastrar\n\t\t\t\t2 - Consultar\n\t\t\t\t3 - Atualizar\n\t\t\t\t4 - Excluir\n\t\t\t\t5 - Encerrar\n");
    printf("\nDigite: ");
    scanf("%d",&op);
    if(op == 5)
        break;
    setbuf(stdin,NULL);
    printf("-----------------------------------------------------------//-----------------------------------------------------------");
    printf("\nSelecione a Tabela:\t\t1 - Cliente\n\t\t\t\t2 - Produto\n\t\t\t\t3 - Vendedor\n\t\t\t\t4 - Fornecedor");
    printf("\nDigite: ");
    scanf("%d",&tb);
    setbuf(stdin,NULL);
    printf("-----------------------------------------------------------//-----------------------------------------------------------");


    //Escolha de Opções e chamadas de Funções
    switch(tb)
    {
    case 1:
        switch(op)
        {
        case 1:

            CadastroCliente();
            break;
        case 2:
            //ConsultaCliente();
            break;
        case 3:
            //AtualizaCliente();
            break;
        case 4:
            //ExcluirCliente();
            break;
        }
        break;
    case 2:
        switch(op)
        {
        case 1:
            //CadastroProduto();
            break;
        case 2:
            //ConsultaProduto();
            break;
        case 3:
            //AtualizaProduto();
            break;
        case 4:
            //ExcluirProduto();
            break;
        }
        break;
    case 3:
        switch(op)
        {
        case 1:
            //CadastroVend();
            break;
        case 2:
            //ConsultaVend();
            break;
        case 3:
            //AtualizaVend();
            break;
        case 4:
            //ExcluirVend();
            break;
        }
        break;
    case 4:
        switch(op)
        {
        case 1:
            //CadastroForn();
            break;
        case 2:
            //ConsultaForn();
            break;
        case 3:
            //AtualizaForn();
            break;
        case 4:
            //ExcluirForn();
            break;
        }
        break;
    }*/




    //Area de Testes
    /*
    printf("\nForneça o CPF do Cliente:\n");
    fgets(CPF,12,stdin);
    setbuf(stdin,NULL);
    */
    ArqCliente = fopen("Cliente.dat","rb");
    while(fread(&cli,sizeof(Cliente),1,ArqCliente))
        printf("\nExemplo: %d\n",cli.Id);


    return 0;

}
