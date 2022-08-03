#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//判断指定位是否为0，若index位为0，则GET_BYTE值为假，否则为真
#define GET_BYTE(value, index) (((value) & (1 << ((index) ^ 7))) != 0)
//将指定位，置为1
#define SET_BYTE(value, index) ((value) |= (1 << ((index) ^ 7)))
//将指定位，置为0
#define CLR_BYTE(value, index) ((value) &= (~(1 << ((index) ^ 7))))

#pragma pack (1)
typedef struct huffman{
    int character;
    int freq;
}HUFFMAN;
typedef struct huff{
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
}Huff;
typedef unsigned char u8;
//压缩文件的头信息
typedef struct message{
        //前三个字节用M，u,f代表哈夫曼文件，不是这三个字符代表该文件不是压缩文件
 	u8 ishuf[3];
        //字符数量
 	u8 count;
        //最后一个字符所对应的下标
 	u8 lastindex;

	int password;
}MESSAGE;

HUFFMAN *freqhuf(int *count, char *goalfile, int *lastindex);

Huff *bulidhuftree(HUFFMAN *information, int *count);

int searchmin(Huff *freq, int count);

void bulidhuftreecode(int root, int index, Huff *freq, char *str);
void creatsourcefile(Huff *freq, int count, char *goalfile, char *resultfile, int lastindex);
//void creatcodefile(Huff *freq, int count, char *goalfile, char *resultfile, HUFFMAN *storefreq);

//int howlongchar(Huff *freq, int count);

//count初值为0，传过来用于统计多少种字符，goalfile，为文件名称
HUFFMAN *freqhuf(int *count, char *goalfile, int *lastindex){
	int i;
	HUFFMAN *result;
	FILE *fpIn;
	
	fpIn = fopen(goalfile, "rb");
	if(fseek(fpIn, 3L, SEEK_SET) == 0){
		fread(count, sizeof(char),  1, fpIn);
		fread(lastindex, sizeof(char),  1, fpIn);
	}
	result = (HUFFMAN *)calloc(*count, sizeof(HUFFMAN));
	if(fseek(fpIn, 12L, SEEK_SET) == 0){
		fread(result, sizeof(HUFFMAN), *count, fpIn);
	}
	fclose(fpIn);
	return result;
}

