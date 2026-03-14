#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "minhalib.h"

void limparBuffer(){
    int c;
    while((c =getchar()) != '\n' &&  c != EOF);
}

int jaExiste(No* ptrInicial, int codigo){
    No* atual = ptrInicial;
    while(atual!=NULL){
        if(atual->dados.codigo == codigo){
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


void liberarLista(No** ptrInicial){
    No* ptrAtual = *ptrInicial;
    No* ptrProximo;
    while(ptrAtual != NULL){
        ptrProximo = ptrAtual->proximo;
        free(ptrAtual);
        ptrAtual = ptrProximo;
    }
    *
    ptrInicial = NULL;
}

void listarProdutos(No* ptrInicial){

    No* ptrAtual = ptrInicial;

    if(ptrAtual == NULL){
        printf("Estoque vazio.\n");
        return;
    }

    while(ptrAtual != NULL){

        printf("Codigo: %d\n", ptrAtual->dados.codigo);
        printf("Nome: %s\n", ptrAtual->dados.nome);
        printf("Quantidade: %d\n", ptrAtual->dados.qtd);
        printf("Preco: %.2f\n", ptrAtual->dados.preco);
        printf("---------------------\n");

        ptrAtual = ptrAtual->proximo;
    }
}

void buscarProduto(No* ptrInicial){

    int codigo;

    printf("Digite o codigo: ");
    scanf("%d",&codigo);

    No* ptrAtual = ptrInicial;

    while(ptrAtual != NULL){

        if(ptrAtual->dados.codigo == codigo){

            printf("Produto encontrado!\n");
            printf("Nome: %s\n", ptrAtual->dados.nome);
            printf("Quantidade: %d\n", ptrAtual->dados.qtd);
            printf("Preco: %.2f\n", ptrAtual->dados.preco);

            return;
        }

        ptrAtual = ptrAtual->proximo;
    }

    printf("Produto nao encontrado.\n");
}

void editarProduto(No* ptrInicial){

    int codigo;

    printf("Codigo do produto: ");
    scanf("%d",&codigo);

    No* ptrAtual = ptrInicial;

    while(ptrAtual != NULL){

        if(ptrAtual->dados.codigo == codigo){

            printf("Novo nome: ");
            scanf("%s", ptrAtual->dados.nome);

            printf("Nova quantidade: ");
            scanf("%d",&ptrAtual->dados.qtd);

            printf("Novo preco: ");
            scanf("%f",&ptrAtual->dados.preco);

            printf("Produto atualizado!\n");
            return;
        }

        ptrAtual = ptrAtual->proximo;
    }

    printf("Produto nao encontrado.\n");
}

void removerProduto(No** ptrInicial){

    int codigo;

    printf("Codigo para remover: ");
    scanf("%d",&codigo);

    No* ptrAtual = *ptrInicial;
    No* ptrAnterior = NULL;

    while(ptrAtual != NULL && ptrAtual->dados.codigo != codigo){

        ptrAnterior = ptrAtual;
        ptrAtual = ptrAtual->proximo;
    }

    if(ptrAtual == NULL){
        printf("Produto nao encontrado.\n");
        return;
    }

    if(ptrAnterior == NULL){
        *ptrInicial = ptrAtual->proximo;
    }
    else{
        ptrAnterior->proximo = ptrAtual->proximo;
    }

    free(ptrAtual);

    printf("Produto removido.\n");
}

void verificarEstoqueBaixo(No* ptrInicial){
    printf("Digite um quantidade limite para que você seja alertado (ex: 5): ");
    int limite;
    scanf("%d", &limite);

    No* ptrAtual = ptrInicial;

    printf("Produto com estoque baixo:\n");
    while(ptrAtual != NULL){

        if(ptrAtual->dados.qtd < limite){

            printf("%s - %d unidades\n",
                   ptrAtual->dados.nome,
                   ptrAtual->dados.qtd);
        }

        ptrAtual = ptrAtual->proximo;
    }
}

void salvarEmArquivo(No* ptrInicial, const char* nomeArquivo){

    FILE* arquivo;

    arquivo = fopen(nomeArquivo,"w");

    if(arquivo == NULL){
        printf("Erro ao abrir arquivo.\n");
        return;
    }

    No* ptrAtual = ptrInicial;

    while(ptrAtual != NULL){

        fprintf(arquivo,"%d;%s;%d;%.2f\n",
        ptrAtual->dados.codigo,
        ptrAtual->dados.nome,
        ptrAtual->dados.qtd,
        ptrAtual->dados.preco);

        ptrAtual = ptrAtual->proximo;
    }

    fclose(arquivo);

    printf("Dados salvos.\n");
}