#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

typedef struct node {

	int data;
	int high;
	struct node* left;
	struct node* right;

}NODE;

NODE* create_treeNode(int val) {

	NODE* newNode = (NODE*)malloc(sizeof(NODE));
	assert(newNode);

	newNode->data = val;
	newNode->high = 1;
	newNode->left = NULL;
	newNode->right = NULL;

	return newNode;
}

int get(NODE* root) {

	if (root == NULL) {
		return 0; 
	}
	else {
		return root->high;
	}
}

int getbalance(NODE* root) {

	if (root == NULL) {
		return 0;
	}
	else {
		return get(root->left) - get(root->right);
	}
}

NODE* leftRoate(NODE* root) {
	/*
	ԭ��1��ǰ�ڵ������������Ϊ�µĸ��ڵ�
		  2��ǰ�ڵ����Ϊ�½ڵ��������
		  3�µ���������������������ԭ�����������ƶ����ɽڵ��������
	*/
	NODE* newNode = root->right;
	
	NODE* newleft = newNode->left;  //�ȱ����¸���������

	newNode->left = root;	//�ٽ��¸�������������ԭ���ĸ��ڵ�

	root->right = newleft;	//��ԭ�����������ƶ����ɽڵ��������

	root->high = 1 + max(get(root->left), get(root->right));	//���¼���ɽڵ�����

	newNode->high = 1 + max(get(newNode->left), get(newNode->right));	//���¼����½ڵ�����

	return newNode;

}

NODE* rightRoate(NODE* root) {

	/*
	ԭ��1��ǰ�ڵ������������Ϊ�µĸ��ڵ�
		  2��ǰ�ڵ����Ϊ�½ڵ��������
		  3�µ���������������������ԭ�����������ƶ����ɽڵ��������
	*/

	NODE* newNode = root->left;

	NODE* newright = newNode->right;  //�ȱ����¸���������

	newNode->right = root;	//�ٽ��¸�������������ԭ���ĸ��ڵ�

	root->left = newright;	//��ԭ�����������ƶ����ɽڵ��������

	root->high = 1 + max(get(root->left), get(root->right));	//����ɽڵ�����

	newNode->high = 1 + max(get(newNode->left), get(newNode->right));	//�����½ڵ�����

	return newNode;

}

NODE* create_tree(NODE* root, int val) {

	if (root == NULL) {  
		root = create_treeNode(val);
		return root;
	}

	if (val < root->data) 
	{
		root->left = create_tree(root->left, val);
	}
	else
	{
		root->right = create_tree(root->right, val);
	}
	//���ⶼ�������Ĳ���

	root->high = 1 + max(get(root->left), get(root->right));	//ÿ�β��������㵱ǰ������

	int balance = getbalance(root);	 //���㵱ǰ�ڵ��ƽ������

	if (balance > 1 && getbalance(root->left) > 0){ //LLʧ��
		return rightRoate(root);
	}
	if (balance > 1 && getbalance(root->left) < 0) { //LRʧ��
		root->left = leftRoate(root->left);
		return rightRoate(root);
	}

	if (balance < -1 && getbalance(root->left) < 0) { //RRʧ��
		return leftRoate(root);
	}
	if (balance < -1 && getbalance(root->left) > 0) { //RLʧ��
		root->right = rightRoate(root->right);
		return leftRoate(root);
	}
	return root;	//��ʧ���򷵻�ԭ�ڵ�
}

void preed(NODE* root) //�������
{

	if (root != NULL) {
		printf("%d ", root->data);
		preed(root->left);
		preed(root->right);
	}

}

void find(NODE* root, int key, int* count) {

	NODE* pmove = root;
	while (pmove != NULL) {
		if (key < pmove->data) {
			pmove = pmove->left;
			(*count)++;
		}
		else if (key > pmove->data){
			pmove = pmove->right;
			(*count)++;
		}
		else {
			return;
		}
	}
	return;
}