#include "differ.h"

int main()
{	
	FILE * fileptr = fopen("example.txt", "r");
	char * arr = MakeArray(fileptr);

	printf("result is %d\n", GetResult(arr));

	return 0;
}
