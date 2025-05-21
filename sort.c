#include "cpt.h"
#include <stdio.h>
#include <windows.h>
void sort()
{
	FILE* fp;
	Contact temp;
	int i, j, count = 0;
	if ((fp = fopen("data.txt", "r+")) == NULL)
	{
		printf("文件打开失败！\n");
		system("pause");
		return;
	}
	while (!feof(fp))
	{
		if (fread(&contacts[count], LEN, 1, fp) == 1)
		{
			count++;
		}//把文件中的数据读入到结构体数组中
	}
	fclose(fp);
	if (count == 0)
	{
		printf("没有联系人信息！\n");
		system("pause");
		return;
	}
	for (i = 0; i < count - 1; i++)
	{
		for (j = 0; j < count - i - 1; j++)
		{
			if (strcmp(contacts[j].name, contacts[j + 1].name) > 0)
			{
				temp = contacts[j];
				contacts[j] = contacts[j + 1];
				contacts[j + 1] = temp;
			}
		}
	}
	if ((fp = fopen("data.txt", "wb")) == NULL)
	{
		printf("文件打开失败！\n");
		system("pause");
		return;
	}
	for (i = 0; i < count; i++)
	{
		if (fwrite(&contacts[i], LEN, 1, fp) != 1)
		{
			printf("写入文件失败！\n");
			system("pause");
			fclose(fp);
			return;
		}

	}
	fclose(fp);
} 