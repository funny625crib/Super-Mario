#include "Main.h"
#include "Game.h"
#include "Float2.h"
#include "Random.h"
#include "Hit.h"
#include "Goomba.h"
__Enenys::_Enemys _Goomba;

//void Goomba::Set_Pos(int h, int w)
//{
//	Pos_.Set((float)h, (float)w);
//}

void Goomba::Init(int map, int h, int w)
{

	image_[0] = LoadGraph("data/Super Mario/enemy/0.png");
	image_[1] = LoadGraph("data/Super Mario/enemy/1.png");
	image_death_ = LoadGraph("data/Super Mario/enemy/2.png");
	goomba_flashing_flame = 0;
	image_index = 0;

	/*_Goomba.pos.x = (float)w * GROUND_SIZE;
	_Goomba.pos.y = (float)h * GROUND_SIZE;*/
	_Goomba.pos.x = 1.0f * w * GROUND_SIZE;
	_Goomba.pos.y = 1.0f * h * GROUND_SIZE + GROUND_SIZE / 2;
	Pos_ = _Goomba.pos;
	//_Goomba.pos = Pos_;
	check_display_on_ = true;
	
}

void Goomba::Update(Float2& player_pos, float player_r, bool map_move_check,  bool player_janp, Float2 map_move_pos)
{

	//クリボーの画像を左右反転させて歩いているように見せる
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
		goomba_x = (Pos_.x- map_move_pos.x) / GROUND_SIZE;
		goomba_y = Pos_.y / GROUND_SIZE;
		
		

		for (int h = 0; h < MAP_H; ++h) {
			for (int w = 0; w < MAP_W; ++w) {
				if (CheckCircleBoxHit(Pos_.x, Pos_.y, 35, map_pos_x- map_move_pos.x, map_pos_y, 35, 35)/* && map_data[goomba_y][goomba_x] != 0 && map_data[goomba_y][goomba_x] != 9 */) {
					move_ *= -1;

				}
				//if (/*CheckCircleBoxHit( player_pos, player_r, ) &&*/ map_data[goomba_y][goomba_x ] != 0 && map_data[goomba_y][goomba_x ] != 9) {
				if (CheckCircleBoxHit(Pos_.x, Pos_.y, 35, (goomba_x - 1) * 35, goomba_y * 35, 35, 35)/* && map_data[goomba_y][goomba_x] != 0 && map_data[goomba_y][goomba_x] != 9 */) {

					move_ *= -1;

				}
			}
		}
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
		//}
		if (CheckCircleHit(Pos_, 32, player_pos, player_r) ) {
			move_ *= -1;
		}
	if (CheckCircleHit(Pos_, 32, player_pos, player_r)&& player_janp==false) {
		//_Goomba[i].move_ *= -1;
		check_display_on_ = false;
		hit_player = true;
	}

	//}


	float speed_map = 0;
	if (map_move_check == true) {
		speed_map = 2.5f;
	}
	Pos_.x -= move_.x + speed_map;;


	int  pos_w;
	int  pos_h;

	for (int h = 0; h < MAP_H; ++h) {
		for (int w = 0; w < MAP_W; ++w) {




			pos_w = _Goomba.pos.x / 35;
			pos_h = _Goomba.pos.y / 35;

			if (pos_w + 1 <= MAP_W - 1 && map_data[pos_h][pos_w + 1] == 1) {

				_Goomba.move_ *= -1;

			}
			if (pos_w - 1 >= 0 && map_data[pos_h][pos_w - 1] == 1) {

				_Goomba.move_ *= -1;

			}

			if (pos_h + 1 <= MAP_H - 1) {
				if (map_data[pos_h + 1][pos_w] == 1) {
					_Goomba.movey_ = 0;
					//_Goomba[i].pos.y = bloc_p_y[pos_h];
				}
			}



		}
	}



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
