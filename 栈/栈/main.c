#include "stack.h"

int main() {

	stack* str = create_stack(20);

	heap(str, 10);
	heap(str, 22);
	heap(str, 12);
	heap(str, 56);

	printf_stack(str);
	stack_infom(str);

	int test = pop(str);

	printf_stack(str);
	stack_infom(str);


	return 0;
}