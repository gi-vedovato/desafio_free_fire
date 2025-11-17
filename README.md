# Free Fire Survival Game - Desafio em C

Um mini-game de sobrevivência desenvolvido em C que simula a experiência de estar preso em uma ilha hostil. O jogo implementa estruturas de dados avançadas, algoritmos de busca e ordenação, demonstrando conceitos importantes de programação.

## 📋 Descrição do Projeto

O jogador acorda em uma ilha desconhecida após um acidente e deve sobreviver coletando recursos, gerenciando seu inventário e, eventualmente, escapar da ilha. O projeto está dividido em três fases progressivas:

### Fase 1: Chegada à Ilha
- Introdução ao cenário
- Coleta inicial de recursos básicos
- Primeiros itens no inventário

### Fase 2: Sobrevivência e Coleta de Recursos
- Sistema de dias com necessidades (fome e sede)
- Exploração e coleta de recursos
- Gerenciamento de inventário
- Demonstrações de algoritmos

### Fase 3: Fuga da Ilha
- Objetivo final: reparar um barco
- Verificação de itens necessários
- Conclusão da jornada

## 🎯 Funcionalidades Implementadas

### 1. Sistema de Inventário com Structs
- **Estrutura de Item**: Contém nome, tipo (alimento/arma/ferramenta), quantidade e valor
- **Inventário com Array (Lista Sequencial)**: Implementação usando array estático com tamanho máximo
- **Inventário com Lista Encadeada**: Implementação dinâmica usando alocação de memória

### 2. Comparação de Estruturas de Dados
O jogo inclui uma demonstração interativa comparando:
- **Arrays (Listas Sequenciais)**
  - Acesso direto O(1)
  - Tamanho fixo
  - Melhor localidade de cache
- **Listas Encadeadas**
  - Tamanho dinâmico
  - Inserção/remoção eficiente no início O(1)
  - Overhead de ponteiros

### 3. Algoritmos de Busca e Ordenação

#### Selection Sort
Implementado para ordenar itens por nome (ordem alfabética):
- Complexidade: O(n²)
- Implementado tanto para arrays quanto listas encadeadas

#### Busca Binária
Busca eficiente em dados ordenados:
- Complexidade: O(log n)
- Requer inventário previamente ordenado

#### Busca Linear
Busca simples percorrendo todos elementos:
- Complexidade: O(n)
- Usada para busca em dados não ordenados

## 🛠️ Compilação e Execução

### Requisitos
- GCC (GNU Compiler Collection)
- Make
- Sistema Linux/Unix ou Windows com MinGW

### Compilar o Projeto
```bash
make
```

### Executar o Jogo
```bash
make run
```

Ou diretamente:
```bash
./free_fire_game
```

### Limpar Arquivos Compilados
```bash
make clean
```

## 📁 Estrutura do Projeto

```
desafio_free_fire/
├── README.md           # Documentação do projeto
├── Makefile           # Automação de compilação
├── inventory.h        # Definições de estruturas e funções de inventário
├── inventory.c        # Implementação do sistema de inventário
└── game.c             # Lógica principal do jogo
```

## 🎮 Como Jogar

1. **Inicie o jogo** e digite o nome do seu personagem
2. **Fase 1**: Leia a introdução e colete os itens iniciais
3. **Fase 2**: Durante 3 dias, você pode:
   - Procurar recursos na ilha
   - Ver seu inventário
   - Usar itens (alimentos restauram fome e sede)
   - Ver demonstrações de algoritmos
   - Comparar estruturas de dados
4. **Fase 3**: Reúna os itens necessários e escape da ilha!

## 💡 Conceitos de Programação Demonstrados

### Estruturas de Dados
- `struct` para representar entidades (Item, Player, Node)
- Arrays estáticos
- Listas encadeadas com alocação dinâmica
- Enumerações (enum) para tipos de itens

### Algoritmos
- **Selection Sort**: Ordenação por seleção
- **Busca Binária**: Busca eficiente em dados ordenados
- **Busca Linear**: Busca sequencial simples

### Gerenciamento de Memória
- `malloc()` para alocação dinâmica
- `free()` para liberação de memória
- Prevenção de memory leaks

### Boas Práticas
- Separação de interface (.h) e implementação (.c)
- Modularização do código
- Uso de constantes (#define)
- Funções com responsabilidade única
- Comentários explicativos

## 🔍 Análise de Complexidade

| Operação | Array | Lista Encadeada |
|----------|-------|-----------------|
| Acesso por índice | O(1) | O(n) |
| Busca | O(n) linear, O(log n) binária | O(n) |
| Inserção no início | O(n) | O(1) |
| Inserção no fim | O(1) | O(n) |
| Remoção | O(n) | O(n) |
| Ordenação (Selection) | O(n²) | O(n²) |

## 📚 Aprendizados

Este projeto demonstra:
1. **Implementação prática de structs** para modelar entidades do jogo
2. **Comparação hands-on** entre arrays e listas encadeadas
3. **Algoritmos fundamentais** de busca e ordenação
4. **Selection Sort** como algoritmo de ordenação quadrático
5. **Busca binária** para otimização de buscas em dados ordenados
6. **Gerenciamento de memória** em C
7. **Organização de código** em módulos

## 🚀 Possíveis Extensões

- Adicionar mais tipos de itens e recursos
- Implementar sistema de combate
- Adicionar mais algoritmos (Quick Sort, Merge Sort)
- Sistema de save/load
- Múltiplos finais baseados nas escolhas
- Interface gráfica com ncurses
- Comparação de desempenho entre estruturas

## 👨‍💻 Desenvolvimento

Projeto desenvolvido como desafio de programação em C, focando em:
- Estruturas de dados fundamentais
- Algoritmos clássicos
- Boas práticas de programação
- Documentação de código

## 📝 Licença

Este projeto é livre para uso educacional.