#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

typedef struct stack {

	int* base;
	int top;
	int capacity;

}stack;

stack* create_stack(int length) {

	stack* s = (stack*)malloc(sizeof(stack));
	assert(s);

	s->capacity = length;
	s->base = (int*)malloc(sizeof(int) * length);

	memset(s->base, 0, sizeof(int) * length);

	s->top = 0;

	return s;
}

void heap(stack* s,int data) {

	if (s->top >= s->capacity) {
		printf("ջ���\n");
		return;
	}

	s->base[s->top] = data;
	s->top++;

}

int pop(stack* s) {

	if (s->top == 0) {
		printf("ջΪ��\n");
		return;
	}

	int ret = s->base[s->top];

	s->base[s->top] = 0;
	s->top--;

	return ret;

}

void printf_stack(stack* s) {

	int i;
	printf("ջ��Ԫ��\n");
	for (i = 0; i < s->top; i++) {

		printf("%d ", s->base[i]);

	}
	printf("\n");

}

void stack_infom(stack* s) {

	printf("ջ��Ԫ����%d��\n", s->top);
	printf("ջ����Ϊ%d��\n", s->capacity);
	printf("ջ��������%d��Ԫ��\n", s->capacity - s->top);

}