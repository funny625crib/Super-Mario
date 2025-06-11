#include "Main.h"
#include "Game.h"
#include "Float2.h"
#include "Random.h"
#include "Hit.h"
#include "Map.h"
#include "player.h"
#include "agaric.h"
#include "Goomba.h"
Map map;

Player player;
 Goomba  goomba;
Agaric agaric;   //キリコ

//---------------------------------------------------------------------------------
//	初期化処理
//---------------------------------------------------------------------------------
void GameInit()
{
	map.Init();
	player.Init();
	agaric.Init();
	for (int h = 0; h < MAP_H; ++h) {
		for (int w = 0; w < MAP_W; ++w) {
			
				goomba.Init(map.map[10][20],1, 1);
		
		}
	}
}
//---------------------------------------------------------------------------------
//	更新処理
//---------------------------------------------------------------------------------
void GameUpdate()
{
	map.Update(player.pos_,player.is_jump,player.jump_frame);

	player.Update(map.is_on_ground,map.is_wall_have,agaric.pos_.x);

	agaric.Update(map.image_x[8][20], map.image_y[8][20],map.agaric_is_hit,map.pos_.x);
	
	goomba.Update(player.pos_, PLAYER_IMAGE_W/2, CheckHitKey(KEY_INPUT_D) && player.pos_.x >= SCREEN_W / 2);
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
	goomba.Render(map.image_x[10][20],30,30);

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
	goomba.Exit();
}
