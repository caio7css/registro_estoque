#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>
#include "minhalib.h"



typedef struct{
  int codigo;
  int nome[50];
  int qtd;
  float preco;
} produto;

typedef struct No{
  produto No;
  struct No* proximo;
}No;


int main(void){
  int opcao;
// é um crud, tem que ter função de adicionar, listar, buscar, editar, remover, relatorios sobre preço e quantidade
  do{
    printf("\n====================================\n");
    printf("SISTEMA ESTOQUE MIZERA'S MARKETPLACE\n");
    printf("====================================\n");
    printf("1. Adicionar Produto\n");
    printf("2. Listar Todos os Produtos\n");
    printf("3. Buscar por Código\n");
    printf("4. Editar Produto\n");
    printf("5. Remover Produto\n");
    printf("6. Relatório de Estoque Baixo\n");
    printf("7. Relatóriovde Valor Total Guardado\n");
    printf("0. Salvar e Sair\n"); 
    printf("Digite sua opção: ");
    scanf("%d", &opcao);
    //função de limpar buffer


    switch(opcao){
      case 1: //chama funcao daqui; break;
      case 2: //chama funcao daqui; break;
      case 3: //chama funcao daqui; break;
      case 4: //chama funcao daqui; break;
      case 5: //chama funcao daqui; break;
      case 6: //chama funcao daqui; break;
      case 7: //chama funcao daqui; break;
      case 0: //chama funcao daqui; break;
      default: printf("Opção Inválida moral, por favor selecione uma opção válida\n");
      
      
      }

      
  }while(opcao !=0);
    
}



