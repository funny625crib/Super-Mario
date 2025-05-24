#include "Main.h"
#include "Game.h"
#include "Float2.h"
#include "Random.h"
#include "Hit.h"
#include "Goomba.h"
__Enenys::_Enemys _Goomba[GOOMBA_MAX];
 
void Goomba::GoombaInit()
{
	for (int i = 0; i < 1; ++i) {
		_Goomba[i].pos = { 800.0f,400.0f };
	}
	for (int i = 1; i < GOOMBA_MAX; ++i) {
		_Goomba[i].pos = { 500.0f,400.0f };
	}
	image[0] = LoadGraph("data/Goomba/Goomba.png");
	image[1] = LoadGraph("data/Goomba/Goomba2.png");
	goomba_flashing_flame = 0;
	image_index = 0;
}

void Goomba::GoombaUpdate()
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
		for (int a = i; a < GOOMBA_MAX; ++a) {
			if (i == a)continue;
			if (CheckCircleHit(_Goomba[i].pos, 17, _Goomba[a].pos, 17)) {
				move *= -1;

			}
		}
	}
	//クリボーの移動処理
	//for (int i = 0; i < GOOMBA_MAX; ++i) {
	//	_Goomba[i].pos.x -= 0.5f;
	//}
	for (int i = 0; i < 1; ++i) {
		_Goomba[i].pos.x -= move;
	}
	for (int i = 1; i < GOOMBA_MAX; ++i) {
		_Goomba[i].pos.x += move;
	}
}

void Goomba::GoombaRender()
{
	for (int i = 0; i < GOOMBA_MAX; ++i) {
		DrawRotaGraph(_Goomba[i].pos.x, _Goomba[i].pos.y,2,0, image[image_index], TRUE);
	}
	//DrawFormatString(0, 0, GetColor(255, 255, 255), "%d",image_index);
}

void Goomba::GoombaExit()
{
	DeleteGraph(image[0]);
	DeleteGraph(image[1]);
}
