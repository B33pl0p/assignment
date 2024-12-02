#ifndef ADT_H
#define ADT_H

#include "transcript.h"

// Define the structure for a node in the priority queue
typedef struct Node {
    int priority;          // Priority of the task (1 is highest, 4 is lowest)
    char data[200];       // Task description
    struct Node* next;    // Pointer to the next node (task)
} Node;

// Define the structure for the priority queue (sorted linked list)
typedef struct PriorityQueue {
    Node* head;           // Head of the queue (sorted list)
} PriorityQueue;

// Function prototypes
PriorityQueue* createPriorityQueue();                  // Create an empty priority queue
void destroyPriorityQueue(PriorityQueue* pq);          // Free memory used by the priority queue
void insertTask(PriorityQueue* pq, int priority, const char* data); // Insert a task into the queue based on priority
void printTasks(PriorityQueue* pq);                     // Print all tasks in priority order

#endif // ADT_H
