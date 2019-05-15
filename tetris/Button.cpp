#include"Button.h"

bool button::setbutton_img(HDC hdc, COLORREF colorkey) {

	__geSetSprSurface(&button_img[0], colorkey);
	button_img[0].hBmp = __geBmpFile2BmpHandle("start.bmp");
	__geLoadSurface(hdc, &button_img[0]);

	__geSetSprSurface(&button_img[1], colorkey);
	button_img[1].hBmp = __geBmpFile2BmpHandle("start.bmp");
	__geLoadSurface(hdc, &button_img[1]);

	position_RB.x += position_LT.x + button_img[0].nWidth;
	position_RB.y += position_LT.y + button_img[0].nHeight;

	return true;
}

bool button::display_button(HDC hdc) {
	if (bepress == true) {
		return __gePutSprite_m(hdc, position_LT.x, position_LT.y, &button_img[1], 1, 0);
	}
	if (bepress == false) {
		return __gePutSprite_m(hdc, position_LT.x, position_LT.y, &button_img[0], 1, 0);
	}
	 
}

bool button::display_button(HDC hdc,int x,int y) {

	position_LT.x = x;
	position_LT.y = y;
	position_RB.x = position_LT.x + button_img[0].nWidth;
	position_RB.y = position_LT.y + button_img[1].nHeight;

	if (bepress == true) {
		return __gePutSprite_m(hdc, x, y, &button_img[1], 1, 0);
	}
	if (bepress == false) {
		return __gePutSprite_m(hdc, x, y, &button_img[0], 1, 0);
	}
	
}



button::button(int x,int y,HDC hdc, char*file_1, char*file_2,COLORREF colorkey) {
	


	position_CT.x = x;
	position_CT.y = y;

	bepress = false;

	__geSetSprSurface(&button_img[0], colorkey);
	button_img[0].hBmp = __geBmpFile2BmpHandle(file_1);
	__geLoadSurface(hdc, &button_img[0]);

	__geSetSprSurface(&button_img[1], colorkey);
	button_img[1].hBmp = __geBmpFile2BmpHandle(file_2);
	__geLoadSurface(hdc, &button_img[1]);


	position_LT.x = position_CT.x - button_img[0].nWidth / 2;
	position_LT.y = position_CT.y - button_img[0].nHeight / 2;

	position_RB.x = position_LT.x + button_img[0].nWidth;
	position_RB.y = position_LT.y + button_img[0].nHeight;

	


}




bool button::Insidearea(POINT _mousepoint){

	if(_mousepoint.x > position_LT.x
		&& _mousepoint.x<position_RB.x
		&&_mousepoint.y>position_LT.y
		&& _mousepoint.y<position_RB.y) {		
	bepress = true;
	return true;
}
	else return false;
}
