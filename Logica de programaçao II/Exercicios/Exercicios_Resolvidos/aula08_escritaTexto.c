/**/

#include <stdio.h>
#include <locale.h>

int main()
{
    FILE *a;
    int sair, idade;
    float salario;

    setlocale(LC_ALL,"Portuguese");

    a = fopen("dados08.txt","r+");
    if(a==NULL)
        a = fopen("dados08.txt","w+");
    if (a!=NULL){
        fseek(a,0,SEEK_END);/*posicionando no final do arquivo*/
        do{
            printf("\nFone�a a idade: ");
            scanf("%d", &idade);

            printf("\nForne�a o sal�rio: R$");
            scanf("%f", &salario);

            fprintf(a, "%d %.2f\n", idade, salario);

            printf("\nDeseja sair? 1-Sim  2-N�o: ");
            scanf("%d", &sair);

        }while(sair!=1);

        fclose(a);
    }else
        printf("\nErro na abertura do arquivo!!!\n");

	return 0;
}
