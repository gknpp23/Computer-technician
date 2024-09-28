#include <stdio.h>
#include <locale.h>
#include <string.h>
#define QuantDep 20
#define QuantFunc 1000

int main(){

        //declaração de variáveis

        int CodDP [QuantDep],cod,Sair,achou,UltPos;
        char NomeDP[QuantDep][100];
        char NomeD[100];
        char SiglaDP[QuantDep][5];

        int MatrFunc[QuantFunc];
        char NomeFunc [QuantFunc][100];
        char DNascFunc[QuantFunc][8];
        char CPF[QuantFunc][14];
        float SalarFunc [QuantFunc];
        int CodFunc [QuantFunc];

        int opcao;
        //inicialização de vetores
        for(int i = 0;i < 5;i++){
            CodDP[i] = 0;
        }

        setlocale(LC_ALL, "Portuguese");

        printf("                      -------------------------Sistema de Gestao de RH-----------------------------                 \n");

        //exibindo MENU
        printf("1 - Cadastro de Departamento\n2 - Cadastro de Funcionários\n3 - Consulta de Funcionários\n4 - Funcionários de um departamento\n5 - Excluir Funcionário\n6 - Excluir Departamento\n7 - Fim\n");

        printf("Escolha sua opção: ");
        scanf("%d",&opcao);

        //verificar se o numero digitado esta entre 1 e 7, se sim executa o codigo, senao mensagem de erro
        if(opcao >= 1 && opcao <= 7){
                switch(opcao){
                    case 1:
                        //Cadastrar código, Nome e sigla de até 20 departamentos
                        //codigo -> unico, nome != ""
                        printf("Opção escolhida: %d\n",opcao);

                        //Recebendo informações para cadastro de departamento
                        for (int i = 0; i < 5; i++)
                        {

                                printf("\nForneça o código do Departamento:\n");
                                scanf("%d",&cod);

                                //verificando se codigo de departamento e unico
                                achou=0;

                                for(int i=0;i<5;i++){
                                    //printf("%d\n",cod);
                                    if(CodDP[i]==cod){
                                            achou=1;
                                            break;
                                    }

                                }

                                if(achou == 0){
                                    CodDP[i]=cod;
                                    UltPos += 1;
                                    setbuf(stdin,NULL);

                                    //Coletando Nome do Dept.
                                    printf("Forneça o Nome do Departamento:");
                                    fgets(NomeD,100,stdin);
                                    while(strlen(NomeD) <= 1){
                                        printf("Nome de Dept. está vazio, por favor digite novamente");
                                        printf("\nForneça o Nome do Departamento:");
                                        fgets(NomeD,100,stdin);
                                    }
                                    NomeDP[UltPos][i]=NomeD;


                                }
                                else{
                                    printf("\nCodigo de departamento Repetido, por favor forneça um valor único\n");
                                }
                                printf("\nDeseja encerrar o cadastro? 1-Sim 2-Não:");
                                scanf("%d",&Sair);

                                if(Sair >= 1 && Sair <= 2)
                                {
                                    if(Sair == 1)
                                        break;

                                }else
                                    printf("Valor Inválido");


                                /*

                                printf("%d resdultado da comparacao",strcmp(&NomeD,"\n"));


                                printf("\nForneça a Sigla do Departamento:(XXX)\n");
                                //fgets(&SiglaDP[i],3,stdin);
                                setbuf(stdin,NULL);*/

                        }

                        break;

                   /* case 2:
                        //Cadastrar matricula, nome, data de nascimento, cpf, salario e codigp de funcionarios de ate 1000 funcionarios
                        // salario > 0, cpf= xxx.xxx.xxx-xx, DN = xx/xx/xx, nome != "", codDep -> CodDep(Vetor), matricula -> unica
                        //printf("Opção escolhida: %d",opcao)
                        for(int i=0;i < QuantFunc; i++){
                            printf("Forneça a matricula do Funcionários:");
                            scanf("%d",&MatrFunc[i]);

                            printf("\Digite o Nome do Funcionário:");
                            fgets(NomeFunc[i],30,stdin);


                        }

                        break;

                    case 3:

                        //mostrar os dados dos funcionarios junto com o nome do DP que possuam o nome com determinado prefixo

                        break;
                    case 4:
                        //mostrar os dados dos funcionarios de um determinado DP
                        break;
                    case 5:
                        //Excluir um funcionario a partir de sua matricula
                        break;
                    case 6:
                        //Excluir um DP a partir de seu codigo junto com todos seu funcionarios
                        break;
                    case 7:
                        //flag de saida
                        break;

                }
        //executa o codigo ate ser digitado o flag de saida:7
        /*while(){

        }*/

        }
}else
    printf("\nValor Inválido\n");

        for(int i = 0;i < 5;i++){
            //printf("\nvalor  de cod. do DP: %d\n",CodDP[i]);
            //printf("%c",NomeD[i]);
            printf("\n%s\n",NomeDP[i][i]);
        }
	return 0;
}
