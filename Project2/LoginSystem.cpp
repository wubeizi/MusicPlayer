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
		printf("��ѡ����1��ע���û�\n");
		judge = '1';
		Register();
		break;
	case '2':
		printf("��ѡ����2���û���¼\n");
		judge = '1';
		Login();
		break;
	case '3':
		printf("��ѡ����3���ο͵�¼\n");
		judge = '0';
		GuestLogin();
		break;
	case '0':
		printf("�˳��ɹ�!\n");
		exit(0);
		break;
	default:
		printf("ѡ�����,������ѡ��!\n");
		break;
	}
}
void menu()
{
	printf("*******************************************\n");
	printf("*******************************************\n");
	printf("*****1.Registerע��         2.Login��¼****\n");
	printf("*****3.GuestLogin�ο͵�¼   0.exit�˳�*****\n");
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
	printf("��ӭ����ע�����!\n");
	FILE* pf = fopen("users.txt", "rb");
	fread(&b, sizeof(Users), 1, pf);
	if (!pf)
	{
		printf("%s", strerror(errno));
		return;
	}
	Sleep(800);
	printf("�����������˺�>>");
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
			printf("���û����Ѵ�����,����������!\n");
			Sleep(500);
			system("cls");
			fclose(pf);
			pf = NULL;
			Register();
		}
	}
	printf("��������������>>");
	scanf("%s", a.name);
	printf("�����������Ա�>>");
	scanf("%s", a.sex);
	printf("���������ĵ绰����>>");
	scanf("%s", a.phone);
	printf("����������>>");
	scanf("%s", a.pwd);
	printf("\n���ٴ�ȷ����������>>");
	scanf("%s", b.pwd);
	do
	{
		if (!strcmp(a.pwd, b.pwd))
		{
			pf = fopen("users.txt", "ab");
			fwrite(&a, sizeof(Users), 1, pf);
			printf("\n�˺�ע��ɹ�,���¼!\n");
			Sleep(500);
			fclose(pf);
			pf = NULL;
			Login();
			return;
		}
		else
		{
			printf("\n�������벻ƥ��!����������>>");
			scanf("%s", a.pwd);
			printf("\n���ٴ�ȷ��>>");
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
	printf("��ӭ������¼����!\n");
	Sleep(1000);
	fread(&b, sizeof(Users), 1, pf);
	printf("�������˺�>>");
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
				printf("���˺Ų�����!����������!\n");
				Sleep(500);
				fclose(pf);
				pf = NULL;
				return;
			}
		}
	}
	do
	{
		printf("����������>>");
		scanf("%s", c.pwd);
		if (!strcmp(c.pwd, b.pwd))
		{
			printf("\n��¼�ɹ�!��ӭʹ��!\n");
			Sleep(500);
			system("cls");
			menu1();
			fclose(pf);
			pf = NULL;
			return;
		}
		else
		{
			printf("\n�����������,����������\n");
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
			printf("�������µ�����:");
			scanf("%s", &name);
			printf("�������µĵ绰���룺");
			scanf("%s", &phone);
			strcpy(a.name, name);
			strcpy(a.phone, phone);
			fseek(pf, -sizeof(Users), SEEK_CUR);
			fwrite(&a, sizeof(Users), 1, pf);
			printf("�޸ĳɹ�\n");
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
		printf("*********************1.��������*********************\n");
		printf("************2.�鿴������Ϣ 3.�޸ĸ�����Ϣ***********\n");
		printf("*************            0.�˳�         ************\n");
		printf("****************************************************\n");
		printf("****************************************************\n");
		setbuf(stdin, NULL);
		input1 = getchar();
		switch (input1)
		{
		case '1':
			printf("��ѡ����1����������\n�����������ֲ��Ź��ܽ���\n");
			Sleep(500);
			system("cls");
			switch2();
			break;
		case '2':
			printf("��ѡ����2���鿴������Ϣ\n");
			Sleep(500);
			system("cls");
			printf("������Ϣ:\n");
			printf("������");
			printf(" % s\n", a.name);
			printf("�绰���룺");
			printf(" % s\n", a.phone);
			printf("�ձ�");
			printf("% s\n", a.sex);
			printf("��Ŀǰ������%d�׸�\n",a.number);
			while (1) {			
				printf("�����밴0:\n");
				scanf("%s", &index);
				if (index == '0') {
					Sleep(500);
					system("cls");
					menu1();
					break;
				}
				else {
					printf("����������������룡\n");
				}
			}
			break;
		case '3':
			printf("��ѡ����3���޸ĸ�����Ϣ\n");
			Sleep(500);
			system("cls");
			Revise();
			break;
		case '0':
			printf("�˳��ɹ�!\n");
			Sleep(500);
			system("cls");
			break;
		default:
			printf("ѡ�����,������ѡ��!\n");
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
	printf("******1.ע��                       2.��¼***********\n");
	printf("*****************3.��������*************************\n");
	printf("****************************************************\n");
	printf("******************0.�˳� ***************************\n");
	setbuf(stdin, NULL);
	input2 = getchar();
	switch (input2)
	{
	case '1':
		printf("��ѡ����1��ע���û�\n");
		Sleep(500);
		system("cls");
		Register();
		break;
	case '2':
		printf("��ѡ����2���û���¼\n");
		Sleep(500);
		system("cls");
		Login();
		break;
	case '3':
		printf("��ѡ����3����������\n�����������ֲ��Ź��ܽ���\n");
		Sleep(500);
		system("cls");
		switch2();
		break;
	case '0':
		printf("�˳��ɹ�!\n");
		Sleep(500);
		system("cls");
		LoginMenu();
		break;
	default:
		printf("ѡ�����,������ѡ��!\n");
		break;
	}while (input2 != '0');
}