///////////////////////////////////////////////////////////////////////////////
///             Universidade Federal do Rio Grande do Norte                 ///
///                 Centro de Ensino Superior do Serido                     ///
///             PROJETO SIG DE UMA LOJA PARA ARTIGOS FEMININOS              ///
///             Developed by @stenioeric -- since August, 2023              ///
///////////////////////////////////////////////////////////////////////////////


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "cliente.h"
#include "util.h"



void moduloCliente(void) {
    char op;

    do {
        op = tela_menu_cliente();
        switch (op) {
            case '1':   tela_cadastro_cliente();
                        break;
            case '2':   tela_pesquisar_cliente();
                        break;
            case '3':   tela_alterar_cliente();
                        break;
            case '4':   tela_excluir_cliente();
                        break;

        }
    } while (op != '0');
}


char tela_menu_cliente(void) {
    char op;

    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///        EEEEEEE lll                                                      ///\n");
    printf("///        EE      lll   eee   gggggg   aa aa nn nnn    cccc   eee          ///\n");
    printf("///        EEEEE   lll ee   e gg   gg  aa aaa nnn  nn cc     ee   e         ///\n");
    printf("///        EE      lll eeeee  ggggggg aa  aaa nn   nn cc     eeeee          ///\n");
    printf("///        EEEEEEE lll  eeeee      gg  aaa aa nn   nn  ccccc  eeeee         ///\n");
    printf("///                             ggggg                                       ///\n");
    printf("///                                                                         ///\n");
    printf("///                      LOJA DE ARTIGOS FEMININOS                          ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///             ------------  MENU CLIENTES ------------                    ///\n");
    printf("///                                                                         ///\n");
    printf("///            1. CADASTRAR CLIENTE                                         ///\n");
    printf("///            2. PESQUISAR DADOS DO CLIENTE                                ///\n");
    printf("///            3. ATUALIZAR CADASTRO DO CLIENTE                             ///\n");
    printf("///            4. EXCLUIR DADOS DO CLIENTE                                  ///\n");
    printf("///            0. VOLTAR AO MENU PRINCIPAL                                  ///\n");
    printf("///                                                                         ///\n");
    printf("///            ESCOLHA A OPCAO DESEJADA: ");
    scanf("%c", &op);
    getchar();
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    return op;

}



