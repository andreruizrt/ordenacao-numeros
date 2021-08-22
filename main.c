#include <stdio.h>
#include <stdlib.h>
#define TAM_MAX 6

// Ask the vector value and return
// the dinamic allocation
int print_vetor(int vet[], int tamanho)
{
  int counter = 0;
  printf("{ ");
  for (int i = 0; i < tamanho; i++)
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

int pedir_vetor(int *vetor)
{

  for (int i = 0; i < TAM_MAX; i++)
  {
    if (i > 0)
    {
      printf("Restam %d valores que ainda podem ser digitados.\n", TAM_MAX - i);
    }

    printf("Digite um valor: ");
    scanf("%d", &vetor[i]);

    if (vetor[i] == 0)
      break;

    if (vetor[i] < 0 || vetor[i] > 100)
    {
      printf("Esse valor nao está no intervalo!\n");
      printf("Digite novamente!\n\n");
      i--;
    }
  }

  int qnt_inputs = print_vetor(vetor, TAM_MAX);
  printf("Valores inseridos: %d\n", qnt_inputs);

  return qnt_inputs;
}

int main()
{
  int *vetor = (int *)malloc(TAM_MAX * sizeof(int));
  int qnt_input = pedir_vetor(vetor);
  int *vetor_inputs = (int *)malloc(qnt_input * sizeof(int));
  
  for (int i = 0; i < qnt_input; i++)
  {
    vetor_inputs[i] = vetor[i];
  }
  
  free(vetor);
  
  print_vetor(vetor_inputs, qnt_input);


  return 0;
}