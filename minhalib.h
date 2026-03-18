//esse arqiovo tem função de definir as estruturas e inicializar as  funções que serão utilizadas

#ifndef MINHALIB_H
#define MINHALIB_H

typedef struct{
  int codigo;
  char nome[50];
  int qtd;
  float preco;
} Produto;

typedef struct No{
  Produto dados;
  struct No* proximo;
}No;


No* criarNo(Produto p);
void inserirOrdenado(No** ptrInicial, Produto p);
void adicionarProduto(No** ptrInicial);
void listarProdutos(No* ptrInicial);
void buscarProduto(No* ptrInicial);
void editarProduto(No* ptrInicial);
void removerProduto(No** ptrInicial);
void verificarEstoqueBaixo(No* ptrInicial);
void salvarEmArquivo(No* ptrInicial, const char* nomeArquivo);
void carregarDoArquivo(No** ptrInicial, const char* nomeArquivo);
void liberarLista(No** ptrInicial); 
void exibirValorTotal(No* ptrInicial);
int jaExiste(No* ptrInicial, int codigo);
void limparBuffer();

#endif
