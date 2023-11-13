#include "AVL.h"

int main() {

	int a[8] = { 10,20,30,40,50,60,70,80 };

	NODE* root = NULL;
	for (int i = 0; i < 8; i++) {
		root = create_tree(root, a[i]);
	}

	int counter = 0;
    find(root, 70, &counter);
	printf("урак%d╢н\n", counter);
	preed(root);


	return 0;
}