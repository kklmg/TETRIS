#include"function.h"

bool CollideWall_Left(block *blk, map *_map) {
	if (blk->position_TL[0].x <= _map->nLeftWall_x
		|| blk->position_TL[1].x <= _map->nLeftWall_x
		|| blk->position_TL[2].x <= _map->nLeftWall_x
		|| blk->position_TL[3].x <= _map->nLeftWall_x)
		return true;
	else return false;
}
bool CollideWall_Right(block *blk, map *_map) {
	if (blk->position_BR[0].x >= _map->nRightWall_x
		|| blk->position_BR[1].x >= _map->nRightWall_x
		|| blk->position_BR[2].x >= _map->nRightWall_x
		|| blk->position_BR[3].x >= _map->nRightWall_x)
		return true;
	else return false;
}
bool CollideWall_Bottom(block *blk, map *_map) {
	if (blk->position_BR[0].y >= _map->nBottom_wall_y
		|| blk->position_BR[1].y >= _map->nBottom_wall_y
		|| blk->position_BR[2].y >= _map->nBottom_wall_y
		|| blk->position_BR[3].y >= _map->nBottom_wall_y)
		return true;
	else return false;
}
bool CollideWall_Top(block *blk, map *_map) {
	if (blk->position_TL[0].y > _map->nTopWall_y
		|| blk->position_TL[1].y > _map->nTopWall_y
		|| blk->position_TL[2].y > _map->nTopWall_y
		|| blk->position_TL[3].y > _map->nTopWall_y)
		return true;
	else return false;
}

bool CollideObstacle_Left(block *blk, map *_map) {
	if (_map->grid[blk->position_Grid[0].y][blk->position_Grid[0].x - 1] >= 1
		|| _map->grid[blk->position_Grid[1].y][blk->position_Grid[1].x - 1] >= 1
		|| _map->grid[blk->position_Grid[2].y][blk->position_Grid[2].x - 1] >= 1
		|| _map->grid[blk->position_Grid[3].y][blk->position_Grid[3].x - 1] >= 1)
		return true;

	else return false;
}
bool CollideObstacle_Right(block *blk, map *_map) {
	if (_map->grid[blk->position_Grid[0].y][blk->position_Grid[0].x + 1] >= 1
		|| _map->grid[blk->position_Grid[1].y][blk->position_Grid[1].x + 1] >= 1
		|| _map->grid[blk->position_Grid[2].y][blk->position_Grid[2].x + 1] >= 1
		|| _map->grid[blk->position_Grid[3].y][blk->position_Grid[3].x + 1] >= 1)
		return true;

	else return false;
}
bool CollideObstacle_Bottom(block *blk, map *_map) {
	if (_map->grid[blk->position_Grid[0].y + 1][blk->position_Grid[0].x] >= 1
		|| _map->grid[blk->position_Grid[1].y + 1][blk->position_Grid[1].x] >= 1
		|| _map->grid[blk->position_Grid[2].y + 1][blk->position_Grid[2].x] >= 1
		|| _map->grid[blk->position_Grid[3].y + 1][blk->position_Grid[3].x] >= 1)
		return true;

	else return false;
}


bool move_left(block *blk, map *_map) {

	blk->position_TL[0].x -= blk->block_length;
	blk->updatestock(_map);
	return true;
}

bool move_right(block *blk, map *_map) {

	blk->position_TL[0].x += blk->block_length;
	blk->updatestock(_map);

	return true;


}

bool move_bottom(block *blk, map *_map) {

	blk->position_TL[0].y += blk->block_length;
	blk->updatestock(_map);

	return true;

}

