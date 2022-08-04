#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//判断指定位是否为0，若index位为0，则GET_BYTE值为假，否则为真
#define GET_BYTE(value, index) (((value) & (1 << ((index) ^ 7))) != 0)
//将指定位，置为1
//#define SET_BYTE(value, index) ((value) |= (1 << ((index) ^ 7)))
//将指定位，置为0
//#define CLR_BYTE(value, index) ((value) &= (~(1 << ((index) ^ 7))))

//#pragma pack (1)
typedef struct huffman
{
  int character;
  int freq;
} HUFFMAN;
typedef struct huff
{
  //字符及其频率
  HUFFMAN freq;
  //左孩子
  int left;
  //右孩子
  int right;
  //是否用过0表示没有用过1表示用过
  int use;
  //该节点对于的哈夫曼编码字符串
  char *code;
} Huff;

//压缩文件的头信息
typedef struct message
{
  //前三个字节用M，u,f代表哈夫曼文件，不是这三个字符代表该文件不是压缩文件
  unsigned char ishuf[3];
  //字符数量
  unsigned charcount;
  //最后一个字符所对应的下标
  unsigned char lastindex;

  int password;
} MESSAGE;

HUFFMAN *freqhuf (int *count, char *goalfile, int *lastindex);
Huff *bulidhuftree (HUFFMAN * information, int *count);
int searchmin (Huff * freq, int count);

void bulidhuftreecode (int root, int index, Huff * freq, char *str);
void creatsourcefile (Huff * freq, int count, char *goalfile,
		      char *resultfile, int lastindex);