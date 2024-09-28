#include <stdio.h>
#include <locale.h>

/*Calcular area de retangulo*/

float CalcAreaRet(float largura, float altura){

    if(largura <= 0 || altura <= 0){
        return 0;
    }
    return largura*altura;
}

int main(){
    float alt=0,larg=0;

    setlocale(LC_ALL,"portuguese");

    printf("\nDigite o valor da altura do retângulo (cm):");
    scanf("%f",&alt);

    printf("\nDigite o valor da largura do retângulo (cm):");
    scanf("%f",&larg);

    if(CalcAreaRet(larg,alt)){
        printf("Área do retangulo é: %.2fcm^2",CalcAreaRet(larg,alt));
    }
    else{
        printf("Valores Inválidos!");
    }


    return 0;
}
