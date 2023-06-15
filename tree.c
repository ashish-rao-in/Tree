#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <stdbool.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} node;

node *root = NULL;

node *
createNode(node *nd, int val)
{
    nd = calloc(1,sizeof(node));
    if (nd) {
        nd->data = val;
        nd->left = NULL;
        nd->right = NULL;
        return nd;
    } else {
        return NULL;
    }
}

// Inserts the node and 
// Returns the pointer to the root of the tree
node *
insertNode(node *root, int value)
{
    if (root == NULL) {
        root = createNode(root, value);
        return root;
    }
    
    if (value < root->data) {
        root->left = insertNode(root->left, value);
    } else {
        root->right = insertNode(root->right, value);
    }
    
    return root;
}

void
walkTree(node *root)
{
    if (!root) {
        return;
    }
    walkTree(root->left);
    printf("%d ",root->data);
    walkTree(root->right);
    return;
}
