#include"object.h"
ball::ball(int x, int y, HDC hdc, char*file, COLORREF colorkey) {

	circle_center.x = x;
	circle_center.y = y;

	__geSetSprSurface(&ball_img, colorkey);
	ball_img.hBmp = __geBmpFile2BmpHandle(file);
	__geLoadSurface(hdc, &ball_img);

	r = ball_img.nWidth / 2;
	double rad = 0;
	for (int i = 0; i < 360; i++)
	{
		rad += pi / 180;
		circle_point[i].x = r*cos(rad) + circle_center.x;
		circle_point[i].y = r*sin(rad) + circle_center.y;

	}

}



bool ball::display_ball(HDC hdc) {

	__gePutSprite_m(hdc, circle_center.x, circle_center.y, &ball_img, 1, 0);
	return true;
}
void ball::updaeposition() {

	double rad = 0;
	for (int i = 0; i < 360; i++)
	{
		rad += pi / 180;
		circle_point[i].x = r*cos(rad) + circle_center.x;
		circle_point[i].y = r*sin(rad) + circle_center.y;
	}
}




object::object(int x, int y, HDC hdc, char *file, COLORREF colorkey, int _maxFrame) {

	disFrame = 0;
	position_CT.x = x;
	position_CT.y = y;
	maxFrame = _maxFrame;
	__geSetSprSurface(&img, colorkey);
	img.hBmp = __geBmpFile2BmpHandle(file);
	__geLoadSurface(hdc, &img);
	Width = img.nWidth / maxFrame;
	Height = img.nHeight;

	position_LT.x = position_CT.x - Width / 2;
	position_LT.y = position_CT.y - Height / 2;

	position_RB.x = position_CT.x + Width / 2;
	position_RB.y = position_CT.y + Height / 2;

}
object::object(int row, int column, HDC hdc, char *file, COLORREF colorkey, int _maxFrame, map *map) {
	Row = row;
	Column = column;
	disFrame = 0;
	maxFrame = _maxFrame;
	sk_round = 0;
	__geSetSprSurface(&img, colorkey);
	img.hBmp = __geBmpFile2BmpHandle(file);
	__geLoadSurface(hdc, &img);
	Width = img.nWidth;
	Height = img.nHeight;

	position_LT.x = map->nLeftWall_x + column*map->grid_length;
	position_LT.y = map->nTopWall_y + row*map->grid_length;

	position_RB.x = position_LT.x + map->grid_length;
	position_RB.y = position_LT.y + map->grid_length;

}
void object::drawobject(HDC hdc) {

	__gePutSprite_m(hdc, position_LT.x, position_LT.y, &img, maxFrame, disFrame);
}
void object::updatestate() {

	/*position_LT.x = position_CT.x - Width / 2;
	position_LT.y = position_CT.y - Height / 2;

	position_RB.x = position_CT.x + Width / 2;
	position_RB.y = position_CT.y + Height / 2;*/

	position_RB.x = position_LT.x + Width;
	position_RB.y = position_LT.y + Height;

}
void object::updatestate(POINT _CT) {

	/*position_LT.x = position_CT.x - Width / 2;
	position_LT.y = position_CT.y - Height / 2;

	position_RB.x = position_CT.x + Width / 2;
	position_RB.y = position_CT.y + Height / 2;*/



}



void object::updatestate(int row, int column, map* _map) {

	Row = row;
	Column = column;

	position_LT.x = _map->nLeftWall_x + column*_map->grid_length;
	position_LT.y = _map->nTopWall_y + row*_map->grid_length;

	position_RB.x = position_LT.x + _map->grid_length;
	position_RB.y = position_LT.y + _map->grid_length;

}

void object::movedown(int speed) {
	position_LT.y += speed;
	updatestate();
}

object::~object() {
	__geReleaseSurface(&img);
}
object::object() {
	Row = 0;
	Column = 0;
	disFrame = 0;
	maxFrame = 0;


	Width = 0;
	Height = 0;

	position_LT.x = 0;
	position_LT.y = 0;

	position_RB.x = 0;
	position_RB.y = 0;



}
//object(const object& ob);
//void operator=(const object& ob);
//void object::operator=(const object &ob)  {
//	Row = ob.Row;
//	Column = ob.Column;
//	disFrame = ob.disFrame;
//	maxFrame =ob.maxFrame;
//	
//	img = ob.img;
//	Width = ob.Width;
//	Height = ob.Height;
//
//	position_LT.x = ob.position_LT.x;
//	position_LT.y = ob.position_LT.y;
//
//	position_RB.x = ob.position_RB.x;
//	position_RB.y = ob.position_RB.y;
//}

//bool coolideblock(map *map,object *object) 
//{
//	
//	
//	if	(object->position_RB.y > map->TopObstacle[1]);
//	return true;	
//	
//
//}
