///////////////////////////////////////////////////////////////////////////////
///             Universidade Federal do Rio Grande do Norte                 ///
///                 Centro de Ensino Superior do Serido                     ///
///             PROJETO SIG DE UMA LOJA PARA ARTIGOS FEMININOS              ///
///             Developed by @stenioeric -- since August, 2023              ///
///////////////////////////////////////////////////////////////////////////////

/// Assinatura das funcoes

typedef struct cliente Cliente;
struct cliente {
    char nome[70];
    char cpf[12];
    char email[50];
    char dataNas[15];
    char telefone[15];
    char status;
};

void moduloCliente(void);
char tela_menu_cliente(void);
Cliente* tela_cadastro_cliente(void);
void tela_pesquisar_cliente(const Cliente*);
void tela_alterar_cliente(const Cliente*);
void tela_excluir_cliente(const Cliente*);
void printCliente(Cliente*);
// void idGenerico(const Cliente*);

// void valCliente (Cliente*);
void limparBuffer(void);
int validarNome(char *nome);
int validarCPF(char *cpf);
int valEmail(char *email);
int validarData(char *data);
int validarFone(char *fone);
void gravaCliente(Cliente*);






