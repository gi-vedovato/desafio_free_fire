#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "inventory.h"

// Estrutura do jogador
typedef struct {
    char name[50];
    int health;
    int hunger;
    int thirst;
    InventoryArray inventory;
} Player;

// Protótipos de funções
void init_player(Player* player, const char* name);
void display_player_status(Player* player);
void phase_1_arrival(Player* player);
void phase_2_survival(Player* player);
void phase_3_escape(Player* player);
void gather_resources(Player* player);
void use_item(Player* player);
void compare_data_structures();
void demonstrate_algorithms();
void clear_input_buffer();
int get_menu_choice(int min, int max);

int main() {
    Player player;
    char player_name[50];
    
    srand(time(NULL));
    
    printf("===========================================\n");
    printf("   BEM-VINDO AO FREE FIRE SURVIVAL GAME   \n");
    printf("===========================================\n\n");
    
    printf("Digite o nome do seu personagem: ");
    fgets(player_name, sizeof(player_name), stdin);
    player_name[strcspn(player_name, "\n")] = 0;
    
    init_player(&player, player_name);
    
    printf("\nJogo iniciado! Boa sorte, %s!\n\n", player.name);
    
    // FASE 1: Chegada à ilha
    phase_1_arrival(&player);
    
    // FASE 2: Sobrevivência e coleta de recursos
    phase_2_survival(&player);
    
    // FASE 3: Fuga da ilha
    phase_3_escape(&player);
    
    printf("\n===========================================\n");
    printf("         FIM DO JOGO - VOCÊ VENCEU!        \n");
    printf("===========================================\n");
    printf("\nParabéns %s! Você conseguiu sobreviver e escapar da ilha!\n", player.name);
    printf("Estatísticas finais:\n");
    display_player_status(&player);
    
    return 0;
}

void init_player(Player* player, const char* name) {
    strncpy(player->name, name, 49);
    player->name[49] = '\0';
    player->health = 100;
    player->hunger = 100;
    player->thirst = 100;
    init_inventory_array(&player->inventory);
}

void display_player_status(Player* player) {
    printf("\n--- STATUS DO JOGADOR ---\n");
    printf("Nome: %s\n", player->name);
    printf("Saúde: %d%%\n", player->health);
    printf("Fome: %d%%\n", player->hunger);
    printf("Sede: %d%%\n", player->thirst);
}

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int get_menu_choice(int min, int max) {
    int choice;
    while (1) {
        printf("Escolha uma opção (%d-%d): ", min, max);
        if (scanf("%d", &choice) == 1 && choice >= min && choice <= max) {
            clear_input_buffer();
            return choice;
        }
        clear_input_buffer();
        printf("Opção inválida! Tente novamente.\n");
    }
}

void phase_1_arrival(Player* player) {
    printf("\n╔════════════════════════════════════════════════════════╗\n");
    printf("║           FASE 1: CHEGADA À ILHA HOSTIL              ║\n");
    printf("╚════════════════════════════════════════════════════════╝\n\n");
    
    printf("Você acorda em uma praia desconhecida após um acidente de avião.\n");
    printf("A ilha parece deserta, mas você ouve sons estranhos ao longe...\n\n");
    
    printf("Você encontra alguns itens espalhados pela praia:\n");
    printf("- Uma faca enferrujada\n");
    printf("- Algumas frutas\n");
    printf("- Uma garrafa de água\n\n");
    
    // Adiciona itens iniciais
    add_item_array(&player->inventory, create_item("Faca Enferrujada", WEAPON, 1, 5));
    add_item_array(&player->inventory, create_item("Frutas Tropicais", FOOD, 3, 3));
    add_item_array(&player->inventory, create_item("Garrafa de Água", FOOD, 1, 5));
    
    printf("Itens adicionados ao inventário!\n");
    display_inventory_array(&player->inventory);
    
    printf("Pressione ENTER para continuar...");
    getchar();
}

