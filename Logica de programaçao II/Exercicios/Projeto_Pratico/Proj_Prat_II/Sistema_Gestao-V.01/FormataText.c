#include <string.h>
#include <ctype.h>


FormataText(char *texto){

    for(int i = 0; i < strlen(texto);i++){

        texto[i] = toupper(texto[i]);

    }

    for(int i = 0; i < strlen(texto);i++){
        switch(texto[i]){
            case '�':
            case '�':
            case '�':
            case '�':
                texto[i] = 'A';
                break;

            case '�':
            case '�':
            case '�':
                texto[i] = 'E';
                break;
            case '�':
            case '�':
            case '�':
                texto[i] = 'I';
                break;
            case '�':
            case '�':
            case '�':
            case '�':
                texto[i] = 'O';
                break;
            case '�':
            case '�':
            case '�':
                texto[i] = 'U';
                break;

        }

    }

}


