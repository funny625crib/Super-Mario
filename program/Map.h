#pragma once
#include "Float2.h"
#include "base.h"

class Map :
	public Base {

public:

	//床タイルのサイズ
#define GROUND_SIZE 35


	int Ground_image_;          //地面の画像
	int Ground1_image_;
	int Wall_image_;            //壁の画像
	int Box_image_;             //箱の画像
	int Coin_image_;            //コインの画像

	int Map_image_;             //実験用画像

	//実験用画像のサイズ
#define IMAGE_W  7070


#define MAP_H 15
#define MAP_W 202     

int image_x[MAP_H][MAP_W];
int image_y[MAP_H][MAP_W];


	int map[MAP_H][MAP_W];
	int data_count_w;
	int data_count_h;

	//プレイヤーが地面にいるかどうか
	bool is_on_ground;


	//壁に当たったら、壁のアニメーション
	bool is_hit;
	//この壁の座標を記録する用変数
	int wall_x;
	int wall_y;


	//箱の表示部分の座標
	int box_image_x[MAP_H][MAP_W];
	int box_image_y[MAP_H][MAP_W];

	//プレイヤーとキノコが含む箱が当たるかどうか
	bool agaric_is_hit;

	void Init();     //	初期化処理
	void Update();	//	更新処理
	void Render();	//	描画処理
	void Exit();		//	終了処理
	void Agaric_hit(Float2& agaric_pos,float& agaric_speed, int agaric_mode);         //	キリコと壁の当たり判定
	void Player_hit(Float2& player_pos, bool& jump_mode, int jump_frame, int player_size, int player_size_w,int& game_mode); //プレイヤーと壁の当たり判定


private:




};
