#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


typedef struct tree {

	struct tree* left;	//左指针域
	struct tree* right;	//右指针域

	int data;	//数据域

}TREE;

TREE* create_root(int data)		//初始化根节点 
{

	TREE* root = (TREE*)malloc(sizeof(TREE));
	assert(root);

	root->left = NULL;
	root->right = NULL;
	root->data = data;

	return root;
}

/*void create_tree(TREE** root) {

	
	printf("输入当前节点的值，0为NULL则返回：");
	int ret = 0;
	scanf_s("%d", ret);

	if (ret == 0) {
		
		*root = NULL;
		return;
	}
	else {

		TREE* newnode = create_root(ret);
		(*root) = newnode;
		create_tree((*root)->left);

		create_tree((*root)->right);

	}

}*/



void insert_left(TREE* root);
void insert_right(TREE* root);

void create_tree( TREE* root)	//初始化插入节点 
{
	
	if (root == NULL) {

		int ret = 0;
		printf("该根节点的值");
		scanf_s("%d", &ret);
		root = create_root(ret);

	}

	int tag;

	printf("选择创立该节点的左子树or右子树(左1，右0),不插入写-1:");
	scanf_s("%d", &tag);
	//对该传入的根节点进行选择插入

	switch (tag) {
	case 1:
		insert_left(root);	//左插入
		break;
	case 0:
		insert_right(root);	//右插入
		break;
	case -1:
		return;
	default:
		system("cls");
		printf("请输入合适的数字\n");
		create_tree(root);
	}

}

void insert_left(TREE* root)	//对左边进行插入
{

	TREE* lpmove = root;	//先让指针指向传入的根节点
	int ret;	//数据
	int tag;	//判断
	
	if ( lpmove->left == NULL)	//如果该根节点的左节点为空则插入
	{

		printf("输入该节点的数据");
		scanf_s("%d", &ret);
		printf("\n");

		TREE* node = create_root(ret);	//创造子树
		lpmove->left = node;	//链接

		printf("是否继续插入(1是，0否)");
		scanf_s("%d", &tag);

		if (tag == 1) {
			create_tree(lpmove);	//将根节点传出再次进行插入
		}
		else {
			return;
		}

	}
	else {
		//到这里说明根节点已有左子树
		printf("该左节点已满，选择插入它的子节点\n");
		printf("选择插入的是左子树还是右子树(左1，右0),不插入写-1:");
		scanf_s("%d", &tag);
		printf("\n");

		lpmove = lpmove->left;	//让指针指向该左子树

		switch (tag) {
		case 1:
			insert_left(lpmove);	//对该根节点的左子树进行左插入
			break;
		case 0:
			insert_right(lpmove);	//对该根节点的左子树进行右插入
			break;
		case -1:
			return;
		default:
			system("cls");
			printf("请输入正确的数字\n");
			insert_left(lpmove);
		}

	}

	printf("\n");

}

void insert_right(TREE* root)	//对右边进行插入
{

	TREE* rpmove = root;	//指向根节点
	int ret;
	int tag;

	if (rpmove->right == NULL) {

		printf("输入该节点的数据");
		scanf_s("%d", &ret);
		printf("\n");

		TREE* node = create_root(ret);
		rpmove->right = node;

		printf("是否继续插入(1是，0否)");
		scanf_s("%d", &tag);

		if (tag == 1) {
			create_tree(rpmove);
		}
		else {
			printf("end");
			return;
		}

	}
	else {
		printf("该右节点已满,选择插入它的子节点\n");
		printf("选择插入的是左子树还是右子树(左1，右0),不插入写-1:");
		scanf_s("%d", &tag);
		printf("\n");

		rpmove = rpmove->right;

		switch (tag) {
		case 1:
			insert_left(rpmove);
			break;
		case 0:
			insert_right(rpmove);
			break;
		case -1:
			return;
		default:
			system("cls");
			printf("请输入正确的数字\n");
			insert_right(rpmove);
		}

	}

}

void create_left(TREE* root) {





}

void serch_tree(int a[]) {





}

void pre_ergodic_tree(TREE* root) //前序遍历法 
{
	if (root != NULL) {
		printf("%d ", root->data);		//先遍历自己
		pre_ergodic_tree(root->left);	//再遍历自己的左子树
		pre_ergodic_tree(root->right);	//再遍历自己的右子树
	}
	
}

void mid_ergodic_tree(TREE* root)	//中序遍历法 
{
	if (root != NULL) {
		mid_ergodic_tree(root->left);	//先遍历左子树
		printf("%d ", root->data);		//再遍历自己
		mid_ergodic_tree(root->right);	//再遍历右子树
	}
	
}

void lat_ergodic_tree(TREE* root)	//后序遍历法
{
	if (root != NULL) {
		lat_ergodic_tree(root->left);
		lat_ergodic_tree(root->right);
		printf("%d ", root->data);
	}
	
}

void delete_treeNode(TREE* root) {

	TREE* pmove = root;

	
    
}


