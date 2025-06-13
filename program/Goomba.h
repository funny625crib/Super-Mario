#pragma once
#include "Float2.h"
#include "Enemys.h"
#include "Map.h"
//ÉNÉäÉ{Å[
const int GOOMBA_MAX = 15;
	class Goomba :public __Enenys::_Enemys {


	public://e
		void Set_Pos(int h, int w);
		int death_count;
		//int ind = 0;
		int  first_pos_x;
		int  first_pos_y;


		int index_ground;
		int map_pos_x_ground[1000];
		int map_pos_y_ground[1000];

		int index_break_block;
		int map_pos_x_break_block[100];
		int map_pos_y_break_block[100];

		bool check_display_on_ = true;
		Float2 Pos_;
		int map_pos_x_pipe[200];
		int map_pos_y_pipe[200];
		Float2 move_ = { 1.0f,0.0f };
		int image_[2];
		int image_death_;
		float map_move_;
		int goomba_flashing_flame;
		int image_index;
		bool hit_player=false;
		int count_enemy_num=0;
		int map_data[MAP_H][MAP_W];
		bool hit_wall = false;
		int goomba_x;
			int goomba_y;
		void Init(int map, int h, int w);
		void Update(Float2& player_pos,float player_r, bool map_move_check,bool player_janp,Float2 map_move_pos,   bool& hit_player);
		void Render();
		void Exit();

		
	private:




	};
