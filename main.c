///////////////////////////////////////////////////////////////////////////////
///             Universidade Federal do Rio Grande do Norte                 ///
///                 Centro de Ensino Superior do Serid√≥                     ///
///             PROJETO SIG DE UMA LOJA PARA ARTIGOS FEMININOS              ///
///             Developed by @stenioeric -- since August, 2023              ///
///////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

////
// Assinatura das fun√ß√µes
void tela_menu_principal(void);
void tela_sobre_projeto(void);
void tela_info_desenvolvedor(void);
void tela_menu_cliente(void);
void tela_cadastro_cliente(void);
void tela_pesquisar_cliente(void);
void tela_alterar_cliente(void);
void tela_excluir_cliente(void);


////
// Programa principal

int main(void) {
    setlocale(LC_ALL, "Portuguese");
    tela_menu_principal();
    tela_sobre_projeto();
    tela_info_desenvolvedor();
    tela_menu_cliente();
    tela_cadastro_cliente();
    tela_pesquisar_cliente();
    tela_alterar_cliente();
    tela_excluir_cliente();
    return 0;
}


/////
// Fun√ß√µes

void tela_menu_principal(void) {
    char op;
    system("clear||cls");
    printf("\n");
    printf("\n///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n                                                                               ");
    printf("\n             EEEEEEE lll                                                       ");
    printf("\n             EE      lll   eee   gggggg   aa aa nn nnn    cccc   eee           ");
    printf("\n             EEEEE   lll ee   e gg   gg  aa aaa nnn  nn cc     ee   e          ");
    printf("\n             EE      lll eeeee  ggggggg aa  aaa nn   nn cc     eeeee           ");
    printf("\n             EEEEEEE lll  eeeee      gg  aaa aa nn   nn  ccccc  eeeee          ");
    printf("\n                                  ggggg                                        ");
    printf("\n                                                                               ");
    printf("\n                         LOJA DE ARTIGOS FEMININOS                             ");
    printf("\n                                                                               ");                                                                       
    printf("\n///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///           ------------ SISTEMA DE GERENCIAMENTO ------------            ///\n");
    printf("///                                                                         ///\n");
    printf("///            1. MENU CLIENTES                                             ///\n");
    printf("///            2. MENU VENDAS                                               ///\n");
    printf("///            3. MENU PRODUTO                                              ///\n");
    printf("///            4. MENU FUNCIONARIOS                                         ///\n");
    printf("///            5. MENU GERENCIA                                             ///\n");
    printf("///            6. INFORMA«’ES DO PROJETO                                    ///\n");
    printf("///            0. SAIR                                                      ///\n");
    printf("///                                                                         ///\n");
    printf("///            ESCOLHA A OPC√O DESEJADA: ");
    scanf("%c", &op);
    getchar();
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}


