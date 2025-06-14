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
Goomba  goomba[10];
Player player;

Agaric agaric;   //�L���R
int index_max;
int mario_game_mode;

//�Q�[���ĊJ�܂ő҂���
int replay_frame;

//---------------------------------------------------------------------------------
//	����������
//---------------------------------------------------------------------------------
void GameInit()
{
	
	//�Q�[�����[�h�ŏ��̓X�^�[�g
	mario_game_mode = GAME_START;

	map.Init();
	player.Init();
	agaric.Init();
	
	for (int h = 0; h < MAP_H; ++h) {
		for (int w = 0; w < MAP_W; ++w) {
			if (map.map[h][w] == 9) {
				goomba[index_max].first_pos_x = w;
				goomba[index_max].first_pos_y = h;
				index_max++;
			}
		}
	}
	for (int i = 0; i < index_max; ++i) {
		goomba[i].Reset_();
	}
	for (int i = 0; i < index_max; ++i) {

		for (int h = 0; h < MAP_H; ++h) {
			for (int w = 0; w < MAP_W; ++w) {
				goomba[i].Goomba_Hit_Map_Init(map.map[h][w], w, h);
			}
		}
	}
	for (int i = 0; i < index_max; ++i) {
		goomba[i].Init(map.map[goomba[i].first_pos_y][goomba[i].first_pos_x], goomba[i].first_pos_y, goomba[i].first_pos_x);
	}
}
//---------------------------------------------------------------------------------
//	�X�V����
//---------------------------------------------------------------------------------
void GameUpdate()
{
	map.Update();

	player.Update(map.is_on_ground);

	agaric.Update(map.image_x[8][20], map.image_y[8][20], map.agaric_is_hit, map.pos_.x);


	//	�L���R�ƃ}�b�v�̓����蔻��
	map.Agaric_hit(agaric.pos_, agaric.speed, agaric.mode_);

	//�v���C���[�ƕǂ̓����蔻��
	map.Player_hit(player.pos_, player.is_jump, player.jump_frame, player.player_size,player.player_image_w, mario_game_mode);

	//�v���C���[�ƃL���R�̓����蔻��
	player.agaric_eat(agaric.pos_, agaric.mode_,map.pos_, map.is_on_ground);
	for (int i = 0; i < index_max; ++i) {
		Float2 map_move = { 0.0f,0.0f };
		
		if (CheckHitKey(KEY_INPUT_D) && player.pos_.x >= SCREEN_W / 2) {
			map_move.x += 3.0f;
		}
		if (CheckCircleBoxHit(goomba[i].Pos_.x, goomba[i].Pos_.y, 35, map_move.x - 35, map.pos_.y - 35, map_move.x + SCREEN_W + 35, SCREEN_H)) {
			goomba[i].Update(player.pos_, PLAYER_IMAGE_W / 2, CheckHitKey(KEY_INPUT_D) && player.pos_.x >= SCREEN_W / 2, map.is_on_ground, map.pos_, player.enemy_hit, player.player_enemy_hit, player.second_jump_player_enemy_hit);
		}
		goomba[i].Goomba_Hit_Map(map.pos_);

	}
	//�Q�[���I�[�o�[�ɂȂ�������
	if (mario_game_mode == GAME_OVER)
	{
		
		replay_frame++;
		//2����Q�[���ĊJ
		if (replay_frame >= 120)
		{
			
			//�S�ď���������
			map.Init();
			player.Init();
			agaric.Init();
			index_max = 0;

			GameInit();
			replay_frame = 0;
			
			mario_game_mode = GAME_START;
		}
	}
}
//---------------------------------------------------------------------------------
//	�`�揈��
//---------------------------------------------------------------------------------
void GameRender()
{
	DrawBox(0, 0, SCREEN_W, SCREEN_H, GetColor(97, 124, 182), TRUE);   //�w�i
	agaric.Render(map.pos_);
	map.Render();
	player.Render();
	for (int i = 0; i < index_max; ++i) {
		goomba[i].Render();

	}
	//Float2 map_move = { 0.0f,0.0f };

	//if (CheckHitKey(KEY_INPUT_D) && player.pos_.x >= SCREEN_W / 2) {
	//	map_move.x += 3.0f;
	//}
	//DrawLineBox(map_move.x - 35, map.pos_.y - 35, map_move.x + SCREEN_W + 35, map.pos_.y+SCREEN_H, GetColor(255, 255, 255));   //�w�i

	//�m�F�p
	DrawFormatString(10 + 20, 10, GetColor(255, 255, 255), "%d", ((int)player.pos_.y / GROUND_SIZE));
	DrawFormatString(10 + 50, 10, GetColor(255, 255, 255), "%d", ((int)(player.pos_.x - map.pos_.x) / GROUND_SIZE));

	DrawFormatString(10 + 90, 10, GetColor(255, 255, 255), "%d", map.map[((int)player.pos_.y / GROUND_SIZE)][((int)(player.pos_.x - map.pos_.x) / GROUND_SIZE)]);

	DrawFormatString(10 , 60, GetColor(255, 255, 255), "%f", player.pos_.y);
	DrawFormatString(10, 80, GetColor(255, 255, 255), "game_mode:%d", mario_game_mode);
	DrawFormatString(40, 100, GetColor(255, 255, 255), "frame:%d", replay_frame);

}
//---------------------------------------------------------------------------------
//	�I������
//---------------------------------------------------------------------------------
void GameExit()
{
	map.Exit();
	player.Exit();
	agaric.Exit();
	for (int i = 0; i < index_max; ++i) {
		goomba[i].Exit();
	}
}
