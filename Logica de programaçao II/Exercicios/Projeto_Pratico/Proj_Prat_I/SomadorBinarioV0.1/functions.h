#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED
#define LIM 2
#define BITS 9
/*
Implementar um somador binário usando-se a representação de complemento de 2.
O programa deve permitir a entrada de vários pares de números inteiros e uma operação(- ou +).
Para cada par de números mostrar sua representação binária(em complemento de 2) e realizar a operação com os dois números.
O resultado deve serapresentado em binário, bem como sua representação na base 10.
*/
void ConvertBinDec(int,int*);

void ToComplemDeDois(int*);

int SomaBin(int*,int*,int*);

int SubtBin(int*,int*,int*);

int ComparaBit(int,int);



#endif // FUNCTIONS_H_INCLUDED
