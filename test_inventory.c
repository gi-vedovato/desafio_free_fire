#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "inventory.h"

void test_array_inventory() {
    printf("Testing Array Inventory...\n");
    
    InventoryArray inv;
    init_inventory_array(&inv);
    assert(inv.size == 0);
    
    // Test adding items
    Item item1 = create_item("Sword", WEAPON, 1, 10);
    assert(add_item_array(&inv, item1) == 1);
    assert(inv.size == 1);
    
    // Test adding duplicate (should increase quantity)
    Item item2 = create_item("Sword", WEAPON, 1, 10);
    assert(add_item_array(&inv, item2) == 1);
    assert(inv.size == 1); // Still 1 item type
    assert(inv.items[0].quantity == 2); // But quantity increased
    
    // Test searching
    Item* found = search_item_array(&inv, "Sword");
    assert(found != NULL);
    assert(strcmp(found->name, "Sword") == 0);
    assert(found->quantity == 2);
    
    // Test removing
    assert(remove_item_array(&inv, "Sword") == 1);
    assert(inv.size == 0);
    
    printf("✓ Array Inventory tests passed!\n\n");
}

void test_linked_list_inventory() {
    printf("Testing Linked List Inventory...\n");
    
    InventoryList inv;
    init_inventory_list(&inv);
    assert(inv.size == 0);
    assert(inv.head == NULL);
    
    // Test adding items
    Item item1 = create_item("Potion", FOOD, 3, 5);
    assert(add_item_list(&inv, item1) == 1);
    assert(inv.size == 1);
    assert(inv.head != NULL);
    
    // Test adding another item
    Item item2 = create_item("Shield", TOOL, 1, 8);
    assert(add_item_list(&inv, item2) == 1);
    assert(inv.size == 2);
    
    // Test searching
    Item* found = search_item_list(&inv, "Potion");
    assert(found != NULL);
    assert(strcmp(found->name, "Potion") == 0);
    assert(found->quantity == 3);
    
    // Test removing
    assert(remove_item_list(&inv, "Potion") == 1);
    assert(inv.size == 1);
    
    // Clean up
    free_inventory_list(&inv);
    assert(inv.head == NULL);
    assert(inv.size == 0);
    
    printf("✓ Linked List Inventory tests passed!\n\n");
}

void test_sorting() {
    printf("Testing Selection Sort...\n");
    
    InventoryArray inv;
    init_inventory_array(&inv);
    
    // Add items in random order
    add_item_array(&inv, create_item("Zebra", TOOL, 1, 5));
    add_item_array(&inv, create_item("Apple", FOOD, 1, 3));
    add_item_array(&inv, create_item("Mango", FOOD, 1, 2));
    add_item_array(&inv, create_item("Banana", FOOD, 1, 2));
    
    sort_inventory_array(&inv);
    
    // Check if sorted alphabetically
    assert(strcmp(inv.items[0].name, "Apple") == 0);
    assert(strcmp(inv.items[1].name, "Banana") == 0);
    assert(strcmp(inv.items[2].name, "Mango") == 0);
    assert(strcmp(inv.items[3].name, "Zebra") == 0);
    
    printf("✓ Selection Sort tests passed!\n\n");
}

void test_binary_search() {
    printf("Testing Binary Search...\n");
    
    InventoryArray inv;
    init_inventory_array(&inv);
    
    // Add items and sort
    add_item_array(&inv, create_item("Delta", TOOL, 1, 5));
    add_item_array(&inv, create_item("Alpha", FOOD, 1, 3));
    add_item_array(&inv, create_item("Charlie", WEAPON, 1, 8));
    add_item_array(&inv, create_item("Bravo", FOOD, 1, 2));
    
    sort_inventory_array(&inv);
    
    // Test successful search
    Item* found = binary_search_array(&inv, "Charlie");
    assert(found != NULL);
    assert(strcmp(found->name, "Charlie") == 0);
    
    // Test unsuccessful search
    Item* not_found = binary_search_array(&inv, "Zulu");
    assert(not_found == NULL);
    
    printf("✓ Binary Search tests passed!\n\n");
}

int main() {
    printf("===========================================\n");
    printf("   RUNNING UNIT TESTS FOR INVENTORY SYSTEM\n");
    printf("===========================================\n\n");
    
    test_array_inventory();
    test_linked_list_inventory();
    test_sorting();
    test_binary_search();
    
    printf("===========================================\n");
    printf("   ALL TESTS PASSED SUCCESSFULLY! ✓\n");
    printf("===========================================\n");
    
    return 0;
}
