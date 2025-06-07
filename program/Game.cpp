#include "Main.h"
#include "Game.h"
#include "Float2.h"
#include "Random.h"
#include "Hit.h"
#include "Map.h"
#include "player.h"
#include "agaric.h"

Map map;

Player player;

Agaric agaric;   //キリコ

//---------------------------------------------------------------------------------
//	初期化処理
//---------------------------------------------------------------------------------
void GameInit()
{
	map.Init();
	player.Init();
	agaric.Init();
}
//---------------------------------------------------------------------------------
//	更新処理
//---------------------------------------------------------------------------------
void GameUpdate()
{
	map.Update(player.pos_,player.is_jump,player.jump_frame);

	player.Update(map.is_on_ground,map.is_wall_have,agaric.pos_.x);

	agaric.Update(map.image_x[8][20], map.image_y[8][20],map.agaric_is_hit,map.pos_.x);
	
}
//---------------------------------------------------------------------------------
//	描画処理
//---------------------------------------------------------------------------------
void GameRender()
{
	DrawBox(0, 0, SCREEN_W, SCREEN_H, GetColor(97, 124, 182), TRUE);   //背景
	agaric.Render();
	map.Render();
	player.Render();
	

	//確認用
	DrawFormatString(10 + 20, 10, GetColor(255, 255, 255), "%d", ((int)player.pos_.y / GROUND_SIZE));
	DrawFormatString(10 + 50, 10, GetColor(255, 255, 255), "%d", ((int)(player.pos_.x-map.pos_.x) / GROUND_SIZE));

	DrawFormatString(10 + 90, 10, GetColor(255, 255, 255), "%d", map.map[((int)player.pos_.y / GROUND_SIZE)][((int)(player.pos_.x - map.pos_.x) / GROUND_SIZE)]);
}
//---------------------------------------------------------------------------------
//	終了処理
//---------------------------------------------------------------------------------
void GameExit()
{
	map.Exit();
	player.Exit();
	agaric.Exit();
}
