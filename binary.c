#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

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

void testTree()
{
    add(5);
    //assert that it didn't fail/break
    assert(seek(5) == 1 && "tree contains the number 5"); //modify the tru to use seek

    add(3);
    add(4);
    assert(seek(9) == 0 && "tree does not contain 9");
}

int main(void)
{
    printf("Hello\n");
    //int data[] = {5,8,2,1,9,4,1,3};
    testTree();
}

void add(int data);
{
    BinaryNode* newNode = malloc(sizeof(BinaryNode));

    newNode->data = data;
    newNode->smaller = NULL;
    newNode->larger = NULL;

    if(root == NULL)
    {
        root = newNode;
        return;
    }

    while(true)
    {
      return;
    }


}

int seek(int data);
{
    return 0;
}