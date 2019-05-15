#pragma once
#include"graphicengine.h"
#include"map.h"
#include<math.h>
#define pi 3.1415926
typedef struct tagPOINT_D
{
	double  x;
	double  y;
} POINT_D;


class ball {

public:
	POINT circle_center;
	double r;
	//POINT circle_point[360];
	POINT_D circle_point[360];
	SURFACEINFO ball_img;

	ball(int x, int y, HDC hdc, char*file, COLORREF colorkey);
	~ball();

	bool display_ball(HDC hdc);
	void updaeposition();
	//(x - a) ^ 2£«(y - b) ^ 2£½r ^ 2
	//£¨r*cosm+a£¬r*sinm+b£©
	//A2=A1*PI/180
	//A1=A2*180/PI
	//360 * pi / 180;
};

class object {
public:
	POINT position_LT;
	POINT position_RB;
	POINT position_CT;
	SURFACEINFO img;
	int disFrame;
	int maxFrame;
	int Width;
	int Height;
	int Row;
	int Column;
	int sk_round;

	object();
	object(int x, int y, HDC hdc, char *file, COLORREF colorkey, int maxFrame);
	object(int x, int y, HDC hdc, char *file, COLORREF colorkey, int _maxFrame, map *map);
	~object();

	object(const object& ob);
	//void operator=(const object& ob);

	void drawobject(HDC hdc);
	void updatestate();
	void updatestate(int row, int column, map *_map);
	void updatestate(POINT _CT);
	void movedown(int speed);



};