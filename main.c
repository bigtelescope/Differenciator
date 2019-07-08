#include "differ.h"

int main()
{	
	FILE * fileptr = fopen("example.txt", "r");
	char * arr = MakeArray(fileptr);

	Tree * two = GetResult(arr);
	ShowTree(two->node);
/*
	Tree one;

	one.node = CreateNode();

	one.node->left = CreateNode();
	one.node->left->value = 11;

	one.node->right = CreateNode();
	one.node->right->sign = "+";

	one.node->right->right = CreateNode();
	one.node->right->right->temp = "x";

	one.node->right->left = CreateNode();
	one.node->right->left->function = "sin";

	//ShowTree(one.node);
*/
	return 0;
}
