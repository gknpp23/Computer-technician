#include <stdio.h>
#include <locale.h>
#include <math.h>
#include "funcao.h"

int CalcMDC(int num1,int num2){
    int maior,menor,resto = 0; // variaveis locais

    if(num1 >= num2){
        maior = num1;
        menor = num2;
    }else{
        maior = num2;
        menor = num1;
    }

    //calculando o MDC atraves de divisoes sucessivas
    if(menor <= 0){
        return 0;
    }
    do{
        resto = maior % menor;

        if(resto == 0){
            return menor;
        }else{
            maior = menor;
            menor = resto;
        }
    }while(resto != 0);

    return -1;
}

int CalcMMC(int num1,int num2,int mdc){

    return (num1 * num2)/ mdc;

}

int SomaDiv(int num){

    int soma,i;
    soma = 0;

    if (num <= 0){
        return 0;
    }

    for(i=1;i <= num; i++){

        if(num % i == 0){
            soma += i;

        }
    }
    return soma;
}

int Fatorial(int num){
    int fat = 1;

    if(num <= 0){
        if(num)
            return -1;
        else
            return 1;
    }

    for(int i=num;i >= 1;i--){
        fat *= i;
    }

    return fat;

}

int CombinSimples(int n,int s){

    if((s > 1) && (n > 1)){
       if(s > n)
          return -1;

       return Fatorial(n) / (Fatorial(s) * Fatorial(n-s)) ;

    }else{
        return -1;
    }


}

int ArranjSimples(int n,int s){

    if((s > 1) && (n > 1)){

       if(s > n){

         return -1;

       }

       return Fatorial(n) /  Fatorial(n-s) ;

    }else{
        return -1;
    }
}

float Exp(float base, int exp){
    float res;
    res = base;

    if(exp <= 0){
        if(exp){
            return -1;
        }else{
            return 1;
        }
    }

    for(int i=1;i < exp; i++){
        res *= base;
    }
    return res;

}
int VerifNumPrim(int num){

    for(int i=2;i <= num/2;i++){
        if(num % i == 0){
            return 0;
        }
    }
    return 1;

}

int VerDiv(int a,int b){
    if(b==0)
        return -1;
    if(a % b)
        return -1;
    else
        return a / b;
}

int ValidData(int dia,int mes,int ano){

    if((dia > 0)&&(mes > 0)&&(ano > 8)){
        switch(mes){
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            if(dia <= 31)
                return 0;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            if(dia <= 30)
                return 0;
            break;
        case 2:
            if(ano % 400){
                if(dia <= 28)
                    return 0;
            }
            else{
                if(dia <= 29)
                    return 0;

            }
            break;
        }

    }else{
        return -1;
    }
    return -1;
}

float verTriang(float A, float B, float C){

    if((A <= 0.0) || (B <= 0.0) || (C <= 0.0)) //validando a entrada
        return -1;

    //verificando condi��o de existencia
    if(A < (B + C)){
        if(B < (A + C))
            if(C < (A + B))
                return 1;
    }

    return -1;

}

float CalcAreaTriang(float A,float B,float C,int formtr){
    float semp,area;

    if(formtr == -1)
        return -1;

    semp = (A+B+C)/2;
    area =  sqrt(semp * (semp - A) * (semp - B) * (semp - C));

    return area;


}

