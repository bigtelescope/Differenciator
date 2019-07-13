#include "differ.h"

int main()
{	
	FILE * fileptr = fopen("example.txt", "r");

	Tree * primary = GetResult(MakeArray(fileptr));

	Tree result;
	result.node = d(primary->node);
	result.node = Bypass(result.node);

	MakeTex(primary->node, result.node);

	return 0;
}
