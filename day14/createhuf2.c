#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//判断指定位是否为0，若index位为0，则GET_BYTE值为假，否则为真
#define GET_BYTE(value, index) (((value) & (1 << ((index) ^ 7))) != 0)
//将指定位，置为1
#define SET_BYTE(value, index) ((value) |= (1 << ((index) ^ 7)))
//将指定位，置为0
#define CLR_BYTE(value, index) ((value) &= (~(1 << ((index) ^ 7))))

typedef struct  Huffman
{
	unsigned char character;
	int freq;
}HUFFMAN_FREQ;
typedef struct  Huffmantree
{
	HUFFMAN_FREQ ch_freq ;
	int left;
	int right;
	int use;
	char *code;

}HUFFMAN_TREE;

typedef struct message
{
	unsigned char ishuf[3];
	unsigned char count;
	unsigned char lastindex;
	unsigned char unuse[11];
}HEAD_MESSAGE;
HUFFMAN_FREQ *get_huffreq(char *sourcefile,int *count);
HUFFMAN_TREE *build_huffmantree( HUFFMAN_FREQ *huffreq,int *count);
int searchmin( HUFFMAN_TREE *huffmantree,int *count);
void createhufcode( HUFFMAN_TREE *huffmantree,int root,int index,char *str);

HUFFMAN_FREQ *get_huffreq(char *sourcefile,int *count)
{
	int i;
	int index;
	char ch;
	FILE *fpin;
	HUFFMAN_FREQ *result;
	
	int freq[256] = {0};
	if ((fpin = (fopen(sourcefile,"rb") )) == NULL)
		printf("error opening source file.\n");

	ch = fgetc(fpin);
	while (!feof(fpin))
	{
		freq[ch]++;
		ch = fgetc(fpin);
	}
	for ( i = 0;i < 255; i++)
	{
		if (freq[i])
		(*count)++;
	}

	result = (HUFFMAN_FREQ *)calloc(2*(*count)-1,sizeof(HUFFMAN_FREQ));
	for ( i = 0,index = 0 ; i < count; i++ )
	{	
		if (freq[i])
		{
			result[index].character = i;
			result[index].freq = freq[i];
			index++;
		}

	}

	fclose(fpin);
	return result;
}

HUFFMAN_TREE *build_huffmantree( HUFFMAN_FREQ *huffreq,int *count)
{
	HUFFMAN_TREE *huffmantree;
	int i;
	int digree;
	digree = 2*(*count)-1;
	int temp;
	huffmantree = (HUFFMAN_TREE*)calloc(digree,sizeof(HUFFMAN_TREE));
	for ( i = 0; i < *count ; i++ )
	{
		huffmantree[i].ch_freq.character = huffreq[i].character;
		huffmantree[i].ch_freq.freq = huffreq[i].freq;
		huffmantree[i].left = -1;
		huffmantree[i].right = -1;
		huffmantree[i].code = (char *)malloc(sizeof(digree)); 
	}

	for ( i = *count ; i < digree ; i++ )
	{
		huffmantree[i].use = 0;
		huffmantree[i].ch_freq.character = '#';
		huffmantree[i].left = searchmin(huffmantree,*count);
		huffmantree[i].right = searchmin(huffmantree,*count);
		huffmantree[i].ch_freq.freq = huffmantree[huffmantree[i].left].ch_freq.freq + huffmantree[huffmantree[i].right].ch_freq.freq;
		(*count)++;
		temp = searchmin (huffmantree,*count);
		if ( temp == -1 )
		{
			break;
		}
		huffmantree[temp].use = 0;



	}
}

int searchmin( HUFFMAN_TREE *huffmantree,int *count)
{
	int i;
	int minindex = -1;

	for ( i = 0 ; i < *count ;i++)
	{
		if ( huffmantree[i].use != 0 )
		{
			minindex = i;
			break;
		}
	}
	if ( minindex == -1)
		return minindex;
	for ( i = 0 ; i < *count ;i++ )
	{
		if ( (huffmantree[i].ch_freq.freq <= huffmantree[minindex].ch_freq.freq ) && (huffmantree[i].use == 0))
		{	
			minindex = i;
		}
	}
	huffmantree[i].use = 1;
	return minindex;
	
}

void createhufcode( HUFFMAN_TREE *huffmantree,int root,int index,char *str)
{
	if ( (huffmantree[root].left != -1) && huffmantree[root].right != -1)
	{
		str[index] = '0';
		createhufcode(huffmantree,huffmantree[root].left,index+1,str);
		str[index] = '1';
		createhufcode(huffmantree,huffmantree[root].right,index+1,str);
	}
	else
	{
		str[index] = 0;
		strcpy(huffmantree[root].code,str);
	}
}

int getlastindex(HUFFMAN_TREE *huffmantree,int count)
{
	int sum;
	int i;
	for ( i =0 ;i < (count+1)/2;i++ )
	{
		sum += strlen(huffmantree[i].code)*huffmantree[i].ch_freq.freq ;
		sum &= 0xFF;
	}
	sum = sum%8;
	return sum == 0 ? 8 : sum;
}
void creathuffile( HUFFMAN_TREE *huffmantree,int count,char *sourcefile,char *resultfile,HUFFMAN_FREQ *huffreq)
{
	FILE *fpin;
	FILE *fpout;参考
	HEAD_MESSAGE *head;
	int i;
	int index;
	int ch;
	unsigned char value;
	char *hufcode;
	HEAD_MESSAGE filehead = {'H','u','f'};



	if ( (fpin = fopen(sourcefile,"rb")) == NULL )
		printf("error opening source file.\n");

	

}

