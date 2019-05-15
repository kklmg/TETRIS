#include <windows.h>
#include "GraphicEngine.h"
#include"block.h"
#include"map.h"
#include<time.h>
#include"Button.h"
#include"function.h"
#include"object.h"

/////////////

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

void ___aInit(HDC hdc);
void ___aDestroyAll();

HINSTANCE g_hInst;
HWND hWndMain;
LPSTR lpszClass = "tetris -_-;";

SURFACEINFO g_sfBack;			
			
//	

SURFACEINFO g_sfBlank;

SURFACEINFO g_sfMonster_red;
SURFACEINFO g_sfMonster_blue;
SURFACEINFO g_sfMonster_yellow;

SURFACEINFO g_sfMonster_red_dead;
SURFACEINFO g_sfMonster_blue_dead;
SURFACEINFO g_sfMonster_yellow_dead;

SURFACEINFO g_sfCoin;
SURFACEINFO g_sfThunder;
SURFACEINFO g_sfBomb;
SURFACEINFO g_sfBomb_dead;
SURFACEINFO g_sfblank_d;

SURFACEINFO g_sfBall;
SURFACEINFO g_sfTitle;
SURFACEINFO g_sfCount[3];
SURFACEINFO g_sfPause;
SURFACEINFO g_sfGameover;
SURFACEINFO g_sfVictory;


SURFACEINFO g_sfBacg;

SURFACEINFO g_sfBacg_Thunder;
SURFACEINFO g_sfBacg_ThunderBall;
SURFACEINFO g_sfBacg_UltBomb;
SURFACEINFO g_sfBacg_Victory;
SURFACEINFO g_sfBacg_GameOver;

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance
	, LPSTR lpszCmdParam, int nCmdShow)
{
	HWND hWnd;
	MSG msg;
	WNDCLASS WndClass;
	g_hInst = hInstance;

	WndClass.cbClsExtra = 0;
	WndClass.cbWndExtra = 0;
	WndClass.hbrBackground = (HBRUSH)GetStockObject(NULL_BRUSH);
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	WndClass.hInstance = hInstance;
	WndClass.lpfnWndProc = (WNDPROC)WndProc;
	WndClass.lpszClassName = lpszClass;
	WndClass.lpszMenuName = NULL;
	WndClass.style = CS_HREDRAW | CS_VREDRAW;

	RegisterClass(&WndClass);

	hWnd = CreateWindow(lpszClass, lpszClass, WS_SYSMENU | WS_CAPTION, //WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, 1000, 1000,
		NULL, (HMENU)NULL, hInstance, NULL);
	ShowWindow(hWnd, nCmdShow);
	hWndMain = hWnd;

	while (1)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_NOREMOVE))
		{
			if (!GetMessage(&msg, NULL, 0, 0)) return (int)msg.wParam;
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		//else 
		
	}
	return (int)msg.wParam;
}


//// 일괄 표면 생성 
void ___aInit(HDC hdc)
{
	__geSetImgSurface(&g_sfBlank);
	g_sfBlank.hBmp = __geBmpFile2BmpHandle("background.bmp");
	__geLoadSurface(hdc, &g_sfBlank);


	////
	__geSetSprSurface(&g_sfMonster_red, RGB(255, 255, 255));
	g_sfMonster_red.hBmp = __geBmpFile2BmpHandle("monster_red.bmp");
	__geLoadSurface(hdc, &g_sfMonster_red);

	__geSetSprSurface(&g_sfMonster_blue, RGB(255, 255, 255));
	g_sfMonster_blue.hBmp = __geBmpFile2BmpHandle("monster_blue.bmp");
	__geLoadSurface(hdc, &g_sfMonster_blue);

	__geSetSprSurface(&g_sfMonster_yellow, RGB(255, 255, 255));
	g_sfMonster_yellow.hBmp = __geBmpFile2BmpHandle("monster_yellow.bmp");
	__geLoadSurface(hdc, &g_sfMonster_yellow);

	__geSetSprSurface(&g_sfMonster_red_dead, RGB(255, 255, 255));
	g_sfMonster_red_dead.hBmp = __geBmpFile2BmpHandle("monster_red_dead.bmp");
	__geLoadSurface(hdc, &g_sfMonster_red_dead);

	__geSetSprSurface(&g_sfMonster_blue_dead, RGB(255, 255, 255));
	g_sfMonster_blue_dead.hBmp = __geBmpFile2BmpHandle("monster_blue_dead.bmp");
	__geLoadSurface(hdc, &g_sfMonster_blue_dead);

	__geSetSprSurface(&g_sfMonster_yellow_dead, RGB(255, 255, 255));
	g_sfMonster_yellow_dead.hBmp = __geBmpFile2BmpHandle("monster_yellow_dead.bmp");
	__geLoadSurface(hdc, &g_sfMonster_yellow_dead);



	__geSetSprSurface(&g_sfCoin, RGB(255, 255, 255));
	g_sfCoin.hBmp = __geBmpFile2BmpHandle("coin.bmp");
	__geLoadSurface(hdc, &g_sfCoin);

	__geSetSprSurface(&g_sfThunder, RGB(255, 255, 255));
	g_sfThunder.hBmp = __geBmpFile2BmpHandle("Thunder.bmp");
	__geLoadSurface(hdc, &g_sfThunder);





	__geSetSprSurface(&g_sfBacg, RGB(255, 255, 255));
	g_sfBacg.hBmp = __geBmpFile2BmpHandle("bacg.bmp");
	__geLoadSurface(hdc, &g_sfBacg);

	__geSetSprSurface(&g_sfBall, RGB(255, 255, 255));
	g_sfBall.hBmp = __geBmpFile2BmpHandle("ball.bmp");
	__geLoadSurface(hdc, &g_sfBall);

	__geSetSprSurface(&g_sfTitle, RGB(255, 255, 255));
	g_sfTitle.hBmp = __geBmpFile2BmpHandle("title.bmp");
	__geLoadSurface(hdc, &g_sfTitle);
	////////////////



	__geSetSprSurface(&g_sfCount[0], RGB(255, 255, 255));
	g_sfCount[0].hBmp = __geBmpFile2BmpHandle("count_1.bmp");
	__geLoadSurface(hdc, &g_sfCount[0]);

	__geSetSprSurface(&g_sfCount[1], RGB(255, 255, 255));
	g_sfCount[1].hBmp = __geBmpFile2BmpHandle("count_2.bmp");
	__geLoadSurface(hdc, &g_sfCount[1]);

	__geSetSprSurface(&g_sfCount[2], RGB(255, 255, 255));
	g_sfCount[2].hBmp = __geBmpFile2BmpHandle("count_3.bmp");
	__geLoadSurface(hdc, &g_sfCount[2]);

	__geSetSprSurface(&g_sfBomb, RGB(255, 255, 255));
	g_sfBomb.hBmp = __geBmpFile2BmpHandle("Bomb.bmp");
	__geLoadSurface(hdc, &g_sfBomb);

	__geSetSprSurface(&g_sfBomb_dead, RGB(255, 255, 255));
	g_sfBomb_dead.hBmp = __geBmpFile2BmpHandle("Bomb_dead.bmp");
	__geLoadSurface(hdc, &g_sfBomb_dead);

	__geSetSprSurface(&g_sfPause, RGB(255, 255, 255));
	g_sfPause.hBmp = __geBmpFile2BmpHandle("Pause.bmp");
	__geLoadSurface(hdc, &g_sfPause);

	__geSetSprSurface(&g_sfGameover, RGB(255, 255, 255));
	g_sfGameover.hBmp = __geBmpFile2BmpHandle("gameover.bmp");
	__geLoadSurface(hdc, &g_sfGameover);

	__geSetSprSurface(&g_sfBacg_Thunder, RGB(255, 255, 255));
	g_sfBacg_Thunder.hBmp = __geBmpFile2BmpHandle("thunder_bacg1.bmp");
	__geLoadSurface(hdc, &g_sfBacg_Thunder);

	__geSetSprSurface(&g_sfBacg_ThunderBall, RGB(255, 255, 255));
	g_sfBacg_ThunderBall.hBmp = __geBmpFile2BmpHandle("thunder_bacg.bmp");
	__geLoadSurface(hdc, &g_sfBacg_ThunderBall);

	__geSetSprSurface(&g_sfBacg_UltBomb, RGB(255, 255, 255));
	g_sfBacg_UltBomb.hBmp = __geBmpFile2BmpHandle("blast_bacg.bmp");
	__geLoadSurface(hdc, &g_sfBacg_UltBomb);

	__geSetSprSurface(&g_sfVictory, RGB(255, 255, 255));
	g_sfVictory.hBmp = __geBmpFile2BmpHandle("victory.bmp");
	__geLoadSurface(hdc, &g_sfVictory);

	__geSetSprSurface(&g_sfBacg_Victory, RGB(255, 255, 255));
	g_sfBacg_Victory.hBmp = __geBmpFile2BmpHandle("victory_bacg.bmp");
	__geLoadSurface(hdc, &g_sfBacg_Victory);
	
	__geSetSprSurface(&g_sfBacg_GameOver, RGB(255, 255, 255));
	g_sfBacg_GameOver.hBmp = __geBmpFile2BmpHandle("gameover_bacg.bmp");
	__geLoadSurface(hdc, &g_sfBacg_GameOver);

}

