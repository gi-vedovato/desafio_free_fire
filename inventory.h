#ifndef INVENTORY_H
#define INVENTORY_H

#define MAX_INVENTORY_SIZE 20
#define MAX_NAME_LENGTH 50

// Enum para tipos de itens
typedef enum {
    FOOD,
    WEAPON,
    TOOL
} ItemType;

// Struct para representar um item
typedef struct {
    char name[MAX_NAME_LENGTH];
    ItemType type;
    int quantity;
    int value; // Valor/utilidade do item
} Item;

// Struct para inventário usando lista sequencial (array)
typedef struct {
    Item items[MAX_INVENTORY_SIZE];
    int size;
} InventoryArray;

// Struct para nó da lista encadeada
typedef struct Node {
    Item item;
    struct Node* next;
} Node;

// Struct para inventário usando lista encadeada
typedef struct {
    Node* head;
    int size;
} InventoryList;

// Funções para inventário com array
void init_inventory_array(InventoryArray* inv);
int add_item_array(InventoryArray* inv, Item item);
int remove_item_array(InventoryArray* inv, const char* name);
Item* search_item_array(InventoryArray* inv, const char* name);
void display_inventory_array(InventoryArray* inv);
void sort_inventory_array(InventoryArray* inv);
Item* binary_search_array(InventoryArray* inv, const char* name);

// Funções para inventário com lista encadeada
void init_inventory_list(InventoryList* inv);
int add_item_list(InventoryList* inv, Item item);
int remove_item_list(InventoryList* inv, const char* name);
Item* search_item_list(InventoryList* inv, const char* name);
void display_inventory_list(InventoryList* inv);
void free_inventory_list(InventoryList* inv);
void sort_inventory_list(InventoryList* inv);

// Funções auxiliares
Item create_item(const char* name, ItemType type, int quantity, int value);
const char* get_item_type_name(ItemType type);

#endif
