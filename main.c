#include "meau.h"
#include "cpt.h"
#include "function.h"
int main() {
	start();
	int choice;
	while (1)
	{
		start_meau();
		scanf("%d", &choice);
		switch (choice)
		{
		case 0:
			start();
			break;
		case 1:
			input();
			break;
		case 2:
			display();
			break;
		case 3:
			search();
			break;
		case 4:
			update();
			break;
		case 5:
			del();
			break;
		case 6:
			end_meau();
			return 0;
		case 7:
			set();
			break;
		default:
			printf("输入错误，请重新输入！\n");
			system("pause");
			break;
		}

	}
	return 0;
}
