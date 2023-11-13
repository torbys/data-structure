#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

/*

二叉搜索树：对一个节点：它的左子树比它的值小。它的右子树比它本身大。

*/

typedef struct node {

    struct node* left;
    struct node* right;

    int data;
}TREE;

TREE* create_node(int data) {

    TREE* newnode = (TREE*)malloc(sizeof(TREE));

    newnode->data = data;

    newnode->left = NULL;
    newnode->right = NULL;

}

void insert(TREE** root, int val){   //传入一个二级指针，这个指针指向-指向根节点的指针

    //用二级指针的本意是可以由二级指针一直指向头节点，然后由一级指针去找空节点，这样我们可以随时通过二级指针从头节点开始找寻
    if (*root == NULL){  //如果这个根节点指针为0则创建节点 
        *root = create_node(val);
        return;
    }

    if (val < (*root)->data) //如果这个节点上有值且小于我们传来的值则插入左边
    {
        insert(&((*root)->left), val);  //注:传过去的也是要一个二级指针
    }
    else//如果这个节点上有值且大于我们传来的值则插入右边
    {
        insert(&((*root)->right), val);
    }
}

// 上述代码中，insert函数接受一个二级指针root和一个值val，
// 如果root指向的节点为空，则将val插入到该位置；
// 否则，根据val的大小，递归地插入到左子树或右子树中。

void preed(TREE* root) //先序遍历
{

    if (root != NULL) {
        printf("%d ", root->data);
        preed(root->left);
        preed(root->right);
    }

}

TREE* search_tree(TREE* root, int data) {

    if (root == NULL) return NULL;

    if (root->data > data) {
        return search_tree(root->left, data);
    }
    else if (root->data < data) {
        return search_tree(root->right, data);
    }
    else if (root->data == data) {
        return root;
    }

}

TREE* deleteNode(TREE* root, int val) {

    if (root == NULL) {
        return NULL;
    }
    if (root->data > val) {
        root->left = deleteNode(root->left, val);
        return root;
    }
    else if (root->data < val) {
        root->right = deleteNode(root->right, val);
        return root;
    }
    else if (root->data == val) {
        if (root->left == NULL && root->right == NULL) {

            TREE* temp = root;
            free(root);
            temp = NULL;
            return temp;

        }
        else if (root->left != NULL && root->right == NULL)  {

            TREE* temp = root->left;
            free(root);
            return temp;

        }
        else if (root->left == NULL && root->right != NULL) {

            TREE* temp = root->right;
            free(root);
            return temp;

        }
        else if (root->left != NULL && root->right != NULL) {

            TREE* pmove = root->right;

            while (pmove->left != NULL) {
                pmove = pmove->left;
            }

            pmove->left = root->left;
            TREE* temp = root->right;
            free(root);
            return temp;
        }
    }
}