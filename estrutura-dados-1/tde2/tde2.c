#include <stdio.h>

#define T 9
#define POSICAO_LIVRE -1

void ver_lista_cartas_invertida(int lista[T]) {
  int i;

  for (i = T - 1; i >= 0; i--) {
    printf("[%d]", lista[i]);
    
    if (i != 0) {
      printf(" - ");
    }
  }
}

void ver_lista_cartas(int lista[T]) {
  int i;

  for (i = 0; i < T; i++) {
    if (lista[i] == POSICAO_LIVRE) {
      printf("[]");
    } else {
      printf("[%d]", lista[i]);
    }

    if (i != T - 1) {
      printf(" - ");
    }
  }

  printf("\n");
}

int achar_posicao_repetido(int valor, int vet[T]) {
  int i;
  for (i = T - 1; i >= 0; i--) {
    if (vet[i] == valor) {
      return i; }
  }
  return -1;
}

void inserir_reposicionar_itens(int valor, int pos, int vet[T]) {
  // insere o valor na posicao e 'empurra' todos os itens posteriores uma posicao pra direita

  if (vet[pos] == POSICAO_LIVRE) {
    vet[pos] = valor;
    return;
  }

  int i;
  int aux;
  for (i = pos; i < T; i++) {
    if (i == pos) {
      aux = vet[i];
      vet[i] = valor;
      continue;
    }

    if (aux == POSICAO_LIVRE) { return; }

    int temp = vet[i];
    vet[i] = aux;
    aux = temp;
  }
}

void recebe_carta(int carta, int vet[T]) {
  int i;
  int pos_repetido = achar_posicao_repetido(carta, vet);

  if (pos_repetido != -1) {
    printf("{info} Repetido, inserindo na posicao %d\n", pos_repetido + 1);

    inserir_reposicionar_itens(carta, pos_repetido + 1, vet);
  } else {
    printf("{info} Nao repetido\n");

    // achar posicao para a carta
    int posicao = 0;
    for (i = 0; i < T; i++) { 
      if (vet[i] != POSICAO_LIVRE && vet[i] < carta) { posicao = i + 1; }
    } 

    inserir_reposicionar_itens(carta, posicao, vet); }
}

int main() {
  int vet[T];
  int carta_atual;
  int i;

  for (i = 0; i < T; i++) { vet[i] = POSICAO_LIVRE; }

  printf("Total de cartas a serem inseridas: %d\n", T);

  for (i = 0; i < T; i++) {
    printf("Lista cartas: ");
    ver_lista_cartas(vet);

    printf("Informe a carta: \n");
    scanf("%d", &carta_atual);


    recebe_carta(carta_atual, vet);
  }

  printf("\n -------------------------");

  printf("\n Lista em ordem crescente: \n");
  ver_lista_cartas(vet);

  printf("\n Lista em ordem decrescente: \n");
  ver_lista_cartas_invertida(vet);

  return 0;
}
