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
void LoginMenu(); //��ʼ����ʵ��
void menu(); //��ʼ�˵���ӡ
void switch1(); //��ʼ�˵���ťѡ��
void Login(); //��¼ϵͳ
void menu1(); //�ѵ�¼�û��Ĺ��ܲ˵���ӡ
void Revise(); //�����޸ĸ�����Ϣ
void Register(); //ע��ϵͳ
void GuestLogin(); //�ο͵�¼
void menu2(); //�ο��û����ܲ˵���ӡ
void menu3(); //��������ʱ�����ӡ
void switch2(); //���ֲ˵���ťѡ��
int indexCorrect(int index); //��ֹ�����±�Խ��
void play(char* musicName); //���ֲ���
void pause(char* musicName); //������ͣ
void stop(char* musicName); //����ֹͣ���Զ�������һ��
void fastForward(char* musicName); //���15��
void rewind(char* musicName); //����15��
void playFrontMusic(int index); //������һ��
void playNextMusic(int index); //������һ��
void playlist(); //ѡ���б�
void playlist1(); //�赥�б�
int getPosition(char* musicName); //�õ����ֵ�ǰ���ŵ���λ��
void downVolume(char* musicName); //��С����
void upVolume(char* musicName); //��������
int getMusicLength(char* musicName); //�õ�������ʱ��
int chooseMusic(int index); //���ݸ赥ѡ��Ҫ���ŵ����ֵ����
void Number(); //��ȡʵ����ȡ����������
char* msTomin(int ms); //��������ת��Ϊ��min:s������ʽ
extern char judge; //�����жϷ�����һ���μ��˵�
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