#include "differ.h"

int main()
{	
	FILE * fileptr = fopen("example.txt", "r");
	char * arr = MakeArray(fileptr);

	Tree * two = GetResult(arr);
	ShowTree(two->node);

	printf("\n\nafter differentiation\n\n");

	Tree three;
	three.node = d(two->node);
	ShowTree(three.node);

	return 0;
}
