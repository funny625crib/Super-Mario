#pragma once
#include "Float2.h"
#include "base.h"

class Agaric :
	public Base {

public:

	//キリコ画像のサイズ
#define AGARIC_IMAGE_SIZE 35



	void Init();     //	初期化処理
	void Update(int pos, int pos_y, bool is_hit, int map_pos_x);	//	更新処理
	void Render();	//	描画処理
	void Exit();		//	終了処理

	//キノコの移動モード
	enum
	{
		MODE_WAIT,
		MODE_APPEAR,
		MODE_MOVE,
		MODE_DISAPPEAR,   //プレイヤーがキリコを食べたら
	};
	int mode_;

	//キノコの移動スピード
	float speed;
};