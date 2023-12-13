///////////////////////////////////////////////////////////////////////////////
///             Universidade Federal do Rio Grande do Norte                 ///
///                 Centro de Ensino Superior do Serido                     ///
///             PROJETO SIG DE UMA LOJA PARA ARTIGOS FEMININOS              ///
///             Developed by @stenioeric -- since August, 2023              ///
///////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"
#include "util.h"


typedef struct cliente Cliente;

void moduloCliente(void) {
    char op;
    do {
        op = tela_menu_cliente();
        switch (op) {
            case '1':   cadCliente();
                        break;
            case '2':   tela_pesquisar_cliente();
                        break;
            case '3':   atualizaCliente();
                        break;
            case '4':   excluirCliente();
                        break;
        }
    } while (op != '0');
}

char tela_menu_cliente(void) {
    char op;
    system("clear||cls");
    printf("\n");
    printf("===========================================\n");
    printf("||       BEM-VINDO A LOJA ELEGANCE       ||\n");
    printf("===========================================\n");
    printf("||                                       ||\n");
    printf("||           MENU DE CLIENTES            ||\n");
    printf("||                                       ||\n");
    printf("||  1. CADASTRAR CLIENTE                 ||\n");
    printf("||  2. PESQUISAR DADOS DO CLIENTE        ||\n");
    printf("||  3. ATUALIZAR CADASTRO DO CLIENTE     ||\n");
    printf("||  4. EXCLUIR DADOS DO CLIENTE          ||\n");
    printf("||  0. VOLTAR AO MENU PRINCIPAL          ||\n");
    printf("||                                       ||\n");
    printf("===========================================\n");
    printf("||                                       ||\n");
    printf("||  ESCOLHA A OPCAO DESEJADA: ");
    scanf(" %c", &op);
    limparBuffer();
    printf("||                                       ||\n");
    printf("===========================================\n");
    printf("\n");
    return op;
}



