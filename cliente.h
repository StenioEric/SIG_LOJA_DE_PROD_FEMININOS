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
    char cpf[13];
    char email[30];
    char dataNas[11];
    char telefone[12];
};

void moduloCliente(void);
char tela_menu_cliente(void);
Cliente* tela_cadastro_cliente(void);
void tela_pesquisar_cliente(void);
void tela_alterar_cliente(void);
void tela_excluir_cliente(void);

void valCliente (Cliente*);
void limparBuffer(void);
int validarNome(char *nome);
int validarCPF(char *cpf);
int valEmail(char *email);
int validarData(char *data);
int validarFone(char *fone);






