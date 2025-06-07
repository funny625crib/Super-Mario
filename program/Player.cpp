#include "Player.h"
#include "map.h"
#include "Game.h"
#include "Main.h"


//---------------------------------------------------------------------------------
//	初期化処理
//---------------------------------------------------------------------------------
void Player::Init()
{
	//プレイヤーの画像の初期化
	image_ = LoadGraph("data/player/Mario.png");

	//プレイヤーの画像は最初は反転しなかった
	is_overturn = false;

	//プレイヤーのモード最初はIDLE
	mode_ = MODE_IDLE;

	//最初はジャンプしていない
	is_jump = false;
	jump_frame = 0;
}

//---------------------------------------------------------------------------------
//	更新処理
//---------------------------------------------------------------------------------
void Player::Update(bool& is_on_ground, bool is_wall_have,float& agaric_pos_x)
{

	//フレーム
	static int player_frame;

	//一時てきにプレイヤーの代わりに操作する
	if (PushHitKey(KEY_INPUT_SPACE) && is_on_ground == true)
	{
		is_jump = true;
		is_on_ground = false;
		jump_frame = 0;
	}

	if (CheckHitKey(KEY_INPUT_D) && is_wall_have == false)
	{
		agaric_pos_x -= 3.0f;
		mode_ = MODE_MOVE;
		pos_.x += PLAYER_MOVE_SPEED;     //RIGHT
		//画像を反転しません
		is_overturn = false;

	}
	if (CheckHitKey(KEY_INPUT_A))
	{
		mode_ = MODE_MOVE;
		pos_.x -= PLAYER_MOVE_SPEED;     //LEFT
		//画像を反転しません
		is_overturn = true;
	}

	if (is_jump == true)
	{
		jump_frame++;
		if (jump_frame < 20)
		{
			pos_.y -= 15.0f;
		}

		//ジャンプの画像に変える
		image_x = 5 * PLAYER_IMAGE_W;
	}



	//何のキーが押されていないとき
	if (CheckHitKeyAll() == 0)
	{
		mode_ = MODE_IDLE;
	}



	if (pos_.x > SCREEN_W / 2)
	{
		pos_.x = SCREEN_W / 2;
	}

	//プレイヤーのモードに対する処理
	switch (mode_)
	{
	case MODE_IDLE:
		if (is_jump == false)
		{
			image_x = 0;
		}

		break;
	case MODE_MOVE:
		//プレイヤーの移動に伴って画像が変化する
		player_frame++;
		if (player_frame % 10 == 0)
		{
			image_x += PLAYER_IMAGE_W;
			if (image_x >= 4 * PLAYER_IMAGE_W)
			{
				image_x = 0;
			}
		}
		break;

	}

}
//---------------------------------------------------------------------------------
//	描画処理
//---------------------------------------------------------------------------------
void Player::Render()
{
	DrawRectGraphF(pos_.x, pos_.y, image_x, image_y, PLAYER_IMAGE_W, PLAYER_IMAGE_H, image_, TRUE, is_overturn);
}
//---------------------------------------------------------------------------------
//	終了処理
//---------------------------------------------------------------------------------
void Player::Exit()
{
	DeleteGraph(image_);
}
