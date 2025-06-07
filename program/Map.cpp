#include "Main.h"
#include "Game.h"
#include "Map.h"
#include "Player.h"
#include <fstream>
#include <string>
#include <sstream>
using namespace std;




//---------------------------------------------------------------------------------
//	初期化処理
//---------------------------------------------------------------------------------
void Map::Init()
{

	Map_image_ = LoadGraph("data/map/map1.png");  //とりあえずマップの画像を入る

	//いろいろな画像を初期化する
	Ground_image_ = LoadGraph("data/map/Ground.png");
	Ground1_image_ = LoadGraph("data/map/Ground1.png");
	Box_image_ = LoadGraph("data/map/Box.png");
	Wall_image_ = LoadGraph("data/map/Wall.png");


	// ファイルから読み込み
	ifstream file("data/map/txt/map1.txt", ios::in);

	//ファイルが開けるかどうか
	if (!file.is_open()) {
		printfDx("ファイルを開けませんでした\n");
		return;
	}

	for (int h = 0; h < MAP_H; ++h) {

		//マップ文字列を代入
		string str;

		getline(file, str);

		//文字列の分割
		stringstream sstr(str);

		for (int w = 0; w < MAP_W; ++w) {

			//分割した文字を保存する用変数
			int num = 0;

			//変数に代入
			sstr >> num;

			//マップに代入
			map[h][w] = num;
		}
	}


	//ファイルを閉める
	file.close();

	//マップの座標を初期化する
	pos_ = { 0.0f,0.0f };


	for (int h = 0; h < MAP_H; ++h)
	{
		for (int w = 0; w < MAP_W; ++w)
		{
			image_x[h][w] = w * GROUND_SIZE;
			image_y[h][w] = h * GROUND_SIZE;

		}
	}

	//最初は地面に当たっている
	is_on_ground = true;

	is_wall_have = false;
}


//---------------------------------------------------------------------------------
//	更新処理
//---------------------------------------------------------------------------------
void Map::Update(Float2& player_pos, bool& jump_mode, int jump_frame)
{

	//プレイヤーが地面に触れると、落下しなくなります
	if (map[((int)player_pos.y / GROUND_SIZE) + 1][((int)(player_pos.x - pos_.x) / GROUND_SIZE)] != 0)    //地面
	{
		is_on_ground = true;

	}
	else       
	{
		//プレイヤーは重力を受ける
		player_pos.y += 5.0f;
		is_on_ground = false;

		if (jump_frame>20)
		{
			jump_mode = false;
		}

	}

	//壁にぶつかると前に進めない
	if (map[((int)player_pos.y / GROUND_SIZE)][((int)(player_pos.x - pos_.x) / GROUND_SIZE) + 1] != 0)   //壁
	{
		is_wall_have = true;
	}
	else
	{
		is_wall_have = false;
	}

	//壁にぶつかると上に進めない
	if (map[((int)player_pos.y / GROUND_SIZE)][((int)(player_pos.x - pos_.x) / GROUND_SIZE)] != 0)
	{
		jump_mode = false;
	}



	//プレイヤーの移動に伴って地図も移動する(プレイヤーの位置が地図の真ん中にある場合)
	if (CheckHitKey(KEY_INPUT_D) && player_pos.x >= SCREEN_W / 2)
	{
		pos_.x -= 3.0f;   //プレイヤーの移動距離を記録する
		for (int h = 0; h < MAP_H; ++h)
		{
			for (int w = 0; w < MAP_W; ++w)
			{
				image_x[h][w] -= 3;

			}
		}
	}

	if (pos_.x < -IMAGE_W + SCREEN_W)
	{
		pos_.x = -IMAGE_W + SCREEN_W;
	}

}

//---------------------------------------------------------------------------------
//	描画処理
//---------------------------------------------------------------------------------
void Map::Render()
{

	//DrawGraphF(pos_.x, pos_.y, Map_image_, TRUE);    //参照用マップ

	DrawBox(0, 0, SCREEN_W, SCREEN_H, GetColor(97, 124, 182), TRUE);   //背景

	//DrawFormatString(10 + 10, 10, GetColor(255, 255, 255), "%d", map[-2][1]);



	//二次元配列でマップを描画する
	for (int h = 0; h < MAP_H; ++h)
	{
		for (int w = 0; w < MAP_W; ++w)
		{
			if (map[h][w] == 1)    //Ground
			{
				DrawGraph(image_x[h][w], image_y[h][w], Ground_image_, TRUE);
			}
			if (map[h][w] == 2)      //Ground1
			{
				DrawGraph(image_x[h][w], image_y[h][w], Ground1_image_, TRUE);
			}
			if (map[h][w] == 3)      //box
			{
				DrawGraph(image_x[h][w], image_y[h][w], Box_image_, TRUE);
			}
			if (map[h][w] == 4)      //wall
			{
				DrawGraph(image_x[h][w], image_y[h][w], Wall_image_, TRUE);
			}
		}
	}

}


//---------------------------------------------------------------------------------
//	終了処理
//---------------------------------------------------------------------------------

void Map::Exit()
{
	DeleteGraph(Ground_image_);
	DeleteGraph(Ground1_image_);
}





