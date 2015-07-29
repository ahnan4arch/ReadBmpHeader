#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include "windows.h"

typedef struct 
{
	unsigned char bfType1;//bfTypeռ���ֽڣ�һ��һ���ֵض��ȽϷ���
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

	/*fread������
	buffer�����ڽ������ݵĵ�ַ��ָ�룩
	size������Ԫ�صĴ�С����λ���ֽ�
	count��Ԫ�ظ���
	stream���ṩ���ݵ��ļ�ָ��*/
	

	//fread(&FileHeader, 14, 1, bmp);

	/***�������������е�freadȫ��ע�͵�,�������Ǿ�fread,ֱ�Ӷ�����ͷ��Ϣ,�����,�޷���ȡ�����ֽ�***/

	printf("bmp�ļ�ͷ��Ϣ\n");

	fread(&FileHeader.bfType1, 1, 1, bmp);
	fread(&FileHeader.bfType2, 1, 1, bmp);
	printf("λͼ���ͣ�%c%c\n", FileHeader.bfType1, FileHeader.bfType2);

	fread(&FileHeader.bfSize, 4, 1, bmp);
	printf("λͼ��С��%lu\n", FileHeader.bfSize);

	fread(&FileHeader.bfReserved1, 2, 1, bmp);
	printf("λͼ������1��%d\n", FileHeader.bfReserved1);

	fread(&FileHeader.bfReserved2, 2, 1, bmp);
	printf("λͼ������2��%d\n", FileHeader.bfReserved2);
	
	fread(&FileHeader.bfOffBits, 4, 1, bmp);
	printf("λͼ���������ʼ��ַ��%lu\n", FileHeader.bfOffBits);

	/*********************************************************************/

	fread(&InfoHeader, 40, 1, bmp);
	
	printf("\nλͼ�ļ�ͷ\n");
	printf("��ͷ�ṹ�Ĵ�С��%lu\n", InfoHeader.biSize);
	printf("λͼ��ȣ���λΪ���أ��з�����������%lu\n", InfoHeader.biWidth);
	printf("λͼ�߶ȣ���λΪ���أ��з�����������%lu\n", InfoHeader.biHeight);
	printf("ɫ��ƽ������ֻ��1Ϊ��Чֵ��%d\n", InfoHeader.biPlans);
	printf("ÿ��������ռλ����%d\n", InfoHeader.biBitCount);
	printf("��ʹ�õ�ѹ��������%lu\n", InfoHeader.biCompression);
	printf("ͼ���С��ָԭʼλͼ���ݵĴ�С����%lu\n", InfoHeader.biSizeImage);
	printf("ͼ��ĺ���ֱ��ʣ���λΪ����ÿ�ף��з�����������%lu\n", InfoHeader.biXpM);
	printf("ͼ�������ֱ��ʣ���λΪ����ÿ�ף��з�����������%lu\n", InfoHeader.biYpM);
	printf("��ɫ�����ɫ����%lu\n", InfoHeader.biClrUsed);
	printf("��Ҫ��ɫ����Ϊ0ʱ��ʾ������ɫ������Ҫ�ģ�ͨ����ʹ�ñ����%lu\n\n", InfoHeader.biClrImportant); 

	/*��ֵ����鿴����*/

	printf("�����ļ�ͷ��С��%d\n", sizeof(FileHeader));//����ֵ���16
	printf("λͼ���ͣ�%d\n", sizeof(FileHeader.bfType1)+sizeof(FileHeader.bfType2));
	printf("λͼ��С��%d\n", sizeof(FileHeader.bfSize));
	printf("λͼ������1��%d\n", sizeof(FileHeader.bfReserved1));
	printf("λͼ������2��%d\n", sizeof(FileHeader.bfReserved2));
	printf("λͼ���������ʼ��ַ��%d\n", sizeof(FileHeader.bfOffBits));

}