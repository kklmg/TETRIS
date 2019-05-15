#include"block.h"

block::~block() {

};
void block::updatestock(map *_map)
{
	if (state >3) state = 0;
	switch (style) {
		
	case 1: {
		switch (state) {
			
		case 1://state
			////////////////update block.left-top positon////////////////////////
			position_TL[1].x = position_TL[0].x + block_length;
			position_TL[1].y = position_TL[0].y - block_length;

			position_TL[2].x = position_TL[0].x + block_length;
			position_TL[2].y = position_TL[0].y;

			position_TL[3].x = position_TL[0].x;
			position_TL[3].y = position_TL[0].y + block_length;

			break;

		case 2:

			position_TL[1].x = position_TL[0].x + block_length;
			position_TL[1].y = position_TL[0].y + block_length;

			position_TL[2].x = position_TL[0].x;
			position_TL[2].y = position_TL[0].y + block_length;

			position_TL[3].x = position_TL[0].x - block_length;
			position_TL[3].y = position_TL[0].y;
			break;
		
		case 3:
			position_TL[1].x = position_TL[0].x - block_length;
			position_TL[1].y = position_TL[0].y + block_length;

			position_TL[2].x = position_TL[0].x - block_length;
			position_TL[2].y = position_TL[0].y;

			position_TL[3].x = position_TL[0].x;
			position_TL[3].y = position_TL[0].y - block_length;
			break;
			

		case 0:
			position_TL[1].x = position_TL[0].x - block_length;
			position_TL[1].y = position_TL[0].y - block_length;

			position_TL[2].x = position_TL[0].x;
			position_TL[2].y = position_TL[0].y - block_length;

			position_TL[3].x = position_TL[0].x + block_length;
			position_TL[3].y = position_TL[0].y;
			break;
		}
	}break;
		//style
	case 2: {
		switch (state) {

		case 1://state
			position_TL[1].x = position_TL[0].x + block_length;
			position_TL[1].y = position_TL[0].y;

			position_TL[2].x = position_TL[0].x + block_length;
			position_TL[2].y = position_TL[0].y + block_length;

			position_TL[3].x = position_TL[0].x;
			position_TL[3].y = position_TL[0].y - block_length;
			break;

		case 2:

			position_TL[1].x = position_TL[0].x;
			position_TL[1].y = position_TL[0].y + block_length;

			position_TL[2].x = position_TL[0].x - block_length;
			position_TL[2].y = position_TL[0].y + block_length;

			position_TL[3].x = position_TL[0].x + block_length;
			position_TL[3].y = position_TL[0].y;
			break;


		case 3:
			position_TL[1].x = position_TL[0].x - block_length;
			position_TL[1].y = position_TL[0].y;

			position_TL[2].x = position_TL[0].x - block_length;
			position_TL[2].y = position_TL[0].y - block_length;

			position_TL[3].x = position_TL[0].x;
			position_TL[3].y = position_TL[0].y + block_length;
			break;


		case 0:
			position_TL[1].x = position_TL[0].x;
			position_TL[1].y = position_TL[0].y - block_length;

			position_TL[2].x = position_TL[0].x + block_length;
			position_TL[2].y = position_TL[0].y - block_length;

			position_TL[3].x = position_TL[0].x - block_length;
			position_TL[3].y = position_TL[0].y;
			break;
		}}break;
	case 3: {
		switch (state) {

		case 1://state
			position_TL[1].x = position_TL[0].x;
			position_TL[1].y = position_TL[0].y - block_length;

			position_TL[2].x = position_TL[0].x;
			position_TL[2].y = position_TL[0].y + block_length;

			position_TL[3].x = position_TL[0].x;
			position_TL[3].y = position_TL[0].y + 2 * block_length;
			break;

		case 2:

			position_TL[1].x = position_TL[0].x + block_length;
			position_TL[1].y = position_TL[0].y;

			position_TL[2].x = position_TL[0].x - block_length;
			position_TL[2].y = position_TL[0].y;

			position_TL[3].x = position_TL[0].x - 2 * block_length;
			position_TL[3].y = position_TL[0].y;
			break;


		case 3:
			position_TL[1].x = position_TL[0].x;
			position_TL[1].y = position_TL[0].y + block_length;

			position_TL[2].x = position_TL[0].x;
			position_TL[2].y = position_TL[0].y - block_length;

			position_TL[3].x = position_TL[0].x;
			position_TL[3].y = position_TL[0].y - 2 * block_length;
			break;


		case 0:
			position_TL[1].x = position_TL[0].x - block_length;
			position_TL[1].y = position_TL[0].y;

			position_TL[2].x = position_TL[0].x + block_length;
			position_TL[2].y = position_TL[0].y;

			position_TL[3].x = position_TL[0].x + 2 * block_length;
			position_TL[3].y = position_TL[0].y;
			break;
		}}break;
	case 4: {
		switch (state) {

		case 1:  
			position_TL[1].x = position_TL[0].x + block_length;
			position_TL[1].y = position_TL[0].y;

			position_TL[2].x = position_TL[0].x;
			position_TL[2].y = position_TL[0].y - block_length;

			position_TL[3].x = position_TL[0].x;
			position_TL[3].y = position_TL[0].y + block_length;
			break;

		case 2:

			position_TL[1].x = position_TL[0].x;
			position_TL[1].y = position_TL[0].y + block_length;

			position_TL[2].x = position_TL[0].x + block_length;
			position_TL[2].y = position_TL[0].y;

			position_TL[3].x = position_TL[0].x - block_length;
			position_TL[3].y = position_TL[0].y;
			break;


		case 3:

			position_TL[1].x = position_TL[0].x - block_length;
			position_TL[1].y = position_TL[0].y;

			position_TL[2].x = position_TL[0].x;
			position_TL[2].y = position_TL[0].y + block_length;

			position_TL[3].x = position_TL[0].x;
			position_TL[3].y = position_TL[0].y - block_length;
			break;


		case 0:
			position_TL[1].x = position_TL[0].x;
			position_TL[1].y = position_TL[0].y - block_length;

			position_TL[2].x = position_TL[0].x - block_length;
			position_TL[2].y = position_TL[0].y;

			position_TL[3].x = position_TL[0].x + block_length;
			position_TL[3].y = position_TL[0].y;
			break;
		}}break;
		
	case 5: {

		switch (state) {

		case 1:
			position_TL[1].x = position_TL[0].x + block_length;
			position_TL[1].y = position_TL[0].y;

			position_TL[2].x = position_TL[0].x + block_length;
			position_TL[2].y = position_TL[0].y + block_length;

			position_TL[3].x = position_TL[0].x;
			position_TL[3].y = position_TL[0].y + block_length;
			break;

		case 2:

			position_TL[1].x = position_TL[0].x;
			position_TL[1].y = position_TL[0].y + block_length;

			position_TL[2].x = position_TL[0].x - block_length;
			position_TL[2].y = position_TL[0].y + block_length;

			position_TL[3].x = position_TL[0].x - block_length;
			position_TL[3].y = position_TL[0].y;
			break;


		case 3:

			position_TL[1].x = position_TL[0].x - block_length;
			position_TL[1].y = position_TL[0].y;

			position_TL[2].x = position_TL[0].x - block_length;
			position_TL[2].y = position_TL[0].y - block_length;

			position_TL[3].x = position_TL[0].x;
			position_TL[3].y = position_TL[0].y - block_length;
			break;


		case 0:

			position_TL[1].x = position_TL[0].x;
			position_TL[1].y = position_TL[0].y - block_length;

			position_TL[2].x = position_TL[0].x + block_length;
			position_TL[2].y = position_TL[0].y - block_length;

			position_TL[3].x = position_TL[0].x + block_length;
			position_TL[3].y = position_TL[0].y;
			break;
		}}break;
	case 6: {

		switch (state) {

		case 1:
			position_TL[1].x = position_TL[0].x + block_length;
			position_TL[1].y = position_TL[0].y - block_length;

			position_TL[2].x = position_TL[0].x;
			position_TL[2].y = position_TL[0].y - block_length;

			position_TL[3].x = position_TL[0].x;
			position_TL[3].y = position_TL[0].y + block_length;
			break;

		case 2:

			position_TL[1].x = position_TL[0].x + block_length;
			position_TL[1].y = position_TL[0].y + block_length;

			position_TL[2].x = position_TL[0].x + block_length;
			position_TL[2].y = position_TL[0].y;

			position_TL[3].x = position_TL[0].x - block_length;
			position_TL[3].y = position_TL[0].y;
			break;



		case 3:

			position_TL[1].x = position_TL[0].x - block_length;
			position_TL[1].y = position_TL[0].y + block_length;

			position_TL[2].x = position_TL[0].x;
			position_TL[2].y = position_TL[0].y + block_length;

			position_TL[3].x = position_TL[0].x;
			position_TL[3].y = position_TL[0].y - block_length;
			break;


		case 0:


			position_TL[1].x = position_TL[0].x - block_length;
			position_TL[1].y = position_TL[0].y - block_length;

			position_TL[2].x = position_TL[0].x - block_length;
			position_TL[2].y = position_TL[0].y;

			position_TL[3].x = position_TL[0].x + block_length;
			position_TL[3].y = position_TL[0].y;
			break;
		}}break;
	case 7: {

		switch (state) {

		case 1:
			
			position_TL[1].x = position_TL[0].x + block_length;
			position_TL[1].y = position_TL[0].y + block_length;

			position_TL[2].x = position_TL[0].x;
			position_TL[2].y = position_TL[0].y - block_length;

			position_TL[3].x = position_TL[0].x;
			position_TL[3].y = position_TL[0].y + block_length;
			break;

		case 2:

			position_TL[1].x = position_TL[0].x - block_length;
			position_TL[1].y = position_TL[0].y + block_length;

			position_TL[2].x = position_TL[0].x + block_length;
			position_TL[2].y = position_TL[0].y;

			position_TL[3].x = position_TL[0].x - block_length;
			position_TL[3].y = position_TL[0].y;
			break;

		case 3:

			position_TL[1].x = position_TL[0].x - block_length;
			position_TL[1].y = position_TL[0].y - block_length;

			position_TL[2].x = position_TL[0].x;
			position_TL[2].y = position_TL[0].y + block_length;

			position_TL[3].x = position_TL[0].x;
			position_TL[3].y = position_TL[0].y - block_length;
			break;


		case 0:

			position_TL[1].x = position_TL[0].x + block_length;
			position_TL[1].y = position_TL[0].y - block_length;

			position_TL[2].x = position_TL[0].x - block_length;
			position_TL[2].y = position_TL[0].y;

			position_TL[3].x = position_TL[0].x + block_length;
			position_TL[3].y = position_TL[0].y;

			break;


		}
		
		   }break;
	}
	////////////////////update block.right-bottom position/////////////////////////
	position_BR[0].x = position_TL[0].x + block_length;
	position_BR[0].y = position_TL[0].y + block_length;

	position_BR[1].x = position_TL[1].x + block_length;
	position_BR[1].y = position_TL[1].y + block_length;

	position_BR[2].x = position_TL[2].x + block_length;
	position_BR[2].y = position_TL[2].y + block_length;

	position_BR[3].x = position_TL[3].x + block_length;
	position_BR[3].y = position_TL[3].y + block_length;
	////////////////////update block.center position//////////////////////////////
	position_center[0].x = (position_BR[0].x - position_TL[0].x) / 2;
	position_center[0].y = (position_BR[0].y - position_TL[0].y) / 2;

	position_center[1].x = (position_BR[1].x - position_TL[1].x) / 2;
	position_center[1].y = (position_BR[1].y - position_TL[1].y) / 2;

	position_center[2].x = (position_BR[2].x - position_TL[2].x) / 2;
	position_center[2].y = (position_BR[2].y - position_TL[2].y) / 2;

	position_center[3].x = (position_BR[3].x - position_TL[3].x) / 2;
	position_center[3].y = (position_BR[3].y - position_TL[3].y) / 2;
	////////////////////update block in map //////////////////////////////
	/////   y==row
	/////   x==column
	position_Grid[0].x = (position_TL[0].x - _map->position_LT.x) / block_length ;
	position_Grid[0].y = (position_TL[0].y - _map->position_LT.y) / block_length ;

	position_Grid[1].x = (position_TL[1].x - _map->position_LT.x) / block_length ;
	position_Grid[1].y = (position_TL[1].y - _map->position_LT.y) / block_length ;

	position_Grid[2].x = (position_TL[2].x - _map->position_LT.x) / block_length;
	position_Grid[2].y = (position_TL[2].y - _map->position_LT.y) / block_length;

	position_Grid[3].x = (position_TL[3].x - _map->position_LT.x) / block_length;
	position_Grid[3].y = (position_TL[3].y - _map->position_LT.y) / block_length;
}

//void drawblock_(HDC backdc, block *blk, SURFACEINFO* psInfo, int x, int y) {
//
//	__gePutSprite(backdc, blk->cx + x, blk->cy + y, psInfo);
//	__gePutSprite(backdc, blk->x1 + x, blk->y1 + y, psInfo);
//	__gePutSprite(backdc, blk->x2 + x, blk->y2 + y, psInfo);
//	__gePutSprite(backdc, blk->x3 + x, blk->y3 + y, psInfo);
//
//}
void drawblock(HDC backdc, block *blk, SURFACEINFO* psInfo,int maxFrame,int disFrame, int x, int y) {
	
	__gePutSprite_m(backdc, blk->position_TL[0].x + x, blk->position_TL[0].y, psInfo, maxFrame, disFrame);
	__gePutSprite_m(backdc, blk->position_TL[1].x + x, blk->position_TL[1].y, psInfo, maxFrame, disFrame);
	__gePutSprite_m(backdc, blk->position_TL[2].x + x, blk->position_TL[2].y, psInfo, maxFrame, disFrame);
	__gePutSprite_m(backdc, blk->position_TL[3].x + x, blk->position_TL[3].y, psInfo, maxFrame, disFrame);


}








