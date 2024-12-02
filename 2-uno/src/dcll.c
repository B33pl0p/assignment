#include "dcll.h"

// Creates a new node for the DLL with the given player name
node_t* dcll_create_node(char* str) {
    node_t* new_node = (node_t*)malloc(sizeof(node_t)); // allocate memory for the new node
    assert(new_node != NULL); // checking if memory allocation works, should fail if it doesn't

    new_node->data = strdup(str); // duplicate the player name into data
    assert(new_node->data != NULL); // make sure strdup worked too

    // Now make this node point to itself, so it forms a circular list
    new_node->next = new_node; // next points to itself
    new_node->prev = new_node; // prev also points to itself

    return new_node; // return the newly created node
}

// Gets the tail node of the list. In a circular list, it's just the prev of head
node_t* dcll_get_tail(node_t* head) {
    if (head == NULL) return NULL; // If list is empty, return NULL
    
    return head->prev; // Tail is just the prev of head in a circular list
}

// Inserts a new node with player name at the end of the list
void dcll_insert(node_t* head, char* str) {
    node_t* new_node = dcll_create_node(str); // create a new node using our create function
    
    // Now, we need to link the new node into the list
    node_t* tail = dcll_get_tail(head); // get the current tail node

    // Adjust the pointers to insert the new node at the end
    tail->next = new_node; // current tail's next should point to new node
    new_node->prev = tail; // new node's prev should point to the old tail
    new_node->next = head; // new node's next points to head (circular)
    head->prev = new_node; // head's prev should point to new node, closing the loop
}

// Searches for a node by player name and returns the node if found
node_t* dcll_search(node_t* head, char* str) {
    node_t* current = head;
    if (current == NULL) return NULL; // If the list is empty, return NULL

    do {
        if (strcmp(current->data, str) == 0) {
            return current; // If the player's name matches, return the node
        }
        current = current->next; // Move to the next node
    } while (current != head); // Keep going till we loop back to the head

    return NULL; // If we reach here, the player wasn't found
}

// Removes a node by player name from the list
node_t* dcll_remove(node_t* head, char* str) {
    node_t* node_to_remove = dcll_search(head, str); // Find the node to remove
    if (node_to_remove == NULL) return NULL; // If the node isn't found, return NULL
    
    // Fix the pointers of the neighboring nodes
    node_to_remove->prev->next = node_to_remove->next; // prev node's next should point to the next node
    node_to_remove->next->prev = node_to_remove->prev; // next node's prev should point to the prev node
    
    if (node_to_remove == head) {
        head = node_to_remove->next; // If we remove the head, move head to the next node
    }

    free(node_to_remove->data); // Free the duplicated string
    free(node_to_remove); // Free the node memory
    return head; // Return the possibly new head node
}

// Pretty print the entire list starting from head
void dcll_pprint(node_t* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    node_t* current = head;
    do {
        printf("%s -> ", current->data); // print the player name
        current = current->next; // move to the next node
    } while (current != head); // loop till we get back to the head
    printf("(head)\n"); // Indicate the head of the list
}

// Pretty print just one node (e.g., the head)
void dcll_pprint_node(node_t* n) {
    if (n == NULL) {
        printf("Node is NULL!\n");
        return;
    }
    printf("Node data: %s\n", n->data); // print the node's data (player name)
}

// Frees the entire list starting from head
void dcll_free(node_t* head) {
    if (head == NULL) return; // Nothing to free if the list is empty

    node_t* current = head;
    node_t* next_node = NULL;
    do {
        next_node = current->next; // save the next node before freeing
        free(current->data); // free the data (player name)
        free(current); // free the node itself
        current = next_node; // move to the next node
    } while (current != head); // loop till we get back to the head
}
