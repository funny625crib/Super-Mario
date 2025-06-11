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
Goomba  goomba[10];
Agaric agaric;   //キリコ
int index = 0;
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
			goomba[index].map_data[h][w] = map.map[h][w];
			if (map.map[h][w] == 5) {
				goomba[0].map_pos_x = w*35;
				goomba[0].map_pos_y = h*35;
			}
			if (map.map[h][w] == 9) {

				goomba[index].first_pos_x = w;
				goomba[index].first_pos_y = h;
				index++;
			}

		}
	}

	for (int i = 0; i < index; ++i) {
		goomba[i].Init(map.map[goomba[i].first_pos_y][goomba[i].first_pos_x], goomba[i].first_pos_y, goomba[i].first_pos_x);
	}

}
//---------------------------------------------------------------------------------
//	更新処理
//---------------------------------------------------------------------------------
void GameUpdate()
{
	map.Update(player.pos_, player.is_jump, player.jump_frame);

	player.Update(map.is_on_ground, map.is_wall_have, agaric.pos_.x);

	agaric.Update(map.image_x[8][20], map.image_y[8][20], map.agaric_is_hit, map.pos_.x);
	for (int i = 0; i < index; ++i) {
		goomba[i].Update(player.pos_, PLAYER_IMAGE_W / 2, CheckHitKey(KEY_INPUT_D) && player.pos_.x >= SCREEN_W / 2,map.is_on_ground, map.pos_);
	}
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
	for (int i = 0; i < index; ++i) {
		goomba[i].Render();
		//if (map.is_on_ground == true) {
		//	DrawFormatString(300, 20 * i, GetColor(255, 255, 255), "%d", goomba[i].goomba_x);
			//DrawFormatString(40, 20 * i, GetColor(255, 255, 255), "%d", goomba[i].goomba_y);
		//if (goomba[i].check_display_on_ == true) {
			DrawFormatString(300, 20 * i, GetColor(255, 255, 255), "%d", goomba[0].map_pos_x);
	//	}
		//}
	}

	/*DrawFormatString(300, 300, GetColor(255, 255, 255), "%d",(int)( player.pos_.x - map.pos_.x )/35);
	DrawFormatString(300, 320, GetColor(255, 255, 255), "%d", (int)player.pos_.y / 35);*/

	//確認用
	DrawFormatString(10 + 20, 10, GetColor(255, 255, 255), "%d", ((int)player.pos_.y / GROUND_SIZE));
	DrawFormatString(10 + 50, 10, GetColor(255, 255, 255), "%d", ((int)(player.pos_.x - map.pos_.x) / GROUND_SIZE));

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
	for (int i = 0; i < index; ++i) {
		goomba[i].Exit();
	}
}
