#include "Functions_Pessoa.h"

int NotNullOrEmpty(char *string)
{
    if(string == NULL)
        return 0;
    if(strlen(string) <= 1)
        return 0;
    return 1;
}
