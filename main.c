#include <stdio.h>
#include <stdlib.h>
#define TAM_MAX 5

int print_vetor(int vet[], int tamanho)
{
  int counter = 0;
  printf("{ ");
  for (int i; i < tamanho; i++)
  {
    if (vet[i] != 0)
    {
      counter++;
      if (i == tamanho - 1)
      {
        printf("%d", vet[i]);
      }
      else
      {
        printf("%d,", vet[i]);
      }
    }
  }
  printf(" }\n");
  return counter;
}

int main()
{
  int numeros[TAM_MAX] = {};

  for (int i = 0; i < TAM_MAX; i++)
  {
    if (i > 0)
      printf("Restam %d valores que ainda podem ser digitados.\n", TAM_MAX - i);

    printf("Digite 0 para sair\n");
    printf("Digite um valor: ");
    scanf("%d", &numeros[i]);

    if (numeros[i] == 0)
      break;

    if (numeros[i] < 0 && numeros[i] > 100)
    {
      printf("Esse valor nao está no intervalo!\n");
      printf("Digite novamente!\n");
      i--;
    }
  }

  int result = print_vetor(numeros, TAM_MAX);
  printf("Valores inseridos: %d\n", result);

  return 0;
}