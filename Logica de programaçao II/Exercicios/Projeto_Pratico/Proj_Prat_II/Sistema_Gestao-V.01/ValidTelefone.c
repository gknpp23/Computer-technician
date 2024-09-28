#include "cliente.h"
#include <string.h>
/*Função para Validação simples um telefone celular
Retorno:
        0 - Telefone Inválido (contém letras)
        1 - Telefone válido, possui Apenas 15 algarismos
*/
int ValidTelefone(char *Tel)
{

    if(strlen(Tel) < 13)
    {
        return 0;
    }
    else
    {
        for(int i=0;i < strlen(Tel);i++)
        {
            if(isalpha(Tel[i]))
                return 0;
        }
    }
    return 1;

}
