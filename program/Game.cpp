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

Agaric agaric;   //�L���R

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
}
