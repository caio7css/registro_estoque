#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>
#include "minhalib.h"


int main(void){
  setlocale(LC_ALL, "Portuguese");
  No* estoque = NULL;
  int opcao;
  char nomeArquivo[]= "estoque.txt"; 
  carregarDoArquivo(&estoque, nomeArquivo);
  
// é um crud, tem que ter função de adicionar, listar, buscar, editar, remover, relatorios sobre preço e quantidade
  do{
    printf("\n====================================\n");
    printf("SISTEMA ESTOQUE MZR'S MARKETPLACE\n");
    printf("====================================\n");
    printf("1. Adicionar Produto\n");
    printf("2. Listar Todos os Produtos\n");
    printf("3. Buscar por Código\n");
    printf("4. Editar Produto\n");
    printf("5. Remover Produto\n");
    printf("6. Relatório de Estoque Baixo\n");
    printf("7. Relatório de Valor Total Guardado\n");
    printf("0. Salvar e Sair\n"); 
    printf("Digite sua opção: ");
    scanf("%d", &opcao);
    printf("\n");
    //função de limpar buffer


    switch(opcao){
      case 1: adicionarProduto(&estoque);  break;
      case 2: listarProdutos(estoque); break;
      case 3: buscarProduto(estoque); break;
      case 4: editarProduto(estoque); break;
      case 5: removerProduto(&estoque); break;
      case 6: verificarEstoqueBaixo(estoque); break;
      case 7: exibirValorTotal(estoque); break;
      case 0: salvarEmArquivo(estoque, nomeArquivo); 
        printf("Dados salvos, saindo do programa..."); break;
      default: printf("Opção Inválida, por favor selecione uma opção válida\n");
      
      }

      
  }while(opcao !=0);

  liberarLista(&estoque);
}