#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct node {

	int data;	//��Ԫ������
	struct node* next;	//��Ԫָ����

}NODE;

typedef struct queue {

	int size;	//���г��ȱ��
	NODE* front;	//����ͷ
	NODE* tail;		//����β

}Linkqueue;

Linkqueue* create_queue() {

	Linkqueue* que = (Linkqueue*)malloc(sizeof(Linkqueue));		//�����¶���
	assert(que);

	que->front = (NODE*)malloc(sizeof(NODE));	//���ٶ�ͷ�ռ�
	assert(que->front);
	que->tail = (NODE*)malloc(sizeof(NODE));	//���ٶ�β�ռ�
	assert(que->tail);

	que->size = 0;
	que->front->data = 0;
	que->tail->data = 0;

	que->front->next = que->tail;
	que->tail->next = NULL;

	return que;

}

void insert(Linkqueue* que,int data) {

	NODE* pmove = que->front->next;
	NODE* preNode = que->front;


	NODE* newNode = (NODE*)malloc(sizeof(NODE));
	assert(newNode);

	newNode->data = data;

	while (pmove->next != NULL) {

		preNode = pmove;
		pmove = pmove->next;

	}
	
	newNode->next = pmove;
	preNode->next = newNode;

	que->size++;

}

int pop(Linkqueue* que) {

	int ret;

	NODE* pmove = que->front->next;

	if (pmove->data == NULL) {
		printf("����Ϊ��\n");
		return 0;
	}
	else {
		 ret = pmove->data;
	}
	
	que->front->next = pmove->next;

	free(pmove);

	que->size--;

	return ret;
}

void printf_queue(Linkqueue* que) {

	NODE* pmove = que->front->next;

	if (que->size == 0) {
		printf("�ö���������\n");
	}
	else {
		printf("�ö��л���%d������\n", que->size);
	}

	printf("�������ݣ�");
	while (pmove->next != NULL) {

		printf("%d ", pmove->data);
		pmove = pmove->next;

	}

	printf("\n");
}




