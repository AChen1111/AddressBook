#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>
#include "set.h"

void start()
{
	printf("============================\n");
	printf("||    ��ܰ��ʾ            ||\n");
	printf("||    ����ֱ�ӹرճ���    ||\n");
	printf("||    ��ʹ���˳�ѡ��      ||\n");
	printf("============================\n");
	system("pause");
}
void start_meau()
{
	    //Sleep(1000);
	    system("cls");
        printf("========================================\n");
        printf("||       Welcome to Address Book      ||\n");
        printf("========================================\n");
        printf("||          [0]. ʹ��˵��             ||\n");
        printf("||          [1]. ����                 ||\n");
        printf("||          [2]. �б�                 ||\n");
        printf("||          [3]. ����                 ||\n");
        printf("||          [4]. �༭                 ||\n");
        printf("||          [5]. ɾ��                 ||\n");
        printf("||          [6]. �˳�                 ||\n");
        printf("||          [7]. ����                 ||\n");
        printf("========================================\n");
        printf("��ѡ��һ��ѡ��: ");
}
void end_meau()
{
	system("cls");
    printf("�����˳�����");
	for (int i = 0; i < 3; i++)
	{
		Sleep(750);
		printf(".");
	}
    system("cls");
    float x, y, a;
    for (y = 1.5; y > -1.5; y -= 0.1) {
        for (x = -1.5; x < 1.5; x += 0.05) {
            a = x * x + y * y - 1;
            putchar(a * a * a - x * x * y * y * y <= 0.0 ? '*' : ' ');
        }
        system("color 0c");
        putchar('\n');
    }
	printf("\nллʹ�ã�\n");
	system("pause");
}
void set()
{
	system("cls");
	printf("��ѡ������ѡ�\n");
	printf("1.�ı�������ɫ\n");
	printf("2.��ʾ����\n");
	printf("3.������Ŀ�ֿ�\n");
	printf("��ѡ��: ");
	int choice;
	scanf("%d", &choice);
	switch (choice)
	{
	case 1:
		change_color();
		break;
	case 2:
		show_date();
		break;
	case 3:
		visit_web();
		break;
	case 4:
		
		break;
	case 5:
		
		break;
	}
}



