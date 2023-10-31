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
		printf("栈溢出\n");
		return;
	}

	s->base[s->top] = data;
	s->top++;

}

int pop(stack* s) {

	if (s->top == 0) {
		printf("栈为空\n");
		return;
	}

	int ret = s->base[s->top];

	s->base[s->top] = 0;
	s->top--;

	return ret;

}

void printf_stack(stack* s) {

	int i;
	printf("栈内元素\n");
	for (i = 0; i < s->top; i++) {

		printf("%d ", s->base[i]);

	}
	printf("\n");

}

void stack_infom(stack* s) {

	printf("栈内元素有%d个\n", s->top);
	printf("栈容量为%d个\n", s->capacity);
	printf("栈还可容纳%d个元素\n", s->capacity - s->top);

}