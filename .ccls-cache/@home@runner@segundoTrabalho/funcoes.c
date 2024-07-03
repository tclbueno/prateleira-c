#include "funcoes.h"
#include <locale.h>
#include <stdio.h>
#include <string.h>

void exibirMenu() {
  setlocale(LC_ALL, "Portuguese");

  printf("\n");
  printf("Menu:\n");
  printf(
      "1 - Calcular o valor em estoque de um produto, a partir do código.\n");
  printf("2 - Calcular o valor total em estoque dos produtos na prateleira.\n");
  printf("3 - Encontrar o produto mais caro da prateleira.\n");
  printf("4 - Encontrar o produto mais barato da prateleira.\n");
  printf("5 - Sair.\n");
}

void receberDadosPrateleira(struct Produto vetor[], int tam) {

  int i;

  for (i = 0; i < TAM; i++) {

    printf("Insira o nome do produto: ");
    fgets(vetor[i].nome, 20, stdin);
    fflush(stdin);

    printf("Insira o codigo do produto: ");
    scanf("%d", &vetor[i].codigo);

    printf("Insira a quantidade do produto: ");
    scanf("%d", &vetor[i].quantidade);

    printf("Insira o preço do produto: ");
    scanf("%f", &vetor[i].preco);
    fflush(stdin);

    getchar();

    printf("\n\n");
  }
}

float calcularValorEstoqueProduto(struct Produto produto) {
  return produto.preco * produto.quantidade;
}

float calcularValorTotalEstoque(struct Produto vetor[], int tam) {
  int i = 0;
  float totalEstoque = 0;

  for (i = 0; i < TAM; i++) {

    totalEstoque += calcularValorEstoqueProduto(vetor[i]);
  }
  return totalEstoque;
}

void encontrarProdutoMaisCaro(struct Produto vetor[], int tam) {
  int maisCaro = 0;

  for (int i = 1; i < TAM; i++) {

    if (vetor[i].preco > vetor[maisCaro].preco) {

      maisCaro = i;
    }
  }
  printf("Nome: %s - Código: %d - Quantidade: %d - Preço: %.2f\n",
         vetor[maisCaro].nome, vetor[maisCaro].codigo,
         vetor[maisCaro].quantidade, vetor[maisCaro].preco);
}

void encontrarProdutoMaisBarato(struct Produto vetor[], int tam) {
  int maisBarato = 0;

  for (int i = 1; i < TAM; i++) {
    if (vetor[i].preco < vetor[maisBarato].preco) {
      maisBarato = i;
    }
  }
  printf("Nome: %s - Código: %d - Quantidade: %d - Preço: %.2f\n",
         vetor[maisBarato].nome, vetor[maisBarato].codigo,
         vetor[maisBarato].quantidade, vetor[maisBarato].preco);
}
