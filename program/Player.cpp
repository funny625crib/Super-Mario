#include "Player.h"
#include "map.h"
#include "Game.h"
#include "Main.h"
#include "agaric.h"
#include "Hit.h"

//---------------------------------------------------------------------------------
//	プレイヤーとキリコの当たり判定
//---------------------------------------------------------------------------------
void Player::agaric_eat(Float2& agaric_pos, int& agaric_mode,Float2 map_pos, bool is_on_ground)
{
	if (CheckBoxHit(pos_.x, pos_.y, PLAYER_IMAGE_W, PLAYER_IMAGE_H, agaric_pos.x+map_pos.x, agaric_pos.y, AGARIC_IMAGE_SIZE, AGARIC_IMAGE_SIZE)
		&& agaric_mode == Agaric::MODE_MOVE)
	{
		agaric_mode = Agaric::MODE_DISAPPEAR;

		//マリオの画像は大きくなる
		player_image_h = PLAYER_BIG_IMAGE_H;
		player_image_w = PLAYER_BIG_IMAGE_W;
		image_ = image_big;
		image_x = 0;
		player_size = SIZE_BIG;

		//プレイヤーが地面いるなら
		if (is_on_ground == true)
		{
			//プレイヤーを地下に出さない
			pos_.y -= GROUND_SIZE;
		}
		
	}
}

//---------------------------------------------------------------------------------
//	初期化処理
//---------------------------------------------------------------------------------
void Player::Init()
{
	//プレイヤーの画像の初期化
	image_small = LoadGraph("data/player/Mario.png");
	image_big = LoadGraph("data/player/Mario_big.png");
	image_diy_ = LoadGraph("data/player/mario_diy.png");
	//プレイヤーの座標を初期化する
	pos_ = { 0.0f,0.0f };

	//プレイヤーの画像は最初は反転しなかった
	is_overturn = false;

	//プレイヤーのモード最初はIDLE
	mode_ = MODE_IDLE;

	//最初はジャンプしていない
	is_jump = false;
	jump_frame = 0;

	//最初は小さいマリオ
	player_image_h = PLAYER_IMAGE_H;
	player_image_w = PLAYER_IMAGE_W;
	image_ = image_small;
	player_size = SIZE_SMALL;

	diy_jump = false;
	player_enemy_hit = false;
	second_jump_player_enemy_hit = false;
	second_jump = false;
	second_jump_count = 0;
	diy_jump_count = 0;
}

//---------------------------------------------------------------------------------
//	更新処理
//---------------------------------------------------------------------------------
void Player::Update(bool& is_on_ground)
{

	//フレーム
	static int player_frame;

	if (player_enemy_hit == true) {
		if (player_size == SIZE_BIG) {
			player_enemy_hit = false;
			player_image_h = PLAYER_IMAGE_H;
			player_image_w = PLAYER_IMAGE_W;
			player_size = SIZE_SMALL;
			image_ = image_small;
		}
		else if (player_size == SIZE_SMALL) {
			diy_jump = true;
		}
	}
	if (diy_jump == true)
	{
		diy_jump_count++;
		if (diy_jump_count < 20)
		{
			pos_.y -= 15.0f;
		}
		else {
			pos_.y += 5.0f;
		}

	}
	if (second_jump_player_enemy_hit == true) {
		second_jump = true;
	}
	if (second_jump == true)
	{
		second_jump_count++;
		if (second_jump_count < 20)
		{
			pos_.y -= 15.0f;
		}
		else {
			second_jump_player_enemy_hit = false;
			second_jump = false;
			second_jump_count = 0;
		}


	}

	//一時てきにプレイヤーの代わりに操作する
	if (PushHitKey(KEY_INPUT_SPACE) && is_on_ground == true)
	{
		is_jump = true;
		is_on_ground = false;
		jump_frame = 0;
	}

	if (CheckHitKey(KEY_INPUT_D))
	{
		
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
		image_x = 5 * player_image_w;
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
		if (is_jump == false)
		{
			player_frame++;
			if (player_frame % 10 == 0)
			{
				image_x += player_image_w;
				if (image_x >= 4 * player_image_w)
				{
					image_x = 0;
				}
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
	if (diy_jump == false) {

		DrawRectGraphF(pos_.x, pos_.y, image_x, image_y, player_image_w, player_image_h, image_, TRUE, is_overturn);
	}
	else {
		DrawRotaGraphF(pos_.x, pos_.y, 2.0f, 0.0f, image_diy_, TRUE, is_overturn);

	}
}
//---------------------------------------------------------------------------------
//	終了処理
//---------------------------------------------------------------------------------
void Player::Exit()
{
	DeleteGraph(image_);
	DeleteGraph(image_small);
	DeleteGraph(image_big);
	DeleteGraph(image_diy_);

}
