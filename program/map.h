#pragma once
#include "Float2.h"
#include "Object.h"
#include "base.h"

class Map :
	public Base {

public:

	//床タイルのサイズ
#define GROUND_SIZE 37


	int Ground_image_;          //地面の画像
	int Wall_image_;            //壁の画像
	int Box_image_;             //箱の画像
	int Coin_image_;            //コインの画像

	int Map_image_;      //実験用画像


#define MAP_H 14
#define MAP_W 191           

	int map[MAP_H][MAP_W];
	int data_count_w;
	int data_count_h;


	void Init();     //	初期化処理
	void Update(Float2& player_pos);	//	更新処理
	void Render();	//	描画処理
	void Exit();		//	終了処理


private:




};
