#include"cpt.h"
#include <stdio.h>
#include <string.h>
void show()
{
	int i, count = 0;
	FILE* fp;
	if ((fp = fopen("data.txt", "rb")) == NULL)
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
	system("cls");
	printf("姓名\t  电话\t\t 地址\t\t     邮箱\n");

	for (i = 0; i < count; i++)
	{
		printf(FORMAT, DATA);
	}
	/*printf("是否进行排序?(Y/n):");
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
	system("cls");
	printf("姓名\t  电话\t\t 地址\t\t     邮箱\n");
	
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
		printf("文件打开失败！\n");
		system("pause");
		return;
	}
	//打开文件若失败抛出异常
	while (!feof(fp))
	{
		if (fread(&contacts[count], LEN, 1, fp) == 1)
		{
			count++;
		}
	}
	//把文件中的数据读入到结构体数组中
	fclose(fp);
	if (count > 500)
	{
		printf("列表已满无法进行添加\n");
		printf("如果您想继续添加用户可以通过:\n");
		printf("主页->[6]特殊功能->3.访问项目仓库 来自行扩容\n");
		system("pause");
	}
	//检查是否超出容量
	if (count == 0)
	{
		printf("没有联系人信息！\n");
		system("pause");
	}
	//若为数组为空给出提示
	else
	{
		system("cls");
		display();
	}
	if ((fp = fopen("data.txt", "wb")) == NULL)
	{
		printf("文件打开失败！\n");
		system("pause");
		return;
	}
	for (i = 0; i < count; i++)
	{
		fwrite(&contacts[i], LEN, 1, fp);
	}
	printf("是否新增联系人请输入(Y/n)：");
	scanf("%s", ch);
	while (strcmp(ch, "Y") == 0)
	{
		printf("请输入联系人姓名:");
		scanf("%s", &contacts[count].name);
		printf("请输入电话：");
		scanf("%s", &contacts[count].phone);
		printf("请输入地址：");
		scanf("%s", &contacts[count].address);
		printf("请输入邮箱：");
		scanf("%s", &contacts[count].email);
		if (fwrite(&contacts[count], LEN, 1, fp) != 1)
		{
			printf("写入文件失败！\n");
			system("pause");
		}
		else
		{
			printf("添加成功！\n");
			count++;
		}
		printf("是否继续添加联系人(Y/n)：");
		scanf("%s", ch);
	}//
	fclose(fp);
	printf("联系人信息已保存到文件中！\n");
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
		printf("文件打开失败！\n");
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

	printf("请输入要搜索的联系人姓名：");
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
				printf("联系人已经找到是否输出?(Y/n)：");
				scanf("%s", ch);
				if (strcmp(ch, "Y") == 0)
				{
					system("cls");
					printf("姓名\t  电话\t\t 地址\t\t     邮箱\n");
					printf(FORMAT, DATA);
					printf("联系人信息已输出！\n");
					system("pause");
				}
				break;
			}
		}
	}
	if (num > 1)
	{
		printf("已经找到%d个联系人，是否进行筛选?(Y/n)：", num);
		scanf("%s", ch);
		if (strcmp(ch, "Y") == 0)
		{
			printf("请输入要筛选的联系人电话：");
			char phone[15];
			scanf("%s", phone);
			for (i = 0; i < count; i++)
			{
				if ((strcmp(contacts[i].phone, phone) == 0) && (strcmp(contacts[i].name, name) == 0))
				{
					system("cls");
					printf("联系人已经找到是否输出?(Y/n)：");
					scanf("%s", ch);
					if (strcmp(ch, "Y") == 0)
					{
						system("cls");
						printf("姓名\t  电话\t\t 地址\t\t     邮箱\n");
						printf(FORMAT, DATA);
						printf("联系人信息已输出！\n");
						system("pause");
					}
					break;
				}
				else if (i == count - 1)
				{
					printf("没有找到该联系人！\n");
					system("pause");
				}
			}
		}
		else
		{
			printf("取消筛选！\n");
			for (i = 0; i < count; i++)
			{
				if (strcmp(contacts[i].name, name) == 0)
				{
					printf("姓名\t  电话\t\t 地址\t\t     邮箱\n");
					printf(FORMAT, DATA);
				}
			}
			printf("联系人信息已输出！\n");
			system("pause");
		}
	}
	if (num == 0)
	{
		printf("没有找到该联系人！\n");
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
		printf("打开文件失败\n");
		return;
	}
	while (!feof(fp))
	{
		if (fread(&contacts[count], LEN, 1, fp) == 1)
		{
			count++;
		}//把文件中的数据读入到结构体数组中
	}

	if (count == 0)
	{
		printf("没有联系人信息！\n");
		fclose(fp);
		system("pause");
		return;
	}
	display();
	printf("请输入要修改的联系人姓名：");
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
				printf("请输入新的电话：");
				scanf("%s", &contacts[i].phone);
				printf("请输入新的地址：");
				scanf("%s", &contacts[i].address);
				printf("请输入新的邮箱：");
				scanf("%s", &contacts[i].email);
				printf("修改成功！\n");
				if ((fp = fopen("data.txt", "wb")) == NULL)
				{
					printf("文件打开失败！\n");
					system("pause");
					return;
				}
				for (j = 0; j < count; j++)
				{
					if (fwrite(&contacts[j], LEN, 1, fp) != 1)
					{
						printf("写入文件失败！\n");
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
		printf("已经找到%d个联系人，是否进行筛选?(Y/n)：", num);
		scanf("%s", ch);
		if (strcmp(ch, "Y") == 0)
		{
			printf("请输入要修改联系人的电话：");
			char phone[15];
			scanf("%s", phone);
			for (i = 0; i < count; i++)
			{
				if ((strcmp(contacts[i].phone, phone) == 0)&&(strcmp(contacts[i].name, name) == 0))
				{
					printf("请输入新的电话：");
					scanf("%s", &contacts[i].phone);
					printf("请输入新的地址：");
					scanf("%s", &contacts[i].address);
					printf("请输入新的邮箱：");
					scanf("%s", &contacts[i].email);
					printf("修改成功！\n");
					if ((fp = fopen("data.txt", "wb")) == NULL)
					{
						printf("文件打开失败！\n");
						system("pause");
						return;
					}
					for (j = 0; j < count; j++)
					{
						if (fwrite(&contacts[j], LEN, 1, fp) != 1)
						{
							printf("写入文件失败！\n");
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
				printf("未找到该联系人\n");
				system("pause");
			}
		}
		else {
			printf("取消修改\n");
			system("pause");
			return;
		}
	}
	if (num == 0)
	{
		printf("没有找到该联系人！\n");
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
		printf("打开文件失败\n");
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
	display();
	printf("请输入要删除的联系人姓名：");
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
				printf("已经找到该联系人,是否删除?(Y/n)：");
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
						printf("文件打开失败！\n");
						system("pause");
						return;
					}
					for (j = 0; j < count; j++)
					{
						if (fwrite(&contacts[j], LEN, 1, fp) != 1)
						{
							printf("写入文件失败！\n");
							system("pause");
						}
					}
					fclose(fp);
					printf("删除成功！\n");
					system("pause");
				}
				else
				{
					printf("取消删除！\n");
					system("pause");
				}
				return;
			}
		}
	}
	if (num > 1)
	{
		printf("已经找到%d个联系人，是否进行筛选?(Y/n)：", num);
		scanf("%s", ch);
		if (strcmp(ch, "Y") == 0)
		{
			printf("请输入要删除联系人的电话：");
			char phone[15];
			scanf("%s",phone);
			for (i = 0; i < count; i++)
			{
				if ((strcmp(contacts[i].phone,phone) == 0)&&(strcmp(contacts[i].name,name)==0))
				{
					printf("已经找到该联系人,是否删除?(Y/n)：");
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
							printf("文件打开失败！\n");
							system("pause");
							return;
						}
						for (j = 0; j < count; j++)
						{
							if (fwrite(&contacts[j], LEN, 1, fp) != 1)
							{
								printf("写入文件失败！\n");
								system("pause");
							}
						}
						fclose(fp);
						printf("删除成功！\n");
						system("pause");
					}
					else
					{
						printf("取消删除！\n");
						system("pause");
					}
					found = 1;
					break;
				}
			}
			if (!found)
			{
				printf("未找到该联系人\n");
				system("pause");
			}
		}
		else {
			printf("取消修改\n");
			system("pause");
			return;
		}
	}
	if (num == 0)
	{
		printf("没有找到该联系人！\n");
		system("pause");
	}

}