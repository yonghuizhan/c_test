#include "createhuf.h"

int  test_buildhuftree_createhuf(Huff *result ,int count)
{	
	int i;
	int error = 0;
	for ( i = 0; i < count; i++ )
	{
		if ( result[i].freq.freq == 0 )
		{
			printf("error create huftree %d point.\n",i);
			error = -1;
			break;
		}
	}
	for ( i = count; i < 2*count-1 ; i++)
	{
		if ( result[i].freq.freq != ( result[result[i].left].freq.freq + result[result[i].right].freq.freq ) )
			{
				printf ("error create hufftree %d point.\n",i);
				error = -1;
				break;
			}
	}
	
	return error;
}