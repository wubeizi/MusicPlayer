#include"PLAYER.h"
#include <iostream>
#include <thread>
char musicNames[5][100] = { ".\\music\\��ɫ����.mp3",".\\music\\��������.mp3",".\\music\\������˪.mp3",".\\music\\�����������.mp3",".\\music\\��ΰ�����Ʒ.mp3" };
int playState = 0;
char* msTomin(int ms)
{
	char s1[100];
	char s2[100] = ":";
	char s3[100];
	int totalS = ms / 1000;
	int min = totalS / 60;
	int s = totalS - min * 60;
	sprintf_s(s1, "%d", min);
	sprintf_s(s3, "%d", s);
	strcat_s(s1, s2);
	strcat_s(s1, s3);
	return s1;
}
void menu3()
{
	Sleep(500);
	system("cls");
	printf("\t\t\t\t�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n");
	printf("\t\t\t\t�U                                                                 �U\n");
	printf("\t\t\t\t�U     *1.˳�򲥷�               *2.��ͣ                           �U\n");
	printf("\t\t\t\t�U                                                                 �U\n");
	printf("\t\t\t\t�U     *3.ֹͣ                   *4.չʾ�赥                       �U\n");
	printf("\t\t\t\t�U                                                                 �U\n");
	printf("\t\t\t\t�U     *5.ѭ������               *6.�������                       �U\n");
	printf("\t\t\t\t�U                                                                 �U\n");
	printf("\t\t\t\t�U     *7.���                   *8.����                           �U\n");
	printf("\t\t\t\t�U                                                                 �U\n");
	printf("\t\t\t\t�U     *9.��һ��                 *10.��һ��                        �U\n");
	printf("\t\t\t\t�U                                                                 �U\n");
	printf("\t\t\t\t�U     *11.��������              *12.�������                      �U\n");
	printf("\t\t\t\t�U                                                                 �U\n");
	printf("\t\t\t\t�U     *13.����ѭ��              *14.ѡ��                          �U\n");
	printf("\t\t\t\t�U                                                                 �U\n");
	printf("\t\t\t\t�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n");
}
void playlist()
{
	printf("\t\t\t\t�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n");
	printf("\t\t\t\t�U                                                                 �U\n");
	printf("\t\t\t\t�U      1. �ܽ��� - ��ɫ����                                       �U\n");
	printf("\t\t\t\t�U                                                                 �U\n");
	printf("\t\t\t\t�U      2. �ܽ��� - ��������                                       �U\n");
	printf("\t\t\t\t�U                                                                 �U\n");
	printf("\t\t\t\t�U      3. �ܽ��� - ������˪                                       �U\n");
	printf("\t\t\t\t�U                                                                 �U\n");
	printf("\t\t\t\t�U      4. �ܽ��� - �����������                                   �U\n");
	printf("\t\t\t\t�U                                                                 �U\n");
	printf("\t\t\t\t�U      5. �ܽ��� - ��ΰ�����Ʒ			                  �U\n");
	printf("\t\t\t\t�U                                                                 �U\n");
	printf("\t\t\t\t�U      6. �˳�����һ��                                            �U\n");
	printf("\t\t\t\t�U                                                                 �U\n");
	printf("\t\t\t\t�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n");
}
void playlist1()
{
	printf("\t\t\t\t�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n");
	printf("\t\t\t\t�U                                                                 �U\n");
	printf("\t\t\t\t�U      1. �ܽ��� - ��ɫ����                                       �U\n");
	printf("\t\t\t\t�U                                                                 �U\n");
	printf("\t\t\t\t�U      2. �ܽ��� - ��������                                       �U\n");
	printf("\t\t\t\t�U                                                                 �U\n");
	printf("\t\t\t\t�U      3. �ܽ��� - ������˪                                       �U\n");
	printf("\t\t\t\t�U                                                                 �U\n");
	printf("\t\t\t\t�U      4. �ܽ��� - �����������                                   �U\n");
	printf("\t\t\t\t�U                                                                 �U\n");
	printf("\t\t\t\t�U      5. �ܽ��� - ��ΰ�����Ʒ			                  �U\n");
	printf("\t\t\t\t�U                                                                 �U\n");
	printf("\t\t\t\t�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n");
}
int indexCorrect(int index)
{
	if (index < 0)
		return 4;
	if (index > 4)
		return 0;
	return index;
}
void play(char* musicName)
{
	char open[100] = "open ";
	char play[100] = "play ";
	strcat_s(open, musicName);
	strcat_s(play, musicName);
	mciSendString(open, NULL, 0, NULL);
	mciSendString(play, NULL, 0, NULL);
}
void pause(char* musicName)
{
	char pause[100] = "pause ";
	strcat_s(pause, musicName);
	mciSendString(pause, NULL, 0, NULL);
}
void stop(char* musicName)
{
	char stop[100] = "stop ";
	char close[100] = "close ";
	strcat_s(stop, musicName);
	strcat_s(close, musicName);
	mciSendString(stop, NULL, 0, NULL);
	mciSendString(close, NULL, 0, NULL);
}
int getPosition(char* musicName)
{
	char s1[100] = "status ";
	char s3[100] = " position";
	char st[100];
	strcat_s(s1, musicName);
	strcat_s(s1, s3);
	mciSendString(s1, st, 100, 0);
	return atoi(st);
}
void fastForward(char* musicName)
{
	int position;
	char st[100];
	char file1[100] = "seek ";
	strcat_s(file1, musicName);
	strcat_s(file1, " to ");
	char file2[100];
	position = atoi(st);
	position = (getPosition(musicName));
	char s1[100] = "���� ";
	char* s2 = msTomin(position);
	strcat(s1, s2);
	position += 15000;
	_itoa_s(position, file2, 10);
	strcat_s(file1, file2);
	mciSendString(file1, st, 100, 0);
	play(musicName);
	char s3[100] = " ������� ";
	char* s4 = (char*)malloc(sizeof(char) * 100);
	s4 = msTomin(position);
	strcat(s1, s3);
	strcat(s1, s4);
	printf(s1);
}
void rewind(char* musicName)
{
	int position;
	char st[100];
	char file1[100] = "seek ";
	strcat_s(file1, musicName);
	strcat_s(file1, " to ");
	char file2[100];
	position = atoi(st);
	position = (getPosition(musicName));
	char s1[100] = "���� ";
	char* s2 = msTomin(position);
	strcat(s1, s2);
	position -= 15000;
	_itoa_s(position, file2, 10);
	strcat_s(file1, file2);
	mciSendString(file1, st, 100, 0);
	play(musicName);
	char s3[100] = " ���˵��� ";
	char* s4 = (char*)malloc(sizeof(char) * 100);
	s4 = msTomin(position);
	strcat(s1, s3);
	strcat(s1, s4);
	printf(s1);
}
void playFrontMusic(int index)
{
	stop(musicNames[index]);
	index--;
	index = indexCorrect(index);
	play(musicNames[index]);
}
void playNextMusic(int index)
{
	stop(musicNames[index]);
	index++;
	index = indexCorrect(index);
	play(musicNames[index]);
}
void downVolume(char* musicName)
{
	char s1[100] = "status ";
	strcat(s1, musicName);
	strcat(s1, " volume");
	char vo[20];
	char s2[100] = "setaudio ";
	strcat(s2, musicName);
	strcat(s2, " volume to ");
	char res[260];
	mciSendString(s1, res, 260, NULL);
	int volume = 0;
	volume = atoi(res);
	volume -= 200;
	itoa(volume, vo, 10);
	strcat(s2, vo);
	mciSendString(s2, NULL, 0, NULL);
}
void upVolume(char* musicName)
{
	char s1[100] = "status ";
	strcat(s1, musicName);
	strcat(s1, " volume");
	char vo[20];
	char s2[100] = "setaudio ";
	strcat(s2, musicName);
	strcat(s2, " volume to ");
	char res[260];
	mciSendString(s1, res, 260, NULL);
	int volume = 0;
	volume = atoi(res);
	volume += 200;
	itoa(volume, vo, 10);
	strcat(s2, vo);
	mciSendString(s2, NULL, 0, NULL);
}
int getMusicLength(char* musicName)
{
	char s1[100] = "status ";
	char s3[100] = " length";
	char st[100];
	strcat_s(s1, musicName);
	strcat_s(s1, s3);
	mciSendString(s1, st, 100, 0);
	return atoi(st);
}
int chooseMusic(int index)
{
	int index0;
	playlist1();
	printf("��������ѡ���ֵ����\n");
	scanf_s("%d", &index0);
	index0 -= 1;
	while (index0 < 0 || index0>4)
	{
		printf("�����������������\n");
		scanf_s("%d", &index0);
		index0 -= 1;
	}
	stop(musicNames[index]);
	return index0;
}
void switch2()
{
	int state = -1;
	printf("��ѡ����Ҫ���ŵĸ���\n");
	playlist();
	int index;
	while (1)
	{
		scanf_s("%d", &index);
		Sleep(500);
		system("cls");
		index -= 1;
		if (0 <= index && index <= 4)
		{
			printf("��ѡ���˵�%d�׸�\n", index + 1);
			printf("%c\n", musicNames[index]);
			Number();
			play(musicNames[index]);
			break;
		}
		else if (index == 5)
		{
			switch (judge) {
			case'0':
				menu2();
				break;
			case'1':
				menu1();
				break;
			}
		}
		else
		{
			printf("ѡ�����������ѡ��\n");
			continue;
		}
	}
	menu3();
	while (state != 3)
	{
		scanf_s("%d", &state);
		switch (state)
		{
		case 1:
			printf("��ѡ����1��˳�򲥷ţ�����Ϊ��������ѡ�񲥷ŵĸ��������������׸�󽫻��˳�����һ���棩\n");
			playState = 0;
			play(musicNames[index]);
			break;
		case 2:
			printf("��ѡ����2;��ͣ���ٴ�ѡ��1���ɼ�������\n");
			pause(musicNames[index]);
			break;
		case 3:
			printf("��ѡ����3;����Ϊ���˻���һ�������嵥��������ѡ����Ҫ���ŵĸ���\n");
			stop(musicNames[index]);
			break;
		case 4:
			printf("��ѡ����4;����Ϊ��չʾ���ֲ����嵥\n");
			playlist1();
			break;
		case 5:
			printf("��ѡ����5;ѭ�����ţ���ǰΪѭ������ģʽ����ͨ����/��һ��ʵ��ѭ������\n");
			playState = 1;
			play(musicNames[index]);
			break;
		case 6:
			printf("��ѡ����6;������ţ���ǰΪ�������ģʽ����ͨ����/��һ��ʵ���������\n");
			playState = 2;
			play(musicNames[index]);
			break;
		case 7:
			printf("��ѡ����7;���\n");
			fastForward(musicNames[index]);
			printf("\n");
			break;
		case 8:
			printf("��ѡ����8������\n");
			rewind(musicNames[index]);
			printf("\n");
			break;
		case 9:
			printf("��ѡ����9;����Ϊ��������һ�׸���\n");
			if (playState == 0)
			{
				if (index > 0)
				{
					Number();
					playFrontMusic(index--);
				}
				else
				{
					state = 3;
					stop(musicNames[0]);
				}
			}
			else if (playState == 1)
			{
				playFrontMusic(index);
				index--;
				index = indexCorrect(index);
			}
			else if (playState == 2)
			{

				srand(time(0));
				int index0 = index;
				do {
					index = rand() % 5;
				} while (index == index0);
				stop(musicNames[index0]);
				play(musicNames[index]);
			}
			else if (playState == 3)
			{
				stop(musicNames[index]);
				play(musicNames[index]);
			}
			break;
		case 10:
			printf("��ѡ����10;����Ϊ��������һ�׸���\n");
			if (playState == 0)
			{
				if (index < 4)
				{
					Number();
					playNextMusic(index++);
				}
				else
				{
					state = 3;
					stop(musicNames[4]);
				}
			}
			else if (playState == 1)
			{
				playNextMusic(index);
				index++;
				index = indexCorrect(index);
			}
			else if (playState == 2)
			{

				srand(time(0));
				int index0 = index;
				do {
					index = rand() % 5;
				} while (index == index0);
				stop(musicNames[index0]);
				play(musicNames[index]);
			}
			else if (playState == 3)
			{
				stop(musicNames[index]);
				play(musicNames[index]);
			}
			break;
		case 11:
			printf("��ѡ����11;��������\n");
			downVolume(musicNames[index]);
			break;
		case 12:
			printf("��ѡ����12;�������\n");
			upVolume(musicNames[index]);
			break;
		case 13:
			printf("��ѡ����13;����ѭ������ǰΪ����ѭ������ģʽ\n");
			playState = 3;
			play(musicNames[index]);
			break;
		case 14:
			printf("��ѡ����14;ѡ��\n");
			index = chooseMusic(index);
			play(musicNames[index]);
			break;
		default:
			printf("�����������������\n");
			break;
		}
	}
	if (state == 3)
	{
		switch2();
	}
	return;
}