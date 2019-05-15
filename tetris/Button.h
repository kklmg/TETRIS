#pragma once
#include"graphicengine.h"
#include"map.h"
class button {
public:

	SURFACEINFO button_img[2];
	POINT position_LT;
	POINT position_RB;
	POINT position_CT;

	button(int x, int y, HDC hdc,char*file_1,char*file_2, COLORREF colorkey);

	~button();

	bool bepress;
	bool setbutton_img(HDC hdc, COLORREF colorkey);
	bool display_button(HDC hdc);
	bool display_button(HDC hdc, int x, int y);
	bool Insidearea(POINT _mousepoint);
};

