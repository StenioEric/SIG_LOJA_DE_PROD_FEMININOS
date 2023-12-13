///////////////////////////////////////////////////////////////////////////////
///             Universidade Federal do Rio Grande do Norte                 ///
///                 Centro de Ensino Superior do Serido                     ///
///             PROJETO SIG DE UMA LOJA PARA ARTIGOS FEMININOS              ///
///             Developed by @stenioeric -- since August, 2023              ///
///////////////////////////////////////////////////////////////////////////////

/// Assinatura das funcoes
/// Assinatura das funcoes

typedef struct cliente Cliente;
struct cliente {
    char nome[70];
    char cpf[12];
    char email[50];
    char dataNas[15];
    char telefone[15];
    Cliente *prox;
    int status;
};

////////////////////////////////
/// FUNCOES COM TELA
void moduloCliente(void);
char tela_menu_cliente(void);
Cliente* tela_cadastro_cliente(void);
Cliente* tela_pesquisar_cliente(void);
char* tela_alterar_cliente(void);
char* tela_excluir_cliente(void);


////////////////////////////////
/// FUNCOES DO MODULO CLIENTES
void printCliente(Cliente*);
Cliente* buscaCliente(char*);
void atualizaCliente(void);
void regravarCliente(Cliente*);
void cadCliente(void);
void removeCliente(Cliente*);
void excluirCliente(void);
void gravaCliente(Cliente*);
// void cabecalhoCli(void);
// void exibeCliente(Cliente*);



////////////////////////////////
/// FUNCOES UTEIS
int verificaCPFDuplicado(const char*);
int verificaEmailDuplicado(const char*);







