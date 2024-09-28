/**/

#include <stdio.h>
#include <locale.h>

int main()
{
    FILE *a;
    int idade;
    float salario;

    setlocale(LC_ALL,"Portuguese");

    a = fopen("dados08.txt","r+");
    if (a!=NULL){
        fseek(a,0,SEEK_SET);/*posicionando no inicio do arquivo*/

        printf("\nDados do arquivo:\n");
        printf("Idade\tSalario\n");

        while(fscanf(a,"%d %f", &idade, &salario)==2);
            printf("%d\t%.2f\n", idade, salario);

        fclose(a);
    }else
        printf("\nErro na abertura do arquivo!!!\n");

	return 0;
}