Cliente* tela_cadastro_cliente(void){
    Cliente *cli;
    cli = (Cliente*)malloc(sizeof(Cliente));
    system("clear||cls");
    printf("\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("            CADASTRO CLIENTE           \n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("\n");
    do {
        printf(" -> NOME: ");
        scanf("%s", cli -> nome);
        limparBuffer();
    } while(!validarNome(cli -> nome));

    int cpfDuplicado = 0;
    do {
        printf(" -> CPF: ");
        scanf("%[0-9]",cli -> cpf);
        limparBuffer();
        cpfDuplicado = verificaCPFDuplicado(cli->cpf);
    if (!validarCPF(cli -> cpf) || cpfDuplicado ) {
        cpfErro();
	}
	} while (!validarCPF(cli -> cpf) || cpfDuplicado );



    int emailDuplicado = 0;
    do {
        printf(" -> EMAIL: ");
        scanf("%[a-z0-9@.]",cli -> email);
        limparBuffer(); 
        emailDuplicado = verificaEmailDuplicado(cli->email);
        if (emailDuplicado || !validarEmail(cli->email)) {
            emailErro();
        }
    } while (emailDuplicado || !validarEmail(cli->email));


    do {
        printf(" -> DATA DE NASCIMENTO(Ex:13/08/2002): ");
        scanf("%[0-9/]",cli -> dataNas);
        limparBuffer();
    } while(!validarData(cli -> dataNas));


    do {
        printf(" -> TELEFONE(xx)xxxxxxxxx): ");
        scanf("%[0-9()]",cli -> telefone);
        limparBuffer();
    } while(!validarFone(cli -> telefone));
    
    cli->status = 1;
    espacamento();
    return cli;
}

Cliente* tela_pesquisar_cliente(void) {
    FILE* fp;
    char cpf[15];
    Cliente* cli = (Cliente*)malloc(sizeof(Cliente)); 
    if (cli == NULL) {
        printf("ERRO DE ALOCACAO DE MEMORIA.");
        exit(1);
    }
    system("clear||cls");
    printf("\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("            PESQUISAR CLIENTE          \n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    do {
        printf(" -> CPF: ");
        scanf("%[0-9]", cpf);
        limparBuffer();
    if (!validarCPF(cpf)) {
        cpfErro();
    }
    } while (!validarCPF(cpf));

    fp = fopen("clientes.dat", "rb");
    if (fp == NULL) {
        telaErro();
        free(cli);
        exit(1);
    }

    int cliEncontrado = 0;
    system("clear||cls");
    printf("|-------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
    printf("|                                                                       DADOS DO CLIENTE                                                                      |\n");
    while (fread(cli, sizeof(Cliente), 1, fp)) {
        if ((cli->status == 1) && (strcmp(cli->cpf, cpf) == 0)) {
            printCliente(cli);
            cliEncontrado = 1;
        }
    }
    fclose(fp);

    if (!cliEncontrado) {
        printf("\n");
        printf(" -> CLIENTE NAO REGISTRADO\n");
        espacamento();
        free(cli);
        return NULL;
    }
    espacamento();
    return cli;
}


char* tela_alterar_cliente(void) {
    char* cpf;
	cpf = (char*) malloc(15*sizeof(char));
    system("clear||cls");
    printf("\n");
    system("clear||cls");
    printf("\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("            ALTERAR CLIENTE            \n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("\n");
    do {
        printf(" -> CPF: ");
        scanf("%[0-9]",cpf);
        limparBuffer();
    if (!validarCPF(cpf)) {
        cpfErro();
	}
	} while (!validarCPF(cpf));
    return cpf;
}


char* tela_excluir_cliente(void) {
    char* cpf;
	cpf = (char*) malloc(15*sizeof(char));
    system("clear||cls");
    printf("\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("            EXCLUIR CLIENTE            \n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("\n");
    do {
        printf(" -> CPF: ");
        scanf("%[0-9]",cpf);
        limparBuffer();
    if (!validarCPF(cpf)) {
        cpfErro();
	}
	} while (!validarCPF(cpf));
    return cpf;
}


////////////////////////////////////////////////////////////////
///////////////// FUNCOES UTILIZADAS NO CODIGO /////////////////
////////////////////////////////////////////////////////////////

// PRINTA DADOS DO CLIENTE
void printCliente(Cliente* cli) {
    printf("|-------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
    printf("| CPF: %-15s | NOME: %-20s | EMAIL: %-25s | ANIVERSARIO: %-12s | TELEFONE: %-15s | STATUS: %d    |\n",
           cli->cpf, cli->nome, cli->email, cli->dataNas, cli->telefone, cli->status);
    printf("|_____________________________________________________________________________________________________________________________________________________________|\n");
}


// Grava os dados do cliente em um arquivo
void gravaCliente(Cliente* cli) {
    // Abre o arquivo "clientes.dat" para escrita binária no final do arquivo
    FILE* fp;
    fp = fopen("clientes.dat", "ab");

    // Verifica se houve erro ao abrir o arquivo
    if (fp == NULL) {
        telaErro(); // Exibe uma mensagem de erro
        exit(1); // Encerra o programa
    }

    // Escreve os dados do cliente no arquivo
    fwrite(cli, sizeof(Cliente), 1, fp);
    // Fecha o arquivo
    fclose(fp);
}


// Busca um cliente pelo CPF
Cliente* buscaCliente(char* cpf) {
    // Abre o arquivo "clientes.dat" para leitura binária
    FILE* fp;
    Cliente* cli;
    cli = (Cliente*)malloc(sizeof(Cliente));
    fp = fopen("clientes.dat", "rb");

    // Verifica se houve erro ao abrir o arquivo
    if (fp == NULL) {
        telaErro(); // Exibe uma mensagem de erro
    }

    // Percorre o arquivo em busca do cliente com o CPF fornecido
    while (fread(cli, sizeof(Cliente), 1, fp)) {
        if (strcmp(cli->cpf, cpf) == 0 && cli->status == 1) {
            fclose(fp); // Fecha o arquivo
            return cli; // Retorna o cliente encontrado
        }
    }

    fclose(fp); // Fecha o arquivo
    free(cli); // Libera a memória alocada para o cliente
    return NULL; // Retorna NULL se o cliente não foi encontrado
}


// Atualiza um cliente
void atualizaCliente(void) {
    Cliente* cli;
    char* cpf;

    // Obtém o CPF do cliente a ser atualizado
    cpf = tela_alterar_cliente();
    cli = buscaCliente(cpf);

    if (cli == NULL) {
        system("clear||cls");
        printf("\n");
        printf(" ->CLIENTE NAO ENCONTRADO!\n\n");
        espacamento();
    } else {
        removeCliente(cli);
        cli = tela_cadastro_cliente();
        strcpy(cli->cpf, cpf);
        regravarCliente(cli);
        free(cli);
    }

    free(cpf);
}


// Reescreve os dados de um cliente no arquivo
void regravarCliente(Cliente* cli) {
    FILE* fp;
    Cliente* cli_Lido;

    cli_Lido = (Cliente*)malloc(sizeof(Cliente));
    fp = fopen("clientes.dat", "r+b");

    if (fp == NULL) {
        telaErro();
    }

    int achou = 0;

    // Busca o cliente pelo CPF no arquivo
    while(!feof(fp)) {
        fread(cli_Lido, sizeof(Cliente), 1, fp);
        if (strcmp(cli_Lido->cpf, cli->cpf) == 0) {
            achou = 1;
            fseek(fp, -1 * sizeof(Cliente), SEEK_CUR);
            fwrite(cli, sizeof(Cliente), 1, fp);
            break;
        }
    }

    fclose(fp); // Fecha o arquivo
    free(cli_Lido); // Libera a memória alocada para o cliente lido do arquivo

    if (!achou) {
        printf("\n");
        printf(" ->CLIENTE NAO ENCONTRADO!\n");
    }
}


// Cadastra um novo cliente
void cadCliente(void) {
    Cliente *cli;
    cli = tela_cadastro_cliente();
    gravaCliente(cli);
    free(cli);
}


// // Remove um cliente
void removeCliente(Cliente* cli) {
    FILE* fp;
    Cliente* cli_Lido;
    cli_Lido = (Cliente*)malloc(sizeof(Cliente));
    fp = fopen("clientes.dat", "r+b");

    if (fp == NULL) {
        telaErro();
    }

    int achou = 0;

    // Busca o cliente pelo CPF no arquivo
    while (fread(cli_Lido, sizeof(Cliente), 1, fp) && !achou) {
        if (strcmp(cli_Lido->cpf, cli->cpf) == 0 && cli_Lido->status) {
            achou = 1;
            fseek(fp, -1 * sizeof(Cliente), SEEK_CUR);
            cli_Lido->status = 0; // Marca o cliente como inativo
            fwrite(cli_Lido, sizeof(Cliente), 1, fp);
        }
    }

    fclose(fp); // Fecha o arquivo
    free(cli_Lido); // Libera a memória alocada para o cliente lido do arquivo

    if (!achou) {
        printf("\n");
        printf(" ->CLIENTE NAO ENCONTRADO OU JA REMOVIDO!\n");
    }
}


// Exclui um cliente
void excluirCliente(void) {
    Cliente *cli;
    char *cpf;

    // Obtém o CPF do cliente a ser excluído
    cpf = tela_excluir_cliente();
    cli = buscaCliente(cpf);

    if (cli == NULL) {
        printf("\n");
        printf(" ->CLIENTE NAO ENCONTRADO!\n\n");
    } else {
        cli->status = 0;
        regravarCliente(cli);
        free(cli);
        cli = NULL; // Define cli como NULL após remoção
        printf("\n");
        printf(" ->CLIENTE EXCLUIDO COM SUCESSO!\n");
    }

    free(cpf);
    espacamento();
}


// Verifica se um CPF já está cadastrado
int verificaCPFDuplicado(const char* cpf) {
    FILE* fp = fopen("clientes.dat", "rb");

    Cliente cli;
    while (fread(&cli, sizeof(Cliente), 1, fp)) {
        if (strcmp(cli.cpf, cpf) == 0) {
            fclose(fp);
            return 1; // CPF duplicado
        }
    }

    fclose(fp); // Fecha o arquivo
    return 0; // CPF não duplicado
}


// Verifica se um e-mail já está cadastrado
int verificaEmailDuplicado(const char* email) {
    FILE* fp = fopen("clientes.dat", "rb");

    Cliente cli;
    while (fread(&cli, sizeof(Cliente), 1, fp)) {
        if (strcmp(cli.email, email) == 0) {
            fclose(fp);
            return 1; // E-mail duplicado
        }
    }

    fclose(fp); // Fecha o arquivo
    return 0; // E-mail não duplicado
}
