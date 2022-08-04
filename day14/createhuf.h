#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct huffman
{
  int character;
  int freq;
} HUFFMAN;
#pragma pack ()
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
  unsigned char count;
  //最后一个字符所对应的下标
  unsigned char lastindex;

  int password;
} MESSAGE;

HUFFMAN *freqhuf (int *count, char *goalfile);

Huff *bulidhuftree (HUFFMAN * information, int *count);

int searchmin (Huff * freq, int count);

void bulidhuftreecode (int root, int index, Huff * freq, char *str);

void creatcodefile (Huff * freq, int count, char *goalfile,char *resultfile, HUFFMAN * storefreq);

int howlongchar (Huff * freq, int count);

int test_freqhuf_createhuf(HUFFMAN *result,int count);

int  test_buildhuftree_createhuf(Huff *result ,int count);