#pragma once
#include "Float2.h"
#include "Object.h"
#include "Map.h"
class Goal :public __Obj::_Object {


public://e
	
	int index_ground;
	int map_pos_x_ground[1000];
	int map_pos_y_ground[1000];

	int  first_pos_x;
	int  first_pos_y;
	int map_move;
	int image_;
	Float2 Pos_;
	void Init(int map, int h, int w);
	void Update(Float2& player_pos, float player_r);
	void Render();
	void Exit();


private:




};