block::block() {
	style = 0;
	state = 0;
	type = 0;
	block_length = 0;
	for (int i = 0; i < 4; i++) {
		position_TL[i].x = 0;
		position_TL[i].y = 0;
		position_BR[i].x = 0;
		position_BR[i].y = 0;
		position_center[i].x = 0;
		position_center[i].y = 0;
		position_Grid[i].x = 0;
		position_Grid[i].y = 0;
	}

}
void block::operator=(const block& blk) {
	style = blk.style;
	state = blk.state;
	type = blk.type;
	block_length = blk.block_length;

	for (int i = 0; i < 4; i++) {
		position_TL[i].x = blk.position_TL[i].x;
		position_TL[i].y = blk.position_TL[i].y;
		position_BR[i].x = blk.position_BR[i].x;
		position_BR[i].y = blk.position_BR[i].y;
		position_center[i].x = blk.position_center[i].x;
		position_center[i].y = blk.position_center[i].y;
		position_Grid[i].x = blk.position_Grid[i].x;
		position_Grid[i].y = blk.position_Grid[i].y;
	}
}
block::block(const block& blk) {

	style = blk.style;
	state = blk.state;
	type = blk.type;
	block_length = blk.block_length;

	for (int i = 0; i < 4; i++) {
		position_TL[i].x = blk.position_TL[i].x;
		position_TL[i].y = blk.position_TL[i].y;
		position_BR[i].x = blk.position_BR[i].x;
		position_BR[i].y = blk.position_BR[i].y;
		position_center[i].x = blk.position_center[i].x;
		position_center[i].y = blk.position_center[i].y;
		position_Grid[i].x = blk.position_Grid[i].x;
		position_Grid[i].y = blk.position_Grid[i].y;
	}




}
bool CanRotate(block *blk, map *_map) {
	switch (blk->style) {
	case 1:
	case 2:
	case 4:
	case 6:
	case 7: {
		if (_map->grid[blk->position_Grid[0].y - 1][blk->position_Grid[0].x - 1] > 0
			|| _map->grid[blk->position_Grid[0].y - 1][blk->position_Grid[0].x] > 0
			|| _map->grid[blk->position_Grid[0].y - 1][blk->position_Grid[0].x + 1] > 0
			|| _map->grid[blk->position_Grid[0].y][blk->position_Grid[0].x - 1] > 0
			|| _map->grid[blk->position_Grid[0].y][blk->position_Grid[0].x + 1] > 0
			|| _map->grid[blk->position_Grid[0].y + 1][blk->position_Grid[0].x - 1] > 0
			|| _map->grid[blk->position_Grid[0].y][blk->position_Grid[0].x] > 0
			|| _map->grid[blk->position_Grid[0].y + 1][blk->position_Grid[0].x + 1] > 0)
			return false;
		else return true; }
			break;
	case 5: {switch (blk->state) {
		//type5:   [1][2]
		//         [C][3]
	case 0: {if (_map->grid[blk->position_Grid[0].y + 1][blk->position_Grid[0].x + 1] > 0
		|| _map->grid[blk->position_Grid[0].y + 1][blk->position_Grid[0].x] > 0)
		return false;
			else return true; }break;
	case 1: {if (_map->grid[blk->position_Grid[0].y][blk->position_Grid[0].x - 1] > 0
		|| _map->grid[blk->position_Grid[0].y + 1][blk->position_Grid[0].x - 1] > 0)
		return false;
			else return true; }break;
	case 2: {if (_map->grid[blk->position_Grid[0].y - 1][blk->position_Grid[0].x - 1] >0
		|| _map->grid[blk->position_Grid[0].y - 1][blk->position_Grid[0].x] > 0)
		return false;
			else return true; }break;
	case 3: {if (_map->grid[blk->position_Grid[0].y - 1][blk->position_Grid[0].x + 1] >0
		|| _map->grid[blk->position_Grid[0].y][blk->position_Grid[0].x + 1] > 0)
		return false;
			else return true; }break;
		/*case 0: {if (_map->grid[blk->position_Grid[0].y - 1][blk->position_Grid[0].x + 1] > 0
		|| _map->grid[blk->position_Grid[0].y][blk->position_Grid[0].x + 1] > 0)
		return false;
		else return true; }break;
		case 1: {if(_map->grid[blk->position_Grid[0].y+1][blk->position_Grid[0].x+1] > 0
		|| _map->grid[blk->position_Grid[0].y + 1][blk->position_Grid[0].x ] > 0)
		return false;
		else return true; }break;
		case 2: {if(_map->grid[blk->position_Grid[0].y][blk->position_Grid[0].x - 1] >0
		|| _map->grid[blk->position_Grid[0].y + 1][blk->position_Grid[0].x - 1] > 0)
		return false;
		else return true; }break;
		case 3: {if (_map->grid[blk->position_Grid[0].y+1][blk->position_Grid[0].x - 1] >0
		|| _map->grid[blk->position_Grid[0].y + 1][blk->position_Grid[0].x ] > 0)
		return false;
		else return true; }break;*/
	}
	}
			break;
	case 3: {
		switch (blk->state) {
		case 0: { if (_map->grid[blk->position_Grid[0].y - 1][blk->position_Grid[0].x - 1] > 0
			|| _map->grid[blk->position_Grid[0].y - 1][blk->position_Grid[0].x] > 0
			|| _map->grid[blk->position_Grid[0].y + 1][blk->position_Grid[0].x] > 0
			|| _map->grid[blk->position_Grid[0].y + 1][blk->position_Grid[0].x + 1] > 0
			|| _map->grid[blk->position_Grid[0].y + 1][blk->position_Grid[0].x + 2] > 0
			|| _map->grid[blk->position_Grid[0].y + 2][blk->position_Grid[0].x] > 0
			|| _map->grid[blk->position_Grid[0].y + 2][blk->position_Grid[0].x + 1] > 0
			|| _map->grid[blk->position_Grid[0].y + 2][blk->position_Grid[0].x + 2] > 0
			)return false;
			return true; }break;
		case 1: { if (_map->grid[blk->position_Grid[0].y - 1][blk->position_Grid[0].x + 1] > 0
			|| _map->grid[blk->position_Grid[0].y][blk->position_Grid[0].x + 1] > 0
			|| _map->grid[blk->position_Grid[0].y][blk->position_Grid[0].x - 1] > 0
			|| _map->grid[blk->position_Grid[0].y][blk->position_Grid[0].x - 2] > 0
			|| _map->grid[blk->position_Grid[0].y + 1][blk->position_Grid[0].x - 1] > 0
			|| _map->grid[blk->position_Grid[0].y + 1][blk->position_Grid[0].x - 2] > 0
			|| _map->grid[blk->position_Grid[0].y + 2][blk->position_Grid[0].x - 1] > 0
			|| _map->grid[blk->position_Grid[0].y + 2][blk->position_Grid[0].x - 2] > 0
			)return false;
			return true; }break;
		case 2: { if (_map->grid[blk->position_Grid[0].y + 1][blk->position_Grid[0].x + 1] > 0
			|| _map->grid[blk->position_Grid[0].y + 1][blk->position_Grid[0].x] > 0
			|| _map->grid[blk->position_Grid[0].y - 2][blk->position_Grid[0].x - 2] > 0
			|| _map->grid[blk->position_Grid[0].y - 2][blk->position_Grid[0].x - 1] > 0
			|| _map->grid[blk->position_Grid[0].y - 2][blk->position_Grid[0].x] > 0
			|| _map->grid[blk->position_Grid[0].y - 1][blk->position_Grid[0].x - 2] > 0
			|| _map->grid[blk->position_Grid[0].y - 1][blk->position_Grid[0].x - 1] > 0
			|| _map->grid[blk->position_Grid[0].y - 1][blk->position_Grid[0].x] > 0
			)return false;
			return true; }break;
		case 3: { if (_map->grid[blk->position_Grid[0].y][blk->position_Grid[0].x - 1] > 0
			|| _map->grid[blk->position_Grid[0].y + 1][blk->position_Grid[0].x - 1] > 0
			|| _map->grid[blk->position_Grid[0].y - 2][blk->position_Grid[0].x + 1] > 0
			|| _map->grid[blk->position_Grid[0].y - 2][blk->position_Grid[0].x + 2] > 0
			|| _map->grid[blk->position_Grid[0].y - 1][blk->position_Grid[0].x + 1] > 0
			|| _map->grid[blk->position_Grid[0].y - 1][blk->position_Grid[0].x + 2] > 0
			|| _map->grid[blk->position_Grid[0].y][blk->position_Grid[0].x + 1] > 0
			|| _map->grid[blk->position_Grid[0].y][blk->position_Grid[0].x + 2] > 0
			)return false;
			return true; }break;
		}
	}break;
	}
}
bool CanRotate_w(block *blk, map *_map) {

	block __block(*blk);


	block_rotate(&__block, _map);
	if (__block.position_TL[0].x < _map->nLeftWall_x
		|| __block.position_TL[1].x < _map->nLeftWall_x
		|| __block.position_TL[2].x < _map->nLeftWall_x
		|| __block.position_TL[3].x < _map->nLeftWall_x
		|| __block.position_BR[0].x > _map->nRightWall_x
		|| __block.position_BR[1].x > _map->nRightWall_x
		|| __block.position_BR[2].x > _map->nRightWall_x
		|| __block.position_BR[3].x > _map->nRightWall_x
		|| __block.position_BR[0].y > _map->nBottom_wall_y
		|| __block.position_BR[1].y > _map->nBottom_wall_y
		|| __block.position_BR[2].y > _map->nBottom_wall_y
		|| __block.position_BR[3].y > _map->nBottom_wall_y
		|| __block.position_TL[0].y < _map->nTopWall_y
		|| __block.position_TL[1].y < _map->nTopWall_y
		|| __block.position_TL[2].y < _map->nTopWall_y
		|| __block.position_TL[3].y < _map->nTopWall_y)
		return false;
	else return true;

}
void block_rotate(block *blk, map *_map)
{
	blk->state++;
	if (blk->state >3) blk->state = 0;
	blk->updatestock(_map);
}
bool __block_rotate(block *blk, map *_map) {

	if (CanRotate_w(blk, _map)) {
		if (CanRotate(blk, _map)) {
			block_rotate(blk, _map);
			return true;
		}
		else return false;

	}
	else return false;


}