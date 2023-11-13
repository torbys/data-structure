#include "search.h"

int main() {

	int a[8] = { 1,2,3,4,6,5,8,1 };
	
	TREE* root = NULL;

	int i;
	for (i = 0; i < 8; i++) {
		insert(&(root), a[i]);
	}

	preed(root);

	TREE* judge = search_tree(root, 8);
	if (judge == NULL) {
		printf("无该节点\n");
	}
	else {
		printf("节点存在\n");
	}

	TREE* root1 = deleteNode(root, 6);

	judge = search_tree(root1, 6);

	if (judge == NULL) {
		printf("无该节点\n");
	}
	else {
		printf("节点存在\n");
	}

	preed(root1);

	return 0;
}