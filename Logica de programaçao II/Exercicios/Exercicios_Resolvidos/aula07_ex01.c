/*Faça um programa que possua o menu:
1 - Cadastro
2 - Consulta
3 - Alterar
4 - Listar
5 - Fim

caso a opção selecionada seja:
1 - Cadastro de matricula, nome e salario de no max 30 funcionários. Matrícula é única
2 - Pedir um valor ao user e mostrar os dados do funcionario da determinada matricula
3 - Pede um valor e exclui o funcionario
4 - Lista os dados de todos os funcionários*/

#include <stdio.h>
#include <string.h>
#include <locale.h>

typedef struct{
    int matricula;
    char nome[100];
    float salario;
}TFuncionario;

void retiraEnter(char s[]){
    if(s[strlen(s)-1]=='\n')
        s[strlen(s)-1] = '\0';
}

/*Rotina que verifica a existência de um funcionário com determinada matricula.
Valores de retorno:
-1 caso não encontre ou a posição relativa no registro no caso de encontrar.*/
int pesquisa(FILE *a, int mat){
    int posicao = 0;
    TFuncionario r;

    /*Posicionando no inicio do arquivo*/
    fseek(a, 0, SEEK_SET); /*rewind(a);  ->  move a marca do bit corrente para o inicio*/

    while(fread(&r, sizeof(TFuncionario), 1, a)==1){
        if(r.matricula==mat)
            return posicao;
        else
            posicao++;
    }

    return -1;
}

void cadastrar(FILE *a){
    int sair, m;
    TFuncionario rf;

    do{
        printf("\nForneça a matrícula: ");
        scanf("%d", &m);

        if(pesquisa(a, m)==-1){
            rf.matricula=m;
            setbuf(stdin,NULL);

            printf("Forneça o nome: ");
            fgets(rf.nome,100,stdin);
            retiraEnter(rf.nome);
            setbuf(stdin,NULL);

            printf("Forneça o salário: ");
            scanf("%f", &rf.salario);

            /*Posicionando no final do arquivo*/
            fseek(a,0,SEEK_END);
            fwrite(&rf,sizeof(TFuncionario),1,a);

        }else
            printf("\nMatrícula repetida!!!\n");

        printf("\nDeseja abandonar o cadastro? 1-Sim 2-Não:");
        scanf("%d", &sair);

    }while(sair!=1);

}

void alterar(FILE *a){
    int sair, m, posicao;
    TFuncionario rf;

    do{
        printf("\nForneça a matrícula:");
        scanf("%d", &m);

        posicao = pesquisa(a, m);
        if(posicao!=-1){
            printf("\nForneça o novo nome: ");
            setbuf(stdin,NULL);
            fgets(rf.nome,100,stdin);
            retiraEnter(rf.nome);
            setbuf(stdin,NULL);

            printf("Forneça o novo salário: ");
            scanf("%f",&rf.salario);

            rf.matricula = m;

            /*Posicionando no registro com o campo matrícula igual ao valor da variável m*/
            fseek(a, posicao*sizeof(TFuncionario), SEEK_SET);
            fwrite(&rf, sizeof(TFuncionario), 1, a);

            printf("\nAlteração completada!!\n");
        }else
            printf("\nMatrícula inexistente!!!\n");

        printf("\nDeseja abandonar a alteração? 1-Sim 2-Não:");
        scanf("%d", &sair);

    }while(sair!=1);
}

void consultar(FILE *a){
    int sair, m, posicao;
    TFuncionario rf;

    /*Verificando se o arquivo está vazio*/
    fseek(a, 0, SEEK_END);
    if(ftell(a)>0){
        do{
            printf("\nForneça a matrícula:");
            scanf("%d", &m);

            posicao = pesquisa(a, m);
            if(posicao!=-1){
                /*Posicionando no registro com o campo matrícula igual ao valor da variável m*/
                fseek(a, posicao*sizeof(TFuncionario), SEEK_SET);
                fread(&rf, sizeof(TFuncionario), 1, a);

                printf("\nDados do funcionário:\n");

                printf("Matrícula = %d", rf.matricula);
                printf("\nNome = %s", rf.nome);
                printf("\nSalário = %.2f\n", rf.salario);
            }else
                printf("\nMatrícula inexistente!!!\n");

            printf("\nDeseja abandonar a consulta? 1-Sim 2-Não:");
            scanf("%d", &sair);

        }while(sair!=1);
    }else
        printf("\nNenhum funcionário cadastrado!!\n");
}

void listar (FILE *a){
    TFuncionario rf;

    fseek(a,0,SEEK_SET);
    printf("\nMatrícula\tNome\t\t\t\tSalário\n");
    while(fread(&rf,sizeof(TFuncionario),1,a)==1)
        printf("%d\t\t%s\t\t\t\t%.2f\n", rf.matricula, rf.nome, rf.salario);


}

int main(){
    FILE *arq;
    int opcao;

	setlocale(LC_ALL,"Portuguese");

	arq=fopen("dados.dat", "rb+");
	if(arq==NULL)
        arq=fopen("dados.dat", "wb+");

    fseek(arq,0,SEEK_END);
    printf("\nNúmero de registros no arquivo = %d\n", ftell(arq)/sizeof(TFuncionario));

    if(arq!=NULL){
        do{
            printf("\n\n1-Cadastro\n2-Consulta\n3-Alterar\n4-Listar\n5-Fim\n");
            printf("Forneça sua opção: ");
            scanf("%d", &opcao);

            switch(opcao){
            case 1:
                cadastrar(arq);
                break;
            case 2:
                consultar(arq);
                break;
            case 3:
                alterar(arq);
                break;
            case 4:
                listar(arq);
                break;
            }

        }while(opcao!=5);
        fclose(arq);
    }else
        printf("\nErro na abertura do arquivo!!!\n");

	return 0;
}

