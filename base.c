// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <locale.h>

// // --- Definição das Estruturas ---

// typedef struct {
//     int codigo;
//     char nome[50];
//     int quantidade;
//     float preco;
// } Produto;

// typedef struct No {
//     Produto dado;
//     struct No* proximo;
// } No;

// // --- Protótipos das Funções ---
// // No* criarNo(Produto p);
// // void adicionarProduto(No** cabeca);
// void listarProdutos(No* cabeca);
// void buscarProduto(No* cabeca);
// void editarProduto(No* cabeca);
// void removerProduto(No** cabeca);
// void verificarEstoqueBaixo(No* cabeca, int limite);
// void salvarEmArquivo(No* cabeca, const char* nomeArquivo);
// // void carregarDoArquivo(No** cabeca, const char* nomeArquivo);
// // void liberarLista(No** cabeca);
// // void exibirValorTotal(No* cabeca);
// // int existeCodigo(No* cabeca, int codigo);
// // void limparBuffer();

// // --- Função Principal ---
// int main() {
//     setlocale(LC_ALL, "Portuguese");
//     No* estoque = NULL;
//     int opcao;
//     char nomeArquivo[] = "estoque_db.txt";

//     // Carrega dados existentes ao iniciar
//     carregarDoArquivo(&estoque, nomeArquivo);

//     do {
//         printf("\n====================================\n");
//         printf("   SISTEMA DE GESTÃO DE ESTOQUE\n");
//         printf("====================================\n");
//         printf("1. Adicionar Produto\n");
//         printf("2. Listar Todos\n");
//         printf("3. Buscar por Código\n");
//         printf("4. Editar Produto\n");
//         printf("5. Remover Produto\n");
//         printf("6. Relatório: Estoque Baixo\n");
//         printf("7. Relatório: Valor Total do Estoque\n");
//         printf("8. Salvar Agora\n");
//         printf("0. Sair e Salvar\n");
//         printf("Escolha: ");
//         scanf("%d", &opcao);
//         limparBuffer();

//         switch(opcao) {
//             case 1: adicionarProduto(&estoque); break;
//             case 2: listarProdutos(estoque); break;
//             case 3: buscarProduto(estoque); break;
//             case 4: editarProduto(estoque); break;
//             case 5: removerProduto(&estoque); break;
//             case 6:
//                 printf("Defina o limite para alerta (ex: 5): ");
//                 int lim;
//                 scanf("%d", &lim);
//                 verificarEstoqueBaixo(estoque, lim);
//                 break;
//             case 7: exibirValorTotal(estoque); break;
//             case 8: salvarEmArquivo(estoque, nomeArquivo); break;
//             case 0:
//                 salvarEmArquivo(estoque, nomeArquivo);
//                 printf("Saindo e salvando dados...\n");
//                 break;
//             default: printf("Opção inválida!\n");
//         }
//     } while (opcao != 0);

//     liberarLista(&estoque);
//     return 0;
// }

// // --- Implementação das Funções ---

// // Utilitário para limpar o buffer do teclado (evita erros com scanf/fgets)
// void limparBuffer() {
//     int c;
//     while ((c = getchar()) != '\n' && c != EOF);
// }

// // Verifica se um código já existe na lista
// int existeCodigo(No* cabeca, int codigo) {
//     No* atual = cabeca;
//     while (atual != NULL) {
//         if (atual->dado.codigo == codigo) return 1;
//         atual = atual->proximo;
//     }
//     return 0;
// }

// // Aloca memória para um novo nó
// No* criarNo(Produto p) {
//     No* novo = (No*) malloc(sizeof(No));
//     if (novo) {
//         novo->dado = p;
//         novo->proximo = NULL;
//     }
//     return novo;
// }

// void adicionarProduto(No** cabeca) {
//     Produto p;
//     printf("\n--- Novo Produto ---\n");
//     printf("Código (número inteiro): ");
//     scanf("%d", &p.codigo);
//     limparBuffer();

//     if (existeCodigo(*cabeca, p.codigo)) {
//         printf("Erro: Já existe um produto com este código!\n");
//         return;
//     }

//     printf("Nome do Produto: ");
//     fgets(p.nome, 50, stdin);
//     p.nome[strcspn(p.nome, "\n")] = 0; // Remove o \n do final

//     printf("Quantidade: ");
//     scanf("%d", &p.quantidade);

//     printf("Preço Unitário: ");
//     scanf("%f", &p.preco);

//     No* novoNo = criarNo(p);
   
//     // Inserção ordenada (opcional) ou no início.
//     // Aqui faremos inserção no início por ser O(1) e mais simples.
//     novoNo->proximo = *cabeca;
//     *cabeca = novoNo;
   
//     printf("Produto cadastrado com sucesso!\n");
// }

// void listarProdutos(No* cabeca) {
//     if (cabeca == NULL) {
//         printf("\nEstoque vazio.\n");
//         return;
//     }
//     printf("\n--- Lista de Produtos ---\n");
//     printf("%-6s | %-20s | %-5s | %-10s\n", "COD", "NOME", "QTD", "PREÇO");
//     printf("--------------------------------------------------\n");
   
//     No* atual = cabeca;
//     while (atual != NULL) {
//         printf("%-6d | %-20s | %-5d | R$ %-8.2f\n",
//                atual->dado.codigo, atual->dado.nome,
//                atual->dado.quantidade, atual->dado.preco);
//         atual = atual->proximo;
//     }
// }

