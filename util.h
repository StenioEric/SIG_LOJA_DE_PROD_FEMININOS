///////////////////////////////////////////////////////////////////////////////
///             Universidade Federal do Rio Grande do Norte                 ///
///                 Centro de Ensino Superior do Serido                     ///
///             PROJETO SIG DE UMA LOJA PARA ARTIGOS FEMININOS              ///
///             Developed by @stenioeric -- since August, 2023              ///
///////////////////////////////////////////////////////////////////////////////

/// Assinatura das funcoes
int ehDigitos(char*);
int ehDigito(char);
int ehLetra(char);
int ehBarra(char);
int ehParentese(char);
int ehBissexto(int);
int ehData(int, int, int);
int validarNome(char*);
int valEmail(char*);
int validarData(char*);
int validarFone(char*);
void limparBuffer(void);
void telaErro(void);
int verificaCPFDuplicado(const char*);
int verificaEmailDuplicado(const char*);

char* pegaNome (void);