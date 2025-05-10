#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>
#include "set.h"

void start()
{
	printf("============================\n");
	printf("||    温馨提示            ||\n");
	printf("||    请勿直接关闭程序    ||\n");
	printf("||    请使用退出选项      ||\n");
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
        printf("||          [0]. 使用说明             ||\n");
        printf("||          [1]. 新增                 ||\n");
        printf("||          [2]. 列表                 ||\n");
        printf("||          [3]. 搜索                 ||\n");
        printf("||          [4]. 编辑                 ||\n");
        printf("||          [5]. 删除                 ||\n");
        printf("||          [6]. 退出                 ||\n");
        printf("||          [7]. 设置                 ||\n");
        printf("========================================\n");
        printf("请选择一个选项: ");
}
void end_meau()
{
	system("cls");
    printf("正在退出程序");
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
	printf("\n谢谢使用！\n");
	system("pause");
}
void set()
{
	system("cls");
	printf("请选择设置选项：\n");
	printf("1.改变字体颜色\n");
	printf("2.显示日期\n");
	printf("3.访问项目仓库\n");
	printf("请选择: ");
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



