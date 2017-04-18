#include <stdio.h>
#include <conio.h>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")
#pragma once
// Ű���� Ű ASCII �� ����
#define LEFT 75 
#define RIGHT 77 
#define UP  72 
#define DOWN 80 
#define SPACE 32
#define ESC 27
#define ENTER 13

#define COMMAND_SIZE 256
using namespace std;

bool GameOver;	// ���� ���� üũ
char onKey;		// �Է��� Ű�� ����
char windowCommand[COMMAND_SIZE] = { '\0', }; //������ �Լ� Ŀ�ǵ�
int lines; //�ܼ�â ����
int cols; // �ܼ�â ����
void Init(int lines, int cols, const char *title); // �ʱ�ȭ
void draw();
void Update();	// ������Ʈ
void Release();	// �޸� ����
void setPos(int x, int y);				// ��ġ ����
void setColor(int color, int bgcolor);	// �� ����
time_t start, end;
enum {	// ���� ����
	Black,		// 0
	DarkBlue,	// 1
	DarkGreen,	// 2
	DarkSkyBlue,// 3
	DarkRed,	// 4
	DarkViolet,	// 5
	DarkYellow,	// 6
	Gray,		// 7
	DarkGray,	// 8
	Blue,		// 9
	Green,		// 10
	SkyBlue,	// 11
	Red,		// 12
	Violet,		// 13
	Yellow,		// 14
	White		// 15
};