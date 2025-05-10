#include <windows.h>
void change_color()
{
	system("cls");
	printf("1. 红色\n");
	printf("2. 绿色\n");
	printf("3. 蓝色\n");
	printf("4. 黄色\n");
	printf("5. 默认\n");
	printf("请选择字体颜色: ");
	int color;
	scanf("%d", &color);
	switch (color)
	{
	case 1:
		system("color 0c");
		break;
	case 2:
		system("color 0a");
		break;
	case 3:
		system("color 0b");
		break;
	case 4:
		system("color 0e");
		break;
	case 5:
		system("color 07");
		break;
	}
}
void show_date()
{
	system("cls");
	system("date /t");
	system("time /t");
	system("pause");
}
void visit_web()
{
	system("cls");
	printf("正在打开网页...\n");
	Sleep(1000);
	system("start https://github.com/AChen1111/AddressBook");
}