void tela_sobre_projeto(void) {
    system("clear||cls");
    printf("\n");
    printf("\n///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n                                                                               ");
    printf("\n             EEEEEEE lll                                                       ");
    printf("\n             EE      lll   eee   gggggg   aa aa nn nnn    cccc   eee           ");
    printf("\n             EEEEE   lll ee   e gg   gg  aa aaa nnn  nn cc     ee   e          ");
    printf("\n             EE      lll eeeee  ggggggg aa  aaa nn   nn cc     eeeee           ");
    printf("\n             EEEEEEE lll  eeeee      gg  aaa aa nn   nn  ccccc  eeeee          ");
    printf("\n                                  ggggg                                        ");
    printf("\n                                                                               ");
    printf("\n                         LOJA DE ARTIGOS FEMININOS                             ");
    printf("\n                                                                               ");                                                                       
    printf("\n///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///                  ------------ PROJETO ------------                      ///\n");
    printf("///                                                                         ///\n");
    printf("///  Programa em linguagem C desenvolvido com fins did·ticos na UFRN Campus ///\n");
    printf("///  Ceres simula uma loja de artigos femininos, permitindo aos estudantes  ///\n");
    printf("///  aplicar conceitos aprendidos em sala de aula de forma pr·tica. AtravÈs ///\n");
    printf("///  da manipulaÁ„o de estruturas de dados, os alunos gerenciam informaÁıes ///\n");
    printf("///  sobre produto,preÁos e categorias,aprimorando habilidades de resoluÁ„o ///\n");
    printf("///  de problemas e lÛgica de programaÁ„o.                                  ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}


void tela_info_desenvolvedor(void) {
    system("clear||cls");
    printf("\n");
    printf("\n///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n                                                                               ");
    printf("\n             EEEEEEE lll                                                       ");
    printf("\n             EE      lll   eee   gggggg   aa aa nn nnn    cccc   eee           ");
    printf("\n             EEEEE   lll ee   e gg   gg  aa aaa nnn  nn cc     ee   e          ");
    printf("\n             EE      lll eeeee  ggggggg aa  aaa nn   nn cc     eeeee           ");
    printf("\n             EEEEEEE lll  eeeee      gg  aaa aa nn   nn  ccccc  eeeee          ");
    printf("\n                                  ggggg                                        ");
    printf("\n                                                                               ");
    printf("\n                         LOJA DE ARTIGOS FEMININOS                             ");
    printf("\n                                                                               ");                                                                       
    printf("\n///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///      ------------ INFORMA«’ES SOBRE O DESENVOLVEDOR ------------        ///\n");   
    printf("///                                                                         ///\n");
    printf("///    Discente: StÍnio …r ic                                               ///\n");
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


void tela_menu_cliente(void) {
    char op;
    system("clear||cls");
    printf("\n");
    printf("\n///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n                                                                               ");
    printf("\n             EEEEEEE lll                                                       ");
    printf("\n             EE      lll   eee   gggggg   aa aa nn nnn    cccc   eee           ");
    printf("\n             EEEEE   lll ee   e gg   gg  aa aaa nnn  nn cc     ee   e          ");
    printf("\n             EE      lll eeeee  ggggggg aa  aaa nn   nn cc     eeeee           ");
    printf("\n             EEEEEEE lll  eeeee      gg  aaa aa nn   nn  ccccc  eeeee          ");
    printf("\n                                  ggggg                                        ");
    printf("\n                                                                               ");
    printf("\n                         LOJA DE ARTIGOS FEMININOS                             ");
    printf("\n                                                                               ");                                                                       
    printf("\n///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///             ------------  MENU CLIENTES ------------                    ///\n");
    printf("///                                                                         ///\n");
    printf("///            1. CADASTRAR CLIENTE                                         ///\n");
    printf("///            2. PESQUISAR DADOS DO CLIENTE                                ///\n");
    printf("///            3. ATUALIZAR CADASTRO DO CLIENTE                             ///\n");
    printf("///            4. EXCLUIR DADOS DO CLIENTE                                  ///\n");
    printf("///            0. VOLTAR AO MENU PRINCIPAL                                  ///\n");
    printf("///                                                                         ///\n");
    printf("///            ESCOLHA A OPC√O DESEJADA: ");
    scanf("%c", &op);
    getchar();
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}


void tela_cadastro_cliente(void) {
    system("clear||cls");
    printf("\n");
    printf("\n///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n                                                                               ");
    printf("\n             EEEEEEE lll                                                       ");
    printf("\n             EE      lll   eee   gggggg   aa aa nn nnn    cccc   eee           ");
    printf("\n             EEEEE   lll ee   e gg   gg  aa aaa nnn  nn cc     ee   e          ");
    printf("\n             EE      lll eeeee  ggggggg aa  aaa nn   nn cc     eeeee           ");
    printf("\n             EEEEEEE lll  eeeee      gg  aaa aa nn   nn  ccccc  eeeee          ");
    printf("\n                                  ggggg                                        ");
    printf("\n                                                                               ");
    printf("\n                         LOJA DE ARTIGOS FEMININOS                             ");
    printf("\n                                                                               ");                                                                       
    printf("\n///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///              -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-                    ///\n");
    printf("///                         CADASTRO CLIENTE                                ///\n");
    printf("///              -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-                    ///\n");   
    printf("///                                                                         ///\n");
    printf("///            Nome Completo do Cliente:                                    ///\n");
    printf("///            CPF:                                                         ///\n");
    printf("///            E-mail:                                                      ///\n");
    printf("///            Data de Nascimento (dd/mm/aaaa):                             ///\n");
    printf("///            Celular (apenas n˙meros):                                    ///\n");
    printf("///            EndereÁo:                                                    ///\n");
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}


void tela_pesquisar_cliente(void) {
    system("clear||cls");
    printf("\n");
    printf("\n///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n                                                                               ");
    printf("\n             EEEEEEE lll                                                       ");
    printf("\n             EE      lll   eee   gggggg   aa aa nn nnn    cccc   eee           ");
    printf("\n             EEEEE   lll ee   e gg   gg  aa aaa nnn  nn cc     ee   e          ");
    printf("\n             EE      lll eeeee  ggggggg aa  aaa nn   nn cc     eeeee           ");
    printf("\n             EEEEEEE lll  eeeee      gg  aaa aa nn   nn  ccccc  eeeee          ");
    printf("\n                                  ggggg                                        ");
    printf("\n                                                                               ");
    printf("\n                         LOJA DE ARTIGOS FEMININOS                             ");
    printf("\n                                                                               ");                                                                       
    printf("\n///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///              -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-                    ///\n");
    printf("///                        PESQUISAR CLIENTE                                ///\n");
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


void tela_alterar_cliente(void) {
    system("clear||cls");
    printf("\n");
    printf("\n///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n                                                                               ");
    printf("\n             EEEEEEE lll                                                       ");
    printf("\n             EE      lll   eee   gggggg   aa aa nn nnn    cccc   eee           ");
    printf("\n             EEEEE   lll ee   e gg   gg  aa aaa nnn  nn cc     ee   e          ");
    printf("\n             EE      lll eeeee  ggggggg aa  aaa nn   nn cc     eeeee           ");
    printf("\n             EEEEEEE lll  eeeee      gg  aaa aa nn   nn  ccccc  eeeee          ");
    printf("\n                                  ggggg                                        ");
    printf("\n                                                                               ");
    printf("\n                         LOJA DE ARTIGOS FEMININOS                             ");
    printf("\n                                                                               ");                                                                       
    printf("\n///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///              -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-                    ///\n");
    printf("///                         ALTERAR CLIENTE                                 ///\n");
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


void tela_excluir_cliente(void) {
    system("clear||cls");
    printf("\n");
    printf("\n///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n                                                                               ");
    printf("\n             EEEEEEE lll                                                       ");
    printf("\n             EE      lll   eee   gggggg   aa aa nn nnn    cccc   eee           ");
    printf("\n             EEEEE   lll ee   e gg   gg  aa aaa nnn  nn cc     ee   e          ");
    printf("\n             EE      lll eeeee  ggggggg aa  aaa nn   nn cc     eeeee           ");
    printf("\n             EEEEEEE lll  eeeee      gg  aaa aa nn   nn  ccccc  eeeee          ");
    printf("\n                                  ggggg                                        ");
    printf("\n                                                                               ");
    printf("\n                         LOJA DE ARTIGOS FEMININOS                             ");
    printf("\n                                                                               ");                                                                       
    printf("\n///////////////////////////////////////////////////////////////////////////////\n");
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
