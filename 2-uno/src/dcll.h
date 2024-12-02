#ifndef DCLL_H
#define DCLL_H

  #include <stdio.h>      // Standard input/output library
  #include <stdlib.h>     // Standard library for memory allocation
  #include <stdbool.h>    // Standard boolean type support
  #include <assert.h>     // Support for runtime assertions
  #include <string.h>     // String manipulation functions

  // Structure definition for a node in the doubly circular linked list
  struct Node
  {
      char* data;               // Pointer to the data (player name)
      struct Node *next;        // Pointer to the next node in the list
      struct Node *prev;        // Pointer to the previous node in the list
  };

  // Typedef for easier usage of the node structure
  typedef struct Node node_t;

  // Function prototypes for operations on the doubly circular linked list

  /**
   * Creates a new node with the specified data on the heap.
   * @param str The string to store in the node.
   * @return A pointer to the newly created node.
   */
  node_t* dcll_create_node(char* str);

  /**
   * Returns the tail node of the doubly circular linked list.
   * @param head A pointer to the head node of the list.
   * @return A pointer to the tail node.
   */
  node_t* dcll_get_tail(node_t* head);

  /**
   * Inserts a new node at the end of the list.
   * If the list is empty, the new node becomes the head.
   * @param head A pointer to the head node of the list.
   * @param str The string data for the new node.
   */
  void dcll_insert(node_t* head, char* str);

  /**
   * Removes a node containing the corresponding node from the list.
   * @param head A pointer to the head node of the list.
   * @param str The string data of the node to remove.
   * @return A pointer to the head node after removal.
   */
  node_t* dcll_remove(node_t* head, char* str);

  /**
   * Prints all nodes in the list starting from the head node.
   * Each node's data is printed in order.
   * A->B->C
   * @param head A pointer to the head node of the list.
   */
  void dcll_pprint(node_t* head);

  /**
   * Prints the details of a single node.
   * @param n A pointer to the node to print.
   */
  void dcll_pprint_node(node_t* n);

  /**
   * Searches for a node containing the specified data.
   * @param head A pointer to the head node of the list.
   * @param str The string data to search for.
   * @return A pointer to the found node, or NULL if not found.
   */
  node_t* dcll_search(node_t* head, char* str);

  /**
   * Frees the memory allocated for the entire list.
   * @param head A pointer to the head node of the list.
   */
  void dcll_free(node_t* head);

#endif // DCLL_H
