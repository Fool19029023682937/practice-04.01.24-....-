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

void bar_drw(HANDLE hConsole, int g, int c, int y){
	COORD cursorPosition = { 0, 25 };
	SetConsoleCursorPosition(hConsole, cursorPosition);
	
    time_t unix_timestamp = time(null);  // Replace with your desired timestamp
    struct tm *tm_info;
    tm_info = gmtime(&unix_timestamp);
	wprintf(L"\x1b[02;32m[  gold: %d  |  crystals: %d  [b] - buy crystals  [i] - info         %d:%d pm.   ]", g, c ,  (tm_info->tm_hour) + 3,  (tm_info->tm_min)); 

	wprintf(L"\x1b[02;00m");
	cursorPosition.X = 0; cursorPosition.Y = y;
	SetConsoleCursorPosition(hConsole, cursorPosition);
}
void inf_drw(HANDLE hConsole, int g, int c){
    time_t unix_timestamp = time(null);  // Replace with your desired timestamp
    struct tm *tm_info;
    tm_info = gmtime(&unix_timestamp);
	wprintf(L"[%d:%d] merchant: i have %d gold and %d crystals. \n", (tm_info->tm_hour) + 3,  (tm_info->tm_min),  g - 10,  c );
}

void buy_dialog_drw(HANDLE hConsole, int *g, int *c, int *g2, int *c2){
    time_t unix_timestamp = time(null);  // Replace with your desired timestamp
    struct tm *tm_info;
    tm_info = gmtime(&unix_timestamp);
	int crystals_req = 0;
	
	wprintf(L"[%d:%d] you: wanna buy crystals. pc's:  ", (tm_info->tm_hour) + 3,  (tm_info->tm_min)); 
	

	char s[8];
	scanf("%s", &s); crystals_req = atoi(s);
	
	
	printf("\n");
	
	int payement = ( (int)((3.4 * crystals_req ) / 1));
	
	if(crystals_req <=  *c2){
		printf("> o-kay. it'll cost: %d golds \n", payement);
		
		if ( payement <= *g){
			printf("> here you are.  \n");
			wprintf(L"[%d:%d] system: spent %d, bought %d crystals.. \n", (tm_info->tm_hour) + 3,  (tm_info->tm_min), payement, crystals_req); 
			
			 *g = *g - payement;
			 *c = *c + crystals_req;
			 
			 *g2 = *g2 + payement;
			 *c2 = *c2 - crystals_req;
			
		}else{
			printf("> sry. it's not enough. come back later((( \n");
		}
	
	}else{
		printf("> sry. i havent enough. come back later((( \n");
	}
	
}


int main(int argc, char *argv[]) {
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
	int y = 0;

	char act = 'n';
	int your_gold = 35;
	int your_crystals = 2;
	int merchant_crystals = 200;
	int merchant_gold = 25;
//-------------------------------------------------------
usual:
	act = getchar();
	bar_drw(hConsole , your_gold ,your_crystals, y);	
	
	switch(act){
		case 'i': 	inf_drw(hConsole ,merchant_gold ,merchant_crystals); y++;	break;	
		case 'b': 	buy_dialog_drw(hConsole , &your_gold , &your_crystals,&merchant_gold, &merchant_crystals ); y += 5;	break;
		
		
	}

	goto usual;	
	return 0;
}
