#pragma once
#include "Float2.h"
#include "base.h"

class Player :
	public Base {

public:

	//プレイヤー画像のサイズ
#define PLAYER_IMAGE_W 33
#define PLAYER_IMAGE_H 34

#define PLAYER_BIG_IMAGE_W 50
#define PLAYER_BIG_IMAGE_H 68

//プレイヤーの移動スピード
#define PLAYER_MOVE_SPEED    2.0f


	//プレイヤー画像のサイズ
	int player_image_w;
	int player_image_h;

	//マリオの画像
	int image_small;
	int image_big;

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

	//プレイヤーの大きさ
	enum
	{
		SIZE_SMALL,
		SIZE_BIG,
		SIZE_SUPER,
	};
	int player_size;

	//プレイヤーがジャンプしているかどうか
	bool is_jump;
	int jump_frame;

	bool player_enemy_hit = false;
	bool diy_jump = false;
	int diy_jump_count = 0;
	int image_diy_;
	bool enemy_hit = false;

	bool second_jump_player_enemy_hit = false;
	bool second_jump = false;
	int second_jump_count = 0;

	void Init();     //	初期化処理
	void Update(bool& is_on_ground);	//	更新処理
	void Render();	//	描画処理
	void Exit();		//	終了処理
	void agaric_eat(Float2& agaric_pos, int& agaric_mode, Float2 map_pos, bool is_on_ground);  //	プレイヤーとキリコの当たり判定

};