void phase_2_survival(Player* player) {
    printf("\n╔════════════════════════════════════════════════════════╗\n");
    printf("║      FASE 2: SOBREVIVÊNCIA E COLETA DE RECURSOS       ║\n");
    printf("╚════════════════════════════════════════════════════════╝\n\n");
    
    printf("Agora você precisa explorar a ilha e coletar recursos para sobreviver.\n\n");
    
    int days = 0;
    while (days < 3) {
        days++;
        printf("\n========== DIA %d ==========\n", days);
        
        // Diminui fome e sede
        player->hunger -= 10;
        player->thirst -= 15;
        
        if (player->hunger < 0) player->hunger = 0;
        if (player->thirst < 0) player->thirst = 0;
        
        display_player_status(player);
        
        printf("\nO que você deseja fazer?\n");
        printf("1. Procurar recursos\n");
        printf("2. Ver inventário\n");
        printf("3. Usar item\n");
        printf("4. Demonstrar algoritmos (busca e ordenação)\n");
        printf("5. Comparar estruturas de dados\n");
        printf("6. Descansar (avança para o próximo dia)\n");
        
        int choice = get_menu_choice(1, 6);
        
        switch(choice) {
            case 1:
                gather_resources(player);
                break;
            case 2:
                display_inventory_array(&player->inventory);
                break;
            case 3:
                use_item(player);
                break;
            case 4:
                demonstrate_algorithms();
                break;
            case 5:
                compare_data_structures();
                break;
            case 6:
                printf("\nVocê descansa e recupera energia...\n");
                break;
        }
    }
    
    printf("\n\nVocê sobreviveu aos primeiros dias na ilha!\n");
    printf("Pressione ENTER para continuar...");
    clear_input_buffer();
    getchar();
}

void gather_resources(Player* player) {
    printf("\nVocê explora a ilha em busca de recursos...\n");
    
    int found = rand() % 5;
    
    switch(found) {
        case 0:
            printf("Você encontrou uma fogueira improvisada!\n");
            add_item_array(&player->inventory, create_item("Kit de Fogueira", TOOL, 1, 8));
            break;
        case 1:
            printf("Você encontrou um estoque de água limpa!\n");
            add_item_array(&player->inventory, create_item("Água Limpa", FOOD, 2, 7));
            break;
        case 2:
            printf("Você encontrou frutas comestíveis!\n");
            add_item_array(&player->inventory, create_item("Frutas Tropicais", FOOD, 2, 3));
            break;
        case 3:
            printf("Você encontrou uma arma improvisada!\n");
            add_item_array(&player->inventory, create_item("Lança de Madeira", WEAPON, 1, 6));
            break;
        case 4:
            printf("Você encontrou uma corda!\n");
            add_item_array(&player->inventory, create_item("Corda Resistente", TOOL, 1, 5));
            break;
    }
}

void use_item(Player* player) {
    printf("\n=== USAR ITEM ===\n");
    display_inventory_array(&player->inventory);
    
    if (player->inventory.size == 0) {
        return;
    }
    
    printf("\nDigite o nome do item que deseja usar: ");
    char item_name[MAX_NAME_LENGTH];
    fgets(item_name, sizeof(item_name), stdin);
    item_name[strcspn(item_name, "\n")] = 0;
    
    Item* item = search_item_array(&player->inventory, item_name);
    
    if (item == NULL) {
        printf("Item não encontrado no inventário!\n");
        return;
    }
    
    if (item->type == FOOD) {
        printf("Você consumiu %s!\n", item->name);
        player->hunger += 20;
        player->thirst += 15;
        if (player->hunger > 100) player->hunger = 100;
        if (player->thirst > 100) player->thirst = 100;
        
        item->quantity--;
        if (item->quantity <= 0) {
            remove_item_array(&player->inventory, item_name);
        }
        printf("Fome e sede restauradas!\n");
    } else {
        printf("Este item não pode ser consumido!\n");
    }
}

void phase_3_escape(Player* player) {
    printf("\n╔════════════════════════════════════════════════════════╗\n");
    printf("║           FASE 3: FUGA DA ILHA                        ║\n");
    printf("╚════════════════════════════════════════════════════════╝\n\n");
    
    printf("Você avista um barco abandonado na costa!\n");
    printf("Porém, ele precisa de alguns itens para ser reparado:\n");
    printf("- Corda Resistente\n");
    printf("- Ferramenta de corte (faca ou machado)\n\n");
    
    int has_rope = 0;
    int has_tool = 0;
    
    // Verifica se o jogador tem os itens necessários
    if (search_item_array(&player->inventory, "Corda Resistente") != NULL) {
        has_rope = 1;
        printf("✓ Você tem uma corda!\n");
    } else {
        printf("✗ Você precisa de uma corda!\n");
    }
    
    if (search_item_array(&player->inventory, "Faca Enferrujada") != NULL ||
        search_item_array(&player->inventory, "Machado") != NULL) {
        has_tool = 1;
        printf("✓ Você tem uma ferramenta de corte!\n");
    } else {
        printf("✗ Você precisa de uma ferramenta de corte!\n");
    }
    
    if (!has_rope || !has_tool) {
        printf("\nVocê não tem todos os itens necessários, mas decide improvisar...\n");
        add_item_array(&player->inventory, create_item("Corda Resistente", TOOL, 1, 5));
        printf("Por sorte, você encontrou uma corda próxima ao barco!\n");
    }
    
    printf("\nVocê conserta o barco e está pronto para partir!\n");
    printf("Após dias difíceis, você finalmente consegue escapar da ilha hostil.\n");
}

