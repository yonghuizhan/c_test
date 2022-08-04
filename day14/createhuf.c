#include "createhuf.h"
HUFFMAN *
freqhuf (int *count, char *goalfile)
{
  int freq[256] = { 0 };
  int i;
  int index;
  HUFFMAN *result;
  FILE *fpIn;
  int ch;

  fpIn = fopen (goalfile, "rb");
  ch = fgetc (fpIn);
//统计所有字符，这里用字符的ASCII码值作为下标，
//freq[ASCII]的值，作为该字符的频率，形成字符和其频率的映射关系
  while (!feof (fpIn))
    {
      freq[ch]++;
      ch = fgetc (fpIn);
    }
  fclose (fpIn);
//统计多少种字符
  for (i = 0; i < 256; i++)
    {
      if (freq[i] != 0)
	{
	  (*count)++;
	}
    }
//将统计的结果，字符和其频率生成数组返回出去。
  result = (HUFFMAN *) calloc (sizeof (HUFFMAN), (2 * (*count) - 1));
  for (i = 0, index = 0; i < 256; i++)
    {
      if (freq[i] != 0)
	{
	  result[index].character = i;
	  result[index++].freq = freq[i];
	}
    }
  return result;
}

Huff *
bulidhuftree (HUFFMAN * information, int *count)
{
  int i;
  int digree = 2 * (*count) - 1;
  Huff *result;
  int temp;

  //将生成的哈夫曼树放在result里返回
  result = (Huff *) calloc (digree, sizeof (Huff));
  //填充基本字符及其频度
  for (i = 0; i < *count; i++)
    {
      result[i].freq.freq = information[i].freq;
      result[i].freq.character = information[i].character;
      result[i].left = -1;
      result[i].right = -1;
      result[i].use = 0;
      result[i].code = (char *) malloc (sizeof (char) * (*count));
    }
  //根据基本字符及其频度填充哈夫曼表
  for (i = *count; i < digree; i++)
    {
      result[i].use = 1;
      result[i].freq.character = '#';
      result[i].right = searchmin (result, *count);
      result[i].left = searchmin (result, *count);
      result[i].freq.freq =
	result[result[i].right].freq.freq + result[result[i].left].freq.freq;
      temp = searchmin (result, ++(*count));
      if (temp == -1)
	{
	  break;
	}
      result[temp].use = 0;
      result[i].use = 0;
    }
  return result;
}

//查找到频率最小的字符的下标
int
searchmin (Huff * freq, int count)
{
  int i;
  int minindex = -1;

  for (i = 0; i < count; i++)
    {
      if (freq[i].use == 0)
	{
	  minindex = i;
	  break;
	}
    }
  // if(minindex == -1){
  //      return -1;
  // }
  for (i = 0; i < count; i++)
    {
      if ((freq[i].freq.freq <= freq[minindex].freq.freq) && freq[i].use == 0)
	{
	  minindex = i;
	}
    }
  freq[minindex].use = 1;
  return minindex;
}


void
bulidhuftreecode (int root, int index, Huff * freq, char *str)
{
  //采用递归，此处是哈夫曼压缩最难得地方，建议大家根据代码遍历跟踪一遍
  if (freq[root].left != -1 && freq[root].right != -1)
    {
      str[index] = '1';
      bulidhuftreecode (freq[root].left, index + 1, freq, str);
      str[index] = '0';
      bulidhuftreecode (freq[root].right, index + 1, freq, str);
    }
  else
    {
      str[index] = 0;
      strcpy (freq[root].code, str);
    }
}

void
creatcodefile (Huff * freq, int count, char *goalfile,
	       char *resultfile, HUFFMAN * storefreq)
{
  FILE *fpOut;
  FILE *fpIn;
  // unsigned char value = 0;
  unsigned char value = 0;
  int i;
  int index = 0;
  const char *hufCode;
  int arr[256];
  int ch;
  int password;
  MESSAGE headcode = { 'H', 'u', 'f' };

  //将密码存入文件头信息
  printf ("请设置压缩密码，以便解压时候用：\n");
  scanf ("%d", &headcode.password);
  fpOut = fopen (resultfile, "wb");
  fpIn = fopen (goalfile, "rb");
  headcode.count = (unsigned char) (count + 1) / 2;
  headcode.lastindex = howlongchar (freq, count);
  //将文件头信息写入文件
  fwrite (&headcode, sizeof (MESSAGE), 1, fpOut);
  //将字符和其频率写入文件
  fwrite (storefreq, sizeof (HUFFMAN), (count + 1) / 2, fpOut);

  for (i = 0; i < (count + 1) / 2; i++)
    {
      arr[freq[i].freq.character] = i;
    }
  //遍历源文件，将每个字符按其哈夫曼编码写入新文件
  ch = fgetc (fpIn);
  while (!feof (fpIn))
    {
      hufCode = freq[arr[ch]].code;
      for (i = 0; hufCode[i]; i++)
	{
	  if (hufCode[i] == '0')
	    {
	      //CLR_BYTE(value, index);
	      value = value << 1;
	    }
	  if (hufCode[i] == '1')
	    {
	      //SET_BYTE(value, index);
	      value = (value << 1) | 0x01;
	    }
	  if (++index >= 8)
	    {
	      index = 0;
	      fwrite (&value, 1, 1, fpOut);
	    }
	}
      ch = fgetc (fpIn);
    }
  if (index)
    {
      fwrite (&value, 1, 1, fpOut);
    }
	// char cmd[256] = "";
	// sprintf(cmd, "md5sum %s | awk '{print $1}' > tmp.md5", goalfile);
	// system(cmd);
	// sprintf(cmd, "cat %s tmp.md5 > %s", resultfile, resultfile);
	// system(cmd);
  fclose (fpIn);
  fclose (fpOut);
}

int
howlongchar (Huff * freq, int count)
{
  int i;
  int sum = 0;

  for (i = 0; i < (count + 1) / 2; i++)
    {
      sum = sum + strlen (freq[i].code);
      sum &= 0xFF;
    }
  return sum % 8 == 0 ? 0 : sum % 8;
}

int 
main (int argc, char *argv[])
{
  int count = 0;
  HUFFMAN *information;
  Huff *freq;
  char *str;
  char resultfile[50];
  char goalfile[50];
  FILE *fp;
  int i;
 int error = 0;		//用于测试函数.
	//system("pause");
	// puts("enter source filename.\n");
	// scanf("%s",goalfile);
	// puts("enter source filename.\n");
	// scanf("%s",resultfile);
  fp = fopen ( argv[1], "r");
  if (fp == NULL)
    {
      printf ("不存在该文件！");
      return 0;
    }
  fclose (fp);
  fp = fopen (argv[2], "w");
  fclose (fp);
   strcpy (goalfile, argv[1]);
   strcpy (resultfile, argv[2]);
  //统计字符
  information = freqhuf (&count, goalfile);
	error = test_freqhuf_createhuf(information,count);

  //临时数组存每个字符code
  str = (char *) malloc (sizeof (char) * (count + 1));

  //构建哈夫曼树
  freq = bulidhuftree (information, &count);
  error = test_buildhuftree_createhuf(freq,count);

  //构建哈夫曼编码
  bulidhuftreecode (count - 1, 0, freq, str);//这里调用count 的时候是作为根节点输入函数的，所以减去1.
  //创建压缩文件

  creatcodefile (freq, count, goalfile, resultfile, information);
  //释放内存
  free (information);
  free (str);
  for (i = 0; i < count; i++)
    {
      free (freq[i].code);
    }
  free (freq);
//   if (error == -1)
//     return 0;
  printf ("压缩成功！");

  return 0;
}
