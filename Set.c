#include <windows.h>
void change_color()
{
	system("cls");
	printf("1. ��ɫ\n");
	printf("2. ��ɫ\n");
	printf("3. ��ɫ\n");
	printf("4. ��ɫ\n");
	printf("5. Ĭ��\n");
	printf("��ѡ��������ɫ: ");
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
	printf("���ڴ���ҳ...\n");
	Sleep(1000);
	system("start https://github.com/AChen1111/AddressBook");
}