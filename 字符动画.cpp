#include <stdio.h>					//此文件中定义了C语言的一些重要函数
#include <string.h>					//此文件中定义了C_字符函数
#include <stdlib.h>					//此文件中定义了编译器中的一些特殊函数
#include <Windows.h>    				//此文件中定义了系统窗口操作命令
#include <assert.h>					//断言
 
void gotoxy(int x, int y)
{
	COORD pos; pos.X = x - 1; pos.Y = y - 1;			//COORD  为 Windows.h 中定义的一个结构体
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
 
int main()
{
	system("color f0");				
	long i;								
	char FileName[100];					
	char hi[254000];					
	FILE *in;							
 
	system("C:\\Users\\15749\\Desktop\\workpace\\dance");	//打开视频或音频文件，
	Sleep(3000);						
 
	//放幻灯片，Sleep()函数调节播放速度
	for (i = 1; i <= 999; i++)	//i 的范围转换为(.txt)文件的个数
	{
		sprintf(FileName,
			"C:\\Users\\15749\\Desktop\\workpace\\txtpicture\\(%ld).txt", i);
 
		in = fopen(FileName, "r");
		assert(in != NULL);		
		fread(hi, 1, 254000, in);//改 ,这是你一个TXT文件里的字符串. 
		printf("%s\n%d", hi, i);
		gotoxy(1, 1);			
		Sleep(26);				//等待27毫秒执行
		fclose(in);
	}
}
