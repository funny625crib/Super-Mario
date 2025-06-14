#include "Main.h"
#include "Game.h"
#include "Float2.h"
#include "Random.h"
#include "Hit.h"
#include "Goomba.h"
__Enenys::_Enemys _Goomba;

void Goomba::Goomba_Hit_Map_Init(int map_deta, int w_, int h_)
{

	//for (int i = 0; i < index; ++i) {

		if (map_deta == 5) {
			map_pos_x_pipe[ind] = w_ * 35;
			map_pos_y_pipe[ind] = h_ * 35;
			ind++;
		}

		if (map_deta == 1) {
			map_pos_x_ground[index_ground] = w_ * 35;
			map_pos_y_ground[index_ground] = h_ * 35;
			index_ground++;

		}
		if (map_deta == 2 || map_deta == 3) {
			map_pos_x_break_block[index_break_block] = w_ * 35;
			map_pos_y_break_block[index_break_block] = h_ * 35;

			index_break_block++;

		}


		//Init(map.map[first_pos_y][first_pos_x],first_pos_y, first_pos_x);
		//ind[i] = 0;
	//}

}


void Goomba::Goomba_Hit_Map(Float2 map_pos)
{
	for (int a = 0; a < ind; ++a) {
		if (CheckCircleBoxHit(Pos_.x, Pos_.y, 35, map_pos_x_pipe[a] + map_pos.x, map_pos_y_pipe[a], 35, 35)) {
			if (map_pos_x_pipe[a] + map_pos.x < Pos_.x && Pos_.x < map_pos_x_pipe[a] + map_pos.x + 35) {
				float dis = (map_pos_x_pipe[a] + map_pos.x) - Pos_.x;
				float dis2 = (map_pos_x_pipe[a] + map_pos.x + 35) - Pos_.x;
				if (dis > dis2) {
					Pos_.x = map_pos_x_pipe[a] + map_pos.x + 35 + 5;
				}
				else {
					Pos_.x = map_pos_x_pipe[a] + map_pos.x - 5;
				}

			}
			move_ *= -1;

		}

	}
	for (int a = 0; a < index_ground; ++a) {
		//if (CheckCircleBoxHit(goomba[i].Pos_.x, goomba[i].Pos_.y, 35, goomba[i].map_pos_x_ground[a] + map.pos_.x, goomba[i].map_pos_y_ground[a], 35, 35)) {
		//
		//	goomba[i].Pos_.y = goomba[i].map_pos_y_ground[a] - 35 / 2 - 1;
		//}
		if (CheckPointBoxHit(Pos_.x, Pos_.y + 35 / 2, map_pos_x_ground[a] + map_pos.x, map_pos_y_ground[a], 35, 35)) {
			Pos_.y = map_pos_y_ground[a] - 35 / 2 - 1;
		}
	}

	for (int a = 0; a < index_break_block; ++a) {
		if (CheckCircleBoxHit(Pos_.x, Pos_.y, 35, map_pos_x_break_block[a] + map_pos.x, map_pos_y_break_block[a], 35, 35)) {

			Pos_.y = map_pos_y_break_block[a] - 35 / 2 - 1;
		}
		//if (CheckPointBoxHit(goomba[i].Pos_.x, goomba[i].Pos_.y+35/2,  goomba[i].map_pos_x_break_block[a] + map.pos_.x, goomba[i].map_pos_y_break_block[a], 35, 35)) {
		//	goomba[i].Pos_.y = goomba[i].map_pos_y_break_block[a] - 35 / 2 - 1;
		//}
	}
	Pos_.y += 3.0f;
}


void Goomba::Reset_()
{
	image_index = 0;
	index_ground = 0;
	index_break_block = 0;
	index = 0;
	ind = 0;

}

//}
	//クリボー
void Goomba::Init(int map, int h, int w)
{

	image_[0] = LoadGraph("data/Super Mario/enemy/0.png");
	image_[1] = LoadGraph("data/Super Mario/enemy/1.png");
	image_death_ = LoadGraph("data/Super Mario/enemy/2.png");
	goomba_flashing_flame = 0;
	
	/*_Goomba.pos.x = (float)w * GROUND_SIZE;
	_Goomba.pos.y = (float)h * GROUND_SIZE;*/
	_Goomba.pos.x = 1.0f * w * GROUND_SIZE;
	_Goomba.pos.y = 1.0f * h * GROUND_SIZE + GROUND_SIZE / 2;
	Pos_ = _Goomba.pos;
	//_Goomba.pos = Pos_;
	check_display_on_ = true;

}

