#include <iostream>
#include "globalVariables.h"
using namespace std;

const char* imgFileName = "test_decoded_dc.yuv";
const char* outFileName = "pmf_dc.csv";
int w = 128;	// ͼ���
int h = 128;	// ͼ���

void Pmf(unsigned char* buffer, int size, FILE* outFilePtr)
{
	int count[256] = { 0 };	// ������
	double freq[256] = { 0 };	// Ƶ��
	double entropy = 0;	// �÷�������

	for (int i = 0; i < size / 2; i++)
	{
		int index = (int)buffer[i];
		count[index]++;
	}

	// ����÷�����Ƶ�ʣ�������÷���
	for (int i = 0; i < 256; i++)
	{
		freq[i] = (double)count[i] / (w * h);	//���ӷ�ĸ��Ϊint�ͣ���������ת������֤���Ϊdouble����
		if (freq[i] != 0)
		{
			entropy += (-freq[i]) * log(freq[i]) / log(2);
		}
	}

	fprintf(outFilePtr, "Symbol,Frequency\n");
	for (int i = 0; i < 256; i++)
	{
		fprintf(outFilePtr, "%-3d,%-8.2e\n", i, freq[i]);	// ������������ļ��У�csv�ļ��ԡ�,����Ϊ�ָ�����
	}
	fprintf(outFilePtr, "%.4lf", entropy);
}