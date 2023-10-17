///////////////////////////////////////////////////////////////////////////////
///             Universidade Federal do Rio Grande do Norte                 ///
///                 Centro de Ensino Superior do Serido                     ///
///             PROJETO SIG DE UMA LOJA PARA ARTIGOS FEMININOS              ///
///             Developed by @stenioeric -- since August, 2023              ///
///////////////////////////////////////////////////////////////////////////////
typedef struct funcio Funcio;
struct funcio {
    char nome[70];
    char cargo[20];
    char cpf[13];
    char dataNas[12];
    char email[30];
    char telefone[12];
    char salario[12];
};

void moduloFuncio(void);
char tela_menu_funcionarios(void);
void tela_cadastro_funcionarios(void);
void tela_pesquisar_funcionarios(void);
void tela_alterar_funcionarios(void);
void tela_excluir_funcionarios(void);
