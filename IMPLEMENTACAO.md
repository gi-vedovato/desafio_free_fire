# IMPLEMENTAÇÃO - Desafio Free Fire Survival Game

## Resumo da Implementação

Este documento descreve a implementação completa do mini-game de sobrevivência desenvolvido em C conforme os requisitos especificados.

## Requisitos Atendidos

### 1. Sistema de Inventário com Structs e Listas Sequenciais ✓

**Implementado em:** `inventory.h` e `inventory.c`

- **Struct Item**: Contém nome, tipo (alimento/arma/ferramenta), quantidade e valor
- **Struct InventoryArray**: Implementação usando lista sequencial (array estático)
  - Capacidade máxima de 20 itens
  - Operações: adicionar, remover, buscar, exibir
- **Enum ItemType**: Define os tipos de itens (FOOD, WEAPON, TOOL)

### 2. Comparação de Listas Encadeadas com Vetores ✓

**Implementado em:** `inventory.c` (funções de lista encadeada) e `game.c` (demonstração interativa)

- **Struct Node**: Nó da lista encadeada com ponteiro para próximo
- **Struct InventoryList**: Implementação com lista encadeada dinâmica
  - Alocação dinâmica de memória
  - Operações: adicionar, remover, buscar, exibir, liberar memória
  
**Demonstração Comparativa** (menu opção 5 durante o jogo):
- Exibe vantagens e desvantagens de cada estrutura
- Mostra exemplos práticos com 3 itens em cada estrutura
- Compara complexidade de operações

### 3. Algoritmos de Busca e Ordenação ✓

**Implementado em:** `inventory.c`

#### Busca Binária (Binary Search)
- Complexidade: O(log n)
- Requer dados ordenados
- Função: `binary_search_array()`
- Implementada para inventário baseado em array

#### Busca Linear
- Complexidade: O(n)
- Para dados não ordenados
- Função: `search_item_array()` e `search_item_list()`

#### Selection Sort
- Complexidade: O(n²)
- Funções: `sort_inventory_array()` e `sort_inventory_list()`
- Ordena itens alfabeticamente por nome
- Implementado para ambas estruturas (array e lista encadeada)

**Demonstração de Algoritmos** (menu opção 4 durante o jogo):
- Mostra inventário antes da ordenação
- Aplica Selection Sort
- Mostra inventário ordenado
- Demonstra busca binária em dados ordenados
- Exibe informações de complexidade

## Estrutura do Jogo (Três Fases)

### Fase 1: Chegada à Ilha
- Introdução narrativa
- Coleta de itens iniciais (faca, frutas, água)
- Inicialização do inventário do jogador

### Fase 2: Sobrevivência e Coleta de Recursos
- Sistema de 3 dias
- Necessidades do jogador (fome e sede diminuem com o tempo)
- Menu interativo com 6 opções:
  1. Procurar recursos (itens aleatórios)
  2. Ver inventário
  3. Usar item (consumir alimentos)
  4. Demonstrar algoritmos (busca e ordenação)
  5. Comparar estruturas de dados
  6. Descansar (avança para próximo dia)

### Fase 3: Fuga da Ilha
- Objetivo: reparar barco para escapar
- Verifica presença de itens necessários
- Conclusão da jornada

## Arquivos Implementados

1. **inventory.h** (1.7 KB)
   - Definições de estruturas
   - Protótipos de funções
   - Constantes do sistema

2. **inventory.c** (7.2 KB)
   - Implementação completa do sistema de inventário
   - Ambas estruturas de dados (array e lista)
   - Todos os algoritmos de busca e ordenação

3. **game.c** (14.3 KB)
   - Lógica principal do jogo
   - Sistema de fases
   - Menu interativo
   - Demonstrações educativas

4. **test_inventory.c** (4.1 KB)
   - Testes unitários completos
   - Testa arrays, listas, ordenação e busca
   - Todos os testes passam com sucesso

5. **Makefile** (691 bytes)
   - Automação de compilação
   - Targets: all, test, clean, run
   - Flags de compilação rigorosas

6. **README.md** (5.8 KB)
   - Documentação completa do projeto
   - Instruções de uso
   - Análise de complexidade
   - Conceitos demonstrados

7. **.gitignore** (237 bytes)
   - Ignora arquivos compilados
   - Ignora executáveis
   - Ignora arquivos temporários

## Qualidade do Código

### Compilação
- Compila sem erros ou warnings
- Flags rigorosas: `-Wall -Wextra -std=c99 -pedantic`
- Compatível com padrão C99

### Boas Práticas
- Separação clara entre interface (.h) e implementação (.c)
- Modularização do código
- Funções com responsabilidade única
- Uso adequado de constantes
- Gerenciamento correto de memória (malloc/free)
- Comentários explicativos

### Testes
- Testes unitários abrangentes
- Cobertura de todas as funcionalidades principais
- Assertions para validação
- Executados automaticamente via `make test`

## Análise de Complexidade

| Operação | Array | Lista Encadeada |
|----------|-------|-----------------|
| Acesso direto | O(1) | O(n) |
| Busca linear | O(n) | O(n) |
| Busca binária | O(log n) | N/A |
| Inserção início | O(n) | O(1) |
| Inserção fim | O(1) | O(n) |
| Remoção | O(n) | O(n) |
| Selection Sort | O(n²) | O(n²) |

## Como Usar

### Compilar
```bash
make
```

### Executar o Jogo
```bash
make run
```

### Executar Testes
```bash
make test
```

### Limpar
```bash
make clean
```

## Conceitos de Programação Demonstrados

1. **Estruturas de Dados**
   - Structs complexos
   - Arrays estáticos
   - Listas encadeadas com alocação dinâmica
   - Enumerações

2. **Algoritmos**
   - Selection Sort (ordenação)
   - Busca binária
   - Busca linear

3. **Gerenciamento de Memória**
   - malloc() e free()
   - Prevenção de memory leaks
   - Ponteiros

4. **Organização de Código**
   - Modularização
   - Headers e implementação separados
   - Makefile para automação

5. **Interatividade**
   - Entrada de usuário
   - Menu interativo
   - Sistema de fases progressivas

## Conclusão

A implementação atende completamente aos requisitos especificados:

✓ Sistema de inventário com structs e listas sequenciais
✓ Comparação prática entre listas encadeadas e vetores  
✓ Implementação de algoritmos de busca (binária e linear)
✓ Implementação de Selection Sort
✓ Aplicação dos conceitos em um mini-game funcional e interativo
✓ Código bem organizado, testado e documentado
✓ Demonstrações educativas integradas ao gameplay

O projeto serve como uma excelente demonstração prática de estruturas de dados e algoritmos fundamentais em C, contextualizada em um jogo de sobrevivência envolvente.
