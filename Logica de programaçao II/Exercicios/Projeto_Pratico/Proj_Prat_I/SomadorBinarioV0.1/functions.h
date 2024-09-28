#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED
#define LIM 2
#define BITS 9
/*
Implementar um somador bin�rio usando-se a representa��o de complemento de 2.
O programa deve permitir a entrada de v�rios pares de n�meros inteiros e uma opera��o(- ou +).
Para cada par de n�meros mostrar sua representa��o bin�ria(em complemento de 2) e realizar a opera��o com os dois n�meros.
O resultado deve serapresentado em bin�rio, bem como sua representa��o na base 10.
*/
void ConvertBinDec(int,int*);

void ToComplemDeDois(int*);

int SomaBin(int*,int*,int*);

int SubtBin(int*,int*,int*);

int ComparaBit(int,int);



#endif // FUNCTIONS_H_INCLUDED
