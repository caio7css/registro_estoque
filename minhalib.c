#include <stdio.h>
#include "minhalib.h"


void limparBuffer(){
    int c;
    while((c =getchar()) != '\n' &&  c != EOF);
}

int jaExiste(No* prtInicial, int codigo){
    No* atual = prtInicial;
    while(atual!=NULL){
        if(atual-> dados.codigo == codigo){
            return 1;
        }
        atual = atual->proximo;
    }
    return 0;
}

No* criarNo(Produto p){
    No* novo = (No*) malloc(sizeof(No));
    if (novo){
        novo->dados = p;
        novo->proximo = NULL;
    }
    return novo;
}

void adicionarProduto(No** ptrInicial){
    Produto p;
    printf("\n--- Novo Produto ---\n");
    printf("Código (número inteiro): ");
    scanf("%d", &p.codigo);
    limparBuffer();

    if (jaExiste(*ptrInicial, p.codigo)) {
        printf("Erro: Já existe um produto com este código!\n");
        return;
    }

    printf("Nome do Produto: ");
    fgets(p.nome, 50, stdin);
    p.nome[strcspn(p.nome, "\n")] = 0; // Remove o \n do final

    printf("Quantidade: ");
    scanf("%d", &p.qtd);

    printf("Preço Unitário: ");
    scanf("%f", &p.preco);

    No* prtNovo = criarNo(p);
    if(prtNovo != NULL){
        prtNovo->dados = p;
        prtNovo->proximo = NULL;

        No* ptrAnterior = NULL;
        No* ptrAtual = *ptrInicial;

        while(ptrAtual != NULL && p.codigo > ptrAtual->dados.codigo){
            ptrAnterior = ptrAtual;
            ptrAtual = ptrAtual->proximo;
        }
    
        if(ptrAnterior == NULL){
            prtNovo->proximo = *ptrInicial;
            *ptrInicial = prtNovo;
        }
        else{
            ptrAnterior->proximo = prtNovo;
            prtNovo->proximo = ptrAtual;
        }
    }

}

void exibirValorTotal(No* ptrInicial){
    float total = 0;
    No* ptrAtual = ptrInicial;
    while(ptrAtual!=NULL){
        total+=(ptrAtual->dados.qtd*ptrAtual->dados.preco);
        ptrAtual=ptrAtual->proximo;
    }
printf("\n O valor total em estoque de mercadorias é: R$: %.2f\n",total);
}

void carregarDoArquivo(No** ptrInicial, const char*nomeArquivo){
    FILE *arq = fopen(nomeArquivo, "r");
    if(arq){
        Produto p;
        while (fscanf(arq, "%d;%[^;];%d;%f\n", &p.codigo, p.nome, &p.qtd, &p.preco) == 4) {
            No* ptrNovo = criarNo(p);
            ptrNovo->proximo = *ptrInicial;
            *ptrInicial = ptrNovo;
    }
    fclose(arq);
    printf("Dados carregados com sucesso!\n");
    }
    else{
        printf("Não há arquivos de dados.\n");
        return;
    }
}


void liberaLista(No *ptrInicial){
    No* ptrAtual = ptrInicial;
    No* ptrProximo;
    while(ptrAtual != NULL){
        ptrProximo = ptrAtual->proximo;
        free(ptrAtual);
        ptrAtual = ptrProximo;
    }
    ptrInicial = NULL;
}