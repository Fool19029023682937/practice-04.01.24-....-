#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <tlhelp32.h>
#include <tchar.h>
#include <wchar.h>

#include <time.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

typedef enum {true, false}bool;

#define null NULL

#ifndef ENABLE_VIRTUAL_TERMINAL_PROCESSING
#define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004
#endif

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct spell{
char name[16];
int dmg;
float chance_to_miss;
};

void spell_dialog(HANDLE hConsole,int *boss_h,int *y){
	COORD cursorPosition = { 0, y + 1 };
	SetConsoleCursorPosition(hConsole, cursorPosition);
	
	time_t unix_timestamp = time(null);  // Replace with your desired timestamp
    struct tm *tm_info;
    tm_info = gmtime(&unix_timestamp);
	
	wprintf(L"[%d:%d] system: You can use: \n", (tm_info->tm_hour) + 3,  (tm_info->tm_min));
	wprintf(L"1. FIREBOLL \n");
	wprintf(L"2. KNIFETOMEETYOU!!\n");
	char select = getchar();
	
	switch(select){
		case '1': *boss_h -= 15;
		case '2': if(0.34 < (((float)rand()/(float)(0.99)) )){*boss_h -= 6;} break;
		
	}
	
}
//if(player_spell_1.chance_to_miss < (((float)rand()/(float)(0.99)) )){boss_h -= player_spell_1.dmg;} break;


void boss_bar_drw(HANDLE hConsole, int health, int y){
	COORD cursorPosition = { (85 / 2), 0 };
	SetConsoleCursorPosition(hConsole, cursorPosition);
	wprintf(L"\x1b[01;31m  BOSS \n"  ); 
	cursorPosition.X = 85 / 2 - 5;
	cursorPosition.Y = 1;
	SetConsoleCursorPosition(hConsole, cursorPosition);
	wprintf("\x1b[01;30m");
	printf("[");
	wprintf("\x1b[01;31m");
	int i = 0; 
	for(i = 0; i < (health / 10); i++ ){
		wprintf(L"\x1b[01;31m#");
	}
	if(health != 100){
		for(i = 0; i < (100 / 10 - (health / 10)); i++ ){
			wprintf(L"\x1b[01;30m#");	
		}	
			
	}
	wprintf(L"\x1b[02;30m");
	//cursorPosition.X = (85 / 2) - 5; 
	//SetConsoleCursorPosition(hConsole, cursorPosition);
	printf("]\n");
	
	wprintf(L"\x1b[02;00m");
	cursorPosition.X = 0; cursorPosition.Y = y;
	SetConsoleCursorPosition(hConsole, cursorPosition);
}

void bar_drw(HANDLE hConsole, int health, int y){
	COORD cursorPosition = { 0, 25 };
	SetConsoleCursorPosition(hConsole, cursorPosition);
    time_t unix_timestamp = time(null);  // Replace with your desired timestamp
    struct tm *tm_info;
    tm_info = gmtime(&unix_timestamp);
	wprintf(L"\x1b[01;30m[ [a] - attack [d] - defend [c] - cast spell"  ); 
	
	cursorPosition.X = 45; cursorPosition.Y = 25;
	SetConsoleCursorPosition(hConsole, cursorPosition);
	wprintf(L"\x1b[02;31m");
	printf("[");	
	int i; 
	for(i = 0; i < (health / 10); i++ ){
		printf("#");	
	}
	if(health != 100){
		for(i = 0; i < (100 / 10 - (health / 10)); i++ ){
			wprintf(L"\x1b[01;30m");
			printf("#");	
		}	
			
	}
	wprintf(L"\x1b[02;31m");
	cursorPosition.X = 55; 
	SetConsoleCursorPosition(hConsole, cursorPosition);
	printf("]");	
	cursorPosition.X = (85 - 22); 
	
	wprintf(L"\x1b[01;30m");
	SetConsoleCursorPosition(hConsole, cursorPosition);
	wprintf(L"      %d:%d pm.  ]", (tm_info->tm_hour) + 3,  (tm_info->tm_min)); 
	wprintf(L"\x1b[02;00m");
	cursorPosition.X = 0; cursorPosition.Y = y;
	SetConsoleCursorPosition(hConsole, cursorPosition);
}

int main(int argc, char *argv[]) {
srand((unsigned int)time(NULL));
//-------------------------------------------------------
//setting up the window:	
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SMALL_RECT windowSize = { 0, 0, 80, 25 };
	SetConsoleWindowInfo(hConsole, TRUE, &windowSize);
	COORD bufferSize = { 80, 25 };
	SetConsoleScreenBufferSize(hConsole, bufferSize);
	
	system("cls");
	WriteConsole(hConsole, "", 0, null, null);

	DWORD dwMode = 0;
	GetConsoleMode(hConsole, &dwMode);
	dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
	SetConsoleMode(hConsole, dwMode);
//-------------------------------------------------------
//data:	
struct spell player_spell_1 = {"fire boll", 45, 0.34};
struct spell boss_spell_1 = {"fire boll", 45, 0.34};
char act = 0;
int y = 2;
int health = 100;
int boss_h = 100;
//-------------------------------------------------------
usual:
	act = getchar();
	bar_drw(hConsole , health , y);	
	boss_bar_drw(hConsole , boss_h , y);
	switch(act){
		case 'a': boss_h -= 15; printf("hp %d \n", boss_h); break; 	
		case 'd': if(boss_spell_1.chance_to_miss < (((float)rand()/(float)(0.99)) )){health -= boss_spell_1.dmg;};	break;	
		case 'c': spell_dialog(hConsole, &boss_h, &y); y += 4;	break;	
	if (act != 'c'){
		health -= 24;
	}	
	}

	
	if(boss_h <= 0){
		COORD cursorPosition = { 0, 0 };
		SetConsoleCursorPosition(hConsole, cursorPosition);	

		cursorPosition.X = 11; cursorPosition.Y = 11;
		SetConsoleCursorPosition(hConsole, cursorPosition);
		wprintf(L"\x1b[01;30m You won the boss and drunked all the nigt... \n");
	while(1){
			cursorPosition.X = 0; cursorPosition.Y = 12;SetConsoleCursorPosition(hConsole, cursorPosition);
			wprintf(L"\x1b[01;31m HeRO tHat SAveD ThE WOrlD dIEd By AlCoHol. whats a shame :D \n");
			sleep(1); cursorPosition.X = 0; cursorPosition.Y = 12;SetConsoleCursorPosition(hConsole, cursorPosition);
			wprintf(L"\x1b[01;31m heRo ThaT saVEd tHE woRLd DiEd bY ALcOHOl. whats a shame :D \n");
			sleep(1);cursorPosition.X = 0; cursorPosition.Y = 12;SetConsoleCursorPosition(hConsole, cursorPosition);
			wprintf(L"\x1b[01;31m HerO tHat SAvEd The WOrld DiEd bY ALcOHOl. whats a shame :D \n");
			sleep(1);
	}
	}

	if(health <= 0){
		COORD cursorPosition = { 0, 0 };
		SetConsoleCursorPosition(hConsole, cursorPosition);	
	
		cursorPosition.X = 25; cursorPosition.Y = 12;
		SetConsoleCursorPosition(hConsole, cursorPosition);
			wprintf(L"\x1b[01;31m You died. Hah. It was a pretty lame, you know?");
			
	}
	
	goto usual;	
	return 0;
}
