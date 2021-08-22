#include <stdio.h>
#include <stdlib.h>
#define TAM_MAX 6

int printVetor(int vet[], int tamanho)
{
  int counter = 0;
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
        printf("%d, ", vet[i]);
      }
    }
  }
  printf("\n");
  return counter;
}

void insertionSort(int vetor[], int tamanho, int hidden)
{
  int i, key, j;
  int comp = 0, troca = 0;

  for (i = 1; i < tamanho; i++)
  {
    key = vetor[i];
    j = i - 1;
    comp++;

    while (j >= 0 && vetor[j] > key)
    {
      vetor[j + 1] = vetor[j];
      j = j - 1;

      comp++;
      troca++;
    }

    vetor[j + 1] = key;
  }

  if (hidden)
  {
    printf("Insertion Sort: comparacoes: %d trocas: %d\n", comp, troca);
  }
}

void swap(int *xp, int *yp)
{
  int temp = *xp;
  *xp = *yp;
  *yp = temp;
}

void selectionSort(int vetor[], int tamanho)
{
  int i, j, min_idx, comp = 0, troca = 0;

  for (i = 0; i < tamanho - 1; i++)
  {
    min_idx = i;
    for (j = i + 1; j < tamanho; j++)
    {
      if (vetor[j] < vetor[min_idx])
      {
        troca++;
        min_idx = j;
      }
      comp++;
    }
    if (vetor[min_idx] != vetor[i])
      troca++;

    swap(&vetor[min_idx], &vetor[i]);
  }

  printf("Selection Sort: comparacoes: %d trocas: %d\n", comp, troca);
}

void bubbleSort(int vetor[], int tamanho)
{
  int i, j, comp = 0, troca = 0;

  for (i = 0; i < tamanho - 1; i++)

    for (j = 0; j < tamanho - i - 1; j++)
    {
      if (vetor[j] > vetor[j + 1])
      {
        swap(&vetor[j], &vetor[j + 1]);
        troca++;
      }
      comp++;
    }

  printf("Bubble Sort: comparacoes: %d trocas: %d\n", comp, troca);
}

int pedirVetor(int *vetor)
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

  int qnt_inputs = printVetor(vetor, TAM_MAX);

  return qnt_inputs;
}

int main()
{
  int *vetor = (int *)malloc(TAM_MAX * sizeof(int));
  int qnt_input = pedirVetor(vetor);
  
  int *vetor_insertion = (int *)malloc(qnt_input * sizeof(int));
  int *vetor_selection = (int *)malloc(qnt_input * sizeof(int));
  int *vetor_bubble = (int *)malloc(qnt_input * sizeof(int));

  for (int i = 0; i < qnt_input; i++)
  {
    vetor_insertion[i] = vetor[i];
    vetor_selection[i] = vetor[i];
    vetor_bubble[i] = vetor[i];
  }

  system("cls");
  printf("Vetor ordenado: ");
  insertionSort(vetor, qnt_input, 0);
  printVetor(vetor, qnt_input);
  free(vetor);

  insertionSort(vetor_insertion, qnt_input, 1);
  selectionSort(vetor_selection, qnt_input);
  bubbleSort(vetor_bubble, qnt_input);

  return 0;
}