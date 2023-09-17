///////////////////////////////////////////////////////////////////////////////
///             Universidade Federal do Rio Grande do Norte                 ///
///                 Centro de Ensino Superior do Serido                     ///
///             PROJETO SIG DE UMA LOJA PARA ARTIGOS FEMININOS              ///
///             Developed by @stenioeric -- since August, 2023              ///
///////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "cliente.c"
#include "vendas.c"
#include "estoque.c"
#include "funcionario.c"
#include "gerencia.c"

////
// Assinatura das funcoes
int tela_menu_principal(void);
void tela_sobre_projeto(void);
void tela_info_desenvolvedor(void);



////
// Programa principal
int main(void) {
    int op;

    do {
        op = tela_menu_principal();
        switch (op) {
            case 1: moduloCliente();
                    break;
            case 2: moduloVendas();
                    break;
            case 3: moduloEstoque();
                    break;
            case 4: moduloFuncio();
                    break;
            case 5: moduloGerencia();
                    break;
            case 6: tela_info_desenvolvedor();
                    break;
            case 7: tela_sobre_projeto();
                    break; 

        }
    } while (op != 0);

    return 0;
}



/////
// Funcoes

int tela_menu_principal(void)
{
    int op;
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
    printf("///           ------------ SISTEMA DE GERENCIAMENTO ------------            ///\n");
    printf("///                                                                         ///\n");
    printf("///            1. MENU CLIENTES                                             ///\n");
    printf("///            2. MENU VENDAS                                               ///\n");
    printf("///            3. MENU ESTOQUE                                              ///\n");
    printf("///            4. MENU FUNCIONARIOS                                         ///\n");
    printf("///            5. MENU GERENCIA                                             ///\n");
    printf("///            6. INFORMACOES DO DESENVOLVEDOR                              ///\n");
    printf("///            7. INFORMACOES DO PROJETO                                    ///\n");
    printf("///            0. SAIR                                                      ///\n");
    printf("///                                                                         ///\n");
    printf("///            ESCOLHA A OPCAO DESEJADA: ");
    scanf("%d", &op);
    getchar();
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    return op;
}


void tela_sobre_projeto(void)
{
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
    printf("///                  ------------ PROJETO ------------                      ///\n");
    printf("///                                                                         ///\n");
    printf("///  Programa em linguagem C desenvolvido com fins didaticos na UFRN Campus ///\n");
    printf("///  Ceres simula uma loja de artigos femininos, permitindo aos estudantes  ///\n");
    printf("///  aplicar conceitos aprendidos em sala de aula de forma pratica. Atraves ///\n");
    printf("///  da manipulacoes de estruturas de dados, os alunos gerenciam informacoes///\n");
    printf("///  sobre produto,precos e categorias,aprimorando habilidades de resolucao ///\n");
    printf("///  de problemas e logica de programacao.                                  ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void tela_info_desenvolvedor(void)
{
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
    printf("///      ------------ INFORMACOES SOBRE O DESENVOLVEDOR ------------        ///\n");
    printf("///                                                                         ///\n");
    printf("///    Discente: Stenio Eric                                                ///\n");
    printf("///    E-mail: stenioeric@gmail.com                                         ///\n");
    printf("///    Telefone: (84) 981295674                                             ///\n");
    printf("///    Redes sociais: @stenioeric                                           ///\n");
    printf("///    Git:https://github.com/StenioEric/SIG_LOJA_DE_PROD_FEMININOS.git     ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}





