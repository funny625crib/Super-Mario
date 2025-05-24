#pragma once
#include "base.h"

//---------------------------------------------------------------------------------
//	基本クラス
//---------------------------------------------------------------------------------

class Map :
	public Base
{
public:

	void Init();		//	初期化処理
	void Update();		//	更新処理
	void Render();		//	描画処理
	void Exit();		//	終了処理

private:

	int Ground_image_;          //地面の画像
	int Wall_image_;            //壁の画像
	int box_image_;             //箱の画像
	int coin_image_;

#define MAP_H
#define MAP_W
	//マップ用変数
	

};