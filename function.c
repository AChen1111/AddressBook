#include"cpt.h"
#include <stdio.h>
#include <string.h>
void show()
{
	int i, count = 0;
	FILE* fp;
	if ((fp = fopen("data.txt", "rb")) == NULL)
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
	system("cls");
	printf("����\t  �绰\t\t ��ַ\t\t     ����\n");

	for (i = 0; i < count; i++)
	{
		printf(FORMAT, DATA);
	}
	/*printf("�Ƿ��������?(Y/n):");
	char ch[2];
	scanf("%s",ch);
	if (strcmp(ch, "Y") == 0)
	{
		sort();
	}*/
	system("pause");
}

void display()
{
	int i, count = 0;
	FILE* fp;
	if ((fp = fopen("data.txt", "rb")) == NULL)
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
	system("cls");
	printf("����\t  �绰\t\t ��ַ\t\t     ����\n");
	
	for (i = 0; i < count; i++)
	{
		printf(FORMAT, DATA);
	}
	
}

void input()
{
	int i, count=0;
	char ch[2];
	FILE* fp;
	if ((fp = fopen("data.txt", "a+")) == NULL)
	{
		printf("�ļ���ʧ�ܣ�\n");
		system("pause");
		return;
	}
	//���ļ���ʧ���׳��쳣
	while (!feof(fp))
	{
		if (fread(&contacts[count], LEN, 1, fp) == 1)
		{
			count++;
		}
	}
	//���ļ��е����ݶ��뵽�ṹ��������
	fclose(fp);
	if (count > 500)
	{
		printf("�б������޷��������\n");
		printf("��������������û�����ͨ��:\n");
		printf("��ҳ->[6]���⹦��->3.������Ŀ�ֿ� ����������\n");
		system("pause");
	}
	//����Ƿ񳬳�����
	if (count == 0)
	{
		printf("û����ϵ����Ϣ��\n");
		system("pause");
	}
	//��Ϊ����Ϊ�ո�����ʾ
	else
	{
		system("cls");
		display();
	}
	if ((fp = fopen("data.txt", "wb")) == NULL)
	{
		printf("�ļ���ʧ�ܣ�\n");
		system("pause");
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
		printf("������绰��");
		scanf("%s", &contacts[count].phone);
		printf("�������ַ��");
		scanf("%s", &contacts[count].address);
		printf("���������䣺");
		scanf("%s", &contacts[count].email);
		if (fwrite(&contacts[count], LEN, 1, fp) != 1)
		{
			printf("д���ļ�ʧ�ܣ�\n");
			system("pause");
		}
		else
		{
			printf("��ӳɹ���\n");
			count++;
		}
		printf("�Ƿ���������ϵ��(Y/n)��");
		scanf("%s", ch);
	}//
	fclose(fp);
	printf("��ϵ����Ϣ�ѱ��浽�ļ��У�\n");
	sort();
	Sleep(1000);
}

void search()
{
	FILE* fp;
	int i, count = 0, num = 0;
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
		system("pause");
		return;
	}

	printf("������Ҫ��������ϵ��������");
	scanf("%s", name);
	for (i = 0; i < count; i++)
	{
		if (strcmp(contacts[i].name, name) == 0)
		{
			num++;
		}
	}
	if (num == 1)
	{
		for (i = 0; i < count; i++)
		{
			if (strcmp(contacts[i].name, name) == 0)
			{
				printf("��ϵ���Ѿ��ҵ��Ƿ����?(Y/n)��");
				scanf("%s", ch);
				if (strcmp(ch, "Y") == 0)
				{
					system("cls");
					printf("����\t  �绰\t\t ��ַ\t\t     ����\n");
					printf(FORMAT, DATA);
					printf("��ϵ����Ϣ�������\n");
					system("pause");
				}
				break;
			}
		}
	}
	if (num > 1)
	{
		printf("�Ѿ��ҵ�%d����ϵ�ˣ��Ƿ����ɸѡ?(Y/n)��", num);
		scanf("%s", ch);
		if (strcmp(ch, "Y") == 0)
		{
			printf("������Ҫɸѡ����ϵ�˵绰��");
			char phone[15];
			scanf("%s", phone);
			for (i = 0; i < count; i++)
			{
				if ((strcmp(contacts[i].phone, phone) == 0) && (strcmp(contacts[i].name, name) == 0))
				{
					system("cls");
					printf("��ϵ���Ѿ��ҵ��Ƿ����?(Y/n)��");
					scanf("%s", ch);
					if (strcmp(ch, "Y") == 0)
					{
						system("cls");
						printf("����\t  �绰\t\t ��ַ\t\t     ����\n");
						printf(FORMAT, DATA);
						printf("��ϵ����Ϣ�������\n");
						system("pause");
					}
					break;
				}
				else if (i == count - 1)
				{
					printf("û���ҵ�����ϵ�ˣ�\n");
					system("pause");
				}
			}
		}
		else
		{
			printf("ȡ��ɸѡ��\n");
			for (i = 0; i < count; i++)
			{
				if (strcmp(contacts[i].name, name) == 0)
				{
					printf("����\t  �绰\t\t ��ַ\t\t     ����\n");
					printf(FORMAT, DATA);
				}
			}
			printf("��ϵ����Ϣ�������\n");
			system("pause");
		}
	}
	if (num == 0)
	{
		printf("û���ҵ�����ϵ�ˣ�\n");
		system("pause");
	}
}

