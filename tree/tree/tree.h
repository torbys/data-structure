#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


typedef struct tree {

	struct tree* left;	//��ָ����
	struct tree* right;	//��ָ����

	int data;	//������

}TREE;

TREE* create_root(int data)		//��ʼ�����ڵ� 
{

	TREE* root = (TREE*)malloc(sizeof(TREE));
	assert(root);

	root->left = NULL;
	root->right = NULL;
	root->data = data;

	return root;
}

/*void create_tree(TREE** root) {

	
	printf("���뵱ǰ�ڵ��ֵ��0ΪNULL�򷵻أ�");
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

void create_tree( TREE* root)	//��ʼ������ڵ� 
{
	
	if (root == NULL) {

		int ret = 0;
		printf("�ø��ڵ��ֵ");
		scanf_s("%d", &ret);
		root = create_root(ret);

	}

	int tag;

	printf("ѡ�����ýڵ��������or������(��1����0),������д-1:");
	scanf_s("%d", &tag);
	//�Ըô���ĸ��ڵ����ѡ�����

	switch (tag) {
	case 1:
		insert_left(root);	//�����
		break;
	case 0:
		insert_right(root);	//�Ҳ���
		break;
	case -1:
		return;
	default:
		system("cls");
		printf("��������ʵ�����\n");
		create_tree(root);
	}

}

void insert_left(TREE* root)	//����߽��в���
{

	TREE* lpmove = root;	//����ָ��ָ����ĸ��ڵ�
	int ret;	//����
	int tag;	//�ж�
	
	if ( lpmove->left == NULL)	//����ø��ڵ����ڵ�Ϊ�������
	{

		printf("����ýڵ������");
		scanf_s("%d", &ret);
		printf("\n");

		TREE* node = create_root(ret);	//��������
		lpmove->left = node;	//����

		printf("�Ƿ��������(1�ǣ�0��)");
		scanf_s("%d", &tag);

		if (tag == 1) {
			create_tree(lpmove);	//�����ڵ㴫���ٴν��в���
		}
		else {
			return;
		}

	}
	else {
		//������˵�����ڵ�����������
		printf("����ڵ�������ѡ����������ӽڵ�\n");
		printf("ѡ������������������������(��1����0),������д-1:");
		scanf_s("%d", &tag);
		printf("\n");

		lpmove = lpmove->left;	//��ָ��ָ���������

		switch (tag) {
		case 1:
			insert_left(lpmove);	//�Ըø��ڵ�����������������
			break;
		case 0:
			insert_right(lpmove);	//�Ըø��ڵ�������������Ҳ���
			break;
		case -1:
			return;
		default:
			system("cls");
			printf("��������ȷ������\n");
			insert_left(lpmove);
		}

	}

	printf("\n");

}

void insert_right(TREE* root)	//���ұ߽��в���
{

	TREE* rpmove = root;	//ָ����ڵ�
	int ret;
	int tag;

	if (rpmove->right == NULL) {

		printf("����ýڵ������");
		scanf_s("%d", &ret);
		printf("\n");

		TREE* node = create_root(ret);
		rpmove->right = node;

		printf("�Ƿ��������(1�ǣ�0��)");
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
		printf("���ҽڵ�����,ѡ����������ӽڵ�\n");
		printf("ѡ������������������������(��1����0),������д-1:");
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
			printf("��������ȷ������\n");
			insert_right(rpmove);
		}

	}

}

void create_left(TREE* root) {





}

void serch_tree(int a[]) {





}

void pre_ergodic_tree(TREE* root) //ǰ������� 
{
	if (root != NULL) {
		printf("%d ", root->data);		//�ȱ����Լ�
		pre_ergodic_tree(root->left);	//�ٱ����Լ���������
		pre_ergodic_tree(root->right);	//�ٱ����Լ���������
	}
	
}

void mid_ergodic_tree(TREE* root)	//��������� 
{
	if (root != NULL) {
		mid_ergodic_tree(root->left);	//�ȱ���������
		printf("%d ", root->data);		//�ٱ����Լ�
		mid_ergodic_tree(root->right);	//�ٱ���������
	}
	
}

void lat_ergodic_tree(TREE* root)	//���������
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


