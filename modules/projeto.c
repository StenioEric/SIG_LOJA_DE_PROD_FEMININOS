///////////////////////////////////////////////////////////////////////////////
///             Universidade Federal do Rio Grande do Norte                 ///
///                 Centro de Ensino Superior do Serido                     ///
///             PROJETO SIG DE UMA LOJA PARA ARTIGOS FEMININOS              ///
///             Developed by @stenioeric -- since August, 2023              ///
///////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include "projeto.h"
#include "util.h"

void moduloSobre (void) {

    tela_sobre_projeto();
    tela_info_desenvolvedor();
    
}


void tela_sobre_projeto(void) {
    system("clear||cls");
    printf("\n");
    printf("|=============================================================================|\n");
    printf("|                                                                             |\n");
    printf("|                      ------------ PROJETO ------------                      |\n");
    printf("|                                                                             |\n");
    printf("|  Programa em linguagem C desenvolvido com fins didaticos na UFRN Campus     |\n");
    printf("|  Ceres simula uma loja de artigos femininos, permitindo aos estudantes      |\n");
    printf("|  aplicar conceitos aprendidos em sala de aula de forma pratica. Atraves     |\n");
    printf("|  da manipulacoes de estruturas de dados, os alunos gerenciam informacoes    |\n");
    printf("|  sobre produto,precos e categorias,aprimorando habilidades de resolucao     |\n");
    printf("|  de problemas e logica de programacao.                                      |\n");
    printf("|                                                                             |\n");
    printf("|=============================================================================|\n");
    espacamento();
}


void tela_info_desenvolvedor(void) {
    system("clear||cls");
    printf("\n");
    printf("|=============================================================================|\n");
    printf("|                                                                             |\n");
    printf("|         ------------ INFORMACOES SOBRE O DESENVOLVEDOR ------------         |\n");
    printf("|                                                                             |\n");
    printf("|    Discente: Stenio Eric                                                    |\n");
    printf("|    E-mail: stenioeric@gmail.com                                             |\n");
    printf("|    Telefone: (84) 981295674                                                 |\n");
    printf("|    Redes sociais: @stenioeric                                               |\n");
    printf("|    Git:https://github.com/StenioEric/SIG_LOJA_DE_PROD_FEMININOS.git         |\n");
    printf("|                                                                             |\n");
    printf("|=============================================================================|\n");
    espacamento();
}
