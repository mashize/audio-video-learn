#include "pch.h"
#include<iostream>
//w,h为像素，num为图像个数，yuv420：每四个Y共用一组UV分量
int simplest_yuv420_split(const char *url, int w, int h, int num)
{
	FILE *fp = fopen(url, "rb+");
	FILE *fp1 = fopen("output_420p_y.y", "wb+");
	FILE *fp2 = fopen("output_420p_u.y", "wb+");
	FILE *fp3 = fopen("output_420p_v.y", "wb+");

	unsigned char *pic = (unsigned char *)malloc(w * h * 3 / 2);

	for (int i = 0; i < num; ++i) {
		fread(pic, 1, w * h * 3 / 2, fp);
		//Y
		fwrite(pic, 1, w * h, fp1);
		//U
		fwrite(pic + w * h, 1, w * h / 4, fp2);
		//V
		fwrite(pic + w * h * 5 / 4, 1, w * h / 4, fp3);
	}

	free(pic);
	fclose(fp);
	fclose(fp1);
	fclose(fp2);
	fclose(fp3);

	return 0;
}

int main()
{
	simplest_yuv420_split("akiyo_cif.yuv", 352, 288, 300);
	return 0;
}