//// 일괄 표면 파괴
void ___aDestroyAll()
{	
	__geReleaseSurface(&g_sfBlank);
	__geReleaseSurface(&g_sfBack);
	__geReleaseSurface(&g_sfMonster_red);
	__geReleaseSurface(&g_sfMonster_blue);
	__geReleaseSurface(&g_sfMonster_yellow);
	__geReleaseSurface(&g_sfThunder);
	__geReleaseSurface(&g_sfCoin);	
}

/////////client /////////
int nClientWidth ;
int nClientHeight ;
POINT nClientcenter;

/////////block/map length///////
int nBlockLength=50;

//map//
map *OB_map;
int grid_column;
int grid_row;
//////////////////////////////////////////////////
/////////////////////block////////////////////////
//////////////////////////////////////////////////
//setblock
block *currentblock;
block *nextblock;
block *virtualblock;

//block-TYPE
#define blank  0
#define monster_red 1
#define monster_blue 2
#define monster_yellow 3
#define coin  4
#define thunder 5
#define bomb 6
#define monster_red_dead 7
#define monster_blue_dead 8
#define monster_yellow_dead 9
#define bomb_dead 10
#define blank_d 11
#define dff 12

int red_weight;
int blue_weight;
int yellow_weight;
int coin_weight;
int thuender_weight;
int bomb_weight;
int __randblocktype(int red, int blue, int yellow) {
	/*if nMonsterRed, nMonsterBlue, nMonsterYellow;*/
	if (red > 0 && blue > 0 && yellow > 0) {
		int i = rand() % 100;
		if (i < 30 && i >= 0) {
			return monster_red;
		}
		else if (i < 50 && i >= 30) {
			return monster_blue;
		}
		else if (i < 70 && i >= 50) {
			return monster_yellow;
		}
		else if (i < 80 && i >= 70) {
			return coin;
		}
		else if (i < 90 && i >= 80) {
			return thunder;
		}
		else if (i < 100 && i >= 90) {
			return bomb;
		}
	}
	if (red > 0 && blue > 0 && yellow <= 0) {
		int i = rand() % 100;
		if (i < 40 && i >= 0) {
			return monster_red;
		}
		else if (i < 70 && i >= 40) {
			return monster_blue;
		}
		else if (i < 80 && i >= 70) {
			return coin;
		}
		else if (i < 90 && i >= 80) {
			return thunder;
		}
		else if (i < 100 && i >= 90) {
			return bomb;
		}
	}
	if (red > 0 && blue <= 0 && yellow <= 0) {
		int i = rand() % 100;
		if (i < 50 && i >= 0) {
			return monster_red;
		}
		else if (i < 60 && i >= 50) {
			return coin;
		}
		else if (i < 80 && i >= 60) {
			return thunder;
		}
		else if (i < 100 && i >= 80) {
			return bomb;
		}
	}
	if (red <= 0 && blue > 0 && yellow > 0) {
		int i = rand() % 100;
		if (i < 30 && i >= 0) {
			return monster_blue;
		}
		else if (i < 60 && i >= 30) {
			return monster_yellow;
		}
		else if (i < 70 && i >= 60) {
			return coin;
		}
		else if (i < 85 && i >= 70) {
			return thunder;
		}
		else if (i < 100 && i >= 85) {
			return bomb;
		}
	}
	if (red <= 0 && blue > 0 && yellow <= 0) {
		int i = rand() % 100;
		if (i < 60 && i >= 0) {
			return monster_blue;
		}
		else if (i < 70 && i >= 60) {
			return coin;
		}
		else if (i < 85 && i >= 70) {
			return thunder;
		}
		else if (i < 100 && i >= 85) {
			return bomb;
		}






	}
	if (red <= 0 && blue <= 0 && yellow > 0) {
		int i = rand() % 100;
		if (i < 60 && i >= 0) {
			return monster_yellow;
		}
		else if (i < 70 && i >= 60) {
			return coin;
		}
		else if (i < 85 && i >= 70) {
			return thunder;
		}
		else if (i < 100 && i >= 85) {
			return bomb;
		}






	}
}
//score,level,coin.......//
int score, level;
static int n_coin;
int nMonsterRed, nMonsterBlue, nMonsterYellow;
int nThunder;

TCHAR buffMonsterRed[20];
TCHAR buffMonsterBlue[20];
TCHAR buffMonsterYellow[20];
TCHAR buffThunder[20];
TCHAR buffscore[20];
TCHAR bufflevel[20];
TCHAR buffcoin[20];

//animation frame//
int thunder_frame;
int monster_frame;
int bomb_frame;
int monster_dead_frame;
int bomb_dead_frame;

///////////////game state////////////////

int gamestate;

//gamestate
#define pause 0
#define ready 4
#define running 1
#define title 2
#define useSkill 3
#define gameover 5
#define gamesetting 6
#define victory 7
//count down//
int GameReadyCount;
int BlockVanishCount;

//button//
button *butt_start;
button *butt_back;
button *butt_pause;
button *butt_exit;
button *butt_SkillThunder;
button *butt_SkillThunderBall;
button *butt_SkillUltBomb;
button *butt_back02;
button *butt_continue;
//skill//
ball *skillball;

int skilltype;
#define sk_Thunder 1
#define sk_ThunderBall 2
#define sk_UltBomb 3
bool TriggarThunder;
bool TriggarUltbomb;
bool TriggarCoin;
int Thunder_amount;
void __KeyProc(HWND hWnd);
////////////////timer/////////////
//Game UI 0~9
#define display_bg 0
#define GameUI 1
#define gamereadycount 2

#define CreateTimer_GameUI SetTimer(hWnd, GameUI, 1000 / 60, NULL);
#define DeleteTimer_GameUI 
#define CreateTimer_DisplayBackground SetTimer(hWnd, display_bg, 1000 / 60, NULL);
#define CreateTimer_BlockAnimation SetTimer(hWnd, block_ani, 150, NULL);
#define CreateTimer_BlockFall SetTimer(hWnd, blockfall, 300 - Block_speed, NULL);
#define CreateTimer_CheckBottom SetTimer(hWnd, checkbottom, 16, NULL);

//Game Function 10~19
#define blockfall 10
#define checkbottom 11
#define saveobstacle 12
#define removeline 13
#define Initblock 14
#define skill_proc 15
#define CreateThunder 16
#define skill_UI 17
#define skill_ani 18
#define skill_create 19
//Game Ani 20~29
#define block_ani 20
#define blockvanishcount 21
#define removeblock_ani01 22
#define removeblock_ani02 23
/////////////////
//SetTimer(hWnd, display_bg, 1000 / 60, NULL);
//SetTimer(hWnd, GameUI, 1000 / 60, NULL);
//SetTimer(hWnd, block_ani, 150, NULL);
//SetTimer(hWnd, blockfall, 300 - level * 30, NULL);
//SetTimer(hWnd, checkbottom, 16, NULL);

