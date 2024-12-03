# Lista Telefônica com Tabela Hash

## Descrição

Este projeto implementa uma lista telefônica em C utilizando uma **tabela hash** para armazenamento e busca eficiente de contatos. A aplicação suporta operações básicas como adicionar, buscar, remover e listar contatos, além de medir o tempo de execução das operações de inserção e busca.

### Objetivos do Projeto

- Implementar e compreender o funcionamento de uma tabela hash.
- Lidar com colisões utilizando listas encadeadas.
- Demonstrar eficiência no armazenamento e na busca de dados.

---

## Estrutura de Dados

### Tabela Hash

- **Estrutura:** Utiliza uma tabela de tamanho fixo (`TABLE_SIZE = 100`) onde cada índice é associado a uma lista encadeada.
- **Colisões:** Resolvidas através de encadeamento, ou seja, contatos com o mesmo índice são armazenados como nós em uma lista encadeada.

### Nó (`HashNode`)

Cada nó armazena:

- O nome do contato (`nome`).
- O número de telefone (`telefone`).
- Um ponteiro para o próximo nó (`next`), em caso de colisão.

---

## Funcionalidades

### 1. Adicionar Contato

Permite ao usuário inserir um novo contato (nome e telefone). Caso o nome já exista, um novo telefone será associado a ele como um nó adicional na lista encadeada. O tempo de execução da operação é exibido.

**void adicionarContato()**

### 2. Buscar Contato

Permite buscar todos os telefones associados a um nome. Caso o nome não seja encontrado, uma mensagem de erro será exibida. O tempo de execução da busca também é exibido.

**void buscarContato()**

### 3. Remover Contato

Permite remover todos os telefones associados a um nome. O nó correspondente é desalocado da memória. Se o contato não for encontrado, uma mensagem de erro é exibida.

**void removerContato()**

### 4. Exibir Todos os Contatos

Exibe todos os contatos armazenados na tabela hash. A saída inclui o nome e todos os telefones associados a ele.

**void exibirContatos()**

Estratégias de Hash e Lidar com Colisões
Função Hash
A função hash converte uma string (nome) em um índice numérico:

unsigned int hash(const char \*key)

A fórmula utilizada combina deslocamentos binários para distribuir uniformemente os dados.

### Colisões

As colisões são tratadas utilizando listas encadeadas. Contatos com o mesmo índice na tabela hash são armazenados como nós em uma lista vinculada.

### Medição de Desempenho

O tempo de execução das operações de inserção e busca é calculado usando a biblioteca time.h:

**clock_t start = clock();**
**clock_t end = clock();**

O tempo é exibido em milissegundos para permitir análise de eficiência.

### Tratamento de Erros

**Contato não encontrado:** Exibe uma mensagem ao tentar buscar ou remover um contato inexistente.
**Duplicidade de nomes:** Permite múltiplos telefones associados ao mesmo nome.

### Desenvolvido por:

Maria Eduarda Muncinelli
Disciplina: Estrutura de Dados - Tabela Hash
Professor Lucas José de Souza
