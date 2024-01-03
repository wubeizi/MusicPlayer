#ifndef _PLAYER_H_
#define _PLAYER_H_
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <windows.h>
#include <memory.h>
#include <Windows.h>
#include <mmsystem.h>
#include <time.h>
#include <sys/types.h> 
#include <iostream>
#include <thread>
#pragma comment(lib,"winmm.lib")
#define MAX_ID 11
#define MAX_PWD 20
#define MAX_NAME 15
#define MAX_SEX 5
#define MAX_PHONE 12
#define MAX_BIRTHDAY 20
#define MAX_NUMBER 15
#define MAX_NUMBER 15
void LoginMenu(); //初始界面实现
void menu(); //初始菜单打印
void switch1(); //初始菜单按钮选择
void Login(); //登录系统
void menu1(); //已登录用户的功能菜单打印
void Revise(); //用于修改个人信息
void Register(); //注册系统
void GuestLogin(); //游客登录
void menu2(); //游客用户功能菜单打印
void menu3(); //播放音乐时界面打印
void switch2(); //音乐菜单按钮选择
int indexCorrect(int index); //防止索引下标越界
void play(char* musicName); //音乐播放
void pause(char* musicName); //音乐暂停
void stop(char* musicName); //音乐停止，自动跳至上一级
void fastForward(char* musicName); //快进15秒
void rewind(char* musicName); //快退15秒
void playFrontMusic(int index); //播放上一首
void playNextMusic(int index); //播放下一首
void playlist(); //选择列表
void playlist1(); //歌单列表
int getPosition(char* musicName); //得到音乐当前播放到的位置
void downVolume(char* musicName); //调小音量
void upVolume(char* musicName); //调大音量
int getMusicLength(char* musicName); //得到音乐总时长
int chooseMusic(int index); //根据歌单选择要播放的音乐的序号
void Number(); //读取实际听取歌曲的数量
char* msTomin(int ms); //将毫秒数转化为“min:s”的形式
extern char judge; //用于判断返回哪一个次级菜单
typedef struct Users
{
	char id[MAX_ID];
	char pwd[MAX_PWD];
	char name[MAX_NAME];
	char sex[MAX_SEX];
	char phone[MAX_PHONE];
	char songs_Number[MAX_NUMBER];
	int  number;
};
#endif