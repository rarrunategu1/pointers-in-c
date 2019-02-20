#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
}   Node;

void push(int, struct Node*);
int pop(Node*);
int peek(Node*);
void freeList(Node*);

int main(void)
{
    //printf("Hello\n");
    //HEAD NODE
    Node* list = NULL;

    // struct Node* second = NULL;
    // struct Node* third = NULL;

    //CREATE THE NODES
     Node* newNode = (Node*)malloc(sizeof(Node));
     newNode->data = 5;
     newNode->next = NULL;

     list = newNode;
    // second = (struct Node*)malloc(sizeof(struct Node));
    // third = (struct Node*)malloc(sizeof(struct Node));

    //give each node their data
    // head->data = 5;
    // head->next = NULL;
    //head->next = second;
    //second->data = 7;
    //second->next = third;
    //third->data = 9;
    //third->next = NULL;

    //same as:
    // head->data = 5;
    // head->next = second;
    // head->next->data = 7;
    // head->next->next = third;
    // head->next->next->data = 9;
    // head->next->next->next = NULL;

    //adds 11 to the end of the list
    push(3, list);
    push(12, list);
    printf("Popped last value: %i\n", pop(list));
    push(14, list);
    printf("Popped last value: %i\n", pop(list));

    //int result = pop(head);
    printf("The last value at the end of list removed is: %i\n", pop(list));
    printf("Peep last value at end of list now.  It is: %i\n", peek(list));
    freeList(list);


}

void push(int data, struct Node* head)
{
    struct Node* trav = head;

    while(trav != NULL && trav->next != NULL)
    {
        //grabs next item of our list
        trav = trav->next;
    }

    //Make space for your new node
    Node* newNode = (Node*)malloc(sizeof(Node));

    //add another node at end of list
    newNode->data = data;
    newNode->next = NULL;
    if(trav == NULL)
    {
        head = newNode;
        return;
    }

    trav->next = newNode;

    //printf("Added Node has a value of: %i\n", trav->next->data);

    //ANOTHER WAY THAT'S QUICKER BUT USES MORE MEMORY
    // struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    // newNode->data = data;
    // newNode->next = NULL;
    // trav->next = newNode;
}

//get pop to work for a single item
int pop(struct Node* head)
{
    struct Node* trav = head;

    if(trav == NULL)
    {
        //our linked list only accepts positive numbers.  You can't pop if trav is equal to NULL
        return -1;
    }
    if(trav->next == NULL)
        {
            int data = trav->data;
            free(trav);
            //trav = NULL;
            //printf("%p\n", trav);
            //printf("%i\n", trav->data);
           return data;

           //second and third malloc causing a memory leak
        }

    while(trav->next->next != NULL)
    {
        trav = trav->next;
    }

    int data = trav->next->data;
    //FREES LAST ITEM WHICH IS EQUAL TO NULL
    free(trav->next);
    //ASSIGNS THE NOW LAST ITEM TO NULL
    trav->next = NULL;

    return data;


}

int peek(struct Node* head)
{
    //get to end of list and return the data
    struct Node* trav = head;

     if(trav == NULL)
    {
        //our linked list only accepts positive numbers.  You can't pop if trav is equal to NULL
        return -1;
    }

    while(trav->next != NULL)
    {
        trav = trav->next;
    }
    int data = trav->data;
    //printf("%i\n", data);
    return data;

}

void freeList(Node* root)
{
    Node* trav = root;

    if(trav == NULL)
    {
        return;
    }

    //if only one item
    if (trav->next == NULL)
    {
        free(trav);
        return;
    }
    if (trav->next->next == NULL)
    {
        //printf("%i\n", trav->next->data);
        free(trav->next);
        free(trav);
        //printf("%i\n", trav->next->data);
        return;
    }
    //printf("%i\n", trav->next->data);
    freeList(trav->next);
    //printf("%i\n", trav->next->data);
    //frees head
    free(root);
    return;


    // int data = trav->data;
    // return data;
}

// void freeListNew(Node* trav)
// {
//     if(trav->next == NULL)
//     {
//         free(trav);
//     }
// }
// freeListNew(trav->next);
// free(trav);

