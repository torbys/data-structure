#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

/*

��������������һ���ڵ㣺����������������ֵС���������������������

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

void insert(TREE** root, int val){   //����һ������ָ�룬���ָ��ָ��-ָ����ڵ��ָ��

    //�ö���ָ��ı����ǿ����ɶ���ָ��һֱָ��ͷ�ڵ㣬Ȼ����һ��ָ��ȥ�ҿսڵ㣬�������ǿ�����ʱͨ������ָ���ͷ�ڵ㿪ʼ��Ѱ
    if (*root == NULL){  //���������ڵ�ָ��Ϊ0�򴴽��ڵ� 
        *root = create_node(val);
        return;
    }

    if (val < (*root)->data) //�������ڵ�����ֵ��С�����Ǵ�����ֵ��������
    {
        insert(&((*root)->left), val);  //ע:����ȥ��Ҳ��Ҫһ������ָ��
    }
    else//�������ڵ�����ֵ�Ҵ������Ǵ�����ֵ������ұ�
    {
        insert(&((*root)->right), val);
    }
}

// ���������У�insert��������һ������ָ��root��һ��ֵval��
// ���rootָ��Ľڵ�Ϊ�գ���val���뵽��λ�ã�
// ���򣬸���val�Ĵ�С���ݹ�ز��뵽���������������С�

void preed(TREE* root) //�������
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