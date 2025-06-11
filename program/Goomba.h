#pragma once
#include "Float2.h"
#include "Enemys.h"
#include "Map.h"

const int GOOMBA_MAX = 15;
	class Goomba :public __Enenys::_Enemys {

	public://e
		
		int image_[2];
		int image_death_;
		float map_move_;
		int goomba_flashing_flame;
		int image_index;
		bool hit_player=false;
		int count_enemy_num=0;
		int map_data[MAP_H][MAP_W];
		void Init(int map,int h, int w);
		void Update(Float2& player_pos,float player_r, bool map_move_check);
		void Render(int& map, int h, int w);
		void Exit();

	private:




	};
