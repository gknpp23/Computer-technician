#include "Functions_Pessoa.h"


int NameIsUniq(char *Nome){

    Pessoa p1;
    ArquivoPessoa = fopen("ArqPessoa.dat","rb");
    if(ArquivoPessoa != NULL)
    {
        while(fread(&p1,sizeof(Pessoa),1,ArquivoPessoa) == 1){
           if(strcmp(Nome,p1.Nome)) //verificar saida da função strcmp()
            return 0;
        }
    }
    fclose(ArquivoPessoa);
}
