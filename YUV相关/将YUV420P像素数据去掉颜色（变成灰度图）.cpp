#include "pch.h"
#include<iostream>
//w,h为像素，num为图像个数，yuv420：每四个Y共用一组UV分量
int simplest_yuv420_split(const char *url, int w, int h, int num)
{
	FILE *fp = fopen(url, "rb+");
	FILE *fp1 = fopen("output_gray", "wb+");

	unsigned char *pic = (unsigned char *)malloc(w * h * 3 / 2);

	for (int i = 0; i < num; ++i) {
		fread(pic, 1, w * h * 3 / 2, fp);

		memset(pic + w * h, 128, w * h / 2);

		fwrite(pic, 1, w * h * 3 / 2, fp1);
	}

	free(pic);
	fclose(fp);
	fclose(fp1);

	return 0;
}

int main()
{
	simplest_yuv420_split("akiyo_qcif.yuv", 176, 144, 75);
	return 0;
}