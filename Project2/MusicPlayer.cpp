#include"PLAYER.h"
#include <iostream>
#include <thread>
char musicNames[5][100] = { ".\\music\\粉色海洋.mp3",".\\music\\还在流浪.mp3",".\\music\\红颜如霜.mp3",".\\music\\我是如此相信.mp3",".\\music\\最伟大的作品.mp3" };
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
	printf("\t\t\t\t╔═════════════════════════════════════════════════════════════════╗\n");
	printf("\t\t\t\t║                                                                 ║\n");
	printf("\t\t\t\t║     *1.顺序播放               *2.暂停                           ║\n");
	printf("\t\t\t\t║                                                                 ║\n");
	printf("\t\t\t\t║     *3.停止                   *4.展示歌单                       ║\n");
	printf("\t\t\t\t║                                                                 ║\n");
	printf("\t\t\t\t║     *5.循环播放               *6.随机播放                       ║\n");
	printf("\t\t\t\t║                                                                 ║\n");
	printf("\t\t\t\t║     *7.快进                   *8.快退                           ║\n");
	printf("\t\t\t\t║                                                                 ║\n");
	printf("\t\t\t\t║     *9.上一首                 *10.下一首                        ║\n");
	printf("\t\t\t\t║                                                                 ║\n");
	printf("\t\t\t\t║     *11.降低音量              *12.提高音量                      ║\n");
	printf("\t\t\t\t║                                                                 ║\n");
	printf("\t\t\t\t║     *13.单曲循环              *14.选歌                          ║\n");
	printf("\t\t\t\t║                                                                 ║\n");
	printf("\t\t\t\t╚═════════════════════════════════════════════════════════════════╝\n");
}
void playlist()
{
	printf("\t\t\t\t╔═════════════════════════════════════════════════════════════════╗\n");
	printf("\t\t\t\t║                                                                 ║\n");
	printf("\t\t\t\t║      1. 周杰伦 - 粉色海洋                                       ║\n");
	printf("\t\t\t\t║                                                                 ║\n");
	printf("\t\t\t\t║      2. 周杰伦 - 还在流浪                                       ║\n");
	printf("\t\t\t\t║                                                                 ║\n");
	printf("\t\t\t\t║      3. 周杰伦 - 红颜如霜                                       ║\n");
	printf("\t\t\t\t║                                                                 ║\n");
	printf("\t\t\t\t║      4. 周杰伦 - 我是如此相信                                   ║\n");
	printf("\t\t\t\t║                                                                 ║\n");
	printf("\t\t\t\t║      5. 周杰伦 - 最伟大的作品			                  ║\n");
	printf("\t\t\t\t║                                                                 ║\n");
	printf("\t\t\t\t║      6. 退出到上一级                                            ║\n");
	printf("\t\t\t\t║                                                                 ║\n");
	printf("\t\t\t\t╚═════════════════════════════════════════════════════════════════╝\n");
}
void playlist1()
{
	printf("\t\t\t\t╔═════════════════════════════════════════════════════════════════╗\n");
	printf("\t\t\t\t║                                                                 ║\n");
	printf("\t\t\t\t║      1. 周杰伦 - 粉色海洋                                       ║\n");
	printf("\t\t\t\t║                                                                 ║\n");
	printf("\t\t\t\t║      2. 周杰伦 - 还在流浪                                       ║\n");
	printf("\t\t\t\t║                                                                 ║\n");
	printf("\t\t\t\t║      3. 周杰伦 - 红颜如霜                                       ║\n");
	printf("\t\t\t\t║                                                                 ║\n");
	printf("\t\t\t\t║      4. 周杰伦 - 我是如此相信                                   ║\n");
	printf("\t\t\t\t║                                                                 ║\n");
	printf("\t\t\t\t║      5. 周杰伦 - 最伟大的作品			                  ║\n");
	printf("\t\t\t\t║                                                                 ║\n");
	printf("\t\t\t\t╚═════════════════════════════════════════════════════════════════╝\n");
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
	char s1[100] = "您从 ";
	char* s2 = msTomin(position);
	strcat(s1, s2);
	position += 15000;
	_itoa_s(position, file2, 10);
	strcat_s(file1, file2);
	mciSendString(file1, st, 100, 0);
	play(musicName);
	char s3[100] = " 快进到了 ";
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
	char s1[100] = "您从 ";
	char* s2 = msTomin(position);
	strcat(s1, s2);
	position -= 15000;
	_itoa_s(position, file2, 10);
	strcat_s(file1, file2);
	mciSendString(file1, st, 100, 0);
	play(musicName);
	char s3[100] = " 快退到了 ";
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
	printf("请输入所选音乐的序号\n");
	scanf_s("%d", &index0);
	index0 -= 1;
	while (index0 < 0 || index0>4)
	{
		printf("输入错误，请重新输入\n");
		scanf_s("%d", &index0);
		index0 -= 1;
	}
	stop(musicNames[index]);
	return index0;
}
void switch2()
{
	int state = -1;
	printf("请选择需要播放的歌曲\n");
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
			printf("你选择了第%d首歌\n", index + 1);
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
			printf("选择错误，请重新选择\n");
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
			printf("您选择了1；顺序播放，即将为您播放你选择播放的歌曲（播放完五首歌后将会退出至上一界面）\n");
			playState = 0;
			play(musicNames[index]);
			break;
		case 2:
			printf("您选择了2;暂停，再次选择1即可继续播放\n");
			pause(musicNames[index]);
			break;
		case 3:
			printf("您选择了3;即将为您退回上一级音乐清单，请重新选择需要播放的歌曲\n");
			stop(musicNames[index]);
			break;
		case 4:
			printf("您选择了4;即将为您展示音乐播放清单\n");
			playlist1();
			break;
		case 5:
			printf("您选择了5;循环播放，当前为循环播放模式，可通过上/下一首实现循环播放\n");
			playState = 1;
			play(musicNames[index]);
			break;
		case 6:
			printf("您选择了6;随机播放，当前为随机播放模式，可通过上/下一首实现随机播放\n");
			playState = 2;
			play(musicNames[index]);
			break;
		case 7:
			printf("您选择了7;快进\n");
			fastForward(musicNames[index]);
			printf("\n");
			break;
		case 8:
			printf("您选择了8；快退\n");
			rewind(musicNames[index]);
			printf("\n");
			break;
		case 9:
			printf("您选择了9;即将为您播放上一首歌曲\n");
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
			printf("您选择了10;即将为您播放下一首歌曲\n");
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
			printf("您选择了11;降低音量\n");
			downVolume(musicNames[index]);
			break;
		case 12:
			printf("您选择了12;提高音量\n");
			upVolume(musicNames[index]);
			break;
		case 13:
			printf("您选择了13;单曲循环，当前为单曲循环播放模式\n");
			playState = 3;
			play(musicNames[index]);
			break;
		case 14:
			printf("您选择了14;选歌\n");
			index = chooseMusic(index);
			play(musicNames[index]);
			break;
		default:
			printf("输入错误，请重新输入\n");
			break;
		}
	}
	if (state == 3)
	{
		switch2();
	}
	return;
}