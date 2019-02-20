#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef struct ListNode
{
    int data;
    struct ListNode *next;
} ListNode;

typedef struct BinaryNode
{
    int data;
    struct BinaryNode *smaller, *larger;

} BinaryNode;


BinaryNode* root = NULL;

//get add to work and hacker challenge is to get seek to work
void add(int);
int seek(int); //true 1 or false 0 if item exists in tree
void freeTree();

void testTree()
{
    add(5);
    //assert that it didn't fail/break
    assert(seek(5) == 1 && "tree contains the number 5"); //modify the tru to use seek

    add(3);
    add(4);
    assert(seek(9) == 0 && "tree does not contain 9");
}

//hardcoded tree
void bruteForceTree()
{
    root = malloc(sizeof(BinaryNode));
    root->data = 5;

    BinaryNode* leftNode = malloc(sizeof(BinaryNode));
    leftNode->data = 2;
    leftNode->smaller = NULL;
    leftNode->larger = NULL;

    BinaryNode* rightNode = malloc(sizeof(BinaryNode));
    rightNode->data = 8;
    rightNode->smaller = NULL;
    rightNode->larger =NULL;

    root->smaller = leftNode;
    root->larger = rightNode;
}

void testSeek()
{
    bruteForceTree();
    assert(seek(5) && "5 was found");
    assert(seek(2) && "2 was found");
    assert(!seek(1) && "confirm 1 does not exist");
    assert(seek(8) && "8 was found");
    assert(!seek(9) && "confirm 9 does not exist");
    assert(!seek(7) && "confirm 7 does not exist");
    assert(!seek(3) && "confirm 3 does not exist");
}

void testAdd()
{
    add(5);
    assert(seek(5) && "found the added 5");
    // add(8);
    // assert(seek(8) && "found the added 8");
    add(2);
    assert(seek(2) && "found the added 2");
    assert(seek(5) && "found the 5 still");
    add(1);
    assert(seek(1) && "found the added 1");
    assert(seek(2) && "found the 2 still");
    // add(8);
    // assert(seek(8) && "found the added 8");
    // add(9);
    // assert(seek(9) && "found the added 9");
    // assert(seek(8) && "found the 8 still");
    // add(4);
    // assert(seek(4) && "found the added 4");
    // add(1);
    // assert(seek(1) && "duplicate 1");
    // add(3);
    // assert(seek(3) && "found the added 3");
}
void testFreeTree()
{
    assert(seek(5) && "5 has been freed");
    assert(seek(2) && "2 has been freed");
    assert(seek(1) && "1 has been freed");

}
int main(void)
{
    printf("Hello\n");
    int data[] = {5,8,2,1,9,4,1,3};
    // testTree();
    //testSeek();
    testAdd();
    freeTree();
    testFreeTree();
}

int seek(int query)
{
    //seek is going to scan the tree for the number sent
    //return 0 if the number isn ot found in the tree
    //return 1 if the number is foumd in the tree


    BinaryNode* nav = root;

    while(true && "Not at the end of a branch or haven't found the data yet")
    {
        //how to find
        //check current node's data
        if (nav->data == query)
        {
            return 1;
        }
        //if found 1
        //else
        //is current node larger or smaller than query
        if(nav->data > query)
        {
            //go smaller node
            //check if there is a node in that direction
            //if null 0
            //the below returns if the number is not found in the tree(bruteForceTree)
            if(nav->smaller == NULL)
            {
                return 0;
            }
            //move nav to new location
            //if node navigate to node and rerun how to find
            nav = nav-> smaller;
            continue;
        }
        //query is greater than current node
        if(nav->larger == NULL)
        {
            return 0;
        }
        nav = nav->larger;
        continue;
    }

    return 0;
}

void add(int item)
{
    //to add item to end of a branch based on following rules:
    //if item is larger then current node move to right larger route
    //if smaller then current node move to left smaller route

    BinaryNode* newNode = malloc(sizeof(BinaryNode));

    newNode->data = item;
    newNode->smaller = NULL;
    newNode->larger = NULL;

    //starts the tree
    if(root == NULL)
    {
        root = newNode;
        return;
    }

    //navigator from root
    BinaryNode* nav = root;

    while("end of branch not found")
    {
        // if(item == nav->data)
        // {
        //     //printf("%i\n", item);
        //     break;
        // }
        //printf("%i\n", item);
        if(item < nav->data)
        {
            //this travels if it's not null
            if(nav->smaller != NULL)
            {
                nav = nav->smaller;
                //printf("%i\n", nav->smaller->data);
                continue;
            }
            nav->smaller = newNode;
            return;
        }
        if(item > nav->data)
        {
            //this travels if it's not null
            if(nav->larger != NULL)
            {
                nav = nav->larger;
                //printf("%i\n", nav->smaller->data);
                continue;
            }
            nav->larger = newNode;
            return;
        }
        return;
    }


}

void freeTree()
{
    //free all heap nodes from tree

    //if nav->smaller or nav->larger == null free nav

    BinaryNode *nav = root;
    // printf("%i\n", nav->smaller->data);
    // printf("%p\n", nav->smaller);

    if(nav->smaller == NULL)
    {
        free(nav);
        return;
    }
    //freeTree(root-smaller);

    if(nav->smaller != NULL)
    {
        nav = nav->smaller;
        //printf("%i\n", nav->smaller->data);
    }
    //printf("%p\n", nav->smaller);
    //printf("%i\n", nav->smaller->data);
    free(nav->smaller);
    free(nav);
    //printf("%p\n", nav->smaller);



    // printf("%p\n", nav->smaller);
}

