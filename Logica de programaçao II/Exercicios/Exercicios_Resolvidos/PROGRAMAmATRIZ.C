#define ORDEM 3

int main(){

    int matriz[ORDEM][ORDEM],linha,coluna;

    for(linha = 0; linha < ORDEM; linha++){
        for(coluna =  0; coluna < ORDEM;coluna++){
            if(linha == coluna)
                matriz[linha][coluna] = 1;
            else
                matriz[linha][coluna] = 0;
        }
    }

    printf("\nConteudo da MATRIZ:\n");






    return 0;
}
