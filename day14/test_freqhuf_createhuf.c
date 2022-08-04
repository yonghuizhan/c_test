#include "createhuf.h"
int test_freqhuf_createhuf(HUFFMAN *result,int count)
{
	int i;
	int error = 0;
	for ( i = 0; i < count; i++)
	{
		if ( result[i].freq == 0)
		{	
			puts("Creating character frequency list failed.\n");
			error = -1;
			break;
		}
	}
	return error;
}