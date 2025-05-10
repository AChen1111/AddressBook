#define _CRT_SECURE_NO_WARNINGS
#include"cpt.h"
#include <stdio.h>
#include <string.h>

void display()
{
	int i, count = 0;
	FILE* fp;
	if ((fp = fopen("data.txt", "rb")) == NULL)
	{
		printf("�ļ���ʧ�ܣ�\n");
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
		getchar();
		return;
	}
	system("cls");
	printf("����\t\t�绰\t\t��ַ\t\t����\n");
	
	for (i = 0; i < count; i++)
	{
		printf(FORMAT, DATA);
	}
	system("pause");
}

void input()
{
	int i, count=0;
	char ch[2];
	FILE* fp;
	if ((fp = fopen("data.txt", "a+")) == NULL)
	{
		printf("�ļ���ʧ�ܣ�\n");
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
	}
	else
	{
		system("cls");
		display();
	}
	if ((fp = fopen("data.txt", "wb")) == NULL)
	{
		printf("�ļ���ʧ�ܣ�\n");
		return;
	}
	for (i = 0; i < count; i++)
	{
		fwrite(&contacts[i], LEN, 1, fp);
	}
	printf("�Ƿ�������ϵ��������(Y/n)��");
	scanf("%s", ch);
	while (strcmp(ch, "Y") == 0)
	{
		printf("��������ϵ������:");
		scanf("%s", &contacts[count].name);
		for (i = 0; i < count; i++)
		{
			if (strcmp(contacts[count].name, contacts[i].name) == 0)
			{
				printf("����ϵ���Ѵ��ڣ�\n");
				getchar();
				fclose(fp);
				return;
			}
		}
		printf("������绰��");
		scanf("%s", &contacts[count].phone);
		printf("�������ַ��");
		scanf("%s", &contacts[count].address);
		printf("���������䣺");
		scanf("%s", &contacts[count].email);
		if (fwrite(&contacts[count], LEN, 1, fp) != 1)
		{
			printf("д���ļ�ʧ�ܣ�\n");
			getchar();
		}
		else
		{
			printf("��ӳɹ���\n");
			count++;
		}
		fclose(fp);
		printf("�Ƿ���������ϵ��(Y/n)��");
		scanf("%s", ch);
	}
	fclose(fp);
	printf("��ϵ����Ϣ�ѱ��浽�ļ��У�\n");
	Sleep(1000);
}
void search()
{
	FILE* fp;
	int i, count = 0;
	char ch[2], name[15];
	if ((fp = fopen("data.txt", "rb")) == NULL)
	{
		printf("�ļ���ʧ�ܣ�\n");
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
		getchar();
		return;
	}
	printf("������Ҫ��������ϵ��������");
	scanf("%s", name);
	for (i = 0; i < count; i++)
	{
		if (strcmp(contacts[i].name, name) == 0)
		{
			printf("��ϵ���Ѿ��ҵ��Ƿ����?(Y/n)��");
			scanf("%s", ch);
			if (strcmp(ch, "Y") == 0)
			{
				system("cls");
				printf("����\t\t�绰\t\t��ַ\t\t����\n");
				printf(FORMAT, DATA);
				printf("��ϵ����Ϣ�������\n");
				getchar();
				getchar();
			}
			break;
		}
	}
	if (i == count)
	{
		printf("û���ҵ�����ϵ�ˣ�\n");
		getchar();
	}
}
void update()
{
	FILE* fp;
	int i, j, count = 0;
	char name[15];
	if ((fp = fopen("data.txt", "r+")) == NULL)
	{
		printf("���ļ�ʧ��\n");
		return;
	}
	while (!feof(fp))
	{
		if (fread(&contacts[count], LEN, 1, fp) == 1)
		{
			count++;
		}//���ļ��е����ݶ��뵽�ṹ��������
	}
	if (count == 0)
	{
		printf("û����ϵ����Ϣ��\n");
		fclose(fp);
		return;
	}
	display();
	printf("������Ҫ�޸ĵ���ϵ��������");
	scanf("%s", name);
	for (i = 0; i < count; i++)
	{
		if (strcmp(contacts[i].name, name) == 0)
		{
			printf("�������µĵ绰��");
			scanf("%s", &contacts[i].phone);
			printf("�������µĵ�ַ��");
			scanf("%s", &contacts[i].address);
			printf("�������µ����䣺");
			scanf("%s", &contacts[i].email);
			printf("�޸ĳɹ���\n");
			if ((fp = fopen("data.txt", "wb")) == NULL)
			{
				printf("�ļ���ʧ�ܣ�\n");
				return;
			}
			for (j = 0; j < count; j++)
			{
				if (fwrite(&contacts[j], LEN, 1, fp) != 1)
				{
					printf("д���ļ�ʧ�ܣ�\n");
					getchar();
				}
			}
			fclose(fp);
			return;
		}
	}
	if (i == count)
	{
		printf("û���ҵ�����ϵ�ˣ�\n");
		getchar();
	}
}
void del()
{
	FILE* fp;
	int i, j, count = 0;
	char ch[2];
	char name[15];
	if ((fp = fopen("data.txt", "r+")) == NULL)
	{
		printf("���ļ�ʧ��\n");
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
		return;
	}
	display();
	printf("������Ҫɾ������ϵ��������");
	scanf("%s", &name);
	for (i = 0; i < count; i++)
	{
		if (strcmp(contacts[i].name, name) == 0)
		{
			printf("�Ѿ��ҵ�����ϵ��,�Ƿ�ɾ��?(Y/n)��");
			scanf("%s", ch);
			if (strcmp(ch, "Y") == 0)
			{
				for (j = i; j < count; j++)
				{
					contacts[j] = contacts[j + 1];
				}
				count--;
				if ((fp = fopen("data.txt", "wb")) == NULL)
				{
					printf("�ļ���ʧ�ܣ�\n");
					return;
				}
				for (j = 0; j < count; j++)
				{
					if (fwrite(&contacts[j], LEN, 1, fp) != 1)
					{
						printf("д���ļ�ʧ�ܣ�\n");
						getchar();
					}
				}
				fclose(fp);
				printf("ɾ���ɹ���\n");
				getchar();
			}
			else
			{
				printf("ȡ��ɾ����\n");
				getchar();
			}
			return;
		}
	}

}
