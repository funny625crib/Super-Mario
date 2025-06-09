#include "agaric.h"
#include "map.h"
#include "Game.h"
#include "Main.h"


//---------------------------------------------------------------------------------
//	初期化処理
//---------------------------------------------------------------------------------
void Agaric::Init()
{
	image_ = LoadGraph("data/map/agaric.png");   //キリコ画像を初期化する
	pos_ = { 20 * GROUND_SIZE,8 * GROUND_SIZE };  //座標を初期化する
	mode_ = MODE_WAIT;                            //キノコのモードを初期化する
	speed = 1.0f;
}
//---------------------------------------------------------------------------------
//	更新処理
//---------------------------------------------------------------------------------
void Agaric::Update(int pos_x, int pos_y, bool is_hit, int map_pos_x)
{


	switch (mode_)
	{
	case MODE_WAIT:
		//プレイヤーはキノコがある箱に当たる前に
			//キノコと箱の座標が同じ
		if (is_hit == false)
		{
			pos_.x = (float)(pos_x);
			pos_.y = (float)(pos_y);
		}
		else
		{
			mode_ = MODE_APPEAR;
		}
		break;
	case MODE_APPEAR:

		pos_.y--;
		if (pos_.y < (float)(pos_y - GROUND_SIZE))
		{
			pos_.y = (float)(pos_y - GROUND_SIZE);
			pos_.x = (float)(pos_x);
			mode_ = MODE_MOVE;
		}
		break;

	case MODE_MOVE:
		pos_.x += speed;
		
		break;

	case MODE_DISAPPEAR:

		break;
	}

}
//---------------------------------------------------------------------------------
//	描画処理
//---------------------------------------------------------------------------------
void Agaric::Render()
{
	if (mode_ != MODE_DISAPPEAR)
	{
		DrawGraph(pos_.x, pos_.y, image_, TRUE);
	}

	DrawFormatString(10, 40, GetColor(255, 255, 255), "speed:%f", speed);
}
//---------------------------------------------------------------------------------
//	終了処理
//---------------------------------------------------------------------------------
void Agaric::Exit()
{
	DeleteGraph(image_);
}