void update()
{
	FILE* fp;
	int i, j, count = 0,num = 0;
	int found = 0;
	char name[15],ch[2];
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
		system("pause");
		return;
	}
	display();
	printf("������Ҫ�޸ĵ���ϵ��������");
	scanf("%s", name);
	for (i = 0; i < count; i++)
	{
		if (strcmp(contacts[i].name, name) == 0)
		{
			num++;
		}
	}
	if (num == 1)
	{
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
					system("pause");
					return;
				}
				for (j = 0; j < count; j++)
				{
					if (fwrite(&contacts[j], LEN, 1, fp) != 1)
					{
						printf("д���ļ�ʧ�ܣ�\n");
						system("pause");
					}
				}
				fclose(fp);
				return;
			}
		}
	}
	if (num > 1)
	{
		printf("�Ѿ��ҵ�%d����ϵ�ˣ��Ƿ����ɸѡ?(Y/n)��", num);
		scanf("%s", ch);
		if (strcmp(ch, "Y") == 0)
		{
			printf("������Ҫ�޸���ϵ�˵ĵ绰��");
			char phone[15];
			scanf("%s", phone);
			for (i = 0; i < count; i++)
			{
				if ((strcmp(contacts[i].phone, phone) == 0)&&(strcmp(contacts[i].name, name) == 0))
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
						system("pause");
						return;
					}
					for (j = 0; j < count; j++)
					{
						if (fwrite(&contacts[j], LEN, 1, fp) != 1)
						{
							printf("д���ļ�ʧ�ܣ�\n");
							system("pause");
						}
					}
					fclose(fp);
					found = 1;
					break;
				}
			}
			if (!found)
			{
				printf("δ�ҵ�����ϵ��\n");
				system("pause");
			}
		}
		else {
			printf("ȡ���޸�\n");
			system("pause");
			return;
		}
	}
	if (num == 0)
	{
		printf("û���ҵ�����ϵ�ˣ�\n");
		system("pause");
	}
}

void del()
{
	FILE* fp;
	int i, j, count = 0,num=0;
	int found = 0;
	char ch[2];
	char name[15];
	if ((fp = fopen("data.txt", "r+")) == NULL)
	{
		printf("���ļ�ʧ��\n");
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
	display();
	printf("������Ҫɾ������ϵ��������");
	scanf("%s", name);
	for (i = 0; i < count; i++)
	{
		if (strcmp(contacts[i].name, name) == 0)
		{
			num++;
		}
	}
	if (num == 1)
	{
		for (i = 0; i < count; i++)
		{
			if (strcmp(contacts[i].name, name) == 0)
			{
				printf("�Ѿ��ҵ�����ϵ��,�Ƿ�ɾ��?(Y/n)��");
				scanf("%s", &ch);
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
						system("pause");
						return;
					}
					for (j = 0; j < count; j++)
					{
						if (fwrite(&contacts[j], LEN, 1, fp) != 1)
						{
							printf("д���ļ�ʧ�ܣ�\n");
							system("pause");
						}
					}
					fclose(fp);
					printf("ɾ���ɹ���\n");
					system("pause");
				}
				else
				{
					printf("ȡ��ɾ����\n");
					system("pause");
				}
				return;
			}
		}
	}
	if (num > 1)
	{
		printf("�Ѿ��ҵ�%d����ϵ�ˣ��Ƿ����ɸѡ?(Y/n)��", num);
		scanf("%s", ch);
		if (strcmp(ch, "Y") == 0)
		{
			printf("������Ҫɾ����ϵ�˵ĵ绰��");
			char phone[15];
			scanf("%s",phone);
			for (i = 0; i < count; i++)
			{
				if ((strcmp(contacts[i].phone,phone) == 0)&&(strcmp(contacts[i].name,name)==0))
				{
					printf("�Ѿ��ҵ�����ϵ��,�Ƿ�ɾ��?(Y/n)��");
					scanf("%s",ch);
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
							system("pause");
							return;
						}
						for (j = 0; j < count; j++)
						{
							if (fwrite(&contacts[j], LEN, 1, fp) != 1)
							{
								printf("д���ļ�ʧ�ܣ�\n");
								system("pause");
							}
						}
						fclose(fp);
						printf("ɾ���ɹ���\n");
						system("pause");
					}
					else
					{
						printf("ȡ��ɾ����\n");
						system("pause");
					}
					found = 1;
					break;
				}
			}
			if (!found)
			{
				printf("δ�ҵ�����ϵ��\n");
				system("pause");
			}
		}
		else {
			printf("ȡ���޸�\n");
			system("pause");
			return;
		}
	}
	if (num == 0)
	{
		printf("û���ҵ�����ϵ�ˣ�\n");
		system("pause");
	}

}