void compare_data_structures() {
    printf("\n╔════════════════════════════════════════════════════════╗\n");
    printf("║    COMPARAÇÃO: LISTA ENCADEADA vs ARRAY               ║\n");
    printf("╚════════════════════════════════════════════════════════╝\n\n");
    
    printf("ARRAY (Lista Sequencial):\n");
    printf("  + Acesso direto O(1) por índice\n");
    printf("  + Melhor localidade de cache\n");
    printf("  + Menos overhead de memória\n");
    printf("  - Tamanho fixo (limitado)\n");
    printf("  - Inserção/remoção no meio é O(n)\n\n");
    
    printf("LISTA ENCADEADA:\n");
    printf("  + Tamanho dinâmico\n");
    printf("  + Inserção/remoção no início é O(1)\n");
    printf("  + Não precisa realocar ao crescer\n");
    printf("  - Acesso sequencial O(n)\n");
    printf("  - Overhead de ponteiros\n");
    printf("  - Pior localidade de cache\n\n");
    
    // Demonstração prática
    printf("Demonstração prática:\n\n");
    
    InventoryArray inv_array;
    InventoryList inv_list;
    
    init_inventory_array(&inv_array);
    init_inventory_list(&inv_list);
    
    // Adiciona itens
    Item items[] = {
        create_item("Espada", WEAPON, 1, 10),
        create_item("Escudo", TOOL, 1, 8),
        create_item("Poção", FOOD, 3, 5)
    };
    
    printf("Adicionando 3 itens em ambas estruturas...\n");
    for (int i = 0; i < 3; i++) {
        add_item_array(&inv_array, items[i]);
        add_item_list(&inv_list, items[i]);
    }
    
    display_inventory_array(&inv_array);
    display_inventory_list(&inv_list);
    
    free_inventory_list(&inv_list);
    
    printf("Pressione ENTER para continuar...");
    getchar();
}

void demonstrate_algorithms() {
    printf("\n╔════════════════════════════════════════════════════════╗\n");
    printf("║       DEMONSTRAÇÃO: BUSCA E ORDENAÇÃO                 ║\n");
    printf("╚════════════════════════════════════════════════════════╝\n\n");
    
    InventoryArray inv;
    init_inventory_array(&inv);
    
    // Adiciona itens desordenados
    add_item_array(&inv, create_item("Zebra Item", TOOL, 1, 5));
    add_item_array(&inv, create_item("Apple Item", FOOD, 1, 3));
    add_item_array(&inv, create_item("Machado", WEAPON, 1, 8));
    add_item_array(&inv, create_item("Banana", FOOD, 2, 2));
    add_item_array(&inv, create_item("Espada", WEAPON, 1, 10));
    
    printf("Inventário ANTES da ordenação:\n");
    display_inventory_array(&inv);
    
    printf("\nAplicando Selection Sort...\n");
    sort_inventory_array(&inv);
    
    printf("\nInventário DEPOIS da ordenação (alfabética):\n");
    display_inventory_array(&inv);
    
    printf("\n--- BUSCA BINÁRIA ---\n");
    printf("Procurando por 'Machado' usando busca binária...\n");
    
    Item* found = binary_search_array(&inv, "Machado");
    if (found != NULL) {
        printf("✓ Item encontrado!\n");
        printf("  Nome: %s\n", found->name);
        printf("  Tipo: %s\n", get_item_type_name(found->type));
        printf("  Quantidade: %d\n", found->quantity);
        printf("  Valor: %d\n", found->value);
    } else {
        printf("✗ Item não encontrado.\n");
    }
    
    printf("\nComplexidade dos algoritmos:\n");
    printf("- Selection Sort: O(n²)\n");
    printf("- Busca Binária: O(log n) - requer dados ordenados\n");
    printf("- Busca Linear: O(n)\n");
    
    printf("\nPressione ENTER para continuar...");
    getchar();
}
