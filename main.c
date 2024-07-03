#include "funcoes.h"
#include <locale.h>
#include <stdio.h>

int main(void) {

  setlocale(LC_ALL, "Portuguese");

  int i, buscaCodigo, opcao = 0;
  struct Produto prateleira[TAM] = {};

  receberDadosPrateleira(prateleira, TAM);

  do {
    exibirMenu();
    scanf("%d", &opcao);
    switch (opcao) {
    case 1:
      printf("Digite o código do produto: ");
      scanf("%d", &buscaCodigo);
      for (i = 0; i < TAM; i++) {
        if (prateleira[i].codigo == buscaCodigo) {
          printf("%.2f", calcularValorEstoqueProduto(prateleira[i]));
        }
      }
      break;
    case 2:
      printf("O valor total em estoque é de %.2f\n",
             calcularValorTotalEstoque(prateleira, TAM));
      break;
    case 3:
      encontrarProdutoMaisCaro(prateleira, TAM);
      break;
    case 4:
      encontrarProdutoMaisBarato(prateleira, TAM);
      break;
    case 5:
      printf("Saindo...");
      break;
    default:
      printf("Opção inválida!");
      break;
    }
  } while (opcao != 5);
}
