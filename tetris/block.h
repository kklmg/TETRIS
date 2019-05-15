#pragma once
#include"graphicengine.h"
#include"map.h"
class map;

class __grid {
	int Row;
	int Column;
};
class block {
public:
	int style;
	int state;
	int type;
	int block_length;
	
	POINT position_TL[4];
	POINT position_BR[4];
	POINT position_center[4];
	POINT position_Grid[4];

	friend map;

	//block(int length, map *_map);
	block();
	~block();
	block(const block& blk);
	void updatestock(map *map);
	void operator=(const block& blk);
	
};


//void drawblock(HDC backdc, block *blk, SURFACEINFO* psInfo,int x, int y);
void drawblock(HDC backdc, block *blk, SURFACEINFO* psInfo, int maxFrame, int disFrame,  int x, int y);




 

