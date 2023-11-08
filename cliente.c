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

int validarEmail(char* email);

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
            case '5':   listarTodosClientes();
                        break;

        }
    } while (op != 0);
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
    printf("///            5. LISTAR TODOS OS CLIENTES                                  ///\n");
    printf("///            0. VOLTAR AO MENU PRINCIPAL                                  ///\n");
    printf("///                                                                         ///\n");
    printf("///            ESCOLHA A OPCAO DESEJADA: ");
    scanf("%c", &op);
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    return op;

}


Cliente* tela_cadastro_cliente(void){
    Cliente *cli;
    cli = (Cliente*)malloc(sizeof(Cliente));
    system("clear||cls");
    printf("\n");
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
    int cpfDuplicado = 0;
    int cpfValido = 0;
    do {
        printf("/// CPF DO CLIENTE: ");
        scanf("%s", cli->cpf);
        limparBuffer();

        cpfDuplicado = verificaCPFDuplicado(cli->cpf);

        if (cpfDuplicado) {
            printf("\n");
            printf("\t\t\tCPF JA EXISTE. TENTE NOVAMENTE.\n");
            printf("\n");
        } else if (validarCPF(cli->cpf)) {
            cpfValido= 1;
        }
        else {
            printf("\n");
            printf("\t\t\tCPF INVALIDO. TENTE NOVAMENTE.\n");
            printf("\n");
        }
    } while (!cpfValido || cpfDuplicado);

    int emailDuplicado = 0;
    int emailValido = 0;
    do {
        printf("/// EMAIL:");
        scanf("%[a-z0-9@.]",cli -> email);
        limparBuffer();

        emailDuplicado = verificaEmailDuplicado(cli->email);

        if (emailDuplicado) {
            printf("\n");
            printf("\t\t\tEMAIL JA EXISTE. TENTE NOVAMENTE.\n");
            printf("\n");
        } else if (validarEmail(cli->email)) {
            emailValido = 1;
        }
        else {
            printf("\n");
            printf("\t\t\tEMAIL INVALIDO. TENTE NOVAMENTE.\n");
            printf("\n");
        }
    } while (emailDuplicado || !emailValido);

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
    
    cli->status = 1;
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    return cli;
}

Cliente* tela_pesquisar_cliente(void) {
    char opc[15];
    FILE* fp;
    Cliente* cli;
    cli = (Cliente*)malloc(sizeof(Cliente));
    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///              -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-                    ///\n");
    printf("///                        PESQUISAR CLIENTE                                ///\n");
    printf("///              -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-                    ///\n");
    printf("///                                                                         ///\n");
    do {
        printf("///CPF DO CLIENTE: ");
        scanf("%[0-9]",opc);
        limparBuffer();
    } while(!validarCPF(opc));
    fp = fopen("clientes.dat", "rb");
    if (fp == NULL) {
        telaErro();
        free(cli);
        exit(1);
    }
    int cliEncontrado = 0;
    while (fread(cli, sizeof(Cliente), 1, fp)) {
        if ((cli->status != 0) && (strcmp(cli->cpf,opc)==0)) {
            printCliente(cli);
            limparBuffer();
            cliEncontrado = 1;
        }
    }
    if (!cliEncontrado){
        printf("\n");
        printf("\t\t\tCLIENTE NAO REGISTRADO\n");
        limparBuffer();
        return NULL;
    }
    
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    return NULL;
}


char* tela_alterar_cliente(void) {
    char* cpf;
	cpf = (char*) malloc(15*sizeof(char));
    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///              -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-                    ///\n");
    printf("///                         ALTERAR CLIENTE                                 ///\n");
    printf("///              -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-                    ///\n");
    printf("///                                                                         ///\n");
    printf("///CPF DO CLIENTE: ");
    scanf("%[0-9]", cpf);
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    return cpf;
}

char* tela_excluir_cliente(void) {
    char* cpf;
	cpf = (char*) malloc(15*sizeof(char));
    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///              -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-                    ///\n");
    printf("///                         EXCLUIR CLIENTE                                 ///\n");
    printf("///              -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-                    ///\n");
    printf("///                                                                         ///\n");
    do {
        printf("///CPF DO CLIENTE: ");
        scanf("%[0-9]",cpf);
        limparBuffer();
    } while(!validarCPF(cpf));
    return cpf;
}



////////////////////////////////////////////////////////////////
///////////////// FUNCOES UTILIZADAS NO CODIGO /////////////////
////////////////////////////////////////////////////////////////

// PRINTA DADOS DO CLIENTE
void printCliente(Cliente* cli) {
    printf("\n = = = DADOS DO CLIENTE = = = \n");
    printf("NOME:              %s\n", cli->nome);
    printf("CPF:               %s\n", cli->cpf);
    printf("EMAIL:             %s\n", cli->email);
    printf("DATA DE NASCIMENTO:%s\n", cli->dataNas);
    printf("TELEFONE:          %s\n", cli->telefone);
    printf("STATUS:            %d\n", cli->status);
    printf("===================================\n");
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

void listarTodosClientes(void) {
    FILE* fp;
    Cliente* cli;
    cli = (Cliente*) malloc(sizeof(Cliente));
    fp = fopen("clientes.dat", "rb");
    if (fp == NULL) {
        telaErro(); // Exibe uma mensagem de erro
        free(cli); // Libera a memória alocada para o cliente
        exit(1); // Encerra o programa
    }

    int clienteEncontrado = 0; // Variável para rastrear se algum cliente foi encontrado

    system("clear||cls");
    while (fread(cli, sizeof(Cliente), 1, fp)) {
        if (cli->status == 1) {
            printCliente(cli); 
            clienteEncontrado = 1; // Marca que um cliente foi encontrado
        }
    }
    fclose(fp);
    free(cli); 
    if (!clienteEncontrado) {
        printf("\nNenhum cliente ativo encontrado.\n"); // Mensagem se nenhum cliente ativo for encontrado
    }
    printf("\n");
    printf("\t\t>>> Tecle ENTER para voltar ao menu anterior... <<<");
    getchar();
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
        printf("\t\t\tCLIENTE NAO ENCONTRADO!\n\n");
        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
        getchar();
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
        printf("\t\t\tCLIENTE NAO ENCONTRADO!\n");
    }
}

// Cadastra um novo cliente
void cadCliente(void) {
    Cliente *cli;
    cli = tela_cadastro_cliente();
    gravaCliente(cli);
    free(cli);
}

// Remove um cliente
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
        printf("\t\t\tCLIENTE NAO ENCONTRADO OU JA REMOVIDO!\n");
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
        printf("\t\t\tCLIENTE NAO ENCONTRADO!\n\n");
    } else {
        cli->status = 0;
        removeCliente(cli);
        free(cli);
        cli = NULL; // Define cli como NULL após remoção
        printf("\n");
        printf("\t\t\tCLIENTE EXCLUIDO COM SUCESSO!\n");
    }

    free(cpf);
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    limparBuffer();
}