///////////////////////////////////////////////////////////////////////////////
///             Universidade Federal do Rio Grande do Norte                 ///
///                 Centro de Ensino Superior do Serido                     ///
///             PROJETO SIG DE UMA LOJA PARA ARTIGOS FEMININOS              ///
///             Developed by @stenioeric -- since August, 2023              ///
///////////////////////////////////////////////////////////////////////////////


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "cliente.h"
#include "util.h"

typedef struct cliente Cliente;

void moduloCliente(void) {
    char op;
    Cliente* modelo;

    do {
        op = tela_menu_cliente();
        switch (op) {
            case '1':   modelo = tela_cadastro_cliente();
                        gravaCliente(modelo);
                        break;
            case '2':   tela_pesquisar_cliente();
                        break;
            case '3':   tela_alterar_cliente();
                        break;
            case '4':   tela_excluir_cliente();
                        break;
            case '5':   listarTodosClientes();
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
    printf("///                 ------------ MENU CLIENTES ------------                 ///\n");
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


Cliente* tela_cadastro_cliente(void) {
    Cliente *cli;
    cli = (Cliente*)malloc(sizeof(Cliente));
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
    do {
        printf("/// NOME:");
        scanf("%s", cli -> nome);
        limparBuffer();
    } while(!validarNome(cli -> nome));
    do {
        printf("/// CPF:");
        scanf("%[0-9/]", cli -> cpf);
        limparBuffer();
    } while(!validarCPF(cli -> cpf));
    do {
        printf("/// EMAIL:");
        scanf("%[a-z0-9@.]",cli -> email);
        limparBuffer();
    } while(!valEmail(cli -> email));
    do {
        printf("/// DATA DE NASCIMENTO:");
        scanf("%[0-9/]",cli -> dataNas);
        limparBuffer();
    } while(!validarData(cli -> dataNas));
    do {
        printf("/// TELEFONE:");
        scanf("%[0-9()]",cli -> telefone);
        limparBuffer();
    } while(!validarFone(cli -> telefone));

    cli -> status = 'A';
    
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    return cli;
}

void tela_pesquisar_cliente(void) {
    char mtr[15];
    FILE* fp;
    Cliente* cli;
    cli = (Cliente*)malloc(sizeof(Cliente));
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
    printf("/// CPF DO CLIENTE: ");
    scanf("%14s", mtr);
    if (cli == NULL){
        printf("\n= = = Cliente não registrado = = =\n");
        free(cli);
        return;
    }
    fp = fopen("clientes.dat", "rb");
    if (fp == NULL) {
        printf("Ops! Erro na abertura do arquivo!\n");
        printf("Não é possível continuar...\n");
        free(cli); // Libera a memória alocada para cli
        exit(1);
    }
    while (fread(cli, sizeof(Cliente), 1, fp)) {
        if ((cli->status != 'x') && (strcmp(cli->cpf,mtr)==0)) {
            printCliente(cli);
            limparBuffer();
        }
    }
    fclose(fp);
    free(fp);
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}


void tela_alterar_cliente(void) {

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
    getchar();
}

void printCliente(Cliente* cli) {
    if ((cli == NULL) || (cli->status == 'x')) {
        printf("\n= = = CLIENTE INEXISTENTE = = =\n");
    } else {
        system("clear||cls");
        printf("\n = = = DADOS DO CLIENTE = = = \n");
        printf("\n");
        printf("NOME:%s\n", cli-> nome);
        printf("CPF:%s\n", cli-> cpf);                                                         
        printf("EMAIL:%s\n", cli-> email);                                                      
        printf("DATA DE NASCIMENTO:%s\n", cli-> dataNas);                                          
        printf("TELEFONE: %s\n", cli-> telefone);
        printf("STATUS: %d\n", cli->status);
        printf("===================================\n");                  
    }

}


void gravaCliente(Cliente* cli) {
    FILE* fp;
    fp = fopen("clientes.dat", "ab");
    if (fp == NULL) {
        printf("Ops! Erro na abertura do arquivo!\n");
        printf("Nao eh possivel continuar...\n");
        exit(1);
    }
    fwrite(cli, sizeof(Cliente), 1, fp);
    fclose(fp);
}


void listarTodosClientes(void) {
    FILE* fp;
    Cliente cli;
    system("clear||cls");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("         PRINT DADOS CLIENTES          \n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("                                       \n");
    fp = fopen("clientes.dat", "rb");
    if (fp == NULL) {
        printf("Ops! Erro na abertura do arquivo!\n");
        printf("Nao eh possivel continuar...\n");
        exit(1);
    }
    while (fread(&cli, sizeof(Cliente), 1, fp)) {
        if (cli.status != 'x') {
            printCliente(&cli);
        }
    }
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    fclose(fp);
}



