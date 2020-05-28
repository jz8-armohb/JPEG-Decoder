#pragma once
extern const char* imgFileName;	// 原始图像路径及文件
extern const char* outFileName;	// R分量统计结果
extern const char* outPathG;	// G分量统计结果
extern const char* outPathB;	// B分量统计结果
extern int w;	// 图像宽
extern int h;	// 图像高
void Pmf(unsigned char* buffer,int size, FILE* outFile);