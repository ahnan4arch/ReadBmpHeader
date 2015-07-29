#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include "windows.h"

typedef struct 
{
	unsigned char bfType1;//bfType占两字节，一个一个字地读比较方便
	unsigned char bfType2;
	unsigned long bfSize;
	unsigned short int bfReserved1;
	unsigned short int bfReserved2;
	unsigned long bfOffBits;
}BmpFileHeader;

typedef struct
{
	unsigned long biSize;
	unsigned long biWidth;
	unsigned long biHeight;
	unsigned short int biPlans;
	unsigned short int biBitCount;
	unsigned long biCompression;
	unsigned long biSizeImage;
	unsigned long biXpM;
	unsigned long biYpM;
	unsigned long biClrUsed;
	unsigned long biClrImportant;
}BmpInfoHeader;

void main()
{
	BmpFileHeader FileHeader;
	BmpInfoHeader InfoHeader;
	FILE *bmp;

	if ((bmp = fopen("a.bmp", "r")) == NULL)
	{
		printf("The File is not exist!\n");
	}

	/*fread函数：
	buffer：用于接收数据的地址（指针）
	size：单个元素的大小，单位是字节
	count：元素个数
	stream：提供数据的文件指针*/
	

	//fread(&FileHeader, 14, 1, bmp);

	/***若将以下内容中的fread全部注释掉,用上面那句fread,直接读整个头信息,会出错,无法读取第三字节***/

	printf("bmp文件头信息\n");

	fread(&FileHeader.bfType1, 1, 1, bmp);
	fread(&FileHeader.bfType2, 1, 1, bmp);
	printf("位图类型：%c%c\n", FileHeader.bfType1, FileHeader.bfType2);

	fread(&FileHeader.bfSize, 4, 1, bmp);
	printf("位图大小：%lu\n", FileHeader.bfSize);

	fread(&FileHeader.bfReserved1, 2, 1, bmp);
	printf("位图保留字1：%d\n", FileHeader.bfReserved1);

	fread(&FileHeader.bfReserved2, 2, 1, bmp);
	printf("位图保留字2：%d\n", FileHeader.bfReserved2);
	
	fread(&FileHeader.bfOffBits, 4, 1, bmp);
	printf("位图像素组的起始地址：%lu\n", FileHeader.bfOffBits);

	/*********************************************************************/

	fread(&InfoHeader, 40, 1, bmp);
	
	printf("\n位图文件头\n");
	printf("该头结构的大小：%lu\n", InfoHeader.biSize);
	printf("位图宽度，单位为像素（有符号整数）：%lu\n", InfoHeader.biWidth);
	printf("位图高度，单位为像素（有符号整数）：%lu\n", InfoHeader.biHeight);
	printf("色彩平面数，只有1为有效值：%d\n", InfoHeader.biPlans);
	printf("每个像素所占位数：%d\n", InfoHeader.biBitCount);
	printf("所使用的压缩方法：%lu\n", InfoHeader.biCompression);
	printf("图像大小（指原始位图数据的大小）：%lu\n", InfoHeader.biSizeImage);
	printf("图像的横向分辨率，单位为像素每米（有符号整数）：%lu\n", InfoHeader.biXpM);
	printf("图像的纵向分辨率，单位为像素每米（有符号整数）：%lu\n", InfoHeader.biYpM);
	printf("调色板的颜色数：%lu\n", InfoHeader.biClrUsed);
	printf("重要颜色数（为0时表示所有颜色都是重要的，通常不使用本项）：%lu\n\n", InfoHeader.biClrImportant); 

	/*奇怪的事情看这里*/

	printf("整个文件头大小：%d\n", sizeof(FileHeader));//很奇怪地是16
	printf("位图类型：%d\n", sizeof(FileHeader.bfType1)+sizeof(FileHeader.bfType2));
	printf("位图大小：%d\n", sizeof(FileHeader.bfSize));
	printf("位图保留字1：%d\n", sizeof(FileHeader.bfReserved1));
	printf("位图保留字2：%d\n", sizeof(FileHeader.bfReserved2));
	printf("位图像素组的起始地址：%d\n", sizeof(FileHeader.bfOffBits));

}