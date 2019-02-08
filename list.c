#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
}   Node;

void push(int, struct Node*);
int pop(struct Node*);
int peek(struct Node*);

int main(void)
{
    //printf("Hello\n");
    //HEAD NODE
    struct Node* head = NULL;

    struct Node* second = NULL;
    struct Node* third = NULL;

    //CREATE THE NODES
    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));

    //give each node their data
    head->data = 5;
    head->next = second;
    second->data = 7;
    second->next = third;
    third->data = 9;
    third->next = NULL;

    //same as:
    // head->data = 5;
    // head->next = second;
    // head->next->data = 7;
    // head->next->next = third;
    // head->next->next->data = 9;
    // head->next->next->next = NULL;

    //adds 11 to the end of the list
    push(11, head);
    printf("Popped value at end of list is: %i\n", pop(head));
    printf("Peep last value at end of list now.  It is: %i\n", peek(head));
    //int result = peek;

}

void push(int data, struct Node* head)
{
    struct Node* trav = head;

    while(trav->next != NULL)
    {
        //grabs next item of our list
        trav= trav->next;
    }

    //Make space for your new node
    trav->next = (struct Node*)malloc(sizeof(struct Node));

    //add another node at end of list
    trav->next->data = data;
    trav->next->next = NULL;
    printf("Added Node has a value of: %i\n", trav->next->data);

    //ANOTHER WAY THAT'S QUICKER BUT USES MORE MEMORY
    // struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    // newNode->data = data;
    // newNode->next = NULL;
    // trav->next = newNode;
}
int pop(struct Node* head)
//navigate to end of list
//traveler points to second to last item of list
//free last item
//update second to last item to be the last itme
{
    struct Node* trav = head;
    //int counter = 0;


    //find second to last node
    while(trav->next->next != NULL)
    {
        trav = trav->next;
    }

    int data = trav->next->data;
    free(trav->next);
    trav->next = NULL;

    return data;

}

int peek(struct Node* head)
{
    //get to end of list and return the data
    struct Node* trav = head;


    while(trav->next != NULL)
    {
        trav = trav->next;
    }
    int data = trav->data;
    //printf("%i\n", data);
    return data;

}

