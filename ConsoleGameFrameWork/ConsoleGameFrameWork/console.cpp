#include "console.h"

int main() {
	lines = 10;
	cols = 100;
	Init(lines,cols,"������");//�Ű����� 3���� 3��
	draw();
	PlaySound(TEXT("Sym.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP | SND_NODEFAULT);// ����
	while (!GameOver) {
		Update();
	}
	Release();
	printf("���α׷� ����\n");
	return 0;
}

void Init(int lines, int cols, const char *title ="title") {
	sprintf(windowCommand, "mode con: lines=%d cols=%d", lines, cols); //�ܼ� ũ�� ����
	system(windowCommand);
	sprintf(windowCommand, "title %s", title); //�ܼ�â �̸� ����
	system(windowCommand);
	GameOver = false;
	onKey = 0;
}

void draw() {
	setPos(4, 5);
	printf("The music playing now is Clean Bandit - Symphony (cover by J.fla)");
	setPos(4, 6);
	printf("If you want exit, Press P Button to finish this program.");
	setPos(4, 7);
	printf("Please Enjoy Music, Thank you.");
}

void Update() {
	while (kbhit()) {		// kbhit() : ����Ű�� �˻��ϴ� �Լ�, ���� Ű�� ������ 1��ȯ, ������ 0 ��ȯ
		onKey = _getch();	// ����Ű�� �ִٸ� _getch()�� �̿��� ���� Ű�� ASCII ���� ����
		if (onKey == 'p')	// ���� Ű�� ������ ���ӿ����� ��
			Release();
	}
}

void Release() {
	PlaySound(NULL, NULL, NULL);
	GameOver = true;
}

void setPos(int x, int y)
{
	COORD POS = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), POS);
}

void setColor(int color, int bgcolor)
{
	color &= 0xf;
	bgcolor &= 0xf;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (bgcolor << 4) | color);
}