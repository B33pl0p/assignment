#include "adt.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to create a new empty priority queue
PriorityQueue* createPriorityQueue() {
    PriorityQueue* pq = malloc(sizeof(PriorityQueue));
    pq->head = NULL;  // Initialize with an empty list
    return pq;
}

// Function to free memory used by the priority queue
void destroyPriorityQueue(PriorityQueue* pq) {
    Node* current = pq->head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);  // Free each node
    }
    free(pq);  // Free the queue itself
}

// Function to insert a task into the queue based on priority
void insertTask(PriorityQueue* pq, int priority, const char* data) {
    Node* newNode = malloc(sizeof(Node));
    newNode->priority = priority;
    strcpy(newNode->data, data);
    newNode->next = NULL;

    // If the list is empty or the new node has higher priority than the head, insert at the beginning
    if (pq->head == NULL || pq->head->priority > priority) {
        newNode->next = pq->head;
        pq->head = newNode;
        return;
    }

    // Otherwise, find the correct place to insert in priority order
    Node* current = pq->head;
    while (current->next != NULL && current->next->priority <= priority) {
        current = current->next;
    }
    
    newNode->next = current->next;
    current->next = newNode;
}

// Function to print tasks in the queue from highest to lowest priority
void printTasks(PriorityQueue* pq) {
    Node* current = pq->head;
    if (current == NULL) {
        printf("No tasks listed.\n");
        return;
    }
    
    while (current != NULL) {
        printf("Priority %d - %s\n", current->priority, current->data);
        current = current->next;
    }
}
