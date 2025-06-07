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
		pos_.x ++;
		if (pos_.x > (float)(pos_x + 4 * GROUND_SIZE))
		{
			pos_.x--;
			pos_.y+=2.0f;
		}
		if (pos_.y >= (float)(pos_y + 3 * GROUND_SIZE))
		{
			pos_.y = (float)(pos_y + 3 * GROUND_SIZE);
			pos_.x++;
		}
		break;
	}

}
//---------------------------------------------------------------------------------
//	描画処理
//---------------------------------------------------------------------------------
void Agaric::Render()
{
	DrawGraph(pos_.x, pos_.y, image_, TRUE);
}
//---------------------------------------------------------------------------------
//	終了処理
//---------------------------------------------------------------------------------
void Agaric::Exit()
{
	DeleteGraph(image_);
}
