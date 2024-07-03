#define TAM 10


struct Produto {
  char nome[20];
  int codigo;
  int quantidade;
  float preco;
};

void exibirMenu();
void receberDadosPrateleira(struct Produto vetor[], int tam);
float calcularValorEstoqueProduto(struct Produto produto);
float calcularValorTotalEstoque(struct Produto vetor[], int tam);
void encontrarProdutoMaisCaro(struct Produto vetor[], int tam);
void encontrarProdutoMaisBarato(struct Produto vetor[], int tam);
void buscarCodigo(struct Produto vetor[], int tam, int codBusca);
