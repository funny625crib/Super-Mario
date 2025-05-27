#include "Main.h"
#include "Game.h"
#include "Map.h"
//# include <vector>
//#include <math.h>
//#include <algorithm>
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

}


//---------------------------------------------------------------------------------
//	更新処理
//---------------------------------------------------------------------------------
void Map::Update(Float2& player_pos)
{


	//プレイヤーが地面に触れると、落下しなくなります
	if (map[((int)player_pos.y / GROUND_SIZE)][((int)player_pos.x / GROUND_SIZE) == 1])
	{

	}
	else
	{
		//プレイヤーは重力を受ける
		player_pos.y += 5.0f;
	}


	//プレイヤーの移動に伴って地図も移動する(暫く)
	if (CheckHitKey(KEY_INPUT_D))
	{
		pos_.x -= 5.0f;
	}



}

//---------------------------------------------------------------------------------
//	描画処理
//---------------------------------------------------------------------------------
void Map::Render()
{

	DrawGraphF(pos_.x, pos_.y, Map_image_, TRUE);

	//DrawFormatString(10 + 10, 10, GetColor(255, 255, 255), "%d", map[-2][1]);



	//二次元配列でマップを描画する
	/*for (int h = 0; h < MAP_H; ++h)
	{
		for (int w = 0; w < MAP_W; ++w)
		{
			if (map[h][w] == 1)
			{
				DrawGraph(w * GROUND_SIZE, h * GROUND_SIZE, Ground_image_, TRUE);
			}
		}
	}*/

}


//---------------------------------------------------------------------------------
//	終了処理
//---------------------------------------------------------------------------------

void Map::Exit()
{


}





