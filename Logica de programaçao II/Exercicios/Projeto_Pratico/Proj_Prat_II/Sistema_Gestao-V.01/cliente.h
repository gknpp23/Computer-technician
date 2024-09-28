#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED
#define viD 1

typedef struct{
    unsigned long Id;
    char Nome[100];
    char CPF[11];
    char Email[50];
    char Telefone[15];

}Cliente;

FILE *ArqCliente;



int CadastroCliente(int *reg);
int ConsultaCliente();
int ValidCPF(char*);
int ValidTelefone(char*);
int Pesq(char*,FILE*);

#endif // CLIENTE_H_INCLUDED
