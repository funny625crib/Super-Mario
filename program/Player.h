#pragma once
#include "Float2.h"
#include "base.h"

class Player :
	public Base {

public:

	//プレイヤー画像のサイズ
#define PLAYER_IMAGE_W 33
#define PLAYER_IMAGE_H 34

//プレイヤーの移動スピード
#define PLAYER_MOVE_SPEED    2.0f

//描画する画面の座標
	int image_x;
	int image_y;

	//プレイヤーの画像が反転するかどうか
	bool is_overturn;

	//プレイヤーの移動モード
	enum
	{
		MODE_IDLE,
		MODE_MOVE,
		MODE_STOP,     //移動中に急に逆方向に移動すると、一時停止します
	};
	int mode_;

	//プレイヤーがジャンプしているかどうか
	bool is_jump;
	int jump_frame;

	void Init();     //	初期化処理
	void Update(bool& is_on_ground, bool is_wall_have, float& agaric_pos_x);	//	更新処理
	void Render();	//	描画処理
	void Exit();		//	終了処理

};