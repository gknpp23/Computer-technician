#include <string.h>
#include <ctype.h>
#include "Functions_Pessoa.h"

/*retira acentos e converte texto p/ maiúscula*/

FormataText(char *texto){

    for(int i = 0; i < strlen(texto);i++){

        texto[i] = toupper(texto[i]);

    }

    for(int i = 0; i < strlen(texto);i++){
        switch(texto[i]){
            case 'Á':
            case 'À':
            case 'Â':
            case 'Ã':
                texto[i] = 'A';
                break;

            case 'É':
            case 'È':
            case 'Ê':
                texto[i] = 'E';
                break;
            case 'Í':
            case 'Ì':
            case 'Î':
                texto[i] = 'I';
                break;
            case 'Ò':
            case 'Ó':
            case 'Ô':
            case 'Õ':
                texto[i] = 'O';
                break;
            case 'Ú':
            case 'Ù':
            case 'Û':
                texto[i] = 'U';
                break;

        }

    }

}