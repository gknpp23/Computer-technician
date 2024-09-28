#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>
#define QuantPessoa 10
#define Regist 10
#define AnoAtual 2020

char* FormNome(char Nome[50],int tam){
        //retirando acentos e passando para LETRAS MAIUSCULAS
        for(int i=0;i < tam; i++){
            Nome[i] = toupper(Nome[i]);
            switch(Nome[i]){

            case 'À':
            case 'Á':
            case 'Â':
            case 'Ã':
                Nome[i] = 'A';
                break;

            case 'É':
            case 'Ê':
            case 'È':
                Nome[i] = 'E';
                break;

            case 'Í':
            case 'Î':
            case 'Ì':
                Nome[i] = 'I';
                break;

            case 'Ó':
            case 'Ò':
            case 'Ô':
            case 'Õ':
                Nome[i] = 'O';
                break;

            case 'Ú':
            case 'Ù':
            case 'Û':
                Nome[i] = 'U';
                break;
                }
            }
            return(Nome);
}

int main(){
    //setando oa exibição de pontuação da língua portuguesa
    setlocale(LC_ALL,"Portuguese");
    //solução para setar acentuação na entrada de dados
    SetConsoleCP(1252);       //Estabelecendo o codepage de entrada 1252(latin2)
    SetConsoleOutputCP(1252);

    //Declaraçao de variaveis
    //exemplo: tipo nomeMatriz [Linhas][colunas]
    char vetNome[QuantPessoa][100], nome[100];
    int vetId[QuantPessoa],Id=0,idReg=0,opcao=-1,sair=0,achou=0,ultPos=-1;
    char vetDatNas[QuantPessoa][11],datNasc[11],vetSepDat[5];
    int dia=0,mes=0,ano=0,dataVald = -1;


    char telefone [Regist][14],tel[14],pref[50];
    char email [Regist][50],eM[50];
    int vetIndTel [Regist][2],indTel = -1;
    int vetIndEm [Regist][2],indEm= -1;
    int InNom = 0,indExcTel = 0,indExcEm = 0;


    printf("\n                         Agenda Eletrônica vrs 1.0                 \n\n");
    while(opcao != 0){

            //exibindo menu
            printf("\n---------------------------------Menu de Opções------------------------");
            printf("\n1 - Incluir Dados de uma pessoa\n2 - Incluir um telefone\n3 - Incluir um E-mail\n4 - Consultar os dados de uma pessoa\n5 - Excluir uma pessoa\n6 - Excluir um telefone de uma pessoa\n7 - Excluir um E-mail de uma pessoa\n0 - Encerrar programa\n");
            printf("-----------------------------------------------------------------------");
            printf("\nForneça o código da opção escolhida:");
            scanf("%d",&opcao);
            setbuf(stdin,NULL);

            if(opcao >= 1 && opcao <= 7){

                    switch(opcao){
                    case 1:
                        /*incluir dados de uma pessoa(max. 20 no programa) e associar um id(auto-incremento a partir de 1)
                        -nome é unico sem acentos e transforme para maiusculo
                        -validar data de nascimento
                        */
                        printf("Forneça o nome da pessoa a ser incluída:");
                        fgets(nome,20,stdin);

                        //verifica se nome fornecido é valido
                        if (strncmp(nome,"\n",20) == 0){

                            printf("\nNome não pode ser vazio\n");
                            printf("Forneça o nome da pessoa a ser incluída:");
                            fgets(nome,20,stdin);

                            //laço para receber um nome válido ou voltar ao menu inicial
                            sair = 0;
                            while(strncmp(nome,"\n",20) == 0 && sair == 0){

                                     printf("\nNome não pode ser vazio\n");

                                     printf("Deseja: 1 - Fornecer o nome\n        2 - Voltar ao menu principal\n");
                                     scanf("%d",&sair);
                                     setbuf(stdin,NULL);

                                     if(sair == 1){

                                        printf("Forneça o nome da pessoa a ser incluída:");
                                        fgets(nome,20,stdin);

                                     }else{

                                            sair = 1;
                                            continue;

                                     }

                            }

                        }
                        else{

                            //retirando acentos e passando para LETRAS MAISUCULAS usando uma função criada.
                            strcpy(nome,FormNome(nome,strlen(nome)));


                            //verificando se o nome é unico
                            for(int i=0;i < QuantPessoa;i++){
                                if(strncmp(vetNome[i],nome,20) == 0){
                                    achou=1;
                                }

                            }

                            //Armazenando os nomes
                            sair = 0;
                            if(achou == 0){
                                ultPos += 1;
                                Id += 1;
                                strcpy(vetNome[ultPos],nome);
                                vetId[ultPos] = Id;

                                //obtendo e validando data de nascimento
                                printf("Forneça a Data de Nascimento (xx/xx/xxxx):");
                                fgets(datNasc,11,stdin);
                                setbuf(stdin,NULL);
                                //printf("%s",datNasc);

                                //verificando se esta no formato correto e separando os valores
                                if(datNasc[2] == '/' && datNasc[5] == '/'){
                                    if(isdigit(datNasc[0]) && isdigit(datNasc[1])){
                                            //obtendo dia
                                            vetSepDat[0] = datNasc[0];
                                            vetSepDat[1] =  datNasc[1];
                                            dia = atoi(vetSepDat);
                                           if(isdigit(datNasc[3]) && isdigit(datNasc[4])){
                                                //obtendo mes
                                                vetSepDat[0] = datNasc[3];
                                                vetSepDat[1] =  datNasc[4];
                                                mes = atoi(vetSepDat);

                                                if(isdigit(datNasc[6]) && isdigit(datNasc[7]) && isdigit(datNasc[8]) && isdigit(datNasc[9])){
                                                    //obtendo ano
                                                    vetSepDat[0] = datNasc[6];
                                                    vetSepDat[1] =  datNasc[7];
                                                    vetSepDat[2] =  datNasc[8];
                                                    vetSepDat[3] =  datNasc[9];
                                                    ano = atoi(vetSepDat);
                                                }
                                           }
                                    }
                                }
                                //validando data
                                if(dia ==0 || mes == 0 || ano == 0){
                                    printf("Data invalida");
                                    //voltar para menu / enecerrar / fornecer valor
                                }else{

                                    if(ano >= 1900 && ano < AnoAtual - 1){

                                        switch(mes){
                                        case 1:
                                        case 3:
                                        case 5:
                                        case 7:
                                        case 8:
                                        case 10:
                                        case 12:
                                            if( dia >= 1 && dia <= 31){
                                                dataVald = 0;
                                            }else{
                                                dataVald = 1;
                                            }
                                            break;
                                        case 2:
                                            if( dia >= 1 && dia <= 29){ //levando em conta anos bissextos
                                                dataVald = 0;
                                            }else{
                                                dataVald = 1;
                                            }
                                            break;
                                        case 4:
                                        case 6:
                                        case 9:
                                        case 11:
                                            if (dia >= 1 && dia <= 30){
                                               dataVald = 0;
                                            }else{
                                                dataVald = 1;
                                            }
                                            break;
                                        default:
                                            dataVald = 1;
                                        }
                                    }else{
                                        dataVald = 1;
                                    }
                                }
                                if(dataVald == 1){
                                    // menu para sair, voltar menu principal ou fornecer novo valor
                                    printf("Data inválida, %d",dataVald);
                                }

                            }
                            else{
                                sair = 0;
                                printf("\nNome já consta na agenda\n");
                                printf("Deseja: 1 - Encerrar a execução\n        2 - Voltar ao menu principal\n");
                                scanf("%d",&sair);
                                setbuf(stdin,NULL);

                                if(sair == 1){

                                    opcao = 0;
                                    //break;
                                }else{
                                    achou=0;
                                    continue;
                                }

                            }


                            /*
                            strcpy(vetNome[1],nome);
                            printf("%s",vetNome[1]);*/

                        }

                        /*for(int i=0;i <= 20;i++){
                                printf("%c",toupper(nome[i]));
                        }*/

                        break;
                    case 2:
                         //incluir num. de telefone (um pessoa pode possuir mais de um),Max. de 500 registros no programa.
                         printf("\nForneça o telefone (xxxxx-xxxx): ");
                         fgets(tel,11,stdin);
                         printf("%s",tel);

                         //validar telefone, nao vazio e tamanho 10, isdigit ou ispunct
                         idReg = 0;
                         printf("\nForneça o ID da pessoa que possui o telefone:");
                         scanf("%d",&idReg);
                         setbuf(stdin,NULL);

                         //Validando ID fornecido, verificando se esta na faixa permitida e se esta contido no vetor de ID
                         achou=0;
                         if(idReg >= 1 && idReg <= QuantPessoa){
                                for (int i=0; i <= QuantPessoa;i++){
                                    if(idReg == vetId[i]){
                                        achou = 1;
                                    }
                                }
                                if(achou = 1){
                                    indTel += 1;
                                    strcpy(telefone[indTel],tel);
                                    vetIndTel[indTel][1] = indTel;
                                    vetIndTel[indTel][2] = idReg;


                                }else{
                                    prinf("ID não cadastrado.");

                                    //opcao para sair ou voltar M. principal
                                    sair = 0;
                                    printf("Deseja: 1 - Encerrar a execução\n        2 - Voltar ao menu principal\n");
                                    scanf("%d",&sair);
                                    setbuf(stdin,NULL);

                                    if(sair == 1){
                                        opcao = 0;
                                        break;

                                    }else{
                                        achou=0;
                                        continue;
                                    }
                                }
                                /*for(int i=0; i < QuantPessoa; i++){
                                    printf("\nTelefone: %s\n",telefone[i]);
                                }*/

                         }else{
                            printf("\nID fornecido não é válido!\n");
                            //opcao para sair ou voltar M. principal
                            sair = 0;
                            printf("Deseja: 1 - Encerrar a execução\n        2 - Voltar ao menu principal\n");
                            scanf("%d",&sair);
                            setbuf(stdin,NULL);

                            if(sair == 1){
                                opcao = 0;
                                break;

                            }else{
                                achou=0;
                                continue;
                            }
                         }

                        break;
                    case 3:
                        //incluir um email(um pessoa pode possuir mais de um),Max. de 500 registros no programa.
                        printf("Forneça o E-mail example@example.com: ");
                        fgets(eM,50,stdin);
                        printf("%s",eM);

                        //validar email como não vazio

                        //coletando ID da pessoa
                        idReg = 0;
                        printf("\nForneça o ID da pessoa que possui o E-mail:");
                        scanf("%d",&idReg);
                        setbuf(stdin,NULL);


                        //Validando ID fornecido, verificando se esta na faixa permitida e se esta contido no vetor de ID
                         achou=0;
                         if(idReg >= 1 && idReg <= QuantPessoa){
                                for (int i=0; i <= QuantPessoa;i++){
                                    if(idReg == vetId[i]){
                                        achou = 1;
                                    }
                                }
                                if(achou = 1){
                                    indEm += 1;
                                    strcpy(email[indEm],eM);
                                    vetIndEm[indEm][1] = indEm;
                                    vetIndEm[indEm][2] = idReg;



                                }else{
                                    prinf("ID não cadastrado.");

                                    //opcao para sair ou voltar M. principal
                                    sair = 0;
                                    printf("Deseja: 1 - Encerrar a execução\n        2 - Voltar ao menu principal\n");
                                    scanf("%d",&sair);
                                    setbuf(stdin,NULL);

                                    if(sair == 1){
                                        opcao = 0;
                                        break;

                                    }else{
                                        achou=0;
                                        continue;
                                    }
                                }
                                /*for(int i=0; i < QuantPessoa; i++){
                                    printf("\nTelefone: %s\n",telefone[i]);
                                }*/

                         }else{
                            printf("\nID fornecido não é válido!\n");
                            //opcao para sair ou voltar M. principal
                            sair = 0;
                            printf("Deseja: 1 - Encerrar a execução\n        2 - Voltar ao menu principal\n");
                            scanf("%d",&sair);
                            setbuf(stdin,NULL);

                            if(sair == 1){
                                opcao = 0;
                                break;

                            }else{
                                achou=0;
                                continue;
                            }
                         }

                        break;

                    case 4:
                        //consultar os dados de uma pessoa a partir do prefixo do nome, mostrar todos os tel. e email
                        printf("Digite o prefixo do nome da pessoa para consultar: ");
                        fgets(pref,50,stdin);

                        //validar prefixo como não vazio
                        if(strcmp(pref,"\n") != 0){

                            //tirando acentos e passando para maiuscula o prefixo
                            strcpy(pref,FormNome(pref,5));
                            printf("%s",pref);

                            //busca no vetor de nomes pelo prefixo

                            /*for(int i=0;i < QuantPessoa;i++){

                                if(strcmp(vetNome[i][strlen(pref)],pref) == 0){
                                    //exibir telefones e emails

                                }
                            }*/

                        }else{
                                printf("\n prefixo vazio, favor fornecer um valor válido.\n");

                                //opcao para sair ou voltar M. principal
                                sair = 0;
                                printf("Deseja: 1 - Encerrar a execução\n        2 - Voltar ao menu principal\n");
                                scanf("%d",&sair);
                                setbuf(stdin,NULL);

                                if(sair == 1){
                                    opcao = 0;
                                    break;

                                }else{
                                    achou=0;
                                    continue;
                                }
                        }

                        break;

                    case 5:
                        //excluir uma pessoa pelo nome(excluir seus telefones e emails)
                        printf("Forneça o nome da pessoa a ser excluída: ");
                        fgets(nome,20,stdin);

                        //formatando nome
                        strcpy(nome,FormNome(nome,20));

                        //verificar se o nome está contido no vetor de nomes e salvar o indice
                        achou = 0;
                        for(int i=0; i < QuantPessoa; i++){
                                if(strcmp(vetNome[i],nome) == 0){
                                    achou = 1;
                                    InNom = i;
                                }
                        }

                        if(achou == 1){

                            //excluindo nome e organizando vetor
                            vetNome[InNom][1] = "";

                            for(int i = InNom + 1; i < ultPos + 1; i++){
                                    if(i == ultPos){
                                        vetNome[ultPos][1] = "";
                                        ultPos--;
                                    }
                                    strcpy(vetNome[i - 1],vetNome[i]);

                            }

                            ultPos--;

                            //excluindo telefone e emails
                            for(int i=0; i < Regist; i++){
                                if (vetIndTel[i][2] == vetId[InNom]){
                                    vetIndTel[i] == vetIndTel[indTel];
                                    vetIndTel[indTel][1] = 0;
                                    vetIndTel[indTel][2] = 0;
                                    indExcTel++;
                                }
                                else{
                                    if(vetIndEm[i][2] == vetId[InNom]){
                                        vetIndEm[i] == vetIndEm[indEm];
                                        vetIndEm[indEm][1] = 0;
                                        vetIndEm[indEm][2] = 0;
                                        indExcEm++;
                                    }
                                }
                            }


                        }else{
                            printf("Pessoa não está cadastrada na Agenda.");
                            //exibir opcao de sair ou voltar menu princ.
                        }

                        break;
                    case 6:
                        //coletando nome da pessoa
                          printf("Forneça o Nome da pessoa:");
                          fgets(nome,20,stdin);

                          //coletando telefone a ser excluido
                          printf("Forneça o Telefone a ser excluído:");
                          fgets(eM,11,stdin);

                          //nome e telefone informado nao estao vazios
                          sair=0;
                          while(nome == "\n"){
                            printf("Nome não pode ser vazio!");
                            printf("Deseja: 1 - encerrar execução 2 - voltar ao menu principal 3 -fornecer um nome válido");
                            scanf("%d",&sair);
                            setbuf(stdin,NULL);
                            switch(sair){
                            case 1:
                                break;
                            case 2:
                                continue;
                            case 3:
                                printf("Forneça o Nome da pessoa:");
                                fgets(nome,20,stdin);
                            default:
                                printf("Forneça uma opção válida!");

                            }

                          }

                          sair=0;
                          while(tel == "\n"){
                            printf("\nTelefone não pode ser vazio!\n");
                            printf("\nDeseja: 1 - encerrar execução 2 - voltar ao menu principal 3 -fornecer um Telefone válido\n");
                            scanf("%d",&sair);
                            setbuf(stdin,NULL);
                            switch(sair){
                            case 1:
                                break;
                            case 2:
                                continue;
                            case 3:
                                printf("Forneça o Telefone a ser excluído:");
                                fgets(eM,11,stdin);
                            default:
                                printf("Forneça uma opção válida!");

                            }

                          }

                          //verificar se o telefone e da pessoa informada
                          idReg=0;
                          InNom=0;

                          for(int i=0; i < ultPos; i++){
                            if(strcmp(vetNome[i],nome) == 0){
                                InNom = i;
                                idReg = vetId[i];
                            }
                          }
                          if(InNom == 1){
                            for(int i = 0; i < Regist; i++){
                            if(vetIndTel[i][2] == idReg){
                                    if (strcmp(telefone[vetIndTel[i][1]],tel) == 0){
                                        telefone[vetIndTel[i][1]][1]= telefone[indTel];
                                        telefone[indTel][1] = "";
                                    }
                            }else{
                                printf("\nTelefone não é da pessoa informada!\n");
                                printf("\nDeseja: 1 - encerrar execução 2 - voltar ao menu principal 3 -fornecer um Telefone válido\n");
                                scanf("%d",&sair);
                                setbuf(stdin,NULL);

                                switch(sair){
                                case 1:
                                    break;
                                case 2:
                                    continue;
                                case 3:
                                    printf("\nForneça o Telefone a ser excluído:");
                                    fgets(tel,11,stdin);
                                default:
                                    printf("\nForneça uma opção válida!\n");

                            }
                            }
                          }
                          }else{
                            printf("\nPessoa não cadastrada\n");
                            printf("Deseja: 1 - encerrar execução 2 - voltar ao menu principal 3 -fornecer um nome válido\n");
                            scanf("%d",&sair);
                            setbuf(stdin,NULL);

                            switch(sair){
                            case 1:
                                break;
                            case 2:
                                continue;
                            case 3:
                                printf("\nForneça o Telefone a ser excluído:");
                                fgets(tel,50,stdin);
                            default:
                                printf("\nForneça uma opção válida!\n");

                            }
                          }



                        break;

                    case 7:
                          //excluir um email de uma pessoa

                          //coletando nome da pessoa
                          printf("Forneça o Nome da pessoa:");
                          fgets(nome,20,stdin);

                          //coletando email a ser excluido
                          printf("Forneça o E-mail a ser excluído:");
                          fgets(eM,50,stdin);

                          //nome e email informado nao estao vazios
                          sair=0;
                          while(nome == "\n"){
                            printf("Nome não pode ser vazio!");
                            printf("Deseja: 1 - encerrar execução 2 - voltar ao menu principal 3 -fornecer um nome válido");
                            scanf("%d",&sair);
                            setbuf(stdin,NULL);

                            switch(sair){
                            case 1:
                                break;
                            case 2:
                                continue;
                            case 3:
                                printf("Forneça o Nome da pessoa:");
                                fgets(nome,20,stdin);
                            default:
                                printf("Forneça uma opção válida!");

                            }

                          }

                          sair=0;
                          while(eM == "\n"){
                            printf("E-mail não pode ser vazio!");
                            printf("Deseja: 1 - encerrar execução 2 - voltar ao menu principal 3 -fornecer um nome válido");
                            scanf("%d",&sair);
                            setbuf(stdin,NULL);

                            switch(sair){
                            case 1:
                                break;
                            case 2:
                                continue;
                            case 3:
                                printf("Forneça o E-mail a ser excluído:");
                                fgets(eM,50,stdin);
                            default:
                                printf("Forneça uma opção válida!");

                            }

                          }

                          //verificar se o email e da pessoa informada
                          idReg=0;
                          InNom=0;

                          for(int i=0; i < ultPos; i++){
                            if(strcmp(vetNome[i],nome) == 0){
                                InNom = i;
                                idReg = vetId[i];
                            }
                          }
                          if(InNom == 1){
                            for(int i = 0; i < Regist; i++){
                            if(vetIndEm[i][2] == idReg){
                                    if (strcmp(email[vetIndEm[i][1]],eM) == 0){
                                        email[vetIndEm[i][1]][1]= email[indEm];
                                        email[indEm][1] = "";
                                    }
                            }else{
                                printf("\nEmail não é da pessoa informada!\n");
                                printf("\nDeseja: 1 - encerrar execução 2 - voltar ao menu principal 3 -fornecer um nome válido\n");
                                scanf("%d",&sair);
                                setbuf(stdin,NULL);

                                switch(sair){
                                case 1:
                                    break;
                                case 2:
                                    continue;
                                case 3:
                                    printf("\nForneça o E-mail a ser excluído:");
                                    fgets(eM,50,stdin);
                                default:
                                    printf("\nForneça uma opção válida!\n");

                            }
                            }
                          }
                          }else{
                            printf("\nPessoa não cadastrada\n");
                            printf("Deseja: 1 - encerrar execução 2 - voltar ao menu principal 3 -fornecer um nome válido\n");
                            scanf("%d",&sair);
                            setbuf(stdin,NULL);
                            switch(sair){
                            case 1:
                                break;
                            case 2:
                                continue;
                            case 3:
                                printf("\nForneça o E-mail a ser excluído:");
                                fgets(eM,50,stdin);
                            default:
                                printf("\nForneça uma opção válida!\n");

                            }
                          }



                        break;

                    }


            }else{
                printf("\nDeseja encerrar o programa? 1 - Sim 2 - Não :");
                scanf("%d",&sair);
                setbuf(stdin,NULL);
                if(sair == 1){

                    break;
                }else{

                    //continue;
                    opcao = 1;


                }
            }


    }































































/*
        for(int i=0;i < QuantPessoa;i++){
            for(int k=0;k < QuantPessoa;k++){
                printf("%c",vetNome[i][k]);
            }


        }*/















    return 0;
}
