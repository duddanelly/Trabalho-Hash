// Estrutura programa Tabela Hash - Professor Lucas.
// Trabalho feito por: Maria Eduarda Muncinelli
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TABLE_SIZE 100

// estrutura do nó
typedef struct HashNode
{
  char *nome;
  char *telefone;
  struct HashNode *next;
} HashNode;

typedef struct HashTable
{
  HashNode *buckets[TABLE_SIZE];
} HashTable;

HashTable *table;

unsigned int hash(const char *key)
{
  unsigned int hash_value = 0;
  while (*key)
  {
    hash_value = (hash_value << 5) + *key++;
  }
  return hash_value % TABLE_SIZE;
}

void inicializarTabela()
{
  table = (HashTable *)malloc(sizeof(HashTable));
  for (int i = 0; i < TABLE_SIZE; i++)
  {
    table->buckets[i] = NULL;
  }
}

void adicionarContato()
{
  char nome[50], telefone[15];
  printf("Digite o nome: ");
  scanf("%s", nome);
  printf("Digite o telefone: ");
  scanf("%s", telefone);

  clock_t start = clock();

  unsigned int index = hash(nome);
  HashNode *node = table->buckets[index];

  // Verifica se o nome já existe
  while (node)
  {
    if (strcmp(node->nome, nome) == 0)
    {
      // Adiciona o novo telefone como um novo nó
      HashNode *new_node = (HashNode *)malloc(sizeof(HashNode));
      new_node->nome = strdup(nome);
      new_node->telefone = strdup(telefone);
      new_node->next = table->buckets[index];
      table->buckets[index] = new_node;

      clock_t end = clock();
      printf("Novo telefone adicionado para o contato '%s'! (tempo de adição: %.5f ms)\n",
             nome, ((double)(end - start) / CLOCKS_PER_SEC) * 1000);
      return;
    }
    node = node->next;
  }

  // Caso o nome não exista, cria um novo contato
  HashNode *new_node = (HashNode *)malloc(sizeof(HashNode));
  new_node->nome = strdup(nome);
  new_node->telefone = strdup(telefone);
  new_node->next = table->buckets[index];
  table->buckets[index] = new_node;

  clock_t end = clock();
  printf("Contato '%s' adicionado com sucesso! (tempo de adição: %.5f ms)\n",
         nome, ((double)(end - start) / CLOCKS_PER_SEC) * 1000);
}

void buscarContato()
{
  char nome[50];
  printf("Digite o nome para buscar: ");
  scanf("%s", nome);

  clock_t start = clock();

  unsigned int index = hash(nome);
  HashNode *node = table->buckets[index];
  int found = 0;

  printf("Telefones associados a '%s':\n", nome);
  while (node)
  {
    if (strcmp(node->nome, nome) == 0)
    {
      printf("- %s\n", node->telefone);
      found = 1;
    }
    node = node->next;
  }

  clock_t end = clock();
  if (!found)
  {
    printf("Contato não encontrado.\n");
  }
  printf("Tempo de busca: %.5f ms\n", ((double)(end - start) / CLOCKS_PER_SEC) * 1000);
}

void removerContato()
{
  char nome[50];
  printf("Digite o nome para remover: ");
  scanf("%s", nome);

  unsigned int index = hash(nome);
  HashNode *node = table->buckets[index];
  HashNode *prev = NULL;

  while (node)
  {
    if (strcmp(node->nome, nome) == 0)
    {
      if (prev)
      {
        prev->next = node->next;
      }
      else
      {
        table->buckets[index] = node->next;
      }
      free(node->nome);
      free(node->telefone);
      free(node);
      printf("Contato removido com sucesso!\n");
      return;
    }
    prev = node;
    node = node->next;
  }
  printf("Contato não encontrado.\n");
}

void exibirContatos()
{
  printf("\n------ Lista de Contatos ------\n");
  for (int i = 0; i < TABLE_SIZE; i++)
  {
    HashNode *node = table->buckets[i];
    while (node)
    {
      printf("Nome: %s, Telefone: %s\n", node->nome, node->telefone);
      node = node->next;
    }
  }
}

void liberarTabela()
{
  for (int i = 0; i < TABLE_SIZE; i++)
  {
    HashNode *node = table->buckets[i];
    while (node)
    {
      HashNode *temp = node;
      node = node->next;
      free(temp->nome);
      free(temp->telefone);
      free(temp);
    }
  }
  free(table);
}

int main()
{
  int opcao;
  inicializarTabela();

  do
  {
    printf("\nEscolha uma opcao:\n");
    printf("1 - Adicionar contato\n");
    printf("2 - Buscar contato por nome\n");
    printf("3 - Remover contato\n");
    printf("4 - Exibir todos os contatos\n");
    printf("0 - Sair\n");
    printf("Digite uma opcao: ");

    scanf("%d", &opcao);

    switch (opcao)
    {
    case 1:
      adicionarContato();
      break;
    case 2:
      buscarContato();
      break;
    case 3:
      removerContato();
      break;
    case 4:
      exibirContatos();
      break;
    case 0:
      printf("Saindo...\n");
      break;
    default:
      printf("Opcao invalida! Tente novamente.\n");
    }
  } while (opcao != 0);

  liberarTabela();
  return 0;
}
