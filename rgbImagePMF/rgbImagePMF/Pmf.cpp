#include <iostream>
#include "globalVariables.h"
using namespace std;

const char* imgFileName = "test_decoded_dc.yuv";
const char* outFileName = "pmf_dc.csv";
int w = 128;	// 图像宽
int h = 128;	// 图像高

void Pmf(unsigned char* buffer, int size, FILE* outFilePtr)
{
	int count[256] = { 0 };	// 计数器
	double freq[256] = { 0 };	// 频率
	double entropy = 0;	// 该分量的熵

	for (int i = 0; i < size / 2; i++)
	{
		int index = (int)buffer[i];
		count[index]++;
	}

	// 计算该分量的频率，并输出该分量
	for (int i = 0; i < 256; i++)
	{
		freq[i] = (double)count[i] / (w * h);	//分子分母都为int型，进行类型转换，保证结果为double类型
		if (freq[i] != 0)
		{
			entropy += (-freq[i]) * log(freq[i]) / log(2);
		}
	}

	fprintf(outFilePtr, "Symbol,Frequency\n");
	for (int i = 0; i < 256; i++)
	{
		fprintf(outFilePtr, "%-3d,%-8.2e\n", i, freq[i]);	// 将数据输出到文件中（csv文件以“,”作为分隔符）
	}
	fprintf(outFilePtr, "%.4lf", entropy);
}