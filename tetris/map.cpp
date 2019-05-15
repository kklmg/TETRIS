#include"map.h"

map::map(int x, int y, int Row, int Column, int length) {

	grid_length = length;
	position_LT.x = x;
	position_LT.y = y;
	position_RB.x = position_LT.x + Column  *length;
	position_RB.y = position_LT.y + Row *length;
	nWidth  = position_RB.x - position_LT.x;
	nHeight = position_RB.y - position_LT.y;
	nRow = Row;
	nColumn = Column;
	if (Row > 0 && Column > 0) {
		
		grid = new int*[Row];
		for (int i = 0; i < Row; i++) {
			grid[i] = new int[Column];
		}
			for (int i = 0; i <Row; i++)
				for (int j = 0; j < Column; j++) {
				grid[i][j] = 0;
			}
	}

	else grid = NULL;

	nLeftWall_x = position_LT.x;
	nRightWall_x = position_RB.x;
	nTopWall_y = position_LT.y;
	nBottom_wall_y = position_RB.y;

	TopObstacle = new int[Column];
	TopObrow = new int[Column];
	for (int i=0; i < Column; i++) {
		TopObstacle[i] = nBottom_wall_y;
		TopObrow[i] = Row;
	}

}
void map::resetgrid() {

	for (int i = 0; i <nRow; i++)
		for (int j = 0; j < nColumn; j++) {
			grid[i][j] = 0;
		}

}

void map::setgrid(int blocktype) {

	for (int i = 0; i <nRow; i++)
		for (int j = 0; j < nColumn; j++) {
			grid[i][j] = blocktype;
		}
}



map::~map() {

	//delete grid;
}
void map::ComputeTopOB_y() {

	for (int i = 0; i <nColumn; i++)
		for (int j = 0; j < nRow; j++) {
		if(grid[j][i]>0){		
			TopObstacle[i] = nTopWall_y+ j*grid_length;
			TopObrow[i] = j;
			break;
		}
		if (j == nRow - 1)
			TopObstacle[i] = nBottom_wall_y;
		}

}

int* random(int count, map *map)
{
	srand((unsigned)time(NULL));
	int *randfigure = new int[count];
	for (int i = 0; i < count;) {
		randfigure[i] = rand() % map->nColumn;
		for (int j = 0; j < i; j++) {
			if (randfigure[j] == randfigure[i])break;
			if (j == i) i++;
		}
	}
	return randfigure;
}
bool map::_gameover() {
	for (int i = 0; i < nColumn; i++) {
		if (grid[0][i] > 0) { return true; break; }
		if (i == nColumn - 1) return false;
	}

}