void tela_cadastro_cliente(void) {

    char op;
    char *nome, *cpf, *email, *dataNasc, *telefone;
    nome = (char*) malloc(50*sizeof(char));
    cpf = (char*) malloc(11*sizeof(char));
    email = (char*) malloc(40*sizeof(char));
    dataNasc = (char*) malloc(10*sizeof(char));
    telefone = (char*) malloc(12*sizeof(char));

    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///        EEEEEEE lll                                                      ///\n");
    printf("///        EE      lll   eee   gggggg   aa aa nn nnn    cccc   eee          ///\n");
    printf("///        EEEEE   lll ee   e gg   gg  aa aaa nnn  nn cc     ee   e         ///\n");
    printf("///        EE      lll eeeee  ggggggg aa  aaa nn   nn cc     eeeee          ///\n");
    printf("///        EEEEEEE lll  eeeee      gg  aaa aa nn   nn  ccccc  eeeee         ///\n");
    printf("///                             ggggg                                       ///\n");
    printf("///                                                                         ///\n");
    printf("///                      LOJA DE ARTIGOS FEMININOS                          ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///              -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-                    ///\n");
    printf("///                         CADASTRO CLIENTE                                ///\n");
    printf("///              -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-                    ///\n");
    printf("///                                                                         ///\n");
    valCliente(nome, cpf ,email, dataNasc, telefone);
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    scanf("%c", &op);
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void tela_pesquisar_cliente(void) {

    char *cpf;
    cpf = (char*) malloc(11*sizeof(char));

    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///        EEEEEEE lll                                                      ///\n");
    printf("///        EE      lll   eee   gggggg   aa aa nn nnn    cccc   eee          ///\n");
    printf("///        EEEEE   lll ee   e gg   gg  aa aaa nnn  nn cc     ee   e         ///\n");
    printf("///        EE      lll eeeee  ggggggg aa  aaa nn   nn cc     eeeee          ///\n");
    printf("///        EEEEEEE lll  eeeee      gg  aaa aa nn   nn  ccccc  eeeee         ///\n");
    printf("///                             ggggg                                       ///\n");
    printf("///                                                                         ///\n");
    printf("///                      LOJA DE ARTIGOS FEMININOS                          ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///              -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-                    ///\n");
    printf("///                        PESQUISAR CLIENTE                                ///\n");
    printf("///              -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-                    ///\n");
    printf("///                                                                         ///\n");
    do {
        printf("///CPF DO CLIENTE:");
        scanf("%s", cpf);
        limparBuffer();    
    }while(!validarCPF(cpf));
    if (validarCPF(cpf) == 1) {
        printDados();
    }
    else {
        printf("///USUARIO NAO ENCONTRADO");
        printf("\n");
        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    }
}


void tela_alterar_cliente(void) {
    
    // char *nome,*cpf,*email, *dataNasc, *telefone;   
    // nome = (char*) malloc(50*sizeof(char));
    // email = (char*) malloc(40*sizeof(char));
    // dataNasc = (char*) malloc(10*sizeof(char));
    // telefone = (char*) malloc(12*sizeof(char));

    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///        EEEEEEE lll                                                      ///\n");
    printf("///        EE      lll   eee   gggggg   aa aa nn nnn    cccc   eee          ///\n");
    printf("///        EEEEE   lll ee   e gg   gg  aa aaa nnn  nn cc     ee   e         ///\n");
    printf("///        EE      lll eeeee  ggggggg aa  aaa nn   nn cc     eeeee          ///\n");
    printf("///        EEEEEEE lll  eeeee      gg  aaa aa nn   nn  ccccc  eeeee         ///\n");
    printf("///                             ggggg                                       ///\n");
    printf("///                                                                         ///\n");
    printf("///                      LOJA DE ARTIGOS FEMININOS                          ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///              -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-                    ///\n");
    printf("///                         ALTERAR CLIENTE                                 ///\n");
    printf("///              -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-                    ///\n");
    printf("///                                                                         ///\n");
    // do {
    //     printf("///CPF DO CLIENTE:");
    //     scanf("%s", cpf);
    //     limparBuffer();
    // }while(!validarCPF(cpf));
    // if (validarCPF(cpf) == 1){
    //     mudaCliente(nome,email, dataNasc,telefone);
    // }
    // else {
    //     printf("///USUARIO NAO ENCONTRADO");
    // }
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void tela_excluir_cliente(void) {

    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///        EEEEEEE lll                                                      ///\n");
    printf("///        EE      lll   eee   gggggg   aa aa nn nnn    cccc   eee          ///\n");
    printf("///        EEEEE   lll ee   e gg   gg  aa aaa nnn  nn cc     ee   e         ///\n");
    printf("///        EE      lll eeeee  ggggggg aa  aaa nn   nn cc     eeeee          ///\n");
    printf("///        EEEEEEE lll  eeeee      gg  aaa aa nn   nn  ccccc  eeeee         ///\n");
    printf("///                             ggggg                                       ///\n");
    printf("///                                                                         ///\n");
    printf("///                      LOJA DE ARTIGOS FEMININOS                          ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///              -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-                    ///\n");
    printf("///                         EXCLUIR CLIENTE                                 ///\n");
    printf("///              -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-                    ///\n");
    printf("///                                                                         ///\n");
    printf("///              CPF DO CLIENTE:                                            ///\n");
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}


///////////////////////////////////////////////////////////////////////////////
/// Validador de nome, cpf , email , telefone e data de nascimento.
///
void valCliente (char *nome, char *cpf, char *email, char *dataNasc, char *telefone ){

    do {
        printf("///NOME:");
        scanf("%s", nome);
        limparBuffer();
    } while(!validarNome(nome));

    do {
        printf("///CPF:");
        scanf("%s", cpf);
        limparBuffer();
    } while(!validarCPF(cpf));

    do {
        printf("///EMAIL:");
        scanf("%[a-z0-9@.]", email);
        limparBuffer();
    } while(!valEmail(email));

    do {
        printf("///DATA DE NASCIMENTO:");
        scanf("%[0-9/]", dataNasc);
        limparBuffer();
    } while(!validarData(dataNasc));

    do {
        printf("///TELEFONE:");
        scanf("%s", telefone);
        limparBuffer();
    } while(!validarFone(telefone));

}

/////////////////////////////////////////////////////////////////////////////
/// Adaptado de Luiz Miguel 
/// link: https://github.com/LuizMiguel4444/GestaoCasaShow/blob/main/client.c


// void mudaCliente (char *nome,char *email, char *dataNasc, char *telefone ){
//     do {
//         printf("///NOME:");
//         scanf("%s", nome);
//         limparBuffer();
//     } while(!validarNome(nome));

//     do {
//         printf("///EMAIL:");
//         scanf("%[a-z0-9@.]", email);
//         limparBuffer();
//     } while(!valEmail(email));

//     do {
//         printf("///DATA DE NASCIMENTO:");
//         scanf("%s", dataNasc);
//         limparBuffer();
//     } while(!validarData(dataNasc));

//     do {
//         printf("///TELEFONE:");
//         scanf("%s", telefone);
//         limparBuffer();
//     } while(!validarFone(telefone));

// }