// void buscarProduto(No* cabeca) {
//     int cod;
//     printf("Digite o código para busca: ");
//     scanf("%d", &cod);
   
//     No* atual = cabeca;
//     while (atual != NULL) {
//         if (atual->dado.codigo == cod) {
//             printf("\nProduto Encontrado:\n");
//             printf("Nome: %s\nQuantidade: %d\nPreço: R$ %.2f\n",
//                    atual->dado.nome, atual->dado.quantidade, atual->dado.preco);
//             return;
//         }
//         atual = atual->proximo;
//     }
//     printf("Produto não encontrado.\n");
// }

// void editarProduto(No* cabeca) {
//     int cod;
//     printf("Digite o código do produto para editar: ");
//     scanf("%d", &cod);
//     limparBuffer();

//     No* atual = cabeca;
//     while (atual != NULL) {
//         if (atual->dado.codigo == cod) {
//             printf("Editando produto: %s\n", atual->dado.nome);
           
//             printf("Novo Nome (Enter para manter '%s'): ", atual->dado.nome);
//             char tempNome[50];
//             fgets(tempNome, 50, stdin);
//             if (strcmp(tempNome, "\n") != 0) {
//                 tempNome[strcspn(tempNome, "\n")] = 0;
//                 strcpy(atual->dado.nome, tempNome);
//             }

//             printf("Nova Quantidade: ");
//             scanf("%d", &atual->dado.quantidade);
           
//             printf("Novo Preço: ");
//             scanf("%f", &atual->dado.preco);
           
//             printf("Produto atualizado!\n");
//             return;
//         }
//         atual = atual->proximo;
//     }
//     printf("Produto não encontrado.\n");
// }

// void removerProduto(No** cabeca) {
//     int cod;
//     printf("Digite o código para remover: ");
//     scanf("%d", &cod);

//     No* atual = *cabeca;
//     No* anterior = NULL;

//     while (atual != NULL && atual->dado.codigo != cod) {
//         anterior = atual;
//         atual = atual->proximo;
//     }

//     if (atual == NULL) {
//         printf("Produto não encontrado.\n");
//         return;
//     }

//     // Se for o primeiro da lista
//     if (anterior == NULL) {
//         *cabeca = atual->proximo;
//     } else {
//         anterior->proximo = atual->proximo;
//     }

//     free(atual);
//     printf("Produto removido com sucesso.\n");
// }

// // Funcionalidade Extra 1: Relatório de Estoque Baixo
// void verificarEstoqueBaixo(No* cabeca, int limite) {
//     printf("\n--- Alerta de Estoque Baixo (Menor que %d) ---\n", limite);
//     int count = 0;
//     No* atual = cabeca;
//     while (atual != NULL) {
//         if (atual->dado.quantidade < limite) {
//             printf("URGENTE: [%d] %s - Apenas %d unidades\n",
//                    atual->dado.codigo, atual->dado.nome, atual->dado.quantidade);
//             count++;
//         }
//         atual = atual->proximo;
//     }
//     if (count == 0) printf("Nenhum produto com estoque baixo.\n");
// }

// // Funcionalidade Extra 2: Valor Total do Patrimônio
// void exibirValorTotal(No* cabeca) {
//     float total = 0;
//     No* atual = cabeca;
//     while (atual != NULL) {
//         total += (atual->dado.quantidade * atual->dado.preco);
//         atual = atual->proximo;
//     }
//     printf("\nValor total do estoque em mercadorias: R$ %.2f\n", total);
// }

// // --- Persistência de Dados (Arquivo) ---

// void salvarEmArquivo(No* cabeca, const char* nomeArquivo) {
//     FILE* file = fopen(nomeArquivo, "w");
//     if (!file) {
//         printf("Erro ao abrir arquivo para escrita!\n");
//         return;
//     }

//     No* atual = cabeca;
//     while (atual != NULL) {
//         // Formato CSV: codigo;nome;quantidade;preco
//         fprintf(file, "%d;%s;%d;%.2f\n",
//                 atual->dado.codigo,
//                 atual->dado.nome,
//                 atual->dado.quantidade,
//                 atual->dado.preco);
//         atual = atual->proximo;
//     }
//     fclose(file);
//     printf("Dados salvos em '%s'.\n", nomeArquivo);
// }

// void carregarDoArquivo(No** cabeca, const char* nomeArquivo) {
//     FILE* file = fopen(nomeArquivo, "r");
//     if (!file) {
//         printf("Nenhum arquivo de dados encontrado. Iniciando novo estoque.\n");
//         return;
//     }

//     Produto p;
//     // O loop lê o arquivo linha por linha seguindo o formato salvo
//     while (fscanf(file, "%d;%[^;];%d;%f\n", &p.codigo, p.nome, &p.quantidade, &p.preco) == 4) {
//         No* novo = criarNo(p);
//         novo->proximo = *cabeca;
//         *cabeca = novo;
//     }
//     fclose(file);
//     printf("Dados carregados com sucesso!\n");
// }

// void liberarLista(No** cabeca) {
//     No* atual = *cabeca;
//     No* prox;
//     while (atual != NULL) {
//         prox = atual->proximo;
//         free(atual);
//         atual = prox;
//     }
//     *cabeca = NULL;
// }