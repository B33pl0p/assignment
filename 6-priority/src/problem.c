#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "transcript.h"
#include "adt.h"

// Usage: ./mysolution [filename]
int main(int argc, char *argv[]) {
    assert(argc == 2);
    char* filename = argv[1];
    
    // Read the transcript file
    Line* transcript[1000];
    int n = readTranscript(filename, transcript);
    
    // Create a new priority queue
    PriorityQueue* pq = createPriorityQueue();

    // Insert tasks into the priority queue based on their priority
    for (int i = 0; i < n; i++) {
        int priority = atoi(transcript[i]->action);  // Action contains the priority
        insertTask(pq, priority, transcript[i]->data);  // Insert the task into the queue
    }

    // Print the tasks from highest to lowest priority
    printTasks(pq);

    // Cleanup memory
    destroyPriorityQueue(pq);
    destroyTranscript(transcript, n);

    return 0;
}