void Goomba::Update(Float2& player_pos, float player_r, bool map_move_check, bool player_janp, Float2 map_move_pos, bool& hit_player, bool& player_enemy_hit, bool& player_enemy_jump)
{

	//クリボーの画像を左右反転させて歩いているように見せるcount_enemy_num
	++goomba_flashing_flame;
	if (goomba_flashing_flame > 10) {
		image_index += 1;
		if (image_index >= 2) {
			image_index = 0;
		}
		goomba_flashing_flame = 0;
	}
	//クリボー同士が当たった時に反転させる
	//for (int i = 0; i < GOOMBA_MAX; ++i) {
	if (check_display_on_ == false) {
		death_count += 1;
		//continue;
	}
	goomba_x = (Pos_.x - map_move_pos.x) / GROUND_SIZE;
	goomba_y = Pos_.y / GROUND_SIZE;



	//	for (int h = 0; h < MAP_H; ++h) {
			//for (int w = 0; w < MAP_W; ++w) {
				//if (CheckCircleBoxHit(Pos_.x, Pos_.y, 35, x - map_move_pos.x, y, 35, 35)/* && map_data[goomba_y][goomba_x] != 0 && map_data[goomba_y][goomba_x] != 9 */) {
				//	move_ *= -1;
				//
				//}
				//if (/*CheckCircleBoxHit( player_pos, player_r, ) &&*/ map_data[goomba_y][goomba_x ] != 0 && map_data[goomba_y][goomba_x ] != 9) {
				//if (CheckCircleBoxHit(Pos_.x, Pos_.y, 35, x - map_move_pos.x, y, 35, 35)/* && map_data[goomba_y][goomba_x] != 0 && map_data[goomba_y][goomba_x] != 9 */) {
				//
				//	move_ *= -1;
				//
				//}
		//	}
	//	}
		//for (int a = i; a < GOOMBA_MAX; ++a) {
		//	if (i == a)continue;
		//
		//	if (_Goomba.check_display_on_ == false) continue;
		//
		//	if (CheckCircleHit(_Goomba.pos, 17, _Goomba.pos, 17)) {
		//		_Goomba.move_ *= -1;
		//		_Goomba.move_ *= -1;
		//	}
		//
		//}goomba_flashing_flame
	Float2 pos_pla;
	pos_pla.x = player_pos.x;
	pos_pla.y = player_pos.y+35/2;

	if (CheckCircleHit(Pos_, 32, pos_pla, player_r) && player_janp == false && check_display_on_ == true&& player_enemy_hit==false) {
		//_Goomba[i].move_ *= -1;
		check_display_on_ = false;
		//hit_player = true;
		player_enemy_jump = true;
	}
	else if (CheckCircleHit(Pos_, 32, pos_pla, player_r) && player_janp == true && check_display_on_ == true) {
		//move_ *= -1;
		player_enemy_hit = true;
	}


	//}


	float speed_map = 0.0f;
	if (map_move_check == true) {
		speed_map = 2.5f;

	}


	Pos_.x -= move_.x + speed_map;;




	//for (int h = 0; h < MAP_H; ++h) {
	//	for (int w = 0; w < MAP_W; ++w) {




	//		pos_w = _Goomba.pos.x / 35;
	//		pos_h = _Goomba.pos.y / 35;

	//		if (pos_w + 1 <= MAP_W - 1 && map_data[pos_h][pos_w + 1] == 1) {

	//			_Goomba.move_ *= -1;

	//		}
	//		if (pos_w - 1 >= 0 && map_data[pos_h][pos_w - 1] == 1) {

	//			_Goomba.move_ *= -1;

	//		}

	//		if (pos_h + 1 <= MAP_H - 1) {
	//			if (map_data[pos_h + 1][pos_w] == 1) {
	//				_Goomba.movey_ = 0;
					//_Goomba.pos.y = bloc_p_y[pos_h];
	//			}
	//		}



	//	}
	//}



	//Pos_.x -= move_.x;

}

void Goomba::Render()
{



	//DrawRotaGraph(map, map,2.0f,0, image_[image_index], TRUE);
	//for (int i = 0; i < count_enemy_num; ++i) {
	if (check_display_on_ == true) {
		//	DrawGraph(_Goomba.pos.x, _Goomba.pos.y, image_[image_index], TRUE);
		DrawRotaGraph(Pos_.x, Pos_.y, 2.0f, 0, image_[image_index], TRUE);
	}
	if (death_count < 30) {
		if (check_display_on_ == false) {
			//DrawGraph(_Goomba.pos.x, _Goomba.pos.y, image_death_, TRUE);
			DrawRotaGraph(Pos_.x, Pos_.y, 2.0f, 0, image_death_, TRUE);
		}
	}
	//	DrawLineBox(goomba_x*35, goomba_y*35, goomba_x * 35 + 35, goomba_y * 35 + 35, GetColor(255, 255, 255));
	//}
	//DrawFormatString(0, 0, GetColor(255, 255, 255), "%f", _Goomba.pos.x);
	//DrawFormatString(0, 0, GetColor(255, 255, 255), "%d", count_enemy_num);
	//DrawFormatString(300, 30, GetColor(255, 255, 255), "%d", first_pos_x);
	//DrawFormatString(300, 50, GetColor(255, 255, 255), "%d", first_pos_y);
}

void Goomba::Exit()
{
	DeleteGraph(image_[0]);
	DeleteGraph(image_[1]);
	DeleteGraph(image_death_);
}
