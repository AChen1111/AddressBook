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
		printf("�ļ���ʧ�ܣ�\n");
		system("pause");
		return;
	}
	while (!feof(fp))
	{
		if (fread(&contacts[count], LEN, 1, fp) == 1)
		{
			count++;
		}//���ļ��е����ݶ��뵽�ṹ��������
	}
	fclose(fp);
	if (count == 0)
	{
		printf("û����ϵ����Ϣ��\n");
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
		printf("�ļ���ʧ�ܣ�\n");
		system("pause");
		return;
	}
	for (i = 0; i < count; i++)
	{
		if (fwrite(&contacts[i], LEN, 1, fp) != 1)
		{
			printf("д���ļ�ʧ�ܣ�\n");
			system("pause");
			fclose(fp);
			return;
		}

	}
	fclose(fp);
} 