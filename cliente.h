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
    int status;
};

void moduloCliente(void);
char tela_menu_cliente(void);
Cliente* tela_cadastro_cliente(void);
Cliente* tela_pesquisar_cliente(void);
char* tela_alterar_cliente(void);
char* tela_excluir_cliente(void);
void printCliente(Cliente*);
Cliente* buscaCliente(char*);
void atualizaCliente(void);
void regravarCliente(Cliente*);
void cadCliente(void);
void removeCliente(Cliente*);
void excluirCliente(void);
void gravaCliente(Cliente*);
void listarTodosClientes(void);


void limparBuffer(void);
// int validarNome(char *nome);
// int validarCPF(char *cpf);
// int validarEmail(char *email);
// int validarData(char *data);
// int validarFone(char *fone);
int verificaCPFDuplicado(const char*);
int verificaEmailDuplicado(const char*);