//Fun��o principal
int main(){

    int N1,N2,N3;
    float n1;
    float n2;
    float n3;

    setlocale(LC_ALL,"portuguese");


    /*1� exercicio
    printf("---------------- Calcula-MDC ------------------\n");

    printf("Forne�a o primeiro n�mero: ");
    scanf("%d",&n1);

    printf("Forne�a o segundo n�mero: ");
    scanf("%d",&n2);

    printf("M.D.C: %d\n",CalcMDC(n1,n2));
    */

    /*2� Exercicio
    printf("---------------- Calcula-MMC ------------------\n");

    n1 = 0;
    n2 = 0;

    printf("Forne�a o primeiro n�mero: ");
    scanf("%d",&n1);

    printf("Forne�a o segundo n�mero: ");
    scanf("%d",&n2);

    printf("\nM.M.C: %d\n",CalcMMC(n1,n2,CalcMDC(n1,n2)));
    */

    /*3� Exercicio

    printf("---------------- Soma-Divisores ------------------\n");
    n1= 0;

    printf("Forne�a um n�mero inteiro: ");
    scanf("%d",&n1);


    if(SomaDiv(n1)){
         printf("\nSoma dos divisores: %d\n",SomaDiv(n1));
    }
    else{
        printf("\nN�mero inv�lido\n");
    }
    */

    /*4� Exercicio
    printf("---------------- Combina��o-Simples ------------------\n");

    n1 = 0;
    n2 = 0;

    printf("\nForne�a o Valor de n elementos:");
    scanf("%d",&n1);

    printf("\nForne�a o Valor s de agrupamento:");
    scanf("%d",&n2);


    if(CombinSimples(n1,n2) == -1){
        printf("\n***N�o � poss�vel calcular a combina��o entre esse valores.***\n");
    }else{
        printf("\nResultado: %d combina��es poss�veis\n",CombinSimples(n1,n2));
    }
    */

    /*5� Exercicio
    printf("---------------- Arranjo-Simples ------------------\n");

    n1 = 0;
    n2 = 0;

    printf("\nForne�a o Valor de n elementos:");
    scanf("%d",&n1);

    printf("\nForne�a o Valor s de agrupamento:");
    scanf("%d",&n2);


    if(ArranjSimples(n1,n2) == -1){
        printf("\n***N�o � poss�vel calcular o Arranjo entre esse valores.***\n");
    }else{
        printf("\nResultado: %d Arranjos poss�veis\n",ArranjSimples(n1,n2));
    }
    */

    /*6� Exercicio
    printf("---------------- Potencia��o ------------------\n");

    n3 = 0;
    n2 = 0;

    printf("\nForne�a o Valor da base:");
    scanf("%f",&n3);

    printf("\nForne�a o Valor do expoente:");
    scanf("%d",&n2);


    if(Exp(n3,n2) == -1){
        printf("***Valores inv�lidos para c�lculo!***");
    }else{
        printf("\n%.1f ^ %d = %.1f\n",n3,n2,Exp(n3,n2));
    }
    */

    /*7� Exercicio
    printf("---------------- Verifica N�mero Primo ------------------\n");

    n1 = 0;

    printf("\nForne�a um n�mero:");
    scanf("%d",&n1);


    if(VerifNumPrim(n1)){
        printf("\n- O N�mero %d � PRIMO! -\n",n1);
    }else{
        printf("\n- O N�mero %d n�o � PRIMO! -\n",n1);
    }
    */

    /*8� Exercicio
    printf("---------------- Verifica divis�o ------------------\n");

    n1 = 0;
    n2 = 0;

    printf("\nForne�a o Dividendo:");
    scanf("%d",&n1);

    printf("\nForne�a o Divisor:");
    scanf("%d",&n2);

    if(VerDiv(n1,n2) != -1)
        printf("\nO N�mero %d pode ser dividido pelo n�mero %d, %d vez(es)!\n",n1,n2,VerDiv(n1,n2));
    else
        printf("\nO N�mero %d pode ser dividido pelo n�mero %d, 0 vezes!\n",n1,n2);

    */

    /*9� Exercicio
    printf("---------------- Verifica tri�ngulo ------------------\n");

    n1 = 0;
    n2 = 0;
    n3 = 0;

    printf("\nForne�a o Lado A (em cm):");
    scanf("%f",&n1);

    printf("\nForne�a o Lado B (em cm):");
    scanf("%f",&n2);

    printf("\nForne�a o Lado C (em cm):");
    scanf("%f",&n3);

    if(verTriang(n1,n2,n3) != -1)
        printf("\nOs n�meros informados formam um tri�ngulo!\n");
    else
        printf("\nOs valores informados n�o formam um tri�ngulo!\n");

    */


    /*10� Exercicio
    printf("---------------- Valida Data ------------------\n");
    N1 = 0;
    N2 = 0;
    N3 = 0;

    printf("\nForne�a o Dia:");
    scanf("%d",&N1);

    printf("\nForne�a o M�s:");
    scanf("%d",&N2);

    printf("\nForne�a o Ano:");
    scanf("%d",&N3);

    if(ValidData(N1,N2,N3) == -1){
        printf("\n***Os valores informados n�o formam uma data v�lida!***\n");
    }else{
        printf("\nData v�lida: %d/%d/%d\n",N1,N2,N3);
    }
    */



    /*11� Exercicio*/





    /*12� Exercicio*/





    /*13� Exercicio
    printf("---------------- Calcula �REA do Tri�ngulo ------------------\n");

    n1 = 0;
    n2 = 0;
    n3 = 0;

    printf("\nForne�a o Lado A (em cm):");
    scanf("%f",&n1);

    printf("\nForne�a o Lado B (em cm):");
    scanf("%f",&n2);

    printf("\nForne�a o Lado C (em cm):");
    scanf("%f",&n3);

    //verificando entrada
    if(CalcAreaTriang(n1,n2,n3,verTriang(n1,n2,n3)) == -1)
       printf("\n***As medidas fornecidas n�o formam um Tri�ngulo***\n");
    else
        printf("\n�REA do Tri�ngulo: %.1f cm^2\n",CalcAreaTriang(n1,n2,n3,verTriang(n1,n2,n3)));

    */
















    return 0;

}
