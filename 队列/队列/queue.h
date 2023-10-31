#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct node {

	int data;	//单元数据域
	struct node* next;	//单元指针域

}NODE;

typedef struct queue {

	int size;	//队列长度标记
	NODE* front;	//队列头
	NODE* tail;		//队列尾

}Linkqueue;

Linkqueue* create_queue() {

	Linkqueue* que = (Linkqueue*)malloc(sizeof(Linkqueue));		//申请新队列
	assert(que);

	que->front = (NODE*)malloc(sizeof(NODE));	//开辟队头空间
	assert(que->front);
	que->tail = (NODE*)malloc(sizeof(NODE));	//开辟队尾空间
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
		printf("队列为空\n");
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
		printf("该队列无数据\n");
	}
	else {
		printf("该队列还有%d个数据\n", que->size);
	}

	printf("队列数据：");
	while (pmove->next != NULL) {

		printf("%d ", pmove->data);
		pmove = pmove->next;

	}

	printf("\n");
}




