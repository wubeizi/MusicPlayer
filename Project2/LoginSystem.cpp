#include"PLAYER.h"
char judge;
Users c;
char input;
void LoginMenu() {
	do { 
		menu();
		switch1();
	} while (input != '0');
}
void Number(){
	Users a;
	FILE* pf = fopen("users.txt", "r+");
	while (fread(&a, sizeof(Users), 1, pf) == 1) 
	{
		if (strcmp(a.id, c.id) == 0)
		{
			a.number = a.number + 1;
			fseek(pf, -sizeof(Users), SEEK_CUR);
			fwrite(&a, sizeof(Users), 1, pf);
			fclose(pf);
		}
	}
}
void GuestLogin()
{
	menu2();
}
void switch1()
{
	setbuf(stdin, NULL);
	input = getchar();
	switch (input)
	{
	case '1':
		printf("您选择了1；注册用户\n");
		judge = '1';
		Register();
		break;
	case '2':
		printf("您选择了2；用户登录\n");
		judge = '1';
		Login();
		break;
	case '3':
		printf("您选择了3；游客登录\n");
		judge = '0';
		GuestLogin();
		break;
	case '0':
		printf("退出成功!\n");
		exit(0);
		break;
	default:
		printf("选择错误,请重新选择!\n");
		break;
	}
}
void menu()
{
	printf("*******************************************\n");
	printf("*******************************************\n");
	printf("*****1.Register注册         2.Login登录****\n");
	printf("*****3.GuestLogin游客登录   0.exit退出*****\n");
	printf("*******************************************\n");
	printf("*******************************************\n");
}
void Register()
{
	Sleep(500);
	system("cls");
	Users a, b;
	memset(&a, 0, sizeof(struct Users));
	memset(&b, 0, sizeof(struct Users));
	printf("欢迎来到注册界面!\n");
	FILE* pf = fopen("users.txt", "rb");
	fread(&b, sizeof(Users), 1, pf);
	if (!pf)
	{
		printf("%s", strerror(errno));
		return;
	}
	Sleep(800);
	printf("请输入您的账号>>");
	scanf("%s", a.id);
	while (1)
	{
		if (strcmp(a.id, b.id))
		{
			if (!feof(pf))
			{
				fread(&b, sizeof(Users), 1, pf);
			}
			else
			{
				break;
			}
		}
		else
		{
			printf("此用户名已存在在,请重新输入!\n");
			Sleep(500);
			system("cls");
			fclose(pf);
			pf = NULL;
			Register();
		}
	}
	printf("请输入您的姓名>>");
	scanf("%s", a.name);
	printf("请输入您的性别>>");
	scanf("%s", a.sex);
	printf("请输入您的电话号码>>");
	scanf("%s", a.phone);
	printf("请输入密码>>");
	scanf("%s", a.pwd);
	printf("\n请再次确认您的密码>>");
	scanf("%s", b.pwd);
	do
	{
		if (!strcmp(a.pwd, b.pwd))
		{
			pf = fopen("users.txt", "ab");
			fwrite(&a, sizeof(Users), 1, pf);
			printf("\n账号注册成功,请登录!\n");
			Sleep(500);
			fclose(pf);
			pf = NULL;
			Login();
			return;
		}
		else
		{
			printf("\n两次密码不匹配!请重新输入>>");
			scanf("%s", a.pwd);
			printf("\n请再次确认>>");
			scanf("%s", b.pwd);
		}
	} while (1);
}
void Login()
{
    Sleep(1);
	system("cls");
	Users b;
	FILE* pf = fopen("users.txt", "rb");
	if (!pf)
	{
		printf("%s\n", strerror(errno));
		return;
	}
	printf("欢迎来到登录界面!\n");
	Sleep(1000);
	fread(&b, sizeof(Users), 1, pf);
	printf("请输入账号>>");
	scanf("%s", c.id);
	while (1)
	{
		if (!strcmp(c.id, b.id))
		{
			break;
		}
		else
		{
			if (!feof(pf))
			{
				fread(&b, sizeof(Users), 1, pf);
			}
			else
			{
				printf("此账号不存在!请重新输入!\n");
				Sleep(500);
				fclose(pf);
				pf = NULL;
				return;
			}
		}
	}
	do
	{
		printf("请输入密码>>");
		scanf("%s", c.pwd);
		if (!strcmp(c.pwd, b.pwd))
		{
			printf("\n登录成功!欢迎使用!\n");
			Sleep(500);
			system("cls");
			menu1();
			fclose(pf);
			pf = NULL;
			return;
		}
		else
		{
			printf("\n密码输入错误,请重新输入\n");
		}
	} while (strcmp(c.pwd, b.pwd));
}
void Revise()
{
	Users a;
	char name[100];
	char phone[100];
	FILE* pf = fopen("users.txt", "r+");
	while (fread(&a, sizeof(Users), 1, pf) == 1)
	{
		if (strcmp(a.id, c.id) == 0)
		{
			printf("请输入新的姓名:");
			scanf("%s", &name);
			printf("请输入新的电话号码：");
			scanf("%s", &phone);
			strcpy(a.name, name);
			strcpy(a.phone, phone);
			fseek(pf, -sizeof(Users), SEEK_CUR);
			fwrite(&a, sizeof(Users), 1, pf);
			printf("修改成功\n");
			Sleep(1000);
			system("cls");
			fclose(pf);
			menu1();
			break;
		}
	}
}
void menu1()
{
	Users a;
	FILE* pf = fopen("users.txt", "rb");
	char input1;
	char index;
	do {
		while (1)
		{
			fread(&a, sizeof(Users), 1, pf);
			if (strcmp(a.id, c.id) != 0)
			{
				if (feof(pf) == 0) 
				{
					fread(&a, sizeof(Users), 1, pf);
				}
			}
			else
				break;
		}
		printf("****************************************************\n");
		printf("****************************************************\n");
		printf("*********************1.播放音乐*********************\n");
		printf("************2.查看个人信息 3.修改个人信息***********\n");
		printf("*************            0.退出         ************\n");
		printf("****************************************************\n");
		printf("****************************************************\n");
		setbuf(stdin, NULL);
		input1 = getchar();
		switch (input1)
		{
		case '1':
			printf("您选择了1；播放音乐\n即将进入音乐播放功能界面\n");
			Sleep(500);
			system("cls");
			switch2();
			break;
		case '2':
			printf("您选择了2；查看个人信息\n");
			Sleep(500);
			system("cls");
			printf("个人信息:\n");
			printf("姓名：");
			printf(" % s\n", a.name);
			printf("电话号码：");
			printf(" % s\n", a.phone);
			printf("姓别：");
			printf("% s\n", a.sex);
			printf("您目前已听了%d首歌\n",a.number);
			while (1) {			
				printf("返回请按0:\n");
				scanf("%s", &index);
				if (index == '0') {
					Sleep(500);
					system("cls");
					menu1();
					break;
				}
				else {
					printf("输入错误，请重新输入！\n");
				}
			}
			break;
		case '3':
			printf("您选择了3；修改个人信息\n");
			Sleep(500);
			system("cls");
			Revise();
			break;
		case '0':
			printf("退出成功!\n");
			Sleep(500);
			system("cls");
			break;
		default:
			printf("选择错误,请重新选择!\n");
			break;
		}
	} while (input1 != '0');
	LoginMenu();
}
void menu2()
{
	char input2;
	Sleep(500);
	system("cls");
	printf("****************************************************\n");
	printf("****************************************************\n");
	printf("******1.注册                       2.登录***********\n");
	printf("*****************3.播放音乐*************************\n");
	printf("****************************************************\n");
	printf("******************0.退出 ***************************\n");
	setbuf(stdin, NULL);
	input2 = getchar();
	switch (input2)
	{
	case '1':
		printf("您选择了1；注册用户\n");
		Sleep(500);
		system("cls");
		Register();
		break;
	case '2':
		printf("您选择了2；用户登录\n");
		Sleep(500);
		system("cls");
		Login();
		break;
	case '3':
		printf("您选择了3；播放音乐\n即将进入音乐播放功能界面\n");
		Sleep(500);
		system("cls");
		switch2();
		break;
	case '0':
		printf("退出成功!\n");
		Sleep(500);
		system("cls");
		LoginMenu();
		break;
	default:
		printf("选择错误,请重新选择!\n");
		break;
	}while (input2 != '0');
}