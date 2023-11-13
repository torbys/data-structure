#include "tree.h"

int main() {

	TREE* root = NULL;

	create_tree(root);

	//insert_tree(root);
	
	pre_ergodic_tree(root);
	printf("\n");
	mid_ergodic_tree(root);
	printf("\n");
	lat_ergodic_tree(root);

	return 0;
}