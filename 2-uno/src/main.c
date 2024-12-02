#include "dcll.h"
#include <stdio.h>
enum subproblem {
    PPRINT_NODE,
    INSERT_NODE,
    FIND_TAIL,
    SEARCH_NODE, 
    TURN_PRINTING, 
    REVERSE_TURN_PRINTING, 
    MEMORYLEAKS
};

// ONLY EDIT DCLL.C
// DO NOT ALTER MAIN
int main(int argc, char const *argv[]) {
    char* players[] = {"Arnold", "Bob", "Carlos", "Duy", "Eva", "Felix", "Gina", "Hugo", "Ivy", "Jack"};

    assert(argc == 4);

    int subproblem = atoi(argv[1]);
    int nplayers = atoi(argv[2]);
    int turns = atoi(argv[3]);

    node_t* head = NULL;
    head = dcll_create_node(players[0]);

    // switch on subproblem
    switch(subproblem){
        case PPRINT_NODE:
            printf("PPRINT_NODE\n");
            dcll_pprint_node(head);
            break;
        case INSERT_NODE:
            printf("INSERT_NODE\n");
            for(int i = 1; i < nplayers; i++){
                dcll_insert(head, players[i]);
            }
            dcll_pprint(head);
            break;
        case FIND_TAIL:
            printf("FIND_TAIL\n");
            for(int i = 1; i < nplayers; i++){
                dcll_insert(head, players[i]);
            }
            node_t* tail = dcll_get_tail(head);
            printf("Tail: %s\n", tail->data);
            break;
        case SEARCH_NODE:
            printf("SEARCH_NODE\n");
            for(int i = 1; i < nplayers; i++){
                dcll_insert(head, players[i]);
            }
            node_t* carlos = dcll_search(head, "Carlos");
            printf("Who is after Carlos? %s\n", carlos->next->data);

            int count = 0; 
            node_t* temp = head;
            while(temp != carlos){
                count++;
                temp = temp->next;
            }
            printf("How many turns until it's Carlos's turn? %d\n", count);
            break;

        case TURN_PRINTING:
            printf("TURN_PRINTING\n");
            for(int i = 1; i < nplayers; i++){
                dcll_insert(head, players[i]);
            }
            for(int i = 0; i < turns; i++){
                printf("%s\n", head->data);
                head = head->next;
            }
            break;
        case REVERSE_TURN_PRINTING:
            printf("REVERSE_TURN_PRINTING\n");
            for(int i = 1; i < nplayers; i++){
                dcll_insert(head, players[i]);
            }
            for(int i = 0; i < turns; i++){
                printf("%s\n", head->data);
                head = head->prev;
            }
            break;
        case MEMORYLEAKS:
            printf("MEMORYLEAKS\n");
            for(int i = 1; i < nplayers; i++){
                dcll_insert(head, players[i]);
            }
            dcll_free(head);
            break;

    }

    return 0;
}
