#include "Main.h"
#include "Game.h"
#include "Float2.h"
#include "Random.h"
#include "Hit.h"
#include "Goomba.h"
__Enenys::_Enemys _Goomba[GOOMBA_MAX];

void Goomba::Init()
{
	//for (int i = 0; i < count_enemy_num; ++i) {
	//	_Goomba[i].pos = { 800.0f,400.0f };
	//}
	//for (int i = 1; i < GOOMBA_MAX; ++i) {
	//	_Goomba[i].pos = { 500.0f,400.0f };
	//}
	image_[0] = LoadGraph("data/Super Mario/enemy/0.png");
	image_[1] = LoadGraph("data/Super Mario/enemy/1.png");
	image_death_ = LoadGraph("data/Goomba/Goomba_Death.png");
	goomba_flashing_flame = 0;
	image_index = 0;

	
	//for (int h = 0; h < MAP_H; ++h) {
		//for (int w = 0; w < MAP_W; ++w) {

			//if (map_data[h][w] == 5) {
				_Goomba[0].pos.x = 5 * GROUND_SIZE;
				_Goomba[0].pos.y = 10 * GROUND_SIZE;
				//count_enemy_num++;
			//}

		//}
	//}
	for (int i = 0; i < count_enemy_num; ++i) {
		//_Goomba[count_enemy_num].pos={}
	}

}

void Goomba::Update(Float2& player_pos, float player_r, float map_move )
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
	for (int i = 0; i < GOOMBA_MAX; ++i) {
		if (_Goomba[i].check_display_on_ == false) {
			_Goomba[i].death_count += 1;
			continue;
		}
		for (int a = i; a < GOOMBA_MAX; ++a) {
			if (i == a)continue;
	
			if (_Goomba[a].check_display_on_ == false) continue;
	
			if (CheckCircleHit(_Goomba[i].pos, 17, _Goomba[a].pos, 17)) {
				_Goomba[i].move_ *= -1;
				_Goomba[a].move_ *= -1;
			}
	
		}
		if (CheckCircleHit(_Goomba[i].pos, 17, player_pos, player_r)) {
			//_Goomba[i].move_ *= -1;
			_Goomba[i].check_display_on_ = false;
			hit_player = true;
		}
	
	}
	//クリボーの移動処理
	//for (int i = 0; i < GOOMBA_MAX; ++i) {
	//	_Goomba[i].pos.x -= 0.5f;
	//}
	int  pos_w;
	int  pos_h;
	//map_move_ = map_move;
	for (int i = 0; i < GOOMBA_MAX; ++i) {
		_Goomba[i].pos.x += map_move;
		
		//_Goomba[i].pos.y += _Goomba[i].movey_;
		//_Goomba[i].movey_ += 0.5f;
	}
	for (int w = 0; w < MAP_W; ++w) {
		//map_move_ -= map_move;
	}
	for (int h = 0; h < MAP_H; ++h) {
		for (int w = 0; w < MAP_W; ++w) {
		
	
			for (int i = 0; i < GOOMBA_MAX; ++i) {
	
				pos_w = _Goomba[i].pos.x / 35;
				pos_h = _Goomba[i].pos.y / 35;
				//DrawFillBox(bloc_p_x[pos_w] *35, bloc_p_y[pos_h], bloc_p_x[pos_w+1]*35, bloc_p_y[pos_h+1] , GetColor(255, 255, 255));
				//DrawFormatString(bloc_p_x[pos_w], bloc_p_y[pos_h], GetColor(0, 0, 0), "%d", pos_w);
				//DrawFormatString(bloc_p_x[pos_w], bloc_p_y[pos_h]+20, GetColor(0, 0, 0), "%d", pos_h);
	
				if (pos_w + 1 <= MAP_W - 1 && map_data[pos_h][pos_w + 1] == 1) {
				
						_Goomba[i].move_ *= -1;
					
				}
				if (pos_w - 1 >= 0 && map_data[pos_h][pos_w - 1] == 1) {
				
						_Goomba[i].move_ *= -1;
					
				}
	
				if (pos_h + 1 <= MAP_H - 1) {
					if (map_data[pos_h + 1][pos_w] == 1) {
						_Goomba[i].movey_ = 0;
						//_Goomba[i].pos.y = bloc_p_y[pos_h];
					}
				}
	
				
			}
		}
	}
	
	
	for (int i = 0; i < GOOMBA_MAX; ++i) {
		_Goomba[i].pos.x -= _Goomba[i].move_;
	}
}

void Goomba::Render(int& map,int h,int w)
{
	DrawRotaGraph(_Goomba[0].pos.x, _Goomba[0].pos.y, 2.0f, 0, image_[image_index], TRUE);
	//DrawRotaGraph(map, map,2.0f,0, image_[image_index], TRUE);
	for (int i = 0; i < count_enemy_num; ++i) {
		//if (_Goomba[i].check_display_on_ == true) {
			DrawGraph(_Goomba[0].pos.x, _Goomba[0].pos.y, image_[image_index], TRUE);

	//	}
		if (_Goomba[i].death_count < 30) {
			if (_Goomba[i].check_display_on_ == false) {
				DrawGraph(_Goomba[i].pos.x, _Goomba[i].pos.y, image_death_, TRUE);
			}
		}
	}
	//DrawFormatString(0, 0, GetColor(255, 255, 255), "%d",image_index);
	DrawFormatString(0, 0, GetColor(255, 255, 255), "%d", count_enemy_num);

}

void Goomba::Exit()
{
	DeleteGraph(image_[0]);
	DeleteGraph(image_[1]);
	DeleteGraph(image_death_);
}
