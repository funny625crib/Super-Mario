#pragma once
#include "Float2.h"
#include "Enemys.h"
#include "Map.h"

const int GOOMBA_MAX = 15;
	class Goomba :public __Enenys::_Enemys {


	public://e
		void Set_Pos(int h, int w);
		int death_count;
		int  first_pos_x;
		int  first_pos_y;
		bool check_display_on_ = true;
		Float2 Pos_;
		int map_pos_x;
		int map_pos_y;
		Float2 move_ = { 1.0f,0.0f };
		int image_[2];
		int image_death_;
		float map_move_;
		int goomba_flashing_flame;
		int image_index;
		bool hit_player=false;
		int count_enemy_num=0;
		int map_data[MAP_H][MAP_W];

		int goomba_x;
			int goomba_y;
		void Init(int map, int h, int w);
		void Update(Float2& player_pos,float player_r, bool map_move_check,bool player_janp,Float2 map_move_pos);
		void Render();
		void Exit();

		
	private:




	};
