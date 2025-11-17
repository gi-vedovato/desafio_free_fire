#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inventory.h"

// Funções auxiliares
Item create_item(const char* name, ItemType type, int quantity, int value) {
    Item item;
    strncpy(item.name, name, MAX_NAME_LENGTH - 1);
    item.name[MAX_NAME_LENGTH - 1] = '\0';
    item.type = type;
    item.quantity = quantity;
    item.value = value;
    return item;
}

const char* get_item_type_name(ItemType type) {
    switch(type) {
        case FOOD: return "Alimento";
        case WEAPON: return "Arma";
        case TOOL: return "Ferramenta";
        default: return "Desconhecido";
    }
}

// ===== IMPLEMENTAÇÃO COM ARRAY (LISTA SEQUENCIAL) =====

void init_inventory_array(InventoryArray* inv) {
    inv->size = 0;
}

int add_item_array(InventoryArray* inv, Item item) {
    if (inv->size >= MAX_INVENTORY_SIZE) {
        printf("Inventário cheio! Não é possível adicionar mais itens.\n");
        return 0;
    }
    
    // Verifica se o item já existe
    for (int i = 0; i < inv->size; i++) {
        if (strcmp(inv->items[i].name, item.name) == 0) {
            inv->items[i].quantity += item.quantity;
            return 1;
        }
    }
    
    // Adiciona novo item
    inv->items[inv->size] = item;
    inv->size++;
    return 1;
}

int remove_item_array(InventoryArray* inv, const char* name) {
    for (int i = 0; i < inv->size; i++) {
        if (strcmp(inv->items[i].name, name) == 0) {
            // Move todos os elementos após este para trás
            for (int j = i; j < inv->size - 1; j++) {
                inv->items[j] = inv->items[j + 1];
            }
            inv->size--;
            return 1;
        }
    }
    return 0;
}

Item* search_item_array(InventoryArray* inv, const char* name) {
    for (int i = 0; i < inv->size; i++) {
        if (strcmp(inv->items[i].name, name) == 0) {
            return &inv->items[i];
        }
    }
    return NULL;
}

void display_inventory_array(InventoryArray* inv) {
    if (inv->size == 0) {
        printf("Inventário vazio.\n");
        return;
    }
    
    printf("\n=== INVENTÁRIO (Array) ===\n");
    printf("%-25s %-15s %-10s %-10s\n", "Item", "Tipo", "Quantidade", "Valor");
    printf("----------------------------------------------------------------\n");
    for (int i = 0; i < inv->size; i++) {
        printf("%-25s %-15s %-10d %-10d\n", 
               inv->items[i].name,
               get_item_type_name(inv->items[i].type),
               inv->items[i].quantity,
               inv->items[i].value);
    }
    printf("Total de itens: %d/%d\n\n", inv->size, MAX_INVENTORY_SIZE);
}

// Selection Sort para ordenar por nome
void sort_inventory_array(InventoryArray* inv) {
    for (int i = 0; i < inv->size - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < inv->size; j++) {
            if (strcmp(inv->items[j].name, inv->items[min_idx].name) < 0) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            Item temp = inv->items[i];
            inv->items[i] = inv->items[min_idx];
            inv->items[min_idx] = temp;
        }
    }
}

// Busca binária (requer inventário ordenado)
Item* binary_search_array(InventoryArray* inv, const char* name) {
    int left = 0;
    int right = inv->size - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        int cmp = strcmp(inv->items[mid].name, name);
        
        if (cmp == 0) {
            return &inv->items[mid];
        } else if (cmp < 0) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return NULL;
}

// ===== IMPLEMENTAÇÃO COM LISTA ENCADEADA =====

void init_inventory_list(InventoryList* inv) {
    inv->head = NULL;
    inv->size = 0;
}

int add_item_list(InventoryList* inv, Item item) {
    // Verifica se o item já existe
    Node* current = inv->head;
    while (current != NULL) {
        if (strcmp(current->item.name, item.name) == 0) {
            current->item.quantity += item.quantity;
            return 1;
        }
        current = current->next;
    }
    
    // Cria novo nó
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Erro ao alocar memória.\n");
        return 0;
    }
    
    new_node->item = item;
    new_node->next = inv->head;
    inv->head = new_node;
    inv->size++;
    return 1;
}

int remove_item_list(InventoryList* inv, const char* name) {
    if (inv->head == NULL) {
        return 0;
    }
    
    // Se o primeiro item é o procurado
    if (strcmp(inv->head->item.name, name) == 0) {
        Node* temp = inv->head;
        inv->head = inv->head->next;
        free(temp);
        inv->size--;
        return 1;
    }
    
    // Procura nos demais nós
    Node* current = inv->head;
    while (current->next != NULL) {
        if (strcmp(current->next->item.name, name) == 0) {
            Node* temp = current->next;
            current->next = current->next->next;
            free(temp);
            inv->size--;
            return 1;
        }
        current = current->next;
    }
    return 0;
}

Item* search_item_list(InventoryList* inv, const char* name) {
    Node* current = inv->head;
    while (current != NULL) {
        if (strcmp(current->item.name, name) == 0) {
            return &current->item;
        }
        current = current->next;
    }
    return NULL;
}

void display_inventory_list(InventoryList* inv) {
    if (inv->head == NULL) {
        printf("Inventário vazio.\n");
        return;
    }
    
    printf("\n=== INVENTÁRIO (Lista Encadeada) ===\n");
    printf("%-25s %-15s %-10s %-10s\n", "Item", "Tipo", "Quantidade", "Valor");
    printf("----------------------------------------------------------------\n");
    
    Node* current = inv->head;
    while (current != NULL) {
        printf("%-25s %-15s %-10d %-10d\n", 
               current->item.name,
               get_item_type_name(current->item.type),
               current->item.quantity,
               current->item.value);
        current = current->next;
    }
    printf("Total de itens: %d\n\n", inv->size);
}

void free_inventory_list(InventoryList* inv) {
    Node* current = inv->head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    inv->head = NULL;
    inv->size = 0;
}

// Selection Sort para lista encadeada
void sort_inventory_list(InventoryList* inv) {
    if (inv->head == NULL || inv->head->next == NULL) {
        return;
    }
    
    Node* current = inv->head;
    while (current != NULL) {
        Node* min_node = current;
        Node* search = current->next;
        
        while (search != NULL) {
            if (strcmp(search->item.name, min_node->item.name) < 0) {
                min_node = search;
            }
            search = search->next;
        }
        
        if (min_node != current) {
            // Troca os itens
            Item temp = current->item;
            current->item = min_node->item;
            min_node->item = temp;
        }
        
        current = current->next;
    }
}
