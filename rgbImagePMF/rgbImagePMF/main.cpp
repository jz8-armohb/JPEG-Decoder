#include <iostream>
#include "globalVariables.h"
using namespace std;

int main()
{
	FILE* imgFilePtr;
	FILE* outFilePtr;	// 存储数据的文件
	int imgSize;	// 图像总字节数

	// 打开文件
	if (fopen_s(&imgFilePtr, imgFileName, "rb") == 0)
	{
		cout << "Successfull opened the original image." << endl;
	}
	else
	{
		cout << "Failed to open the original image." << endl;
	}
	fopen_s(&outFilePtr, outFileName, "w");

	// 计算图片总字节数
	fseek(imgFilePtr, 0L, SEEK_END);	// 使文件指针指向文件末尾
	imgSize = ftell(imgFilePtr);	// 文件总字节数
	rewind(imgFilePtr);	// 使文件指针再回到文件起始（若不回到起始，无法将img中的数据读入到缓冲区中）
	cout << "The space that original image accounts for: " << imgSize << " Bytes = " << imgSize / 1024 << " kB" << endl;

	// 建立缓冲区
	unsigned char* imgBuffer = new unsigned char[imgSize];	// 图像缓冲区
	unsigned char* yBuffer = new unsigned char[imgSize / 2];	// Y分量缓冲区

	// 将数据读入缓冲区
	fread(yBuffer, sizeof(unsigned char), imgSize / 2, imgFilePtr);

	// 分别统计R、G、B分量的概率分布
	Pmf(yBuffer, imgSize, outFilePtr);

	// 关闭文件
	fclose(imgFilePtr);
	fclose(outFilePtr);
	// 释放内存
	delete[]imgBuffer;
	delete[]yBuffer;
}