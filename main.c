#include "differ.h"

int main()
{	
	FILE * fileptr = fopen("example.txt", "r");
	char * arr = MakeArray(fileptr);

	Tree * two = GetResult(arr);
	ShowTree(two->node);
/*
	printf("\n\nafter bypassing\n\n");

	two->node = Bypass(two->node);
	ShowTree(two->node);
*/

	printf("\n\nafter differentiation\n\n");

	Tree three;
	three.node = d(two->node);
	ShowTree(three.node);

	printf("\n\nafter bypassing\n\n");

	three.node = Bypass(three.node);
	ShowTree(three.node);

	MakeTex(two->node, three.node);

	return 0;
}
