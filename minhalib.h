#ifndef MINHALIB_H
#define MINHALIB_H

No* criarProduto(Produto p);
void adicionarProduto(No* ptrInicial);
void listarProdutos(No* ptrInicial);
void buscarProduto(No* ptrInicial);
void editarProduto(No* ptrInicial);
void removerProduto(No** ptrInicial);
void verificarEstoqueBaixo(No* ptrInicial, int limite);
void salvarEmArquivo(No* ptrInicial, const char* nomeArquivo);
void carregarDoArquivo(No* ptrInicial, const char* nomeArquivo);
void liberarLista(No** ptrInicial); //TALVEZ
void exibirValorTotal(No* ptrInicial);
void existeCodigo(No* ptrInicial, int codigo);
void limparBuffer();

typedef struct{
  int codigo;
  int nome[50];
  int qtd;
  float preco;
} Produto;

typedef struct No{
  Produto dados;
  struct No* proximo;
}No;

#endif
