#include "cliente.h"
#include <string.h>
/*
Valida um CPF com base no algoritmo utilizado pelo Minis. da Fazenda
Retorno:
**  1 para CPFs v�lidos
**  0 caso n�o passe na valida��o ou possua todos os digitos iguais;
**
*/
int ValidCPF(char *CPF){

    //Declara��o de variaveis
    int vetAux[11];
    int ver = 10;
    int res = 0;
    int igual = 1;


    //Convertendo char para int
    for(int i=0; i < 11; i++)
    {
        if(isalpha(CPF[i]))
            return 0;
        vetAux[i] = CPF[i] - '0';
    }

    //verificando se todos digitos sao iguais
    for(int i=0; i < 11; i++){
        if(vetAux[i] == vetAux[i+1])
            igual += 1;
    }

    //validando o primeiro digito verificador
    for(int i=0; i < 9; i++)
    {
        res += vetAux[i] * ver;
        ver--;
    }

    if(((res * 10) % 11 == vetAux[9]) && (igual != 11))
    {

        //Validando o segundo digito verificador
        res = 0;
        ver = 11;

        for(int i=0; i < 10; i++)
        {
            res += vetAux[i] * ver;
            ver--;
        }

        if((res * 10) % 11 == vetAux[10])
        {
             return 1;
        }
    }
    else{
        return 0;
    }

}