/////////////////

static int nBgY;
POINT skill_ball;
int ballmove_x;
int ballmove_y;
object *skill_thunder;
object *abc;
object *bcd;
bool *Timer_on;
POINT MousePoint;
object **Ob_Thunder;
int skill_lasttime;
int Block_speed;
bool b_fullline;
bool b_FulllineBycoin;
bool block_arrivebottom;
HFONT oldfont;
HFONT newfont;

void resetgame() {
	score = 0;
	level = 0;
	n_coin = 0;
	nMonsterBlue = 200;
	nMonsterRed = 300;
	nMonsterYellow = 100;
	nThunder = 0;	
	Block_speed = 0;
}
void resetmap(int __row,int __column) {
	grid_column = __column;
	grid_row = __row;
	OB_map = new map(250, 10, grid_row, grid_column, nBlockLength);
}
void resetblockstate() {
	//set first current block situation
	currentblock->position_TL[0].x = OB_map->nLeftWall_x + 4 * nBlockLength;
	currentblock->position_TL[0].y = OB_map->nTopWall_y + nBlockLength;
	//set nextblock display situation
	nextblock->position_TL[0].x = 820;
	nextblock->position_TL[0].y = 370;
	//////////set first block status///////////
	//set current block type,style,state
	block_arrivebottom = false;
	currentblock->type = __randblocktype(nMonsterRed, nMonsterBlue, nMonsterYellow);
	currentblock->style = rand() % 7 + 1;
	currentblock->state = 0;
	currentblock->updatestock(OB_map);
	//set next block type&style
	nextblock->style = rand() % 7 + 1;
	nextblock->type = __randblocktype(nMonsterRed, nMonsterBlue, nMonsterYellow);
	nextblock->state = 0;
	nextblock->updatestock(OB_map);

}
void UseSkill_Thunder(int time,int amount) {
	

}
LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC backdc, hdc;
	PAINTSTRUCT ps;
	HBITMAP newbmp, oldbmp;
	
	
	switch (iMessage)
	{
		////set default state
		////////////////
	case WM_CREATE:{

		//Load graphic imagine	
		hdc = GetDC(hWnd);
		___aInit(hdc);
		ReleaseDC(hWnd, hdc);

		srand((unsigned)time(NULL));

		//game score/coin/level
		resetgame();
		//create map
		resetmap(18, 10);
		//create block
		currentblock = new block;
		nextblock = new block;		
		//set default game state
		gamestate = title;
		//set map&block length		
		currentblock->block_length = nBlockLength;
		nextblock->block_length = nBlockLength;

		//set block state
		resetblockstate();

		
		//set default obstacle
		//OB_map->grid[5][6] = 5;

		//anime frame
		thunder_frame = 0;
		monster_frame = 0;
		bomb_frame = 0;
		monster_dead_frame = 0;
		bomb_dead_frame = 0;
		
		ballmove_x = 10;
		ballmove_y = 10;

		//create basic game timer	
		CreateTimer_GameUI
		CreateTimer_DisplayBackground
		CreateTimer_BlockAnimation
		if(Block_speed>=275) Block_speed = level * 30;
		CreateTimer_BlockFall 
		CreateTimer_CheckBottom 

		//////
		Timer_on = new bool[20];
		for (int i = 0; i < 20; i++) {
			Timer_on[i] = false;
		}
		
		skill_ball.x = OB_map->nLeftWall_x + 4 * nBlockLength;;
		skill_ball.y = 200;
		GameReadyCount = 2;
		skill_lasttime = 0;
		b_fullline = false;
		b_FulllineBycoin = false;
	}
				   TriggarThunder = false;
				   TriggarUltbomb = false;
				   TriggarCoin = false;
		return 0;
	case WM_SIZE: {
		nClientWidth = LOWORD(lParam); // width of client area
		nClientHeight = HIWORD(lParam); // height of client area
		nClientcenter.x = nClientWidth / 2;
		nClientcenter.y = nClientHeight /2;

		hdc = GetDC(hWnd);
		
		butt_start = new button(nClientcenter.x, nClientcenter.y-100, hdc, "start.bmp", "start_1.bmp", RGB(255, 255, 255));
		butt_back = new button(70, 80, hdc, "back_0.bmp", "back_1.bmp", RGB(255, 255, 255));
		butt_back02 = new button(nClientcenter.x, nClientcenter.y + 110, hdc, "back2_0.bmp", "back2_1.bmp", RGB(255, 255, 255));
		butt_continue = new button(nClientcenter.x, nClientcenter.y , hdc, "continue_0.bmp", "continue_1.bmp", RGB(255, 255, 255));
	    butt_pause = new button(120, 800, hdc, "pause_0.bmp", "pause_1.bmp" ,RGB(255, 255, 255));
		butt_exit= new button(nClientcenter.x, nClientcenter.y+100, hdc, "exit_0.bmp", "exit_1.bmp", RGB(255, 255, 255));
		butt_SkillThunder = new button(850, 500, hdc, "thunder_0.bmp", "thunder_1.bmp", RGB(255, 255, 255));
		butt_SkillThunderBall = new button(850, 650, hdc, "ball_0.bmp", "ball_1.bmp", RGB(255, 255, 255));
		butt_SkillUltBomb = new button(850, 800, hdc, "bomb_0.bmp", "bomb_1.bmp", RGB(255, 255, 255));
	//	skill_thunder = new object(500, 0, hdc, "thunder-O.bmp", RGB(255, 255, 255), 20);
		abc= new object(0, 0, hdc, "thunder-O.bmp", RGB(255, 255, 255), 20,OB_map);		
		skillball = new ball(600, 200, hdc, "ball.bmp", RGB(255, 255, 255));
		
		ReleaseDC(hWnd, hdc);
	}
		return 0;
	case WM_TIMER:
		//display game UI
		if (wParam == GameUI)
		{
			hdc = GetDC(hWnd);			
			backdc = CreateCompatibleDC(hdc);
			newbmp = CreateCompatibleBitmap(hdc, nClientWidth, nClientHeight);
			oldbmp = (HBITMAP)SelectObject(backdc, newbmp);
			PatBlt(backdc, 0, 0, nClientWidth, nClientHeight, PATCOPY);

			//set font
			newfont = CreateFont
			(
				45, 0,    //高度20, 宽取0表示由系统选择最佳值
				0, 0,    //文本倾斜，与字体倾斜都为0
				FW_HEAVY,    //粗体
				0, 0, 0,        //非斜体，无下划线，无中划线
				GB2312_CHARSET,    //字符集
				OUT_DEFAULT_PRECIS,
				CLIP_DEFAULT_PRECIS,
				DEFAULT_QUALITY,        //一系列的默认值
				DEFAULT_PITCH | FF_DONTCARE,
				"自定义字体"    //字体名称
			);
			SetTextColor(hdc, RGB(0, 255, 0));
			SetBkMode(backdc, TRANSPARENT);
			oldfont = (HFONT)SelectObject(backdc, newfont);
			/////////////////////////////////////////////////////////////
			///////////////////////game main menu////////////////////////
			/////////////////////////////////////////////////////////////

			if (gamestate == title) {
			
				__gePutImage(backdc, 0, 0, &g_sfTitle);
				butt_start->display_button(backdc);
				butt_exit->display_button(backdc);

			}
			/////////////////////game set menu/////////////////////
			if (gamestate == gamesetting) {	}			
			///////////////////////game ready////////////////////////
			if (gamestate == ready) {
			
				//display background
				__gePutImage(backdc, 0, nBgY, &g_sfBacg);
				__gePutImage(backdc, 0, nBgY + 1000, &g_sfBacg);
			
				//display grid
				for (int i = 0; i < OB_map->nRow; i++)
					for (int j = 0; j < OB_map->nColumn; j++) {
						__gePutImageBlend(backdc, OB_map->position_LT.x + j*nBlockLength, OB_map->position_LT.y + i*nBlockLength, &g_sfBlank, 240);
					}
				//countdown			
				__gePutSprite_m(backdc,nClientcenter.x- g_sfCount[GameReadyCount].nWidth/2, 
					nClientcenter.y- g_sfCount[GameReadyCount].nHeight / 2-50, &g_sfCount[GameReadyCount], 1, 0);
			
			}
			///////////////////////game pause////////////////////////
			if (gamestate == pause) {

				__gePutImage(backdc, 0, nBgY, &g_sfBacg);
				__gePutImage(backdc, 0, nBgY + 1000, &g_sfBacg);
				
				//display grid
				for (int i = 0; i < OB_map->nRow; i++)
					for (int j = 0; j < OB_map->nColumn; j++) {
						__gePutImageBlend(backdc, OB_map->position_LT.x + j*nBlockLength, OB_map->position_LT.y + i*nBlockLength, &g_sfBlank, 240);
					}
			//pause image
				__gePutSprite_m(backdc, nClientcenter.x-180, nClientcenter.y-120, &g_sfPause, 1, 0);
			
			}
			///////////////////////game running////////////////////////
			if (gamestate == running){
				// __KeyProc( hWnd);
			//display background
			__gePutImage(backdc, 0, nBgY, &g_sfBacg);
			__gePutImage(backdc, 0, nBgY + 1000, &g_sfBacg);
			//display button
			butt_back->display_button(backdc);
			butt_pause->display_button(backdc);
			if (nThunder >= 20)butt_SkillThunder->display_button(backdc);
			//butt_SkillThunderBall->display_button(backdc);
			if (n_coin >= 100)butt_SkillUltBomb->display_button(backdc);
			
			/////DRAW basic game UI			
			//score
			TextOut(backdc, 780, 10, TEXT("Score:"), 6);
			wsprintf(buffscore, TEXT("%d"), score);
			TextOut(backdc, 810, 60, buffscore, lstrlen(buffscore));
			//level
			TextOut(backdc, 780, 110, TEXT("Level:"), 6);
			wsprintf(bufflevel, TEXT("%d"), level);
			TextOut(backdc, 810, 160, bufflevel, lstrlen(bufflevel));
			//coin
			__gePutSprite_m(backdc, 50, 200, &g_sfCoin, 1, 0);
			wsprintf(buffcoin, TEXT("%d"), n_coin);
			TextOut(backdc, 110, 200, buffcoin, lstrlen(buffcoin));
			//monster blue
			__gePutSprite_m(backdc, 50, 500, &g_sfMonster_blue, 8, monster_frame);
			wsprintf(buffMonsterBlue, TEXT("%d"), nMonsterBlue);
			TextOut(backdc, 110, 500, buffMonsterBlue, lstrlen(buffMonsterBlue));
			//monster red
			__gePutSprite_m(backdc, 50, 400, &g_sfMonster_red, 8, monster_frame);
			wsprintf(buffMonsterRed, TEXT("%d"), nMonsterRed);
			TextOut(backdc, 110, 400, buffMonsterRed, lstrlen(buffMonsterRed));
			//monster yellow
			__gePutSprite_m(backdc, 50, 600, &g_sfMonster_yellow, 8, monster_frame);
			wsprintf(buffMonsterYellow, TEXT("%d"), nMonsterYellow);
			TextOut(backdc, 110, 600, buffMonsterYellow, lstrlen(buffMonsterYellow));
			//thunder
			__gePutSprite_m(backdc, 50, 300, &g_sfThunder, 20, thunder_frame);
			wsprintf(buffThunder, TEXT("%d"), nThunder);
			TextOut(backdc, 110, 300, buffThunder, lstrlen(buffThunder));
			//nextblock			
			TextOut(backdc, 780, 220, TEXT("Next"), 4);
			TextOut(backdc, 780, 270, TEXT(" Block:"), 7);
					
			//grid image
			for (int i = 0; i < OB_map->nRow; i++)
				for (int j = 0; j < OB_map->nColumn; j++) {
					__gePutImageBlend(backdc, OB_map->position_LT.x+j*nBlockLength, OB_map->position_LT.y+i*nBlockLength, &g_sfBlank, 240);
				}
			//display object
			for (int i = 0; i < OB_map->nRow; i++)
				for (int j = 0; j <OB_map->nColumn; j++) {
					switch (OB_map->grid[i][j]) {
					case monster_red:
						__gePutSprite_m(backdc, j*nBlockLength + OB_map->position_LT.x, i*nBlockLength + OB_map->position_LT.y, &g_sfMonster_red, 8, monster_frame); break;
					case monster_blue:
						__gePutSprite_m(backdc, j*nBlockLength + OB_map->position_LT.x, i*nBlockLength + OB_map->position_LT.y, &g_sfMonster_blue, 8, monster_frame); break;
					case monster_yellow:
						__gePutSprite_m(backdc, j*nBlockLength + OB_map->position_LT.x, i*nBlockLength + OB_map->position_LT.y, &g_sfMonster_yellow, 8, monster_frame); break;
					case monster_red_dead:
						__gePutSprite_m(backdc, j*nBlockLength + OB_map->position_LT.x, i*nBlockLength + OB_map->position_LT.y, &g_sfMonster_red_dead, 8, monster_dead_frame); break;
					case monster_blue_dead:
						__gePutSprite_m(backdc, j*nBlockLength + OB_map->position_LT.x, i*nBlockLength + OB_map->position_LT.y, &g_sfMonster_blue_dead, 8, monster_dead_frame); break;
					case monster_yellow_dead:
						__gePutSprite_m(backdc, j*nBlockLength + OB_map->position_LT.x, i*nBlockLength + OB_map->position_LT.y, &g_sfMonster_yellow_dead, 8, monster_dead_frame); break;
					case bomb:
						__gePutSprite_m(backdc, j*nBlockLength + OB_map->position_LT.x, i*nBlockLength + OB_map->position_LT.y, &g_sfBomb, 10, bomb_frame); break;
					case thunder:						
						__gePutSprite_m(backdc, j*nBlockLength + OB_map->position_LT.x, i*nBlockLength + OB_map->position_LT.y, &g_sfThunder, 20, thunder_frame); break;
					case coin:
						__gePutSprite_m(backdc, j*nBlockLength + OB_map->position_LT.x, i*nBlockLength + OB_map->position_LT.y, &g_sfCoin, 1, 0); break;
					case bomb_dead:
						__gePutSprite_m(backdc, j*nBlockLength + OB_map->position_LT.x, i*nBlockLength + OB_map->position_LT.y, &g_sfBomb_dead, 15, bomb_dead_frame); break;
					case blank_d:
						__gePutSprite_m(backdc, j*nBlockLength + OB_map->position_LT.x, i*nBlockLength + OB_map->position_LT.y, &g_sfBlank, 1, 0); break;
					}
				}			
			//display nextblock
			switch (nextblock->type) {
			case monster_red:
				drawblock(backdc, nextblock, &g_sfMonster_red, 8, monster_frame, 0, 0);  break;
			case monster_blue:
				drawblock(backdc, nextblock, &g_sfMonster_blue, 8, monster_frame, 0, 0);  break;
			case monster_yellow:
				drawblock(backdc, nextblock, &g_sfMonster_yellow, 8, monster_frame, 0, 0);  break;
			case coin:
				drawblock(backdc, nextblock, &g_sfCoin, 1, 0, 0, 0);  break;
			case thunder:
				drawblock(backdc, nextblock, &g_sfThunder, 20, thunder_frame, 0, 0);  break;
			case bomb:
				drawblock(backdc, nextblock, &g_sfBomb, 10, bomb_frame, 0, 0);  break;
			
			}
			
				//display cuurent block
				if (block_arrivebottom == false) {
					switch (currentblock->type) {

					case monster_red:
						drawblock(backdc, currentblock, &g_sfMonster_red, 8, monster_frame, 0, 0);  break;
					case monster_blue:
						drawblock(backdc, currentblock, &g_sfMonster_blue, 8, monster_frame, 0, 0);  break;
					case monster_yellow:
						drawblock(backdc, currentblock, &g_sfMonster_yellow, 8, monster_frame, 0, 0);  break;
					case bomb:
						drawblock(backdc, currentblock, &g_sfBomb, 10, bomb_frame, 0, 0);  break;
					case coin:
						drawblock(backdc, currentblock, &g_sfCoin, 1, 0, 0, 0);  break;
					case thunder:
						drawblock(backdc, currentblock, &g_sfThunder, 20, thunder_frame, 0, 0);  break;

					}
				}
			//skill balll
			//skillball->display_ball(backdc);
		    //__gePutSprite_m(backdc, skill_ball.x, skill_ball.y, &g_sfBall, 1, 0);						
			}
			/////////////////////game over/////////////////////
			if (gamestate == gameover) {
				__gePutImage(backdc, 0, nBgY, &g_sfBacg);
				__gePutImage(backdc, 0, nBgY + 1000, &g_sfBacg);
				////display grid
				//for (int i = 0; i < OB_map->nRow; i++)
				//	for (int j = 0; j < OB_map->nColumn; j++) {
				//		__gePutImageBlend(backdc, OB_map->position_LT.x + j*nBlockLength, OB_map->position_LT.y + i*nBlockLength, &g_sfBlank, 240);
				//	}
				////display object
				//for (int i = 0; i < OB_map->nRow; i++)
				//	for (int j = 0; j <OB_map->nColumn; j++) {
				//		switch (OB_map->grid[i][j]) {
				//		case monster_red:
				//			__gePutSprite_m(backdc, j*nBlockLength + OB_map->position_LT.x, i*nBlockLength + OB_map->position_LT.y, &g_sfMonster_red, 8, monster_frame); break;
				//		case monster_blue:
				//			__gePutSprite_m(backdc, j*nBlockLength + OB_map->position_LT.x, i*nBlockLength + OB_map->position_LT.y, &g_sfMonster_blue, 8, monster_frame); break;
				//		case monster_yellow:
				//			__gePutSprite_m(backdc, j*nBlockLength + OB_map->position_LT.x, i*nBlockLength + OB_map->position_LT.y, &g_sfMonster_yellow, 8, monster_frame); break;
				//		case monster_red_dead:
				//			__gePutSprite_m(backdc, j*nBlockLength + OB_map->position_LT.x, i*nBlockLength + OB_map->position_LT.y, &g_sfMonster_red_dead, 8, monster_dead_frame); break;
				//		case monster_blue_dead:
				//			__gePutSprite_m(backdc, j*nBlockLength + OB_map->position_LT.x, i*nBlockLength + OB_map->position_LT.y, &g_sfMonster_blue_dead, 8, monster_dead_frame); break;
				//		case monster_yellow_dead:
				//			__gePutSprite_m(backdc, j*nBlockLength + OB_map->position_LT.x, i*nBlockLength + OB_map->position_LT.y, &g_sfMonster_yellow_dead, 8, monster_dead_frame); break;
				//		case bomb:
				//			__gePutSprite_m(backdc, j*nBlockLength + OB_map->position_LT.x, i*nBlockLength + OB_map->position_LT.y, &g_sfBomb, 10, bomb_frame); break;
				//		case thunder:
				//			__gePutSprite_m(backdc, j*nBlockLength + OB_map->position_LT.x, i*nBlockLength + OB_map->position_LT.y, &g_sfThunder, 20, thunder_frame); break;
				//		case coin:
				//			__gePutSprite_m(backdc, j*nBlockLength + OB_map->position_LT.x, i*nBlockLength + OB_map->position_LT.y, &g_sfCoin, 1, 0); break;
				//		}
				//	}

				__gePutImage(backdc, 0, 0, &g_sfBacg_GameOver);
				__gePutImage(backdc, nClientcenter.x - g_sfGameover.nWidth / 2,
					nClientcenter.y - g_sfGameover.nHeight / 2 - 200, &g_sfGameover);

				butt_continue->display_button(backdc);

				__gePutSprite_m(backdc, nClientcenter.x + 120, nClientcenter.y-25, &g_sfCoin, 1, 0);
				
				wsprintf(buffcoin, TEXT("%d"), 100);
				TextOut(backdc, nClientcenter.x + 180, nClientcenter.y-25, buffcoin, lstrlen(buffcoin));

				butt_back02->display_button(backdc);


			}
			///////////////////////////////////////////////////
			if (gamestate == victory) {
				__gePutImage(backdc, 0, 0, &g_sfBacg_Victory);
				__gePutSprite_m(backdc, nClientcenter.x - g_sfVictory.nWidth / 2,
					nClientcenter.y - g_sfVictory.nHeight / 2-100, &g_sfVictory, 1, 0);
				butt_continue->display_button(backdc, 
					nClientcenter.x - butt_continue->button_img[0].nWidth/2,
					nClientcenter.y - butt_continue->button_img[0].nHeight / 2+50);

				


			}
			///////////////////////////////skill UI
			if (gamestate == useSkill) {
				//display background
				switch (skilltype) {
				case sk_Thunder: {
					__gePutImage(backdc, 0, 0, &g_sfBacg_Thunder);	
					for (int i = 0; i < Thunder_amount; i++) {
						Ob_Thunder[i]->drawobject(backdc);
					}
				}break;
				case sk_ThunderBall:__gePutImage(backdc, 0, 0, &g_sfBacg_ThunderBall);	break;
				case sk_UltBomb:__gePutImage(backdc, 0, 0, &g_sfBacg_UltBomb);	break;
				}
						
				//display object
				for (int i = 0; i < OB_map->nRow; i++)
					for (int j = 0; j <OB_map->nColumn; j++) {
						switch (OB_map->grid[i][j]) {
						case monster_red:
							__gePutSprite_m(backdc, j*nBlockLength + OB_map->position_LT.x, i*nBlockLength + OB_map->position_LT.y, &g_sfMonster_red, 8, monster_frame); break;
						case monster_blue:
							__gePutSprite_m(backdc, j*nBlockLength + OB_map->position_LT.x, i*nBlockLength + OB_map->position_LT.y, &g_sfMonster_blue, 8, monster_frame); break;
						case monster_yellow:
							__gePutSprite_m(backdc, j*nBlockLength + OB_map->position_LT.x, i*nBlockLength + OB_map->position_LT.y, &g_sfMonster_yellow, 8, monster_frame); break;
						case monster_red_dead:
							__gePutSprite_m(backdc, j*nBlockLength + OB_map->position_LT.x, i*nBlockLength + OB_map->position_LT.y, &g_sfMonster_red_dead, 8, monster_dead_frame); break;
						case monster_blue_dead:
							__gePutSprite_m(backdc, j*nBlockLength + OB_map->position_LT.x, i*nBlockLength + OB_map->position_LT.y, &g_sfMonster_blue_dead, 8, monster_dead_frame); break;
						case monster_yellow_dead:
							__gePutSprite_m(backdc, j*nBlockLength + OB_map->position_LT.x, i*nBlockLength + OB_map->position_LT.y, &g_sfMonster_yellow_dead, 8, monster_dead_frame); break;
						case bomb:
							__gePutSprite_m(backdc, j*nBlockLength + OB_map->position_LT.x, i*nBlockLength + OB_map->position_LT.y, &g_sfBomb, 10, bomb_frame); break;
						case thunder:
							__gePutSprite_m(backdc, j*nBlockLength + OB_map->position_LT.x, i*nBlockLength + OB_map->position_LT.y, &g_sfThunder, 20, thunder_frame); break;
						case coin:
							__gePutSprite_m(backdc, j*nBlockLength + OB_map->position_LT.x, i*nBlockLength + OB_map->position_LT.y, &g_sfCoin, 1, 0); break;
						case bomb_dead:
							__gePutSprite_m(backdc, j*nBlockLength + OB_map->position_LT.x, i*nBlockLength + OB_map->position_LT.y, &g_sfBomb_dead, 15, bomb_dead_frame); break;
						}
					}
				
				
				
				
			}
			/////////////////////put buffdc to hdc/////////////			
			BitBlt(hdc, 0, 0, nClientWidth, nClientHeight, backdc, 0, 0, SRCCOPY);
			InvalidateRect(hWnd, NULL, TRUE);	
			//////////delete object////////////
			SelectObject(backdc, oldfont);
			DeleteObject(newfont);
			SelectObject(backdc, oldbmp);
			DeleteObject(oldbmp);
			DeleteObject(newbmp);
			DeleteDC(backdc);
			ReleaseDC(hWnd, hdc);
		}
		//block fall
		if (wParam == blockfall) {

			if (gamestate == running) {
			
				if (CollideWall_Bottom(currentblock,OB_map)==false
					&& CollideObstacle_Bottom(currentblock, OB_map) == false) {					
					currentblock->position_TL[0].y += nBlockLength;
					currentblock->updatestock(OB_map);
				}								
			}
		}
		//savestock
		if (wParam == saveobstacle) {
			//save stock
			score += 4;
			if (CollideWall_Bottom(currentblock, OB_map) == true
				|| CollideObstacle_Bottom(currentblock, OB_map) == true){
				OB_map->grid[currentblock->position_Grid[0].y][currentblock->position_Grid[0].x] = currentblock->type;
				OB_map->grid[currentblock->position_Grid[1].y][currentblock->position_Grid[1].x] = currentblock->type;
				OB_map->grid[currentblock->position_Grid[2].y][currentblock->position_Grid[2].x] = currentblock->type;
				OB_map->grid[currentblock->position_Grid[3].y][currentblock->position_Grid[3].x] = currentblock->type;
				block_arrivebottom = true;
			}
			else {
				SetTimer(hWnd, checkbottom, 16, NULL);
				KillTimer(hWnd, saveobstacle);
				break;
			}
			//check line 
			for (int i = 0; i < OB_map->nRow; i++)
				for (int j = 0; j < OB_map->nColumn; j++) {
					{
						if (OB_map->grid[i][j] == 0) break;
						if (j == OB_map->nColumn - 1) {
							b_fullline = true;
							//full line by red monster//
							for (int k = 0; k < OB_map->nColumn; k++) {
								if (OB_map->grid[i][k] != monster_red) break;
								if (k == OB_map->nColumn - 1) {
									gamestate = gameover;
									break;
								}							
							}
							//full line by bluemonster//
							for (int k = 0; k < OB_map->nColumn; k++) {
								if (OB_map->grid[i][k] != monster_blue) break;
								if (k == OB_map->nColumn - 1) {
									gamestate = gameover;
									break;
								}
							}
							//full line by yellow monster//
							for (int k = 0; k < OB_map->nColumn; k++) {
								if (OB_map->grid[i][k] != monster_yellow) break;
								if (k == OB_map->nColumn - 1) {
									gamestate = gameover;
									break;
								}
							}
							//fullline by thunder//
							for (int k = 0; k < OB_map->nColumn; k++) {
								if (OB_map->grid[i][k] != thunder) break;
								if (k == OB_map->nColumn - 1) {
									TriggarThunder = true;									
									break;
								}
							}
							//fullline by coin//
							for (int k = 0; k < OB_map->nColumn; k++) {
								if (OB_map->grid[i][k] != coin) break;
								if (k == OB_map->nColumn - 1) {
									b_FulllineBycoin = true;
									n_coin += 50;
									TriggarCoin = true;
									break;
								}
							}
							//fullline by bomb//
							for (int k = 0; k < OB_map->nColumn; k++) {
								if (OB_map->grid[i][k] != bomb) break;
								if (k == OB_map->nColumn - 1) {									
									TriggarUltbomb = true;
									break;
								}
							}


							for (int k = 0; k < OB_map->nColumn; k++) {															
								switch (OB_map->grid[i][k]) {
								case coin: { OB_map->grid[i][k] = blank_d; if(b_FulllineBycoin==false)n_coin++; }break;
								case monster_red: { OB_map->grid[i][k] = monster_red_dead; nMonsterRed--; } break;
								case monster_blue: { OB_map->grid[i][k] = monster_blue_dead; nMonsterBlue--; } break;
								case monster_yellow: { OB_map->grid[i][k] = monster_yellow_dead; nMonsterYellow--;} break;
								case bomb:OB_map->grid[i][k] = bomb_dead; break;
								case thunder: { OB_map->grid[i][k] = blank_d; nThunder++; }break; 

								}
							}
							KillTimer(hWnd, blockfall);
							KillTimer(hWnd, saveobstacle);							
							SetTimer(hWnd, removeblock_ani01, 100, NULL);
							SetTimer(hWnd, removeblock_ani02, 100, NULL);
						}
					}
				}
			if (b_fullline == false) {			
				if (OB_map->_gameover()) {
					gamestate = gameover;				
				}
				//init block state
				block_arrivebottom = false;
				currentblock->position_TL[0].x = OB_map->nLeftWall_x + OB_map->nWidth / 2;
				currentblock->position_TL[0].y = OB_map->nTopWall_y + nBlockLength;

				srand((unsigned)time(NULL));

				currentblock->style = nextblock->style;
				currentblock->type = nextblock->type;

				nextblock->style = rand() % 7 + 1;
				nextblock->type = __randblocktype(nMonsterRed, nMonsterBlue, nMonsterYellow);
				currentblock->state = 0;
				currentblock->updatestock(OB_map);
				nextblock->updatestock(OB_map);

				SetTimer(hWnd, checkbottom, 16, NULL);
				KillTimer(hWnd, saveobstacle);

			}
			

		}
		if (wParam == checkbottom) {
			if(gamestate==running){				
			//check  obstacle bottom
				//__KeyProc(hWnd);
				level = score / 50;
				if (nMonsterBlue <= 0 && nMonsterRed <= 0 && nMonsterYellow <= 0)gamestate = victory;
				
				if (CollideWall_Bottom(currentblock, OB_map) == true
					|| CollideObstacle_Bottom(currentblock, OB_map) == true)
				{
					
					SetTimer(hWnd, saveobstacle, 400, NULL);
					KillTimer(hWnd, checkbottom);
					}
				}
			}
		if (wParam == Initblock) {
		
			currentblock->position_TL[0].x = OB_map->nLeftWall_x + OB_map->nWidth / 2;
			currentblock->position_TL[0].y = OB_map->nTopWall_y + nBlockLength;

			srand((unsigned)time(NULL));


			currentblock->style = nextblock->style;
			currentblock->type = nextblock->type;

			nextblock->style = rand() % 7 + 1;
			nextblock->type = __randblocktype(nMonsterRed, nMonsterBlue, nMonsterYellow);
			currentblock->state = 0;
			currentblock->updatestock(OB_map);
			nextblock->updatestock(OB_map);
			//SetTimer(hWnd, removeline, 100, NULL);
			SetTimer(hWnd, checkbottom, 16, NULL);
			SetTimer(hWnd, blockfall, 300 - level * 20, NULL);
			KillTimer(hWnd, Initblock);		
		}		
		if (wParam == removeline) {		
			for (int i = 0; i < OB_map->nRow; i++)
				for (int j = 0; j < OB_map->nColumn; j++) {
					{
						if (OB_map->grid[i][j] == 0)break;

						if (j == OB_map->nColumn - 1) {
							score += 20;
							for (int k = 0; k < OB_map->nColumn; k++) {
								OB_map->grid[i][k] = 0;
								for (int l = i; l > 0; l--) {
									OB_map->grid[l][k] = OB_map->grid[l - 1][k];
								}
							}
						}
					}
				}
			b_fullline = false;
			b_FulllineBycoin = false;
			block_arrivebottom = false;
			if (TriggarThunder == true) {
				TriggarThunder = false;
				skilltype = sk_Thunder;
				gamestate = useSkill;				
				//
				hdc = GetDC(hWnd);
				skill_lasttime = 100;
				Thunder_amount = 5;
				Ob_Thunder = new object*[Thunder_amount];
				for (int i = 0; i < Thunder_amount; i++) {
					Ob_Thunder[i] = new object(0, rand() % OB_map->nColumn, hdc,
						"thunder-O.bmp", RGB(255, 255, 255), 20, OB_map);
				}
				ReleaseDC(hWnd, hdc);
				//
				SetTimer(hWnd, skill_proc, 1000 / 30, NULL);
				SetTimer(hWnd, skill_ani, 100, NULL);

			}
			else if (TriggarUltbomb == true) {
				TriggarUltbomb = false;
				skilltype = sk_UltBomb;
				gamestate = useSkill;			
				SetTimer(hWnd, skill_proc, 1000 / 30, NULL);
				SetTimer(hWnd, skill_ani, 100, NULL);					
			}
			else if (TriggarCoin == true) {
				TriggarCoin = false;
				for (int i = 0; i <OB_map->nRow; i++)
					for (int j = 0; j <OB_map->nColumn; j++) {
					if(OB_map->grid[i][j]>0)OB_map->grid[i][j] = coin;
					}
			
			
			}
			else {
				SetTimer(hWnd, Initblock, 10, NULL);
				KillTimer(hWnd, removeline);
			}

		}
		if (wParam == block_ani) {			
				if (gamestate == running
					|| gamestate == useSkill) {							
				thunder_frame++;
				monster_frame++;
				bomb_frame++;				
				abc->disFrame++;
				if (abc->disFrame == 20)abc->disFrame = 0;
				if (thunder_frame == 20)thunder_frame = 0;
				if (monster_frame == 8)monster_frame = 0;
				if (bomb_frame == 10)bomb_frame = 0;						
				skillball->circle_center.x+= ballmove_x;
				skillball->circle_center.y+= ballmove_y;
				skillball->updaeposition();
				for (int i = 0; i < 360; i++) {
					if (skillball->circle_point[i].x > OB_map->nRightWall_x) {
					
						ballmove_x = -10;
						
						break;
					}
					 if (skillball->circle_point[i].x < OB_map->nLeftWall_x) {

						ballmove_x = 10;
						break;
					}
					 if (skillball->circle_point[i].y > OB_map->nBottom_wall_y) {

						 ballmove_y = -10;

						 break;
					 }
					 if (skillball->circle_point[i].y < OB_map->nTopWall_y) {

						 ballmove_y = 10;

						 break;
					 }

						//skillball->circle_center.x += 10;									
						//skillball->circle_point[i].y
				}
				/*if (skillball->circle_center.x>OB_map->nRightWall_x)
				{
					skillball->circle_center.x--;
					skillball->circle_center.y++;
				}
				else
				{
					skillball->circle_center.x+=10;
					skillball->circle_center.y+=10;
				}
				*/
				///
				return 0;

			}
		}
		if (wParam == gamereadycount) {
			GameReadyCount--;
			if (GameReadyCount < 0) {
				KillTimer(hWnd, gamereadycount);
				gamestate = running;
			}		
		}
		if (wParam == removeblock_ani01) {
			if (gamestate == running) {
				if (monster_dead_frame < 8)
					monster_dead_frame++;
				if (bomb_dead_frame < 15)
					bomb_dead_frame++;

				if (bomb_dead_frame >= 14) {

					monster_dead_frame = 0;
					bomb_dead_frame = 0;
					SetTimer(hWnd, removeline, 10, NULL);
					KillTimer(hWnd, removeblock_ani01);

				}
			}
		}
		if (wParam == display_bg) {
			switch (gamestate) {
			case title:
				return 0;
			case running:
				if (nBgY < -1000) nBgY = 0;
				nBgY -= 2+level*5;
				return 0;
			}
		}
		
		if (wParam == skill_ani) {
			if (skilltype == sk_Thunder) {
				for (int i = 0; i < Thunder_amount; i++) {
					Ob_Thunder[i]->disFrame++;
				}
				for (int i = 0; i < Thunder_amount; i++) {
					if (Ob_Thunder[i]->disFrame == 20)Ob_Thunder[i]->disFrame = 0;
				}
			}
			if (skilltype == sk_UltBomb) {
				if (monster_dead_frame < 8)
					monster_dead_frame++;
				if (bomb_dead_frame < 15)
					bomb_dead_frame++;
			}
		}
		if (wParam == skill_proc) {		
			if (skilltype == sk_Thunder) {
				KillTimer(hWnd, checkbottom);
				skill_lasttime--;
				OB_map->ComputeTopOB_y();
				for (int i = 0; i < Thunder_amount; i++) {

					if (Ob_Thunder[i]->position_RB.y - 20 < OB_map->TopObstacle[Ob_Thunder[i]->Column])
					{
						Ob_Thunder[i]->movedown(40);
					}
					else {
						if (Ob_Thunder[i]->position_RB.y < OB_map->nBottom_wall_y) {
							switch (OB_map->grid[OB_map->TopObrow[Ob_Thunder[i]->Column]]
								[Ob_Thunder[i]->Column]) {
							case coin: n_coin++; break;
							case monster_red:  nMonsterRed--;  break;
							case monster_blue: nMonsterBlue--;  break;
							case monster_yellow: nMonsterYellow--;  break;						
							case thunder: nThunder++; break;
							}
							OB_map->grid[OB_map->TopObrow[Ob_Thunder[i]->Column]][Ob_Thunder[i]->Column] = 0;
							OB_map->ComputeTopOB_y();
						}
						//Ob_Thunder[i]->sk_round++;
						Ob_Thunder[i]->updatestate(0, rand() % 10, OB_map);
					}
				}
				if (skill_lasttime <= 0) {
					skill_lasttime = 0;
					TriggarThunder = false;
					gamestate = running;
					SetTimer(hWnd, checkbottom, 16, NULL);
					KillTimer(hWnd, skill_proc);
					KillTimer(hWnd, skill_ani);
				}
			}
			if (skilltype == sk_ThunderBall) {			
				skill_lasttime--;
			if(skill_lasttime <= 0) {				
					skill_lasttime = 0;
					gamestate = running;
					KillTimer(hWnd, skill_proc);
					KillTimer(hWnd, skill_ani);
					
				}
			
			}
			if (skilltype == sk_UltBomb) {
				
				skill_lasttime--;
				OB_map->setgrid(bomb_dead);
				
				if (bomb_dead_frame==15) {
					bomb_dead_frame = 0;
					skill_lasttime = 0;
					TriggarUltbomb = false;
					delete OB_map;
					grid_row--;
					OB_map = new map(250, 10, grid_row, grid_column, nBlockLength);
					gamestate = running;
					SetTimer(hWnd, checkbottom, 16, NULL);
					KillTimer(hWnd, skill_proc);
					KillTimer(hWnd, skill_ani);
				}

			}
		}
				return 0;
	case WM_KEYDOWN: {
		if (gamestate == running) {
			switch (wParam) {
			case VK_LEFT: {
				if (CollideWall_Left(currentblock, OB_map)) break;
				else {
					if (CollideObstacle_Left(currentblock, OB_map)) break;
					else {
						move_left(currentblock, OB_map);
					}
				}
			}
						  break;
			case VK_RIGHT: {
				if (CollideWall_Right(currentblock, OB_map)) break;
				else {
					if (CollideObstacle_Right(currentblock, OB_map))  break;
					else {
						move_right(currentblock, OB_map);
					}
				}
			}
						   break;
			case VK_UP: {
				__block_rotate(currentblock, OB_map);
			}
						break;
			case VK_DOWN: {
				if (CollideWall_Bottom(currentblock, OB_map)) break;
				else {
					if (CollideObstacle_Bottom(currentblock, OB_map)) break;
					else {
						move_bottom(currentblock, OB_map);
					}
				}

			}
						  break;
			case VK_SPACE: {
				nMonsterBlue =1;
				nMonsterRed = 1;
				nMonsterYellow = 1;
			}
						   break;
			case VK_RETURN: {
				// OB_map->resetgrid();
				

				n_coin = 9999;
				
				nThunder = 9999;
			}
							break;
			case 80: {
				if (gamestate == pause) {
					gamestate = ready;
					GameReadyCount = 2;
					SetTimer(hWnd, gamereadycount, 1000, NULL);
				}
				if (gamestate == running) {
					gamestate = pause;
				}}
					 break;
			case 49: currentblock->type = 1; break;
			case 50: currentblock->type = 2; break;
			case 51: currentblock->type = 3; break;
			case 52: currentblock->type = 4; break;
			case 53: currentblock->type = 5; break;
			case 54: currentblock->type = 6; break;

			}
		}
			}
							return 0;
			case WM_LBUTTONDOWN: {
				MousePoint.x = LOWORD(lParam);
				MousePoint.y = HIWORD(lParam);

				if (gamestate == title) {
					//start button
					butt_start->Insidearea(MousePoint);
					//exit button
					butt_exit->Insidearea(MousePoint);
				}
				if (gamestate == running) {
					//back button
					butt_back->Insidearea(MousePoint);
					//stop button
					butt_pause->Insidearea(MousePoint);

					//skill thunder button
					butt_SkillThunder->Insidearea(MousePoint);
					//skill thunderball button
					butt_SkillThunderBall->Insidearea(MousePoint);
					//skill UltBomb button
					butt_SkillUltBomb->Insidearea(MousePoint);

				}
				if (gamestate == gameover) {
					//continue button
					butt_continue->Insidearea(MousePoint);
					//back button
					butt_back02->Insidearea(MousePoint);

				}
				if (gamestate == victory) {
					//continue button
					butt_continue->Insidearea(MousePoint);
				}
			}
				return 0;
			case WM_LBUTTONUP: {
				MousePoint.x = LOWORD(lParam);
				MousePoint.y = HIWORD(lParam);
				if (gamestate == pause) {
					gamestate = ready;
					GameReadyCount = 2;
					SetTimer(hWnd, gamereadycount, 1000, NULL);
				}
				if (gamestate == running) {

					butt_back->bepress = false;
					butt_pause->bepress = false;
					butt_SkillThunderBall->bepress = false;
					butt_SkillUltBomb->bepress = false;
					butt_SkillThunder->bepress = false;
					//back button
					if (butt_back->Insidearea(MousePoint)) {
						gamestate = title;
						butt_back->bepress = false;
					}
					//stop button
					if (butt_pause->Insidearea(MousePoint)) {
						gamestate = pause;
						butt_pause->bepress = false;
					}
					//skill Thunder button
					if (nThunder >= 20) {
						if (butt_SkillThunder->Insidearea(MousePoint)) {
							butt_SkillThunder->bepress = false;
							nThunder -= 20;
							skilltype = sk_Thunder;
							gamestate = useSkill;
							butt_SkillThunder->bepress = false;
							//
							hdc = GetDC(hWnd);
							skill_lasttime = 100;
							Thunder_amount = 5;
							Ob_Thunder = new object*[Thunder_amount];
							for (int i = 0; i < Thunder_amount; i++) {
								Ob_Thunder[i] = new object(0, rand() % OB_map->nColumn, hdc,
									"thunder-O.bmp", RGB(255, 255, 255), 20, OB_map);
							}
							ReleaseDC(hWnd, hdc);
							//
							SetTimer(hWnd, skill_proc, 1000 / 30, NULL);
							SetTimer(hWnd, skill_ani, 100, NULL);


						}
					}
					//skill ThunderBall button(****updating)
					/*if (butt_SkillThunderBall->Insidearea(MousePoint)) {
						skilltype = sk_ThunderBall;
						gamestate = useSkill;
						butt_SkillThunderBall->bepress = false;
						SetTimer(hWnd, skill_proc, 1000 / 30, NULL);
						SetTimer(hWnd, skill_ani, 100, NULL);
					}*/
					//skill Ultbomb button
					if (n_coin >= 100) {
						if (butt_SkillUltBomb->Insidearea(MousePoint)) {
							skilltype = sk_UltBomb;
							gamestate = useSkill;
							n_coin -= 100;
							butt_SkillUltBomb->bepress = false;
							SetTimer(hWnd, skill_proc, 1000 / 30, NULL);
							SetTimer(hWnd, skill_ani, 100, NULL);
						}
					}
				}
				if (gamestate == title) {
					butt_exit->bepress = false;
					butt_start->bepress = false;
					if (butt_exit->Insidearea(MousePoint)) {
						butt_exit->bepress = false;
						PostQuitMessage(0);
					}

					if (butt_start->Insidearea(MousePoint)){
						if (gamestate == title) {
							butt_start->bepress = false;
							gamestate = ready;
							GameReadyCount = 2;
							SetTimer(hWnd, gamereadycount, 1000, NULL);

							if (OB_map) {
								delete OB_map;
								resetmap(18, 10);
								OB_map->resetgrid();
							}
							
							resetgame();
							resetblockstate();
							CreateTimer_DisplayBackground
							CreateTimer_BlockAnimation
							CreateTimer_BlockFall
						

						}
					}
				}
				if (gamestate == gameover) {
					butt_continue->bepress = false;
					butt_back02->bepress = false;
					//continue button
					if(butt_continue->Insidearea(MousePoint)) {
						butt_continue->bepress = false;
						if (n_coin >= 150) {
							n_coin -= 150;
							OB_map->resetgrid();
							gamestate = running;
						}
											
					}
					//back button
					if(butt_back02->Insidearea(MousePoint)) {
					
						butt_back02->bepress = false;
						gamestate = title;
					}

				}
				if (gamestate == victory) {
					//continue button
					butt_continue->bepress = false;
					if (butt_continue->Insidearea(MousePoint)) {
						gamestate = title;

				}
				}
				}
		return 0;
			case WM_DESTROY: {
				//free(stock);
				KillTimer(hWnd, 1);
				___aDestroyAll();
				PostQuitMessage(0);
				return 0; }
	}
	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
}

