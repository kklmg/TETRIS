#pragma once
#include"map.h"
#include"block.h"

bool CollideWall_Left(block *blk, map *_map);
bool CollideWall_Right(block *blk, map *_map);
bool CollideWall_Bottom(block *blk, map *_map);
bool CollideWall_Top(block *blk, map *_map);

bool CollideObstacle_Left(block *blk, map *_map);
bool CollideObstacle_Right(block *blk, map *_map);
bool CollideObstacle_Bottom(block *blk, map *_map);
bool move_left(block *blk, map *_map);
bool move_right(block *blk, map *_map);
bool move_bottom(block *blk, map *_map);
void block_rotate(block *blk, map *_map);
bool CanRotate(block *blk, map *_map);
bool CanRotate_w(block *blk, map *_map);
bool __block_rotate(block *blk, map *_map);