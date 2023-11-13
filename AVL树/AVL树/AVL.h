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
	原则：1当前节点的右子树会作为新的根节点
		  2当前节点会作为新节点的左子树
		  3新的树根，若有左子树，则原来的左子树移动到旧节点的右子树
	*/
	NODE* newNode = root->right;
	
	NODE* newleft = newNode->left;  //先保存新根的左子树

	newNode->left = root;	//再将新根的左子树换成原来的根节点

	root->right = newleft;	//将原来的左子树移动到旧节点的右子树

	root->high = 1 + max(get(root->left), get(root->right));	//重新计算旧节点树高

	newNode->high = 1 + max(get(newNode->left), get(newNode->right));	//重新计算新节点树高

	return newNode;

}

NODE* rightRoate(NODE* root) {

	/*
	原则：1当前节点的左子树会作为新的根节点
		  2当前节点会作为新节点的右子树
		  3新的树根，若有右子树，则原来的右子树移动到旧节点的左子树
	*/

	NODE* newNode = root->left;

	NODE* newright = newNode->right;  //先保存新根的右子树

	newNode->right = root;	//再将新根的右子树换成原来的根节点

	root->left = newright;	//将原来的右子树移动到旧节点的左子树

	root->high = 1 + max(get(root->left), get(root->right));	//计算旧节点树高

	newNode->high = 1 + max(get(newNode->left), get(newNode->right));	//计算新节点树高

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
	//到这都是正常的插入

	root->high = 1 + max(get(root->left), get(root->right));	//每次插入完后计算当前的树高

	int balance = getbalance(root);	 //计算当前节点的平衡因子

	if (balance > 1 && getbalance(root->left) > 0){ //LL失衡
		return rightRoate(root);
	}
	if (balance > 1 && getbalance(root->left) < 0) { //LR失衡
		root->left = leftRoate(root->left);
		return rightRoate(root);
	}

	if (balance < -1 && getbalance(root->left) < 0) { //RR失衡
		return leftRoate(root);
	}
	if (balance < -1 && getbalance(root->left) > 0) { //RL失衡
		root->right = rightRoate(root->right);
		return leftRoate(root);
	}
	return root;	//不失衡则返回原节点
}

void preed(NODE* root) //先序遍历
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