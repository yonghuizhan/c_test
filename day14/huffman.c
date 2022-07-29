#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct huffman
{
    int  character;
    int freq;
}HUFFMAN;
/*************************/
/*统计字符的频率*/
/*************************/
HUFFMAN *freqhuf(int *count,char *goalfile)
{
    FILE *fpin;
    char ch;
    int i;
    HUFFMAN *result;

    if((fpin = fopen(goalfile,"rb")) == NULL)//判断是否成功打开文件.
        {
            printf("error opening file.\n");
            exit(1);
        }

    ch = fgetc(fpin);
    int index;
    int freq[256]= {0};
    while ( !feof(ch))
    {
        freq[ch]++;
        ch = fgetc(fpin);//统计字符频率
    }


    for   ( i =0;i < 256;i++)
    {
        if ( freq[i] != 0)
        {
            (*count)++;
        }
    }



    result = (HUFFMAN*)calloc(2*(*count)-1,sizeof(HUFFMAN));
    for ( i = 0,index = 0 ;i < 256 ;i++ )
    {
        if( freq[i] != 0 )
        {
            result[index].character = i;
            result[index].freq = freq[i];
            index++; 
        }
    }
    fclose(fpin);
    return result;//返回了一个储存了字符对应asiic码和对于频率的结构数组.

}

/***********************/
/*比较频率，生成编码*/
/***********************/

typedef struct huff
{
    HUFFMAN freq;

    int left;

    int right;

    int use;//use为0表示没有使用，1表示使用过了.

    char *code;
}Huff;

Huff *buildhufftree(HUFFMAN *information,int *count)
{
    Huff *result;
    int i;
    int digree;
    digree = 2*(*count)-1;
    int temp;

    result = (Huff*)calloc(sizeof(Huff),digree);

    for ( i = 0 ; i < *count ;i++)//初始化哈夫曼树的前面count个子结点.
    {
        result[i].freq.freq = information[i].freq;
        result[i].freq.character = information[i].character;
        result[i].left = -1;
        result[i].right = -1;
        result[i].use = 0;
        result[i].code = (char *)malloc(sizeof(digree));
    }

    for ( i = *count ; i < digree ; i++)//生成parents节点.
    {
        result[i].use = 1;
        result[i].freq.character = '#';
        result[i].left = searchmin(result,*count);
        result[i].right = searchmin(result,*count);
        result[i].freq.freq = result[result[i].left].freq.freq+result[result[i].right].freq.freq;
        temp = searchmin(result,++(*count));//检查树生成是否到了最后.

        if ( temp == -1)
        {
            break;
        }
        result[temp].use = 0;//如果没有到最后，把这个检查节点的use 标识重置.
        result[i].use = 0;//重置 use 标识，在下一次寻找最小频率的时候可以使用新生成的parents节点.
    }
    return result;//返回生成的哈夫曼树，是一个结构数组的形式.
}

int searchmin( Huff *freq, int count )
{
    int i;
    int minindex = -1;
    for ( i = 0 ; i < count ;i++)
    {
        if ( freq[i].use == 0 ) 
        {
            minindex = i;
        }
    }
    if ( minindex == -1)
    {
        return -1;
    }
    for ( i = 0 ; i < count;i++)
    {
        if ( ( freq[i].freq.freq <= freq[minindex].freq.freq ) && ( freq[i].use == 0 ) )
        {
            minindex = i;
        }
    }
    freq[minindex].use = 1;
    return minindex;
}

void buildhufcode(int root,int index,Huff *freq,char *str)
{
    if ( freq[root].left != -1 && freq[root].right != -1 ) 
    {
        str[index] = '1';
        buildhufode(freq[root].left,index+1,freq,str );
        str[index] = '0';
        buildhufcode(freq[root].right,index+1,freq,str );
    }
    else 
    {
        str[index] = 0;
        strcpy(freq[index].code ,str);
    }

}
#define CLR_BYTER(value,index) ((value) &= (~(1 << (index)^7)))
#define SET_BYTER(value,index) ((value) |= (1 << (index)^7))
#define GET_BYTER(value,index) (((value) & (1 << ((index)^7))) !=0 )
typedef unsigned char u8;

typedef struct message{

    u8 ishuf[3];
    u8 count;
    u8 lastindex;
    char passward;
}MESSAGE;

void creatcodefile(Huff *freq,int count,char *goalfile,char *resultfile,HUFFMAN *storefreq)
{
    FILE *fpout;
    FILE *fpin;
    u8  value;
    int i;
    int index;
    const char *hufcode;
    int arr[256];
    int ch;
    int password;
    MESSAGE headcode = {'M','u','f'};
    
    if ((fpout = fopen(goalfile,"rb")) == NULL)
        puts("error opening file");
    if ((fpin = fopen(resultfile,"wb") == NULL))
        puts("error writting file");
    headcode.count = (u8)(count +1)/2;
    headcode.lastindex = howlongchar(freq,count);

    fwrite(&headcode,sizeof(MESSAGE),1,fpout);
    fwrite(storefreq,sizeof(HUFFMAN),(count +1)/2,fpout);
    for ( i = 0; i< count ;i++)
    {
        arr[freq[i].freq.character] = i;
    }
     ch = fgetc(fpin);
     while(!feof(fpin))
     {
        hufcode = freq[arr[ch]].code;
        for( i = 0; hufcode[i]; i++ ) 
        {
            if (hufcode[i] == '0')
            {
                CLR_BYTER(value,index);
            }
            if (hufcode[i] == '1')
            {
                SET_BYTER(value,index);
            }
            if (++index >= 8)
            {
                index = 0;
                fwrite( &value,1,1,fpout);
            }
            ch = fgetc(fpin);
        }
        if (index)
        {
            fwrite(&value,1,1,fpout);
        }
     }
    fclose(fpin);
    fclose(fpout);
}

int howlongchar(Huff *freq,int count)
{
    int i;
    int sum = 0;

    for ( i= 0; i < (count+1)/2;i++ )
    {
        sum = sum +strlen(freq[i].code);
        sum &= 0xFF;
    }
    return sum % 8 == 0 ? 8 : sum %8;
}

int main()
{
    int count = 0;
    char goalfile[50];
    char resultfile[50];
    HUFFMAN *information;
    Huff *freq;
    char *str;
    FILE *fpin;
    FILE *fpout;
    int i;

    puts("Enter the source file");
    gets(goalfile);

    puts("Enter the result file name");
    gets(resultfile);

    if ((fpin = fopen(goalfile,"w")) == NULL)
        puts("Error opening source file\n");
    fclose(fpin);
    
}



