#pragma once
#include"graphicengine.h"
#include"block.h"
#include<time.h>
class map {
public:

	POINT position_LT;
	POINT position_RB;
	
	int nWidth;
	int nHeight;

	int nRow;
	int nColumn;

	int *TopObstacle;
	int *TopObrow;
	int grid_length;
	int **grid;

	int nLeftWall_x;
	int nRightWall_x;
	int nTopWall_y;
	int nBottom_wall_y;

	
	
	map(int x, int y,int width, int height,int length);
	~map();

	void ComputeTopOB_y();
	void resetgrid();
	void setgrid(int blocktype);
	bool _gameover();
};

int* random(int count, map *map);