Huff *bulidhuftree(HUFFMAN *information, int *count){
	int i;
	int degree = 2*(*count) - 1;
	Huff *result;
	int temp;
 
	//将生成的哈夫曼树放在result里返回
	result = (Huff *)calloc(sizeof(Huff), degree);
        //填充基本字符及其频度
	for(i = 0; i < *count; i++){
		result[i].freq.freq = information[i].freq;
		result[i].freq.character= information[i].character;
		result[i].left = -1;
		result[i].right = -1;
		result[i].use = 0;
		result[i].code = (char*)malloc(sizeof(char)*(*count));
	}
	//根据基本字符及其频度填充哈夫曼表
	for(i = *count; i < degree; i++){
		result[i].use = 1;
		result[i].freq.character = '#';
		result[i].right = searchmin(result, *count);
		result[i].left = searchmin(result, *count);
		result[i].freq.freq = result[result[i].right].freq.freq + result[result[i].left].freq.freq;
		temp  = searchmin(result, ++(*count));
		if(temp == -1){
			break;
		}
		result[temp].use = 0;
		result[i].use = 0;
	}
	return result;
}

 
void bulidhuftreecode(int root, int index, Huff *freq, char *str){
	//采用递归，此处是哈夫曼压缩最难得地方，建议大家根据代码遍历跟踪一遍
	if(freq[root].left != -1 && freq[root].right != -1){
		str[index] = '1';
		bulidhuftreecode(freq[root].left, index+1, freq, str);
		str[index] = '0';
		bulidhuftreecode(freq[root].right, index+1, freq, str);
	}
	else{
		str[index] = 0;
		strcpy(freq[root].code, str);
	}	
}
int searchmin(Huff *freq, int count){
	int i;
	int minindex = -1;
	
	for(i = 0; i < count; i++){
		if(freq[i].use == 0){
			minindex = i;
			break;
		}
	}
	if(minindex == -1){
		return -1;
	}
	for(i = 0; i < count; i++){
		if((freq[i].freq.freq <= freq[minindex].freq.freq) && freq[i].use == 0){
			minindex = i;
		}
	}
	freq[minindex].use = 1;
	return minindex;
}
void creatsourcefile(Huff *freq, int count, char *goalfile, char *resultfile, int lastindex){
	FILE *fpOut;
	FILE *fpIn;
	long temp;
	u8 value;
	int index = 0;
	int root;
	long bitecount;
	int fininsh = 0;
	
	fpIn = fopen(goalfile, "rb");
	fseek(fpIn, 0L, SEEK_END);
	bitecount = ftell(fpIn);//统计文件的字节数，辅助后面判断解码最后一个字节有效位判断.
	fclose(fpIn);
	
	root = count - 1;
	temp = (long)(count + 1)/2;
	fpOut = fopen(resultfile, "wb");
	fpIn = fopen(goalfile, "rb");
	if(fseek(fpIn, temp * 8 + 12, SEEK_SET) == 0){
		printf("解码中！");
		fread(&value, sizeof(char), 1, fpIn);
		while(!fininsh){
			if(GET_BYTE(value, index) == 0){
				root = freq[root].right;
			}
			if(GET_BYTE(value, index) == 1){
				root = freq[root].left;
			}
			if(freq[root].right == -1 && freq[root].right == -1){
				fwrite(&freq[root].freq.character, sizeof(char), 1, fpOut);
				root = count - 1;
			}
			if(++index >= 8){
				fread(&value, sizeof(char), 1, fpIn);
			}
			if(ftell(fpIn) == bitecount){
				if(index >= lastindex){
					fininsh = 1;
				}
			}	
			if(index >= 8){
				index = 0;
			}	//原来这里有一个bug,这个重置index = 0 的语句在上一个用来判断最后一个字节之前的if语句里面，导致解码完成后无法跳出循环.
		}
		printf("解码成功！\n");	
	}
	else{
		printf("解码失败！\n");
	}
}
int main(int argc, char *argv[]) {
	int count = 0;
	HUFFMAN *information;
	Huff *freq;
	char *str;
	char 	resultfile[50];
	char  goalfile[50];
	FILE *fp;
	char Huf[3];
	int lastindex = 0;
	int i;
	int password;
	int unpassword;
	
	fp = fopen(argv[1], "rb");
	if(fp == NULL){
		printf("不存在该文件！");
		return 0;
	}
	fread(&Huf, sizeof(char), 3, fp);
	if(Huf[0] != 'H' || Huf[1] != 'u' || Huf[2] != 'f'){
		printf("该文件不是哈夫曼压缩的文件！");
		return 0;
	}
	if(fseek(fp, 8L, SEEK_SET) == 0){
		fread(&password, sizeof(int), 1, fp);
		printf("请输入解压密码：");
		scanf("%d", &unpassword);
		if(password != unpassword){
			printf("密码错误！");
			return 0;
		}
	}
	fclose(fp);
	fp = fopen(argv[2], "w");
	fclose(fp);
	strcpy(goalfile, argv[1]);
	strcpy(resultfile, argv[2]);
	
	information = freqhuf(&count, goalfile, &lastindex);
	str = (char*)malloc(sizeof(char)*(count+1));  //临时数组存每个字符code
	freq = bulidhuftree(information, &count);
	bulidhuftreecode(count - 1, 0, freq, str);
	free(str);
	creatsourcefile(freq, count, goalfile, resultfile, lastindex);
	
	free(information);
	for(i = 0; i < count; i++){
		free(freq[i].code);
	}
	free(freq);
	
	return 0;  
}