//void useskill(HWND hWnd,int,int _skiltype, int _lasttime, int _skilllevel) {
//
//	skilltype = sk_ThunderBall;
//	gamestate = useSkill;
//	butt_SkillThunderBall->bepress = false;
//	SetTimer(hWnd, skill_create, 100, NULL);
//
//}

void __KeyProc(HWND hWnd)
{
	//// 0x80 비트가 1이면 가상키가 눌린 것
	//   만약 0x80 비트가 1이었다가 0이 되면 가상키를 뗀 것
	//   (0x80 비트가 0인 상태가 가상키를 뗀 것이 아님에 유의)
	// 0x80 == 0b1000 0000
	if (GetKeyState(VK_LEFT) & 0x80)
	{
		if (CollideWall_Left(currentblock, OB_map)) {}
		else {
			if (CollideObstacle_Left(currentblock, OB_map)) {}
			else {
				move_left(currentblock, OB_map);
			}
		}
	}
	if (GetKeyState(VK_RIGHT) & 0x80)
	{
		if (CollideWall_Right(currentblock, OB_map)) {}
		else {
			if (CollideObstacle_Right(currentblock, OB_map)) {}
			else {
				move_right(currentblock, OB_map);
			}
		}
	}
	if (GetKeyState(VK_UP) & 0x80)
	{
		__block_rotate(currentblock, OB_map);
	}
	if (GetKeyState(VK_DOWN) & 0x80)
	{
		if (CollideWall_Bottom(currentblock, OB_map)) {}
		else {
			if (CollideObstacle_Bottom(currentblock, OB_map)) {}
			else {
				move_bottom(currentblock, OB_map);
			}
		}
	}
}