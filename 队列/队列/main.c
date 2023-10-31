#include "queue.h"

int main() {

	int ret;

	Linkqueue* que = create_queue();

	insert(que, 5);
	insert(que, 10);
	insert(que, 129308);
	insert(que, 128);

	printf_queue(que);

	ret = pop(que);

	printf("ret=%d\n", ret);

	printf_queue(que);


	return 0;
}