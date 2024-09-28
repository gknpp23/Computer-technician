#include <ctype.h>
#include <string.h>
#include "Functions_Pessoa.h"

int ValidData(char *DN){

    int dia;
    int mes;
    int ano;


    //validar tamanho da data e se e toda numerica
    if(strlen(DN) != 8)
    {
        return 0;

    }
    else
    {
        for(int i = 0; i < 8;i++)
        {
            if(!isdigit(DN[i]))
            {
                return 0;
            }

        }
            // separando o dia, mes e ano

            dia = ((DN[0] - '0') * 10) + ((DN[1] - '0') * 1);

            mes = ((DN[2] - '0') * 10) + ((DN[3] - '0') * 1);

            ano = ((DN[4] - '0') * 1000) + ((DN[5] - '0') * 100) + ((DN[6] - '0') * 10) + ((DN[7] - '0') * 1);



    }



    //validar meses e dias
    switch(mes)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
             if(!(dia >= 1 && dia <= 31))
                return 0;
        break;

        case 2:
            if(ano % 4 == 0)
            {
                if(!(dia >= 1 && dia <= 29))
                    return 0;
            }
            else
            {
                if(!(dia >= 1 && dia <= 28))
                    return 0;
            }
        break;

        case 4:
        case 6:
        case 9:
        case 11:
            if(!(dia >= 1 && dia <= 30))
                return 0;
        break;

        default:
            return 0;
        break;

    }

    return 1;
}

    /*
    switch(i){
                    case 0:
                    dia[0] = DN[i];
                    break;

                    case 1:
                    dia[1] = DN[i];
                    break;

                    case 2:
                    mes[0] = DN[i];
                    break;

                    case 3:
                    mes[1] = DN[i];
                    break;

                    case 4:
                    ano[0] = DN[i];
                    break;

                    case 5:
                    ano[1] = DN[i];
                    break;

                    case 6:
                    ano[2]  = DN[i];
                    break;

                    case 7:
                    ano[3] = DN[i];
                    break;
    */




