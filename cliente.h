///////////////////////////////////////////////////////////////////////////////
///             Universidade Federal do Rio Grande do Norte                 ///
///                 Centro de Ensino Superior do Serido                     ///
///             PROJETO SIG DE UMA LOJA PARA ARTIGOS FEMININOS              ///
///             Developed by @stenioeric -- since August, 2023              ///
///////////////////////////////////////////////////////////////////////////////

/// Assinatura das funcoes

void moduloCliente(void);
char tela_menu_cliente(void);
void tela_cadastro_cliente(void);
void tela_pesquisar_cliente(void);
void tela_alterar_cliente(void);
void tela_excluir_cliente(void);
void valCliente (char *nome, char *cpf, char *email, char *dataNasc, char *telefone);
void limparBuffer(void);
int validarNome(char *nome);
int validarCPF(char *cpf);
int valEmail(char *email);
int validarData(char *data);
int validarFone(char *fone);



